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
	int rows;
	int seats;
	unordered_set<int> aisle;
	unordered_set<string> bookedseats;

public:
	Screen(vector<string> &command){
		name = command[1];
		rows = stoi(command[2]);
		seats = stoi(command[3]);

		bool flag = true;
		for(int i = 4; i < command.size(); i++){
			int curr_seat = stoi(command[i]);
			if(curr_seat > seats)
				flag = false;
			aisle.insert(curr_seat);
		}
		
		if(flag)
			cout<<"success\n";
		else
			cout<<"failure\n";
	}

	bool reserve_seat(vector<string> &command){
		int row = stoi(command[2]);

		if(row > rows){
			return false;
		}
		for(int i = 3; i < command.size(); i++){
			int curr_seat = stoi(command[i]);
			if(curr_seat > seats)
				return false;

			string temp = to_string(row) + " " + to_string(curr_seat);
			if(bookedseats.find(temp) != bookedseats.end())
				return false;
		}
		//book only if all the seats are free
		for(int i = 3; i < command.size(); i++){
			int curr_seat = stoi(command[i]);

			string temp = to_string(row) + " " + to_string(curr_seat);
			bookedseats.insert(temp);
		}

		return true;
	}

	void get_unres(int row_no){
		if(row_no > rows){
			return;
		}

		for(int i = 1; i <= seats; i++){
			string temp = to_string(row_no) + " " + to_string(i);

			if(bookedseats.find(temp) == bookedseats.end()){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}

	void suggest_seats(vector<string> &command){

		int n = stoi(command[2]);
		int row_no = stoi(command[3]);
		int choice = stoi(command[4]);

		if(row_no > rows){
			cout<<"none\n";
			return;
		}
		if(n > seats){
			cout<<"none\n";
			return;
		}

		bool to_the_left = true, to_the_right= true;
		vector<int> suggested_seats;
		int aisle_seats = 0;

		//if there are enough choices to the right
		if(seats - choice + 1 >= n){
			for(int i = choice; i < choice + n; i++){
			
				string temp = to_string(row_no) + " " + to_string(i);

				if(bookedseats.find(temp) != bookedseats.end()){
					to_the_right = false;
					break;
				}
				else if(aisle.find(i) != aisle.end()){
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

				string temp = to_string(row_no) + " " + to_string(i);

				if(bookedseats.find(temp) != bookedseats.end()){
					to_the_left = false;
					break;
				}
				else if(aisle.find(i) != aisle.end()){
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

	void printScreen(){
		cout<<" Name = "<<this->name<<endl;
		cout<<" rows = "<<this->rows<<endl;
		cout<<" seats = "<<this->seats<<endl;
		cout<<" Aisle seats = ";
		for(int i:this->aisle){
			cout<<i<<" ";
		}
		cout<<endl;

		for(auto a:this->bookedseats){
			cout<<a<<"\t";
		}
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
