cmake_minimum_required(VERSION 3.2.1)

project(baseDatos2)

add_subdirectory (src)

add_executable(database2_exe src/main.cpp)

install(FILES universidad.bd DESTINATION ${INSTALL_MISC_DIR})
install(FILES curso.tab DESTINATION ${INSTALL_MISC_DIR})
install(FILES matricula.tab DESTINATION ${INSTALL_MISC_DIR})