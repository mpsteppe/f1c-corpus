// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A210
// Canonical corpus name: sub_47A210
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47A210_0047a210.c

void UnknownObject::ObjectInitWithVTableOverride()
{
    // Straight-line object initializer. Calls InitVTableSet(this, 0, 1065353216) to seed the vtable slot and write the default float 1.0, then overrides the vtable pointer at this+0x0 to off_5A6068 and zeroes the byte at this+0x100. Returns this. Exact field semantics are unverified beyond the raw writes; the constructor/override role is DERIVED from existing analysis only.
    // CALL: Call InitVTableSet(this, 0, 1065353216) to initialize the vtable reference and write default float 1.0 (bit pattern 1065353216) at offset 0. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Override the vtable pointer at this+0x0 with off_5A6068. [field:this:0x00000000, global:0x005A6068, source:raw]
    // ASSIGNMENT: Zero the byte at this+0x100 (offset 256), a per-instance flag cleared during construction. [field:this:0x00000100, source:raw]
    // RETURN: Return this, the initialized object. [function:0x0047A210, source:raw]

    // Conservative worker pseudocode:
    //   InitVTableSet(this, 0, 1065353216);
    //   this[0] = &off_5A6068;
    //   *(byte*)((char*)this + 0x100) = 0;
    //   return this;
    // UNRESOLVED: Semantics of the byte flag at +0x100 (init state vs enabled flag) are unverified.
    // UNRESOLVED: The purpose of the InitVTableSet call combined with the immediate vtable override is unverified; existing analysis interprets it as base init followed by derived vtable install (DERIVED).
    // UNRESOLVED: Owner class is unknown; no static caller found.
}
