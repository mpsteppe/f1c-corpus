// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A55A0
// Canonical corpus name: ConditionalDispatch_55a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_55a0_004a55a0.c

void UnknownObject::ThreeTargetAnimationDispatcher()
{
    // Per-frame dispatcher that forwards to up to three sub-object pointers held in `this`: calls sub_4A3570 on the objects at this+0x10 and this+0xC passing a3, and calls AccumulatorWithStateSwitch on the object at this+0x14 passing a2. Each call is independently guarded by a null-pointer check.
    // ASSIGNMENT: Load the first sub-object pointer from this+0x10 (this[4]). [field:this:0x00000010, source:raw]
    // GUARD: Guard on the sub-object pointer at this+0x10 being non-null before calling into it. [field:this:0x00000010, source:raw]
    // CALL: Call sub_4A3570 on the object at this+0x10, passing a3. [callee:0x004A3570, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Load the second sub-object pointer from this+0xC (this[3]). [field:this:0x0000000C, source:raw]
    // GUARD: Guard on the sub-object pointer at this+0xC being non-null before calling into it. [field:this:0x0000000C, source:raw]
    // CALL: Call sub_4A3570 on the object at this+0xC, passing a3. [callee:0x004A3570, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Load the accumulator pointer from this+0x14 (this[5]). [field:this:0x00000014, source:raw]
    // GUARD: Guard on the accumulator pointer at this+0x14 being non-null before calling into it. [field:this:0x00000014, source:raw]
    // CALL: Call AccumulatorWithStateSwitch on the object at this+0x14, passing a2. [callee:0x004A4050, field:this:0x00000014, source:raw]
    // RETURN: Return void. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4A55A0(int* this, float a2, float a3) {
    //     if (this[4] != 0) sub_4A3570(this[4], a3);
    //     if (this[3] != 0) sub_4A3570(this[3], a3);
    //     if (this[5] != 0) AccumulatorWithStateSwitch(this[5], a2);
    //   }
    // UNRESOLVED: The identities of `this` and of the three sub-objects are unknown; the owner proposal is therefore UNKNOWN rather than a specific animation class.
    // UNRESOLVED: The two float parameters are forwarded asymmetrically (a3 to the sub_4A3570 targets, a2 to the accumulator); the meaning of each is delegated to the respective callee and not established here.
    // UNRESOLVED: The existing skeleton analysis labels sub_4A3570 as AnimationTargetPropagator and AccumulatorWithStateSwitch as a mode-switch accumulator; those roles are DERIVED prose, not confirmed.
}
