#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;
//Greeting the user
void greetUser(string name){
    cout<<"Hello "<<name<<"! I'm your virtual Assistant."<<endl;
}
//Asking our assistant for the time
void showTime(){
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<"Current time: ";
    cout<<1+ltm->tm_hour<<":"<<ltm->tm_min<<endl;
}
//Asking for assistant for the date
void showDate(){
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<"Today's Date: ";
    cout<<1900+ltm->tm_year<<"/"<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<endl;
}
//Asking our assistant "How's the weather?"
void weather() {
    string weatherConditions[] = {
        "It's sunny and warm today!",
        "Looks like it's going to rain. Carry an umbrella!",
        "It's cloudy and cool.",
        "Stormy weather outside. Stay safe!",
        "Chilly winds are blowing. Wear a jacket!",
        "Perfect weather for a walk!"
    };
    srand(time(0));
    int index = rand() % 6;
    cout << weatherConditions[index] << endl;
}
//Requesting our assistant for a Joke
void tellJoke() {
    string jokes[] = {
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the computer get cold? Because it forgot to close its Windows.",
        "I told my computer I needed a break, and it said 'No problem, I'll go to sleep!'"
    };
    srand(time(0));
    int index = rand() % 3;
    cout << jokes[index] << endl;
}
int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    greetUser(name);


string command;

while (true) {
    cout << "\nHow can I help you, " << name << "? (type 'help' for options)\n> ";
    getline(cin, command);

    if (command == "time") {
        showTime();
    } else if (command == "date") {
        showDate();
    } else if (command == "weather") {
        weather();
    } else if (command == "joke") {
        tellJoke();
    } 
     else if (command == "help") {
        cout << "Available commands:\n";
        cout << "- time\n- date\n- weather\n- joke\n- calculator\n- save reminder\n- read reminder\n- exit\n";
    } else if (command == "exit") {
        cout << "Goodbye, " << name << "! Have a great day!" << endl;
        break;
    } else {
        cout << "Sorry, I didn't understand that command." << endl;
    }
}
