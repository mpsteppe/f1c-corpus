// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A29A0
// Canonical corpus name: ArrayResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayResourceCleanup_004a29a0.c

void UnknownObject::ArrayResourceCleanup()
{
    // Cleanup for a struct managing an array of 120-byte elements plus an optional 3D sound source. Zeroes three header DWORDs (this[0..2]), zeroes a per-element field at +100 for every counted element, then nulls the count. When the array pointer is non-null it runs a backward 120-byte walk calling sub_4A2220 as a per-element destructor, frees the allocation block via FreeWrapper_7bcf, and nulls the array pointer. Finally, if global dword_8AFE88 is non-zero and the sound-source pointer is non-null, destroys it via F_3DSoundSourceDestructor and nulls the pointer.
    // ASSIGNMENT: Read element count from this[0xC] into local v2. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero header DWORDs this[0x0], this[0x4] and this[0x8]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Guard: element count read from this[0xC] must be > 0 before the forward zeroing loop runs. [field:this:0x0000000C, source:raw]
    // LOOP: Forward do-while loop over the counted elements: for each of the this[0xC] elements (120-byte stride from this[0x10]) zero the DWORD at element offset +100. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set element count this[0xC] = 0 after the zeroing loop. [field:this:0x0000000C, source:raw]
    // GUARD: Guard: array pointer this[0x10] non-null before running element destructors and freeing. [field:this:0x00000010, source:raw]
    // LOOP: Backward do-while walk of the array (120-byte stride) calling sub_4A2220 as the per-element destructor; element count for the walk is read from the allocation header DWORD at array-4. [callee:0x004A2220, field:this:0x00000010, source:raw]
    // CALL: Free the array allocation block via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set array pointer this[0x10] = 0 after freeing. [field:this:0x00000010, source:raw]
    // GUARD: Guard: global dword_8AFE88 non-zero gates the sound-source destruction block. [global:0x008AFE88, source:raw]
    // GUARD: Guard: sound-source pointer this[0x14] non-null before destructing. [field:this:0x00000014, source:raw]
    // CALL: Destroy the 3D sound source via F_3DSoundSourceDestructor. [callee:0x00545150, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set sound-source pointer this[0x14] = 0. [field:this:0x00000014, source:raw]
    // RETURN: Return the last stored result value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A29A0(int *this) {
    //     int count = this[3];
    //     int result;
    //     this[0] = 0; this[1] = 0; this[2] = 0;
    //     if (count > 0)
    //       for (int i = 0, off = 0; i < count; ++i, off += 120)
    //         *(DWORD*)(this[4] + off + 100) = 0;
    //     result = this[4];
    //     this[3] = 0;
    //     if (result) {
    //       int n = *(DWORD*)(result - 4);
    //       void* block = (void*)(result - 4);
    //       char* p = (char*)(result + 120 * n);
    //       for (int i = n - 1; i >= 0; --i) {
    //         p -= 120;
    //         sub_4A2220(p);
    //       }
    //       result = FreeWrapper_7bcf(block);
    //     }
    //     this[4] = 0;
    //     if (dword_8AFE88) {
    //       result = this[5];
    //       if (result) result = F_3DSoundSourceDestructor(this[5]);
    //     }
    //     this[5] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Identity and layout of the 120-byte element struct are not covered by packet fields; the +100 DWORD zeroed per element has unknown meaning.
    // UNRESOLVED: The allocation header DWORD at array-4 (used as the backward-walk element count) is read in the raw source but has no packet field entry.
    // UNRESOLVED: The global dword_8AFE88 gating sound-source destruction is semantically unrelated to the array cleanup; its role is unknown.
}
