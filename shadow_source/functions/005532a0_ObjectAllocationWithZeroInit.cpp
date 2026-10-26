// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005532A0
// Canonical corpus name: ObjectAllocationWithZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectAllocationWithZeroInit_005532a0.c

void UnknownObject::ObjectAllocationWithZeroInit()
{
    // Constructor/initializer: calls GlobalZeroInit_c2a0, sets this+0x0 to 2 and zeroes this+0x4 through this+0x10, then allocates a 36-byte block via OperatorNewNhMallocWrapper(36). On success the block is zero-filled and stored at this+0x14; on failure this+0x14 is zero. The this+0x18/0x1C/0x20 dwords are zeroed in both branches. Returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to run the shared zero-initialization helper. [callee:0x0053C2A0]
    // ASSIGNMENT: Set the dword at this+0x0 to 2 (a type or version marker). [field:this:0x00000000]
    // ASSIGNMENT: Set the dword at this+0x4 to 0. [field:this:0x00000004]
    // ASSIGNMENT: Set the dword at this+0x8 to 0. [field:this:0x00000008]
    // ASSIGNMENT: Set the dword at this+0xC to 0. [field:this:0x0000000C]
    // ASSIGNMENT: Set the dword at this+0x10 to 0. [field:this:0x00000010]
    // CALL: Allocate a 36-byte block via OperatorNewNhMallocWrapper(36); result kept in a local pointer v2. [callee:0x00587C03, source:raw]
    // GUARD: Branch on v2 != null: allocation success path versus failure path. [source:raw]
    // ASSIGNMENT: On success, zero-fill the 36-byte allocation (nine dwords v2[0] through v2[8]). [source:raw]
    // ASSIGNMENT: On success, store the allocation at this+0x14 (this[5] = v2). [field:this:0x00000014]
    // ASSIGNMENT: On success, zero the dwords at this+0x18, this+0x1C and this+0x20. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // ASSIGNMENT: On allocation failure, set this+0x14 to 0. [field:this:0x00000014]
    // ASSIGNMENT: On allocation failure, zero the dwords at this+0x18, this+0x1C and this+0x20. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // RETURN: Return this as the initialized object. [function:0x005532A0, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_5532A0(void* this) {
    //     GlobalZeroInit_c2a0(this);
    //     *(unsigned*)this = 2;
    //     *(unsigned*)((char*)this + 4) = 0;
    //     *(unsigned*)((char*)this + 8) = 0;
    //     *(unsigned*)((char*)this + 0xC) = 0;
    //     *(unsigned*)((char*)this + 0x10) = 0;
    //     unsigned* v2 = OperatorNewNhMallocWrapper(36);
    //     if (v2) {
    //       for (int i = 0; i < 9; i++) v2[i] = 0;
    //       *(unsigned*)((char*)this + 0x18) = 0;
    //       *(unsigned*)((char*)this + 0x1C) = 0;
    //       *(unsigned*)((char*)this + 0x20) = 0;
    //       *(unsigned*)((char*)this + 0x14) = (unsigned)v2;
    //     } else {
    //       *(unsigned*)((char*)this + 0x18) = 0;
    //       *(unsigned*)((char*)this + 0x1C) = 0;
    //       *(unsigned*)((char*)this + 0x20) = 0;
    //       *(unsigned*)((char*)this + 0x14) = 0;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: Role of the marker value 2 at this+0x0 and the purpose of the 36-byte allocated block stored at this+0x14 depend on the owning object's layout, which is unknown.
    // UNRESOLVED: The zero-filled allocation has no reads or further references within this function; its field meaning is unresolved here.
}
