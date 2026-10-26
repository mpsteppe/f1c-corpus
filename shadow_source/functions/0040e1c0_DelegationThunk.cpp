// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E1C0
// Canonical corpus name: DelegationThunk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationThunk_0040e1c0.c

void UnknownObject::DelegationThunk()
{
    // Cleanup/delegation thunk: zeroes a run of globals starting at dword_5EA560 (unk_5EA568, dword_5EA570, unk_5EA578, unk_5EA580, unk_5EA588, unk_5EA594, unk_5EA5A0, unk_5EA5AC, unk_5EA5B8, unk_5EA5C4), calls GraphicsResourceDestructor(), then returns a pointer to dword_5EA560. Reads/writes a graphics-resource block and hands its base pointer back to the caller.
    // ASSIGNMENT: Zero a contiguous run of globals in the graphics-resource block: unk_5EA568, dword_5EA570, unk_5EA578, unk_5EA580, unk_5EA588, unk_5EA594, unk_5EA5A0, unk_5EA5AC, unk_5EA5B8 and unk_5EA5C4 are each set to 0. [global:0x005EA560, source:raw]
    // CALL: Delegate the resource teardown to GraphicsResourceDestructor(). [source:raw]
    // RETURN: Return a pointer to the first global of the block, dword_5EA560. [global:0x005EA560, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_40E1C0() {
    //     unk_5EA568 = 0; dword_5EA570 = 0; unk_5EA578 = 0; unk_5EA580 = 0;
    //     unk_5EA588 = 0; unk_5EA594 = 0; unk_5EA5A0 = 0; unk_5EA5AC = 0;
    //     unk_5EA5B8 = 0; unk_5EA5C4 = 0;
    //     GraphicsResourceDestructor();
    //     return &dword_5EA560;
    //   }
    // UNRESOLVED: Layout and per-field meaning of the zeroed global block starting at 0x5EA560 are unknown.
    // UNRESOLVED: GraphicsResourceDestructor is called but carries no callee evidence reference in this packet.
    // UNRESOLVED: Semantics of the returned base pointer (why the caller receives &dword_5EA560 after teardown) are unclear.
}
