#include "ArmorGameObject.h"
#include "CreatureGameObject.h"

ArmorGameObject::ArmorGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor):
	ItemGameObject(Value, Effect, Name, Symbol, Armor)
{

}

GameObject* ArmorGameObject::clone() const
{
	return new ArmorGameObject(*this);
}

int ArmorGameObject::onDamege(int damage, CreatureGameObject& self)
{
	self.addEffect(*effect);
	return damage;
}

ArmorGameObject::~ArmorGameObject()
{
}

