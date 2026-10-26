// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562FE0
// Canonical corpus name: AudioValueSetterCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioValueSetterCall_00562fe0.c

void UnknownObject::AudioValueSetterCall()
{
    // Stores a new value a2 at the object base, then dispatches through the object's call table. The previous value at byte offset 124 is captured first and passed back as the third argument of an indirect call through a function pointer loaded from byte offset 120, with fixed arguments 1, 0 and 0. The indirect call's return value is propagated to the caller.
    // ASSIGNMENT: Capture the previous value stored at byte offset 124 of the object into local v3 before it is overwritten. [function:0x00562FE0, source:raw]
    // ASSIGNMENT: Store the incoming value a2 at the object base (byte offset 0), replacing its prior value. [function:0x00562FE0, source:raw]
    // CALL: Indirect call through the function pointer loaded from byte offset 120 of the object, invoked with the object pointer, constant 1, the captured old value v3, and two zero arguments. [function:0x00562FE0, source:raw]
    // RETURN: Return the result of the indirect call so the caller receives the callable's return value. [function:0x00562FE0, source:raw]
    // CALL: The setter is reached from audio-path callers including sub_562E30, sub_5630D0, NetworkConnection, sub_563410 and sub_563AB0. [caller:0x00562E30, caller:0x005630D0, caller:0x00563260, caller:0x00563410, caller:0x00563AB0]

    // Conservative worker pseudocode:
    //   int AudioValueSetterCall(int a1, int a2) {
    //     int v3 = *(int*)(a1 + 124);
    //     *(int*)a1 = a2;
    //     return ((int (__cdecl*)(int, int, int, int, int))*(int*)(a1 + 120))(a1, 1, v3, 0, 0);
    //   }
    // UNRESOLVED: The meaning of the fixed arguments 1, 0 and 0 passed to the indirect callable is not established.
    // UNRESOLVED: The object class behind this dispatcher and the role of the byte-offset-124 value are unknown.
}
