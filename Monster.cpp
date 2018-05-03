/*Title: Monster.cpp
Author: Nauman Hameed
Date: 11/29/16
Section: 17
Description: The enemies Ben Tennyson.
*/
#include "Monster.h"
#include "Ben.h"
//Monster Constructor takes in the level
Monster::Monster(int level)
{
  LoadMonster();
  m_name = SummonMonster();
  //Sets life and attack based by level from chart given for the project.
  if(level == 1)
  {
    m_life = 20+(rand()%(50-20+1));
    m_attack = 1+(rand()%(5-1+1));
  }
  if(level == 2)
  {
    m_life = 30+(rand()%(60-30+1));
    m_attack = 3+(rand()%(10-3+1));
  }
  if(level >= 3)
  {
    m_life = 40+(rand()%(70-40+1));
    m_attack = 5+(rand()%(15-5+1));
  }
}

//Monster Destructor 
Monster::~Monster()
{
 
}

//Returns the name of a random monster from m_monster.
string Monster::SummonMonster()
{
  int i = rand()%29+1;
  string monsterName = m_monster[i];
  return monsterName;
}

//Loads the names of the monsters into the structure m_monster.
void Monster::LoadMonster()
{
  string name;
  ifstream inStream;
  inStream.open("monster.txt");
  while(getline(inStream, name))
    {
      m_monster.push_back(name);
    }
}

//Allows Monster to attack Ben.
void Monster::Attack(Ben *&target)
{
  int life;
  cout << m_name << " attacks " << target->GetName() << " using a normal attack." << endl;
  if(target->GetName() == "Crystalsapien")
    {m_attack = m_attack-(m_attack*0.25);}            //To account for the defenseBonus Crystalsapien has.
  cout << m_name << " did " << m_attack << " to Ben." << endl;
  life = target->GetLife() - m_attack;
  target->SetLife(life);  //Sets Ben's life to account for damage done by monster.
}


//Setter allows adjustment of the current Monster's life.
void Monster::SetLife(int life)
{
  m_life = life;
}

//Getter to obtain the life of the current Monster.
int Monster::GetLife()
{
  return m_life;
}

//Gettter to obtain the name of the current Monster.
string Monster::GetName()
{ 
  return m_name;
}
