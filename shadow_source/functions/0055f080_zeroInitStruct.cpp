// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055F080
// Canonical corpus name: StructZeroInitConstructor_f080
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInitConstructor_f080_0055f080.c

void UnknownObject::zeroInitStruct()
{
    // Constructor-style initializer for an unknown object: calls GlobalZeroInit_c2a0(this) to bulk-zero the base structure, then explicitly zeroes 15 fields (leading DWORD at +0x0; BYTEs at +0x4, +0x2C, +0x54; DWORDs at +0x24, +0x28, +0x4C, +0x50, +0x74, +0x78, +0x7C, +0x80, +0x94, +0x98, +0x9C). No reads, no branches; returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to bulk-zero the object before field-level zeroing. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Zero DWORD at this+0x0 (*this = 0). [field:this:0x00000000]
    // ASSIGNMENT: Zero BYTE at this+0x4. [field:this:0x00000004]
    // ASSIGNMENT: Zero DWORD at this+0x24 (this[9]). [field:this:0x00000024]
    // ASSIGNMENT: Zero DWORD at this+0x28 (this[10]). [field:this:0x00000028]
    // ASSIGNMENT: Zero BYTE at this+0x2C (byte offset 44). [field:this:0x0000002C]
    // ASSIGNMENT: Zero DWORD at this+0x4C (this[19]). [field:this:0x0000004C]
    // ASSIGNMENT: Zero DWORD at this+0x50 (this[20]). [field:this:0x00000050]
    // ASSIGNMENT: Zero BYTE at this+0x54 (byte offset 84). [field:this:0x00000054]
    // ASSIGNMENT: Zero DWORD at this+0x74 (this[29]). [field:this:0x00000074]
    // ASSIGNMENT: Zero DWORD at this+0x78 (this[30]). [field:this:0x00000078]
    // ASSIGNMENT: Zero DWORD at this+0x7C (this[31]). [field:this:0x0000007C]
    // ASSIGNMENT: Zero DWORD at this+0x80 (this[32]). [field:this:0x00000080]
    // ASSIGNMENT: Zero DWORD at this+0x94 (this[37]). [field:this:0x00000094]
    // ASSIGNMENT: Zero DWORD at this+0x98 (this[38]). [field:this:0x00000098]
    // ASSIGNMENT: Zero DWORD at this+0x9C (this[39]). [field:this:0x0000009C]
    // RETURN: Return this, the initialized object pointer. [function:0x0055F080, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   *(uint32_t*)this = 0;
    //   *(uint8_t*)((uint8_t*)this + 0x4) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x24) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x28) = 0;
    //   *(uint8_t*)((uint8_t*)this + 0x2C) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x4C) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x50) = 0;
    //   *(uint8_t*)((uint8_t*)this + 0x54) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x74) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x78) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x7C) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x80) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x94) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x98) = 0;
    //   *(uint32_t*)((uint8_t*)this + 0x9C) = 0;
    //   return this;
    // UNRESOLVED: Owner object type and identity are not established by packet evidence; callers RenderUISystemGlobalInit (0x0053C360) and sub_556260 (0x00556260) suggest an init-time UI/system object but do not name it.
    // UNRESOLVED: GlobalZeroInit_c2a0 bulk-zeroing plus explicit field writes is redundant unless the structure is partially reused; purpose unknown.
    // UNRESOLVED: Mixed byte/dword field widths (BYTEs at +0x4, +0x2C, +0x54) imply a heterogeneous member layout, but no type evidence is present in the packet.
}
