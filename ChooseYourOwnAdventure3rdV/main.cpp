//
//  main.cpp
//  ChooseYourOwnAdventure3rdV
//
//  Created by Jack Kalnicki on 9/28/17.
//  Copyright © 2017 Jack Kalnicki. All rights reserved.
//

#include <iostream>
using namespace std;

int alive = 1;
string input = "0";
string room = "main";
string name = "--";

int main(int argc, const char * argv[]) {
    cout << "Welcome to Choose Your Own Adventure!\n";
    cout << "Please enter your name.\n";
    cin >> name;
    cout << "Okay " << name << " Get ready to play!\n";
    while(input !="q" || room == "Win"){
        if(room == "main"){
            cout << "Hello? Hello? You hear from a voice in the distance. You are in a dark room.\n";
            cout << "You have a few options. You can either look for the voice or turn on the lights";
            cin >> input;
            if(input == "look"){
                cout << "You have been looking for 30 minutes and you have found nothing. You are very tired. Do you want to sleep or try to stay awake.\n";
                cin >> input;
                if(input == "sleep"){
                    cout << "You have been killed by something unknown.\n";
                    input = "q";
                    
                }
            }
                
            
            
            {
}


}







    }}

