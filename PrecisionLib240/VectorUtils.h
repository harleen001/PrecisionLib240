#ifndef VECTORUTILS_H
#define VECTORUTILS_H

#include <vector>
#include <cmath>
#include <stdexcept>

class VectorUtils {
public:
    static float dotProduct(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        if (vectorA.size() != vectorB.size())
            throw std::invalid_argument("Vectors must have the same size");

        float dot = 0.0f;
        for (size_t i = 0; i < vectorA.size(); ++i) {
            dot += vectorA[i] * vectorB[i];
        }
        return dot;
    }

    static std::vector<float> crossProduct(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        if (vectorA.size() != 3 || vectorB.size() != 3)
            throw std::invalid_argument("Cross product requires vectors of size 3");

        std::vector<float> cross(3);
        cross[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
        cross[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
        cross[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
        return cross;
    }

    static std::vector<float> scalarMultiply(const std::vector<float>& vector, float scalar) {
        std::vector<float> result;
        for (float value : vector) {
            result.push_back(value * scalar);
        }
        return result;
    }

    static std::vector<float> normalize(const std::vector<float>& vector) {
        float mag = magnitude(vector);
        std::vector<float> normalized;
        for (float value : vector) {
            normalized.push_back(value / mag);
        }
        return normalized;
    }

    static float magnitude(const std::vector<float>& vector) {
        float mag = 0.0f;
        for (float value : vector) {
            mag += value * value;
        }
        return sqrt(mag);
    }

    static std::vector<float> addVectors(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        if (vectorA.size() != vectorB.size())
            throw std::invalid_argument("Vectors must have the same size");

        std::vector<float> sum;
        for (size_t i = 0; i < vectorA.size(); ++i) {
            sum.push_back(vectorA[i] + vectorB[i]);
        }
        return sum;
    }

    static std::vector<float> subtractVectors(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        if (vectorA.size() != vectorB.size())
            throw std::invalid_argument("Vectors must have the same size");

        std::vector<float> diff;
        for (size_t i = 0; i < vectorA.size(); ++i) {
            diff.push_back(vectorA[i] - vectorB[i]);
        }
        return diff;
    }

    static float angleBetweenVectors(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        float dot = dotProduct(vectorA, vectorB);
        float magA = magnitude(vectorA);
        float magB = magnitude(vectorB);

        return acos(dot / (magA * magB));
    }

    static bool areCollinear(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        std::vector<float> cross = crossProduct(vectorA, vectorB);
        return magnitude(cross) == 0;
    }

    static bool areOrthogonal(const std::vector<float>& vectorA, const std::vector<float>& vectorB) {
        return dotProduct(vectorA, vectorB) == 0;
    }
};

#endif
