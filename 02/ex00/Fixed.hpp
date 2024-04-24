#pragma once

class Fixed {
public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);

        int getRawBits();
        void setRawBits(int raw);
private:
        int _bits;
        static const int fractionalBits = 8;
};
