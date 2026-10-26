// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D1B0
// Canonical corpus name: SessionPhaseDispatchWithCascadeChecks
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionPhaseDispatchWithCascadeChecks_0040d1b0.c

void UnknownObject::SessionPhaseDispatchWithCascadeChecks()
{
    // Dispatches an action (a2) with modifier flag a3 through a three-stage cascade of lookup objects on the session dispatcher (this): menu-slot dispatch, callback lookup, then resource lookup. On the first successful match it records the matched object via SimpleSetter, sets the dispatch flag at this+0x2C, decodes the session phase, transitions the game action state machine, and - when a3 is set - fires the matched object's vtable slot at +16. Returns 0 when a2 is null or no cascade stage matches; otherwise returns 1.
    // GUARD: __thiscall entry: result is initialized to 0; when a2 is 0 the function returns 0 immediately. [abi:lead]
    // GUARD: First cascade stage: when MenuSlotActionDispatch(*(this+0x18), a2, a3) succeeds, record the matched object with SimpleSetter(this, *(this+0x18)). [callee:0x0040A910, callee:0x0040CDD0, field:this:0x00000018]
    // GUARD: Second cascade stage: else when LookupWithOptionalCallback(*(this+0x1C), a2, a3) succeeds, record the matched object with SimpleSetter(this, *(this+0x1C)). [callee:0x0040B450, callee:0x0040CDD0, field:this:0x0000001C]
    // GUARD: Third cascade stage: else when ResourceLookupWithOptionalVTableDispatch(*(this+0x20), a2, a3) succeeds, record it with SimpleSetter(this, *(this+0x20)); if that lookup fails return 0. [callee:0x0040BCD0, callee:0x0040CDD0, field:this:0x00000020]
    // ASSIGNMENT: On any successful dispatch set the flag byte at this+0x2C to 1. [field:this:0x0000002C]
    // CALL: Decode the current session phase via SessionPhaseDecode(), then transition the game action state machine with GameActionStateMachine(decodedPhase, 0). [callee:0x0040CD60, callee:0x0040CDE0]
    // GUARD: When a3 is set and the matched object pointer at this+0x8 is nonzero, invoke its virtual slot: (*(*(*(this+0x8)+0)+16))(*(this+0x8)). [field:this:0x00000008, field:*(this+0x8):0x00000000, field:*(*(this+0x8)+0x0):0x00000010]
    // RETURN: Return 1 after a successful cascade dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   int SessionPhaseDispatchWithCascadeChecks(int this, int a2, char a3) {
    //     int result = 0;
    //     if (a2) {
    //       if (MenuSlotActionDispatch(*(int*)(this + 24), a2, a3)) SimpleSetter(this, *(int*)(this + 24));
    //       else if (LookupWithOptionalCallback(*(int*)(this + 28), a2, a3)) SimpleSetter(this, *(int*)(this + 28));
    //       else {
    //         if (!ResourceLookupWithOptionalVTableDispatch(*(int*)(this + 32), a2, a3)) return 0;
    //         SimpleSetter(this, *(int*)(this + 32));
    //       }
    //       *(char*)(this + 44) = 1;
    //       GameActionStateMachine(SessionPhaseDecode(), 0);
    //       if (a3) { int v8 = *(int*)(this + 8); if (v8) (*(void(**)(int))(*(int*)v8 + 16))(v8); }
    //       return 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Raw decompilation passes an uninitialized ecx-aliased register to SessionPhaseDecode(); the intended no-argument call is a DERIVED reading.
    // UNRESOLVED: Semantics of the three cascade objects (menu slot / callback / resource) and the exact meaning of a2 and a3 depend on external session-dispatch callers.
    // UNRESOLVED: The matched-object pointer stored into this+0x8 is read back only when a3 is set; its lifecycle is external.
}
