// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046DC60
// Canonical corpus name: sub_46DC60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46DC60_0046dc60.c

void UnknownObject::SessionStateHandler()
{
    // Session/game-mode initialization handler with two branches. When the session manager reports a valid state it runs state checks and returns 1 on any failure; otherwise it initializes the session-type flag, and for a formation-lap race session (state 5) builds a UI object and arms force-feedback, then validates session data and stores 4 into the session init state on success.
    // CALL: Invoke VirtualCallOnDAT008ac4c4_8d80, the scene-array access helper tied to byte_8AC494. [callee:0x004C8D80, global:0x008AC494]
    // GUARD: Session-state branch: when SessionStateCheckWrapper(dword_7CD25C) is nonzero the session manager is in a valid state. [callee:0x00461DB0, global:0x007CD25C]
    // GUARD: Within the valid-state branch, fail when StateCheckWrapper(dword_7CD25C) is zero or an indirect __thiscall state check on dword_7CD25C returns zero. [callee:0x00461DC0, global:0x007CD25C, source:raw]
    // RETURN: Return 1 when the current session state fails validation. [source:raw]
    // CALL: Else (no valid session state): call sub_42D210 with the address of dword_7C569C and 1 to initialize the session-type flag. [callee:0x0042D210, global:0x007C569C]
    // GUARD: When dword_7C56A4 equals 5 (race session) and byte_7CEBC4 (formation-lap flag) is set, perform UI and force-feedback setup. [global:0x007C56A4, global:0x007CEBC4]
    // CALL: Invoke the virtual method at offset 0x1C of the object held at this+0x40 (this[16]) with argument 30 to obtain a UI object. [field:this:0x00000040, field:*(this+0x40):0x0000001C]
    // CALL: If the obtained UI object is non-null, pass it together with the a2 parameter to sub_46BF10. [callee:0x0046BF10]
    // CALL: Call sub_4D2450 with dword_8ACEE0 (force-feedback base) to arm feedback. [callee:0x004D2450, global:0x008ACEE0]
    // CALL: Run ShortComputation_7250 on this[16] with 1. [callee:0x00497250, field:this:0x00000040]
    // GUARD: When sub_4A0590 on unk_7CE24C (session data object) returns nonzero, fail with return 1. [callee:0x004A0590, global:0x007CE24C]
    // ASSIGNMENT: On the success path store 4 into dword_5CC9E8 (session init state). [global:0x005CC9E8]
    // RETURN: Return 0 after successful initialization. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_46DC60(void **this, char a2) {
    //     VirtualCallOnDAT008ac4c4_8d80();
    //     if (SessionStateCheckWrapper(dword_7CD25C)) {
    //       if (!StateCheckWrapper(dword_7CD25C) || !indirectStateCheck(dword_7CD25C))
    //         return 1;
    //     } else {
    //       sub_42D210(&dword_7C569C, 1);
    //       if (dword_7C56A4 == 5 && byte_7CEBC4) {
    //         void *ui = (*vtable(this[16]) + 28)(this[16], 30);
    //         if (ui) sub_46BF10(ui, a2);
    //         sub_4D2450(dword_8ACEE0);
    //       }
    //       ShortComputation_7250(this[16], 1);
    //       if (sub_4A0590(&unk_7CE24C))
    //         return 1;
    //     }
    //     dword_5CC9E8 = 4;
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the indirect __thiscall state check on dword_7CD25C is not resolved to a named callee.
    // UNRESOLVED: Meaning of the a2 parameter is unknown; it is only forwarded to sub_46BF10.
    // UNRESOLVED: Semantics of the session state values (5, 1, 0) and of dword_5CC9E8 = 4 come from the existing fill, not proven here.
}
