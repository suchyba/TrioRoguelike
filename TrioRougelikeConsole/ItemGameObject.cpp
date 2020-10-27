#include "ItemGameObject.h"
#include "CreatureGameObject.h"

ItemGameObject::ItemGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor, int MinDamage, int MaxDamage) :
    bonusArmor(Armor), value(Value), minDamage(MinDamage), maxDamage(MaxDamage), GameObject(Name, Symbol)
{
    effect = dynamic_cast<EffectGameObject*>(Effect->clone());
    cout << getTag() << "Created ItemGameObject (armor=" << bonusArmor << ", minDamage=" << minDamage << ", maxDamage=" << maxDamage<< ", value=" << value << ", effect=" << (effect == NULL ? "NULL" : effect->getName()) << ")" << endl;
}

int ItemGameObject::getArmor() const
{
    return bonusArmor;
}
int ItemGameObject::getMinDamage() const
{
    return minDamage;
}
int ItemGameObject::getMaxDamage() const
{
    return maxDamage;
}

int ItemGameObject::getValue() const
{
    return value;
}

void ItemGameObject::onAttack(CreatureGameObject& opponent)
{
    cout << getTag() << "No effect when attacking with this item." << endl;
}

int ItemGameObject::onDamege(int damage, CreatureGameObject& self)
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

ItemGameObject::~ItemGameObject()
{
    if (effect)
        delete effect;
}
