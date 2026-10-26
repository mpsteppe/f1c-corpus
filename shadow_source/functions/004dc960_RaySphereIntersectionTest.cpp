// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC960
// Canonical corpus name: RaySphereIntersectionTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaySphereIntersectionTest_004dc960.c

void UnknownObject::RaySphereIntersectionTest()
{
    // Ray-sphere intersection test. Retrieves a 3D vector via TripleFieldGetter_2460, computes squared distance between that vector and the point a2, and returns 0 when the distance exceeds radius squared (a5*a5). When the distance is acceptable it copies a struct field array, calls an indirect D3D-device-wrapper routine, and rejects with 0 when the viewport depth result is not positive. Otherwise it clamps the hit position via ViewportPositionClamping, computes a delta through sub_5424E0, writes distance to a4 and position/delta to a3, and returns 1.
    // CALCULATION: Retrieve the three components of a 3D vector (fields this+0/4/8) into locals v17, v18, v19 via TripleFieldGetter_2460. [callee:0x00542460, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // CALCULATION: Compute squared distance v10 between the retrieved vector and point a2: sums of squared per-axis differences (v19 vs a2[2], v18 vs a2[1], v17 vs a2[0]). [source:raw]
    // GUARD: Reject the test when squared distance v10 exceeds radius squared a5*a5 (return 0). [source:raw]
    // CALL: Call StructFieldArrayCopy to copy a struct/transform field array into v22 for the intersection calculation. [callee:0x00542400]
    // CALL: Call the indirect routine at (*(dword_8B8F24))+4 with the D3D-device wrapper pointer dword_8B8F24, point a2, and buffers v20/v22. [global:0x008B8F24]
    // GUARD: Reject the test when the depth result v21 is not positive (return 0). [source:raw]
    // CALL: Call ViewportPositionClamping on the hit position a2 and write the clamped position into v15. [callee:0x005425A0]
    // CALL: Call sub_5424E0 to compute an offset/delta (v13/v16) used for the hit-point delta. [callee:0x005424E0]
    // CALCULATION: Compute the position delta v16 as v13 minus the pre-existing v16 value. [source:raw]
    // ASSIGNMENT: Write the output record: a4 receives sqrt of the squared distance, a3 receives clamped position v15, a3+4 receives delta v16, and a3+8 is set to 0. [source:raw]
    // RETURN: Return 1 for a valid intersection that passed both guards. [source:raw]

    // Conservative worker pseudocode:
    //   int RaySphereIntersectionTest(int a1, float *a2, int a3, float *a4, float a5) {
    //     float v17, v18, v19;
    //     TripleFieldGetter_2460(&v17, &v18, &v19);
    //     float dx = -v17 - a2[0], dy = -v18 - a2[1], dz = -v19 - a2[2];
    //     float dist2 = dx*dx + dy*dy + dz*dz;
    //     if (dist2 > a5*a5) return 0;
    //     StructFieldArrayCopy(v22);
    //     (*(void (**)(...))*(int*)dword_8B8F24 + 4)(dword_8B8F24, a2, v20, v22);
    //     if (v21 <= 0.0f) return 0;
    //     ViewportPositionClamping(a2, &v15);
    //     sub_5424E0(v12, v12, v12, &v13);
    //     *a4 = sqrtf(dist2);
    //     *(float*)a3 = v15;
    //     *(float*)(a3 + 4) = (float)(v13 - v16);
    //     *(int*)(a3 + 8) = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Global flt_59E440 is listed as a referenced global but no direct access to it appears in the raw source; its role (possibly a zero/epsilon threshold used through an inlined path) is unconfirmed.
    // UNRESOLVED: The indirect routine dispatched through dword_8B8F24+4 and the exact meaning of the buffers v20/v22 are unresolved.
    // UNRESOLVED: Meaning of the v12/v13/v16 delta produced by sub_5424E0 is unresolved.
    // UNRESOLVED: The relationship between the `this` field vector and the parameter point a2 is only inferred from the distance computation.
}
