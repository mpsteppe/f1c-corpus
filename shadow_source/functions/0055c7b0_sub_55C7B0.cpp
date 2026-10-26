// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C7B0
// Canonical corpus name: sub_55C7B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C7B0_0055c7b0.c

void UnknownObject::sub_55C7B0()
{
    // Small wrapper: initializes a local output pointer v2 to the current instance, calls sub_55C450(this[1274], 0, &v2) passing this[1274] (offset 0x13E8) as the first argument, mode 0, and the address of v2 as an output context, then returns v2. Called by KeyEventDispatchToSubHandlers.
    // ASSIGNMENT: Initialize the local output pointer v2 = this (offset 0x0 of the instance) before the call. [source:raw]
    // CALL: Invoke sub_55C450(this[1274], 0, &v2), passing the field at offset 0x13E8 as the first argument and the address of v2 as an output parameter. [callee:0x0055C450, field:this:0x000013E8, source:raw]
    // RETURN: Return the (possibly updated) output pointer v2. [source:raw]
    // CALL: Called by KeyEventDispatchToSubHandlers (0x0055C7F0) on the input/display dispatch path. [caller:0x0055C7F0, source:raw]

    // Conservative worker pseudocode:
    //   int *sub_55C7B0(int *this) {
    //     int *v2 = this;
    //     sub_55C450(this[1274], 0, &v2);
    //     return v2;
    //   }
    // UNRESOLVED: Semantics of the first argument this[1274] (offset 0x13E8) passed to sub_55C450 are unproven.
    // UNRESOLVED: Meaning of the mode constant 0 and of the output context pointer v2 for sub_55C450 is unknown from this packet.
    // UNRESOLVED: Relationship between this[1274] and the caller's input/display object is unconfirmed.
}
