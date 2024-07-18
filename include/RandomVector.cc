
#include "RandomVector.h"
#include "Random.h"


std::vector<double> RandomVector::randomValues;
int RandomVector::index;

void RandomVector::initialize(int size) {
    for (int i=0; i<size; i++)
        randomValues.push_back(randomDouble(0.0, 1.0));
    index = 0;
}

double RandomVector::getValue() {
    double ret = randomValues[index];
    index++;
    if (index > randomValues.size())
        index = 0;
    return ret;
}



