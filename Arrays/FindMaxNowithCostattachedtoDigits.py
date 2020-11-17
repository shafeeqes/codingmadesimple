/*

I have been given the total money I have. Now I know the cost it takes to write down each digit (1 to 9). 
So how to create a maximum number out of it? Is there any dynamic programming approach for this problem?

Example:

total money available = 2
cost of each digit (1 to 9) = 9, 11, 1, 12, 5, 8, 9, 10, 6
output:33

*/


/*

I don't think you need dynamic programming, just do the following:

Pick as many of the digit that costs the least as you can afford.
Now you have a number (consisting of only 1 type of digit).
Replace the first digit with the greatest possible digit that you can afford
If you have money left, do the same for the second, and the third and so on, until you run out of money.
Why this works:

Consider that 11111 > 9999 and 91111 > 88888, or, in words, it's best to:

Pick as many digits as possible, which is done by picking the cheapest digits.
Then replace these digits, from the left, with the highest valued digit you can afford (this is always better than 
picking a few more expensive digits to start).
Optimization:

To do this efficiently, discard any digits that cost more than a bigger digit: (because it's never a good idea to pick 
that one instead of a cheaper digit with a bigger value)

Given:
9, 11, 1, 12, 5, 8, 9, 10, 6
Removing all those where I put an X:
X, X, 1, X, 5, X, X, X, 6
So:
1, 5, 6
Now you can just do binary search on it (just remember which digit which value came from) (although, for only 9 digits, 
binary search doesn't really do wonders for the already-minor running time).

Running time:

O(n) (with or without the optimization, since 9 is constant)

*/



total_money = 2   
    
    cost_of_digit = [9, 11, 1, 12, 5, 8, 9, 10, 6]
    
    # Appending the list digits with [weight, number] 
    k=1
    digits=list()
    
    for i in cost_of_digit:
        digits.append([i,k])
        k+=1
    
    #  Discarding any digits that cost more than a bigger digit: (because it's never a good idea to pick that one instead of a cheaper digit with a bigger value)
    i = 8
    while(i>0):
        if digits[i][0] <= digits[i-1][0]:
            del digits[i-1]
            i-=1
        else:
            i-=1
    
    # Sorting the digits based on weight
    digits.sort(key=lambda x:x[0],reverse=True)
    
    max_digits = total_money//digits[-1][0] # Max digits that we can have in ANSWER
    selected_digit_weight = digits[-1][0] 
    
    ans=list()
    
    if max_digits > 0:
        for i in range(max_digits):
            ans.append(digits[-1][1])
    
    # Calculating extra money we have after the selected digits
    extra_money = total_money % digits[-1][0]
    
    index = 0
    
    # Sorting digits in Descending order according to their value
    digits.sort(key=lambda x:x[1],reverse=True)
    
    while(extra_money >= 0 and index < max_digits):
        temp = extra_money + selected_digit_weight # The money we have to replace the digit
        swap = False # If no digit is changed we can break the while loop 
        
        for i in digits:
            # Checking if the weight is less than money we have AND the digit is greater than previous digit
            if i[0] <= temp and i[1] > digits[-1][1]: 
                ans[index] = i[1]
                index += 1
                extra_money = temp - i[0]
                swap = True
                break
        if(not swap):
            break
    
    if len(ans) == 0:
        print("Number cannot be formed")
    else:
        for i in ans:
            print(i,end="")
        print()
