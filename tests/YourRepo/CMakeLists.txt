#Create a new target executable called YourRepo_test
add_executable(YourRepo_test YourRepo.test.cpp)

#Make it's binaries appear in the build/bin folder, for ease of use.
set_target_properties(YourRepo_test PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#Add one test file per source/header file below:
target_sources(YourRepo_test PRIVATE
    DotProduct.test.cpp
)

#Link it to the testing framework and main program library.
target_link_libraries(YourRepo_test doctest::doctest YourRepo)

#Register it wth CMake. If the target and the executable have the same name (which will be true unless it has been explicitly renamed, as we did with YourRepo-bin), COMMAND can just be the name of the target, as shown here.
add_test(NAME YourRepo_test COMMAND YourRepo_test)
