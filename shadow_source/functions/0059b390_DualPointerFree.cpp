// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B390
// Canonical corpus name: DualPointerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualPointerFree_0059b390.c

void UnknownObject::DualPointerFree()
{
    // Calls FreeWrapper on the object pointer stored at this[0], then calls FreeWrapper on the pointer stored at this[2] and returns its result. No guards, no globals, no branches beyond the two calls.
    // CALL: Invoke FreeWrapper_7bcf on the pointer at this[0] (offset 0x0), releasing the first owned sub-object. [callee:0x00587BCF, field:this:0x00000000]
    // CALL: Invoke FreeWrapper_7bcf on the pointer at this[2] (offset 0x8), releasing the second owned sub-object. [callee:0x00587BCF, field:this:0x00000008]
    // RETURN: Return the result of the second FreeWrapper_7bcf call as the function value. [source:raw]

    // Conservative worker pseudocode:
    //   FreeWrapper(this[0]);
    //   return FreeWrapper(this[2]);
    // UNRESOLVED: Return value of the first FreeWrapper call is discarded while the second is returned; whether this is meaningful (e.g. first-failure propagation) is not evident.
    // UNRESOLVED: Concrete type of 'this' and the objects at offsets 0x0 and 0x8 is unknown.
    // UNRESOLVED: Whether the two pointers are freed unconditionally or only if non-null is hidden inside FreeWrapper_7bcf.
}
