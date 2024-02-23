
#ifndef __HEADER_BENCHMARK__
#define __HEADER_BENCHMARK__

class Benchmark {

public:
    Benchmark(const std::string& benchmarkName = "Benchmark")
		: name(benchmarkName)
	{
        start = std::chrono::high_resolution_clock::now();
    }

    ~Benchmark()
	{
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << name << " took " << duration << " microseconds." << std::endl;
    }

private:
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

};

#endif // __HEADER_BENCHMARK__

