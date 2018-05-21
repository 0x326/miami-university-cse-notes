#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
 public:
    Rectangle();
    Rectangle(int height, int width);
    virtual ~Rectangle();
    // if virtual methods exist, you must define a deconstructor
    // https://stackoverflow.com/a/3065223

    int constMethod() const;
    // A method must be declared virtual if it is to be overridden
    // If it is not, it is merely hidden and the super-class implementation is used during polymorphism
    int constHiddenMethod() const;
    virtual int constOverriddenMethod() const;
    virtual int constOverriddenMethodAnnotated() const;

 private:
    int height;
    int width;
};

#endif //RECTANGLE_H
