// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B5A0
// Canonical corpus name: VTableSwitchWithVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSwitchWithVirtualCall_0040b5a0.c

void UnknownObject::VTableSwitchWithVirtualCall()
{
    // Vtable transition sequence: reads the sub-object pointer at this+0xC, switches this object's vtable (this+0x0) to off_59E6AC, calls virtual entry 0 of the sub-object with argument 3 when the sub-object is non-null, then switches this object's vtable back to off_59E634 and returns the virtual call result.
    // ASSIGNMENT: Load the sub-object pointer at this+0xC into v2. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Switch this object's vtable pointer at this+0x0 to off_59E6AC. [source:raw, field:this:0x00000000, global:0x0059E6AC]
    // GUARD: Guard on the sub-object pointer v2 being non-null before performing the virtual call. [source:raw, field:this:0x0000000C]
    // CALL: Call virtual entry 0 of the sub-object v2 with argument 3 and store the result. [source:raw, field:*(this+0xC):0x00000000]
    // ASSIGNMENT: Switch this object's vtable pointer at this+0x0 back to off_59E634. [source:raw, field:this:0x00000000, global:0x0059E634]
    // RETURN: Return the virtual call result (uninitialized value when the sub-object was null and the call was skipped). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40B5A0(_DWORD *this) {
    //     int (__thiscall ***v2)(_DWORD, int) = (int (__thiscall ***)(_DWORD, int))this[3];
    //     *this = &off_59E6AC;
    //     if (v2)
    //       result = (**v2)(v2, 3);
    //     *this = &off_59E634;
    //     return result;
    //   }
    // UNRESOLVED: Identity and purpose of the virtual call with argument 3 are unknown; the sub-object class at this+0xC is unconfirmed.
    // UNRESOLVED: Role of the vtable switch pair (off_59E6AC then off_59E634) and what off_59E634 represents is DERIVED at most from the packet analysis.
    // UNRESOLVED: Return value is uninitialized when the sub-object pointer is null.
}
