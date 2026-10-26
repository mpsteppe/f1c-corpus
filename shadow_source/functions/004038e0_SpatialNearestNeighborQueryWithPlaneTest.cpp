// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004038E0
// Canonical corpus name: SpatialNearestNeighborQueryWithPlaneTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialNearestNeighborQueryWithPlaneTest_004038e0.c

void UnknownObject::SpatialNearestNeighborQueryWithPlaneTest()
{
    // Nearest-strut query over a strut array with optional strut-type filtering and a plane-side rejection test. Scans all struts (count at this+0x130, array base this+0x134, stride 316) for the minimum squared distance from a query point a2, requiring a3 == -1 or a3 == the strut type at +300. If a best strut is found, a plane-normal product (+164/+172 coefficients against the strut's +148/+152/+156 position) decides whether to return the strut pointer itself or its linked collision child at +272. Returns 0 immediately when the count is 0.
    // GUARD: If the strut count at this+0x130 is less than or equal to 0, return 0 immediately (no struts to scan). [field:this:0x00000130, source:raw]
    // ASSIGNMENT: Initialize result v4 to 0 and best squared distance v12 to 9.9999999e36. [source:raw]
    // ASSIGNMENT: Load strut array base v5 = this+0x134 and loop counter v6 = count (this+0x130). [field:this:0x00000134, field:this:0x00000130, source:raw]
    // LOOP: Iterate over the struts, advancing the cursor by stride 316 and decrementing the counter until it reaches 0. [source:raw]
    // CALCULATION: Compute squared distance from query point a2 to the current strut's position (+148/+152/+156) as dx*dx + dy*dy + dz*dz. [source:raw]
    // GUARD: Candidate test per strut: accept only if the squared distance is below the current best AND (a3 == -1 OR a3 == the dword type at +300). [source:raw]
    // ASSIGNMENT: When the candidate test passes, record the strut pointer as best (v4) and the distance as best (v12). [source:raw]
    // GUARD: Plane test on the best strut: if a best strut exists and the product of normal coefficients at +164/+172 with (strut position at +148/+156 minus query point) is negative, select the linked collision child pointer at +272 instead. [source:raw]
    // RETURN: Return the best strut pointer, or the linked child pointer at +272 when the plane test rejects the strut. [source:raw]

    // Conservative worker pseudocode:
    //   if (count <= 0) return 0;
    //   best = 0; bestDist = 9.9999999e36;
    //   for (cursor = base; i < count; cursor += 316, i++) {
    //     d = sq(a2[0]-cursor[+148]) + sq(a2[1]-cursor[+152]) + sq(a2[2]-cursor[+156]);
    //     if (d < bestDist && (a3 == -1 || a3 == *(int*)(cursor+300))) { bestDist = d; best = cursor; }
    //   }
    //   if (best && *(float*)(best+172)*(*(float*)(best+156)-a2[2]) + *(float*)(best+164)*(*(float*)(best+148)-a2[0]) < 0.0)
    //     return *(int*)(best+272);
    //   return best;
    // UNRESOLVED: this+0x1C8, this+0x1CC, this+0x1D0, this+0x1D8, this+0x1E0, this+0x244, this+0x260 are listed as read but do not appear in the raw source text.
    // UNRESOLVED: Global flt_59E440 is listed as read but does not appear in the raw source; existing analysis labels it a zero-threshold constant (DERIVED).
    // UNRESOLVED: Strut element layout (position +148/+152/+156, normal coefficients +164/+172, type +300, linked child +272, stride 316) is DERIVED from the decompilation; the packet carries no field table for this element type.
}
