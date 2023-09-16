cmake_minimum_required(VERSION 3.10)


set(PATCH_VERSION "4")
set(PROJECT_VESRION 0.0.4)

project(tape VERSION ${PROJECT_VESRION})

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(tape main.cpp tape.cpp tapesort.cpp)

#add_executable(boost_test boost_test.cpp)

SET (main.cpp tape.cpp PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

#set_target_properties(boost_test PROPERTIES
 #   COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  #  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

install(TARGETS tape RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

#add_test(boost_test boost_test)
