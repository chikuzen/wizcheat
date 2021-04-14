wizcheat:
 A character editor for Wizardry#1, #2 and #3 for IBM-PC(Dosbox).

usage: wizcheat <DSK file> <character's name> <action> [<action> ...]

example: wizcheat C:\wiz1to3\SAVE1.DSK DEADPOOL NEUTRAL NINJA ALL18 ITEM EXP EXP GOLD
    (A character named DEADPOOL becomes a NEUTRAL NINJA with
     all stats values of 18, and gains the strongest equipments,
     20 levels of experience and 1000000 gold.)

actions:
    FIGHTER - change character's class to FIGHTER.
    MAGE    - change character's class to MAGE.
    PRIEST  - change character's class to PRIEST.
    THIEF   - change character's class to THIEF.
    BISHOP  - change character's class to BISHOP.
    SAMURAI - change character's class to SAMURAI.
    LORD    - change character's class to LORD.
    NINJA   - change character's class to NINJA.
    GOOD    - change character's alignment to GOOD.
    NEUTRAL - change character's alignment to NEUTRAL.
    EVIL    - change character's alignment to EVIL.
    HUMAN   - change character's race to HUMAN.
    ELF     - change character's race to HUMAN.
    DWARF   - change character's race to HUMAN.
    GNOME   - change character's race to HUMAN.
    HOBBIT  - change character's race to HUMAN.
    ALL18   - change character's all stats to 18.
    CURE    - change character's condition
              ('PARALY', 'STONED', 'DEAD', 'ASHED' and 'LOST') to 'OK'.
    ITEM    - change character's items to the most powerful ones for the class.
    AGE     - decrease character's age to zero.
    GOLD    - increase character's gold by 1,000,000.
    EXP     - increase character's experience by 10 levels.
    RESET   - reset character's password.
    others  - print the character's status, and quit without saving.

*** NOTE ***
This tool will rewrite the DSK file.
You should make a backup before using this.
