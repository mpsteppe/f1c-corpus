// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00429FC2
// Canonical corpus name: Corrupt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Corrupt_00429fc2.c

void UnknownObject::DeadCodeGlobalByteIncrement()
{
    // Corrupt/dead-code stub flagged by the decompiler ('positive sp value has been detected, the output may be wrong!'; LEGACY ABI Corrupt_Dead_Code_PARTIAL). It adds the byte argument a1 (passed in AL) to the byte at 0xCE8B0875, then tail-jumps to 0x42A206 instead of returning. Likely misdecoded data or a fragment, not a real control-flow function.
    // ASSIGNMENT: Receive the byte argument a1 in the AL register (__usercall convention). [source:raw]
    // ASSIGNMENT: Add a1 to the byte stored at 0xCE8B0875 (MEMORY[0xCE8B0875] += a1). [global:0xCE8B0875, source:raw]
    // UNKNOWN: Tail-jump (JUMPOUT) to 0x42A206 instead of returning; decompiler marks the function corrupt (positive sp detected). [source:raw]

    // Conservative worker pseudocode:
    //   MEMORY[0xCE8B0875] += a1;
    //   JUMPOUT(0x42A206); /* decompiler-corrupted tail jump, does not return * /
    // UNRESOLVED: The function is decompiler-corrupt: the positive-sp warning makes the entire body unreliable.
    // UNRESOLVED: The write target 0xCE8B0875 is not a normal game image address and the jump target 0x42A206 is not recorded as a callee; this is likely misdecoded data rather than a live function.
    // UNRESOLVED: The purpose of the byte at 0xCE8B0875 (incremented by a1) is unknown.
}
