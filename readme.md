# Ray Tracer (C++ / SFML / CMake) — In Progress

A CPU-based ray tracer built from scratch in C++. Uses SFML for window/display output and CMake for builds.

# Current Features
- Custom `vec3` math library (operators, dot, cross, unit vectors)
- Rays + camera setup
- Ray–sphere intersection
- Basic shading (surface normals + diffuse lighting)
- SFML window output (preview)

# Planned
- Anti-aliasing (multi-sampling)
- Reflections / recursive ray bounces
- Materials (Lambertian/metal/dielectric)
- Acceleration (BVH)

# Build & Run
```bash
cmake -S . -B build
cmake --build build
./build/RAYTRACER
