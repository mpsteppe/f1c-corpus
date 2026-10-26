// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD450
// Canonical corpus name: FloatVectorInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatVectorInit_004dd450.c

void UnknownObject::FloatVectorInit()
{
    // Thin __thiscall initializer writing a 20-byte block: this[0] is set to 1065353216 (1.0f) and this[1] through this[4] (offsets 0x4, 0x8, 0xC, 0x10) are zeroed. Returns the this pointer unchanged. Only known static caller is sub_4E3360.
    // ASSIGNMENT: Write 1065353216 (1.0f) into this[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero this+0x4 (this[1]). [field:this:0x00000004]
    // ASSIGNMENT: Zero this+0x8 (this[2]). [field:this:0x00000008]
    // ASSIGNMENT: Zero this+0xC (this[3]). [field:this:0x0000000C]
    // ASSIGNMENT: Zero this+0x10 (this[4]). [field:this:0x00000010]
    // RETURN: Return the this pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *FloatVectorInit(_DWORD *this) {
    //       this[0] = 1065353216; // 1.0f
    //       this[1] = 0;
    //       this[2] = 0;
    //       this[3] = 0;
    //       this[4] = 0;
    //       return this;
    //   }
    // UNRESOLVED: The concrete owner type of the 20-byte block is unknown; the float-vector reading (1.0f followed by zeroed components) is DERIVED from the literal pattern, not confirmed by an owner.
    // UNRESOLVED: Purpose and object type of the only known static caller sub_4E3360 (0x004E3360) are unknown.
}
