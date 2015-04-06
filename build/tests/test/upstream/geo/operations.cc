// auto-generated by yaml_to_cxx.py from test/upstream/geo/operations.yaml
#include "testlib.h"
void test_upstream_geo_operations() {
    enter_section("test_upstream_geo_operations: Test basic geometry operators");
    TEST_EQ(R::distance(R::point(-122, 37), R::point(-123, 37)).coerce_to("STRING").run(*conn), ("89011.262538353315904"));
    TEST_EQ(R::distance(R::point(-122, 37), R::point(-122, 36)).coerce_to("STRING").run(*conn), ("110968.30443995493988"));
    TEST_EQ(R::distance(R::point(-122, 37), R::point(-122, 36)).eq(R::distance(R::point(-122, 36), R::point(-122, 37))).run(*conn), (true));
    TEST_EQ(R::point(-122, 37).distance(R::point(-123, 37)).coerce_to("STRING").run(*conn), ("89011.262538353315904"));
    auto someDist = R::distance(R::point(-122, 37), R::point(-123, 37));
    TEST_EQ(someDist.mul(R::expr(1.0) / 1000.0).eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"unit", R::expr("km")}})).run(*conn), (true));
    TEST_EQ(someDist.mul(R::expr(1.0) / 1609.344).eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"unit", R::expr("mi")}})).run(*conn), (true));
    TEST_EQ(someDist.mul(R::expr(1.0) / 0.3048).eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"unit", R::expr("ft")}})).run(*conn), (true));
    TEST_EQ(someDist.mul(R::expr(1.0) / 1852.0).eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"unit", R::expr("nm")}})).run(*conn), (true));
    TEST_EQ(someDist.eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"geo_system", R::expr("WGS84")}})).run(*conn), (true));
    TEST_EQ(someDist.div(10).eq(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"geo_system", R::expr(R::object("a", 637813.7, "f", R::expr(1.0) / 298.257223563))}})).run(*conn), (true));
    TEST_EQ(R::distance(R::point(-122, 37), R::point(-123, 37), R::OptArgs{{"geo_system", R::expr("unit_sphere")}}).coerce_to("STRING").run(*conn), ("0.01393875509649327056"));
    TEST_EQ(R::distance(R::point(0, 0), R::point(0, 0)).coerce_to("STRING").run(*conn), ("0"));
    TEST_EQ(R::distance(R::point(0, 0), R::point(180, 0)).mul(2).coerce_to("STRING").run(*conn), ("40007862.91725089401"));
    TEST_EQ(R::distance(R::point(0, -90), R::point(0, 90)).mul(2).coerce_to("STRING").run(*conn), ("40007862.91725089401"));
    TEST_EQ(R::distance(R::point(0, 0), R::line(R::array(0, 0), R::array(0, 1))).coerce_to("STRING").run(*conn), ("0"));
    TEST_EQ(R::distance(R::line(R::array(0, 0), R::array(0, 1)), R::point(0, 0)).coerce_to("STRING").run(*conn), ("0"));
    TEST_EQ(R::distance(R::point(0, 0), R::line(R::array(0.1, 0), R::array(1, 0))).eq(R::distance(R::point(0, 0), R::point(0.1, 0))).run(*conn), (true));
    TEST_EQ(R::distance(R::point(0, 0), R::line(R::array(5, -1), R::array(4, 2))).coerce_to("STRING").run(*conn), ("492471.49900552548934"));
    TEST_EQ(R::distance(R::point(0, 0), R::polygon(R::array(5, -1), R::array(4, 2), R::array(10, 10))).coerce_to("STRING").run(*conn), ("492471.49900552548934"));
    TEST_EQ(R::distance(R::point(0, 0), R::polygon(R::array(0, -1), R::array(0, 1), R::array(10, 10))).coerce_to("STRING").run(*conn), ("0"));
    TEST_EQ(R::distance(R::point(0.5, 0.5), R::polygon(R::array(0, -1), R::array(0, 1), R::array(10, 10))).coerce_to("STRING").run(*conn), ("0"));
    TEST_EQ(R::circle(R::array(0, 0), 1, R::OptArgs{{"fill", R::expr(false)}}).eq(R::circle(R::array(0, 0), 1, R::OptArgs{{"fill", R::expr(true)}})).run(*conn), (false));
    TEST_EQ(R::circle(R::array(0, 0), 1, R::OptArgs{{"fill", R::expr(false)}}).fill().eq(R::circle(R::array(0, 0), 1, R::OptArgs{{"fill", R::expr(true)}})).run(*conn), (true));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0.1, 0.1), R::array(0.9, 0.1), R::array(0.9, 0.9), R::array(0.1, 0.9))).run(*conn), (R::Object{{"$reql_type$","GEOMETRY"}, {"coordinates",R::Array{R::Array{R::Array{0, 0}, R::Array{1, 0}, R::Array{1, 1}, R::Array{0, 1}, R::Array{0, 0}}, R::Array{R::Array{0.1, 0.1}, R::Array{0.9, 0.1}, R::Array{0.9, 0.9}, R::Array{0.1, 0.9}, R::Array{0.1, 0.1}}}}, {"type","Polygon"}}));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0.1, 0.9), R::array(0.9, 0.0), R::array(0.9, 0.9), R::array(0.1, 0.9))).run(*conn), (err("RqlRuntimeError", "The second argument to `polygon_sub` is not contained in the first one.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0, 0), R::array(2, 0), R::array(2, 2), R::array(0, 2))).run(*conn), (err("RqlRuntimeError", "The second argument to `polygon_sub` is not contained in the first one.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0, -2), R::array(1, -2), R::array(-1, 1), R::array(0, -1))).run(*conn), (err("RqlRuntimeError", "The second argument to `polygon_sub` is not contained in the first one.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0, -1), R::array(1, -1), R::array(1, 0), R::array(0, 0))).run(*conn), (err("RqlRuntimeError", "The second argument to `polygon_sub` is not contained in the first one.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0.1, -1), R::array(0.9, -1), R::array(0.9, 0.5), R::array(0.1, 0.5))).run(*conn), (err("RqlRuntimeError", "The second argument to `polygon_sub` is not contained in the first one.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0, 0), R::array(0.1, 0.9), R::array(0.9, 0.9), R::array(0.9, 0.1))).run(*conn), (R::Object{{"$reql_type$","GEOMETRY"}, {"coordinates",R::Array{R::Array{R::Array{0, 0}, R::Array{1, 0}, R::Array{1, 1}, R::Array{0, 1}, R::Array{0, 0}}, R::Array{R::Array{0, 0}, R::Array{0.1, 0.9}, R::Array{0.9, 0.9}, R::Array{0.9, 0.1}, R::Array{0, 0}}}}, {"type","Polygon"}}));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::polygon(R::array(0, 0), R::array(0.1, 0.9), R::array(0.9, 0.9), R::array(0.9, 0.1)).polygon_sub(R::polygon(R::array(0.2, 0.2), R::array(0.5, 0.8), R::array(0.8, 0.2)))).run(*conn), (err("RqlRuntimeError", "Expected a Polygon with only an outer shell.  This one has holes.", R::Array{0})));
    TEST_EQ(R::polygon(R::array(0, 0), R::array(1, 0), R::array(1, 1), R::array(0, 1)).polygon_sub(R::line(R::array(0, 0), R::array(0.9, 0.1), R::array(0.9, 0.9), R::array(0.1, 0.9))).run(*conn), (err("RqlRuntimeError", "Expected a Polygon but found a LineString.", R::Array{})));
}
