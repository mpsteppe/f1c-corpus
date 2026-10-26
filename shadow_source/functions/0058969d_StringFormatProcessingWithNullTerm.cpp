// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058969D
// Canonical corpus name: StringFormatProcessingWithNullTerm
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatProcessingWithNullTerm_0058969d.c

void UnknownObject::StringFormatProcessingWithNullTerm()
{
    // Variadic string formatting wrapper that formats into the output buffer a1 using format string a3 and the argument list, advancing a cursor, then guarantees the result is null-terminated. The capacity argument a2 is decremented after formatting; if it underflows the buffer is considered exhausted and the error path sub_58CF35 is taken, otherwise the formatted text is null-terminated in place. Returns the value returned by the underlying formatter sub_58D04D.
    // ASSIGNMENT: Seed the formatting state: cursor v7 and v9 point at the output buffer a1, remaining v8 holds the capacity a2, and the local v10 is assigned the constant 66. [source:raw]
    // CALL: Call sub_58D04D(&v7, a3, va) to format the variadic arguments into the buffer, advancing the cursor; its return value is kept as the function result. [callee:0x0058D04D]
    // CALCULATION: Decrement the remaining capacity v8 and test the signed underflow condition (--v8 < 0). [source:raw]
    // GUARD: When the remaining capacity underflows, take the error/exhaustion path instead of null-terminating in place. [source:raw, abi:lead]
    // CALL: Call sub_58CF35(0, &v7) on the exhausted-buffer path to handle the overlong result. [callee:0x0058CF35]
    // ASSIGNMENT: On the success path, write a null terminator at the formatted end of the buffer: *v7 = 0. [source:raw, field:this:0x00000000]
    // RETURN: Return the result produced by sub_58D04D on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58969D(_BYTE *output, int capacity, const char *fmt, ...) {
    //     va_list va;
    //     va_start(va, fmt);
    //     _BYTE *cursor = output;
    //     int remaining = capacity;
    //     int result = sub_58D04D(&cursor, fmt, va);
    //     if (--remaining < 0)
    //       sub_58CF35(0, &cursor);
    //     else
    //       *cursor = 0;
    //     return result;
    //   }
    // UNRESOLVED: The local v10 is assigned 66 but never read in the decompiled body; its purpose (likely a discarded enum or flag) is unknown.
    // UNRESOLVED: Exact contract of sub_58CF35 on the exhausted path (abort, truncation, or error reporting) is unproven.
    // UNRESOLVED: Whether the value returned by sub_58D04D is a byte count, character count, or success flag is unknown.
}
