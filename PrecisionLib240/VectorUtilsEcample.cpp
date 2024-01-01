#include <iostream>
#include "VectorUtils.h"

int main() {
    std::vector<float> vectorA = {1.0f, 2.0f, 3.0f};
    std::vector<float> vectorB = {4.0f, 5.0f, 6.0f};

    // Dot product
    float dot = VectorUtils::dotProduct(vectorA, vectorB);
    std::cout << "Dot Product: " << dot << std::endl;

    // Cross product
    std::vector<float> cross = VectorUtils::crossProduct(vectorA, vectorB);
    std::cout << "Cross Product: ";
    for (float val : cross) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Scalar multiplication
    std::vector<float> scalarMult = VectorUtils::scalarMultiply(vectorA, 2.5f);
    std::cout << "Scalar Multiplication: ";
    for (float val : scalarMult) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Normalization
    std::vector<float> normalized = VectorUtils::normalize(vectorA);
    std::cout << "Normalized Vector: ";
    for (float val : normalized) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Magnitude
    float magnitude = VectorUtils::magnitude(vectorB);
    std::cout << "Magnitude of vectorB: " << magnitude << std::endl;

    // Addition of vectors
    std::vector<float> sum = VectorUtils::addVectors(vectorA, vectorB);
    std::cout << "Sum of vectors: ";
    for (float val : sum) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Subtraction of vectors
    std::vector<float> diff = VectorUtils::subtractVectors(vectorA, vectorB);
    std::cout << "Difference of vectors: ";
    for (float val : diff) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Angle between vectors
    float angle = VectorUtils::angleBetweenVectors(vectorA, vectorB);
    std::cout << "Angle between vectors: " << angle << " radians" << std::endl;

    // Check for collinearity and orthogonality
    bool collinear = VectorUtils::areCollinear(vectorA, vectorB);
    bool orthogonal = VectorUtils::areOrthogonal(vectorA, vectorB);
    std::cout << "Collinear: " << std::boolalpha << collinear << std::endl;
    std::cout << "Orthogonal: " << std::boolalpha << orthogonal << std::endl;

    return 0;
}
