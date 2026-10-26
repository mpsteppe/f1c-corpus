// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487830
// Canonical corpus name: ConditionalStateMachineDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalStateMachineDispatch_00487830.c

void UnknownObject::ConditionalStateMachineDispatch()
{
    // State-machine dispatch with boolean input. Computes a state 0-4 via ShortComputation_6720 and switch-dispatches: states 0-1 fire a vtable+64 __thiscall with argument 2/3 only when the boolean a2 is non-zero; states 2-3 fire with argument 0/1 only when a2 is zero. Case 4 guards on ByteFieldGetterAt100 and uses ShortComputation_7720 to pick between two __stdcall vtable+64 argument mappings. The default path returns the raw state without any virtual call.
    // CALCULATION: Compute the switch selector v2 = ShortComputation_6720(this), yielding the current state 0-4. [source:raw, callee:0x00486720]
    // GUARD: Switch on the state via the jump table jpt_48783E; the default case returns the state value unchanged with no vtable call. [source:raw, global:0x004878E0]
    // GUARD: Case 0: fire only when a2 is non-zero; when a2 != 0 call the vtable+64 __thiscall with argument 2 and store its result as the return value, otherwise skip with return value left as a2. [source:raw]
    // GUARD: Case 1: fire only when a2 is non-zero; when a2 != 0 call the vtable+64 __thiscall with argument 3 and store its result, otherwise skip with return value left as a2. [source:raw]
    // GUARD: Case 2: fire only when a2 is zero; when a2 == 0 call the vtable+64 __thiscall with argument 0 and store its result, otherwise skip. [source:raw]
    // GUARD: Case 3: fire only when a2 is zero; when a2 == 0 call the vtable+64 __thiscall with argument 1 and store its result, otherwise skip. [source:raw]
    // GUARD: Case 4: when ByteFieldGetterAt100(v3) is non-zero the whole case is skipped. When zero, branch on !ShortComputation_7720(v4): if true call vtable+64 __stdcall with argument (a2 != 0 ? 2 : 0), else call with argument (2 * (a2 != 0) + 1). [source:raw, callee:0x00486710, callee:0x00487720]
    // RETURN: Return v2: the raw state on the default path, a2 on a skipped guarded case, or the stored result of the last executed vtable+64 call. [source:raw]

    // Conservative worker pseudocode:
    //   char ConditionalStateMachineDispatch(int this, char a2) {
    //     int v2 = ShortComputation_6720(this);
    //     switch (v2) {
    //       case 0: if (a2) v2 = (*(int (__thiscall **)(void*, int))(*(void**)v3 + 64))(v3, 2); break;
    //       case 1: if (a2) v2 = (*(int (__thiscall **)(void*, int))(*(void**)v3 + 64))(v3, 3); break;
    //       case 2: if (!a2) v2 = (*(int (__thiscall **)(void*, void*))(*(void**)v3 + 64))(v3, 0); break;
    //       case 3: if (!a2) v2 = (*(int (__thiscall **)(void*, int))(*(void**)v3 + 64))(v3, 1); break;
    //       case 4:
    //         if (!ByteFieldGetterAt100(v3)) {
    //           bool v5 = !ShortComputation_7720(v4);
    //           int* v7 = *v6;
    //           if (v5) v2 = (*(int (__stdcall **)(int))(v7 + 64))(a2 != 0 ? 2 : 0);
    //           else    v2 = (*(int (__stdcall **)(int))(v7 + 64))(2 * (a2 != 0) + 1);
    //         }
    //         break;
    //       default: return v2;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: v3, v4 and v6 are uninitialized receiver/pointer variables in the decompiled source; the object whose vtable+64 is invoked is not statically proven to be `this`.
    // UNRESOLVED: Case 4 dispatches through a separate __stdcall vtable call (via v7) rather than the __thiscall used in cases 0-3; receiver and vtable identity unknown.
    // UNRESOLVED: The vtable+64 virtual method has no name; the meaning of its numeric arguments (0-3) is unknown.
    // UNRESOLVED: Semantics of the state byte read by ByteFieldGetterAt100 and the secondary condition computed by ShortComputation_7720 are unknown.
}
