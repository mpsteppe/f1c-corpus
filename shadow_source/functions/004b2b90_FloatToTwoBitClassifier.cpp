// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B90
// Canonical corpus name: FloatThresholdClassification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatThresholdClassification_004b2b90.c

void UnknownObject::FloatToTwoBitClassifier()
{
    // Classifies a float input a2 into one of four 2-bit categories written into bits [1:0] of the dword at this + 15. Ranges: a2 <= 0.75 maps to 0, 0.75 < a2 < 0.85000002 maps to 1, 0.85000002 <= a2 < 0.94999999 maps to 2, a2 >= 0.94999999 maps to 3. Bits outside [1:0] are preserved via the 0xFFFFFFFC mask. Called by VectorToShort3Conversion (004B2C80).
    // GUARD: Outer guard: when a2 <= 0.75, clear the classification bits (this+15 &= 0xFFFFFFFC) and skip the higher classes. [source:raw]
    // ASSIGNMENT: Low class: set bits to 1 via (this+15 & 0xFFFFFFFC) | 1 when 0.75 < a2 < 0.85000002. [source:raw, field:this:0x0000000F]
    // GUARD: Mid guard: when a2 >= 0.85000002, distinguish the upper two classes. [source:raw]
    // GUARD: High guard: when a2 >= 0.94999999, select class 3. [source:raw]
    // ASSIGNMENT: Highest class: set bits to 3 via this+15 |= 3u. [source:raw, field:this:0x0000000F]
    // ASSIGNMENT: Mid class: set bits to 2 via (this+15 & 0xFFFFFFFC) | 2 when 0.85000002 <= a2 < 0.94999999. [source:raw, field:this:0x0000000F]
    // ASSIGNMENT: Clear path: this+15 &= 0xFFFFFFFC when a2 <= 0.75. [source:raw, field:this:0x0000000F]
    // RETURN: Void function; no explicit return value. [function:0x004B2B90, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4B2B90(int this, float a2) {
    //     if (a2 > 0.75) {
    //       if (a2 >= 0.85000002) {
    //         if (a2 >= 0.94999999)
    //           *(_DWORD *)(this + 15) |= 3u;
    //         else
    //           *(_DWORD *)(this + 15) = *(_DWORD *)(this + 15) & 0xFFFFFFFC | 2;
    //       } else {
    //         *(_DWORD *)(this + 15) = *(_DWORD *)(this + 15) & 0xFFFFFFFC | 1;
    //       }
    //     } else {
    //       *(_DWORD *)(this + 15) &= 0xFFFFFFFC;
    //     }
    //   }
    // UNRESOLVED: The three float globals flt_59E7FC, flt_59E908, flt_59EE8C are listed by packet facts as read but appear nowhere in the raw decompiled source; the thresholds are compiled-in literals here.
    // UNRESOLVED: Meaning of the two-bit classification and the layout of the dword at this + 15 depend on the caller's (unknown) object type.
}
