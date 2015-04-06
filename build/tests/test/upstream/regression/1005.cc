// auto-generated by yaml_to_cxx.py from test/upstream/regression/1005.yaml
#include "testlib.h"
void test_upstream_regression_1005() {
    enter_section("test_upstream_regression_1005: Regression test for issue");
    TEST_EQ(R::expr(str(R::table_list())).run(*conn), (R::table_list()));
    TEST_EQ(R::expr(str(R::table_create("a"))).run(*conn), (R::table_create("a")));
    TEST_EQ(R::expr(str(R::table_drop("a"))).run(*conn), (R::table_drop("a")));
    TEST_EQ(R::expr(str(R::db("a").table_list())).run(*conn), (R::db("a").table_list()));
    TEST_EQ(R::expr(str(R::db("a").table_create("a"))).run(*conn), (R::db("a").table_create("a")));
    TEST_EQ(R::expr(str(R::db("a").table_drop("a"))).run(*conn), (R::db("a").table_drop("a")));
}
