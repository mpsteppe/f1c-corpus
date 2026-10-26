// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567B00
// Canonical corpus name: sub_567B00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_567B00_00567b00.c

void UnknownObject::FileDataProcessorThunk()
{
    // __stdcall thunk: forwards its two arguments a1 and a2 unchanged to sub_567AF0 and returns that call's result. The only caller recorded in the packet is FileDataProcessor (0x00567FB0), so the thunk sits on a file-data processing path, but the forwarded call's purpose is not established because sub_567AF0 is absent from the packet callee evidence.
    // CALL: Forward both arguments a1 and a2 to sub_567AF0 (named only in the raw source text; no callee address evidence in the packet). [function:0x00567B00, source:raw]
    // RETURN: Return the result produced by sub_567AF0. [function:0x00567B00, source:raw]
    // CALL: Called by FileDataProcessor (0x00567FB0), placing this thunk on a file-data processing call path. [caller:0x00567FB0, source:raw]

    // Conservative worker pseudocode:
    //   int FileDataProcessorThunk(int a1, int a2) {
    //     return sub_567AF0(a1, a2);
    //   }
    // UNRESOLVED: sub_567AF0 is named only in the raw source text; it is absent from the packet callee evidence, so its address and semantic contract are unverified.
    // UNRESOLVED: The purpose of the forwarded call (validation, dispatch, transform) cannot be determined from this packet alone.
}
