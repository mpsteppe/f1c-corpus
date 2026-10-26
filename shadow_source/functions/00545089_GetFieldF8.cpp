// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545089
// Canonical corpus name: sub_545089
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_545089_00545089.c

void UnknownObject::GetFieldF8()
{
    // Trivial getter (thiscall): returns the 32-bit value of this[62], i.e. the dword at byte offset 0xF8 of the receiver. No side effects and no parameters beyond this.
    // RETURN: return this[62], reading the dword at byte offset 0xF8 (index 62) of this; read-only access with no other operations [field:this:0x000000F8, source:raw]

    // Conservative worker pseudocode:
    //   int GetFieldF8(_DWORD *this) { return this[62]; }  // this+0xF8
    // UNRESOLVED: Owner class of the object holding the field at +0xF8 is not evidenced in this packet; the getter's field semantics depend on that unknown owner
}
