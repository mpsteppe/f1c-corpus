// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591727
// Canonical corpus name: sub_591727
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_591727_00591727.c

void UnknownObject::BuildFPUExceptionContextAndRaise()
{
    // Builds an FPU exception context record (exception-type bitfield, control-word and status-word derived flag words, two double operands with classification flags) from a decoded exception-code bitmask, FPU status/control information and the two double operands, calls RaiseException to signal the exception, then reads the context back to update the caller's output parameters (precision/rounding mode and status bits) and return the context base.
    // ASSIGNMENT: zero-initialize context fields: exception-type bitfield (+4), control-word flag word (+8), status-word flag word (+C) [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: decode dwExceptionCode bitmask: each of bits 0x10/0x2/0x1/0x4/0x8 selects a distinct Win32 FPU exception code and sets the corresponding bit in the exception-type bitfield (+4) [field:this:0x00000004, source:raw]
    // CALCULATION: encode rounding/precision/underflow flags derived from *a2 into the control-word flag word (+8) [field:this:0x00000008, source:raw]
    // CALL: call ShortComputation_1e49() and map its returned status/control bits into the status-word flag word (+C) [callee:0x00591E49, field:this:0x0000000C, source:raw]
    // CALCULATION: decode precision-control bits (*a2 & 0xC00: 0x0/1024/2048/3072) into context flag bits 0-1 [field:this:0x00000000, source:raw]
    // CALCULATION: decode rounding-control bits (*a2 & 0x300: 0x0/512/768) into context flag bits 3-5 [field:this:0x00000000, source:raw]
    // CALCULATION: write (a4 & 0xFFF) into context flag word bits 5-15 (exception/control mask) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: store first double operand *a5 into context +16 and set its classification flags at +32 [field:this:0x00000010, field:this:0x00000020, source:raw]
    // ASSIGNMENT: store second double operand *a6 into context +64 and set its classification flags at +80 [field:this:0x00000040, field:this:0x00000050, source:raw]
    // CALL: call FPUStatusWordRead() to read the current x87 status word (result not used directly; status is conveyed through the context) [callee:0x00591E57, source:raw]
    // CALL: call RaiseException(dwExceptionCode, 0, 1, &Arguments) to raise the FPU exception with the populated context record [global:0x0059E130, field:this:0x00000000, source:raw]
    // CALCULATION: after the raise returns, clear FPU exception bits in *a2 for flags set in the control-word flag word (+8) [field:this:0x00000008, source:raw]
    // CALCULATION: decode the precision encoding written in context flag word (+0) back into *a2 bits [field:this:0x00000000, source:raw]
    // CALCULATION: decode the rounding mode written in context flag word (+0) back into *a2 bits [field:this:0x00000000, source:raw]
    // ASSIGNMENT: copy the second-operand result from context +64 back into *a6 [field:this:0x00000040, source:raw]
    // RETURN: return the context base (Arguments) holding the exception-record-style structure [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   // zero context words; decode exception-code bitmask into context[0x4] and dwExceptionCode
    //   // encode *a2 control bits into context[0x8] and status bits into context[0xC]
    //   // store operand doubles + classification flags at context[0x10]/[0x20] and [0x40]/[0x50]
    //   // RaiseException(dwExceptionCode, 0, 1, &context); decode results back into *a2 and *a6
    // UNRESOLVED: Exact Win32 STATUS_* constant names for the five decoded FPU exception codes are not confirmed from packet evidence.
    // UNRESOLVED: The role of the discarded return value of FPUStatusWordRead() is unexplained.
}
