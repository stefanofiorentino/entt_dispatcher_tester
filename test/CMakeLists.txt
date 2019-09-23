set(entt_dispatcher_tester_SRC_DIR ${PROJECT_SRC_DIR})

if (WIN32)
    set(WINSOCK2 ws2_32)
elseif (NOT APPLE)
    find_library(LIBRT rt)
endif ()

set(
        COMMON_LINK_LIBS
        gtest_main
        ${LIBRT}
        Threads::Threads
        ${WINSOCK2}
)

macro(ADD_REFL_TEST TEST_NAME TEST_SOURCE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_include_directories(${TEST_NAME} PRIVATE
            ${entt_dispatcher_tester_SRC_DIR}
            ${CMAKE_SOURCE_DIR}/deps/entt/src
            ${CMAKE_SOURCE_DIR}/deps/googletest/googletest/include)
    target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_link_libraries(${TEST_NAME} PRIVATE ${COMMON_LINK_LIBS})
    add_test(NAME entt_dispatcher_tester_${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
endmacro()

ADD_REFL_TEST(listener_tester listener_tester.cpp)
