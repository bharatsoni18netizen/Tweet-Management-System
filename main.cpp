#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Tweet {
public:
    int tweetId;
    string text;
    Tweet* next;

    Tweet(int id, string content) {
        tweetId = id;
        text = content;
        next = NULL;
    }
};

class TweetManager {
private:
    Tweet* head;
    int nextId;

public:
    TweetManager() {
        head = NULL;
        nextId = 1;
    }

    void createTweet(string text) {
        Tweet* newTweet = new Tweet(nextId++, text);
        if (head == NULL) {
            head = newTweet;
        } else {
            Tweet* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTweet;
        }
        cout << "\n[Success] Tweet created with ID: " << (nextId - 1) << endl;
    }

    void displayTweets() {
        if (head == NULL) {
            cout << "\n[Notice] No tweets found to display." << endl;
            return;
        }
        cout << "\n========== Tweet Feed ==========" << endl;
        Tweet* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->tweetId << " | " << temp->text << endl;
            temp = temp->next;
        }
        cout << "================================" << endl;
    }

    void searchTweet(int id) {
        Tweet* temp = head;
        while (temp != NULL) {
            if (temp->tweetId == id) {
                cout << "\n[Found] ID: " << temp->tweetId << " | " << temp->text << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\n[Error] Tweet with ID " << id << " not found." << endl;
    }

    void deleteTweet(int id) {
        if (head == NULL) {
            cout << "\n[Notice] Feed is empty." << endl;
            return;
        }
        if (head->tweetId == id) {
            Tweet* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "\n[Success] Tweet ID " << id << " deleted." << endl;
            return;
        }
        Tweet* temp = head;
        while (temp->next != NULL && temp->next->tweetId != id) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "\n[Error] Tweet with ID " << id << " not found." << endl;
        } else {
            Tweet* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "\n[Success] Tweet ID " << id << " deleted." << endl;
        }
    }
};

int main() {
    TweetManager tm;
    int choice, id;
    string text;

    while (true) {
        system("cls");
        cout << "===== Tweet Management System (C++) =====" << endl;
        cout << "1. Create Tweet" << endl;
        cout << "2. Display All Tweets" << endl;
        cout << "3. Search Tweet by ID" << endl;
        cout << "4. Delete Tweet" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nEnter tweet content: ";
                getline(cin, text);
                tm.createTweet(text);
                break;
            case 2:
                tm.displayTweets();
                break;
            case 3:
                cout << "\nEnter Tweet ID to search: ";
                cin >> id;
                tm.searchTweet(id);
                break;
            case 4:
                cout << "\nEnter Tweet ID to delete: ";
                cin >> id;
                tm.deleteTweet(id);
                break;
            case 5:
                cout << "\nExiting system..." << endl;
                return 0;
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }
        cout << "\nPress any key to continue...";
        getch();
    }
    return 0;
}