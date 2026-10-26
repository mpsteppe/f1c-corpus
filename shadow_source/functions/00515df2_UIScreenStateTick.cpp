// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515DF2
// Canonical corpus name: UIScreenStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScreenStateMachine_00515df2.c

void UnknownObject::UIScreenStateTick()
{
    // Ticks a UI screen state machine. Early-returns state code 2 when the exiting flag at +0x19D is already set. Otherwise obtains the current state code via an indirect vtable call through the dispatch struct at +0x190 (function pointer at +0x194) and returns it. On state 1 it either runs TextureSurfaceValidator (0x005159F5) and clears the pending flag at +0x1A0, or, when the flag at +0x19C is clear, issues a screen transition request by writing ID 34 to the screen object (+0x14) and invoking the screen vtable method at *a1, then calls VtableDelegateDispatch (0x00515DB8). On state 2 it sets the exiting flag at +0x19D to 1 and either clamps the target at +0x84 down to the selection at +0x7C, or, when the dispatch-struct byte at +0x1E1 is set, issues a transition request by writing ID 58 to the screen object (+0x14) and invoking the screen vtable method at *a1.
    // GUARD: Early-exit guard: dereference a1[99] (state flags base at this+0x18C) into v1; when the flag byte v1[17] (this+0x19D) is non-zero, return state code 2 without further processing. [function:0x00515DF2, field:this:0x0000018C, field:this:0x0000019D, source:raw]
    // CALL: State getter via vtable: invoke the __cdecl function pointer at a1[100]+4 (dispatch struct at this+0x190, method pointer at this+0x194) with a1 as the single argument; store the returned state code in v3. [function:0x00515DF2, field:this:0x00000000, field:this:0x00000190, field:this:0x00000194, source:raw]
    // CALL: State 1 path, pending flag set: call TextureSurfaceValidator (0x005159F5) with (int)a1 to validate/refresh the screen's texture surfaces. [function:0x00515DF2, callee:0x005159F5, source:raw]
    // ASSIGNMENT: Clear the pending flag v1[20] at this+0x1A0 to 0 after texture validation completes. [function:0x00515DF2, field:this:0x0000018C, field:this:0x000001A0, source:raw]
    // ASSIGNMENT: State 1 path, pending flag clear and v1[16] (this+0x19C) clear: write screen transition ID 34 to the screen object field at *a1 + 20 (obj+0x14). [function:0x00515DF2, field:obj:0x00000014, field:this:0x0000019C, source:raw]
    // CALL: Request the screen change: invoke the __cdecl vtable method at *a1 (obj+0x0) with a1, sending the transition ID written to obj+0x14. [function:0x00515DF2, field:obj:0x00000000, field:obj:0x00000014, source:raw]
    // CALL: State 1 path, pending flag clear: call VtableDelegateDispatch (0x00515DB8) with (int)a1 to dispatch screen input/update to the active delegate. [function:0x00515DF2, callee:0x00515DB8, source:raw]
    // STATE_TRANSITION: State 2 path: record the exiting transition by setting v1[17] at this+0x19D to 1. [function:0x00515DF2, field:this:0x0000018C, field:this:0x0000019D, source:raw]
    // GUARD: Guard 0: v4 = (v1[20] == 0) on the pending flag at this+0x1A0; when the flag was clear take the clamp branch, otherwise the special transition branch. [function:0x00515DF2, guard:0, field:this:0x0000018C, field:this:0x000001A0, source:raw]
    // ASSIGNMENT: State 2, pending flag was clear: read the selection value v5 from a1[31] (this+0x7C) and clamp the target at a1[33] (this+0x84) down to v5 when the target is larger. [function:0x00515DF2, field:this:0x0000007C, field:this:0x00000084, source:raw]
    // ASSIGNMENT: State 2, pending flag was set and the dispatch-struct byte at a1[100]+81 (this+0x1E1) is non-zero: write screen transition ID 58 to the screen object field at *a1 + 20 (obj+0x14). [function:0x00515DF2, field:obj:0x00000014, field:this:0x000001E1, source:raw]
    // CALL: Request the screen change: invoke the __cdecl vtable method at *a1 (obj+0x0) with a1, sending the transition ID 58 written to obj+0x14. [function:0x00515DF2, field:obj:0x00000000, field:obj:0x00000014, source:raw]
    // RETURN: Return v3, the state code obtained from the state getter, to the caller. [function:0x00515DF2, source:raw]

    // Conservative worker pseudocode:
    //   int UIScreenStateTick(unsigned int *sm) {
    //     unsigned char *flags = (unsigned char *)sm[99];            // this+0x18C
    //     if (flags[17]) return 2;                                    // this+0x19D exiting
    //     int state = (*(int (__cdecl **)(unsigned int *))(sm[100] + 4))(sm); // this+0x190/+0x194
    //     if (state == 1) {
    //       if (flags[20]) {                                          // this+0x1A0
    //         TextureSurfaceValidator((int)sm);
    //         flags[20] = 0;
    //       } else {
    //         if (!flags[16]) {                                      // this+0x19C
    //           *(int *)(*sm + 20) = 34;                              // obj+0x14
    //           (*(void (__cdecl **)(unsigned int *))*sm)(sm);
    //         }
    //         VtableDelegateDispatch((int)sm);
    //       }
    //     } else if (state == 2) {
    //       int cleared = (flags[20] == 0);
    //       flags[17] = 1;
    //       if (cleared) {
    //         int sel = sm[31];                                       // this+0x7C
    //         if (sm[33] > sel) sm[33] = sel;                         // this+0x84
    //       } else if (*(unsigned char *)(sm[100] + 81)) {             // this+0x1E1
    //         *(int *)(*sm + 20) = 58;                                 // obj+0x14
    //         (*(void (__cdecl **)(unsigned int *))*sm)(sm);
    //       }
    //     }
    //     return state;
    //   }
    // UNRESOLVED: The getter at a1[100]+4 returns a state code treated as 1 and 2 here; the exact state enum (and any other possible values) is not evidenced in this packet.
    // UNRESOLVED: The screen object behind *a1 and the semantics of the transition IDs 34 and 58 are not identified by the packet.
    // UNRESOLVED: The meaning of the flag v1[16] at this+0x19C (screen-not-ready gate) is inferred, not evidenced.
    // UNRESOLVED: The dispatch-struct byte at a1[100]+81 (this+0x1E1) and the special transition path it gates are unexplained by the packet.
    // UNRESOLVED: The connection between the pending flag at +0x1A0 and the transition IDs 34/58 is DERIVED from control flow, not a packet fact.
}
