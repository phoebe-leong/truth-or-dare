#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
#include <time.h>

void truth_or_dare();

int shotsTaken = 0;
std::string truths[7] = {
    "Have you ever told a secret you swore you wouldn't?",
    "What are you currently wearing?",
    "Favourite colour?",      
    "Who's the last person you called by the wrong name?",
    "What thing did you do that got you into the most trouble",
    "What's your secret hobby?",
    "If you could be invisible for a day what would be the first thing you would do?"
    };
std::string dares[7] = {
    "Shout something really loud in a crowded place randomly.",
    "Tell the last person you texted that you love them.",
    "Take an embarrassing photo of yourself and post it online.",
    "Tweet something controversial and don't reply to any of the comments.",
    "Drink a small glass of straight vinegar.",
    "Draw on your face in permanent marker.",
    "Eat a raw egg"
};

int close ( ) {
    std::cout << "Press enter to close the program.\n";
    std::cin.ignore ( );
    std::cin.get ( );
    return 0;
}

void results ( ) {
    std::cout << "You took " << shotsTaken << " shots.\n\n";
}

    void truth ( ) {
        int randomNumber = rand() % 7;
        std::string input;

        std::string randomTruth = truths[randomNumber];

        std::cout << randomTruth << "\n";
        std::cin >> input;

        if (input == "p") {
            shotsTaken++;
            truth_or_dare();
        } else if (input == "q") {
            results();
            close();
        } else {
            truth_or_dare();
        }
    }

    void dare ( ) {
        int randomNumber = rand() % 7;
        std::string input;
        std::string randomDare = dares[randomNumber];

        std::cout << randomDare << "\n";
        std::cin >> input;

        if (input == "done") {
            truth_or_dare();
        } else if (input == "p") {
            shotsTaken++;
            truth_or_dare();
        } else if (input == "q") {
            results();
            close();
        } else {
            truth_or_dare();
        }
    }

void truth_or_dare ( ) {

    std::string tod;

    std::cout << "Truth or Dare?\n";
    std::cin >> tod;

    if (tod == "truth") {
        truth();
    } else if (tod == "dare" || tod == "d") {
        dare();
    } else if (tod == "q") {
        close();
    } else if (tod == "truth" || tod == "t") {
        truth();
    }
     else {
        truth_or_dare();
    }
}

void menu ( ) {
    char input;

    cout << "\n";
    cout << "***************************************\n";
    cout << "*            Made by PH03be           *\n";
    cout << "*           Press s to start          *\n";
    cout << "*       Press q to quit the program   *\n";
    cout << "***************************************\n";
    cout << "\n\nTruth Or Dare Commands:\n";
    cout << "c : list of commands.\n";
    cout << "t : choose truth.\n";
    cout << "d : choose dare.\n";
    cout << "p : pass.\n";
    cout << "done : tell the computer that you did the dare.\n";
    cout << "q : quit the program\n";
    cin >> input;

    switch (input) {
        case 's':
        truth_or_dare();
        break;
        case 'q':
        close();
        break;
    }
}

int main ( ) {
    srand(time(NULL));

    menu();
}
