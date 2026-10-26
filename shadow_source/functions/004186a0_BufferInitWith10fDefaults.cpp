// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004186A0
// Canonical corpus name: BufferInitWith10fDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferInitWith10fDefaults_004186a0.c

void UnknownObject::BufferInitWith10fDefaults()
{
    // Bulk initializer on a large object (this). Initializes a run of 20 fixed-size blocks via StructInitWithSentinelValues, fills a 0x219-DWORD (2148-byte) buffer at byte offset 2808 with the sentinel value -1082130432 (the IEEE-754 bit pattern of float -1.0f), writes scalar defaults at offsets 2788/2792/2796/4956, and returns 0. Called from many engine, session and UI initialization paths.
    // LOOP: do-while loop of 20 iterations. The block pointer starts at this + 537 (in _DWORD pointer units, i.e. byte offset 2148) and advances by 32 bytes per iteration. [source:raw]
    // CALL: Each iteration calls StructInitWithSentinelValues on the current block, initializing that block with sentinel values. [callee:0x004144D0, source:raw]
    // ASSIGNMENT: memset32(this + 2808, -1082130432, 0x219): fills 537 DWORDs (2148 bytes) at byte offset 2808 with the integer value -1082130432, which is the IEEE-754 bit pattern for -1.0f. [source:raw]
    // ASSIGNMENT: Write scalar defaults: *(BYTE*)(this + 2788) = 0, *(DWORD*)(this + 2792) = 0, *(DWORD*)(this + 2796) = -1. [source:raw]
    // ASSIGNMENT: Write *(DWORD*)(this + 4956) = 0, the DWORD immediately after the memset region. [source:raw]
    // RETURN: Return 0. [source:raw, function:0x004186A0]

    // Conservative worker pseudocode:
    //   int sub_4186A0(DWORD* this) {
    //     DWORD* p = this + 537;
    //     for (int i = 20; i != 0; --i) { StructInitWithSentinelValues(p); p = (DWORD*)((char*)p + 32); }
    //     memset32((void*)((char*)this + 2808), -1082130432, 0x219);
    //     *(DWORD*)((char*)this + 2792) = 0;
    //     *(BYTE*)((char*)this + 2788) = 0;
    //     *(DWORD*)((char*)this + 2796) = -1;
    //     *(DWORD*)((char*)this + 4956) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type and the meaning of the 20 initialized blocks are unknown; the 32-byte stride follows the decompiler's integer arithmetic but the exact block layout needs a caller.
    // UNRESOLVED: The legacy ABI name claims the buffer is filled with 1.0f, but the literal -1082130432 is the IEEE-754 bit pattern of float -1.0f, not 1.0f; the ABI label is treated as lower trust than the raw source.
    // UNRESOLVED: Semantic roles of the sentinel values (-1 at 2796, -1082130432 in the memset region) are unproven.
}
