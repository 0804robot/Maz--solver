#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

typedef enum {
    RIGHT_WALL,
    LEFT_WALL,
}   wallToFollow;

typedef enum {
    RIGHT,
    LEFT,
    FOWARD,
    BACKWARD,
    BRAKE,
    TURN_AROUND,
} directions;

class maze_solver
{
private:
    wallToFollow wall_folllow;
    double thresholdRight;
    double thresholdLeft;
    double thresholdFront;
    bool WallFound(double threshold, double val);
public:
    maze_solver(wallToFollow wall, double threshold_right, double threshold_front,double threshold_left);
    directions get_turn_directions(double front_dist, double right_dist, double left_dist);
};

#endif