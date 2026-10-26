// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D200
// Canonical corpus name: StructZeroInitWithBaseCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInitWithBaseCall_0055d200.c

void UnknownObject::StructZeroInitWithBaseCall()
{
    // __thiscall constructor. Calls GlobalZeroInit_c2a0(this) to zero the base sub-object, then clears this[0] and this[5..12] (offsets 0x0 and 0x14..0x30) to zero. Returns this. No reads, no globals, no guards.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the base sub-object of the structure. [callee:0x0053C2A0]
    // ASSIGNMENT: Write 0 to *this (offset 0x0). [field:this:0x00000000, function:0x0055D200, source:raw]
    // ASSIGNMENT: Write 0 to this[8] (offset 0x20). [field:this:0x00000020]
    // ASSIGNMENT: Write 0 to this[7] (offset 0x1C). [field:this:0x0000001C]
    // ASSIGNMENT: Write 0 to this[6] (offset 0x18). [field:this:0x00000018]
    // ASSIGNMENT: Write 0 to this[5] (offset 0x14). [field:this:0x00000014]
    // ASSIGNMENT: Write 0 to this[12] (offset 0x30). [field:this:0x00000030]
    // ASSIGNMENT: Write 0 to this[11] (offset 0x2C). [field:this:0x0000002C]
    // ASSIGNMENT: Write 0 to this[10] (offset 0x28). [field:this:0x00000028]
    // ASSIGNMENT: Write 0 to this[9] (offset 0x24). [field:this:0x00000024]
    // RETURN: Return this (pointer to the constructed object). [function:0x0055D200]

    // Conservative worker pseudocode:
    //   _DWORD *StructZeroInitWithBaseCall(_DWORD *this) {
    //     GlobalZeroInit_c2a0(this);
    //     this[0] = 0;
    //     this[5] = this[6] = this[7] = this[8] = 0;
    //     this[9] = this[10] = this[11] = this[12] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Three callers (DrawableObjectNodeManager 0x005454D0, sub_5491D0 0x005491D0, VertexBufferTransform 0x0054C6C0) hint at a rendering/graph-node object, but the exact type is not established.
    // UNRESOLVED: Struct fields are zeroed only; no non-zero default values are set, so the purpose of individual fields is unknown.
}
