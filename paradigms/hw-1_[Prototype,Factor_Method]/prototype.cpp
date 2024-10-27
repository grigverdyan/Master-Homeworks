#include <iostream>
#include <vector>
#include <memory>


struct Point
{
    double  x;
    double  y;

    Point (double x = 0, double y = 0)
        : x(x), y(y)
    {}
};

class Shape
{
public:
    Point   center;
    double  size;

    Shape(Point c = {0, 0}, double s = 1)
        : center(c), size(s)
    {}

    virtual ~Shape() = default;
    virtual void print() const = 0;
    virtual std::unique_ptr<Shape> clone(Point new_center, double new_size) const = 0;
};

class Square : public Shape
{
public:
    Square(Point c = {0, 0}, double s = 1) 
        : Shape(c, s) 
    {}

    void print() const override
    {
        std::cout << "Square: Center -> (" << center.x << ", " << center.y << "), Size -> " << size << std::endl;
    }

    std::unique_ptr<Shape> clone(Point new_center, double new_size) const override
    {
        return std::make_unique<Square>(new_center, new_size);
    }
};

class Circle : public Shape
{
public:
    Circle(Point c = {0, 0}, double s = 1) 
        : Shape(c, s) 
    {}

    void print() const override
    {
        std::cout << "Circle: Center -> (" << center.x << ", " << center.y << "), Size -> " << size << std::endl;
    }

    std::unique_ptr<Shape> clone(Point new_center, double new_size) const override
    {
        return std::make_unique<Circle>(new_center, new_size);
    }
};

class Triangle : public Shape
{
public:
    Triangle(Point c = {0, 0}, double s = 1) 
        : Shape(c, s) 
    {}

    void print() const override
    {
        std::cout << "Triangle: Center -> (" << center.x << ", " << center.y << "), Size -> " << size << std::endl;
    }

    std::unique_ptr<Shape> clone(Point new_center, double new_size) const override
    {
        return std::make_unique<Triangle>(new_center, new_size);
    }
};

class Wave {
public:
    void addShape(std::unique_ptr<Shape> shape)
    {
        shapes.push_back(std::move(shape));
    }

    void print() const
    {
        for (const auto& shape : shapes)
        {
            shape->print();
        }
    }

private:
    std::vector<std::unique_ptr<Shape>> shapes;
};

class Client
{
public:
    Client(std::unique_ptr<Shape> shape) 
        : shape(std::move(shape)) 
    {}

    Wave makeWave(Point center)
    {
        Wave result;
        result.addShape(shape->clone(center, 1));
        result.addShape(shape->clone(center, 2));
        result.addShape(shape->clone(center, 3));
        return result;
    }

private:
    std::unique_ptr<Shape> shape;
};

int main()
{
    Client client(std::make_unique<Circle>());
    Wave wave = client.makeWave({0, 0});
    wave.print();

    return 0;
}
