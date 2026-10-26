// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565760
// Canonical corpus name: sub_565760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565760_00565760.c

void UnknownObject::SerializeTupleToBuffer()
{
    // Formats a variable-length numeric tuple into a buffer and verifies the write. First validates via sub_565400(this, a2); on failure returns 0. Then selects a format string by which of a4/a5/a6 are non-zero: four values "(%d,%d,%d,%d)", three "(%d,%d,%d)", two "(%d,%d)", one "(%d)", and bare "%d" as a last resort when the parenthesized one-value form fails. Returns TRUE when the formatted string length equals the number of formatted arguments. Used by config, career and vehicle-file loaders as a shared tuple writer.
    // CALL: Call sub_565400(this, a2) as a precondition for the whole function. [callee:0x00565400, source:raw]
    // GUARD: Guard on the sub_565400 result: if it returns 0, abort immediately with result 0. [callee:0x00565400, source:raw]
    // ASSIGNMENT: Read the destination buffer pointer from this+0x180 (first argument of every format call). [field:this:0x00000180, source:raw]
    // CALL: When a6 is non-zero, format "(%d,%d,%d,%d)" with a3,a4,a5,a6 into the buffer via StrlenFormatCallWrapper and return (length == 4). [callee:0x005887ED, global:0x005E5090, source:raw]
    // CALL: When a6 is zero but a5 is non-zero, format "(%d,%d,%d)" with a3,a4,a5 into the buffer and return (length == 3). [callee:0x005887ED, global:0x005E5084, source:raw]
    // CALL: When a6 and a5 are zero but a4 is non-zero, format "(%d,%d)" with a3,a4 into the buffer and return (length == 2). [callee:0x005887ED, global:0x005E507C, source:raw]
    // GUARD: Guard on a3: if a3 is zero, return 0 (nothing to serialize). [source:raw]
    // CALL: Single value path: format "(%d)" with a3 into the buffer; return TRUE when the formatted length == 1. [callee:0x005887ED, global:0x005E5074, source:raw]
    // CALL: Fallback single value path: when the parenthesized one-value form did not yield length 1, format "%d" with a3 and return (length == 1). [callee:0x005887ED, global:0x005C3280, source:raw]
    // RETURN: Return the result of the selected comparison (TRUE when the formatted length matches the argument count, otherwise FALSE). [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_565760(int this, int a2, int a3, int a4, int a5, int a6) {
    //     if (!sub_565400(this, a2)) return 0;
    //     char* dst = *(char**)(this + 0x180);
    //     if (a6) return StrlenFormatCallWrapper(dst, "(%d,%d,%d,%d)", a3,a4,a5,a6) == 4;
    //     if (a5) return StrlenFormatCallWrapper(dst, "(%d,%d,%d)",   a3,a4,a5)   == 3;
    //     if (a4) return StrlenFormatCallWrapper(dst, "(%d,%d)",     a3,a4)     == 2;
    //     if (!a3) return 0;
    //     if (StrlenFormatCallWrapper(dst, "(%d)", a3) == 1) return 1;
    //     return StrlenFormatCallWrapper(dst, "%d", a3) == 1;
    //   }
    // UNRESOLVED: Purpose and result semantics of the sub_565400 precondition call and of argument a2 are unknown.
    // UNRESOLVED: The mapping of the five format-literal globals (0x005C3280 aD_1, 0x005E5074 aD_0, 0x005E507C aDD_0, 0x005E5084 aDDD_1, 0x005E5090 aDDDD_0) to specific format strings is DERIVED from the global name pattern, not locked by the packet.
    // UNRESOLVED: Why the function compares the formatted string length to the number of arguments rather than to the tuple contents is unresolved.
    // UNRESOLVED: Field this+0x180 is the format output buffer pointer (DERIVED from it being the first argument of every StrlenFormatCallWrapper call).
}
