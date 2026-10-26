// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C770
// Canonical corpus name: sub_49C770
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C770_0049c770.c

void UnknownObject::FormatFuelLevelWithUnit()
{
    // Formats a fuel quantity (read from dword_7C54E0 + 14724) together with a unit suffix into the caller-supplied buffer a1, selecting the unit string either by copying the literal at byte_5CCEA0 or by computing it through CRTFtol + StringFormatWithBufferOverflowCheck with the format at off_5CCEA4, depending on a multiplier read from dword_7C54E0 + 13384. When the CostDisplayMode flag dword_7D0450 equals 1 the value is rendered as US gallons (v8 * 0.26417205, one decimal), otherwise as a rounded integer. Returns 0.
    // ASSIGNMENT: Read the fuel quantity v8 = *(float *)(dword_7C54E0 + 14724). [global:0x007C54E0, source:raw]
    // ASSIGNMENT: Read the unit conversion multiplier v2 = *(float *)(dword_7C54E0 + 13384). [global:0x007C54E0, source:raw]
    // GUARD: if (v2 <= 0.0): multiplier is not positive, so the unit string is copied literally from byte_5CCEA0 instead of being computed. [global:0x005CCEA0, source:raw]
    // LOOP: Copy bytes of byte_5CCEA0 into the local v9 buffer one at a time until the NUL terminator is copied (do/while on v5 = byte_5CCEA0[v4]). [global:0x005CCEA0, source:raw]
    // CALL: Multiplier path: v3 = CRTFtol(v2 * v8); StringFormatWithBufferOverflowCheck(v9, &off_5CCEA4, v3) formats the computed unit value into v9 using the format string at off_5CCEA4. [callee:0x00587BDC, callee:0x0058815F, global:0x005CCEA4, source:raw]
    // GUARD: if (dword_7D0450 == 1): CostDisplayMode selects the gallon (imperial) rendering path. [global:0x007D0450, source:raw]
    // CALL: Gallon path: StringFormatWithBufferOverflowCheck(a1, " %.1f%s", v8 * 0.26417205, v9) writes the converted value (liters to gallons factor 0.26417205, one decimal) followed by the unit suffix v9 into a1. [callee:0x0058815F, global:0x005CCE98, source:raw]
    // CALL: Default path: v7 = CRTFtol(v8 + 0.5) rounds the quantity, then StringFormatWithBufferOverflowCheck(a1, " %d%s", v7, v9) writes the integer followed by the unit suffix v9 into a1. [callee:0x00587BDC, callee:0x0058815F, global:0x005CCE90, source:raw]
    // RETURN: Return 0 after formatting. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatFuelLevelWithUnit(char *out, int out_len) {
    //     float v8 = *(float *)(dword_7C54E0 + 14724);
    //     double v2 = *(float *)(dword_7C54E0 + 13384);
    //     char v9[16];
    //     if (v2 <= 0.0) {
    //       int v4 = 0; char v5;
    //       do { v5 = byte_5CCEA0[v4]; v9[v4++] = v5; } while (v5);
    //     } else {
    //       int v3 = CRTFtol(v2 * v8);
    //       StringFormatWithBufferOverflowCheck(v9, &off_5CCEA4, v3);
    //     }
    //     if (dword_7D0450 == 1)
    //       StringFormatWithBufferOverflowCheck(out, " %.1f%s", v8 * 0.26417205, v9);
    //     else {
    //       int v7 = CRTFtol(v8 + 0.5);
    //       StringFormatWithBufferOverflowCheck(out, " %d%s", v7, v9);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The two format-string globals aDS_3 (0x005CCE90) and a1fS_0 (0x005CCE98) are rendered by the decompiler as the literals " %d%s" and " %.1f%s"; their exact pairing with the two branches is inferred from the IDA constant naming (dS vs 1fS) and is DERIVED, not confirmed.
    // UNRESOLVED: The float constants at 0x0059E440, 0x0059E880 and 0x005ACAF8 are referenced by the function but do not appear directly in the decompiled text; they are presumed to be the inlined immediates (0.0 threshold, 0.5 rounding, 0.26417205 conversion factor) but the per-constant mapping is unknown.
    // UNRESOLVED: off_5CCEA4 is passed by address as a format string; its content is not visible here, so the shape of the computed unit suffix is unknown.
    // UNRESOLVED: The struct base dword_7C54E0 is shared with unrelated state; offsets 14724 and 13384 have no confirmed field names in this packet.
}
