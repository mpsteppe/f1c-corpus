// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B46B0
// Canonical corpus name: StructZeroInit_46b0
// Owner: PooledBuffer [DERIVED]
// Raw source: functions/StructZeroInit_46b0_004b46b0.c

void PooledBuffer::StructZeroInit()
{
    // Struct zero-initializer: zeroes 0x34 bytes from byte offset 0x01, then 0x34 contiguous bytes from byte offset 0x35, zeroes the dword at 0x6C, and zeroes four consecutive dwords per iteration over a 4-iteration loop starting at byte offset 0x70. Returns this. No reads, no globals, no calls; called by BufferPoolAllocatorInitialization.
    // ASSIGNMENT: Zero 0x34 bytes starting at byte offset 0x01 via memset((char*)this + 1, 0, 0x34). [source:raw]
    // ASSIGNMENT: Zero 0x34 bytes starting at byte offset 0x35 via memset((char*)this + 53, 0, 0x34), contiguous with the first zeroed block. [source:raw]
    // LOOP: do-while loop of 4 iterations; each iteration writes four consecutive zero dwords starting at byte offset 0x70, then advances the write pointer by four dwords. The listed fields at 0x70, 0x74, 0x78 and 0x7C are the first iteration's writes. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C]
    // ASSIGNMENT: Zero the dword at this+0x6C (this[27]). [field:this:0x0000006C]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* StructZeroInit(DWORD* this) {
    //     memset((char*)this + 1, 0, 0x34);
    //     memset((char*)this + 53, 0, 0x34);
    //     DWORD* p = this + 28;
    //     int n = 4;
    //     do { p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; p += 4; --n; } while (n);
    //     this[27] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The object type and the purpose of the zeroed region (pooled buffer header and slot table?) are unknown; the PooledBuffer owner is DERIVED only from the caller BufferPoolAllocatorInitialization.
    // UNRESOLVED: Why the memset blocks begin at byte offsets 0x01 and 0x35 rather than the struct base is unresolved.
    // UNRESOLVED: Relationship between the 0x6C dword and the dword block at 0x70 is unknown.
}
