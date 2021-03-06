// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// Standard pinout since July 2015
// This uses the PWM pin to create the timing.
#define RGB_PARALLEL_CHAINS 3
union IoBits {
  struct {
    // This bitset reflects the GPIO mapping. The naming of the
    // pins of type 'p0_r1' means 'first parallel chain, red-bit one'
    //                                 GPIO Header-pos
    unsigned int unused_0_1     : 2;  //  0..1  (only on RPi 1, Revision 1)
    unsigned int p2_g1          : 1;  //  2 P1-03 (masks SDA when parallel=3)
    unsigned int p2_b1          : 1;  //  3 P1-05 (masks SCL when parallel=3)
    unsigned int strobe         : 1;  //  4 P1-07
    unsigned int p1_g1          : 1;  //  5 P1-29 (only on A+/B+/Pi2)
    unsigned int p1_b1          : 1;  //  6 P1-31 (only on A+/B+/Pi2)
    // TODO: be able to disable chain 0 for higher-pin RPis to gain SPI back.
    unsigned int p0_b1          : 1;  //  7 P1-26 (masks: SPI0_CE1)
    unsigned int p0_r2          : 1;  //  8 P1-24 (masks: SPI0_CE0)
    unsigned int p0_g2          : 1;  //  9 P1-21 (masks: SPI0_MISO
    unsigned int p0_b2          : 1;  // 10 P1-19 (masks: SPI0_MOSI)
    unsigned int p0_r1          : 1;  // 11 P1-23 (masks: SPI0_SCKL)

    unsigned int p1_r1          : 1;  // 12 P1-32 (only on A+/B+/Pi2)
    unsigned int p1_g2          : 1;  // 13 P1-33 (only on A+/B+/Pi2)
    unsigned int p2_r1          : 1;  // 14 P1-08 (masks TxD when parallel=3)
    unsigned int e              : 1;  // 15 P1-10 (RxD) - kept free unless 1:64
    unsigned int p2_g2          : 1;  // 16 P1-36 (only on A+/B+/Pi2)

    unsigned int clock          : 1;  // 17 P1-11

    unsigned int output_enable  : 1;  // 18 P1-12 (PWM pin: our timing)
    unsigned int p1_r2          : 1;  // 19 P1-35 (only on A+/B+/Pi2)
    unsigned int p1_b2          : 1;  // 20 P1-38 (only on A+/B+/Pi2)
    unsigned int p2_b2          : 1;  // 21 P1-40 (only on A+/B+/Pi2)

    unsigned int a              : 1;  // 22 P1-15  // row bits.
    unsigned int b              : 1;  // 23 P1-16
    unsigned int c              : 1;  // 24 P1-18
    unsigned int d              : 1;  // 25 P1-22

    unsigned int p2_r2          : 1;  // 26 P1-37 (only on A+/B+/Pi2)
    unsigned int p0_g1          : 1;  // 27 P1-13 (Not on RPi1, Rev1)
  } bits;
  uint32_t raw;
  IoBits() : raw(0) {}
};
