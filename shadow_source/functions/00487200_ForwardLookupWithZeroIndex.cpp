// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487200
// Canonical corpus name: TrivialThunk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrivialThunk_00487200.c

void UnknownObject::ForwardLookupWithZeroIndex()
{
    // __thiscall forwarding thunk. Delegates directly to sub_4870E0(this, 0) and returns its result unchanged. The constant second argument selects index 0 in the shared lookup routine.
    // CALL: Forward to sub_4870E0(this, 0) and return its result unchanged. [callee:0x004870E0, source:raw]
    // RETURN: Return the result of the forwarded call. [function:0x00487200, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_487200(_DWORD *this) {
    //     return sub_4870E0(this, 0);
    //   }
    // UNRESOLVED: Semantics of the second argument 0 and of the underlying lookup sub_4870E0 are unknown; sub_4870E0 is analyzed separately.
    // UNRESOLVED: Owner object type is not established by the packet.
}
