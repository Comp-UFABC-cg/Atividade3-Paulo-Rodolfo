project(Aplicacao_3D)
add_executable(${PROJECT_NAME} camera.cpp ground.cpp main.cpp model.cpp openglwindow.cpp trackball.cpp)
enable_abcg(${PROJECT_NAME})
