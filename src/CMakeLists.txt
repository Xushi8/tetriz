add_executable (${PROJECT_NAME} main.cpp)

add_subdirectory (terminal)


target_link_libraries (${PROJECT_NAME}
PUBLIC
    # src
    terminal
    
    # package
    Threads::Threads
    OpenMP::OpenMP_CXX
    fmt::fmt

    # external
)
