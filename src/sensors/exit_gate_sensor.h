#ifndef EXIT_GATE_SENSOR_H
#define EXIT_GATE_SENSOR_H

class ExitGateSensor
{
public:
    ExitGateSensor(int trigPin, int echoPin);

    void begin();

    float getDistance();

    bool isTriggered();

private:
    int _trigPin;
    int _echoPin;
};

#endif