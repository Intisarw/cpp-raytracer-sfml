#pragma once


// This space is for utility functions

// Helps value stay within a range of minVals and maxVals
inline double clamp(double x, double minVal, double maxVal)
{
    if(x < minVal) return minVal;
    if(x > maxVal) return maxVal;

    return x;
}