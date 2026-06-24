#ifndef SERVO_SCANNER_H
#define SERVO_SCANNER_H

class ServoScanner {
    public:
        ServoScanner(int servoPin);

        void begin();

        void center();

        void moveLeft();

        void moveRight();

        void sweep();
    private:
        int _servoPin;

};

#endif;