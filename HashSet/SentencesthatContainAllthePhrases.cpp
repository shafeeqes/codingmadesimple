"""
Given a list of sentences and a list of phrases. The task is to find which sentence(s) contain all the words in a phrase and for every phrase print the sentences number that contains the given phrase.

Constraint: A word cannot be a part of more than 10 sentences.

Examples:

Input:
Sentences:
1. Strings are an array of characters.
2. Sentences are an array of words.
Phrases:
1. an array of
2. sentences are strings
Output:
Phrase1 is present in sentences: 1,2
Phrase2 is present in sentences: None
Since each word in phrase 1 exists in both the sentences,
but all the words in second phrase do not exist in either.

Input:
Sentences:
1. Sets in python are a hash table representation of arrays.
2. Searching in Sets are a function of time complexity O(1).
3. Sets only contain unique elements, and have no order.
Phrases:
1. Sets are a
2. Searching in
Output:
Phrase1 is present in sentences: 1, 2
Phrase2 is present in sentences: 2



Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: For each Phrase, we have to find the sentences which contain all the words of the phrase. So, for each word in the given phrase, we check if a sentence contains it. We do this for each sentence. This process of searching may become faster if the words in the sentence are stored in a set instead of a list.

Below is the implementation of above approach:

filter_none
edit
play_arrow

brightness_4

"""

# Python program to find the sentence 
# that contains all the given phrases  
def getRes(sent, ph): 
    sentHash = dict() 
  
    # Loop for adding hased sentences to sentHash 
    for s in range(1, len(sent)+1): 
        sentHash[s] = set(sent[s-1].split()) 
          
    # For Each Phrase 
    for p in range(0, len(ph)): 
        print("Phrase"+str(p + 1)+":") 
  
        # Get the list of Words 
        wordList = ph[p].split() 
        res = [] 
  
        # Then Check in every Sentence 
        for s in range(1, len(sentHash)+1): 
            wCount = len(wordList) 
  
            # Every word in the Phrase 
            for w in wordList: 
                if w in sentHash[s]: 
                    wCount -= 1
  
            # If every word in phrase matches 
            if wCount == 0: 
  
            # add Sentence Index to result Array 
                res.append(s) 
        if(len(res) == 0): 
            print("NONE") 
        else: 
            print('% s' % ' '.join(map(str, res))) 
  
# Driver Function 
def main(): 
    sent = ["Strings are an array of characters", 
    "Sentences are an array of words"] 
    ph = ["an array of", "sentences are strings"] 
    getRes(sent, ph) 
  
main() 
Output:
Phrase1:
1 2
Phrase2:
NONE
