cmake_minimum_required(VERSION 3.28)

project(FormationCpp
    DESCRIPTION "Formation C++ moderne par la pratique"
    LANGUAGES CXX)

# --- Standard C++ commun à tout le projet ----------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   # -std=c++20, pas -std=gnu++20

# Par défaut on construit en Debug (utile pour apprendre : asserts, sanitizers).
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type de build" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CompilerWarnings)

# --- Catch2 v3 récupéré automatiquement via FetchContent --------------------
# (Utilisé à partir du chapitre 2. Le chapitre 1 se compile à la main avec le
#  harnais maison common/check.hpp, hors de ce CMakeLists.)
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.6.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
include(Catch)   # fournit catch_discover_tests()

enable_testing()

# --- Corrigés : compilés uniquement sur demande explicite -------------------
option(BUILD_SOLUTIONS "Compiler les corrigés du dossier solutions/" OFF)

# --- Chapitres ---------------------------------------------------------------
# Le chapitre 1 (01-fondamentaux) est volontairement HORS CMake : on le compile
# à la main avec g++, c'est pédagogique. Les chapitres suivants seront ajoutés
# ici au fur et à mesure de leur création :
#
#   add_subdirectory(02-cmake-catch2)
#   add_subdirectory(03-memoire-pointeurs)
#   ...
#
# (Aucun add_subdirectory pour l'instant : les chapitres 2+ n'existent pas
#  encore. La configuration CMake reste donc valide en l'état.)

if(BUILD_SOLUTIONS AND EXISTS "${CMAKE_SOURCE_DIR}/solutions/CMakeLists.txt")
    add_subdirectory(solutions)
endif()
