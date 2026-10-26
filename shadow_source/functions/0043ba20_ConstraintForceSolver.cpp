// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043BA20
// Canonical corpus name: ConstraintForceSolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstraintForceSolver_0043ba20.c

void UnknownObject::ConstraintForceSolver()
{
    // Searches the constraint element array (this+0x15C8, count at this+0x15C4) for an element whose body-pair identifiers match either ordering of this+0x15F0 and this+0x141C. On match, accumulates the incoming delta a2 into the constraint output vector, applies a matrix-vector transform against the body rotation matrix (this+0x15F0), then calls RelativeVelocityCompute and sub_56D2D0 on the element. Part of the per-frame constraint force solving system dispatched by SolverDispatch (0x0043B930).
    // GUARD: Read constraint element count from this+0x15C4 and loop only while it is positive. [field:this:0x000015C4, caller:0x0043B930]
    // LOOP: Iterate the constraint element array starting at this+0x15C8, advancing one element per step (18 DWORD stride per element). [field:this:0x000015C8, field:this:0x000015C4]
    // GUARD: Match element body identifiers against this+0x15F0 (as a body id) and this+0x141C in either order: element[1]==this+0x15F0 && element[3]==this+0x141C, or the swapped pairing. [field:*(this+0x15C8):0x00000004, field:*(this+0x15C8):0x0000000C, field:this:0x000015F0, field:this:0x0000141C]
    // GUARD: Both constraint pointers (element[2] and element[4]) must be non-null before computing forces. [field:*(this+0x15C8):0x00000008, field:*(this+0x15C8):0x00000010]
    // ASSIGNMENT: Accumulate incoming delta a2 plus this+0x1420 into the first element of the constraint output vector (element+0x10). [field:this:0x00001420, field:*(this+0x15C8):0x00000010, source:raw]
    // CALCULATION: Read the body rotation matrix base from this+0x15F0 and scale the accumulated delta by the matrix element at relative offset 0x34. [field:this:0x000015F0, field:*(this+0x15F0):0x00000034]
    // CALCULATION: Compute constraint force component at element+0x20 as scaled delta plus matrix[0x4C]*output[2] plus output[0]*matrix[0x1C]. [field:*(this+0x15F0):0x0000004C, field:*(this+0x15F0):0x0000001C, field:*(this+0x15C8):0x00000018, field:*(this+0x15C8):0x00000020]
    // CALCULATION: Compute constraint force component at element+0x28 from matrix[0x3C]*output[1], matrix[0x24]*output[0], and matrix[0x54]*output[2]. [field:*(this+0x15F0):0x0000003C, field:*(this+0x15F0):0x00000024, field:*(this+0x15F0):0x00000054, field:*(this+0x15C8):0x00000028]
    // CALCULATION: Compute constraint force component at element+0x30 from matrix[0x44]*output[1], matrix[0x2C]*output[0], and matrix[0x5C]*output[2]. [field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x0000005C, field:*(this+0x15C8):0x00000030]
    // CALL: Compute relative velocity for the matched constraint element via RelativeVelocityCompute. [callee:0x0056D1C0, field:*(this+0x15C8):0x00000008]
    // CALL: Run the constraint resolution step sub_56D2D0 on the matched element, then return. [callee:0x0056D2D0, field:*(this+0x15C8):0x00000008]
    // RETURN: Return after the matched element is solved; if no element matched, fall out of the loop without returning a value. [source:raw, function:0x0043BA20]

    // Conservative worker pseudocode:
    //   count = *(this + 0x15C4);
    //   for (i = 0; i < count; ++i) {
    //     el = *(this + 0x15C8) + i * 0x48;
    //     match = (el[0x4] == *(this + 0x15F0) && el[0xC] == *(this + 0x141C))
    //             || (el[0xC] == *(this + 0x15F0) && el[0x4] == *(this + 0x141C));
    //     if (!match) continue;
    //     out = el[0x8]; other = el[0x10];
    //     if (!out || !other) continue;
    //     out[0x10] = a2 + *(this + 0x1420);
    //     m = *(this + 0x15F0);
    //     s = out[0x10] * m[0x34];
    //     out[0x20] = s + m[0x4C] * out[0x18] + out[0x8] * m[0x1C];
    //     out[0x28] = m[0x3C] * out[0x10] + m[0x24] * out[0x8] + m[0x54] * out[0x18];
    //     out[0x30] = m[0x44] * out[0x10] + m[0x2C] * out[0x8] + m[0x5C] * out[0x18];
    //     RelativeVelocityCompute(el);
    //     sub_56D2D0(el);
    //     return;
    //   }
    // UNRESOLVED: Element field at relative offset 0x38 (listed RW in the packet) is not written by this function; it may be written by RelativeVelocityCompute or sub_56D2D0.
    // UNRESOLVED: this+0x15F0 is read both as a body identifier (DWORD) for matching and as a pointer to the body rotation matrix; whether these are the same value is unresolved.
    // UNRESOLVED: Precise meaning of the element[0x4]/element[0xC] identifier pair and of element[0x10] is unverified.
}
