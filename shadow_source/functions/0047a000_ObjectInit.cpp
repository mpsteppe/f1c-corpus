// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A000
// Canonical corpus name: sub_47A000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47A000_0047a000.c

void UnknownObject::ObjectInit()
{
    // Object constructor: calls InitVTableSet(this, 0, 1065353216) to initialize a two-float range as [0.0f, 1.0f], installs vtable off_5A5EF8 at this+0x0, and zeroes the byte field at this+0x104. Returns this. Straight-line unconditional construction.
    // CALL: InitVTableSet(this, 0, 1065353216) — initializes the object's paired float range fields with literals 0 (0.0f) and 1065353216 (1.0f) [callee:0x004668E0, source:raw]
    // ASSIGNMENT: write vtable pointer: *(this + 0x0) = &off_5A5EF8 — installs the object type's vtable [field:this:0x00000000, global:0x005A5EF8, source:raw]
    // ASSIGNMENT: write byte: *(this + 0x104) = 0 — state/flag byte initialized to 0 (inactive) [field:this:0x00000104, source:raw]
    // RETURN: return this — constructor returns the initialized object pointer [function:0x0047A000, source:raw]

    // Conservative worker pseudocode:
    //   InitVTableSet(this, 0, 1065353216);
    //   *(_DWORD*)this = &off_5A5EF8;
    //   *(_BYTE*)(this + 0x104) = 0;
    //   return this;
    // UNRESOLVED: Owner class unknown; only its distinct vtable (off_5A5EF8) and the InitVTableSet range pattern are observable
    // UNRESOLVED: The semantics of the [0.0, 1.0] range initialized by InitVTableSet depend on the callee's field layout, which this packet does not contain
    // UNRESOLVED: Purpose of the zeroed byte at +0x104 (flag vs state) is not determinable from this constructor alone
}
