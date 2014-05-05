#ifndef FP_Position_h
#define FP_Position_h




/**
 * Possible Positions with in the model. LEFTH (Left Hallway).
 * Other positions include rooms with in the model
 *
 * @author  Michael Kapnick
 * @version 1.0
 */
enum Position
{
    LEFTH,
    RIGHTH,
    BACKH,
    FRONTH,
    MIDDLEH,
    ROOM_WITH_SIDES_AND_BACK,
    ROOM_WITH_SIDES_AND_BACK_NO_RUG
};
#endif