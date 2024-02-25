find_package (Threads REQUIRED)
find_package (OpenMP REQUIRED)
find_package (fmt CONFIG REQUIRED)
find_package (TBB CONFIG REQUIRED COMPONENTS tbb)

find_path (GMP_INCLUDE_DIR NAMES gmp.h)
find_library (GMP_LIBRARIES NAMES gmp libgmp)
find_library (GMPXX_LIBRARIES NAMES gmpxx libgmpxx)

# find_path (MARIADB_INCLUDE_DIR NAMES mariadb)
# find_library (MARIADB_LIBRARIES NAMES mariadb libmariadb)