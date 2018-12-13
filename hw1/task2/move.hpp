#pragma once

class Move {
private:
    mutable double x;
    mutable double y;

public:
    Move(double a = 0, double b = 0); // sets x, y to a, b
    void showmove() const; // shows current x, y values
    Move add(const Move &) const ;
    // this function adds x of m to x of invoking object to get new x,
    // adds y of m to y of invoking object to get new y, creates a new
    // move object initialized to new x, y values and returns it
    void reset(double, double); // resets x,y to a, b
};