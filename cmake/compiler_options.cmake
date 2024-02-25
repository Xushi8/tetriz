if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDBUG")
    # set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDBUG")
    
    add_compile_options (-march=native)
    
    add_compile_options (-Wall)
    add_compile_options (-Wextra)
    add_compile_options (-pedantic)
    add_compile_options (-Wshadow)
    add_compile_options (-Wconversion)
    add_compile_options (-Wcast-qual)                # Cast for removing type qualifiers
    add_compile_options (-Wfloat-equal)              # Floating values used in equality comparisons
    add_compile_options (-Wredundant-decls)          # if anything is declared more than once in the same scope
    add_compile_options (-Wundef)
    
    add_compile_options (-fopenmp)
    add_compile_options (-ffast-math)

    add_compile_options (-fdiagnostics-color=always)
    
    # add_compile_options (-fopt-info)


    # add_compile_options (-fgraphite-identity)
    # add_compile_options (-floop-nest-optimize)
    # add_compile_options (-fdevirtualize-at-ltrans)
    # add_compile_options (-fipa-pta)
    add_compile_options (-fno-semantic-interposition)
    add_compile_options (-flto=auto)
    add_compile_options (-fuse-linker-plugin)
    add_compile_options (-pipe)


    # add_compile_options (-fsanitize=address)
    # add_compile_options (-fno-omit-frame-pointer)
    # add_compile_options (-fsanitize=undefined)
    
    
    # add_compile_options (-save-temps=obj)
    # add_compile_options (-fverbose-asm) # 汇编保留源码
    # add_compile_options (-masm=intel) # intel汇编

endif ()
