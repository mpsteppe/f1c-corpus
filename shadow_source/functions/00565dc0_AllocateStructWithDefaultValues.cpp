// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565DC0
// Canonical corpus name: AllocateStructWithDefaultValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AllocateStructWithDefaultValues_00565dc0.c

void UnknownObject::AllocateStructWithDefaultValues()
{
    // thiscall factory that allocates a 548-byte object via OperatorNewNhMallocWrapper, default-initializes its fields (zeroing several leading dwords/bytes, storing a -1 sentinel at offset 532), stores the resulting pointer into *this (or 0 on allocation failure), and returns this. Callers span resource cleanup, file enumeration, profile loading, and texture scanning, suggesting a per-resource state struct, but the struct identity is not established.
    // CALL: Call OperatorNewNhMallocWrapper with size 548; the returned pointer (v2) is the new object or null on allocation failure. [callee:0x00587C03, source:raw, abi:lead]
    // GUARD: Guard on v2: when non-null the new object is default-initialized; when null the out-pointer *this is cleared instead. [source:raw]
    // ASSIGNMENT: Zero the leading fields of the new object: dwords at offsets 0, 4, 8, 12 and the byte at offset 16. [source:raw]
    // ASSIGNMENT: Zero the dword at offset 528 and store -1 into the dword at offset 532 (sentinel/default value). [source:raw]
    // ASSIGNMENT: Zero the byte at offset 536 and the dwords at offsets 540 and 544; re-zero the byte at offset 16 (duplicate write preserved from the raw source). [source:raw]
    // ASSIGNMENT: Store v2 into *this on the success path, or 0 into *this on the allocation-failure path. [field:this:0x00000000, source:raw]
    // RETURN: Return this. [function:0x00565DC0]

    // Conservative worker pseudocode:
    //   void* v2 = OperatorNewNhMallocWrapper(548);
    //   if (v2) {
    //     *(dword*)(v2 + 0) = 0;
    //     *(dword*)(v2 + 4) = 0;
    //     *(dword*)(v2 + 8) = 0;
    //     *(dword*)(v2 + 12) = 0;
    //     *(byte*)(v2 + 16) = 0;
    //     *(dword*)(v2 + 528) = 0;
    //     *(dword*)(v2 + 532) = -1;
    //     *(byte*)(v2 + 536) = 0;
    //     *(dword*)(v2 + 540) = 0;
    //     *(dword*)(v2 + 544) = 0;
    //     *this = v2;
    //   } else {
    //     *this = 0;
    //   }
    //   return this;
    // UNRESOLVED: Exact struct identity and class owner of the 548-byte object are not identified; callers span resource cleanup, file enumeration, profile loading, and texture scanning.
    // UNRESOLVED: Semantics of the zero-initialized fields (offsets 0, 4, 8, 12, 16, 528, 536, 540, 544) and the -1 sentinel at offset 532 are unknown without a live struct probe.
    // UNRESOLVED: The duplicate byte-zero write at offset 16 is preserved from the raw source and may indicate separate boolean fields sharing the byte.
}
