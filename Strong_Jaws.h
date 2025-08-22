#ifndef STRONG_JAWS_H
#define STRONG_JAWS_H

class Animal; 

class Strong_Jaws {
public:
    virtual void bite(Animal* other) = 0;
    virtual ~Strong_Jaws() {}
};

#endif // STRONG_JAWS_H