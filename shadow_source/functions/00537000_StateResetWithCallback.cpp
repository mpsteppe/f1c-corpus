// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537000
// Canonical corpus name: StateResetWithCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateResetWithCallback_00537000.c

void UnknownObject::StateResetWithCallback()
{
    // State-machine lifecycle reset that zeroes state slots, restores a saved backup value, and optionally re-registers a callback. Before resetting, a caller-supplied output pointer a3 receives the current callback-result slot a1[15]. The current state code *a1 selects optional callbacks: states 4/5 invoke a function pointer stored at a2+36 with arguments (*(a2+40), a1[3]); state 6 calls IndirectCallViaVTable0x24(a1[1], a2). After resetting, if the stored callback pointer a1[14] is non-null it is invoked with (0, 0, 0) and its result is stored back into a1[15] and at a2+48, becoming the return value. On the per-frame path.
    // GUARD: If a3 is non-null, write the current callback-result slot a1[15] into *a3. [source:raw]
    // GUARD: If the state code *a1 is 4 or 5, invoke the function pointer stored at a2+36 with arguments (*(_DWORD*)(a2+40), a1[3]). [source:raw]
    // GUARD: If the state code *a1 is 6, call IndirectCallViaVTable0x24(a1[1], a2) — an indirect call through vtable offset 0x24. [callee:0x00539F60, source:raw]
    // ASSIGNMENT: Save the backup value a1[10] (field this+0x28), reset the state to 0, then restore the saved value into both a1[13] and a1[12] (field this+0x30 written by the restore). [field:this:0x00000028, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Zero the state slots a1[7] and a1[8]. [source:raw]
    // CALL: Load the callback pointer a1[14]; if non-null, call it with (0, 0, 0) and store the returned pointer into a1[15] and at a2+48. [source:raw]
    // RETURN: Return the (possibly updated) callback pointer; returns null when no callback was stored. [source:raw]
    // CALL: Called by ArithmeticComparison_5620 (0x00535620), sub_5357E0 (0x005357E0), MultiBlockAllocator (0x00537070) and TripleVTableCall (0x00537CE0) to reset state and refresh the callback. [caller:0x00535620, caller:0x005357E0, caller:0x00537070, caller:0x00537CE0, source:raw]

    // Conservative worker pseudocode:
    //   funcptr StateResetWithCallback(DWORD* self, int ctx, DWORD* out) {
    //     if (out) *out = self[15];
    //     if (self[0] == 4 || self[0] == 5) (*(fn**)(ctx + 36))(*(DWORD*)(ctx + 40), self[3]);
    //     if (self[0] == 6) IndirectCallViaVTable0x24(self[1], ctx);
    //     DWORD saved = self[10];
    //     self[0] = 0; self[13] = saved; self[12] = saved;
    //     funcptr result = (funcptr)self[14];
    //     self[7] = 0; self[8] = 0;
    //     if (result) { result = result(0, 0, 0); self[15] = (DWORD)result; *(DWORD*)(ctx + 48) = (DWORD)result; }
    //     return result;
    //   }
    // UNRESOLVED: Packet records a read of field this+0x24, but the decompiled text's state checks read *a1 (offset 0x00); the 0x24 access is not visible in the raw C and its purpose is unknown.
    // UNRESOLVED: Identity and class of the object a1 and of the context a2 are unknown; the a2+36 / a2+40 / a2+48 slot layout is a caller-owned structure.
    // UNRESOLVED: Meaning of the state codes 4/5/6 and of the backup-restore fields a1[10]/a1[12]/a1[13] depends on the owning state machine.
}
