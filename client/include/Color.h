#pragma once

#include <cstdint>
#include <cstring>

#include "FMath.h"

struct Color
{
    float r;
    float g;
    float b;
    float a;

    Color(float r = 1, float g = 1, float b = 1, float a = 1)
    {
        Set(r, g, b, a);
    };

    Color(const Color &color)
    {
        Set(color);
    };

    void Set(uint32_t hexa)
    {
        uint8_t t[4];

        std::memcpy(t, &hexa, 4);
        Set(t[0], t[1], t[2], t[3]);
    };

    void Set(uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255)
    {
        this->r = r / 255.0f;
        this->g = g / 255.0f;
        this->b = b / 255.0f;
        this->a = a / 255.0f;
    };

    void Set(float r = 1, float g = 1, float b = 1, float a = 1)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };

    void Set(const Color &color)
    {
        this->r = color.r;
        this->g = color.g;
        this->b = color.b;
        this->a = color.a;
    };

    static Color Lerp(const Color &a, const Color &b, float t)
    {
        auto tr = FMath::Lerp(a.r, b.r, t);
        auto tg = FMath::Lerp(a.g, b.g, t);
        auto tb = FMath::Lerp(a.b, b.b, t);
        auto ta = FMath::Lerp(a.a, b.a, t);

        return Color(tr, tg, tb, ta);
    };

    static Color Red()
    {
        return Color(1, 0, 0);
    };

    static Color Green()
    {
        return Color(0, 1, 0);
    };

    static Color Blue()
    {
        return Color(0, 0, 1);
    };

    static Color Black()
    {
        return Color(0, 0, 0, 0);
    };

    static Color White()
    {
        return Color();
    };

    static Color Magenta()
    {
        return Color(1, 1, 0);
    }
};