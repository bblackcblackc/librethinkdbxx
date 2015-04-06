// auto-generated by yaml_to_cxx.py from test/upstream/math_logic/mul.yaml
#include "testlib.h"
void test_upstream_math_logic_mul() {
    enter_section("test_upstream_math_logic_mul: Tests for the basic usage of the multiplication operation");
    TEST_EQ((R::expr(1) * 2).run(*conn), (2));
    TEST_EQ((R::expr(1) * R::expr(2)).run(*conn), (2));
    TEST_EQ(R::expr(1).mul(2).run(*conn), (2));
    TEST_EQ((R::expr(-1) * -1).run(*conn), (1));
    TEST_EQ((R::expr(1.5) * 4.5).run(*conn), (6.75));
    TEST_EQ((R::expr(R::array(1, 2, 3)) * 3).run(*conn), (R::Array{1, 2, 3, 1, 2, 3, 1, 2, 3}));
    TEST_EQ((R::expr("a") * 0.8).run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found STRING.", R::Array{0})));
    TEST_EQ((R::expr(1) * "a").run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found STRING.", R::Array{1})));
    TEST_EQ((R::expr("b") * "a").run(*conn), (err("RqlRuntimeError", "Expected type NUMBER but found STRING.", R::Array{0})));
    TEST_EQ((R::expr(R::array()) * 1.5).run(*conn), (err("RqlRuntimeError", "Number not an integer: 1.5", R::Array{0})));
    exit_section();
}
