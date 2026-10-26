// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C060
// Canonical corpus name: CallWrapper_c060
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallWrapper_c060_0055c060.c

void UnknownObject::CallWrapper_c060()
{
    // Thin forwarding wrapper: indexes an element out of `this` using the value stored at this[0] as an index base (`this[*(int*)this + 2]`), then forwards it together with two globals (dword_8B78A0, dword_8B8F28) to sub_555E50, returning that callee's result. `a2` is unused. The element offset is a runtime-derived index, not a compile-time field offset.
    // CALCULATION: Compute the element address `this[*this + 2]`: read the dword at this+0x0 as an index/offset, add 2, and dereference that element of the `this` array. [field:this:0x00000000, source:raw]
    // CALL: Forward the call to sub_555E50 with three arguments: global dword_8B78A0, the element read from this[*this + 2], and global dword_8B8F28. [source:raw]
    // RETURN: Return the result produced by sub_555E50 unchanged. [source:raw]
    // CALL: Used by StateFlagComputation (0x004F9B30) and VidMan_Enter (0x004FA000) as a call-through; the wrapper's two globals make it likely a registered callback/indirection point. [caller:0x004F9B30, caller:0x004FA000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55C060(void *this, int a2) {
    //     return sub_555E50(dword_8B78A0, this[*(int *)this + 2], (void *)dword_8B8F28);
    //   }
    // UNRESOLVED: Identity and semantics of sub_555E50: not listed as a packet callee and absent from allowed evidence refs, so only its invocation is known.
    // UNRESOLVED: Meaning of the two globals dword_8B78A0 and dword_8B8F28 (first and third arguments) is not present in the packet.
    // UNRESOLVED: The object layout behind the `this[*this + 2]` element access is unknown; the index is computed at runtime from this[0].
    // UNRESOLVED: Parameter a2 is unused; its purpose is unknown.
}
