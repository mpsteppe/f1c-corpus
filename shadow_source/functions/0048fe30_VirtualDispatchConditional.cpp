// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FE30
// Canonical corpus name: sub_48FE30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48FE30_0048fe30.c

void UnknownObject::VirtualDispatchConditional()
{
    // Conditional virtual double-dispatch on a sub-object at this+0x30. If the sub-object pointer is non-null, invokes its vtable method at offset 0x3C (slot 15) with argument a2, replaces the low byte of that method's return value with the boolean (a2 == 0), then invokes the vtable method at offset 0x38 (slot 14) on the same sub-object with that coerced value and returns its result. On the null path the function returns an uninitialized value.
    // GUARD: Load sub-object pointer from this+0x30 (this[12]); if null, fall through to return with no dispatch performed. [field:this:0x00000030, source:raw]
    // CALL: First virtual dispatch: call sub-object vtable method at offset 0x3C (vtable+60) with argument a2. [field:*(this+0x30):0x0000003C, source:raw]
    // ASSIGNMENT: Coerce the low byte of the first dispatch result to the boolean (a2 == 0), overwriting the returned value. [source:raw]
    // CALL: Second virtual dispatch: call sub-object vtable method at offset 0x38 (vtable+56) with the coerced value from the previous step. [field:*(this+0x30):0x00000038, source:raw]
    // RETURN: Return the result of the second virtual dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   sub = this[12];
    //   if (sub != 0) {
    //       r = sub->vtbl[0x3C / 4](a2);
    //       r = (a2 == 0);
    //       return sub->vtbl[0x38 / 4](r);
    //   }
    //   // else: return uninitialized result (undefined behavior)
    // UNRESOLVED: Sub-object class and both vtable method identities (slots 14 and 15) are unknown; only the vtable offsets 0x38 and 0x3C are evidenced.
    // UNRESOLVED: Argument a2 semantics unknown; the low-byte coercion (a2 == 0) suggests a boolean or option flag, not confirmed.
    // UNRESOLVED: Null path returns an uninitialized result (this[12] null); cannot determine caller intent.
    // UNRESOLVED: Whether the coercion replaces the method return value or a boolean derived from it is ambiguous from the decompilation alone.
}
