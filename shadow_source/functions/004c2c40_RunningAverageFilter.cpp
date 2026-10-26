// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2C40
// Canonical corpus name: RunningAverageFilter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RunningAverageFilter_004c2c40.c

void UnknownObject::RunningAverageFilter()
{
    // Computes an incremental running average of input value a2 using the sample count at this+0x28 as the weighting denominator and storing the result at this+0x44. A count of zero is a no-op; a count of one stores the input directly; otherwise the weighted average ((count-1)*old_average + input)/count is computed and stored. The result is then clamped: a compare-flag branch writes 1065353216 (1.0f) and an over-range branch writes 1102053376 (22.0f). Called by sub_4C29F0.
    // GUARD: If the sample count at this+0x28 is zero the function does nothing. [field:this:0x00000028, source:raw]
    // GUARD: If the sample count at this+0x28 equals 1 the average at this+0x44 is initialized directly from the input. [field:this:0x00000028, source:raw]
    // ASSIGNMENT: First-sample path: store input a2 as a float at this+0x44. [field:this:0x00000044, source:raw]
    // CALCULATION: Compute weighted sum and average: ((count-1)*old_average at this+0x44 + input) / count at this+0x28. [field:this:0x00000028, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Store the computed average at this+0x44. [field:this:0x00000044, source:raw]
    // GUARD: If the floating-point compare flags (v6|v7) indicate the unordered/below-range case, write 1065353216 (1.0f) to this+0x44. [field:this:0x00000044, source:raw]
    // GUARD: Else if the computed average exceeds 22.0, write 1102053376 (22.0f) to this+0x44. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Clamp path: store the lower clamp 1065353216 (1.0f) or the upper clamp 1102053376 (22.0f) at this+0x44. [field:this:0x00000044, source:raw]

    // Conservative worker pseudocode:
    //   void RunningAverageFilter(int this, int a2) {
    //     int count = *(int*)(this + 40);        // this+0x28
    //     if (count == 0) return;
    //     if (count == 1) { *(float*)(this + 68) = (float)a2; return; }   // this+0x44
    //     float avg = ((float)(count - 1) * *(float*)(this + 68) + (float)a2) / (float)count;
    //     *(float*)(this + 68) = avg;
    //     if (compare_flags_unordered) *(DWORD*)(this + 68) = 1065353216;        // 1.0f
    //     else if (avg > 22.0)          *(DWORD*)(this + 68) = 1102053376;       // 22.0f
    //   }
    // UNRESOLVED: Globals flt_59E43C and flt_59E85C are read by this function per the deterministic facts but do not appear as symbols in the raw source; the source uses the literals 1065353216/1102053376 and 22.0 directly.
    // UNRESOLVED: The v6|v7 compare-flag test is a decompiler artifact of an FPU compare; its exact comparison is not visible in the raw source text.
}
