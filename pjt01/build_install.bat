@echo off
echo "1. Clean CMakeCache.txt"
@del /f CMakeCache.txt

echo "2. Generate Make Files ( MinGW Makefiles )
cmake -G "MinGW Makefiles" .

echo "3. Make with Clean-First"
cmake --build . --clean-first

echo "4. Install"
make install

echo "5. Build & Install Done."
