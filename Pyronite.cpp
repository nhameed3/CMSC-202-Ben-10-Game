/*Title: Pyronite.cpp
Author: Nauman Hameed
Date: 11/29/16
Section: 17
Description: Child class of Ben, one of the aliens he can transform into.
*/
#include "Monster.h"
  
  // One of the virtual functions of Ben 
  void Pyronite::Attack(Monster *&target)
  {
    int life;
    int damage = rand()%m_maxDamageNormal + m_minDamageNormal;
    int probability = rand()%100+1;
    if(probability>=1 && probability<=15)  // Allows Pyronite to miss
      cout << m_name << " missed! " << target->GetName() << " retaliates!" << endl;
    else
    {
      cout << m_name << " attacks using " << m_nameNormal << " attack." << endl;
      cout << m_name << " did " << damage << " to " << target->GetName() << "." <<endl;
      life = target->GetLife() - damage;
      target->SetLife(life); 
    }
  }
  
  
  // One of the virtual functions of Ben
  void Pyronite:: SpecialAttack(Monster *&target)
  {
   int life;
   int damage = m_damageSpecial;
   if(m_usedSpecial>=1)
      cout << m_name << " is out of special attacks! " << target->GetName() << " retaliates!" << endl;
   else
    {
      cout << m_name << " attacks using his " << m_nameSpecial << " attack." << endl;
      cout << m_name << " did " << damage << " to " << target->GetName() << "." << endl;
      life = target->GetLife() - damage;
      target->SetLife(life);
      m_usedSpecial++;
    } 
  }