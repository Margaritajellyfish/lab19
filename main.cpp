#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

class Movie {
private:
    
    struct Node {
        double rate;
        string comment;
        Node* next;
    };

    Node* head;
    string title;

public:
    
    Movie(string movieTitle) : title(movieTitle), head(nullptr) {}

    void addReview(string comment) {
        
        double randomRate = (rand() % 41 + 10) / 10.0;

        Node* newNode = new Node;
        newNode->rate = randomRate;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }
    void printReviews() {
        cout << "Movie: " << title << endl;
        Node* current = head;
        int count = 1;
        while (current != nullptr) {
            cout << "> Review #" << count << ": Rating: " << current->rate
                 << " - " << current->comment << endl;
            current = current->next;
            count++;
        }
        cout << endl;
    }

    ~Movie() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<Movie> movies;

    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Could not open file." << endl;
        return 1;
    }

    movies.push_back(Movie("a"));
    movies.push_back(Movie("b"));
    movies.push_back(Movie("c"));
    movies.push_back(Movie("d"));

    string review;
    int count = 0;
    
    while (getline(fin, review)) {
        if (count < 3) {
            movies[0].addReview(review);
        } else if (count < 6) {
            movies[1].addReview(review);
        } else if (count < 9) {
            movies[2].addReview(review);
        } else if (count <12){
                movies[3].addReview(review);
            }

        count++;
    }

    fin.close();

    
    for (int i =0; i<4; i++) {
        movies[i].printReviews();
    }

    return 0;
}
