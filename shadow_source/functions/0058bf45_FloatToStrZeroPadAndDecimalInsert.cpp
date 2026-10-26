// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BF45
// Canonical corpus name: UtilityFunction_bf45
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_bf45_0058bf45.c

void UnknownObject::FloatToStrZeroPadAndDecimalInsert()
{
    // Formats a numeric value into the output buffer a1: writes a leading '-' (45) when the sign flag *a3 equals 45, shifts the buffer to make room, writes the locale decimal separator byte_5E6BD8, and pads with '0' characters for negative exponent spans. Handles a zero-value special case by writing '0' plus a NUL terminator. Returns the buffer start pointer.
    // GUARD: Zero special case: when flag a4 is set and a3[1]-1 equals a2, write character '0' (48) followed by a NUL terminator at the computed buffer position. [field:this:0x00000001, source:raw]
    // GUARD: Negative sign: when the sign flag *a3 equals 45, write '-' at the buffer start and advance the write cursor by one. [field:this:0x00000000, source:raw]
    // GUARD: Branch on the digit count a3[1]: if positive use it as the digit span; otherwise shift the buffer right by one, write '0', and advance the cursor. [field:this:0x00000002, source:raw]
    // CALL: StringShiftByOffset moves existing buffer content right to make room for the sign or digit characters. [callee:0x0058C0D0]
    // GUARD: When a2 is positive, shift the buffer again and write the locale decimal separator byte_5E6BD8 at the current position. [global:0x005E6BD8, source:raw]
    // CALCULATION: For a negative digit count a3[1], compute the magnitude a2 = -a3[1] as the zero-pad span. [source:raw]
    // CALL: sub_58BB10 fills the buffer region with '0' (0x30) padding over the requested span. [callee:0x0058BB10]
    // RETURN: Return the buffer start pointer a1. [source:raw, caller:0x0058BEF0, caller:0x0058BFEC, function:0x0058BF45]

    // Conservative worker pseudocode:
    //   char* FloatToStrZeroPadAndDecimalInsert(char* buf, int span, int* fmt, int flag) {
    //     if (flag && fmt[1] - 1 == span) {
    //       char* p = &buf[fmt[1] - 1 + (fmt[0] == 45)];
    //       *p = 48; p[1] = 0;
    //     }
    //     char* cur = buf;
    //     if (fmt[0] == 45) { *buf = 45; cur = buf + 1; }
    //     char* dig;
    //     if (fmt[1] > 0) { dig = &cur[fmt[1]]; }
    //     else { StringShiftByOffset(cur, 1); *cur = 48; dig = cur + 1; }
    //     if (span > 0) {
    //       StringShiftByOffset(dig, 1); *dig = byte_5E6BD8;
    //       int n = fmt[1]; char* tail = dig + 1;
    //       if (n < 0) { span = -n; StringShiftByOffset(tail, span); sub_58BB10(tail, 0x30, span); }
    //     }
    //     return buf;
    //   }
    // UNRESOLVED: Exact meaning of a3 (sign flag plus count pair) depends on the calling format helpers and is not fully pinned down here.
    // UNRESOLVED: byte_5E6BD8 is treated as the locale decimal separator per prior analysis; the value is only read, never validated here.
}
