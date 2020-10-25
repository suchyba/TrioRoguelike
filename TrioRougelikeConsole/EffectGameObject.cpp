#include "EffectGameObject.h"

void EffectGameObject::onInteraction()
{

}

EffectGameObject::EffectGameObject(string Name, GraphicalSymbol Symbol) : DynamicGameObject(Name, Symbol)
{
	cout << getTag() << "Created EffectGameObject" << endl;
}

void EffectGameObject::onRefresh()
{

}
