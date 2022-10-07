#include <maze_solver.h>

maze_solver::maze_solver(wallToFollow wall, double threshold_right, double threshold_front,double threshold_left) {
    wall_folllow = wall;
    thresholdFront = threshold_front;
    thresholdLeft = threshold_left;
    thresholdRight = threshold_right;
}

bool maze_solver::WallFound(double threshold, double val){
    if (val < threshold) {
        return true;
    }else{
        return false;
    }
}

directions maze_solver::get_turn_directions(double front_dist, double right_dist, double left_dist) {
    bool wallRight, wallLeft, wallFront;
    wallRight = WallFound(thresholdRight, right_dist);
    wallLeft = WallFound(thresholdLeft, left_dist);
    wallFront = WallFound(thresholdFront, front_dist);

    if (wallFront == false && wallLeft == false && wallRight == false){
        return FOWARD;
    }else if (wallLeft == false && wallFront == false && wallRight == true) {
        if (wall_folllow == RIGHT_WALL){
            return FOWARD;
        }else {
            return LEFT;
        }
    }else if (wallLeft == false && wallFront == true && wallRight == false) {//POSSIBLE TOSS UP
        if (wall_folllow == RIGHT_WALL){
            return RIGHT;
        }else {
            return LEFT;
        }
    }else if (wallLeft == false && wallFront == true && wallRight == true) {
        return LEFT;
    }else if (wallLeft == true && wallFront == false && wallRight == false)
    {
        if (wall_folllow == RIGHT_WALL){
            return RIGHT;
        }else {
            return FOWARD;
        }
    }else if (wallLeft == true && wallFront == false && wallRight == true){
        return FOWARD;
    }else if (wallLeft == true && wallFront == true && wallRight == false){
        return RIGHT;
    }else{
        return TURN_AROUND;
    }
    
}