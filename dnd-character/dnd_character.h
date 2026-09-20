#pragma once

namespace dnd_character {

    int modifier(int x);
    int ability();
    class Character{
        public:
            Character();
            int strength;
            int dexterity;
            int constitution;
            int intelligence;
            int wisdom;
            int charisma;
            int hitpoints;
    };
    void rolling();

}  // namespace dnd_character
