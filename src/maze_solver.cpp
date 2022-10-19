#include <include/maze_solver.h>

maze_solver::maze_solver(wallToFollow wall, double threshold_right, double threshold_front, double threshold_left)
{
    this->wall_folllow = wall;
    this->thresholdFront = threshold_front;
    this->thresholdLeft = threshold_left;
    this->thresholdRight = threshold_right;
}

bool maze_solver::WallFound(double threshold, double val)
{
    if (val < threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}

directions maze_solver::get_turn_directions(double front_dist, double right_dist, double left_dist)
{
    bool wallRight, wallLeft, wallFront;
    wallRight = WallFound(thresholdRight, right_dist);
    wallLeft = WallFound(thresholdLeft, left_dist);
    wallFront = WallFound(thresholdFront, front_dist);

    // Truth table
    // Left Front Right Decisiom
    //  0     0     0      F
    //  0     0     1      F
    //  0     1     0      L
    //  0     1     1      L
    //  1     0     0      F
    //  1     0     1      F
    //  1     1     0      R
    //  1     1     1      T
    if (wallLeft == false && wallFront == false && wallRight == false)
    {
        return FOWARD;
    }
    else if (wallLeft == false && wallFront == false && wallRight == true)
    {
        return FOWARD;
    }
    else if (wallLeft == false && wallFront == true && wallRight == false)
    {
        return LEFT;
    }
    else if (wallLeft == false && wallFront == true && wallRight == true)
    {
        return LEFT;
    }
    else if (wallLeft == true && wallFront == false && wallRight == false)
    {
        return FOWARD;
    }
    else if (wallLeft == true && wallFront == false && wallRight == true)
    {
        return FOWARD;
    }
    else if (wallLeft == true && wallFront == true && wallRight == false)
    {
        return RIGHT;
    }
    else if (wallLeft == true && wallFront == true && wallRight == true)
    {
        return TURN_AROUND;
    }                     
    else
    {
        return TURN_AROUND;
    }
}