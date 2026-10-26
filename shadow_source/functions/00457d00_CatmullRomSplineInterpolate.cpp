// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457D00
// Canonical corpus name: CubicSplineInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CubicSplineInterpolation_00457d00.c

void UnknownObject::CatmullRomSplineInterpolate()
{
    // Evaluates a Catmull-Rom-style cubic spline at parameter a2 over a keyframe array reached through this[0] (28-byte per-keyframe stride: 3 position components plus tangent/control and time fields). Reads the keyframe count minus 3 from this[1] as the number of segments and the total time span from this[2]. When a2 is negative the first keyframe is copied and this[3] is set to 0.0; when a2 is at or beyond this[2] the last keyframe is copied; otherwise the segment containing a2 is found, the parameter is normalized inside it, four basis polynomials are evaluated, and interpolated X/Y/Z are written to this[4]/this[5]/this[6] with this[3] = a2. Returns a pointer to this[4].
    // GUARD: Lower clamp: when a2 < 0.0 the function skips interpolation and copies the first keyframe (array base + 28 bytes) into the X/Y/Z outputs this[4..6] and writes this[3] = 0.0. [field:this:0x00000000, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // GUARD: Upper clamp: when a2 >= this[2] the function copies the last keyframe (array base + 28 * (this[1] - 2)) into this[4..6] and writes this[3] = this[2]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // LOOP: Segment scan over the 28-byte-stride keyframe array (base this[0]): starting at offset 52 (the second keyframe time), advance 28 bytes per keyframe while the current keyframe's time is still above a2 or the next keyframe's time is at or below a2; the scan is bounded by the segment count this[1] - 3. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: Normalized parameter v17 = (a2 - keyframe[v6].time) / (keyframe[v6+1].time - keyframe[v6].time); the segment times live inside the keyframe array, whose second keyframe occupies offsets 0x1C/0x20/0x24/0x34 relative to the array base. [field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024, field:obj:0x00000034, field:this:0x00000000, source:raw]
    // CALCULATION: Catmull-Rom basis polynomials from v17: v20 = 3*v17^2 - 5*v17^3 + 2, v19 = 4*v17^2 - 3*v17^3 + v17, v18 = v17^3 - v17^2, v14 = 2*v17^2 - v17^3 - v17; the floating-point coefficients are supplied by read-only globals 0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E7EC and 0x0059E800. [global:0x0059E440, global:0x0059E450, global:0x0059E46C, global:0x0059E478, global:0x0059E7EC, global:0x0059E800, source:raw]
    // CALCULATION: Interpolated X = 0.5 * (kf[i].X * v14 + kf[i+1].X * v20 + kf[i+2].X * v19 + kf[i+3].X * v18), written to this[4]. [field:this:0x00000010, source:raw]
    // CALCULATION: Interpolated Y = 0.5 * (kf[i].Y * v14 + kf[i+1].Y * v20 + kf[i+2].Y * v19 + kf[i+3].Y * v18), written to this[5]. [field:this:0x00000014, source:raw]
    // CALCULATION: Interpolated Z = 0.5 * (kf[i].Z * v14 + kf[i+1].Z * v20 + kf[i+2].Z * v19 + kf[i+3].Z * v18), written to this[6]. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Store the evaluated parameter this[3] = a2 so the output slots this[3..6] hold time plus interpolated X/Y/Z. [field:this:0x0000000C, source:raw]
    // RETURN: Return a pointer to this[4] (the interpolated X output slot). [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 < 0.0) { copy first keyframe -> out X/Y/Z; this[3] = 0.0; }
    //   else if (a2 < this[2]) {
    //     n = this[1] - 3; i = 0;
    //     while (t[i] > a2 || t[i+1] <= a2) { i++; if (i >= n) break; }
    //     t = (a2 - t[i]) / (t[i+1] - t[i]);
    //     w0 = 2*t^2 - t^3 - t; w1 = 3*t^2 - 5*t^3 + 2; w2 = 4*t^2 - 3*t^3 + t; w3 = t^3 - t^2;
    //     outX = 0.5*(kf[i].X*w0 + kf[i+1].X*w1 + kf[i+2].X*w2 + kf[i+3].X*w3);
    //     outY = 0.5*(kf[i].Y*w0 + kf[i+1].Y*w1 + kf[i+2].Y*w2 + kf[i+3].Y*w3);
    //     outZ = 0.5*(kf[i].Z*w0 + kf[i+1].Z*w1 + kf[i+2].Z*w2 + kf[i+3].Z*w3);
    //     this[3] = a2;
    //   }
    //   else { copy last keyframe -> out X/Y/Z; this[3] = this[2]; }
    //   return this + 4;
    // UNRESOLVED: The obj-base fields 0x1C/0x20/0x24/0x34 are extracted relative to a separate obj base but the raw source reaches the keyframe array only through this[0]; the packet does not prove obj and this[0] point to the same array, so the identification of these four fields with the second keyframe (offsets 28..52) is an interpretation from the existing analysis fill, not independently evidenced.
    // UNRESOLVED: The read-only globals (0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E7EC, 0x0059E800) are not individually mapped to the floating-point literals in the raw source (3.0, 5.0, 4.0, 2.0, 0.5, 0.0); the fill labels 0x0059E440 as a zero threshold at DERIVED trust, which is not adopted here.
    // UNRESOLVED: The legacy ABI label 'FAIL_457d00' (abi:lead) carries no semantic information and conflicts with the evident spline behavior; the proposed name follows the existing analysis fill (CatmullRomSplineInterpolate).
}
