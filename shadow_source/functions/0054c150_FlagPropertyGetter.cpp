// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C150
// Canonical corpus name: FlagPropertyGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagPropertyGetter_0054c150.c

void UnknownObject::FlagPropertyGetter()
{
    // Flag-gated field reader. When the flag bits of a3 indicate the 0x800 mode (BYTE1(a3) & 8) and the node's flags word at this+0x3C has the 0x800 bit set, the stored value at this+0x234 is written to *a2. Otherwise, when BYTE1(a3) has the 0x1000-mode bit (BYTE1(a3) & 0x10) and the high byte of the flags word at this+0x3C has its bit set, the stored value at this+0x238 is written to *a2. Returns the value read, or a3 unchanged when no branch matched.
    // ASSIGNMENT: Initialize result to a3 as the default return value before any flag check. [source:raw]
    // GUARD: Guard on the 0x800-mode flag (BYTE1(a3) & 8) being set and the flags word at this[15] (+0x3C) having the 0x800 bit set. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Read the stored value at this[141] (+0x234) and write it into *a2. [field:this:0x00000234, source:raw]
    // GUARD: Else-if guard on the 0x1000-mode flag (BYTE1(a3) & 0x10) being set. [source:raw]
    // GUARD: Nested guard reading the flags word at this[15] (+0x3C) and testing BYTE1(result) bit 0x10 (the 0x1000 bit of the flags word). [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Write the stored value at this[142] (+0x238) into *a2 and set result to the output pointer. [field:this:0x00000238, source:raw]
    // RETURN: Return the read value for the 0x800 mode, the output pointer after the 0x1000-mode write, or a3 unchanged when neither flag matched. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_54C150(_DWORD* this, _DWORD* a2, _DWORD* a3) {
    //     _DWORD* result = a3;
    //     if ((BYTE1(a3) & 8) && (this[15] & 0x800)) {
    //       result = (_DWORD*)this[141];
    //       *a2 = result;
    //     } else if (BYTE1(a3) & 0x10) {
    //       result = (_DWORD*)this[15];
    //       if (BYTE1(result) & 0x10) {
    //         result = a2;
    //         *a2 = this[142];
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the flag word at this+0x3C and the stored values at this+0x234 / this+0x238 depends on the callers; the caller expectations were not analyzed.
    // UNRESOLVED: The setter counterpart (RenderFlagSetter_0054c110) was not analyzed; it may explain the flag/value pairing.
    // UNRESOLVED: Callers LapSplitTimeEvent (004bc390), NetworkMessageReceiveAndDispatch (004c7ca0), TimerFrameRateThrottle (004d3740), and TrackTemperatureDisplay (004d37b0) were not analyzed.
}
