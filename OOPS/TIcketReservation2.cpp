#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<set>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define pb push_back


class Screen{
	string name;
	vector<vector<int>> seats;

	//seat = 0
	//aisle = 2
	//booked = 1

public:
	Screen(vector<string> &command){
		name = command[1];
		int rows = stoi(command[2]);
		int n = stoi(command[3]);

		this->seats.resize(rows, vector<int> (n,0));

		bool flag = true;
		
		for(int i = 4; i < command.size(); i++){
			int curr_seat = stoi(command[i]);
			if(curr_seat > this->seats[0].size()){
				flag = false;
				break;
			}
			for(int j = 0; j < rows; j++){
				seats[j][curr_seat-1] = 2;
			}
		}
		
		if(flag)
			cout<<"success\n";
		else
			cout<<"failure\n";
	}

	bool reserve_seat(vector<string> &command){
		int row = stoi(command[2]);
		if(row > this->seats.size()){
			return false;
		}
		for(int i = 3; i < command.size(); i++){
			int curr_seat = stoi(command[i]);
			if(curr_seat > this->seats[0].size())
				return false;

			if(this->seats[row-1][curr_seat-1] == 1)
				return false;
		}
		//book only if all the seats are free
		for(int i = 3; i < command.size(); i++){
			int curr_seat = stoi(command[i]);

			this->seats[row-1][curr_seat-1] = 1;
		}

		return true;
	}

	void get_unres(int row_no){
		if(row_no > this->seats.size()){
			return;
		}

		for(int i = 0; i < this->seats[row_no-1].size(); i++){
			if(this->seats[row_no-1][i] != 1)
				cout<< i+1 <<" ";
		}
		cout<<endl;
	}

	void suggest_seats(vector<string> &command){

		int n = stoi(command[2]);
		int row_no = stoi(command[3]);
		int choice = stoi(command[4]);

		int rows = this->seats.size();
		if(row_no > rows){
			cout<<"none\n";
			return;
		}
		int totalseats = seats[row_no-1].size();

		if(n > totalseats){
			cout<<"none\n";
			return;
		}

		bool to_the_left = true, to_the_right= true;
		vector<int> suggested_seats;
		int aisle_seats = 0;

		//if there are enough choices to the right
		if(totalseats - choice + 1 >= n){
			for(int i = choice; i < choice + n; i++){
			
				if(this->seats[row_no-1][i-1] == 1){
					to_the_right = false;
					break;
				}
				else if(this->seats[row_no-1][i-1] == 2){
					aisle_seats++;
				}

				if(aisle_seats > 1){
					to_the_right = false;
					break;
				}
				suggested_seats.pb(i);
			}
		}

		if(suggested_seats.size() >= n){
			for(int i:suggested_seats){
				cout<< i <<" ";
			}
			cout<<endl;
			return;
		}
		else{
			suggested_seats.clear();
			aisle_seats = 0;
		}

		//if there are enough seats to the left
		if(choice >= n){
			for(int i = choice; i > choice - n ; i--){

				if(this->seats[row_no-1][i-1] == 1){
					to_the_right = false;
					break;
				}
				else if(this->seats[row_no-1][i-1] == 2){
					aisle_seats++;
				}

				if(aisle_seats > 1){
					to_the_left = false;
					break;
				}
				suggested_seats.pb(i);
			}
		}

		if(suggested_seats.size() >= n){
			sort(suggested_seats.begin(),suggested_seats.end());
			for(int i:suggested_seats){
				cout<< i <<" ";
			}
			cout<<endl;
			return;
		}

		cout<<"none\n";
	}

};

int main(){
	int t;
	unordered_map<string, Screen*> screens;
    string test;
    getline(cin,test);
    t = stoi(test);

	while(t--){
		string str;
		cin.clear();

		getline(cin,str);
		vector<string> command;

		stringstream s(str);
		string word;

		while(s>>word){
			command.pb(word);
		}

		if(command[0] == "add-screen"){
			Screen* new_screen = new Screen(command);
			string name = command[1];
			screens.insert({name,new_screen});
		}

		else if(command[0]=="reserve-seat"){
            string name = command[1];
            if(screens.find(name)== screens.end()){
            	cout<<"failure\n";
            }
	        else{
	            if(screens[name]->reserve_seat(command)){
	            	cout<<"success\n";
	            }
	            else{
	            	cout<<"failure\n";
	            }
        	}
        }
        else if(command[0]=="get-unreserved-seats"){
            string name = command[1];
            if(screens.find(name)== screens.end()){
            	cout<<"failure\n";
            }
	        else{
	            int row_no = stoi(command[2]);
	            screens[name]->get_unres(row_no);
        	}
        }
        
        else if(command[0]=="suggest-contiguous-seats"){
            string name = command[1];
            if(screens.find(name)== screens.end()){
            	cout<<"failure\n";
            }
	        else{
	            int row_no = stoi(command[2]);
	            screens[name]->suggest_seats(command);
        	}
        }
        else{
            cout<<"failure\n";
        }
	}
}
