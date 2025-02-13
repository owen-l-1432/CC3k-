#ifndef ITEM_H
#define ITEM_H


class Item {  
    char Type;
    public:
    void setType(char Type);
    char getType();
    Item(){};
    virtual ~Item(){}
    virtual int defence() = 0;
    virtual int attack() = 0;
    virtual int gold() = 0;
    virtual int health() = 0;
};

class Decorator : public Item {
    public:
    Decorator(){};//constructor
    ~Decorator(){} // destructor
    int defence() override;
    int attack() override;
    int gold() override;
    int health() override;
};

//Different items
class RH : public Decorator {
    public:
    RH();
    int health() override;
};

class BA : public Decorator {
    public:
    BA();
    int attack() override;
};

class BD : public Decorator {
    public:
    BD();
    int defence() override;
};

class PH : public Decorator {
    public:
    PH();
    int health() override;
};

class WA : public Decorator {
    public:
    WA();
    int attack() override;
};

class WD : public Decorator {
    public:
    WD();
    int defence() override;
};

class Normal : public Decorator {
    public:
    Normal();
    int gold() override;
};

class Small : public Decorator {
    public:
    Small();
    int gold() override;
};

class MHoard : public Decorator {
    public:
    MHoard();
    int gold() override;
};

class DHoard : public Decorator {
    public:
    DHoard();
    int gold() override;
};

class Compass : public Decorator {
    public:
    Compass();
    bool PickedCompass();
};

class BarrierSuit : public Decorator {
    public:
    BarrierSuit();
    bool PickedBarrierSuit();
};

#endif
