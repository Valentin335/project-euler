# Active un jeu de warnings stricts et cohérent sur une cible.
# Usage : set_project_warnings(ma_cible)
#
# On garde les warnings en "non bloquants" par défaut (pas de -Werror) pour ne
# pas transformer chaque avertissement en échec de build pendant l'apprentissage.
# Pour les rendre bloquants : passer -DWARNINGS_AS_ERRORS=ON au configure.

option(WARNINGS_AS_ERRORS "Traiter les warnings comme des erreurs" OFF)

function(set_project_warnings target)
    set(GCC_CLANG_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow            # variable qui en masque une autre
        -Wconversion        # conversions implicites qui perdent de l'info
        -Wsign-conversion
        -Wnon-virtual-dtor  # classe polymorphe sans dtor virtuel
        -Wold-style-cast    # casts à la C
        -Wcast-align
        -Wunused
        -Woverloaded-virtual
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2
    )

    if(WARNINGS_AS_ERRORS)
        list(APPEND GCC_CLANG_WARNINGS -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE ${GCC_CLANG_WARNINGS})
    endif()
endfunction()
