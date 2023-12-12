use crate::gate::syscall_dispatch;
use core::arch::asm;
use managers_bindings::stack_frame_t;
use systypes::Status;

#[no_mangle]
/// # Safety
/// This function is always unsafe because it has to dereference
/// raw pointers coming from C/ASM. Caller should make sure the
/// input stack_frame is valid according to the StackFrame struct
/// above
pub unsafe fn svc_handler_rs(stack_frame: *mut stack_frame_t) -> *mut stack_frame_t {
    let syscall_num = *((*stack_frame).pc as *const u8).offset(-2);
    let args = [
        (*stack_frame).r0,
        (*stack_frame).r1,
        (*stack_frame).r2,
        (*stack_frame).r3,
    ];
    match syscall_dispatch(syscall_num, &args) {
        Ok(None) => {
            (*stack_frame).r0 = Status::Ok as u32;
            stack_frame
        }
        Ok(Some(ret_stack_frame)) => {
            (*ret_stack_frame).r0 = Status::Ok as u32;
            ret_stack_frame
        }
        Err(err) => {
            (*stack_frame).r0 = err as u32;
            stack_frame
        }
    }
}

pub fn __wfe() {
    unsafe {
        asm!("wfe");
    }
}

pub fn __wfi() {
    unsafe {
        asm!("wfi");
    }
}

// /// SVC interrupt handler for ARMv7 cores
// /// Currently unused
// #[no_mangle]
// #[naked]
// extern "C" fn SVC_Handler() {
//     unsafe {
//         asm!(
//             "tst   lr, #4",
//             "ite   eq",
//             "mrseq r0, msp",
//             "mrsne r0, psp",
//             "b     svc_handler_rs",
//             "b     =0xfffffffd",
//             options(noreturn)
//         );
//     }
// }
