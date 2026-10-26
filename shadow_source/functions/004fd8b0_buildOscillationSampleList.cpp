// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FD8B0
// Canonical corpus name: sub_4FD8B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FD8B0_004fd8b0.c

void UnknownObject::buildOscillationSampleList()
{
    // Rebuilds a linked list of oscillation samples for camera/vehicle sway: clears the previous list, allocates a head node, then traverses nodes accumulating a time value from a2 and writing per-node float outputs derived from clamped random-noise and sinusoidal motion, until the accumulated value exceeds the a3 threshold.
    // CALL: DualLinkedListDestruction(this) tears down the previously built sample list before rebuilding. [callee:0x004FD840, source:raw]
    // CALCULATION: Rotation seed: v4 = RandomNoiseValueGenerator(&dword_8AAE70) * 360.0; v29 = clamp(v4, -900.0, 900.0); then v5 = v29 * 0.25 and v32 = clamp(v5, -900.0, 900.0). Reads read-only constant-pool float constants consumed by the rotation amplitude computations. [callee:0x004B3CE0, global:0x008AAE70, global:0x005AD2B8, global:0x005AD2D4, global:0x005AD2D8, global:0x005AD2DC, global:0x005AD2E0, global:0x005AD2F0, global:0x005AD2F8, global:0x005ACB0C, global:0x005AD148, global:0x005AD184, source:raw]
    // CALCULATION: Lateral seed: v6 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.40000001; v27 = clamp(v6, -1.0, 1.0); then v7 = v27 * 0.0056250002 and v31 = clamp(v7, -0.1, 0.1). Reads read-only constant-pool float constants consumed by the lateral computations. [callee:0x004B3CE0, global:0x008AAE70, global:0x0059E7EC, global:0x0059E7F0, global:0x0059E8F0, global:0x0059E8F8, global:0x0059E91C, source:raw]
    // CALCULATION: Vertical seed: v8 = RandomNoiseValueGenerator(&dword_8AAE70) * 5.0; v28 = clamp(v8, -12.5, 12.5); then v9 = v28 * 0.0025000002 and v30 = clamp(v9, -2.0, 2.0). Reads read-only constant-pool float constants consumed by the vertical computations. [callee:0x004B3CE0, global:0x008AAE70, global:0x0059E7F8, global:0x0059E800, global:0x0059E814, global:0x0059E84C, global:0x005AD2E4, global:0x005AD2E8, source:raw]
    // CALCULATION: Snap seed: v10 = v27 + 0.30000001; v33 = clamp(v10, 0.0, 1.0). Reads read-only constant-pool float constants used for the low clamp and scaling. [global:0x0059E43C, global:0x0059E440, global:0x0059E450, source:raw]
    // CALL: Allocates a 16-byte list node: v11 = OperatorNewNhMallocWrapper(16); v12 = FloatArrayInitializer(v11) on success, otherwise 0. [callee:0x00587C03, callee:0x004FC9A0, source:raw]
    // ASSIGNMENT: List head stored at this+0x3C and the traversal cursor at this+0x38; node data (accumulated position) at *(this+0x44)+0 is zeroed; this+0x44 also holds the allocated head pointer used by the extractor's field analysis. [field:this:0x0000003C, field:this:0x00000038, field:this:0x00000044, field:*(this+0x44):0x00000000, source:raw]
    // LOOP: Traverses the node list starting at this+0x3C head with cursor this+0x38, advancing through the node's next link (node+12), until the loop breaks on accumulated time. [field:this:0x00000038, field:this:0x0000003C, source:raw]
    // CALCULATION: v13 = a2 + node accumulated position (field at *(this+0x44)+0); v35 = v13 records the accumulated time. [field:*(this+0x44):0x00000000, source:raw]
    // CALL: InterruptDispatch(v13) is invoked with the accumulated time value. [callee:0x0058957A, source:raw]
    // CALCULATION: Sinusoidal vertical term v36 = sin(v13 * 0.0000363610260832152) * 10.0 + 15.0 - (v33 - 0.5) * 5.0. Reads read-only constant-pool float constants feeding the oscillation scaling. [global:0x0059E450, global:0x0059E4E8, global:0x0059E5FC, global:0x0059E670, global:0x0059E868, global:0x0059E8B4, global:0x0059E8C8, global:0x0059E8D8, global:0x0059E920, source:raw]
    // CALCULATION: Lateral update: v14 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.19 + v30 - v28 * 0.0025000002; v30 = v14 - 0.1 * v14; v30 clamped to +/-2.0. [callee:0x004B3CE0, global:0x008AAE70, source:raw]
    // CALCULATION: Vertical accumulator update: v15 = v30 + v28; v28 = clamp(v15, -12.5, 12.5). [source:raw]
    // CALCULATION: Mid-range update: v16 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.013 + v31 - v27 * 0.0056250002; v31 = v16 - 0.15000001 * v16; v31 clamped to +/-0.1. [callee:0x004B3CE0, global:0x008AAE70, source:raw]
    // CALCULATION: Lateral accumulator update: v17 = v31 + v27; v27 = clamp(v17, -1.0, 1.0). [source:raw]
    // ASSIGNMENT: Per-node outputs written: node+4 = v36 + v28 and node+8 = v27 + 0.30000001, then node+8 is clamped to the 0.0..1.0 range. [source:raw]
    // GUARD: Mid-range snap: when node+8 lies between 0.60000002 and 0.64999998 it is snapped to 0.625 if at least 0.625, otherwise to 0.6 (literals 1058642330 / 1059481190); this+0x40 holds the 0.6 threshold constant. [field:this:0x00000040, source:raw]
    // GUARD: Loop exit: if the node's accumulated position (field at *(this+0x44)+0) exceeds a3, the traversal breaks. [field:*(this+0x44):0x00000000, source:raw]
    // CALCULATION: Rotation increment: v22 = RandomNoiseValueGenerator(&dword_8AAE70) * 500.0 + v32 - v29 * 0.25; v32 = v22 - v22; v32 clamped to +/-900.0. [callee:0x004B3CE0, global:0x008AAE70, source:raw]
    // GUARD: Special distance range: when v35 lies between 28800.0 and 57600.0 the amplitude bounds are tightened from +/-900.0 to +/-280.0 (v23/v34 become 400.0/280.0). Reads read-only constant-pool clamp constants. [global:0x005AD2FC, global:0x005AD300, source:raw]
    // CALCULATION: Rotation accumulator update: v29 = v32 + v29; v29 = clamp(v29, -v34, v34) using the active amplitude bound. [source:raw]
    // CALL: Allocates the next node via OperatorNewNhMallocWrapper(16) and FloatArrayInitializer; stores it in the current node's next link (node+12) and seeds its accumulated position field with v23 + v29 plus the previous node's accumulated value. [callee:0x00587C03, callee:0x004FC9A0, field:*(this+0x44):0x00000000, source:raw]
    // LOOP: Cursor advances to the node at +12 (this+0x38) and the traversal repeats until the exit guard breaks the loop. [field:this:0x00000038, source:raw]

    // Conservative worker pseudocode:
    //   DualLinkedListDestruction(this);
    //   seed v27/v28/v29/v30/v31/v32/v33 from clamped RandomNoiseValueGenerator(&dword_8AAE70) products;
    //   head = FloatArrayInitializer(OperatorNewNhMallocWrapper(16));
    //   this[0x3C] = head; this[0x38] = head; head[0] = 0;
    //   for (node = head; ; node = node[3]) {
    //     t = a2 + node[0]; InterruptDispatch(t);
    //     vertical = sin(t * 0.0000363610260832152) * 10.0 + 15.0 - (v33 - 0.5) * 5.0;
    //     // update v27/v28/v30/v31/v32/v33 with clamped random noise terms;
    //     node[1] = vertical + v28; node[2] = clamp(v27 + 0.3, 0.0, 1.0);
    //     // snap node[2] to 0.625/0.6 when in 0.6..0.65;
    //     if (node[0] > a3) break;
    //     // rotation increment, special 28800..57600 range tightens bounds to 280.0;
    //     next = FloatArrayInitializer(OperatorNewNhMallocWrapper(16));
    //     node[3] = next; next[0] = v23 + v29 + node[0];
    //   }
    // UNRESOLVED: Exact owning class is unknown: the ABI lead Rain_Drop_Spray_Particle_Generator (LEGACY) conflicts with the existing-analysis label CameraOscillationGenerator; the two interpretations differ on whether the sample list drives rain spray or camera sway.
    // UNRESOLVED: The mapping of individual read-only constant-pool globals (flt_59E*, flt_5AD*) to specific arithmetic literals is not established from this packet alone.
    // UNRESOLVED: this+0x44 and this+0x40 appear in the packet field list but are not directly rendered in the raw source; their relationship to the node cursor (this+0x38) and the 0.6 threshold is inferred from the deterministic extractor only.
}
