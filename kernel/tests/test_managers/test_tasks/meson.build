# SPDX-FileCopyrightText: 2023 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

task_files = files([
    join_paths(meson.project_source_root(), 'kernel/src/managers/task/task_init.c'),
    join_paths(meson.project_source_root(), 'kernel/src/managers/task/task_idle.c'),
    join_paths(meson.project_source_root(), 'kernel/src/managers/task/task_core.c'),
])

if kconfig_data.get('CONFIG_BUILD_TARGET_AUTOTEST', 0) == 1
    task_files += task_autotest
endif

test_task = executable(
    'test_task',
    sources: [
        'test_task.cpp',
        task_files,
        managers_header_set_config.sources(),
        sentry_header_set_config.sources(),
    ],
    include_directories: kernel_inc,
    override_options: ['cpp_std=gnu++20'],
    cpp_args: [
        '-DTEST_MODE=1',
        '-DCONFIG_BUILD_TARGET_DEBUG=1',
        '-include', join_paths(fs.parent(kconfig_h),fs.name(kconfig_h)),
    ],
    c_args: [
        '-DTEST_MODE=1',
        '-DCONFIG_BUILD_TARGET_DEBUG=1',
        global_build_args,
        '-std=gnu11',
        '-include', join_paths(fs.parent(kconfig_h),fs.name(kconfig_h)),
    ],
    dependencies: [gtest_main],
    link_language: 'cpp',
    native: true,
)

test('task',
     test_task,
     env: nomalloc,
     suite: 'ut-managers')
