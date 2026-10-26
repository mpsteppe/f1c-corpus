// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477FA0
// Canonical corpus name: PollingStateChangeDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PollingStateChangeDetection_00477fa0.c

void UnknownObject::PollingStateChangeDetection()
{
    // Polls two monitored state sources and dispatches a notification when either cached value changes. First source is fetched through a virtual accessor on the this+0x40 sub-object (slot +0x1C, argument 3); its value is extracted via GuardedAccessor (0x0048D360) and compared against the cached value at this+0x11C. Second source is fetched through the global dispatch interface dword_7CD8C0 (slot +0x1C, command 18) and compared against the cached value at this+0x120. When a cache differs, it is updated and a virtual notification callback (vtable slot +0xA0) is invoked on this. Always returns 0.
    // CALL: Fetch first monitored state object through virtual accessor at slot +0x1C of the this+0x40 sub-object, passing argument 3. [field:this:0x00000040, field:*(this+0x40):0x0000001C, source:raw]
    // GUARD: Guard: proceed only if the fetched state object is non-null and the cached value this+0x11C differs from GuardedAccessor(state). [field:this:0x0000011C, callee:0x0048D360, source:raw]
    // CALL: Call GuardedAccessor on the first state object to extract its integer value. [callee:0x0048D360, source:raw]
    // ASSIGNMENT: Update cached first state value this+0x11C to the extracted value. [field:this:0x0000011C, source:raw]
    // CALL: Invoke virtual notification callback at vtable slot +0xA0 on this to signal the first state changed. [field:this:0x00000000, field:obj:0x000000A0, source:raw]
    // CALL: Fetch second monitored state object through virtual accessor at slot +0x1C of the dword_7CD8C0 dispatch interface, passing command 18. [global:0x007CD8C0, source:raw]
    // GUARD: Guard: proceed only if the second state object is non-null and the cached value this+0x120 differs from the value read at offset 372 of that object. [field:this:0x00000120, source:raw]
    // ASSIGNMENT: Update cached second state value this+0x120 to the value read at offset 372 of the second state object. [field:this:0x00000120, source:raw]
    // CALL: Invoke virtual notification callback at vtable slot +0xA0 on this to signal the second state changed. [field:this:0x00000000, field:obj:0x000000A0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int PollingStateChangeDetection(void **this) {
    //     int *s1 = (*(int (**)(void *, int))(*this[16] + 28))(this[16], 3);
    //     if (s1 && this[71] != (void *)GuardedAccessor(s1)) {
    //       this[71] = (void *)GuardedAccessor(s1);
    //       (*(void (**)(void **))this[0][40])(this);
    //     }
    //     int *s2 = (*(int (**)(int, int))(*(void **)dword_7CD8C0 + 28))(dword_7CD8C0, 18);
    //     if (s2 && this[72] != *(void **)(s2 + 372)) {
    //       this[72] = *(void **)(s2 + 372);
    //       (*(void (**)(void **))this[0][40])(this);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Identity and type of the first state object produced by the virtual accessor on the this+0x40 sub-object are unknown.
    // UNRESOLVED: dword_7CD8C0 interface identity and the object type returned by command 18 are unknown.
    // UNRESOLVED: Semantics of the second monitored value at offset 372 of the second state object are unknown; the offset is not a named packet field.
    // UNRESOLVED: Purpose and behaviour of the shared virtual notification callback at slot +0xA0 are unknown.
}
