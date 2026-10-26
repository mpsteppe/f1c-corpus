// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537CE0
// Canonical corpus name: TripleVTableCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleVTableCall_00537ce0.c

void UnknownObject::TripleVTableCall()
{
    // Resets state via StateResetWithCallback(a1, a2, 0), then invokes the same vtable function pointer stored at a2+36 three times, passing the object pointer at a2+40 with three different arguments: a1[10] (offset 0x28), a1[9] (offset 0x24), and a1 itself. Always returns 0. Cluster-copied prelabel notes a structural twin.
    // CALL: Call StateResetWithCallback(a1, a2, 0) to reset state before the vtable dispatches. [callee:0x00537000, source:raw]
    // CALL: Invoke the function pointer at a2+36 with object a2+40 and argument a1[10] (dword at offset 0x28). [field:this:0x00000028, source:raw]
    // CALL: Invoke the same function pointer at a2+36 with object a2+40 and argument a1[9] (dword at offset 0x24). [field:this:0x00000024, source:raw]
    // CALL: Invoke the same function pointer at a2+36 a third time with object a2+40 and the a1 pointer itself as the argument. [source:raw]
    // RETURN: Return 0 as the function result after the three vtable dispatches. [function:0x00537CE0, source:raw]

    // Conservative worker pseudocode:
    //   int TripleVTableCall(void *a1, void *a2) {
    //       StateResetWithCallback(a1, a2, 0);
    //       void (__fastcall *fn)(void *, void *) = *(void (__fastcall **)(void *, void *))(a2 + 36);
    //       void *obj = *(void **)(a2 + 40);
    //       fn(obj, *(void **)((char *)a1 + 0x28));
    //       fn(obj, *(void **)((char *)a1 + 0x24));
    //       fn(obj, a1);
    //       return 0;
    //   }
    // UNRESOLVED: The identity of the object at a2+36/a2+40 and the meaning of the three arguments (a1[10], a1[9], a1) is not evidenced; the packet only grounds a triple dispatch to one vtable slot after a reset.
    // UNRESOLVED: Why a1[9] (0x24) is passed after a1[10] (0x28), out of ascending-offset order, is unevidenced.
    // UNRESOLVED: The semantics of StateResetWithCallback's third argument 0 are not evidenced in this packet.
}
