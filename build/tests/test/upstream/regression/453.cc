// auto-generated by yaml_to_cxx.py from test/upstream/regression/453.yaml
#include "testlib.h"
void test_upstream_regression_453() {
    enter_section("test_upstream_regression_453: Sanity Check Fails, with r.table() expression inside a map (#453)");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    tbl.insert(R::array(R::object("a", 1), R::object("a", 2))).run(*conn);
    TEST_EQ(tbl.map([=](R::Var x){ return tbl; }).run(*conn), (err("RqlRuntimeError", "Expected type DATUM but found TABLE.", R::Array{0})));
    TEST_EQ(tbl.map([=](R::Var x){ return tbl.coerce_to("array"); }).count().run(*conn), (2));
    exit_section();
}
