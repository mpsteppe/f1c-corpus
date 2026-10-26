// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004139C0
// Canonical corpus name: CollisionShapeSizeClassify
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionShapeSizeClassify_004139c0.c

void UnknownObject::CollisionShapeSizeClassify()
{
    // Classifies a collision-shape size argument a3 into an integer size class written to this+8, then stores the result of a sub-call at this+12. Classification only runs when a2 is zero and the a4 byte flag is clear, otherwise the function returns -1. The a3 value is promoted to double and pushed through a chain of ascending double thresholds held in the read-only dbl_59E788..dbl_59E7E0 globals (1.0 through 52.5) to produce the class index, with the upper tail split further by integer bounds 75, 110 and 999. Called by SoundEventDispatcher (00411E90).
    // RETURN: Early return path: the function defaults result to -1 and returns it whenever a2 is non-zero or a4 is non-zero, so classification only proceeds under the a2==0 && a4==0 guard [function:0x004139C0, source:raw]
    // GUARD: Classification gated on a2 == 0 and a4 == 0; both must be clear for the threshold chain to run [function:0x004139C0, source:raw]
    // CALCULATION: a3 promoted to double and compared against the ascending chain of read-only double thresholds stored in dbl_59E788 through dbl_59E7E0 (the 1.0 through 52.5 constants), mapping the value onto integer class index 32..44 [global:0x0059E788, global:0x0059E790, global:0x0059E798, global:0x0059E7A0, global:0x0059E7A8, global:0x0059E7B0, global:0x0059E7B8, global:0x0059E7C0, global:0x0059E7C8, global:0x0059E7D0, global:0x0059E7D8, global:0x0059E7E0, source:raw]
    // CALCULATION: Upper tail of the chain split by integer bounds: a3 >= 999 selects class 48, a3 >= 110 selects class 47, a3 >= 75 selects class 46, otherwise class 45; the dbl_59E420 threshold participates in this upper classification [global:0x0059E420, source:raw]
    // ASSIGNMENT: Writes the computed size class index to the output struct at this+8 [field:this:0x00000008, source:raw]
    // CALL: sub_414180 invoked with argument 0 and its return value stored at this+12 [callee:0x00414180, field:this:0x0000000C, source:raw]
    // RETURN: Successful classification returns 1; the a2==0 && a4==0 failure path returns -1 [function:0x004139C0, source:raw]
    // CALL: Invoked by SoundEventDispatcher (00411E90) [caller:0x00411E90, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 != 0 || a4 != 0) return -1;
    //   cls = classify((double)a3 against dbl_59E420..dbl_59E7E0 chain of 1.0..52.5);
    //   if (a3 >= 75) { if (a3 >= 110) cls = (a3 >= 999) + 47; else cls = 46; } else { cls = 45; }
    //   this[8] = cls;
    //   this[12] = sub_414180(0);
    //   return 1;
    // UNRESOLVED: The exact association of each dbl_59E420..dbl_59E7E0 global to a specific threshold literal (1.0..52.5) is not determinable from this packet; only the inline decimal constants appear in the raw source
    // UNRESOLVED: The output struct type at this+8/this+12 is unknown; a1 is used only as a write base
    // UNRESOLVED: sub_414180 is called with a constant 0 argument and its semantics are not defined in this packet
}
