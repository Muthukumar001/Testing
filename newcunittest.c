
#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "add.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

int add(int x, int y);

void test1() {
    CU_ASSERT_EQUAL( add(5,5), 10 );
}

void test2() {
    CU_ASSERT_EQUAL( add(2,3), 5 );
}

void test3() {
    
    CU_ASSERT_EQUAL( add(68,77), 145 );
}

void test4() {
    CU_ASSERT_EQUAL( add(0,6), 6 );
	CU_ASSERT_EQUAL( sizeof(z), 4 );
	printf("%d",sizeof(z));
}

void testAdd() {
//    int x;
//    int y;
//    int result = add(x, y);
    if ( 1 ) /*check result*/ {
        CU_ASSERT_EQUAL( add(2,8), 10 );
	CU_ASSERT_EQUAL( sizeof(z), 4 );
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ( (NULL == CU_add_test(pSuite, "test1", test1)) ||
            (NULL == CU_add_test(pSuite, "test2", test2)) ||
            (NULL == CU_add_test(pSuite, "test3", test3)) ||
            (NULL == CU_add_test(pSuite, "test4", test4)) ||
            (NULL == CU_add_test(pSuite, "testAdd", testAdd))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ( (NULL == CU_add_test(pSuite, "test1", test1)) ||
            (NULL == CU_add_test(pSuite, "test2", test2)) ||
            (NULL == CU_add_test(pSuite, "test3", test3)) ||
            (NULL == CU_add_test(pSuite, "test4", test4)) ||
            (NULL == CU_add_test(pSuite, "testAdd", testAdd))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
