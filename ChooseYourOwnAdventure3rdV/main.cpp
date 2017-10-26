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
    int swordlevel = 0; // Changed to Int
    int health = 100;
    string minionskilled = "";
    string strategy = "";
    string monsterskilled = "";
    string planeticket = "";
    string water = "";
    
    cout << "Welcome to Choose Your Own Adventure!\n";
    cout << "Please enter your name.\n";
    cin >> name;
    cout << "Okay " << name << " Get ready to play!\n";
    room = "begin";
    while ((input != "q" && input != "Q") && health > 0)
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
                room = "east"; //Added this because it was blank and did nothing when the east option was chosen.
            }
            
            else
            {
                cout << "Sorry, but that is not a valid input\n";
            }
        }
        
        else if(room == "north" && swordlevel == 0)
        {
            cout << "On the floor there is a strange box would you like to open it?\n";
            
            cin >> input;
            
            if(input == "yes")
            {
                cout << "Theres a piece of paper and under it you have found a level 1 sword! The paper says this sword could be very valueable so hold on to it!";
                swordlevel = 1;
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
        
        else if(room == "north" && (swordlevel == 1 || swordlevel == 2))
        {
            cout << "You can go back to the main room or you can try to open the door with a keypad.\n";
            cin >> input;
            
            if(input == "main" || input == "Main" || input == "m")
            {
                room = "begin";
            }
            
            else if(input == "door" || input == "Door")
            {
                room = "door";
            }
            
        }
        
        else if(room == "door")
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
        
        else if(room == "south")
        {
            cout << "You hear buzzing. The door is closing in behind you. Do you want to run backwards or forwards?\n";
            cin >> input;
            
            if(input == "Forwards" || input == "forwards" || input == "f")
            {
                cout << "25 minions are coming at you! You are trying to fight them off!\n";
                
                if(swordlevel == 2 && strategy == "friend")
                {
                    cout << "Your friend helped you with the strategy and with your sword you slayed all the minions!\n You also have a piece of paper!";
                    minionskilled = "yes";
                    planeticket = "yes";
                    
                }
                
                else if(strategy == "best")
                {
                    cout << "He is a great fighter, but he thought you were an enemy too! You died\n";
                    input = "q";
                }
                
                else if(swordlevel == 1)
                {
                    cout << "Your sword is not powerful enough. You died.\n";
                    input = "q";
                }
            }
            
            if(input == "Backwards" || input == "backwards" || input == "b")
            {
                health -= 50;
                cout << "Its all gone WRONG! You went the wrong way and got ran over by the wall!\nYou have lost 50 Health! Your Health is now " << health << " You will be going back to main for now.\n";
                room = "begin";
            }
            
        }
        
        else if(room == "south" && minionskilled == "yes")
        {
            cout << "Theres only one direction you can go. That way is the way you came.\n";
            room = "begin";
        }
        
        else if(room == "east")
        {
            cout << "You are in a sketchy hallway with a door and paint on the wall which says dapyek 67854\nYou have 2 options, you can go through the door or go back to main\n";
            cin >> input;
            
            if(input == "door" || input == "Door" || input == "d")
            {
                health -= 80;
                cout << "You opened the door and acid started coming out and it injured you! You have lost 80 Health!" << " Your health is now " << health;
                room = "east";
            }
            
            else if(input == "main" || input == "Main" || input == "m")
            {
                room = "begin";
            }
        }
        
        else if(room == "west" && strategy == "")
        {
            cout << "You have found 2 people! You have found and expierenced friend with great strategy and a very good fighter. Which one would you like to fight with.\n";
            cin >> input;
            
            if(input == "Friend" || input == "friend" || input == "f")
            {
                cout << "Okay I cant wait to help you with if any unexpected fights occur!\n";
                strategy = "friend";
            }
            else if(input == "Fighter" || input == "fighter")
            {
                cout << "I will kill anything in sight! I will help you complete this adventure!\n";
                strategy = "best";
            }
        }
        
        else if(room == "west" && (strategy == "friend" || strategy == "best"))
        {
            cout << "We can go to main or we can go to get a taxi!\n";
            cin >> input;
            
            if(input == "main" || input == "Main" || input == "m")
            {
                room = "begin";
            }
            
            else if(input == "taxi" || input == "Taxi" || input == "t")
            {
                room = "taxi";
            }
        }
        
        else if(room == "northtwo")
        {
            cout << "A fight begins!\n There is no escape! What fight approach do you want to take? Slow or Fast?";
            cin >> input;
            
            if(input == "slow" || input == "Slow" || input == "s")
            {
                cout << "You killed 3 monsters however the 4th one got you!";
                input = "q";
            }
            
            else if((input == "fast" || input == "Fast" || input == "f") && swordlevel == 1)
            {
                cout << "You killed all 4 with one hit! That was impressive! Your sword has leveled up!\n";
                swordlevel = 2;
                monsterskilled = "yes";
            }
            
        }
        
        else if(room == "northtwo" && monsterskilled == "yes")
        {
             cout << "You will be teleported back to main";
             room = "main";
        }
        
        else if(room == "taxi")
        {
            cout  << "You hopped in the taxi.\nWhere would you like to go? The hot room or to the canyon?\n";
            cin >> input;
            if(input == "hot" || input == "Hot" || input == "h")
            {
                cout << "Your driver gives you a bottle of water.\n";
                room = "hotroom";
                water = "yes";
            }
            
            else if(input == "canyon" || input == "Canyon" || input == "c")
            {
                cout << "STOP! You yell. Your driver drove to far and the car went down the canyon and you crashed!";
                input = "q";
            }
        }
        
        else if(room == "hotroom")
        {
            cout << "Fire is everywhere!\nTheres monsters. Do you want to drink water or pour it on your sword.\n";
            cin >> input;
            
            if(input == "drink" || input == "Drink" || input == "d")
            {
                cout << "You needed the water on your sword to defeat the fire monsters!";
                input = "q";
            }
            else if(input == "pour")
            {
                if(swordlevel == 2)
                {
                    cout <<"You killed all the fire monsters because of the help from water!\nYou ran outside to take another Taxi and its taking you somewhere!\n";
                    room = "airport";
                }
                
                else if(swordlevel == 1)
                {
                    cout << "You had the correct idea but your sword wasnt strong enough!\n";
                    input = "q";
                }
            }
        }
        
        else if(room == "airport")
        {
            if(planeticket == "yes")
            {
                cout << "Congrats you made it on a plane to your hometown! That piece of paper was an important ticket! Congrats on your amazing adventure!";
            }
            
            else
            {
                cout << "Sorry you didnt have a plane ticket and you are stuck at the airport";
                input = "q";
            }
        }
    }
    return 0;
}
