#ifndef FRAMAC_TOOLS_H
#define FRAMAC_TOOLS_H

/*
 * FramaC-based generated entropy sources for varisous type coverage
 * and bound checking
 */
extern volatile uint8_t Frama_C_entropy_source_8 __attribute__((unused)) __attribute__((FRAMA_C_MODEL));
extern volatile uint16_t Frama_C_entropy_source_16 __attribute__((unused)) __attribute__((FRAMA_C_MODEL));
extern volatile uint32_t Frama_C_entropy_source_32 __attribute__((unused)) __attribute__((FRAMA_C_MODEL));

/*@ requires order: 0 <= min <= max <= 255;
    assigns \result \from min, max, Frama_C_entropy_source_8;
    assigns Frama_C_entropy_source_8 \from Frama_C_entropy_source_8;
    ensures result_bounded: min <= \result <= max ;
 */
uint8_t Frama_C_interval_8(uint8_t min, uint8_t max);

/*@ requires order: 0 <= min <= max <= 65535;
    assigns \result \from min, max, Frama_C_entropy_source_16;
    assigns Frama_C_entropy_source_16 \from Frama_C_entropy_source_16;
    ensures result_bounded: min <= \result <= max ;
 */
uint16_t Frama_C_interval_16(uint16_t min, uint16_t max);

/*@ requires order: 0 <= min <= max <= 4294967295;
    assigns \result \from min, max, Frama_C_entropy_source_32;
    assigns Frama_C_entropy_source_32 \from Frama_C_entropy_source_32;
    ensures result_bounded: min <= \result <= max ;
 */
uint32_t Frama_C_interval_32(uint32_t min, uint32_t max);

#endif/*FRAMAC_TOOLS_H*/
