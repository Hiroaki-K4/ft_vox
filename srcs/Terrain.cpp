#include "Terrain.hpp"

Terrain::Terrain() {
    std::cout << "Terrain constructor" << std::endl;
}

Terrain::Terrain(std::vector<double> noise) {
    std::cout << "Terrain constructor2" << std::endl;
    this->noise = noise;
}

Terrain::~Terrain() {
    std::cout << "Terrain destructor" << std::endl;
}

void Terrain::create_perline_noise(unsigned int size, unsigned int octs, bool random_seed) {
    PerlineNoise perline_noise(size, octs, random_seed);
    std::vector<double> noise;
    perline_noise.create_perline_noise(noise);
    this->noise = noise;
}

void Terrain::rescale_noise(unsigned int scale) {
    double min_noise = *std::min_element(this->noise.begin(), this->noise.end());
    transform(this->noise.begin(), this->noise.end(), this->noise.begin(), bind2nd(std::plus<double>(), -(min_noise-0.0)));
    double max_noise = *std::max_element(this->noise.begin(), this->noise.end());
    std::cout << "minmax: " << min_noise << " " << max_noise << std::endl;
    double mag = scale / max_noise;
    std::transform(this->noise.begin(), this->noise.end(), this->noise.begin(),
        std::bind1st(std::multiplies<double>(), mag));
    double min_noise_fi = *std::min_element(this->noise.begin(), this->noise.end());
    double max_noise_fi = *std::max_element(this->noise.begin(), this->noise.end());
    std::cout << "minmax_fi: " << min_noise_fi << " " << max_noise_fi << std::endl;
}

void Terrain::create_mountain(std::vector<glm::vec3> &positions, unsigned int size) {
    for (int z = 0; z < size; z++) {
        for (int x = 0; x < size; x++) {
            int y = int(noise[size * z + x]);
            positions.push_back(glm::vec3(x, y, z));
            for (int i = y-10; i < y; i++) {
                positions.push_back(glm::vec3(x, i, z));
            }
        }
    }
}
