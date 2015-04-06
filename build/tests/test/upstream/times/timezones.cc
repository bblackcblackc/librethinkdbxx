// auto-generated by yaml_to_cxx.py from test/upstream/times/timezones.yaml
#include "testlib.h"
void test_upstream_times_timezones() {
    enter_section("test_upstream_times_timezones: Test basic timezone manipulation");
    auto t1 = R::time(2013, R::july, 29, 23, 30, 0, "+00:00");
    auto tutc1 = t1.in_timezone("Z");
    auto tutc2 = t1.in_timezone("+00:00");
    auto tutc3 = t1.in_timezone("+00");
    auto tutcs = R::expr(R::array(tutc1, tutc2, tutc3));
    auto tm1 = t1.in_timezone("-00:59");
    auto tm2 = t1.in_timezone("-01:00");
    auto tm3 = t1.in_timezone("-01:01");
    auto tms = R::expr(R::array(tm1, tm2, tm3));
    auto tp1 = t1.in_timezone("+00:59");
    auto tp2 = t1.in_timezone("+01:00");
    auto tp3 = t1.in_timezone("+01:01");
    auto tps = R::expr(R::array(tp1, tp2, tp3));
    auto ts = tutcs.union_(tms).union_(tps).union_(R::Array{t1});
    TEST_EQ(tutcs.map([=](R::Var x){ return R::array((*x).timezone(), (*x).day()); }).run(*conn), (R::Array{R::Array{"+00:00", 29}, R::Array{"+00:00", 29}, R::Array{"+00:00", 29}}));
    TEST_EQ(tms.map([=](R::Var x){ return R::array((*x).timezone(), (*x).day()); }).run(*conn), (R::Array{R::Array{"-00:59", 29}, R::Array{"-01:00", 29}, R::Array{"-01:01", 29}}));
    TEST_EQ(tps.map([=](R::Var x){ return R::array((*x).timezone(), (*x).day()); }).run(*conn), (R::Array{R::Array{"+00:59", 30}, R::Array{"+01:00", 30}, R::Array{"+01:01", 30}}));
    TEST_EQ(ts.concat_map([=](R::Var x){ return ts.map([=](R::Var y){ return *x - *y; }); }).distinct().run(*conn), (R::Array{0}));
    TEST_EQ(R::now().in_timezone("").run(*conn), (err("RqlRuntimeError", "Timezone `` does not start with `-` or `+`.")));
    TEST_EQ(R::now().in_timezone("-00").run(*conn), (err("RqlRuntimeError", "`-00` is not a valid time offset.")));
    TEST_EQ(R::now().in_timezone("-00:00").run(*conn), (err("RqlRuntimeError", "`-00:00` is not a valid time offset.")));
    TEST_EQ(R::now().in_timezone("UTC+00").run(*conn), (err("RqlRuntimeError", "Timezone `UTC+00` does not start with `-` or `+`.")));
    TEST_EQ(R::now().in_timezone("+00:60").run(*conn), (err("RqlRuntimeError", "Minutes out of range in `+00:60`.")));
    TEST_EQ(R::now().in_timezone("+25:00").run(*conn), (err("RqlRuntimeError", "Hours out of range in `+25:00`.")));
    TEST_EQ(R::time(2013, 1, 1, "").run(*conn), (err("RqlRuntimeError", "Timezone `` does not start with `-` or `+`.")));
    TEST_EQ(R::time(2013, 1, 1, "-00").run(*conn), (err("RqlRuntimeError", "`-00` is not a valid time offset.")));
    TEST_EQ(R::time(2013, 1, 1, "-00:00").run(*conn), (err("RqlRuntimeError", "`-00:00` is not a valid time offset.")));
    TEST_EQ(R::time(2013, 1, 1, "UTC+00").run(*conn), (err("RqlRuntimeError", "Timezone `UTC+00` does not start with `-` or `+`.")));
    TEST_EQ(R::time(2013, 1, 1, "+00:60").run(*conn), (err("RqlRuntimeError", "Minutes out of range in `+00:60`.")));
    TEST_EQ(R::time(2013, 1, 1, "+25:00").run(*conn), (err("RqlRuntimeError", "Hours out of range in `+25:00`.")));
}
