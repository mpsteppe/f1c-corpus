// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488970
// Canonical corpus name: ShortComputation_8970
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8970_00488970.c

void UnknownObject::ClampScrollOffset()
{
    // Clamps the stored offset at this+0xE0 (this[56]) into a valid scroll range and then tail-calls a virtual accessor. If the stored offset is negative it is reset to 0. Otherwise the offset plus the value returned by the virtual +0x18 accessor is compared against the value returned by the virtual +0x20 accessor; when it exceeds that extent the offset is rewritten as extent minus position, so offset + position stays within the extent. In all cases the result of the virtual +0xA8 call is returned. The +0x18, +0x20 and +0xA8 accessors are dispatched through the vtable pointer at this+0x0.
    // GUARD: Sign check on the stored offset: if this[0xE0] >= 0 take the clamping path, otherwise reset this[0xE0] to 0. [field:this:0x000000E0, guard:0, function:0x00488970, source:raw]
    // CALCULATION: Compute v2 = this[0xE0] + position where position is the result of the virtual call at vtable slot +0x18 (vtable pointer at this+0x0). [field:this:0x00000000, field:obj:0x00000018, field:this:0x000000E0, function:0x00488970, source:raw]
    // GUARD: Overflow check: if v2 > extent, where extent is the result of the virtual call at vtable slot +0x20, enter the clamp branch. [field:this:0x00000000, field:obj:0x00000020, field:this:0x000000E0, function:0x00488970, source:raw]
    // ASSIGNMENT: Clamp branch: this[0xE0] = extent - position, so the offset keeps offset + position within the extent. [field:obj:0x00000018, field:obj:0x00000020, field:this:0x000000E0, function:0x00488970, source:raw]
    // ASSIGNMENT: Else branch: when the stored offset is negative, this[0xE0] = 0. [field:this:0x000000E0, function:0x00488970, source:raw]
    // CALL: Tail virtual dispatch: call the accessor at vtable slot +0xA8 (vtable pointer at this+0x0) and use its result as the return value. [field:this:0x00000000, field:obj:0x000000A8, function:0x00488970, source:raw]
    // RETURN: Return the result of the virtual +0xA8 call. [function:0x00488970, source:raw]

    // Conservative worker pseudocode:
    //   if (offset < 0) {
    //     offset = 0;
    //   } else {
    //     if (offset + position() > extent())
    //       offset = extent() - position();
    //   }
    //   return state();
    // UNRESOLVED: The owning object type is unidentified; the three callers (DeltaBasedUpdate 00488900, ScrollProgressHandler 0048D4B0, InputDispatch 0048D590) and the vtable slots +0x18/+0x20/+0xA8 suggest a UI scroll container, but that interpretation is DERIVED from the existing analysis, not evidenced by the packet.
    // UNRESOLVED: The legacy ABI label 'Short_Computation_488970' (abi:lead) is a generic placeholder and carries no object semantics; the proposed name follows the existing analysis fill (ScrollPositionClamp).
}
