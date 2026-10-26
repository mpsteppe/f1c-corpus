// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005647D0
// Canonical corpus name: CallbackCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackCheck_005647d0.c

void UnknownObject::CallbackCheck()
{
    // Callback-driven lookup helper. Invokes the caller-supplied callback stored at a1+12 with a2 and the dword at a1+4, uses the integer result v3 as an index into a dword table referenced at a1[0], computes a buffer index with BufferIndexComputation(*(a1+16), 0, 0), and returns the LinearInterpolation of the selected table entry and that buffer index. Returns 0 when the buffer index computation fails (-1).
    // CALL: Invoke the callback stored at a1+12 (fastcall) with arguments a2 and the dword at a1+4; capture the integer result as v3. [source:raw, function:0x005647D0]
    // CALL: Compute the buffer index: v4 = BufferIndexComputation(*(a1+16), 0, 0). [callee:0x00564A20, source:raw]
    // GUARD: Guard on v4 == -1: when the buffer index computation fails, return 0. [source:raw]
    // CALCULATION: Select the table entry at *(a1) + 4*v3, using the callback result v3 as a dword index. [source:raw]
    // RETURN: Return LinearInterpolation(selected table entry, v4). [source:raw]

    // Conservative worker pseudocode:
    //   int CallbackCheck(int a1, int a2) {
    //     int v3 = (*(int (__fastcall **)(int, int))(a1 + 12))(a2, *(int*)(a1 + 4));
    //     int v4 = BufferIndexComputation(*(int*)(a1 + 16), 0, 0);
    //     if (v4 == -1) return 0;
    //     return LinearInterpolation(*(int*)(*(int*)a1 + 4 * v3), v4);
    //   }
    // UNRESOLVED: Layout and meaning of a1: callback pointer at +12, argument dword at +4, buffer-index source at +16, and the dword table at a1[0] are caller-specific; no packet field evidence names them.
    // UNRESOLVED: Meaning and allowed range of the callback's integer result v3 when indexing the table.
    // UNRESOLVED: Semantics of BufferIndexComputation's extra zero arguments and of LinearInterpolation are defined in their own functions.
    // UNRESOLVED: Why the buffer-index failure (-1) maps to a 0 return value.
}
