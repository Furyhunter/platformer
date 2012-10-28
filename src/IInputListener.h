#pragma once

class IInputListener {
public:
    virtual void buttonPressed(unsigned int button) = 0;
    virtual void buttonReleased(unsigned int button) = 0;
};
