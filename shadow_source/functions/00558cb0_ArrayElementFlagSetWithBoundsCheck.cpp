// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558CB0
// Canonical corpus name: ArrayElementFlagSetWithBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayElementFlagSetWithBoundsCheck_00558cb0.c

void UnknownObject::ArrayElementFlagSetWithBoundsCheck()
{
    // Bounds-checked array element flag setter. When index a2 is below the element count at this[0x2C], calls sub_53B330 on the element entry at array base + a2*128 + 16 with three caller arguments, then sets flag 0x4000 on the element base dword at array base + a2*128. Returns the element base pointer on success, or the raw index a2 when the index is out of bounds. Per-frame path; callers include ParticleCollisionSpark (004CB620), WheelRenderObjectPerFrameUpdate (004CB860), ParticleTrailEmitter (004CBC50), ParticleInstanceUpdate (004CC1D0).
    // GUARD: If index a2 is >= the element count at this[0x2C], skip the update and return a2 unmodified [field:this:0x0000002C]
    // CALCULATION: Element base = array pointer at this[0x34] + (a2 << 7), using the 128-byte element stride; entry for the helper = base + 16 [field:this:0x00000034]
    // CALL: Call sub_53B330 at element base + 16 with arguments a3, a4, a5 to update multiple fields on the array element [callee:0x0053B330, field:this:0x00000034]
    // ASSIGNMENT: Set flag 0x4000 on the element base dword at array base + a2*128 [field:this:0x00000034]
    // RETURN: Return element base pointer when the index was in bounds, otherwise return the raw index a2 [source:raw, function:0x00558CB0]
    // CALL: Invoked per frame by ParticleCollisionSpark (004CB620), WheelRenderObjectPerFrameUpdate (004CB860), ParticleTrailEmitter (004CBC50), and ParticleInstanceUpdate (004CC1D0) [caller:0x004CB620, caller:0x004CB860, caller:0x004CBC50, caller:0x004CC1D0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 >= this[11]) return (DWORD*)a2;
    //   sub_53B330(this[13] + (a2 << 7) + 16, a3, a4, a5);
    //   result = this[13] + (a2 << 7);
    //   *result |= 0x4000;
    //   return result;
    // UNRESOLVED: Role of arguments a3, a4, a5 forwarded to sub_53B330 is unknown; they are not referenced directly here
    // UNRESOLVED: Meaning of flag bit 0x4000 and the 128-byte element layout is not established
    // UNRESOLVED: Element count field at this[0x2C] and array pointer at this[0x34] are read-only here; their writers are elsewhere
}
