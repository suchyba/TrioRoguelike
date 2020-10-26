#include "ItemGameObject.h"
#include "CreatureGameObject.h"

ItemGameObject::ItemGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor, int Damage) :
    bonusArmor(Armor), value(Value), damage(Damage), GameObject(Name, Symbol)
{
    effect = dynamic_cast<EffectGameObject*>(Effect->clone());
    cout << getTag() << "Created ItemGameObject (armor=" << bonusArmor << ", damage=" << damage << ", value=" << value << ", effect=" << (effect == NULL ? "NULL" : effect->getName()) << ")" << endl;
}

int ItemGameObject::getArmor() const
{
    return bonusArmor;
}

int ItemGameObject::getDamage() const
{
    return damage;
}

int ItemGameObject::getValue() const
{
    return value;
}

void ItemGameObject::onAttack(CreatureGameObject& opponent)
{
    cout << getTag() << "Effect when attacking with this item." << endl;
    opponent.addEffect(*effect);
}

int ItemGameObject::onDamege(int damage)
{
    return damage;
}

void ItemGameObject::onActivation()
{

}

void ItemGameObject::onEquipping(CreatureGameObject& creature)
{
    cout << getTag() << "Event when equipping!" << endl;
}
