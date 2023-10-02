// SPDX-FileCopyrightText: 2023 Ledger SAS
// SPDX-License-Identifier: Apache-2.0

/**
 * @file Sentry I/O manager
 */
#include <stdbool.h>

#include <uapi/handle.h>

#include <sentry/ktypes.h>

/* BSP headers */
#include <bsp/drivers/gpio/gpio.h>
#ifdef CONFIG_SOC_FAMILY_STM32
#include <bsp/drivers/exti/exti.h>
#endif

#include <sentry/managers/io.h>



/**
 * @brief probe all BSP-related part of the I/O manipulation
 *
 * Kconfig already has auto-selected the various drviers needed for I/O. All
 * I/O drivers probing and manipulation is done through this manager's API.
 */
kstatus_t mgr_io_probe(void)
{
    kstatus_t status = K_STATUS_OKAY;

    /* This backend should be generic to any SoC, any arch */
    if (unlikely((status = gpio_probe()) != K_STATUS_OKAY)) {
        goto err;
    };
#ifdef CONFIG_SOC_FAMILY_STM32
    /* STM32 BSP implement EXTI controler for external interrupt & events */
    if (unlikely((status = exti_probe()) != K_STATUS_OKAY)) {
        goto err;
    };
#endif
err:
    return status;
}

/**
 * @brief Set I/O identified by ioh
 *
 * This set output moode I/O line value to high level
 */
kstatus_t mgr_io_set(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

/**
 * @brief Reset I/O identified by ioh
 *
 * This set output moode I/O line value to low level
 */
kstatus_t mgr_io_reset(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

/**
 * @brief Read I/O identified by ioh
 *
 * This get back current I/O line value, in both INPUT and OUTPUT mode
 */
kstatus_t mgr_io_read(ioh_t ioh, bool *val)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

/**
 * @brief Configure I/O identified by ioh
 */
kstatus_t mgr_io_configure(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

/* About interrupt associated to I/O */


kstatus_t mgr_io_mask_interrupt(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

kstatus_t mgr_io_unmask_interrupt(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

kstatus_t mgr_io_mask_event(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

kstatus_t mgr_io_unmask_event(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}

kstatus_t mgr_io_clear_pending_interrupt(ioh_t ioh)
{
    kstatus_t status = K_STATUS_OKAY;
    return status;
}
