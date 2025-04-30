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
//Asking our assistant for the date
void showDate(){
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<"Today's Date: ";
    cout<<1900+ltm->tm_year<<"/"<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<endl;
}
// Function to ask a riddle
void askRiddle() {
    string input;
    cout << "Bot: Welcome! Let's solve a riddle." << endl;
    cout << "Bot: Here’s your riddle:" << endl;
    cout << "I’m something. The more of me you have, the less you can see. What am I?" << endl;
    while (true) {
        cout <<"You: ";
        cin>>input;  //to capture user input
        if (input == "darkness" || input == "Darkness") {
            cout <<"Assistant: Correct! Darkness is the answer."<< endl;
            break;
        }
        else if (input == "bye") {
            cout <<"Assistant: Goodbye! Have a great day!"<< endl;
            break;
        }
        else {
            cout <<"Assistant: Oops! Try again. Hint: It's the absence of light."<< endl;
        }
    }
}

//Asking our assistant "How's the weather?"
void weather() {
    string weatherConditions[] = {
        "It's raining cats and dogs. Grab an umbrella!",
        "The sun is shining, but it's a bit windy.",
        "It’s foggy outside, so drive carefully.",
        "Heavy thunderstorms are expected. Stay indoors!",
        "The temperature is mild and pleasant today.",
        "It’s a hot day, make sure to stay hydrated!",
        "It's cloudy and cool.",
        "It's sunny and warm today!",
        "Looks like it's going to rain. Carry an umbrella!",
        "Stormy weather outside. Stay safe!",
        "Chilly winds are blowing. Wear a jacket!",
        "Perfect weather for a walk!"
    };
    srand(time(0));
    int index = rand() % 12;
    cout << weatherConditions[index] << endl;
}
//Requesting our assistant for a Joke
void tellJoke() {
    string jokes[] = {
        "Why don't skeletons fight each other? Because they don't have the guts.",
        "Why did the computer get cold? Because it forgot to close its Windows.",
        "I told my computer I needed a break, and it said 'No problem, I'll go to sleep!'",
        "Why don't scientists trust atoms? Because they make up everything!",
        "I'm on a seafood diet. I see food and I eat it.",
        "Why was the math book sad? Because it had too many problems."

    };
    srand(time(0));
    int index = rand() % 3;
    cout << jokes[index] << endl;
}
// Function to get a list of fun facts
void printRandomFunFact() {
    const char* facts[] = {
        "Honey never spoils. Archaeologists found 3000-year-old honey and it was perfectly edible!",
        "Bananas are berries, but strawberries are not!",
        "Octopuses have three hearts!",
        "A group of flamingos is called a 'flamboyance'.",
        "There are more stars in the universe than grains of sand on Earth.",
        "Butterflies can taste with their feet!",
        "Sharks existed before trees!",
        "The unicorn is the national animal of Scotland.",
        "A day on Venus is longer than a year on Venus.",
        "Sloths can hold their breath longer than dolphins can!"
    };
    const int numFacts = sizeof(facts) / sizeof(facts[0]);
    srand(time(0));  // Seed the random number generator
    int index = rand() % numFacts;
    cout << "Fun Fact: " << facts[index] << endl;
}

void calculator() {
    double a, b;
    char op;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;

    switch(op) {
        case '+': cout << "Result: " << a + b << endl; break;
        case '-': cout << "Result: " << a - b << endl; break;
        case '*': cout << "Result: " << a * b << endl; break;
        case '/': 
            if(b != 0)
                cout << "Result: " << a / b << endl; 
            else
                cout << "Cannot divide by zero!" << endl;
            break;
        default: cout << "Invalid operator!" << endl;
    }
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
    } else if (command == "date ") {
        showDate();
    } else if (command == "weather") {
        weather();
    } else if (command == "joke") {
        tellJoke();
    } else if(command == "calculator"){
        calculator();
    } else if (command == "funfact") {
        printRandomFunFact();
    } else if (command == "riddle") {
        askRiddle();
    }else if (command == "help") {
        cout << "Available commands:\n";
        cout << "- time\n- date\n- weather\n- joke\n- calculator\n- save reminder\n-funfact\n- riddle\n read reminder\n- exit\n";
    } else if (command == "exit") {
        cout << "Goodbye, " << name << "! Have a great day!" << endl;
        break;
    } else {
        cout << "Sorry, I didn't understand that command." << endl;
    }
}
