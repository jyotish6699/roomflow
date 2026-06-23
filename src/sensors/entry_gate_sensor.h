#ifndef ENTRY_GATE_SENSOR_H
#define ENTRY_GATE_SENSOR_H

class EntryGateSensor {
    public: 
        EntryGateSensor(int trigPin, int echoPin);

        void begin();

        float getDistance();

        bool isTriggered();

    private:
        int _trigPin;
        int _echoPin;
};

#endif;