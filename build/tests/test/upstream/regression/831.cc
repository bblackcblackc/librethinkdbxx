// auto-generated by yaml_to_cxx.py from test/upstream/regression/831.yaml
#include "testlib.h"
void test_upstream_regression_831() {
    enter_section("test_upstream_regression_831: 831 -- Empty batched_replaces_t constructed");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_EQ(tbl.insert(R::array(true, true)).run(*conn), (R::Object{{"first_error","Expected type OBJECT but found BOOL."}, {"skipped",0}, {"deleted",0}, {"unchanged",0}, {"errors",2}, {"replaced",0}, {"inserted",0}}));
    exit_section();
}
