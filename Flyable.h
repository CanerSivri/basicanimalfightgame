#ifndef FLYABLE_H
#define FLYABLE_H

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

#endif // FLYABLE_H