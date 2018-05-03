/*Title: Game.cpp
Author: Nauman Hameed
Date: 11/29/16
Section: 17
Description: Contains the driver of the game along with its helper functions.
*/
#include"Game.h"

//Constructor of Game
Game::Game()
{
 m_level =  1;
 m_levels = NumLevels();
 m_formsBen = 0;
 Start(0);
}

/*Destructor of Game iterates through
the arrays to free memory.*/
Game::~Game()
{
	for(int i = 0; i < m_levels; i++)
	{
		delete m_mons[i];
	}
	for(int i = 0; i < 3; i++)
	{
		delete m_ben[i];
	}
	 delete [] m_mons;
   m_mons = NULL;
	 delete [] m_ben;
	 m_ben = NULL;
}


//Dynamically populates m_mons with one monster per level.
void Game::InitMonsters()
{
 m_mons = new Monster*[20]; 
 for(int i = 0; i < m_levels; i++)
	{
		m_mons[i] = new Monster(i+1);
	}
}

//Dynamically populates m_ben with all his possible forms.
void Game::InitBen()
{
  m_ben = new Ben*[3];
  m_ben[0] = new Ben("Ben", 100, "hand-to-hand", "kick", 0, 10, 0, 10, 2, 20, 25);
  m_ben[1] =  new Pyronite("Pyronite", 100, "fire", "flamer", 0, 15, 0, 15, 1, 20, 30);
  m_ben[2] = new Crystalsapien("Crystalsapien", 100, "energy", "laser", 25.0, 25, 0, 25, 1, 30, 10);
}


//Allows the user to select from the forms of Ben available at their level.
void Game::SetBen(int startLife)
{
 cout << "Select one from the available forms of Ben at level " << m_level << " are: " << endl;
 //Do while loops to ensure that the user inputs an integer within range. VALIDATION.
	if(m_level == 1)
 {
	 do
	 {
		 cout << "1.Ben" << endl;
		 cin >> m_formsBen;
		 if(m_formsBen != 1)
			 cout << "Invalid input; please re-enter." << endl;
	 }while(m_formsBen != 1);
 } 
 if(m_level == 2)
 {
	 do
	 {
	 	cout << "1.Ben" << endl;
	 	cout << "2.Pyronite" << endl;
		cin >> m_formsBen;
		 if(m_formsBen < 1 || m_formsBen > 2 )
			 cout << "Invalid input; please re-enter." << endl;
	 }while(m_formsBen < 1 || m_formsBen > 2);
 }
	if(m_level >= 3)
	{
		do
		{
	 		cout << "1.Ben" << endl;
	 		cout << "2.Pyronite" << endl;
	 		cout << "3.CrystalSapien" << endl;
			cin >> m_formsBen;
			if(m_formsBen < 1 || m_formsBen > 3)
				cout << "Invalid input; please re-enter." << endl;
		}while(m_formsBen < 1 || m_formsBen > 3);
	}
	cout << "What would you like to do?" << endl;
	//Switch statement sets Ben based on user input and intializes his health.
	switch(m_formsBen)
	{
		case 1:
		m_currBen = m_ben[0];
		m_currBen->SetLife(startLife);
		cout << "BEN: Ben" << endl;
		break;
		case 2:
		m_currBen = m_ben[1];
		m_currBen->SetLife(startLife);
		cout << "BEN: Pyronite" << endl;
		break;
		case 3:
		m_currBen = m_ben[2];
		m_currBen->SetLife(startLife);
		cout << "BEN: CrystalSapien" << endl;
		break;
	}
	m_currMons = m_mons[m_level-1];           //Sets the current Monster for the level.
	cout << "MONSTER: " << m_currMons->GetName() << endl;
	cout << "The start life of Ben is: " << m_currBen->GetLife() << endl;
	cout << "The start life of Monster is: " << m_currMons->GetLife() << endl;
}


//Primary Driver for the game.
void Game::Start(int startLife)
{
	InitBen();
 	InitMonsters();
	cout << "            The game starts... " << endl;
	cout << "            LEVEL " << m_level << " of " << m_levels << endl;
  SetBen(100);
  while(m_currBen->GetLife()>0  && m_level <= m_levels)        //Makes sure to loop while Ben is alive and levels are valid
  {
		startLife = m_currBen->GetLife();
   	Input();
		if(m_currMons->GetLife() > 0)                           //Monster can only attack if it is alive.
			{m_currMons->Attack(m_currBen);}
		cout << "Ben: " << m_currBen->GetLife() << "      Monster: " << m_currMons->GetLife() << endl;
		startLife = m_currBen->GetLife();
    if(m_currMons->GetLife()<=0)
      {
				cout << "Congrats! " << m_currBen->GetName() << " won that level." << endl;
				m_level++;               
				if(m_level <= m_levels)   //Proceeds to the next level only if valid.
				{
					cout << "            The game starts..." << endl;
					cout << "            LEVEL " << m_level << " of " << m_levels << endl;
					SetBen(startLife);
				}
      }
		
  }
	
	//Checks to see if ben is alive, Monster Wins if he isnt.
  if(m_currBen->GetLife()<=0)
    {    
			cout << m_currMons->GetName() << " wins." << endl;
      cout << m_currBen->GetName() << " lost." << endl;
      cout << "You Lose." << endl;
    }
	
	//Checks to see if the Monster is alive, Ben wins if it isnt.
	if(m_currMons->GetLife() <= 0)
	{
		cout << "Congrats! you won the game." << endl;
	}
}

//Allows user to select number of levels they would like to play within 1-20
int Game::NumLevels()
{
	//do while reprompts if not in range. VALIDATION.
	do
	{
  	cout <<"How many levels would you like to try?"<<endl;
  	cin >> m_levels;
		if(m_levels < 1 || m_levels > 20 )
			cout << "You should do less than 20 levels!" << endl;
	}while(m_levels < 1 || m_levels > 20);
  return m_levels;
}


//Allows current version of Ben to attack, user picks attack.
bool Game::Input()
{
  int choice;
	if(m_currBen->GetLife()>0 && m_currMons->GetLife()>0)
	{
	//Do while to ensure within range. VALIDATION.
		do
		{
  		cout << "What would you like to do?" << endl;
  		cout << "1. Normal Attack" << endl;
  		cout << "2. Special Attack" << endl;
  		cout << "3. Ultimate Attack" << endl;
  		cout << "Enter 1 to 3: " << endl;
  		cin >> choice;
			if(choice < 1 || choice > 3)
				cout << "Invalid input; please re-enter." << endl;
		}while(choice < 1 || choice > 3);
		switch(choice)
    	{
    	case 1:
      	m_currBen->Attack(m_currMons);
      	break;
    	case 2:
      	m_currBen->SpecialAttack(m_currMons);
      	break;
    	case 3:
      	m_currBen->UltimateAttack(m_currMons);
      	break;
    	}
	}
	//Checks life of Ben and returns false if he is defeated.
  if(m_currBen->GetLife()<=0)
    {
			return false;
    }
  return true;
}

