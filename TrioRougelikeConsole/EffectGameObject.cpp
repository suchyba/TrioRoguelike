#include "EffectGameObject.h"
#include "CreatureGameObject.h"

void EffectGameObject::onInteraction()
{

}

void EffectGameObject::onRefresh()
{

}

EffectGameObject::EffectGameObject(string Name, GraphicalSymbol Symbol) : DynamicGameObject(Name, Symbol)
{
	cout << getTag() << "Created EffectGameObject" << endl;
}

bool EffectGameObject::onRefresh(GameObject& object)
{
	cout << getTag() << "Effect is affecting: " << object.getName() << endl;
	return false;
}
