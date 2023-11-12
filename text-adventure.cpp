#include <iostream>
#include <ctime>
#include <stdlib.h>

int main(){

    // Keeps randomization random and not static after one run.
    srand(time(NULL));

    int playerHealth = 1000;
    int enemyHealth = 1000;

    std::cout << "It's grand finals time, let's have ourselves a grand battle!\n";

    while(playerHealth > 0 && enemyHealth > 0){
        int playerChoice;
        int enemyChoice = rand() % 3 + 1;

        int dodge = rand() % 5 + 1;
        bool block;
        bool enemyBlock;

        block = false;
        std::cout << "Player Health: " << playerHealth << "HP\t Enemy Health: " << enemyHealth << "HP\n";
        std::cout << "Pick your move:\n1) Shoryuken\n2) Shinkuu Hadouken\n3) Block\n";
        std::cin >> playerChoice;
        
        // Player's choice of attacks so long as they are still alive
        if(playerHealth > 0){    
            switch(playerChoice){
                case 1:
                    std::cout << "The player goes for a Shoryuken Uppercut!\n";
                    if(dodge != 4 || dodge != 5){
                        std::cout << "What a staggering attack! A direct hit!\n";
                        if(enemyBlock){
                            enemyHealth -= 15;
                        }else{
                            enemyHealth -= 30;
                        }
                    }else{
                        std::cout << "A major whiff on the player's part! You're open to attack!\n";
                    }
                    break;
                case 2:
                    std::cout << "The player risks it all for a Shinkuu Hadouken!\n";
                    if(dodge == 1 || dodge == 2){
                        std::cout << "Bull's Eye! The enemy is weak to the knees!\n";
                        if(enemyBlock){
                            enemyBlock -= 45;
                        }else{
                            enemyHealth -= 90;
                        }
                    }else{
                        std::cout << "Uh-Oh! The enemy side-stepped your projectile leaving you wide open!\n";
                    }
                    break;
                case 3:
                std::cout << "The player takes a blocking stance! Here comes the enemy strike!\n";
                    block = true;
                    break;
                default:
                    std::cout << "Player, you gotta make a choice, the enemy is ready to bash you in! Watch out!!\n";
                    break;
            }
        }
        //---
        // Enemy's choice of attacks so long as they are still alive
        enemyBlock = false;
        if(enemyHealth > 0){
            switch(enemyChoice){
                case 1:
                    std::cout << "The enemy goes for an Electric Wind God Fist Uppercut!\n";
                    if(dodge != 4 || dodge != 5){
                        std::cout << "The player is taken down! Right on the target!\n";
                        if(block){
                            playerHealth -= 15;
                        }else{
                        playerHealth -= 30;
                        }
                    }else{
                        std::cout << "The player ducked the high attack! Get ready to strike back, player!\n";
                    }
                    break;
                case 2:
                    std::cout << "Here comes the enemy's Rage Art!\n";
                    if(dodge == 1 || dodge == 2){
                        std::cout << "Devastating damage! A laser right through the player's chest!\n";
                        if(block){
                            playerHealth -= 45;
                        }else{
                        playerHealth -= 90;
                        }
                    }else{
                        std::cout << "The player parried the super! Let's go player!\n";
                    }
                    break;
                case 3:
                    std::cout << "The enemy chooses to stand still! How will the player react?!\n";
                    enemyBlock = true;
                    break;
                default:
                    std::cout << "Enemy, you gotta make a choice, the player is ready to bash you in! Watch out!!\n";
                    break;
            }
        }
    }
    if(enemyHealth <= 0){
        std::cout << "Congratualtions on your tournament victory, Player!\n";
    }else if(playerHealth <= 0){
        std::cout << "Give a round of applause to the tournament victor, Enemy!\n";
    }
    return 0;
}
/*
GAME STORYBOARD
-You are in a fighting tournament and made it to grand finals

GAMEPLAY LOOP
-Choose to attack
-Choose to defend
-Attack enemy and defend from enemy
-Some attacks may miss

OUTCOMES
-You win the fight
-You lose the fight
-Tie game
*/