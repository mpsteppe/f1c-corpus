// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DFB60
// Canonical corpus name: InitWithDualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithDualCall_004dfb60.c

void UnknownObject::InitWithDualCall()
{
    // Initializer: bulk zero-init via LargeZeroInit, then zero three dword fields (decompiler indices 67, 68, 72 on an aliased base), then run the 17-element zero-init helper F_17ElementZeroInitLoop twice at two different bases (v1+28 and v2+180), returning the last helper's result. Callers: sub_4DFBB0 and VehicleResetClear.
    // CALL: LargeZeroInit(this) performs bulk zero-initialization of the object [callee:0x004DFB00]
    // ASSIGNMENT: zero dword index 72 of a base object (decompiler alias v1) [source:raw]
    // ASSIGNMENT: zero dword index 67 of a base object (decompiler alias v1) [source:raw]
    // ASSIGNMENT: zero dword index 68 of a base object (decompiler alias v1) [source:raw]
    // CALL: F_17ElementZeroInitLoop(v1 + 28) zeroes a 17-element block at the first base [callee:0x004DFA50]
    // CALL: F_17ElementZeroInitLoop(v2 + 180) zeroes a 17-element block at the second base [callee:0x004DFA50]
    // RETURN: returns the int result of the final 17-element zero-init call [abi:lead]

    // Conservative worker pseudocode:
    //   LargeZeroInit(this);
    //   baseA[72] = 0;
    //   baseA[67] = 0;
    //   baseA[68] = 0;
    //   F_17ElementZeroInitLoop(baseA + 28);
    //   return F_17ElementZeroInitLoop(baseB + 180);
    // UNRESOLVED: decompiler leaves v1 and v2 (edx) uninitialized, so the exact target structs for the three zero-writes and the two 17-element loops are not determinable from this packet
    // UNRESOLVED: interpretation of indices 67/68/72 as object fields requires external field evidence
}
