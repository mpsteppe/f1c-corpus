// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8250
// Canonical corpus name: ObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectDestructor_004f8250.c

void UnknownObject::ObjectDestructor()
{
    // COM-like object destruction: guards on the object pointer at a1, runs the vtable destruction chain (slot 2 at vtable+8 release, slot 6 at vtable+24 cleanup, then slot 0 delete with argument 1), and nulls the caller's pointer. Returned value is the last call result. Called by DoubleBufferFree (0x004F83B0).
    // GUARD: Guard: proceed only when the object pointer stored at a1 (field obj+0x0) is non-null; otherwise return immediately. [field:obj:0x00000000, source:raw]
    // CALL: Call vtable slot 2 (function pointer at vtable+8) on the object; this is the first destruction-phase callback. [field:*(obj+0x0):0x00000008, field:*(obj+0x0):0x00000000, source:raw]
    // CALL: Call vtable slot 6 (function pointer at vtable+24) on the object; this is the second destruction-phase callback, whose return value becomes the function result. [field:*(obj+0x0):0x00000018, field:*(obj+0x0):0x00000000, source:raw]
    // GUARD: Guard: re-check the object pointer at a1 (field obj+0x0) before the delete call. [field:obj:0x00000000, source:raw]
    // CALL: Call vtable slot 0 (function pointer at vtable+0) on the object with argument 1; this is the final delete/free call. [field:*(obj+0x0):0x00000000, source:raw]
    // ASSIGNMENT: Null the caller's output pointer at a1 (field this+0x0) after destruction. [field:this:0x00000000, source:raw]
    // RETURN: Return the result of the last executed destruction callback (or the unmodified pointer value when the initial guard fails). [source:raw]

    // Conservative worker pseudocode:
    //   int ObjectDestructor(DWORD *a1) {
    //     if (*a1) {
    //       (*a1)->vtbl[2](*a1);            // release at vtable+8
    //       int r = (*a1)->vtbl[6](*a1);    // cleanup at vtable+24
    //       if (*a1) (*a1)->vtbl[0](*a1, 1); // delete at vtable+0, arg 1
    //       *a1 = 0;
    //       return r;
    //     }
    //     return (int)a1;
    //   }
    // UNRESOLVED: The object type is unknown; vtable slot call targets are indirect so their addresses are not evidenced in this packet.
    // UNRESOLVED: The meaning of the argument 1 passed to the delete slot is not evidenced.
    // UNRESOLVED: Callee identities for the three vtable calls are not statically resolved.
}
