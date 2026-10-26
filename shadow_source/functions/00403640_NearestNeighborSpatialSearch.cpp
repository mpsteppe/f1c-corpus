// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00403640
// Canonical corpus name: sub_403640
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_403640_00403640.c

void UnknownObject::NearestNeighborSpatialSearch()
{
    // Nearest-neighbor spatial query. When a starting node (a3) is given, walks two linked lists (next pointers at +0x110 and +0x10C from node base) to find the closest node to query point a2 by squared XZ distance, then applies a signed plane-proximity test via sub_4FB6D0. When a3 is null, initializes best candidates to huge sentinel values and scans the strut array (base this+0x134, stride 316, count this+0x130), keeping the closest strut and the closest candidate that passes the plane test. Returns the closest qualifying node pointer, or the plane-verified candidate if the final signed-distance check is non-negative.
    // GUARD: Branch on whether a starting node a3 is provided; when null, candidate pointers and scores are initialized to sentinel values (0 pointers, FLT_MAX scores). [source:raw]
    // LOOP: Walk first linked list from node a3 via next pointer at node+0x110, tracking the node with minimum squared XZ distance to the query point. [source:raw]
    // LOOP: Walk second linked list from node a3 via next pointer at node+0x10C, updating the nearest node when a closer squared XZ distance is found. [source:raw]
    // CALL: Call sub_4FB6D0(a2) to obtain signed distance from query point to a reference plane; if negative, return the nearest node found so far. [callee:0x004FB6D0, source:raw]
    // CALCULATION: Compute candidate plane-proximity score: squared XYZ distance to best node with a 4x-weighted Z component, and (signed_distance + 30)^2 as acceptance radius. [source:raw]
    // GUARD: Guard on strut scan count this+0x130 > 0; enables the stride-316 loop over the strut array at this+0x134. [guard:0, field:this:0x00000130, source:raw]
    // LOOP: Iterate strut entries (count this+0x130, base this+0x134, stride 316); entries whose type field at entry+0x12C is <= 1 are distance-tested against the query point. [field:this:0x00000130, field:this:0x00000134, source:raw]
    // ASSIGNMENT: Track the strut with the smallest weighted squared distance as the primary candidate v8. [source:raw]
    // CALL: When a plane-validated candidate (signed distance > 0) is closer than the acceptance radius, call sub_4FB6D0(a2) again and keep the strut with the smaller signed distance. [callee:0x004FB6D0, source:raw]
    // CALL: Final call to sub_4FB6D0(a2); if the signed distance is non-negative return the plane-verified candidate v28, otherwise return the nearest node v8. [callee:0x004FB6D0, source:raw]
    // RETURN: Return the selected node pointer (nearest node or plane-verified candidate). [source:raw]

    // Conservative worker pseudocode:
    //   node* sub_403640(this, float* query, node* start) {
    //     best = NULL; bestScore = 0; bestSigned = FLT_MAX; radius = FLT_MAX;
    //     if (start) {
    //       best = walk(start, +0x110, +0x10C, query);      // two linked lists
    //       if (planeDist(query) < 0.0) return best;
    //       score = weightedSqDist(query, best);            // 4x-weight Z
    //       radius = (planeDist(query) + 30.0)^2;
    //     }
    //     if (this->count(0x130) > 0)
    //       for (p = this->base(0x134); p < end; p += 316)
    //         if (p->type(0x12C) <= 1) {
    //           d = weightedSqDist(query, p);
    //           if (d < bestScore) { bestScore = d; best = p; }
    //           if (planeDist(query) > 0.0 && d < radius) {
    //             s = planeDist(query);
    //             if (s < bestSigned) { bestSigned = s; v28 = p; radius = (s + 30.0)^2; }
    //           }
    //         }
    //     return (planeDist(query) >= 0.0) ? v28 : best;
    //   }
    // UNRESOLVED: Meaning of the three read-only globals flt_59E440, flt_59E468, flt_59E46C: not visible in the raw source text; likely plane/threshold constants used by the distance or plane test.
    // UNRESOLVED: The 4x-weighted Z component in the squared-distance score (v34 * 4.0 * (v34 * 4.0)) has an unexplained scaling factor.
    // UNRESOLVED: Semantics of node link offsets +0x110 and +0x10C (which collision geometry list each belongs to).
    // UNRESOLVED: Type selector at entry+0x12C restricts which strut entries are distance-tested; exact enum values beyond <= 1 are unknown.
}
