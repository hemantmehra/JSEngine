# CMakeList.txt : CMake project for JSEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (JSEngine "main.cpp"  "AST.h" "AST.cpp" "Interpreter.h" "Interpreter.cpp" "Value.h" "Object.h" "Object.cpp" "Forward.h" "Function.cpp" "Value.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JSEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
