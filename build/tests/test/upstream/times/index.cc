// auto-generated by yaml_to_cxx.py from test/upstream/times/index.yaml
#include "testlib.h"
void test_upstream_times_index() {
    enter_section("test_upstream_times_index: secondary indexes on times");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    auto ts = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445162.0872}, {"$reql_type$","TIME"}};
    auto t1 = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445163.0872}, {"$reql_type$","TIME"}};
    auto t2 = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445163.08832}, {"$reql_type$","TIME"}};
    auto t3 = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445163.08943}, {"$reql_type$","TIME"}};
    auto t4 = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445163.09055}, {"$reql_type$","TIME"}};
    auto t5 = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445163.09166}, {"$reql_type$","TIME"}};
    auto te = R::Object{{"timezone","-07:00"}, {"epoch_time",1375445164.0872}, {"$reql_type$","TIME"}};
    auto trows = R::Array{R::Object{{"id",t1}}, R::Object{{"id",t2}}, R::Object{{"id",t3}}, R::Object{{"id",t4}}, R::Object{{"id",t5}}};
    TEST_EQ(tbl.insert(trows)["inserted"].run(*conn), (5));
    auto bad_insert = R::Array{R::Object{{"id",R::expr(t1).in_timezone("Z")}}};
    TEST_EQ(tbl.insert(bad_insert)["first_error"].run(*conn), ("Duplicate primary key `id`:\n{\n	\"id\":	{\n		\"$reql_type$\":	\"TIME\",\n		\"epoch_time\":	1375445163.0869998932,\n		\"timezone\":	\"-07:00\"\n	}\n}\n{\n	\"id\":	{\n		\"$reql_type$\":	\"TIME\",\n		\"epoch_time\":	1375445163.0869998932,\n		\"timezone\":	\"+00:00\"\n	}\n}"));
    TEST_EQ(tbl.between(ts, te).count().run(*conn), (5));
    TEST_EQ(tbl.between(t1, t4).count().run(*conn), (3));
    TEST_EQ(tbl.between(t1, t4, R::OptArgs{{"right_bound", R::expr("closed")}}).count().run(*conn), (4));
    TEST_EQ(tbl.between(R::expr(ts).in_timezone("+06:00"), te).count().run(*conn), (5));
    TEST_EQ(tbl.between(t1, R::expr(t4).in_timezone("+08:00")).count().run(*conn), (3));
    TEST_EQ(tbl.between(R::expr(t1).in_timezone("Z"), t4, R::OptArgs{{"right_bound", R::expr("closed")}}).count().run(*conn), (4));
    TEST_EQ(tbl.update([=](R::Var row){ return R::object("a", (*row)["id"]); })["replaced"].run(*conn), (5));
    TEST_EQ(tbl.index_create("a").run(*conn), (R::Object{{"created",1}}));
    TEST_EQ(tbl.index_wait("a").count().run(*conn), (1));
    TEST_EQ(tbl.between(ts, te, R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (5));
    TEST_EQ(tbl.between(t1, t4, R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(t1, t4, R::OptArgs{{"right_bound", R::expr("closed")}, {"index", R::expr("a")}}).count().run(*conn), (4));
    TEST_EQ(tbl.between(R::expr(ts).in_timezone("+06:00"), te, R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (5));
    TEST_EQ(tbl.between(t1, R::expr(t4).in_timezone("+08:00"), R::OptArgs{{"index", R::expr("a")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(R::expr(t1).in_timezone("Z"), t4, R::OptArgs{{"right_bound", R::expr("closed")}, {"index", R::expr("a")}}).count().run(*conn), (4));
    TEST_EQ(tbl.index_create("b", [=](R::Var row){ return R::branch((*row)["id"]<t4, (*row)["a"], R::Nil()); }).run(*conn), (R::Object{{"created",1}}));
    TEST_EQ(tbl.index_wait("b").count().run(*conn), (1));
    TEST_EQ(tbl.index_wait("b").count().run(*conn), (1));
    TEST_EQ(tbl.between(ts, te, R::OptArgs{{"index", R::expr("b")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(t1, t4, R::OptArgs{{"index", R::expr("b")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(t1, t4, R::OptArgs{{"right_bound", R::expr("closed")}, {"index", R::expr("b")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(R::expr(ts).in_timezone("+06:00"), te, R::OptArgs{{"index", R::expr("b")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(t1, R::expr(t4).in_timezone("+08:00"), R::OptArgs{{"index", R::expr("b")}}).count().run(*conn), (3));
    TEST_EQ(tbl.between(R::expr(t1).in_timezone("Z"), t4, R::OptArgs{{"right_bound", R::expr("closed")}, {"index", R::expr("b")}}).count().run(*conn), (3));
    auto oldtime = datetime.fromtimestamp(1375147296.681, PacificTimeZone());
    auto curtime = datetime.now();
    TEST_EQ(tbl.insert(R::array(R::object("id", oldtime)))["inserted"].run(*conn), (1));
    TEST_EQ(tbl.get(oldtime)["id"].type_of().run(*conn), ("PTYPE<TIME>"));
}
