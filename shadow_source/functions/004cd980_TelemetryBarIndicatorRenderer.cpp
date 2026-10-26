// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CD980
// Canonical corpus name: TelemetryBarIndicatorRenderer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TelemetryBarIndicatorRenderer_004cd980.c

void UnknownObject::TelemetryBarIndicatorRenderer()
{
    // Telemetry bar-indicator particle renderer. When the scoring gate dword_8AB6E4 equals 2 it delegates via Delegation(&dword_8AB6EC), otherwise it falls back to the session-time global dbl_8AFEA0 as the reference time. Iterates the particle array at this+0x68 (count at this+0x64), computing two fade values per particle from its lifetime fields (particle+8 start, particle+12 end, particle+96/particle+100 fade thresholds) scaled by this+0x40. Particles whose reference time falls inside the lifetime window with any non-zero fade are drawn by writing four pixel attributes to the particle's texture; particles outside the window are removed from the array via ArrayElementRemoval.
    // GUARD: If dword_8AB6E4 == 2, call Delegation(&dword_8AB6EC) to obtain the reference data; otherwise use dbl_8AFEA0 as the reference time. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, callee:0x004B9CE0, source:raw]
    // CALCULATION: Read the particle count from this+0x64 and the particle array pointer from this+0x68; prepare the loop counter. [field:this:0x00000064, field:this:0x00000068, source:raw]
    // LOOP: Iterate each particle block: v4 = array entry at this+0x68 + 4*index; continue while the index is below the count at this+0x64. [field:this:0x00000068, field:this:0x00000064, source:raw]
    // CALCULATION: Compute normalized lifetime progress v8 = (reference time - particle start field) * scale factor from this+0x40. [field:this:0x00000040, source:raw]
    // CALCULATION: Fade A: when v8 is below the particle's first fade threshold, compute the fade attribute as (threshold - v8) * 254 packed into a 24-bit color (shifted left by 24 plus 0xFFFFFF); otherwise keep it zero. [source:raw]
    // CALCULATION: Fade B: when v8 is below the particle's second fade threshold, compute the second fade attribute similarly from (threshold - v8) * 254; otherwise keep it zero. [source:raw]
    // GUARD: If the reference time is inside the particle's lifetime window (>= start and <= end) and either fade attribute is non-zero, render the particle. [source:raw]
    // CALL: PixelAttributeWriteToTexture(texture, 0, fadeA), (texture, 1, fadeB), (texture, 2, fadeB), (texture, 3, fadeA): write four pixel attributes to the particle's texture using the two computed fades. [callee:0x00558DC0, source:raw]
    // CALL: ArrayElementRemoval(this, v4): remove the particle from the array when it falls outside the lifetime window or both fades are zero; rewind the index so the shifted element is re-examined. [callee:0x004CB5A0, source:raw]
    // RETURN: Return the final loop index (last value of the counter). [function:0x004CD980, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8AB6E4 == 2) Delegation(&dword_8AB6EC);
    //   else ref_time = dbl_8AFEA0;
    //   for (i = 0; i < *(int*)(this + 100); ) {
    //       p = *(float**)(*(int*)(this + 104) + 4*i);
    //       v8 = (ref_time - p[2]) * *(float*)(this + 64);
    //       fadeA = (v8 < p[25]) ? ((int)((p[25] - v8) * 254.0) << 24) + 0xFFFFFF : 0;
    //       fadeB = (v8 < p[24]) ? ((int)((p[24] - v8) * 254.0) << 24) + 0xFFFFFF : 0;
    //       if (ref_time <= p[3] && ref_time >= p[2] && (fadeA || fadeB)) {
    //           PixelAttributeWriteToTexture(*(int*)p, 0, fadeA);
    //           PixelAttributeWriteToTexture(*(int*)p, 1, fadeB);
    //           PixelAttributeWriteToTexture(*(int*)p, 2, fadeB);
    //           PixelAttributeWriteToTexture(*(int*)p, 3, fadeA);
    //           i++;
    //       } else {
    //           ArrayElementRemoval(this, p);
    //       }
    //   }
    // UNRESOLVED: flt_5ACEC4 is listed as a global in the packet but is not read anywhere in this function's raw source; it appears only in the existing_analysis fill, so it is recorded here.
    // UNRESOLVED: The per-particle fields p[2], p[3], p[24], p[25] have no packet field evidence entries; their dword indices come only from the raw source.
    // UNRESOLVED: The exact pixel-attribute semantics (color vs. alpha/fade channel) of the four PixelAttributeWriteToTexture writes are inferred from the call name and the two computed fades.
}
