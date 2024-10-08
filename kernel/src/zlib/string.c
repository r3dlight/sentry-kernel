// SPDX-FileCopyrightText: 2023 Ledger SAS
// SPDX-License-Identifier: Apache-2.0

#include <string.h>
#include <sentry/ktypes.h>

/* string related functions, for debug usage only */
#ifndef __FRAMAC__
static
#endif
size_t sentry_strnlen(const char *s, size_t maxlen)
{
    size_t result = 0;

    if (s == NULL) {
        /** TODO: panic to be called */
        goto err;
    }

    while ((s[result] != '\0') && result < maxlen) {
        result++;
    }
err:
    return result;
}

/**
 * @brief Set n first bytes of a given memory area with a given byte value
 *
 * INFO: The C standard says that null argument(s) to string
 * functions produce undefined behavior.
 *
 * This is a global warning for the POSIX and C99/C99 libstring:
 * check your arguments before using it!
 *
 * Conforming to:
 * POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.
 */
#ifndef __FRAMAC__
static
#endif
void   *sentry_memset(void *s, int c, unsigned int n)
{
    /* sanitation. This part can produce, as defined in the above
     * standard, an 'undefined behavior'. As a consequence, in all
     * string function, invalid input will produce, for integer
     * return, returning 42, for string return, returning NULL */
    if (unlikely(!s)) {
        goto err;
    }

    /* memseting s with c */
    char   *bytes = s;

    while (n) {
        *bytes = c;
        bytes++;
        n--;
    }
err:
    return s;
}

static secure_bool_t regions_overlaps(const void* a, const void* b, unsigned int n)
{
    secure_bool_t res = SECURE_TRUE;
    size_t _a = (size_t)a;
    size_t _b = (size_t)b;
    if ((_a < _b) && ((_a + n) > _b)) {
        goto err;
    }
    if ((_a > _b) && ((_b + n) > _a)) {
        goto err;
    }
    res = SECURE_FALSE;
err:
    return res;
}

#ifndef __FRAMAC__
static
#endif
void   *sentry_memcpy(void * restrict dest, const void* restrict src, size_t n)
{
    if (unlikely(!dest || !src)) {
        goto err;
    }
    if (unlikely(regions_overlaps(dest, src, n) == SECURE_TRUE)) {
        goto err;
    }

    uint32_t *s = (uint32_t*)src;
    uint32_t *d = (uint32_t*)dest;

    /* copy word by word */
    while (n >= 4) {
        *d = *s;
        d++;
        s++;
        n -= 4;
    }
    /* if n is not word aligned, finishing with last bytes */
    uint8_t *s8 = (uint8_t*)s;
    uint8_t *d8 = (uint8_t*)d;
    while (n) {
        *d8 = *s8;
        d8++;
        s8++;
        n--;
    }
err:
    return dest;
}

#ifndef TEST_MODE
#ifndef __FRAMAC__
/** NOTE: FramaC requires that we use its own compiler builtins (see -eva-builtins-list for more info) */
/* if not in the test suite case, aliasing to POSIX symbols, standard string.h header can be added */
size_t strnlen(const char *s, size_t maxlen) __attribute__((alias("sentry_strnlen")));
void* memset(void *s, int c, unsigned int n) __attribute__((alias("sentry_memset")));
void* memcpy(void * restrict d, const void * restrict s, size_t) __attribute__((alias("sentry_memcpy")));
#endif
#endif/*!TEST_MODE*/
