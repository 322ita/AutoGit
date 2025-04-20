cmake_minimum_required(VERSION 3.16)            

project(AutoGit VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Imposta le cartelle di output organizzate             !!!!AI GENERATED!!!!
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # Per gli eseguibili (.exe, etc.)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Per le librerie condivise (.so, .dll)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Per le librerie statiche (.a, .lib)

# Nasconde le cartelle di output specifiche della configurazione (Debug/Release)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach()

add_executable(AutoGit main.cpp)

# Opzionale: Mostra info utili dopo la configurazione
message(STATUS "Output directories:")
message(STATUS "  - Binari: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "  - Librerie: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# Opzionale: Aggiungi install target
install(TARGETS AutoGit
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib