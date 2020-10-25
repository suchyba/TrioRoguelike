#include "ItemGameObject.h"
#include "CreatureGameObject.h"

ItemGameObject::ItemGameObject(int armor, int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol) :
    bonusArmor(armor), value(Value), damage(0), GameObject(Name, Symbol)
{
    if (Effect)
        effect = new EffectGameObject(*Effect);
    else
        effect = NULL;

    cout << getTag() << "Created armor ItemGameObject (armor=" << bonusArmor << ", value=" << value << ", effect=" << (effect == NULL ? "NULL" : effect->getName()) << ")" << endl;
}

ItemGameObject::ItemGameObject(string Name, int Damage, int Value, const EffectGameObject* Effect, GraphicalSymbol Symbol) :
    bonusArmor(0), value(Value), damage(Damage), GameObject(Name, Symbol)
{
    if (Effect)
        effect = new EffectGameObject(*Effect);
    else
        effect = NULL;

    cout << getTag() << "Created weapon ItemGameObject (damage=" << damage << ", value=" << value << ", effect=" << (effect == NULL ? "NULL" : effect->getName()) << ")" << endl;
}

ItemGameObject::ItemGameObject(int armor, int Damage, int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol) :
    bonusArmor(armor), value(Value), damage(Damage), GameObject(Name, Symbol)
{
    if (Effect)
        effect = new EffectGameObject(*Effect);
    else
        effect = NULL;

    cout << getTag() << "Created addon ItemGameObject (armor=" << bonusArmor << ", damage = " << damage << ", value=" << value << ", effect=" << (effect == NULL ? "NULL" : effect->getName()) << ")" << endl;
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
    cout << getTag() << "Effect when equipping!" << endl;
}
