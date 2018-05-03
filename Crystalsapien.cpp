/*Title: Crystalsapien.cpp
Author: Nauman Hameed
Date: 11/29/16
Section: 17
Description: Child class of Ben, one of the aliens he can transform into.
*/
#include "Crystalsapien.h"
#include "Monster.h"
  
//Allow Crystalsapien to use normal attack, one of the functions of Ben
  void Crystalsapien::Attack(Monster *&target)
  {
    int life;
    int damage = rand()%m_maxDamageNormal + m_minDamageNormal;
    int probability = rand()%100+1;
    if(probability>=1 && probability<=25)
      cout << m_name << " missed! " << target->GetName() << " retaliates!" << endl;
    else
    {
      cout << m_name << " attacks using " << m_nameNormal << " attack." << endl;
      cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
      life = target->GetLife() - damage;
      target->SetLife(life); 
    }
  }
  
  
  //Allows Crystalsapien to use special attack, one of the functions of Ben.
  void Crystalsapien::SpecialAttack(Monster *&target)
  {
   int life;
   int damage = m_damageSpecial;
   if(m_usedSpecial>=1)            //limits his special attack to 1 use.
      cout << m_name << " is out of special attacks! " << target->GetName() << " retaliates!" << endl;
   else
    {
      cout << m_name << "  attacks using his " << m_nameSpecial << " attack." << endl;
      cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
      life = target->GetLife() - damage;
      target->SetLife(life);
      m_usedSpecial++;
    } 
  } 


//Crystalsapien has an ultimate attack unlike sibling and parent class.
  void Crystalsapien::UltimateAttack(Monster *&target)
  {
   int life;
   int damage = m_damageSpecial*10; //damage is ten times more!
   cout << m_name << " attacks using **ULTIMATE** ATTACK!! " << endl;
   cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
   life = target->GetLife() - damage;
   target->SetLife(life);
  }
