// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543250
// Canonical corpus name: ClippedRenderRegion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClippedRenderRegion_00543250.c

void UnknownObject::clipAndCompositeSurfaceRegion()
{
    // Renders a 2D surface region with negative source offsets folded into the destination, then clipping both destination (a2,a3) and source (a5,a6) rectangles against the extent pair (a7,a8) via sub_543540. If the clipped region is non-empty (a7 > 0 and a8 > 0) it composites the surface through F_2DSurfaceCompositing using the global surface context dword_8B78A0, and clears bit 0x400 on a4[6]. Returns the region width a7 when no compositing occurs, otherwise the compositing result.
    // CALCULATION: If the source x extent a5 is negative, fold it into the destination x a2 (a2 -= a5), normalising the negative offset into the destination position. [source:raw]
    // CALCULATION: If the source y extent a6 is negative, fold it into the destination y a3 (a3 -= a6). [source:raw]
    // CALL: Call sub_543540(&a2, &a3, &a7, &a8) to clip the destination rectangle (a2,a3) against the region extents (a7,a8), narrowing them in place. [callee:0x00543540, source:raw]
    // CALL: Call sub_543540(&a5, &a6, &a7, &a8) to clip the source rectangle (a5,a6) against the same region extents. [callee:0x00543540, source:raw]
    // GUARD: Proceed only if the clipped region is non-empty (a7 > 0 and a8 > 0); otherwise return a7 unchanged. [source:raw]
    // CALL: Composite the clipped surface via F_2DSurfaceCompositing(dword_8B78A0, this, a2, a3, a4, a5, a6, a7, a8, a9), passing the global surface context dword_8B78A0 and the adjusted/clipped rectangles. [global:0x008B78A0, callee:0x00540250, source:raw]
    // ASSIGNMENT: Clear bit 0x400 on a4[6] (v11[6] &= ~0x400u), where v11 is the a4 pointer argument, resetting the flag after compositing. [source:raw]
    // RETURN: Return the F_2DSurfaceCompositing result when the region was non-empty, or the clipped width a7 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   if (a5 < 0) a2 -= a5;
    //   if (a6 < 0) a3 -= a6;
    //   sub_543540(&a2, &a3, &a7, &a8);
    //   sub_543540(&a5, &a6, &a7, &a8);
    //   if (a7 > 0 && a8 > 0) {
    //     result = F_2DSurfaceCompositing(dword_8B78A0, this, a2, a3, a4, a5, a6, a7, a8, a9);
    //     a4[6] &= ~0x400u;
    //   }
    //   return result;
    // UNRESOLVED: Exact clipping semantics of sub_543540 (intersection versus clamp) are inferred from argument usage, not evidenced by the packet.
    // UNRESOLVED: Meaning of a4[6] bit 0x400 (a draw/composite flag) and of a9/a10 is not visible from this packet.
    // UNRESOLVED: dword_8B78A0 (a global render surface/driver context) has no type evidence here.
}
