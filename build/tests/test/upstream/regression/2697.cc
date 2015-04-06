// auto-generated by yaml_to_cxx.py from test/upstream/regression/2697.yaml
#include "testlib.h"
void test_upstream_regression_2697() {
    enter_section("test_upstream_regression_2697: 2697 -- Array insert and splice operations don't check array size limit.");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_DO(auto ten_l = (R::expr(R::array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))));
    TEST_EQ(tbl.insert(R::object("id", 1, "a", R::expr(ten_l).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }))).pluck("first_error", "inserted").run(*conn), (R::Object{{"inserted",1}}));
    TEST_EQ(tbl.get(1).replace(R::object("id", 1, "a", R::row["a"].splice_at(0, R::array(2)))).pluck("first_error").run(*conn), (R::Object{{"first_error","Array over size limit `100000`."}}));
    TEST_EQ(tbl.get(1)["a"].count().run(*conn), (100000));
    TEST_EQ(tbl.get(1).replace(R::object("id", 1, "a", R::row["a"].insert_at(0, R::array(2)))).pluck("first_error").run(*conn), (R::Object{{"first_error","Array over size limit `100000`."}}));
    TEST_EQ(tbl.get(1)["a"].count().run(*conn), (100000));
    TEST_EQ(R::expr(ten_l).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).splice_at(0, R::array(1)).count().run(*conn), (err("RqlRuntimeError", "Array over size limit `100000`.", R::Array{})));
    TEST_EQ(R::expr(ten_l).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).concat_map([=](R::Var l){ return (R::range(1, 11)); }).insert_at(0, R::array(1)).count().run(*conn), (err("RqlRuntimeError", "Array over size limit `100000`.", R::Array{})));
    exit_section();
}
