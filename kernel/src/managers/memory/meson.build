# SPDX-FileCopyrightText: 2023 Ledger SAS
# SPDX-License-Identifier: Apache-2.0


shm_template_h = files(['memory_shm-dt.h.in'])
shm_dtsgen_h = dtsgen.process(shm_template_h)

shm_template_c = files(['memory_shm-dt.c.in'])
shm_dtsgen_c = dtsgen.process(shm_template_c)

managers_private_gen_header_set.add(shm_dtsgen_h)
# TODO: create manager_private_gen_source_set
managers_private_gen_header_set.add(shm_dtsgen_c)

managers_source_set.add(files('memory_shm.c'))
managers_source_set.add(files('memory_mpu.c'))
