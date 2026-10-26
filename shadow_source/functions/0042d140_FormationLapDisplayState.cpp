// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D140
// Canonical corpus name: sub_42D140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42D140_0042d140.c

void UnknownObject::FormationLapDisplayState()
{
    // Formation-lap / pit-timer display state setter. Stores the new state argument into this[3] (offset 0xC) when it changes. For new states greater than 2 it calls ArithmeticComparison_2e20 on dword_8ACEE0. On a server session (dword_7C569C == 5), dispatches on the stored state through the jpt_42D17C jump table: for state 3, when byte_7CEC78 (pit-timer visible) is set, it resolves the 'Begin Formation' string via BinarySearchInStringTable into byte_5EC4CC and renders it with TextLineWrappingAndRendering; states 0, 2, 3 and 4 all then run a loop from 0 to dword_5C329C calling sub_4C6B60(0) per iteration. Called from LapCompletion, PitTimerStateInit, PitTimer and Steward_Restart.
    // ASSIGNMENT: Initialise the return value to the new state argument (result = a2). [function:0x0042D140, source:raw]
    // GUARD: State-change guard: proceed only when the stored display state at this[3] (offset 0xC) differs from the new state a2; otherwise return the unchanged result. [field:this:0x0000000C, function:0x0042D140, source:raw]
    // STATE_TRANSITION: Store the new display state a2 into this[3] (offset 0xC). [field:this:0x0000000C, source:raw]
    // CALL: When the new state a2 is greater than 2, call ArithmeticComparison_2e20(&dword_8ACEE0) and use its return value as result. [callee:0x004D2E20, global:0x008ACEE0, source:raw]
    // GUARD: Server-session guard: the state-machine body runs only while dword_7C569C equals 5. [global:0x007C569C, source:raw]
    // STATE_TRANSITION: Dispatch on the stored state this[3] through the switch jump table jpt_42D17C: cases 0, 2 and 4 jump to the vehicle loop; case 3 falls through message setup into the same loop; the default case returns immediately. [field:this:0x0000000C, global:0x0042D1F4, function:0x0042D140, source:raw]
    // GUARD: For state 3: proceed to message setup only when byte_7CEC78 (pit-timer visible flag) is non-zero. [global:0x007CEC78, source:raw]
    // CALL: Resolve the 'Begin Formation' message: BinarySearchInStringTable(byte_5EC4C0, aBeginFormation, byte_5EC4CC); when it returns non-zero, copy aBeginFormation into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005C35B4, global:0x005EC4CC, source:raw]
    // LOOP: String copy loop: copy aBeginFormation byte-by-byte into byte_5EC4CC until the NUL terminator has been copied. [global:0x005C35B4, global:0x005EC4CC, source:raw]
    // CALL: Render the prepared message buffer: TextLineWrappingAndRendering(byte_5EC4CC, 3, 16909060). [callee:0x0045BD10, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Seed the loop count and result from the vehicle count: result = dword_5C329C. [global:0x005C329C, source:raw]
    // LOOP: Per-vehicle loop: for i from 0 to dword_5C329C, call sub_4C6B60(0) each iteration and re-read dword_5C329C into result. [callee:0x004C6B60, global:0x005C329C, source:raw]
    // RETURN: Return result on every exit path: state unchanged, default switch case, and fall-through after the per-vehicle loop. [function:0x0042D140, source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   if (this[3] != a2) {
    //       this[3] = a2;
    //       if (a2 > 2) result = ArithmeticComparison_2e20(&dword_8ACEE0);
    //       if (dword_7C569C == 5) {
    //           switch (this[3]) {
    //           case 0: case 2: case 4: goto vehicle_loop;
    //           case 3:
    //               if (byte_7CEC78) {
    //                   if (BinarySearchInStringTable(byte_5EC4C0, aBeginFormation, byte_5EC4CC))
    //                       copy aBeginFormation into byte_5EC4CC until NUL;
    //                   TextLineWrappingAndRendering(byte_5EC4CC, 3, 16909060);
    //               }
    //           vehicle_loop:
    //               result = dword_5C329C;
    //               for (i = 0; i < dword_5C329C; ++i) { sub_4C6B60(0); result = dword_5C329C; }
    //               break;
    //           default: return result;
    //           }
    //       }
    //   }
    //   return result;
    // UNRESOLVED: dword_7C54F0 and dword_7CD204 are listed as read globals but do not appear in the raw decompiled body; they are likely read indirectly by sub_4C6B60 or unused here (existing analysis names them VehiclePtrArray [FACT] and ResourceDispatch_007CD204 [DERIVED]).
    // UNRESOLVED: The semantics of ArithmeticComparison_2e20(&dword_8ACEE0) and why it runs only for states greater than 2 are unconfirmed.
    // UNRESOLVED: The meaning of the individual display states 0-4 and of the per-vehicle call sub_4C6B60(0) is DERIVED from existing analysis, not confirmed by the packet.
    // UNRESOLVED: The literals 3 (render mode) and 16909060 (color/value) in the TextLineWrappingAndRendering call have no confirmed semantics in the packet.
    // UNRESOLVED: The owning object class behind this (only this[3] known) is unknown.
}
