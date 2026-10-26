// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543540
// Canonical corpus name: sub_543540
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_543540_00543540.c

void UnknownObject::ClipRectToSurfaceBounds()
{
    // Thiscall rectangle-clipping helper. Clips two coordinate/extent pairs (a2 with a4, a3 with a5) against surface bounds read from this[7] (this+0x1C) and this[8] (this+0x20). For each axis, a negative coordinate is folded into the extent and zeroed, then the extent is clamped so coordinate + extent stays within the surface bound. Returns a5 (which doubles as the second output pointer). Called from render clipping paths.
    // GUARD: If *a2 < 0, fold the negative offset into the first-axis extent and zero the coordinate: *a4 += *a2; *a2 = 0. [source:raw, function:0x00543540]
    // CALCULATION: Read the first-axis surface bound: v5 = this[7] at this+0x1C. [field:this:0x0000001C, source:raw]
    // GUARD: If *a2 + *a4 exceeds the first-axis bound, clamp the extent: *a4 = v5 - *a2. [source:raw]
    // CALCULATION: Clamp the first-axis extent to at most the surface bound: v6 = *a4; if (*a4 >= this[7]) v6 = this[7]; *a4 = v6. [field:this:0x0000001C, source:raw]
    // GUARD: If *a3 < 0, fold the negative offset into the second-axis extent and zero the coordinate: *a5 += *a3; *a3 = 0. [source:raw]
    // CALCULATION: Read the second-axis surface bound: v8 = this[8] at this+0x20. [field:this:0x00000020, source:raw]
    // GUARD: If *a3 + *a5 exceeds the second-axis bound, clamp the extent: *a5 = v8 - *a3. [source:raw]
    // CALCULATION: Clamp the second-axis extent to at most the surface bound: v9 = this[8]; if (*a5 >= v9) *a5 = v9 else *a5 = *a5. [field:this:0x00000020, source:raw]
    // RETURN: Return a5 (the second output pointer, kept in eax as result). [source:raw]

    // Conservative worker pseudocode:
    //   if (*a2 < 0) { *a4 += *a2; *a2 = 0; }
    //   if (*a2 + *a4 > this->bound0) *a4 = this->bound0 - *a2;
    //   if (*a4 >= this->bound0) *a4 = this->bound0;
    //   if (*a3 < 0) { *a5 += *a3; *a3 = 0; }
    //   if (*a3 + *a5 > this->bound1) *a5 = this->bound1 - *a3;
    //   if (*a5 >= this->bound1) *a5 = this->bound1;
    //   return a5;
    // UNRESOLVED: Exact role mapping of the four pointer parameters (which are x/y/width/height, and which pair is source vs destination) is not established by the packet; the two-axis clipping pattern is the confirmed shape.
    // UNRESOLVED: this+0x1C / this+0x20 as surface width/height is carried over from the existing fill (DERIVED), not independently proven here.
    // UNRESOLVED: The else branch '*a5 = *a5' is a no-op left by the decompiler; it is preserved but contributes nothing.
    // UNRESOLVED: Returning a5 while also using it as an output pointer is unusual; caller contract unknown.
}
