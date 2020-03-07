/*
MIT License

Copyright (c) 2020 Leszek Kantorek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "CUnitTests/CUnitTests.h"

static void error_should_be(__CUnitTests_Error error){
    if(__CUnitTests_Global_currentTest->result != error){
        test_failed();
    }else{
        test_succeed();
    }
}

test(assert_true_success,{
    test_assert_true(1, "Should be true");
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_true_failure,{
    test_assert_true(0, "Should be true");
    error_should_be(__CUnitTests_Error_Failed);
});

test(assert_false_success,{
    test_assert_false(0, "Should be false");
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_false_failure,{
    test_assert_false(1, "Should be false");
    error_should_be(__CUnitTests_Error_Failed);
});

test(assert_equal_success,{
 	int first = 1;
 	int second = 1;
    test_assert_equal(first, second, "Should be %d but was %d", first, second);
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_equal_failure,{
    int first = 1;
 	int second = 2;
    test_assert_equal(first, second, "Should be %d but was %d", first, second);
    error_should_be(__CUnitTests_Error_Failed);
});

test(assert_not_equal_success,{
 	int first = 2;
 	int second = 1;
    test_assert_not_equal(first, second, "Should not be %d but was %d", first, second);
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_not_equal_failure,{
    int first = 1;
 	int second = 1;
    test_assert_not_equal(first, second, "Should not be %d but was %d", first, second);
    error_should_be(__CUnitTests_Error_Failed);
});

test(assert_null_success,{
 	char *test = NULL;
    test_assert_null(test, "Should be null");
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_null_failure,{
    char *test = "Something";
    test_assert_null(test, "Should be null");
    error_should_be(__CUnitTests_Error_Failed);
});

test(assert_not_null_success,{
 	char *test = "Something";
    test_assert_not_null(test, "Should not be null");
    error_should_be(__CUnitTests_Error_Succeed);
});

test(assert_not_null_failure,{
    char *test = NULL;
    test_assert_not_null(test, "Should not be null");
    error_should_be(__CUnitTests_Error_Failed);
});