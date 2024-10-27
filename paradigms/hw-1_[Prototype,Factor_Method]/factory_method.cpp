#include <iostream>
#include <vector>
#include <memory>

struct Point
{
    double  x;
    double  y;

    Point(double x = 0, double y = 0) 
        : x(x), y(y)
    {}
};

class Shape
{
public:
    Point center;
    int size;

public:
    Shape(Point c = {0, 0}, double s = 1)
        : center(c), size(s)
    {}
    
    virtual ~Shape() = default;
    virtual void print() const = 0;
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

class Creator {
public:
    virtual ~Creator() = default;

    virtual std::unique_ptr<Shape> factoryMethod(Point center, double size) const = 0;

    Wave makeWave(Point center)
    {
        Wave result;
        result.addShape(factoryMethod(center, 1));
        result.addShape(factoryMethod(center, 2));
        result.addShape(factoryMethod(center, 3));
        return result;
    }
};

class CircleWaveCreator : public Creator
{
public:
    std::unique_ptr<Shape> factoryMethod(Point center, double size) const override
    {
        return std::make_unique<Circle>(center, size);
    }
};

class SquareWaveCreator : public Creator
{
public:
    std::unique_ptr<Shape> factoryMethod(Point center, double size) const override
    {
        return std::make_unique<Square>(center, size);
    }
};

class TriangleWaveCreator : public Creator
{
public:
    std::unique_ptr<Shape> factoryMethod(Point center, double size) const override
    {
        return std::make_unique<Triangle>(center, size);
    }
};

class Client
{
public:
    Client(std::unique_ptr<Creator> creator)
        : creator(std::move(creator))
    {}

    Wave makeWave(Point center)
    {
        return creator->makeWave(center);
    }

private:
    std::unique_ptr<Creator> creator;
};

int main()
{
    Client client(std::make_unique<TriangleWaveCreator>());
    Wave wave = client.makeWave({0, 0});
    wave.print();

    return 0;
}
