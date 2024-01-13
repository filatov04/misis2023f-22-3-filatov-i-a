cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
cmake --install build --prefix C:\spring_oop\SysCalculator
pause