#ifndef SHAPE04_01_POINT_H
#define SHAPE04_01_POINT_H


class Point {
public:
    Point(double x, double y);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

private:
    double x;
    double y;

};


#endif //SHAPE04_01_POINT_H
