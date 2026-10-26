// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00458020
// Canonical corpus name: UtilityFunction_8020
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_8020_00458020.c

void UnknownObject::ReleaseBufferAndReset()
{
    // Releases a heap buffer whose allocation start is 4 bytes before the pointer stored at this+0x0, then clears the buffer record. Reads the pointer at this+0x0; if non-null it calls FreeWrapper_7bcf(pointer-4), zeros this+0x0, and returns FreeWrapper's result. If the stored pointer was null it skips the free and returns 0. Regardless of the free branch, the six remaining dwords this[1]..this[6] (offsets 0x4..0x18) are zeroed. The result is the FreeWrapper return when a buffer existed, otherwise the null pointer read at entry.
    // ASSIGNMENT: result = this[0] : read the stored buffer pointer from offset 0x0. [field:this:0x00000000, source:raw]
    // GUARD: if (this[0] != 0) : the buffer is released only when the stored pointer is non-null. [field:this:0x00000000, source:raw]
    // CALL: result = FreeWrapper_7bcf((void*)(this[0] - 4)) : the actual heap block starts 4 bytes before the stored pointer, so the allocation base is freed. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[0] = 0 : clear the stored buffer pointer after the free. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero this[1] through this[6] (offsets 0x4, 0x8, 0xC, 0x10, 0x14, 0x18) : the buffer record is reset unconditionally. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // RETURN: return result : returns FreeWrapper's result if a buffer was freed, otherwise the null pointer read at entry. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_458020(int *this) {
    //     int result = this[0];
    //     if (this[0]) {
    //       result = FreeWrapper_7bcf((LPVOID)(result - 4));
    //       this[0] = 0;
    //     }
    //     this[1] = this[2] = this[3] = 0;
    //     this[4] = this[5] = this[6] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The stored pointer at this+0x0 points 4 bytes past the block start passed to FreeWrapper_7bcf, implying an allocation header or tagged prefix whose layout is not part of this evidence.
    // UNRESOLVED: Owner object and the meaning of the seven cleared dwords (0x0..0x18) are unknown; caller context is sub_457F90 0x00457F90 and BufferAllocCopy 0x004582E0.
}
