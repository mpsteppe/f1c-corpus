// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409F40
// Canonical corpus name: VTableDispatchChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchChain_00409f40.c

void UnknownObject::vtableDispatchChain()
{
    // Two-stage virtual dispatch: calls vtable slot at +0x18 on this; if the result is non-null, calls vtable slot at byte offset +28 on that result and returns it, otherwise returns the null result. Structural twin of sub_404D20 (00404d20); subsystem 'ai'.
    // CALL: result = (this->vtable[0x18])(this) — first virtual call, slot at +0x18. [field:obj:0x00000024, field:this:0x00000000, source:raw]
    // GUARD: if (result) proceed to second dispatch. [source:raw]
    // CALL: return (result->vtable[28])(result) — second virtual call, slot at byte offset +28 on the returned object. [source:raw]
    // RETURN: return result — null when the first dispatch returned null (chain short-circuits). [source:raw]
    // UNRESOLVED: Second dispatch reads vtable slot at byte offset +28; only the first slot (+0x18) has a dedicated field evidence entry in the packet.
}
