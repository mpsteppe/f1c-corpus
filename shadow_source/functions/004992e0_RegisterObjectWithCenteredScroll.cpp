// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004992E0
// Canonical corpus name: sub_4992E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4992E0_004992e0.c

void UnknownObject::RegisterObjectWithCenteredScroll()
{
    // Registers an object pointer at this+0x4C and, when the a3 flag is set, computes a centered scroll offset from the object's geometry (via a2+12's half-extents and this+0x50 sub-struct spans) and dispatches it through ScrollOffsetUpdateWithConditionalDispatch. Returns the registered pointer a2.
    // GUARD: Guard on object pointer a2 being non-null; when null the function returns a2 unchanged without storing anything. [source:raw]
    // ASSIGNMENT: Store the registered object pointer into this[19] (byte offset this+0x4C) for later use. [field:this:0x0000004C, source:raw]
    // GUARD: Guard on the boolean flag a3; when set, compute and dispatch centered scroll offsets. [source:raw]
    // ASSIGNMENT: Read the registered object's geometry: dereference a2 + 12, then read fields +28 and +32 as the half-extent components used to center the view. [source:raw]
    // CALCULATION: Compute the two centering deltas from the this+0x50 sub-struct: vertical span = field at +16 minus field at +12 (this+0x60 - this+0x5C), horizontal span = field at +8 minus field at +4 (this+0x58 - this+0x54); each clamped to zero when negative and then incremented by one. [field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // CALL: Call ScrollOffsetUpdateWithConditionalDispatch with target offsets (span_x/2 - this[3] - half_extent_a/2, span_y/2 - this[1] - half_extent_b/2), where this[1]/this[3] are the reference offsets at this+0x4/this+0xC. [field:this:0x00000004, field:this:0x0000000C, callee:0x0049ACC0, source:raw]
    // RETURN: Return the registered object pointer a2. [source:raw]

    // Conservative worker pseudocode:
    //   int RegisterObjectWithCenteredScroll(_DWORD *this, int obj, char enable) {
    //     if (!obj) return obj;
    //     this[19] = obj;
    //     if (enable) {
    //       int *geo = *(_DWORD **)(obj + 12);
    //       int ha = *(int*)(geo + 28), hb = *(int*)(geo + 32);
    //       int *sp = (_DWORD*)this[20];
    //       int dx = (sp[4] - sp[3] > 0) ? sp[4] - sp[3] + 1 : 0;
    //       int dy = (sp[2] - sp[1] > 0) ? sp[2] - sp[1] + 1 : 0;
    //       return ScrollOffsetUpdateWithConditionalDispatch(dx / 2 - this[3] - ha / 2, dy / 2 - this[1] - hb / 2);
    //     }
    //     return obj;
    //   }
    // UNRESOLVED: The meaning of the a3 flag (immediate centering vs deferred scroll update) is not confirmed; only its gating effect on the dispatch is known.
    // UNRESOLVED: The interpretation of this+0x50 sub-struct spans (this+0x54/0x58/0x5C/0x60) as a scrollable content rectangle is DERIVED from the arithmetic, not confirmed.
    // UNRESOLVED: The fields at a2+12, +28 and +32 have no packet field evidence and are described only from raw arithmetic.
}
