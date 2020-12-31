#include <gtest/gtest.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern "C"
{
#include "FIFO.h"
}

#define SIZE 5

class FIFO_test : public ::testing::Test
{
public:
    FIFO_test() {}
    ~FIFO_test() {}

    virtual void SetUp()
    {
        ASSERT_EQ(list, nullptr);
        init_fifo(&list);
    }

    virtual void TearDown()
    {
        FIFO_delete(&list);
        ASSERT_EQ(list, nullptr);
    }

    Fifo_data *list = NULL;

    void init_fifo(Fifo_data **list);
    void FIFO_delete(Fifo_data **list);

    /* test values */
    uint16_t tab1[SIZE] = {
        5,
        10,
        15,
        20,
        25,
    };

    const int total_time = 75;

    uint16_t tab2[SIZE] = {
        1,
        2,
        3,
        5,
        8,
    };
};
/*********************** LOCAL FUNCTIONS *******************/
void FIFO_test ::init_fifo(Fifo_data **list)
{
    for (int i = 0; i < SIZE; ++i)
    {
        write_data_to_FIFO(list, tab1[i], tab2[i]);
    }
}

void FIFO_test ::FIFO_delete(Fifo_data **list)
{
    if ((*list) != NULL)
    {
        while (get_amount_of_times(*list) > 0)
        {
            Fifo_data *new_one = NULL;
            new_one = (*list)->next;
            free(*list);
            (*list) = new_one;
        }
    }
}

/************************** TESTS **************************/

TEST_F(FIFO_test, test_function_read_data)
{
    uint16_t var1 = 33;
    uint16_t var2 = 13;

    read_data(&list, &var1, &var2);

    EXPECT_EQ(var1, 5);
    EXPECT_EQ(var2, 1);
}

TEST_F(FIFO_test, test_function_read_time)
{
    int retVal = 10;
    retVal = read_time(list);

    EXPECT_EQ(retVal, total_time);
}