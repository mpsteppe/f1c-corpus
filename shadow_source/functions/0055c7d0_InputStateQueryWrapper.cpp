// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C7D0
// Canonical corpus name: InputStateQueryWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputStateQueryWrapper_0055c7d0.c

void UnknownObject::InputStateQueryWrapper()
{
    // Thin __thiscall wrapper around an input-state query. Copies the this pointer into a local, passes a dword field read at offset 0x13EC (this[1275]) as the handle, a constant zero, and a pointer to the local into sub_55C450, then returns the local (which aliases this). Acts as an adapter between the caller and the input-state query routine.
    // ASSIGNMENT: Copy this into the stack local v2 so it can be passed by address. [source:raw]
    // CALL: Call sub_55C450 with the input-state handle read from this[1275] (offset 0x13EC), constant 0, and the address of v2. [callee:0x0055C450, field:this:0x000013EC, source:raw]
    // RETURN: Return v2, which still holds this after the query call. [source:raw]

    // Conservative worker pseudocode:
    //   int *InputStateQueryWrapper(int *this) {
    //     int *v2 = this;
    //     sub_55C450(this[1275], 0, &v2);
    //     return v2;
    //   }
    // UNRESOLVED: Meaning of the constant 0 argument to sub_55C450 is unknown.
    // UNRESOLVED: Whether sub_55C450 writes through &v2 and can mutate the returned value is not established here.
    // UNRESOLVED: Ownership and type of the object containing offset 0x13EC are unknown.
}
