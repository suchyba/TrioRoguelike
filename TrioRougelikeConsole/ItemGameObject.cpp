#include "ItemGameObject.h"

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

void ItemGameObject::onAttack(CreatureGameObject* opponent)
{

}

void ItemGameObject::onDamege(int damage)
{
}

void ItemGameObject::onActivation()
{
}
