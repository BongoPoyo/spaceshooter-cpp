@echo off


echo Creating build directory...
mkdir build
cd build

echo Configuring project with CMake...
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..

echo Building project...
mingw32-make

IF EXIST SpaceShooter.exe (
    cd ..
    echo Running SpaceShooter.exe...
    build\SpaceShooter.exe
) ELSE (
    echo SpaceShooter.exe not found!
)

cd ..

echo Done!


