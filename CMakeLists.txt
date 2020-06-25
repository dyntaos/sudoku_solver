cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(SudokuSolver)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

set(project_sources main.cpp MainWindow.cpp board.cpp ClusterWidget.cpp)
set(project_headers include/MainWindow.hpp include/board.hpp include/ClusterWidget.hpp)
qt5_wrap_cpp(moc_sources ${project_headers})

add_executable(SudokuSolver ${project_sources} ${project_headers} ${moc_sources})



target_link_libraries(SudokuSolver
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets)

# auto copy dlls if on windows
if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}> )
endif(WIN32)
