#include "WeaponGameObject.h"
#include "CreatureGameObject.h"

WeaponGameObject::WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int MinDamage, int MaxDamage) :
    ItemGameObject(Value, Effect, Name, Symbol, 0, MinDamage, MaxDamage)
{
    cout << getTag() << "Created WeaponGameObject" << endl;
}

GameObject* WeaponGameObject::clone() const
{
    return new WeaponGameObject(*this);
}

void WeaponGameObject::onAttack(CreatureGameObject& opponent)
{
    if (effect) {
        cout << getTag() << "Applying weapon effect (" << effect->getName() << ") on opponent : " << opponent.getName() << endl;
        opponent.addEffect(*effect);
    }
}

WeaponGameObject::~WeaponGameObject()
{

}
