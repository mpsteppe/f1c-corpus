// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00403640
// Canonical corpus name: sub_403640
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_403640_00403640.c

void UnknownObject::NearestNeighborPlaneQuery()
{
    // Finds the closest physics strut or collision node to a query point a2 using Euclidean squared distance plus a signed-distance plane test. When start node a3 is provided, walks its linked geometry lists (next pointers at +268/+272); otherwise initializes from a full-array scan. Global scan iterates this->strut array (0x134 base, 316-byte stride) while this->strutCount (0x130) > 0. Candidates passing the plane distance test sub_4FB6D0 are selected; called by VehicleMainPhysicsUpdate, Camera, PositionChangeMonitor, AIRacingLinePathFollowing and sub_4F1FE0 on the per-frame path.
    // GUARD: If start node a3 is non-null, initialize the linked-list nearest-neighbor walk from node at a3 (seed distance via offsets +0/+8) instead of the full-array scan path. [source:raw]
    // LOOP: Walk linked geometry nodes via next pointers at +272 (and +268 on the second list) computing squared XZ distance to query point; retain the nearest node while the walk distance improves. [source:raw]
    // GUARD: this->strutCount (0x130) > 0 enables the strut-array scan loop over all active struts; count <= 0 skips the scan. [guard:0, field:this:0x00000304]
    // LOOP: Iterate strut entries at base this->strutData (0x134) with 316-byte stride; read entry type word at +300 and when type <= 1 compute squared distance to the query point with Y component weighted by 4.0, keeping the nearest candidate. [field:this:0x00000304, field:this:0x00000308, source:raw]
    // CALL: Call sub_4FB6D0(a2) to obtain the signed distance from the query point to the reference plane/surface; negative distance disqualifies early and returns the nearest node. [callee:0x004FB6D0, source:raw]
    // CALCULATION: Plane-proximity scoring: for scan candidates when best plane distance is positive, re-call sub_4FB6D0 and accept the candidate if its distance improves bestPlaneDistance and its squared (distance+30) window is within bestSquaredDistance. [callee:0x004FB6D0, source:raw]
    // RETURN: Final signed plane distance: if >= 0.0 return the plane-qualified candidate (v28), otherwise return the nearest raw node (v8). [source:raw]

    // Conservative worker pseudocode:
    //   if (a3) { v8 = nearest of linked lists; best = dist^2(a2, v8); if (PlaneDist(a2) < 0.0) return v8; }
    //   for each strut entry (base this[0x134/4], stride 316, type word at +300):
    //       if type <= 1: d = dist^2(a2, entry) with Y*4.0; track nearest (v8) and plane-qualified candidate (v28);
    //   return PlaneDist(a2) >= 0.0 ? v28 : v8;
    // UNRESOLVED: flt_59E440 / flt_59E468 / flt_59E46C are read by this function but do not appear in the extracted pseudocode; likely thresholds or transforms consumed by sub_4FB6D0 path, exact use unconfirmed.
    // UNRESOLVED: The stride-316 strut entry layout (type word at +300, position at +0/+4/+8) is inferred from pseudocode only; struct definition not confirmed.
}
