// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499050
// Canonical corpus name: GuardedSubRectangleRenderDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedSubRectangleRenderDispatch_00499050.c

void UnknownObject::GuardedSubRectangleFill()
{
    // Guarded render-surface sub-rectangle fill dispatch. Reads the mode value at this+0x7C (reached through the sub-structure pointer at this+0x54 plus 40 bytes) and subtracts 2 into v5. When that mode equals 2 it obtains the render surface/context via Accessor() and fills the sub-rectangle through RenderSurfaceFillCopy, storing the result into the low byte of v5. Returns v5 whether or not the fill ran.
    // CALCULATION: Computes v5 as the mode value at this+0x7C, reached through the sub-structure pointer at this+0x54 plus 40 bytes, minus 2. [field:this:0x00000054, field:this:0x0000007C, source:raw]
    // GUARD: Proceeds with the fill only when the mode value at this+0x7C equals 2; otherwise the fill is skipped entirely. [guard:0, field:this:0x0000007C, source:raw]
    // CALL: Obtains the render surface/context pointer via Accessor() into v6. [callee:0x00490920, source:raw]
    // CALL: Fills the sub-rectangle through RenderSurfaceFillCopy(v6, a4, a2, a5 - a4, a3 - a2) and stores the result into the low byte of v5. [callee:0x004918D0, source:raw]
    // RETURN: Returns v5: the mode-minus-2 value when the guard blocks the fill, or the fill-copy result when the fill ran. [function:0x00499050, source:raw]

    // Conservative worker pseudocode:
    //   v5 = *(*(this + 0x54) + 40) - 2;
    //   if (*(*(this + 0x54) + 40) == 2) {
    //     v6 = Accessor();
    //     v5 = (char)RenderSurfaceFillCopy(v6, a4, a2, a5 - a4, a3 - a2);
    //   }
    //   return v5;
    // UNRESOLVED: this+0x54 points to a sub-structure whose mode field sits 40 bytes in; the byte displacement to this+0x7C is derived from the raw body (this[21] plus 40) and corroborated by the packet guard field, but the sub-structure type is unknown.
    // UNRESOLVED: The result of RenderSurfaceFillCopy is stored only into the low byte of v5 (LOBYTE); the meaning of the high byte and the exact contract of the returned value are not resolved.
    // UNRESOLVED: Callers MultiRegionOffsetAccumulationWithVTableDispatch (0x004869E0) and GuardedConditionalRenderCall (0x00486F00) indicate render-path use; the owning render object is unknown.
}
