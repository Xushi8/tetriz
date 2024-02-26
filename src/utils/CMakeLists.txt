add_library (utils "")

file (GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file (GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources (utils
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories (utils PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
