// SPDX-FileCopyrightText: 2023 Ledger SAS
// SPDX-License-Identifier: Apache-2.0


#include <sentry/bits.h>
#include <gtest/gtest.h>

TEST(Bits, Bit) {
    EXPECT_EQ(BIT(0), 0x00000001);
    EXPECT_EQ(BIT(1), 0x00000002);
    EXPECT_EQ(BIT(2), 0x00000004);
    EXPECT_EQ(BIT(3), 0x00000008);
    EXPECT_EQ(BIT(4), 0x00000010);
    EXPECT_EQ(BIT(5), 0x00000020);
    EXPECT_EQ(BIT(6), 0x00000040);
    EXPECT_EQ(BIT(7), 0x00000080);
    EXPECT_EQ(BIT(8), 0x00000100);
    EXPECT_EQ(BIT(9), 0x00000200);
    EXPECT_EQ(BIT(10), 0x00000400);
    EXPECT_EQ(BIT(11), 0x00000800);
    EXPECT_EQ(BIT(12), 0x00001000);
    EXPECT_EQ(BIT(13), 0x00002000);
    EXPECT_EQ(BIT(14), 0x00004000);
    EXPECT_EQ(BIT(15), 0x00008000);
    EXPECT_EQ(BIT(16), 0x00010000);
    EXPECT_EQ(BIT(17), 0x00020000);
    EXPECT_EQ(BIT(18), 0x00040000);
    EXPECT_EQ(BIT(19), 0x00080000);
    EXPECT_EQ(BIT(20), 0x00100000);
    EXPECT_EQ(BIT(21), 0x00200000);
    EXPECT_EQ(BIT(22), 0x00400000);
    EXPECT_EQ(BIT(23), 0x00800000);
    EXPECT_EQ(BIT(24), 0x01000000);
    EXPECT_EQ(BIT(25), 0x02000000);
    EXPECT_EQ(BIT(26), 0x04000000);
    EXPECT_EQ(BIT(27), 0x08000000);
    EXPECT_EQ(BIT(28), 0x10000000);
    EXPECT_EQ(BIT(29), 0x20000000);
    EXPECT_EQ(BIT(30), 0x40000000);
    EXPECT_EQ(BIT(31), 0x80000000);
}

TEST(BitFieldMask, SingleBitMask) {
    EXPECT_EQ(BITFIELD_MASK(0, 0), 0x1);
    EXPECT_EQ(BITFIELD_MASK(7, 7), 0x80);
    EXPECT_EQ(BITFIELD_MASK(8, 8), 0x100);
    EXPECT_EQ(BITFIELD_MASK(15, 15), 0x8000);
    EXPECT_EQ(BITFIELD_MASK(16, 16), 0x10000);
    EXPECT_EQ(BITFIELD_MASK(23, 23), 0x800000);
    EXPECT_EQ(BITFIELD_MASK(24, 24), 0x1000000);
    EXPECT_EQ(BITFIELD_MASK(31, 31), 0x80000000);
}

TEST(BitFieldMask, RandomBitWidthMask) {
    EXPECT_EQ(BITFIELD_MASK(12, 0), 0x1fff);
    EXPECT_EQ(BITFIELD_MASK(24, 18), 0x1fc0000);
    EXPECT_EQ(BITFIELD_MASK(31, 9), 0xfffffe00);
    EXPECT_EQ(BITFIELD_MASK(22, 10), 0x007ffc00);
}

TEST(BitFieldMask, FullMask) {
    EXPECT_EQ(BITFIELD_MASK(31, 0), 0xffffffff);
}

TEST(BitFieldShift, GetShiftBitFromBit) {
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(0)), 0);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(1)), 1);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(2)), 2);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(3)), 3);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(4)), 4);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(5)), 5);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(6)), 6);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(7)), 7);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(8)), 8);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(9)), 9);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(10)), 10);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(11)), 11);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(12)), 12);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(13)), 13);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(14)), 14);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(15)), 15);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(16)), 16);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(17)), 17);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(18)), 18);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(19)), 19);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(20)), 20);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(21)), 21);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(22)), 22);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(23)), 23);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(24)), 24);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(25)), 25);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(26)), 26);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(27)), 27);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(28)), 28);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(29)), 29);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(30)), 30);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BIT(31)), 31);
}

TEST(BitFieldShift, GetShiftBitFromMask) {
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(0, 0)), 0);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(7, 7)), 7);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(8, 8)), 8);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(15, 15)), 15);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(16, 16)), 16);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(23, 23)), 23);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(24, 24)), 24);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(31, 31)), 31);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(12, 0)), 0);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(24, 18)), 18);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(31, 9)), 9);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(22, 10)), 10);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(31, 0)), 0);
    EXPECT_EQ(__BITSHIFT_FROM_MASK(BITFIELD_MASK(31, 0)), 0);
}

TEST(BitFieldValue, Put) {
    /* a test field is a pair<field_mask, field_value> */
    using test_field = std::pair<uint32_t, uint32_t>;
    auto test_bitfield_put = [] (uint32_t expected, auto... Fields) -> void {
        uint32_t bitfield = 0UL;
        for (test_field& field: std::array<test_field, sizeof...(Fields)>{Fields...}) {
            bitfield |= BITFIELD_PUT(field.second, field.first);
        }
        EXPECT_EQ(bitfield, expected);
    };

    test_field field1{BITFIELD_MASK(3, 0), 0xa};
    test_field field2{BITFIELD_MASK(14, 5), 0x1f0};
    test_field field3{BITFIELD_MASK(31, 17), 0x3f00};

    test_field truncated_field1{BITFIELD_MASK(3, 0), 0x1a};
    test_field truncated_field2{BITFIELD_MASK(14, 5), 0x1001f0};

    test_bitfield_put(0x0000000a, field1);
    test_bitfield_put(0x00003e00, field2);
    test_bitfield_put(0x0000000a, truncated_field1);
    test_bitfield_put(0x00003e00, truncated_field2);
    test_bitfield_put(0x7e000000, field3);
    test_bitfield_put(0x00003e0a, field1, field2);
    test_bitfield_put(0x7e00000a, field1, field3);
    test_bitfield_put(0x7e003e00, field2, field3);
    test_bitfield_put(0x7e003e0a, field1, field2, field3);
}

TEST(BitFieldValue, Get) {
    auto field1{BITFIELD_MASK(3, 0)};
    auto field2{BITFIELD_MASK(14, 5)};
    auto field3{BITFIELD_MASK(31, 17)};

    const uint32_t bitfield{0x7e003e0a};

    EXPECT_EQ(BITFIELD_GET(bitfield, field1), 0x0000000a);
    EXPECT_EQ(BITFIELD_GET(bitfield, field2), 0x000001f0);
    EXPECT_EQ(BITFIELD_GET(bitfield, field3), 0x00003f00);
}
