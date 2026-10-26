// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448FC0
// Canonical corpus name: SATSeparatingAxisTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SATSeparatingAxisTest_00448fc0.c

void UnknownObject::SATSeparatingAxisTest()
{
    // Tests a point/vector a2 (floats a2[0] and a2[3]) against a run of consecutive half-plane coefficient triples (nx, ny, d) stored as doubles starting at a1 + 0x10, stepping 3 doubles per plane. The loop continues only while the point lies strictly beyond the current plane (a2[0] * nx + a2[3] * ny > d). If the point is beyond all three planes the counter reaches 3 and the function returns 1; if any plane is not exceeded it returns 0. Invoked by SATEdgeSeparationTest (0x004491C0).
    // LOOP: Iterates over the plane coefficient triples beginning at a1 + 0x10, advancing the pointer i by 3 doubles per step (one plane per triple) [field:this:0x00000010, source:raw]
    // GUARD: Loop continues only while the point lies strictly beyond the current plane: a2[0] * plane.nx + a2[3] * plane.ny > plane.d, where plane.nx = *(i-2), plane.ny = *(i-1) and plane.d = *i [source:raw]
    // GUARD: Each time the point lies beyond a plane the counter v2 is incremented; when v2 reaches 3 the point is beyond all three planes and the function returns 1 [source:raw]
    // RETURN: Returns 1 when the point is beyond all three planes, otherwise returns 0 when the loop exits early; the caller is SATEdgeSeparationTest (0x004491C0) [caller:0x004491C0, function:0x00448FC0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   double* i = (double*)(a1 + 16);
    //   int count = 0;
    //   while (a2[0] * *(i-2) + a2[3] * *(i-1) > *i) {
    //       if (++count >= 3) return 1;
    //       i += 3;
    //   }
    //   return 0;
    // UNRESOLVED: The prelabel template proposed a simple getter of field +0x10, but the raw source shows an iteration over plane triples beginning at a1 + 0x10; the template summary is overridden by the raw source
    // UNRESOLVED: The exact meaning of the a2[3] component (axis/component selection) and how the 1/0 result is consumed by SATEdgeSeparationTest are not determinable from this packet alone
}
