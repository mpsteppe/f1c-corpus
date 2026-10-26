// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00403AA0
// Canonical corpus name: SpatialTreeNearestNeighborSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialTreeNearestNeighborSearch_00403aa0.c

void UnknownObject::SpatialTreeNearestNeighborSearch()
{
    // Spatial tree nearest-neighbor search over a linked node structure. Given a query point a2 and an identifier a4, descends and walks the node chains (+268 siblings, +272 children) keeping the node with minimum squared distance, with identifier checks (+300). When the tree walk yields no candidate (null node) or the optional plane test (a5) rejects the candidate, it falls back to SpatialNearestNeighborQueryWithPlaneTest. Used by AI racing-line / steering callers.
    // GUARD: If starting node a3 is null, call SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4) and return its result. [callee:0x004038E0, source:raw]
    // GUARD: If a3+300 != a4 and a3+276 is nonzero and (a3+276)+300 == a4, switch the working node to a3+276. [source:raw]
    // CALCULATION: Compute squared distance from query point a2 to the node position stored at +148/+152/+156. [source:raw]
    // LOOP: Walk the +268 sibling chain while distance decreases and node+300 == a4, tracking the closest node; if the chain ends, call SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4) and return. [callee:0x004038E0, source:raw]
    // LOOP: Walk the +272 child chain while distance decreases, tracking the closest node; if the chain ends, call SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4) and return. [callee:0x004038E0, source:raw]
    // GUARD: If a5 (plane-test flag) is set and the closest node fails the plane-side test computed from +164/+172 coefficients and its +148/+156 position, advance to the +272 child. [source:raw]
    // RETURN: Return the closest node, or call SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4) and return its result if no node was selected. [callee:0x004038E0, source:raw]
    // UNRESOLVED: Global flt_59E440 is listed as read (R) but does not appear in the raw source; its use is unclear.
    // UNRESOLVED: Node layout (position +148/+152/+156, plane coefficients +164/+172, links +268/+272, child-select +276, identifier +300) is DERIVED from the decompilation; the packet carries no field table for this type.
    // UNRESOLVED: Return-value semantics (pointer to nearest node) and tree role are inferred from AI racing-line/steering callers (DERIVED).
}
