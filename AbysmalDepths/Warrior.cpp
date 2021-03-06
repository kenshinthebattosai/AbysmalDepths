/*
"Abysmal Depths" is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

"Abysmal Depths" is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with "Abysmal Depths".  If not, see <http://www.gnu.org/licenses/>.
*/

#include"Includes.h"

string Warrior::getClass()
{
	return "Warrior";
}

Warrior::Warrior(string newName)
{
	name=newName;
	heroType=1;
	xp=level=0;
	xpMod=1;
	strength=5;
	maxHP=curHP=(int)(strength*2.5);
	dexterity=2;
	damageMultiplier=dexterity*1.05;
	critMultiplier=1.05;
	meleeDamage=5;
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock=5;
	block=3;
	chanceToEvade=1;
	endurance=5;
	maxStamina=curStamina=(int)(endurance*1.5);
	knowledge=3;
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	stealth=1;
	chanceToEvade+=stealth;
}

void Warrior::updateAttributes()
{
	strength+=(2*xpMod);
	endurance+=(2*xpMod);
	dexterity+=(1*xpMod);
	knowledge+=(1*xpMod);
	stealth+=(1*xpMod);
}

void Warrior::updateStats()
{
	maxHP=curHP=(int)(strength*2.5);
	damageMultiplier=dexterity*1.05;
	critMultiplier+=(0.05*xpMod);
	meleeDamage+=(5*xpMod);
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock+=(5*xpMod);
	block+=(3*xpMod);
	chanceToEvade+=(1*xpMod);
	maxStamina=curStamina=(int)(endurance*1.5);
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	chanceToEvade+=stealth;
}
