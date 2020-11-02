#include "EffectGameObject.h"
#include "CreatureGameObject.h"

void EffectGameObject::onInteraction()
{

}

void EffectGameObject::onRefresh()
{

}

EffectGameObject::EffectGameObject(int Duration, string Name, GraphicalSymbol Symbol) : 
	duration(Duration),
	DynamicGameObject(Name, Symbol)
{
	cout << getTag() << "Created EffectGameObject" << endl;
}

bool EffectGameObject::onRefresh(GameObject& object)
{
	cout << getTag() << "Effect is affecting: " << object.getName() << endl;
	return false;
}

GameObject* EffectGameObject::clone() const
{
	return new EffectGameObject(*this);
}

int EffectGameObject::getDuration() const
{
	return duration;
}

EffectGameObject::~EffectGameObject()
{
}
