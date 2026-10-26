// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDB10
// Canonical corpus name: SphereProximityTag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SphereProximityTag_004bdb10.c

void UnknownObject::SphereProximityTagUpdater()
{
    // Walks the tag list on this (element count at this+0x1C, pointer array at this+0x20 with 4-byte stride) and, for every element object whose tag field at element+4 differs from a2, overwrites that tag with a2 and calls UIFocusChange with the element's UI handle (element+32) and 1. Returns the element count. Per-frame path, invoked by SpriteGridRender (004BE4E0).
    // ASSIGNMENT: Reads the array element count from this+0x1C into the loop bound [field:this:0x0000001C, source:raw]
    // LOOP: Iterates once per element over the pointer array at this+0x20 (4-byte stride), bound by the count at this+0x1C [field:this:0x00000020, field:this:0x0000001C, source:raw]
    // CALCULATION: Dereferences the current slot to obtain the element object pointer v8 = *(this+0x20 + 4*i) [field:this:0x00000020, source:raw]
    // GUARD: Element is updated only when its tag at v8+4 differs from a2; the accompanying !(v10|v11) term is an uninitialized x87 flag artifact, treated as an always-true decompilation residue [source:raw]
    // ASSIGNMENT: Writes the new tag value a2 into the element field at v8+4 [source:raw]
    // CALL: UIFocusChange invoked with the element UI handle at v8+32 and constant 1 to switch the focus state [callee:0x0054F7A0, source:raw]
    // RETURN: Returns the element count held in this+0x1C [field:this:0x0000001C, source:raw]
    // CALL: Invoked on the frame path by SpriteGridRender (004BE4E0) to refresh the proximity tags [caller:0x004BE4E0, source:raw]

    // Conservative worker pseudocode:
    //   count = this[7];
    //   for (i = 0; i < count; ++i) {
    //     element = *(this[8] + 4*i);
    //     if (element[1] != a2) {
    //       element[1] = a2;
    //       UIFocusChange(element[8], 1);
    //     }
    //   }
    //   return count;
    // UNRESOLVED: Guard term !(v10|v11) reads two uninitialized registers (decompilation artifact of x87 status flags); the effective condition is only element[1] != a2
    // UNRESOLVED: Parameters a3, a4, a5 are declared but never referenced in the body
    // UNRESOLVED: Element object layout (tag at +4, UI handle at +32) is only reachable through the element pointer; the element type is not defined in this packet
}
