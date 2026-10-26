// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487260
// Canonical corpus name: sub_487260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_487260_00487260.c

void UnknownObject::DispatchCheckedStateToVtable64()
{
    // State-dependent dispatcher. Selects a mode with ShortComputation_6720(this) and switches on its result using the jump table jpt_48726F. Each case conditionally forwards the boolean a2 (checked state) through the object's vtable slot +0x40 as an integer parameter: case 0 passes 1 when a2 set, case 1 passes 0 when a2 clear, case 2 passes 3 when a2 set, case 3 passes 2 when a2 clear. Case 4 first reads a byte field via ByteFieldGetterAt100; when that is zero it branches on RangeCheck to pass either (a2 != 0) or (a2 != 0) + 2. Default returns the selector unchanged.
    // CALL: v2 = ShortComputation_6720(this): compute the widget mode/state used as the switch selector [callee:0x00486720, source:raw]
    // STATE_TRANSITION: Switch on v2 via jump table jpt_48726F with cases 0, 1, 2, 3, 4 and a default [global:0x00487310, source:raw]
    // GUARD: Case 0: execute only when a2 is non-zero [source:raw]
    // CALL: Case 0: call vtable slot +0x40 on v3 with literal parameter 1 [source:raw]
    // GUARD: Case 1: execute only when a2 is zero [source:raw]
    // CALL: Case 1: call vtable slot +0x40 on v3 with literal parameter 0 [source:raw]
    // GUARD: Case 2: execute only when a2 is non-zero [source:raw]
    // CALL: Case 2: call vtable slot +0x40 on v3 with literal parameter 3 [source:raw]
    // GUARD: Case 3: execute only when a2 is zero [source:raw]
    // CALL: Case 3: call vtable slot +0x40 on v3 with literal parameter 2 [source:raw]
    // CALL: Case 4: read the byte field at the object via ByteFieldGetterAt100(v3) [callee:0x00486710, source:raw]
    // GUARD: Case 4: continue only when the ByteFieldGetterAt100 result is zero [source:raw]
    // CALL: Case 4: RangeCheck() determines which sub-branch to take (result compared to zero) [callee:0x00487740, source:raw]
    // GUARD: Case 4: when RangeCheck returned zero, dispatch with parameter (a2 != 0); otherwise dispatch with parameter (a2 != 0) + 2 [source:raw]
    // CALL: Case 4: call vtable slot +0x40 on v5 with the selected parameter [source:raw]
    // RETURN: Default case returns v2 unchanged; all other cases fall through to return v2 (the parameter passed to the vtable call is captured in LOBYTE(v2)) [source:raw]

    // Conservative worker pseudocode:
    //   v2 = ShortComputation_6720(this);
    //   switch (v2) {
    //     case 0: if (a2) dispatch(v3, 1); break;
    //     case 1: if (!a2) dispatch(v3, 0); break;
    //     case 2: if (a2) dispatch(v3, 3); break;
    //     case 3: if (!a2) dispatch(v3, 2); break;
    //     case 4:
    //       if (ByteFieldGetterAt100(v3) == 0) {
    //           int p = (a2 != 0);
    //           if (RangeCheck() != 0) p += 2;
    //           dispatch(v5, p);
    //       }
    //       break;
    //     default: return v2;
    //   }
    //   return v2;
    // UNRESOLVED: v3 and v5 are register-held object pointers left uninitialized by the decompiler; their identity and the concrete class behind vtable slot +0x40 are unknown
    // UNRESOLVED: The vtable slot +0x40 target and the semantics of parameters 0-3 are not identified by the packet
    // UNRESOLVED: Purpose of the RangeCheck branch in case 4 (parameter + 2) is undocumented
    // UNRESOLVED: jpt_48726F is referenced as the switch jump table but its contents are not part of the packet
    // UNRESOLVED: Called by UIRadioCheckStateChangeHandler (00487460), VirtualDispatchWithErrorHandling (00487530), sub_487D70, and UtilityFunction_7e10
}
