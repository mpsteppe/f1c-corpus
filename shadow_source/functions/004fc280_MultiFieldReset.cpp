// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC280
// Canonical corpus name: MultiFieldReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldReset_004fc280.c

void UnknownObject::MultiFieldReset()
{
    // Resets a multi-field owner object at `this`: writes the sentinel -1 at +0x44, zeroes the header dword at +0x0, clears a three-dword block starting at byte offset 16 (16, 20, 24), conditionally frees the pointer stored at +0x4C via FreeWrapper_7bcf, zeroes the +0x48 and +0x4C dwords and the byte at +0x50, zeroes the dword at +0x70, conditionally frees the pointer captured from +0x80, and zeroes +0x7C, +0x80, the byte at +0x84, and the dword at +0xA4. Returns the captured +0x80 pointer (replaced by FreeWrapper_7bcf's return value when freed). Called by StructInitWithFloatDefaults (0x004FC9C0) and TwoCallDelegation_d6d0 (0x004FD6D0).
    // ASSIGNMENT: Write -1 (sentinel/invalid marker) to the dword at this+0x44. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Clear the header dword at this+0x0 to 0. [field:this:0x00000000, source:raw]
    // LOOP: Clear the three-dword block starting at byte offset 16 (offsets 16, 20, 24) using a 3-iteration countdown. [field:this:0x00000010, source:raw]
    // GUARD: Guard on the pointer at this+0x4C being non-zero before freeing it. [field:this:0x0000004C, source:raw]
    // CALL: Free the heap buffer pointed to by this+0x4C via FreeWrapper_7bcf (0x00587BCF). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the dword at this+0x48 to 0. [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Clear the dword at this+0x4C to 0. [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Clear the byte at this+0x50 to 0. [field:this:0x00000050, source:raw]
    // ASSIGNMENT: Clear the dword at this+0x70 to 0. [field:this:0x00000070, source:raw]
    // GUARD: Capture the pointer at this+0x80 as the result; guard on it being non-zero before freeing it. [field:this:0x00000080, source:raw]
    // CALL: Free the captured this+0x80 pointer via FreeWrapper_7bcf (0x00587BCF) and store its return value as result. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the dword at this+0x7C to 0. [field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Clear the dword at this+0x80 to 0. [field:this:0x00000080, source:raw]
    // ASSIGNMENT: Clear the byte at this+0x84 to 0. [field:this:0x00000084, source:raw]
    // ASSIGNMENT: Clear the dword at this+0xA4 to 0. [field:this:0x000000A4, source:raw]
    // RETURN: Return the result pointer (captured +0x80 value, or FreeWrapper_7bcf's return value after the second free). [source:raw]

    // Conservative worker pseudocode:
    //   void* MultiFieldReset(this) {
    //     *(dword*)(this + 0x44) = -1;
    //     *(dword*)this = 0;
    //     p = (dword*)(this + 0x10); n = 3;
    //     do { *p = 0; p += 4; --n; } while (n);
    //     if (*(dword*)(this + 0x4C)) FreeWrapper_7bcf(*(void**)(this + 0x4C));
    //     result = *(void**)(this + 0x80);
    //     *(dword*)(this + 0x48) = 0; *(dword*)(this + 0x4C) = 0;
    //     this[0x50] = 0; *(dword*)(this + 0x70) = 0;
    //     if (result) result = FreeWrapper_7bcf(result);
    //     *(dword*)(this + 0x7C) = 0; *(dword*)(this + 0x80) = 0;
    //     this[0x84] = 0; *(dword*)(this + 0xA4) = 0;
    //     return result;
    //   }
    // UNRESOLVED: The object type and the meaning of the -1 sentinel at +0x44 are unknown; the owner is UnknownObject.
    // UNRESOLVED: The conditionally-freed pointers at +0x4C and +0x80 are presumed to be owned heap buffers managed by FreeWrapper_7bcf; the allocator semantics of FreeWrapper_7bcf are not examined here.
    // UNRESOLVED: The three-dword block cleared by the loop (byte offsets 16..24) overlaps fields not listed in the packet field table; only +0x10 is represented by a field evidence reference.
}
