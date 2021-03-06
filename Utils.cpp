#include "Utils.hpp"

#include <chrono>
#include <cmath>

std::default_random_engine Utils::generator;

void Utils::init()
{
    generator = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
}

double Utils::add_uniform_noise(double level, double x)
{
    std::uniform_real_distribution<double> distribution(-level,level);
    double noise = distribution(generator);
    return x + noise;
}

double Utils::sample_uniform(double from, double to)
{
    std::uniform_real_distribution<double> distribution(from,to);
    return distribution(generator);
}

double Utils::sample_Gaussian(double mu, double sigma)
{
    std::normal_distribution<double> distribution(mu, sigma);
    double noise = distribution(generator);
    return noise;
}

