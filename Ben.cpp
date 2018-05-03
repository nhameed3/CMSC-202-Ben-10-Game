/*Title: Ben.cpp
Author: Nauman Hameed
Date: 11/29/16
Section: 17
Description: Ben Tennyson and his functions, virtual functions, etc.
*/
#include "Ben.h"
#include "Monster.h"
//Default Constructor of Ben.
Ben::Ben(string name, int life)
{
  m_name = name;
  m_life = life;
}

//Overloaded Constructor of Ben.
Ben::Ben(string name, int life, string nameNorm, string nameSpecial,
	  double defenseBonus, double missPercent, int usedSpecial,
	  int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec)
{
  m_name = name;
  m_life = life;
  m_nameNormal = nameNorm;
  m_nameSpecial = nameSpecial;
  m_defenseBonus = defenseBonus;
  m_missPercent = missPercent;
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial;
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm;
  m_damageSpecial = damSpec;
}

//Destructor for Ben.
Ben::~Ben()
{
	
}

//Function allows Ben to fight his Monster nemisis.
void Ben::Attack(Monster *&target)
{
 int life;
 int damage = rand()%m_maxDamageNormal+m_minDamageNormal;    //generates attack damage between range.
 int probability = rand()%100+1;
 if(probability>=1 && probability<=10)											// Allows Ben a 90 percent hit chance.
   cout << m_name << " missed! "<< target->GetName() << " retaliates!" << endl;
 else
   {
     cout << m_name << " attacks using his "<< m_nameNormal <<" attack." << endl;
     cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
     life = target->GetLife() - damage;
     target->SetLife(life); 																//Adjusts the life of the Monster after being hit.
   }
}


//Function allows Ben to use his special attack
void Ben::SpecialAttack(Monster *&target)
{
  int life;
  int damage = m_damageSpecial;
  if(m_usedSpecial>=2)									//Special Attacks are limited to 2.
      cout << "Ben is out of special attacks! " << target->GetName() << " retaliates!" << endl;
  else
    {
      cout << m_name <<" attacks using his "<< m_nameSpecial << " attack." << endl;
      cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
      life = target->GetLife() - damage;
      target->SetLife(life);
      m_usedSpecial++;
    }
}


//Informs the user of Ben's lack of Ultimate attacks.
void Ben::UltimateAttack(Monster *&target)
{
  cout << m_name << " has no ultimate attack! " << target->GetName() << " retaliates! " << endl;
}


//Setter allows adjustment of the current Ben's life.
void Ben::SetLife(int life)
{
  m_life = life;
}

//Getter to obtain the current Ben's name.
string Ben::GetName()
{
  return m_name;	
}

//Getter to obtain the current Ben's life.
int Ben::GetLife()
{
  return m_life;
}

//Getter to obtain the current Ben's defenseBonus.
double Ben::GetDefenseBonus()
{  
	return m_defenseBonus;
}