#ifndef FAHRZEUG_H
#define FAHRZEUG_H

class Fahrzeug {
    public:
        Fahrzeug();
        void accelerate(float seconds);// TODO: Virtuellize accelerate as pure method
        void showValues() const;
        float getSpeed() const;
        void setSpeed(float newSpeed);
    private:
        float mSpeed = 0.0f; // km/h
};

#endif // FAHRZEUG_H