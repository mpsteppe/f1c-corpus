// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EB40
// Canonical corpus name: F_2D3DTrianglePointTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2D3DTrianglePointTest_0054eb40.c

void UnknownObject::F_2D3DTrianglePointTest()
{
    // Tests whether a 3D point lies inside a triangle projected onto a 2D plane. A selector (first argument) picks one of six projection/winding modes; modes 0-3 run inline cross-product edge tests and modes 4-5 delegate the same three edge tests to the F_2DCrossProduct helper. Returns 1 when every edge test passes (point inside), 0 otherwise; an unhandled selector returns 1.
    // GUARD: Dispatch on selector a1 through jump table jpt_54EB4D (0x0054EE74); cases 0-5 select the projection plane and winding direction, default falls through to inside result [global:0x0054EE74, source:raw]
    // ASSIGNMENT: Load triangle vertex 0 pointer (a2[0]) from obj base offset 0x0 [field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Load triangle vertex 1 pointer (a2[1]) from obj base offset 0x4 [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Load triangle vertex 2 pointer (a2[2]) from obj base offset 0x8 [field:obj:0x00000008, source:raw]
    // CALCULATION: Run cross-product edge tests between triangle edges and the test point coordinates (point X/Y/Z at this offsets 0x0/0x4/0x8); reject as outside when an edge test has the wrong sign for the selected winding [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Edge tests compare the cross-product sign against the zero threshold constant flt_59E440 (0x0059E440) [global:0x0059E440, source:raw]
    // CALL: Cases 4 and 5 delegate the three edge tests to F_2DCrossProduct(vertex, 0, 1) (0x0054EE90), returning 0 immediately when an edge test fails [callee:0x0054EE90, field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, source:raw]
    // RETURN: Return 1 (inside) when all three edge tests pass for the selected projection, 0 (outside) otherwise; unhandled selector values return 1 [function:0x0054EB40, source:raw]

    // Conservative worker pseudocode:
    //   // selector dispatch; triangle vertices = a2[0..2], test point = a3
    //   // reject outside if any edge cross product has the wrong sign for the selected projection
    //   // return 1 when every edge test passes, 0 otherwise
    // UNRESOLVED: Exact 2D projection plane and winding direction per selector 0-5 are not determinable from the raw arithmetic alone; which coordinate indices each case combines is visible, but the axis mapping is DERIVED
    // UNRESOLVED: Fields this+0xC and this+0x10 are packet-listed read fields, but the raw source never accesses point coordinates beyond a3[0..2]; their role is unresolved
}
