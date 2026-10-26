// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004668E0
// Canonical corpus name: InitVTableSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitVTableSet_004668e0.c

void UnknownObject::InitVTableSet()
{
    // Constructor helper: calls UIConstructorWithVTableParams(a2, a3) for base initialization, then writes the vtable pointer &off_59F210 into the this object's offset-0 slot, and returns this. Unconditional, no guards. Shared base initialization invoked by a family of UI component constructor stubs (00466A30, 00479C80, 00479DB0, 00479E30, 0047A000, 0047A190, 0047A210, 0047A3A0, 0047A550, 0047A580, 0047A5B0, 0047A5E0, 0047A620, 0047A800, 0047A8F0).
    // CALL: UIConstructorWithVTableParams(a2, a3) performs base UI construction with the given parameters. [callee:0x0048D3A0, source:raw]
    // ASSIGNMENT: Writes the vtable pointer &off_59F210 into the this object at offset 0, installing the object's virtual dispatch table. [field:this:0x00000000, global:0x0059F210, source:raw]
    // RETURN: Returns the fully initialized this pointer. [source:raw]
    // CALL: Invoked as shared base initialization by a family of UI/component constructor stubs, including ConstructorWithVTableAndFloatInit (00466A30), UIComponentInit2 (00479C80), ObjectInit_a5b0 (0047A5B0), UIComponentInit3 (0047A620), ConstructorWithRangeInit_a800 (0047A800) and others. [caller:0x00466A30, caller:0x00479C80, caller:0x0047A5B0, caller:0x0047A620, caller:0x0047A800, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* sub_4668E0(DWORD* this, int a2, int a3) {
    //     UIConstructorWithVTableParams(a2, a3);
    //     *this = &off_59F210;
    //     return this;
    //   }
    // UNRESOLVED: The exact meaning of a2/a3 is delegated entirely to UIConstructorWithVTableParams and is not resolvable from this packet.
    // UNRESOLVED: The concrete object type behind this is unknown; the vtable off_59F210 is referenced but its dispatch contents are outside this packet.
}
