// auto-generated by yaml_to_cxx.py from test/upstream/datum/bool.yaml
#include "testlib.h"
void test_upstream_datum_bool() {
    enter_section("test_upstream_datum_bool: Tests of conversion to and from the RQL bool type");
    TEST_EQ(R::expr(true).run(*conn), (true));
    TEST_EQ(R::expr(false).run(*conn), (false));
    TEST_EQ(R::expr(false).type_of().run(*conn), ("BOOL"));
    TEST_EQ(R::expr(true).coerce_to("string").run(*conn), ("true"));
    TEST_EQ(R::expr(true).coerce_to("bool").run(*conn), (true));
    exit_section();
}
