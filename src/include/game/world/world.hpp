#pragma once

// https://github.com/Reputeless/PerlinNoise
#include "PerlinNoise.hpp"

#include <vector>
#include "structs.hpp"
struct Chunk {
    int xoffset;
    int zoffset;
    std::vector<std::vector<std::vector<int>>> blocks; // x, y, z
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

struct WorldMesh {
    int chunkcount;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

class World {
public:

    unsigned long GetSeed();

    World(unsigned long seed);
    Chunk GetChunk(int xoffset, int zoffset);
    void LoadChunks(int xstart, int xend, int zstart, int zend);
    WorldMesh GetWorldMesh();

private:
    unsigned long seed;
    int chunksize = 16;
    int chunkheight = 256;
    float scale = 0.01f;
    unsigned int octaves = 4;
    siv::PerlinNoise::seed_type perlinnoiseseed;
    siv::PerlinNoise perlinnoise;

    std::vector<Chunk> chunks;

    bool IsChunkLoaded(int xoffset, int zoffset);
    void SetSeed(unsigned long seed);
    std::vector<std::vector<float>> SampleChunkNoise(int xoffset, int zoffset);
    std::array<int, 6> ChunkBlockSides(std::vector<std::vector<std::vector<int>>> &blocks, int x, int y, int z);
};
