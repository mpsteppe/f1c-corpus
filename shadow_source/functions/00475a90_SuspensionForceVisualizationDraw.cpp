// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475A90
// Canonical corpus name: sub_475A90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_475A90_00475a90.c

void UnknownObject::SuspensionForceVisualizationDraw()
{
    // Draws a 2D suspension-force visualization for each wheel joint of the vehicle context at byte_7C56C0. First calls sub_4881F0 (context setup), then guards on two UtilityFunction_7160 lookups (index 0 and 1) that return the suspension anchor endpoints (v15/v16 and v17/v18). Computes a wheel-speed scalar from the velocity constants dword_7C6C44, dbl_7C6C38, dbl_7C6C30 scaled by 9.549296585513721 * 0.0001 and the endpoint span v18-v16, selects the speed-unit conversion from byte_7D0474 (3.6 for km/h, 2.236936292054402 for mph), reads the joint count from DynamicsJointCount, and accumulates per-joint suspension forces via TireSuspensionForceComputation into v25. Interpolates the drawing positions along the endpoint span scaled by the forces and draws line segments with ConditionalDraw, resolving intermediate positions with OffsetPositionComputation.
    // CALL: sub_4881F0(this, a2, a3, a4, a5): opaque context/frame setup called before the drawing guard. [callee:0x004881F0, source:raw]
    // GUARD: Both suspension anchor lookups must succeed: UtilityFunction_7160(this, 0, &v15, &v16) and UtilityFunction_7160(this, 1, &v17, &v18); the drawing body only runs when both return true. [callee:0x00487160, source:raw]
    // CALL: DynamicsJointCount(&byte_7C56C0): reads the number of wheel/suspension joints for the vehicle context; the count v8 bounds both force and drawing loops. [callee:0x00431820, global:0x007C56C0, source:raw]
    // CALCULATION: Wheel-speed-derived pixel offset v20 = CRTFtol((dword_7C6C44 * dbl_7C6C38 + dbl_7C6C30) * 9.549296585513721 * 0.0001 * (v18 - v16) + v16): combines the speed scaling constants with the anchor Y span and rounds to an integer. [callee:0x00587BDC, global:0x007C6C30, global:0x007C6C38, global:0x007C6C44, source:raw]
    // CALCULATION: Speed-unit conversion factor: when byte_7D0474 is set use 3.6 (km/h), otherwise 2.236936292054402 (mph); the factor is stored as a float in v19[0] and scales every suspension force. [global:0x007D0474, source:raw]
    // LOOP: Force gathering loop over joints 0..v8-1: v25[i] = TireSuspensionForceComputation(&byte_7C56C0, i) * (float)v19[0], i.e. each suspension force scaled by the speed unit conversion. [callee:0x00431850, global:0x007C56C0, source:raw]
    // CALCULATION: First drawing position: v21 = CRTFtol((v17 - v15) * (v25[0] * 0.01) + v15), the start anchor X advanced by the first scaled force over the anchor span; v22 is initialized to v20. [callee:0x00587BDC, source:raw]
    // CALL: ConditionalDraw(&v23, &v21): draws the first line segment between the carried point and the first interpolated point. [callee:0x00475C80, source:raw]
    // LOOP: Remaining segment loop over joints i = 1..v8-1: recomputes v21 = CRTFtol(v25[i] * 0.01 * (v17 - v15) + v15), resolves the intermediate position with OffsetPositionComputation, then draws two segments per joint (ConditionalDraw twice). [callee:0x00475C80, callee:0x00475CC0, callee:0x00587BDC, source:raw]
    // RETURN: Function always returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   sub_4881F0(this, a2, a3, a4, a5);
    //   if (UtilityFunction_7160(this, 0, &x0, &y0) && UtilityFunction_7160(this, 1, &x1, &y1)) {
    //     n = DynamicsJointCount(vehicle);
    //     speed = CRTFtol((dword_7C6C44 * dbl_7C6C38 + dbl_7C6C30) * 9.549296585513721 * 0.0001 * (y1 - y0) + y0);
    //     unit = byte_7D0474 ? 3.6 : 2.236936292054402;
    //     for (i = 0; i < n; i++) forces[i] = TireSuspensionForceComputation(vehicle, i) * unit;
    //     p = {x0, y0};
    //     y = CRTFtol((x1 - x0) * (forces[0] * 0.01) + x0);
    //     x = speed;
    //     ConditionalDraw(&p, &{x, y});
    //     for (i = 1; i < n; i++) {
    //       y = CRTFtol(forces[i] * 0.01 * (x1 - x0) + x0);
    //       OffsetPositionComputation(x, &p, &y, &p2);
    //       ConditionalDraw(&{x, y}, &p2);
    //       ConditionalDraw(&p2, &{x, y});
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: The read-only globals 0x0059EA38, 0x0059EA90, 0x0059EA98, 0x0059EB20 and 0x005A4420 are listed in the packet but never appear in the raw source text; the extraction reports them as read-only but their role in this function is unknown (the fill labels them BodyDragCoeff / Unknown_Double / TireTerrainDoubleThreshold at DERIVED trust, not adopted here).
    // UNRESOLVED: The parameters a2..a5 are forwarded unmodified to sub_4881F0 and their meaning is unknown.
    // UNRESOLVED: The exact screen-space meaning of v20/v21/v22 (whether they are pixel coordinates or 2D widget coordinates) is not established by the packet.
}
