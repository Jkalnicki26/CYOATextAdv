//
//  main.cpp
//  ChooseYourOwnAdventure3rdV
//
//  Created by Jack Kalnicki on 9/28/17.
//  Copyright © 2017 Jack Kalnicki. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    
    string input = "";
    string room = "";
    string name = "";
    string swordlevel = "0";
    string minionskilled = "";
    string strategy = "";
    
    cout << "Welcome to Choose Your Own Adventure!\n";
    cout << "Please enter your name.\n";
    cin >> name;
    cout << "Okay " << name << " Get ready to play!\n";
    room = "begin";
    while (input != "q" && input != "Q")
    {
        if(room == "begin")
        {
            
            cout << "There are 4 doors around you in all directions. You can go East, West, South, North.\nWhere would you like to go?\n";
            
            cin >> input;
            
            if(input == "West" || input == "west" || input == "w")
            {
                room = "west";
            }
            
            else if(input == "South" || input == "south" || input == "s")
            {
                room = "south";
            }
            
            else if(input == "North" || input == "north" || input == "n")
            {
                room = "north";
            }
            
            else if(input == "East" || input == "east" || input == "e")
            {
                
            }
            
            else
            {
                cout << "Sorry, but that is not a valid input\n";
            }
        }
        
        if(room == "north" && swordlevel == "0")
        {
            cout << "On the floor there is a strange box would you like to open it?\n";
            
            cin >> input;
            
            if(input == "yes")
            {
                cout << "Theres a piece of paper and under it you have found a level 1 sword! The paper says this sword could be very valueable so hold on to it!";
                swordlevel = "1";
            }
            
            else if(input == "no")
            {
                cout << "The box magically flew away and in the process locked the door so you cant get out! You died!";
                input = "q";
            }
            
            else
            {
                cout << "Sorry, but that is not a valid input\n";
            }
            
        }
        
        if(room == "north" && (swordlevel == "1" || swordlevel == "2"))
        {
            cout << "You can go back to the main room or you can try to open the door with a keypad.\n";
            cin >> input;
            
            if(input == "main" || input == "Main" || input == "m")
            {
                room = "begin";
            }
            
            if(input == "door" || input == "Door")
            {
                room = "door";
            }
            
        }
        
        if(room == "door")
        {
            cout << "What is the code?";
            cin >> input;
            
            if(input == "67854")
            {
                room = "northtwo";
            }
            
            else if(input != "67854")
            {
                cout << "Wrong. The door blew up.\n";
                input = "q";
            }
        }
        
        if(room == "south")
        {
            cout << "You hear buzzing. The door is closing in behind you. Do you want to run backwards or forwards?\n";
            cin >> input;
            
            if(input == "Forwards" || input == "forwards" || input == "f")
            {
                cout << "25 minions are coming at you! You are trying to fight them off!\n";
                
                if(swordlevel == "2" && strategy == "friend")
                {
                    cout << "Your friend helped you with the strategy and with your sword you slayed all the minions!\n";
                    minionskilled = "yes";
                    
                }
                
                if(strategy == "best")
                {
                    cout << "He is a great fighter, but he thought you were an enemy too! You died\n";
                    input = "q";
                }
                
                if(swordlevel == "1")
                {
                    cout << "Your sword is not powerful enough. You died.\n";
                    input = "q";
                }
            }
            
            if(input == "Backwards" || input == "backwards" || input == "b")
            {
                cout << "Its all gone WRONG! You went the wrong way and got ran over by the wall!\n";
                input = "q";
            }
            
        }
        
        if(room == "south" && minionskilled == "yes")
        {
            cout << "Theres only one direction you can go. That way is the way you came.\n";
            room = "begin";
        }
        
        if(room == "east")
        {
            cout << "You are in a sketchy hallway with a door and paint on the wall which says dapyek 67854\nYou have 2 options, you can go through the door or go back to main\n";
            cin >> input;
            
            if(input == "door" || input == "Door" || input == "d")
            {
                cout << "You opened the door and acid started coming out and it killed you in 5 mintues.";
                input = "q";
            }
            
            if(input == "main" || input == "Main" || input == "m")
            {
                room = "main";
            }
        }
        
        if(room == "west")
        {
            
        }
        
    }
}
