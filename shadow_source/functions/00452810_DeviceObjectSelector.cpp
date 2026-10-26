// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00452810
// Canonical corpus name: DeviceObjectSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DeviceObjectSelector_00452810.c

void UnknownObject::DeviceObjectSelector()
{
    // Device/config object selector: matches the input integer a2 against the stored values of 36 pre-registered global config objects (collision, audio, rendering constants) and, on a match, stores the address of the matched global into this[8] (this+0x20). Sets this[0] to 2 (matched) or 0 (no match), reinitializes the this+1 sub-structure via SwapAndReinit, clears this[7] (this+0x1C), and returns 0 on a match or -1 when no global matched. Called by ShortComputation_30a0 (0x004530A0).
    // ASSIGNMENT: Preset this[0] = 2 as the matched status before dispatch. [field:this:0x00000000, source:raw]
    // GUARD: Compare a2 in sequence against the stored values of 36 pre-registered global objects (dword_7CA490, dword_7CCA44, dword_7CA3E8, dword_7CA470, dword_7CD198, dword_7CA3C8, dword_7CCBB0, dword_7CCFB0, dword_7CCA6C, dword_7CCF80, dword_7CCCB0, dword_7CCA7C, dword_7CD148, dword_7CCFDC, dword_7CD108, dword_7CD188, dword_7CA3B8, dword_7CC9BC, dword_7CD158, dword_7CA50C, dword_7CD0F8, dword_7CA438, dword_7CA448, dword_7CCBF4, dword_7CA3A8, dword_7CA480, dword_7CC9EC, dword_7CA3D8, dword_7CCF90, dword_7CCF60, dword_7CCF70, dword_7CCFA0, dword_7CA4F8, dword_7CA57C, dword_7CA410, dword_7CA4D0) and stop at the first equal one. [global:0x007CA3A8, global:0x007CA3B8, global:0x007CA3C8, global:0x007CA3D8, global:0x007CA3E8, global:0x007CA410, global:0x007CA438, global:0x007CA448, global:0x007CA470, global:0x007CA480, global:0x007CA490, global:0x007CA4D0, global:0x007CA4F8, global:0x007CA50C, global:0x007CA57C, global:0x007CC9BC, global:0x007CC9EC, global:0x007CCA44, global:0x007CCA6C, global:0x007CCA7C, global:0x007CCBB0, global:0x007CCBF4, global:0x007CCCB0, global:0x007CCF60, global:0x007CCF70, global:0x007CCF80, global:0x007CCF90, global:0x007CCFA0, global:0x007CCFB0, global:0x007CCFDC, global:0x007CD0F8, global:0x007CD108, global:0x007CD148, global:0x007CD158, global:0x007CD188, global:0x007CD198, source:raw]
    // ASSIGNMENT: On a match, store the address of the matched global into this[8] (this+0x20). [field:this:0x00000020, source:raw]
    // GUARD: If no global value equals a2, set this[8] = 0, clear this[0] to 0 and set v3 = -1. [field:this:0x00000000, field:this:0x00000020, source:raw]
    // CALL: Reinitialize the sub-structure at this + 1 via SwapAndReinit(this + 1, 89, 0). [callee:0x00452740, source:raw]
    // ASSIGNMENT: Clear this[7] (the dword at this+0x1C) to 0 after the sub-structure reinit. [field:this:0x0000001C, source:raw]
    // RETURN: Return v3: 0 when a global matched, -1 when the input a2 matched none of the 38 registered objects. [source:raw]
    // CALL: This selector is invoked by ShortComputation_30a0 (0x004530A0), which feeds the selected config/device pointer into the device initialization flow. [caller:0x004530A0]

    // Conservative worker pseudocode:
    //   int sub_452810(int *this, int a2) {
    //     int result = 0;
    //     *this = 2;
    //     if      (a2 == dword_7CA490)  this[8] = (int)&dword_7CA490;
    //     else if (a2 == dword_7CCA44)  this[8] = (int)&dword_7CCA44;
    //     /* ... 36 more equal-check branches selecting &dword_7Cxxxx ... * /
    //     else if (a2 == dword_7CA4D0)  this[8] = (int)&dword_7CA4D0;
    //     else {
    //       this[8] = 0;
    //       *this = 0;
    //       result = -1;
    //     }
    //     SwapAndReinit(this + 1, 89, 0);
    //     this[7] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The semantic role of each of the 38 global config objects (the legacy analysis names them collision/audio/rendering constants) and the meaning of the SwapAndReinit size argument 89 are not documented by this function.
    // UNRESOLVED: The identity and layout of the this object (with status at 0x0, cleared dword at 0x1C and selected pointer at 0x20) is not evidenced beyond this function.
}
