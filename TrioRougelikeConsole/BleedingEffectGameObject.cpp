#include "BleedingEffectGameObject.h"
#include "CreatureGameObject.h"

BleedingEffectGameObject::BleedingEffectGameObject(int Offset, int Duration, int MinDamage, int MaxDamage, string Name, GraphicalSymbol Symbol) : 
	offset(Offset), minDamage(MinDamage), maxDamage(MaxDamage),
	EffectGameObject(Duration, Name, Symbol)
{
//	cout << getTag() << "Created BleedingEffectGameObject (offset=" << offset << ", duration=" << duration << ", minDmg=" << minDamage << ", maxDmg=" << maxDamage << ")" << endl;
}

bool BleedingEffectGameObject::onRefresh(GameObject& object)
{
	CreatureGameObject* c = dynamic_cast<CreatureGameObject*>(&object);
	if (c == NULL)
		return false;
	
	if (frameFromStart % offset == 0)
	{
		//cout << getTag() << "Dealing damage to creature: " << c->getName() << endl;
		c->directDmg(minDamage + rand() % (maxDamage - minDamage + 1));
		++frameFromStart;
		--duration;
		if (duration <= 0)
		{
			c->removeEffect(name);
		}
	}
	else
		++frameFromStart;

	return true;
}

GameObject* BleedingEffectGameObject::clone() const
{
	return new BleedingEffectGameObject(*this);
}

BleedingEffectGameObject::~BleedingEffectGameObject()
{

}
