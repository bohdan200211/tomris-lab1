cmake_minimum_required(VERSION 3.21)
project(tomris-lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(tomris-lab1
    main.c
    subtraction.h
    subtraction.c
    utility.h
    utility.c
    division.h
    division.c
    cli.h
    cli.c
    image.c
    imag.h
)

include(GNUInstallDirs)
install(TARGETS tomris-lab1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(InstallRequiredSystemLibraries)

set(CPACK_OUTPUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/CPackDefaultConfig.cmake")

include(CPack)

add_custom_target(package
    COMMAND ${CMAKE_COMMAND} -E echo Run zip target...
    COMMAND ${CMAKE_CPACK_COMMAND}
            -G 7Z
            --config "${CMAKE_BINARY_DIR}/CPackDefaultConfig.cmake"
    VERBATIM
    USES_TERMINAL
)
