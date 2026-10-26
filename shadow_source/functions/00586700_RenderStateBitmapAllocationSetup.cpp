// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586700
// Canonical corpus name: SEHProtectedDirectXRenderStateSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHProtectedDirectXRenderStateSetup_00586700.c

void UnknownObject::RenderStateBitmapAllocationSetup()
{
    // Seeded init for a render-state object: calls sub_587460(0) and sub_59B2F0(8, 1, 16, 8), then registers five bitmap-allocation tracker entries on member offsets 52..68 of `this` with mode flags 1, 8, 1, 2, 16, and finally calls sub_586AA0(this) to finish bitmap-field initialization. Returns `this`. Called once by SEHProtectedDataCopy (0x0057A760); not on the tick frame path.
    // CALL: Call sub_587460(0): general one-argument init with a zero parameter. [callee:0x00587460]
    // CALL: Call sub_59B2F0(8, 1, 16, 8): setup with four literal arguments, likely render-state dimensions or allocation parameters. [callee:0x0059B2F0]
    // CALL: Call BitmapAllocationTracker(1, this + 52): register bitmap allocation at offset 52 with mode 1. [callee:0x0059B5C0]
    // CALL: Call BitmapAllocationTracker(8, this + 56): register bitmap allocation at offset 56 with mode 8. [callee:0x0059B5C0]
    // CALL: Call BitmapAllocationTracker(1, this + 60): register bitmap allocation at offset 60 with mode 1. [callee:0x0059B5C0]
    // CALL: Call BitmapAllocationTracker(2, this + 64): register bitmap allocation at offset 64 with mode 2. [callee:0x0059B5C0]
    // CALL: Call BitmapAllocationTracker(16, this + 68): register bitmap allocation at offset 68 with mode 16. [callee:0x0059B5C0]
    // CALL: Call sub_586AA0(this): finalize or reset multi-block bitmap fields after the tracker registrations. [callee:0x00586AA0]
    // RETURN: Return `this` unchanged as the initializer result. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_586700(char *this) {
    //     sub_587460(0);
    //     sub_59B2F0(8, 1, 16, 8);
    //     BitmapAllocationTracker(1, this + 52);
    //     BitmapAllocationTracker(8, this + 56);
    //     BitmapAllocationTracker(1, this + 60);
    //     BitmapAllocationTracker(2, this + 64);
    //     BitmapAllocationTracker(16, this + 68);
    //     sub_586AA0(this);
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the mode flags 1, 8, 1, 2, 16 passed to BitmapAllocationTracker.
    // UNRESOLVED: Purpose and exact effect of sub_587460(0) and sub_59B2F0(8, 1, 16, 8) are defined in callees not inspected here.
    // UNRESOLVED: Semantics of sub_586AA0's finalization step relative to the tracker registrations.
    // UNRESOLVED: What render-state fields the offsets 52..68 of `this` back; field layout of the owning object is unknown.
}
