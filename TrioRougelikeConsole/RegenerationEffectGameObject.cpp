#include "RegenerationEffectGameObject.h"
#include "CreatureGameObject.h"

RegenerationEffectGameObject::RegenerationEffectGameObject(int Offset, int Duration, int RegeneredHP, string Name, GraphicalSymbol Symbol) :
	offset(Offset), regeneratedHP(RegeneredHP),
	EffectGameObject(Duration, Name, Symbol)
{

}

bool RegenerationEffectGameObject::onRefresh(GameObject& object)
{
	CreatureGameObject* c = dynamic_cast<CreatureGameObject*>(&object);
	if (c == NULL)
		return false;

	if (frameFromStart % offset == 0)
	{
		//cout << getTag() << "Healing creature: " << c->getName() << endl;
		c->directDmg(-regeneratedHP);
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

GameObject* RegenerationEffectGameObject::clone() const
{
	return new RegenerationEffectGameObject(*this);
}

RegenerationEffectGameObject::~RegenerationEffectGameObject()
{
}
