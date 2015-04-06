// auto-generated by yaml_to_cxx.py from test/upstream/aggregation.yaml
#include "testlib.h"
void test_upstream_aggregation() {
    enter_section("test_upstream_aggregation: Tests that manipulation data in tables");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    temp_table tbl2_table;
    R::Query tbl2 = tbl2_table.table();
    temp_table tbl3_table;
    R::Query tbl3 = tbl3_table.table();
    temp_table tbl4_table;
    R::Query tbl4 = tbl4_table.table();
    TEST_EQ(tbl.insert(R::range(100).map([=](R::Var i){ return R::object("id", *i, "a", *i % 4); })).run(*conn), (R::Object{{"deleted",0.0}, {"replaced",0.0}, {"unchanged",0.0}, {"errors",0.0}, {"skipped",0.0}, {"inserted",100}}));
    TEST_EQ(tbl2.insert(R::range(100).map([=](R::Var i){ return R::object("id", *i, "b", *i % 4); })).run(*conn), (R::Object{{"deleted",0.0}, {"replaced",0.0}, {"unchanged",0.0}, {"errors",0.0}, {"skipped",0.0}, {"inserted",100}}));
    TEST_EQ(tbl3.insert(R::range(100).map([=](R::Var i){ return R::object("id", *i, "a", *i % 4, "b", R::object("c", *i % 5)); })).run(*conn), (R::Object{{"deleted",0.0}, {"replaced",0.0}, {"unchanged",0.0}, {"errors",0.0}, {"skipped",0.0}, {"inserted",100}}));
    TEST_DO(auto time1 = (1375115782.24));
    TEST_DO(auto time2 = (1375147296.68));
    TEST_EQ(tbl4.insert(R::object("id", 0, "time", R::epoch_time(time1))).run(*conn), (R::Object{{"deleted",0.0}, {"replaced",0.0}, {"unchanged",0.0}, {"errors",0.0}, {"skipped",0.0}, {"inserted",1}}));
    TEST_EQ(tbl4.insert(R::object("id", 1, "time", R::epoch_time(time2))).run(*conn), (R::Object{{"deleted",0.0}, {"replaced",0.0}, {"unchanged",0.0}, {"errors",0.0}, {"skipped",0.0}, {"inserted",1}}));
    TEST_EQ(tbl.sum("a").run(*conn), (150));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).sum().run(*conn), (150));
    TEST_EQ(tbl.group("a").sum("id").run(*conn), (R::Object{{"0",1200}, {"1",1225}, {"2",1250}, {"3",1275}}));
    TEST_EQ(tbl.avg("a").run(*conn), (1.5));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).avg().run(*conn), (1.5));
    TEST_EQ(tbl.group("a").avg("id").run(*conn), (R::Object{{"0",48}, {"1",49}, {"2",50}, {"3",51}}));
    TEST_EQ(tbl.min("a")["a"].run(*conn), (0));
    TEST_EQ(tbl.order_by("id").min("a").run(*conn), (R::Object{{"a",0}, {"id",0}}));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).min().run(*conn), (0));
    TEST_EQ(tbl.group("a").min("id").run(*conn), (R::Object{{"0",R::Object{{"a",0}, {"id",0}}}, {"1",R::Object{{"a",1}, {"id",1}}}, {"2",R::Object{{"a",2}, {"id",2}}}, {"3",R::Object{{"a",3}, {"id",3}}}}));
    TEST_EQ(tbl.order_by("id").max("a").run(*conn), (R::Object{{"a",3}, {"id",3}}));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).max().run(*conn), (3));
    TEST_EQ(tbl.group("a").max("id").run(*conn), (R::Object{{"0",R::Object{{"a",0}, {"id",96}}}, {"1",R::Object{{"a",1}, {"id",97}}}, {"2",R::Object{{"a",2}, {"id",98}}}, {"3",R::Object{{"a",3}, {"id",99}}}}));
    TEST_EQ(tbl.min().run(*conn), (R::Object{{"a",0}, {"id",0}}));
    TEST_EQ(tbl.group("a").min().run(*conn), (R::Object{{"0",R::Object{{"a",0}, {"id",0}}}, {"1",R::Object{{"a",1}, {"id",1}}}, {"2",R::Object{{"a",2}, {"id",2}}}, {"3",R::Object{{"a",3}, {"id",3}}}}));
    TEST_EQ(tbl.max().run(*conn), (R::Object{{"a",3}, {"id",99}}));
    TEST_EQ(tbl.group("a").max().run(*conn), (R::Object{{"0",R::Object{{"a",0}, {"id",96}}}, {"1",R::Object{{"a",1}, {"id",97}}}, {"2",R::Object{{"a",2}, {"id",98}}}, {"3",R::Object{{"a",3}, {"id",99}}}}));
    TEST_EQ(tbl.sum([=](R::Var row){ return (*row)["a"]; }).run(*conn), (150));
    TEST_EQ(tbl.sum(R::row["a"]).run(*conn), (150));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).sum().run(*conn), (150));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).sum([=](R::Var row){ return (*row)["id"]; }).run(*conn), (R::Object{{"0",1200}, {"1",1225}, {"2",1250}, {"3",1275}}));
    TEST_EQ(tbl.avg([=](R::Var row){ return (*row)["a"]; }).run(*conn), (1.5));
    TEST_EQ(tbl.avg(R::row["a"]).run(*conn), (1.5));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).avg().run(*conn), (1.5));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).avg([=](R::Var row){ return (*row)["id"]; }).run(*conn), (R::Object{{"0",48}, {"1",49}, {"2",50}, {"3",51}}));
    TEST_EQ(tbl.order_by(R::desc("id")).min([=](R::Var row){ return (*row)["a"]; }).run(*conn), (R::Object{{"a",0}, {"id",96}}));
    TEST_EQ(tbl.order_by(R::desc("id")).min(R::row["a"]).run(*conn), (R::Object{{"a",0}, {"id",96}}));
    TEST_EQ(tbl.order_by(R::desc("id")).min([=](R::Var row){ return (*row)["a"]; })["a"].run(*conn), (0));
    TEST_EQ(tbl.order_by(R::desc("id")).min(R::row["a"])["a"].run(*conn), (0));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).min().run(*conn), (0));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).min([=](R::Var row){ return (*row)["id"]; })["id"].run(*conn), (R::Object{{"0",0}, {"1",1}, {"2",2}, {"3",3}}));
    TEST_EQ(tbl.max([=](R::Var row){ return (*row)["a"]; })["a"].run(*conn), (3));
    TEST_EQ(tbl.max(R::row["a"])["a"].run(*conn), (3));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).max().run(*conn), (3));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).max([=](R::Var row){ return (*row)["id"]; })["id"].run(*conn), (R::Object{{"0",96}, {"1",97}, {"2",98}, {"3",99}}));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"0",1200}, {"1",1225}, {"2",1250}, {"3",1275}}));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1200}, R::Array{1, 1225}, R::Array{2, 1250}, R::Array{3, 1275}}}}));
    TEST_EQ(tbl.group(R::row["a"]).map(R::row["id"]).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1200}, R::Array{1, 1225}, R::Array{2, 1250}, R::Array{3, 1275}}}}));
    TEST_EQ(R::expr(R::array(R::object("a", 1))).filter(true).limit(1).group("a").run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{1, R::Array{R::Object{{"a",1}}}}}}}));
    TEST_EQ(tbl.group("a").type_of().run(*conn), ("GROUPED_STREAM"));
    TEST_EQ(tbl.group("a").count().type_of().run(*conn), ("GROUPED_DATA"));
    TEST_EQ(tbl.group("a").coerce_to("ARRAY").type_of().run(*conn), ("GROUPED_DATA"));
    TEST_EQ(tbl.order_by(R::OptArgs{{"index", R::expr("id")}}).filter([=](R::Var row){ return (*row)["id"]<10; }).group("a").map([=](R::Var row){ return (*row)["id"]; }).coerce_to("ARRAY").run(*conn), (R::Object{{"0",R::Array{0, 4, 8}}, {"1",R::Array{1, 5, 9}}, {"2",R::Array{2, 6}}, {"3",R::Array{3, 7}}}));
    TEST_EQ(tbl.filter([=](R::Var row){ return (*row)["id"]<10; }).group("a").count().do_([=](R::Var x){ return *x * *x; }).run(*conn), (R::Object{{"0",9}, {"1",9}, {"2",4}, {"3",4}}));
    TEST_EQ(tbl.union_(tbl).group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.union_(tbl).group(R::row["a"]).map(R::row["id"]).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.coerce_to("array").union_(tbl).group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.coerce_to("array").union_(tbl).group(R::row["a"]).map(R::row["id"]).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.union_(tbl.coerce_to("array")).group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.union_(tbl.coerce_to("array")).group(R::row["a"]).map(R::row["id"]).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 2400}, R::Array{1, 2450}, R::Array{2, 2500}, R::Array{3, 2550}}}}));
    TEST_EQ(tbl.group([=](R::Var row){ return (*row)["a"]; }).map([=](R::Var row){ return (*row)["id"]; }).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1200}, R::Array{1, 1225}, R::Array{2, 1250}, R::Array{3, 1275}}}}));
    TEST_EQ(tbl.group(R::row["a"]).map(R::row["id"]).reduce([=](R::Var a, R::Var b){ return *a + *b; }).run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1200}, R::Array{1, 1225}, R::Array{2, 1250}, R::Array{3, 1275}}}}));
    TEST_EQ(tbl.group("a").count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 25}, R::Array{1, 25}, R::Array{2, 25}, R::Array{3, 25}}}}));
    TEST_EQ(tbl.group("a").sum("id").run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1200}, R::Array{1, 1225}, R::Array{2, 1250}, R::Array{3, 1275}}}}));
    TEST_EQ(tbl.group("a").avg("id").run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 48}, R::Array{1, 49}, R::Array{2, 50}, R::Array{3, 51}}}}));
    TEST_EQ(tbl3.group([=](R::Var row){ return (*row)["b"]["c"]; }).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 20}, R::Array{1, 20}, R::Array{2, 20}, R::Array{3, 20}, R::Array{4, 20}}}}));
    TEST_EQ(tbl.group("a", [=](R::Var row){ return (*row)["id"].mod(3); }).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{R::Array{0, 0}, 9}, R::Array{R::Array{0, 1}, 8}, R::Array{R::Array{0, 2}, 8}, R::Array{R::Array{1, 0}, 8}, R::Array{R::Array{1, 1}, 9}, R::Array{R::Array{1, 2}, 8}, R::Array{R::Array{2, 0}, 8}, R::Array{R::Array{2, 1}, 8}, R::Array{R::Array{2, 2}, 9}, R::Array{R::Array{3, 0}, 9}, R::Array{R::Array{3, 1}, 8}, R::Array{R::Array{3, 2}, 8}}}}));
    TEST_EQ(tbl.map([=](R::Var row){ return (*row)["a"]; }).distinct().count().run(*conn), (4));
    TEST_EQ(tbl.distinct().type_of().run(*conn), ("STREAM"));
    TEST_EQ(tbl.distinct().count().run(*conn), (100));
    TEST_EQ(tbl.distinct(R::OptArgs{{"index", R::expr("id")}}).type_of().run(*conn), ("STREAM"));
    TEST_EQ(tbl.distinct(R::OptArgs{{"index", R::expr("id")}}).count().run(*conn), (100));
    TEST_EQ(tbl.index_create("a").run(*conn), (R::Object{{"created",1}}));
    TEST_EQ(tbl.index_wait("a").pluck("index", "ready").run(*conn), (R::Array{R::Object{{"index","a"}, {"ready",true}}}));
    TEST_EQ(tbl.between(0, 1, R::OptArgs{{"index", R::expr("a")}}).distinct().count().run(*conn), (25));
    TEST_EQ(tbl.between(0, 1, R::OptArgs{{"index", R::expr("a")}}).distinct(R::OptArgs{{"index", R::expr("id")}}).count().run(*conn), (25));
    TEST_EQ(tbl.distinct(R::OptArgs{{"index", R::expr("a")}}).type_of().run(*conn), ("STREAM"));
    TEST_EQ(tbl.distinct(R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (4));
    TEST_EQ(tbl.group().run(*conn), (err("RqlRuntimeError", "Cannot group by nothing.", R::Array{})));
    TEST_EQ(tbl.group(R::OptArgs{{"index", R::expr("id")}}).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 1}, R::Array{1, 1}, R::Array{2, 1}, R::Array{3, 1}, R::Array{4, 1}, R::Array{5, 1}, R::Array{6, 1}, R::Array{7, 1}, R::Array{8, 1}, R::Array{9, 1}, R::Array{10, 1}, R::Array{11, 1}, R::Array{12, 1}, R::Array{13, 1}, R::Array{14, 1}, R::Array{15, 1}, R::Array{16, 1}, R::Array{17, 1}, R::Array{18, 1}, R::Array{19, 1}, R::Array{20, 1}, R::Array{21, 1}, R::Array{22, 1}, R::Array{23, 1}, R::Array{24, 1}, R::Array{25, 1}, R::Array{26, 1}, R::Array{27, 1}, R::Array{28, 1}, R::Array{29, 1}, R::Array{30, 1}, R::Array{31, 1}, R::Array{32, 1}, R::Array{33, 1}, R::Array{34, 1}, R::Array{35, 1}, R::Array{36, 1}, R::Array{37, 1}, R::Array{38, 1}, R::Array{39, 1}, R::Array{40, 1}, R::Array{41, 1}, R::Array{42, 1}, R::Array{43, 1}, R::Array{44, 1}, R::Array{45, 1}, R::Array{46, 1}, R::Array{47, 1}, R::Array{48, 1}, R::Array{49, 1}, R::Array{50, 1}, R::Array{51, 1}, R::Array{52, 1}, R::Array{53, 1}, R::Array{54, 1}, R::Array{55, 1}, R::Array{56, 1}, R::Array{57, 1}, R::Array{58, 1}, R::Array{59, 1}, R::Array{60, 1}, R::Array{61, 1}, R::Array{62, 1}, R::Array{63, 1}, R::Array{64, 1}, R::Array{65, 1}, R::Array{66, 1}, R::Array{67, 1}, R::Array{68, 1}, R::Array{69, 1}, R::Array{70, 1}, R::Array{71, 1}, R::Array{72, 1}, R::Array{73, 1}, R::Array{74, 1}, R::Array{75, 1}, R::Array{76, 1}, R::Array{77, 1}, R::Array{78, 1}, R::Array{79, 1}, R::Array{80, 1}, R::Array{81, 1}, R::Array{82, 1}, R::Array{83, 1}, R::Array{84, 1}, R::Array{85, 1}, R::Array{86, 1}, R::Array{87, 1}, R::Array{88, 1}, R::Array{89, 1}, R::Array{90, 1}, R::Array{91, 1}, R::Array{92, 1}, R::Array{93, 1}, R::Array{94, 1}, R::Array{95, 1}, R::Array{96, 1}, R::Array{97, 1}, R::Array{98, 1}, R::Array{99, 1}}}}));
    TEST_EQ(tbl.group(R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{0, 25}, R::Array{1, 25}, R::Array{2, 25}, R::Array{3, 25}}}}));
    TEST_EQ(tbl.group("a", R::OptArgs{{"index", R::expr("id")}}).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{R::Array{0, 0}, 1}, R::Array{R::Array{0, 4}, 1}, R::Array{R::Array{0, 8}, 1}, R::Array{R::Array{0, 12}, 1}, R::Array{R::Array{0, 16}, 1}, R::Array{R::Array{0, 20}, 1}, R::Array{R::Array{0, 24}, 1}, R::Array{R::Array{0, 28}, 1}, R::Array{R::Array{0, 32}, 1}, R::Array{R::Array{0, 36}, 1}, R::Array{R::Array{0, 40}, 1}, R::Array{R::Array{0, 44}, 1}, R::Array{R::Array{0, 48}, 1}, R::Array{R::Array{0, 52}, 1}, R::Array{R::Array{0, 56}, 1}, R::Array{R::Array{0, 60}, 1}, R::Array{R::Array{0, 64}, 1}, R::Array{R::Array{0, 68}, 1}, R::Array{R::Array{0, 72}, 1}, R::Array{R::Array{0, 76}, 1}, R::Array{R::Array{0, 80}, 1}, R::Array{R::Array{0, 84}, 1}, R::Array{R::Array{0, 88}, 1}, R::Array{R::Array{0, 92}, 1}, R::Array{R::Array{0, 96}, 1}, R::Array{R::Array{1, 1}, 1}, R::Array{R::Array{1, 5}, 1}, R::Array{R::Array{1, 9}, 1}, R::Array{R::Array{1, 13}, 1}, R::Array{R::Array{1, 17}, 1}, R::Array{R::Array{1, 21}, 1}, R::Array{R::Array{1, 25}, 1}, R::Array{R::Array{1, 29}, 1}, R::Array{R::Array{1, 33}, 1}, R::Array{R::Array{1, 37}, 1}, R::Array{R::Array{1, 41}, 1}, R::Array{R::Array{1, 45}, 1}, R::Array{R::Array{1, 49}, 1}, R::Array{R::Array{1, 53}, 1}, R::Array{R::Array{1, 57}, 1}, R::Array{R::Array{1, 61}, 1}, R::Array{R::Array{1, 65}, 1}, R::Array{R::Array{1, 69}, 1}, R::Array{R::Array{1, 73}, 1}, R::Array{R::Array{1, 77}, 1}, R::Array{R::Array{1, 81}, 1}, R::Array{R::Array{1, 85}, 1}, R::Array{R::Array{1, 89}, 1}, R::Array{R::Array{1, 93}, 1}, R::Array{R::Array{1, 97}, 1}, R::Array{R::Array{2, 2}, 1}, R::Array{R::Array{2, 6}, 1}, R::Array{R::Array{2, 10}, 1}, R::Array{R::Array{2, 14}, 1}, R::Array{R::Array{2, 18}, 1}, R::Array{R::Array{2, 22}, 1}, R::Array{R::Array{2, 26}, 1}, R::Array{R::Array{2, 30}, 1}, R::Array{R::Array{2, 34}, 1}, R::Array{R::Array{2, 38}, 1}, R::Array{R::Array{2, 42}, 1}, R::Array{R::Array{2, 46}, 1}, R::Array{R::Array{2, 50}, 1}, R::Array{R::Array{2, 54}, 1}, R::Array{R::Array{2, 58}, 1}, R::Array{R::Array{2, 62}, 1}, R::Array{R::Array{2, 66}, 1}, R::Array{R::Array{2, 70}, 1}, R::Array{R::Array{2, 74}, 1}, R::Array{R::Array{2, 78}, 1}, R::Array{R::Array{2, 82}, 1}, R::Array{R::Array{2, 86}, 1}, R::Array{R::Array{2, 90}, 1}, R::Array{R::Array{2, 94}, 1}, R::Array{R::Array{2, 98}, 1}, R::Array{R::Array{3, 3}, 1}, R::Array{R::Array{3, 7}, 1}, R::Array{R::Array{3, 11}, 1}, R::Array{R::Array{3, 15}, 1}, R::Array{R::Array{3, 19}, 1}, R::Array{R::Array{3, 23}, 1}, R::Array{R::Array{3, 27}, 1}, R::Array{R::Array{3, 31}, 1}, R::Array{R::Array{3, 35}, 1}, R::Array{R::Array{3, 39}, 1}, R::Array{R::Array{3, 43}, 1}, R::Array{R::Array{3, 47}, 1}, R::Array{R::Array{3, 51}, 1}, R::Array{R::Array{3, 55}, 1}, R::Array{R::Array{3, 59}, 1}, R::Array{R::Array{3, 63}, 1}, R::Array{R::Array{3, 67}, 1}, R::Array{R::Array{3, 71}, 1}, R::Array{R::Array{3, 75}, 1}, R::Array{R::Array{3, 79}, 1}, R::Array{R::Array{3, 83}, 1}, R::Array{R::Array{3, 87}, 1}, R::Array{R::Array{3, 91}, 1}, R::Array{R::Array{3, 95}, 1}, R::Array{R::Array{3, 99}, 1}}}}));
    TEST_EQ(tbl.group("a", R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{R::Array{0, 0}, 25}, R::Array{R::Array{1, 1}, 25}, R::Array{R::Array{2, 2}, 25}, R::Array{R::Array{3, 3}, 25}}}}));
    TEST_EQ(tbl.group("a", [=](R::Var row){ return R::expr("f"); }, [=](R::Var row){ return R::array(); }, [=](R::Var row){ return R::array(R::object(), R::array(0), R::Nil(), 0); }, R::OptArgs{{"multi", R::expr(true)}}).count().run(*conn), (R::Object{{"$reql_type$","GROUPED_DATA"}, {"data",R::Array{R::Array{R::Array{0, "f", R::Nil(), R::Array{0}}, 25}, R::Array{R::Array{0, "f", R::Nil(), R::Nil()}, 25}, R::Array{R::Array{0, "f", R::Nil(), 0}, 25}, R::Array{R::Array{0, "f", R::Nil(), R::Object{}}, 25}, R::Array{R::Array{1, "f", R::Nil(), R::Array{0}}, 25}, R::Array{R::Array{1, "f", R::Nil(), R::Nil()}, 25}, R::Array{R::Array{1, "f", R::Nil(), 0}, 25}, R::Array{R::Array{1, "f", R::Nil(), R::Object{}}, 25}, R::Array{R::Array{2, "f", R::Nil(), R::Array{0}}, 25}, R::Array{R::Array{2, "f", R::Nil(), R::Nil()}, 25}, R::Array{R::Array{2, "f", R::Nil(), 0}, 25}, R::Array{R::Array{2, "f", R::Nil(), R::Object{}}, 25}, R::Array{R::Array{3, "f", R::Nil(), R::Array{0}}, 25}, R::Array{R::Array{3, "f", R::Nil(), R::Nil()}, 25}, R::Array{R::Array{3, "f", R::Nil(), 0}, 25}, R::Array{R::Array{3, "f", R::Nil(), R::Object{}}, 25}}}}));
    TEST_EQ(tbl.group("a").count().ungroup().run(*conn), (R::Array{R::Object{{"group",0}, {"reduction",25}}, R::Object{{"group",1}, {"reduction",25}}, R::Object{{"group",2}, {"reduction",25}}, R::Object{{"group",3}, {"reduction",25}}}));
    TEST_EQ(tbl.group("a").ungroup()["group"].run(*conn), (R::Array{0, 1, 2, 3}));
    TEST_EQ(tbl.order_by(R::OptArgs{{"index", R::expr("id")}}).limit(16).group("a", "a").map(R::row["id"]).sum().ungroup().run(*conn), (R::Array{R::Object{{"group",R::Array{0, 0}}, {"reduction",24}}, R::Object{{"group",R::Array{1, 1}}, {"reduction",28}}, R::Object{{"group",R::Array{2, 2}}, {"reduction",32}}, R::Object{{"group",R::Array{3, 3}}, {"reduction",36}}}));
    TEST_EQ(tbl.group("a", R::Nil()).count().ungroup().run(*conn), (R::Array{R::Object{{"group",R::Array{0, R::Nil()}}, {"reduction",25}}, R::Object{{"group",R::Array{1, R::Nil()}}, {"reduction",25}}, R::Object{{"group",R::Array{2, R::Nil()}}, {"reduction",25}}, R::Object{{"group",R::Array{3, R::Nil()}}, {"reduction",25}}}));
    TEST_EQ(tbl.group("a", [=](R::Var row){ return R::array(1, "two"); }, R::OptArgs{{"multi", R::expr(true)}}).count().ungroup().run(*conn), (R::Array{R::Object{{"group",R::Array{0, 1}}, {"reduction",25}}, R::Object{{"group",R::Array{0, "two"}}, {"reduction",25}}, R::Object{{"group",R::Array{1, 1}}, {"reduction",25}}, R::Object{{"group",R::Array{1, "two"}}, {"reduction",25}}, R::Object{{"group",R::Array{2, 1}}, {"reduction",25}}, R::Object{{"group",R::Array{2, "two"}}, {"reduction",25}}, R::Object{{"group",R::Array{3, 1}}, {"reduction",25}}, R::Object{{"group",R::Array{3, "two"}}, {"reduction",25}}}));
    TEST_EQ(tbl.count().run(*conn), (100));
    TEST_EQ(tbl.min().run(*conn), (R::Object{{"a",0}, {"id",0}}));
    TEST_EQ(tbl.min(R::OptArgs{{"index", R::expr("id")}}).run(*conn), (R::Object{{"a",0}, {"id",0}}));
    TEST_EQ(tbl.min(R::OptArgs{{"index", R::expr("a")}}).run(*conn), (R::Object{{"a",0}, {"id",0}}));
    TEST_EQ(tbl.max().without("b").run(*conn), (R::Object{{"a",3}, {"id",99}}));
    TEST_EQ(tbl.max(R::OptArgs{{"index", R::expr("id")}}).without("b").run(*conn), (R::Object{{"a",3}, {"id",99}}));
    TEST_EQ(tbl.max(R::OptArgs{{"index", R::expr("a")}}).without("b").run(*conn), (R::Object{{"a",3}, {"id",99}}));
    exit_section();
}
