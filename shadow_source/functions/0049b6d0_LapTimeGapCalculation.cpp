// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B6D0
// Canonical corpus name: LapTimeGapCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LapTimeGapCalculation_0049b6d0.c

void UnknownObject::LapTimeGapCalculation()
{
    // Computes the time and lap gap between two vehicles a1 and a2, writing a float time gap to a3 and a lap-count gap to a4. Reads each vehicle's lap counter at +0x403C and its time via sub_4F01B0 on the sub-object at +12. Equal lap counts produce the signed time gap v9 - v7; one-lap wrap with v9 < v7 produces flt_5EA408 - v7 + v9; otherwise the integer lap difference is output with a decrement when v9 < v7. Returns 0 when a gap is computed, 1 when inputs are null or a1 is behind on lap count. ABI lead name Lap_Time_Gap_Calculation.
    // ASSIGNMENT: Initialize result to 1 before any computation. [source:raw]
    // GUARD: If a1 or a2 is null, skip the computation and return 1. [source:raw]
    // ASSIGNMENT: Read the lap counter at a1 + 16444 (0x403C) into v5. [field:this:0x0000403C, source:raw]
    // CALL: Call sub_4F01B0(a1 + 12) and store the returned time value in v9. [callee:0x004F01B0, source:raw]
    // ASSIGNMENT: Read the lap counter at a2 + 16444 (0x403C) into v6. [field:this:0x0000403C, source:raw]
    // CALL: Call sub_4F01B0(a2 + 12) and store the returned time value in v7. [callee:0x004F01B0, source:raw]
    // ASSIGNMENT: Initialize the outputs: *a3 = 0.0 and *a4 = 0. [source:raw]
    // CALCULATION: If the lap counters are equal (v5 == v6), set result = 0 and write the signed time gap v9 - v7 to *a3. [source:raw]
    // GUARD: Else if v5 <= v6, a1 is behind by lap count: return 1. [source:raw]
    // CALCULATION: Else if a1 is exactly one lap ahead (v6 + 1 == v5) and its time is smaller (v9 < v7), set result = 0 and write the wrap-around gap flt_5EA408 - v7 + v9 to *a3. [global:0x005EA408, source:raw]
    // CALCULATION: Otherwise set v8 = v5 - v6 and result = 0; if v9 < v7 decrement v8, then write the lap gap v8 to *a4. [source:raw]
    // RETURN: Return result: 0 when a gap was computed, 1 when inputs are null or a1 is behind by lap count. [source:raw]

    // Conservative worker pseudocode:
    //   int LapTimeGapCalculation(int a1, int a2, float *a3, int *a4) {
    //       int result = 1;
    //       if (a1 && a2) {
    //           int v5 = *(int *)(a1 + 0x403C);
    //           float v9 = sub_4F01B0(a1 + 12);
    //           int v6 = *(int *)(a2 + 0x403C);
    //           double v7 = sub_4F01B0(a2 + 12);
    //           *a3 = 0.0f;
    //           *a4 = 0;
    //           if (v5 == v6) {
    //               result = 0;
    //               *a3 = v9 - v7;
    //           } else if (v5 <= v6) {
    //               return 1;
    //           } else if (v6 + 1 == v5 && v9 < v7) {
    //               result = 0;
    //               *a3 = flt_5EA408 - v7 + v9;
    //           } else {
    //               int v8 = v5 - v6;
    //               result = 0;
    //               if (v9 < v7)
    //                   --v8;
    //               *a4 = v8;
    //           }
    //       }
    //       return result;
    //   }
    // UNRESOLVED: The sub-object offsets a1 + 12 and a2 + 12 passed to sub_4F01B0 appear only in the raw source; the packet field table lists only offset 0x403C, so the time sub-object offset has no dedicated field evidence reference.
    // UNRESOLVED: sub_4F01B0's contract (reading a per-vehicle time at the given offset) is taken from its name and the existing analysis; the packet provides only the call sites.
    // UNRESOLVED: flt_5EA408 is read as a session maximum-time constant for the wrap-around case; the packet evidence is a plain global read.
    // UNRESOLVED: The vehicle object types behind a1 and a2 are not evidenced; the owner is unknown.
}
