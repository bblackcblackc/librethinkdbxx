// auto-generated by yaml_to_cxx.py from test/upstream/json.yaml
#include "testlib.h"
void test_upstream_json() {
    enter_section("test_upstream_json: Tests RQL json parsing");
    TEST_EQ(R::json("[1,2,3]").run(*conn), (R::Array{1, 2, 3}));
    TEST_EQ(R::json("1").run(*conn), (1));
    TEST_EQ(R::json("{}").run(*conn), (R::Object{}));
    TEST_EQ(R::json("\"foo\"").run(*conn), ("foo"));
    TEST_EQ(R::json("[1,2").run(*conn), (err("RqlRuntimeError", "Failed to parse \"[1,2\" as JSON.", R::Array{0})));
    TEST_EQ(R::json("[1,2,3]").to_json_string().run(*conn), ("[1,2,3]"));
    TEST_EQ(R::json("[1,2,3]").to_json().run(*conn), ("[1,2,3]"));
    TEST_EQ(R::json("{\"foo\":4}").to_json_string().run(*conn), ("{\"foo\":4}"));
    TEST_EQ(R::json("{\"foo\":4}").to_json().run(*conn), ("{\"foo\":4}"));
    TEST_DO(auto text = ("[{\"id\":1,\"first_name\":\"Harry\",\"last_name\":\"Riley\",\"email\":\"hriley0@usgs.gov\",\"country\":\"Andorra\",\"ip_address\":\"221.25.65.136\"},{\"id\":2,\"first_name\":\"Bonnie\",\"last_name\":\"Anderson\",\"email\":\"banderson1@list-manage.com\",\"country\":\"Tuvalu\",\"ip_address\":\"116.162.43.150\"},{\"id\":3,\"first_name\":\"Marie\",\"last_name\":\"Schmidt\",\"email\":\"mschmidt2@diigo.com\",\"country\":\"Iraq\",\"ip_address\":\"181.105.59.57\"},{\"id\":4,\"first_name\":\"Phillip\",\"last_name\":\"Willis\",\"email\":\"pwillis3@com.com\",\"country\":\"Montenegro\",\"ip_address\":\"24.223.139.156\"}]"));
    TEST_DO(auto sorted = ("[{\"country\":\"Andorra\",\"email\":\"hriley0@usgs.gov\",\"first_name\":\"Harry\",\"id\":1,\"ip_address\":\"221.25.65.136\",\"last_name\":\"Riley\"},{\"country\":\"Tuvalu\",\"email\":\"banderson1@list-manage.com\",\"first_name\":\"Bonnie\",\"id\":2,\"ip_address\":\"116.162.43.150\",\"last_name\":\"Anderson\"},{\"country\":\"Iraq\",\"email\":\"mschmidt2@diigo.com\",\"first_name\":\"Marie\",\"id\":3,\"ip_address\":\"181.105.59.57\",\"last_name\":\"Schmidt\"},{\"country\":\"Montenegro\",\"email\":\"pwillis3@com.com\",\"first_name\":\"Phillip\",\"id\":4,\"ip_address\":\"24.223.139.156\",\"last_name\":\"Willis\"}]"));
    TEST_EQ(R::json(text).to_json_string().run(*conn), (sorted));
    TEST_EQ(R::expr(R::minval).to_json_string().run(*conn), (err("RqlRuntimeError", "Cannot convert `r.minval` to JSON.")));
    TEST_EQ(R::expr(R::maxval).to_json_string().run(*conn), (err("RqlRuntimeError", "Cannot convert `r.maxval` to JSON.")));
    TEST_EQ(R::expr(R::minval).coerce_to("string").run(*conn), (err("RqlRuntimeError", "Cannot convert `r.minval` to JSON.")));
    TEST_EQ(R::expr(R::maxval).coerce_to("string").run(*conn), (err("RqlRuntimeError", "Cannot convert `r.maxval` to JSON.")));
    TEST_EQ(R::time(2014, 9, 11, "Z").run(*conn), (R::Object{{"timezone","+00:00"}, {"$reql_type$","TIME"}, {"epoch_time",1410393600}}));
    TEST_EQ(R::time(2014, 9, 11, "Z").to_json_string().run(*conn), ("{\"$reql_type$\":\"TIME\",\"epoch_time\":1410393600,\"timezone\":\"+00:00\"}"));
    TEST_EQ(R::point(0, 0).run(*conn), (R::Object{{"$reql_type$","GEOMETRY"}, {"coordinates",R::Array{0, 0}}, {"type","Point"}}));
    TEST_EQ(R::point(0, 0).to_json_string().run(*conn), ("{\"$reql_type$\":\"GEOMETRY\",\"coordinates\":[0,0],\"type\":\"Point\"}"));
    TEST_DO(auto s = ("foo"));
    TEST_EQ(R::binary(s).run(*conn), (s));
    TEST_EQ(R::expr("foo").coerce_to("binary").to_json_string().run(*conn), ("{\"$reql_type$\":\"BINARY\",\"data\":\"Zm9v\"}"));
    exit_section();
}
