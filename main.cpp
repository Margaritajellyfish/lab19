#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;

struct Node{
    double rate;
    string comment;
    Node * previous;
    Node * next;
};
class Movie{
    string title;
    
};
ifstream fin;
fin.open("input.txt");
int main(){
    int choice;
    bool loop;
    char again;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *current = nullptr;
        Node *temp = new Node;
        cout << "Enter review rating 0-5: ";
        cin >> temp->rate;
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, temp->comment);

        if(head==nullptr){
            head = temp;
            tail = temp;
        }
        else{
            
            temp->next = head;
            head->previous = temp;
            head = temp;
        }

        }

        cout << "Enter another review? Y/N: ";
        cin >>again;
        if ((again== 'Y')||(again== 'y')){
            loop = true;
        }
        else{
            loop = false;
        }

    }while(loop==true);
    current = head;
    cout << "Outputting all reviews: \n";
    int count = 1;
    double total = 0;
    while(current){
        cout << "> Review #" << count << ": " << current->rate << ": " << current->comment << endl;
        total += current->rate;
        current = current->next;
    }
    cout << "> Average: " << total/ count;

    return 0;
}
