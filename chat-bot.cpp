#include <iostream>
#include <string>
#include <map>

using namespace std;

class Chatbot {
private:
    map<string, string> responses;

public:
    Chatbot() {
        // Initialize responses
        responses["hello"] = "Hello! How can I assist you today?";
        responses["hi"] = "Hi! What's on your mind?";
        responses["how are you"] = "I'm doing well, thanks! How about you?";
        responses["what is your name"] = "My name is Chatty, nice to meet you!";
        responses["goodbye"] = "Goodbye! It was nice chatting with you.";
        responses["exit"] = "Goodbye! It was nice chatting with you.";
    }

    string respond(string input) {
        // Convert input to lowercase
        for (char& c : input) {
            c = tolower(c);
        }

        // Check if input matches a response
        if (responses.find(input)!= responses.end()) {
            return responses[input];
        } else {
            return "I didn't understand that. Can you please rephrase?";
        }
    }
};

int main() {
    Chatbot chatbot;

    cout << "Welcome to Chatty! I'm here to help with any questions you may have." << endl;

    string input;
    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (input == "exit" || input == "goodbye") {
            break;
        }

        string response = chatbot.respond(input);
        cout << "Chatty: " << response << endl;
    }

    return 0;
}