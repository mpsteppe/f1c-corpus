// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005414E0
// Canonical corpus name: Field0x13B0Accessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Field0x13B0Accessor_005414e0.c

void UnknownObject::Field0x13B0Accessor()
{
    // Getter __thiscall: returns the integer field at offset 0x13B0 of this (this[1260]). No side effects, no guards, no globals, no callees.
    // RETURN: return this[0x13B0]; yield the field value at this+0x13B0 to the caller [field:this:0x000013B0, source:raw]
    // CALL: Called by VertexBufferResourceAllocation (0x00543FA0), which reads this field during vertex-buffer resource setup. [caller:0x00543FA0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5414E0(_DWORD *this) {
    //     return this[1260];
    //   }
    // UNRESOLVED: Meaning of the field at this+0x13B0 and the owning object type are not identified in the packet; the caller name suggests a rendering/resource path but is not corroborated here.
    // UNRESOLVED: The field is read-only in this function; its writer is not present in the packet.
}
