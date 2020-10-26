#include "WeaponGameObject.h"
#include "CreatureGameObject.h"

WeaponGameObject::WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Damage) :
    ItemGameObject(Value, Effect, Name, Symbol, 0, Damage)
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
