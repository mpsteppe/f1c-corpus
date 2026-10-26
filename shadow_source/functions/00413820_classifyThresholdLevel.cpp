// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00413820
// Canonical corpus name: sub_413820
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_413820_00413820.c

void UnknownObject::classifyThresholdLevel()
{
    // Cascading threshold classifier invoked by SoundEventDispatcher (0x00411E90). When both a2 and a4 are zero, widens integer a3 to double and selects one of 17 bucket indices (1..17) through a chain of double comparisons against read-only threshold constants; final buckets 14..17 are decided by integer comparisons a3 >= 75, a3 >= 110 and a3 >= 999. Writes the bucket index to a1+8 and the result of sub_414180(0) to a1+12, returning 1. When the active-guard fails (a2 or a4 non-zero) the function does not touch a1 and returns -1.
    // GUARD: Active guard: when a2 != 0 or a4 != 0 the classifier is skipped; result stays -1 and neither a1+8 nor a1+12 is written. [function:0x00413820, source:raw]
    // CALCULATION: Widen integer a3 to double v5 for the subsequent float threshold comparisons. [source:raw]
    // GUARD: Cascading double-threshold chain over v5 selects bucket index v6 in 1..17. The thresholds are read from the 13 read-only double globals dbl_59E420, dbl_59E788, dbl_59E790, dbl_59E798, dbl_59E7A0, dbl_59E7A8, dbl_59E7B0, dbl_59E7B8, dbl_59E7C0, dbl_59E7C8, dbl_59E7D0, dbl_59E7D8, dbl_59E7E0. After the last double threshold, the remaining buckets 14..17 are chosen by integer checks on a3: a3 >= 75, a3 >= 110, and a3 >= 999. [global:0x0059E420, global:0x0059E788, global:0x0059E790, global:0x0059E798, global:0x0059E7A0, global:0x0059E7A8, global:0x0059E7B0, global:0x0059E7B8, global:0x0059E7C0, global:0x0059E7C8, global:0x0059E7D0, global:0x0059E7D8, global:0x0059E7E0, source:raw]
    // ASSIGNMENT: Write the selected bucket index v6 to *(a1 + 8) (this+0x8). [field:this:0x00000008, source:raw]
    // CALL: Call sub_414180 with argument 0 and store its returned value at *(a1 + 12) (this+0xC). [callee:0x00414180, field:this:0x0000000C, source:raw]
    // RETURN: Return 1 on successful classification; otherwise the pre-set result -1 is returned. [source:raw]

    // Conservative worker pseudocode:
    //   result = -1;
    //   if (a2 == 0 && a4 == 0) {
    //     v5 = (double)a3;
    //     if (v5 >= 1.0) { if (v5 >= 3.0) { if (v5 >= 4.0) { if (v5 >= 7.5) { if (v5 >= 12.5) { if (v5 >= 17.5) { if (v5 >= 22.5) { if (v5 >= 27.5) { if (v5 >= 32.5) { if (v5 >= 37.5) { if (v5 >= 42.5) { if (v5 >= 47.5) { if (v5 >= 52.5) { v6 = a3 >= 75 ? (a3 >= 110 ? (a3 >= 999 ? 17 : 16) : 15) : 14; } else v6 = 13; } else v6 = 12; } else v6 = 11; } else v6 = 10; } else v6 = 9; } else v6 = 8; } else v6 = 7; } else v6 = 6; } else v6 = 5; } else v6 = 4; } else v6 = 3; } else v6 = 2; } else v6 = 1;
    //     *(a1 + 8) = v6;
    //     *(a1 + 12) = sub_414180(0);
    //     return 1;
    //   }
    //   return result;
    // UNRESOLVED: The semantic meaning of the 17 bucket indices and of the input value a3 being classified is not established by the packet.
    // UNRESOLVED: The purpose of the value returned by sub_414180(0) stored at a1+12 is unknown.
    // UNRESOLVED: Which threshold global holds which numeric double value is not deterministically tied by the packet (the raw decompilation inlines the literals).
    // UNRESOLVED: The owner object is unknown; the function is used as a per-event handler by SoundEventDispatcher (0x00411E90).
}
