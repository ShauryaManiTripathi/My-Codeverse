package A7;

public class Q1 {
    public static void main(String[] args) {
        Area area = new Area(10,10);
        area.calculateArea();
    }
}

abstract class Shape {
    abstract double getArea();
}

class Rectangle extends Shape {
    double length;
    double breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    @Override
    public double getArea() {
        return length * breadth;
    }
}

class Square extends Shape {
    double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}

class Circle extends Shape {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Area {
    Rectangle rectangle;
    Square square;
    Circle circle;

    public Area(double a,double b) {
        rectangle = new Rectangle(a,b);
        square = new Square(a);
        circle = new Circle(b);
    }

    public void calculateArea() {
        System.out.println("Rectangle Area: " + rectangle.getArea());
        System.out.println("Square Area: " + square.getArea());
        System.out.println("Circle Area: " + circle.getArea());
    }
}

