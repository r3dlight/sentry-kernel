# SPDX-FileCopyrightText: 2023-2024 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

add_languages('cpp', native: true, required: true)

hostcc = meson.get_compiler('c', native: true)
hostcc.has_function('__builtin_ffsl')

# no need to perturb malloc as we do not have malloc in kernel
nomalloc = environment({'MALLOC_PERTURB_': '0'})

gtest_main = dependency('gmock_main', version: '>=1.13.0',
                         fallback : ['gtest', 'gmock_main_dep'],
                         native: true)

subdir('test_utils')
subdir('test_bsp')
subdir('test_managers')

if get_option('b_coverage')
# INFO: when building libsentry with cross-toolchain and test with native one,
# gcov fails when reading gcno content of libsentry as this is two distinct toolchains
# to avoid that, we use a dedicated custom target that reduce the search path of gcdo/na to tests
# subdir only, to let gcov read only file that has been produce by the very same native
# toolchain
gcovr = find_program('gcovr')

cover_sonar = custom_target(
    'sonar_coverage',
    command: [
        gcovr,
        '-r', meson.project_source_root(),
        join_paths(meson.project_build_root(), 'kernel/tests'),
        '-e', join_paths(meson.project_source_root(), 'subprojects'),
        '--sonarqube',
        '-o', 'sonarqube.xml',
    ],
    output: 'sonarqube.xml',
)
sonar = alias_target('sonar', cover_sonar)

endif
