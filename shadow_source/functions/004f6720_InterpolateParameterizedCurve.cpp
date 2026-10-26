// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6720
// Canonical corpus name: ParameterizedCurveInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParameterizedCurveInterpolation_004f6720.c

void UnknownObject::InterpolateParameterizedCurve()
{
    // Piecewise-linear curve interpolation over a table of (x, y1, y2) triple points stored at this+0x6C8 with a 24-byte stride, the point count being a dword at this+0x6C4. Finds the segment bracketing input a2, linearly interpolates both y outputs into a3 and a4, clamps the case where the second output is below the first by averaging both to their midpoint, and handles the empty-table (writes 0.0 into both outputs) and single-point (copies the point's y1/y2 directly) degenerate cases. Called per-frame by brake-temperature, aero and suspension physics.
    // GUARD: Read the curve point count dword at this+0x6C4. If it is not greater than zero, write 0.0 into both output doubles (a3 and a4) and return without interpolating. [field:this:0x000006C4, function:0x004F6720, source:raw]
    // GUARD: If the point count equals 1, copy the single point's y1 double (this+0x6D0/0x6D4) into a3 and its y2 double (this+0x6D8/0x6DC) into a4, then return without interpolating. [field:this:0x000006D0, field:this:0x000006D4, field:this:0x000006D8, field:this:0x000006DC, source:raw]
    // LOOP: Scan forward through the triple-point table (first x-coordinate at this+0x6C8, 24-byte stride) from index 0, advancing while the current point's x is not greater than a2; stop at the first point whose x exceeds a2, bounded by the point count. [field:this:0x000006C8, source:raw]
    // CALCULATION: Clamp the interpolation bracket: when a2 precedes the first point use points 0 and 1; when the scan passed the last point use the final two points; otherwise bracket points v5-1 and v5. [field:this:0x000006C8, source:raw]
    // CALCULATION: Compute the blend factor v9 = (a2 - x_lo) / (x_hi - x_lo) from the x-coordinates of the bracketing points. [field:this:0x000006C8, source:raw]
    // CALCULATION: Linearly interpolate both outputs from the bracketing points' y1/y2 doubles: a3 = y1_lo + v9 * (y1_hi - y1_lo) and a4 = y2_lo + v9 * (y2_hi - y2_lo). [field:this:0x000006D0, field:this:0x000006D4, field:this:0x000006D8, field:this:0x000006DC, source:raw]
    // GUARD: If the interpolated second value (a4) is below the first (a3), clamp both outputs to their midpoint (v10 + a3) * 0.5 using the HalfStep constant dbl_59E880 and write the average into both a3 and a4. [global:0x0059E880, source:raw]
    // RETURN: Return void; results are delivered through the a3/a4 output pointers. Invoked per-frame by BrakeTemperatureFadeModel (0x00430A50), sub_43C250 and SuspensionAndWheelPhysics (0x004E5F60). [caller:0x00430A50, caller:0x0043C250, caller:0x004E5F60, function:0x004F6720]

    // Conservative worker pseudocode:
    //   count = *((int*)this + 0x6C4/4);
    //   if (count <= 0) { *a3 = 0.0; *a4 = 0.0; return; }
    //   if (count == 1) { *a3 = points[0].y1; *a4 = points[0].y2; return; }
    //   i = 0; while (i < count && a2 >= points[i].x) i++;
    //   if (i == 0)        { lo = 0;       hi = 1; }
    //   else if (i >= count) { lo = count-2; hi = count-1; }
    //   else              { lo = i-1;     hi = i; }
    //   t = (a2 - points[lo].x) / (points[hi].x - points[lo].x);
    //   y1 = points[lo].y1 + t * (points[hi].y1 - points[lo].y1);
    //   y2 = points[lo].y2 + t * (points[hi].y2 - points[lo].y2);
    //   if (y2 < y1) { y1 = y2 = (y1 + y2) * 0.5; }
    //   *a3 = y1; *a4 = y2;
    // UNRESOLVED: Owner identity is unknown: the LEGACY ABI lead 'Parameterized_Curve_Interpolation' names the routine itself, not a class; no confirmed owner symbol is present in the packet.
    // UNRESOLVED: dbl_59E880 (0x0059E880) is attributed as the 0.5 HalfStep constant used in the midpoint clamp; the attribution is DERIVED from the existing analysis because the constant is folded into the decompiled arithmetic and the global does not appear by name in the raw source text.
}
