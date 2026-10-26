// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C510
// Canonical corpus name: sub_54C510
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54C510_0054c510.c

void UnknownObject::updateMeshVertexBuffers()
{
    // Advances four mesh vertex-buffer base pointers (this+0x11C/0x124/0x12C/0x134) by a per-call delta (this + a3), then walks the primary element array (count at this+0x118, stride 64 at this+0x11C). For each element it resolves a material via sub_548850 key lookup followed by ArithmeticComparisonBinarySearch over the global material library array at dword_8B8F28+272, stores the resolved material object back into the element, accumulates per-element offsets, and sets render-flag byte bits (this+0x16: 0x08/0x10) from material/part flags. A failed lookup breaks out to sub_53C590(-1, aSurfaceMatLibM) and returns -1. On the tail path it ORs render flag word this+0x14 with unk_800000 when this+0x130 > 0, then re-bases the secondary stride-36 array (this+0x124) elements' +8 word to this+0x11C + (old << 6) when this+0x120 > 0, and returns 0.
    // ASSIGNMENT: Array base pointers this+0x11C, this+0x124, this+0x12C and this+0x134 are each advanced by (this + a3). [field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, field:this:0x00000134, source:raw]
    // GUARD: Primary element count at this+0x118 (280) <= 0 skips the primary material loop and jumps to the tail (LABEL_13). [field:this:0x00000118, source:raw]
    // LOOP: Primary loop iterates while element_index < count at this+0x118; each element lives in the array at this+0x11C with stride 64. [field:this:0x00000118, field:this:0x0000011C, source:raw]
    // CALCULATION: Within each primary element: +12 and +20 accumulate (this + a3); +24 is set to `this` (owning-object back-pointer); +4 holds the lookup key and is later replaced by the resolved material object. [field:this:0x0000011C, source:raw]
    // CALL: sub_548850(a2, element+4) converts the element key into the material lookup key v11. [callee:0x00548850, source:raw]
    // CALL: ArithmeticComparisonBinarySearch(*(dword_8B8F28 + 272), v11) searches the global material-library array for the key. [callee:0x005477F0, global:0x008B8F28, source:raw]
    // GUARD: A NULL search result breaks the primary loop and routes to the failure call sub_53C590. [callee:0x005477F0, source:raw]
    // LOOP: For the resolved material object v12, iterate its part list: count at v12+164, first part at v12+168+96, stride 148. [source:raw]
    // ASSIGNMENT: Render flag byte this+22 (0x16): OR 0x08 when a part's count (v14-24) > 1; OR 0x10 when material flags (v12+156) bit 0x40 or part flags (v14+2) bit 0x20 are set. [field:this:0x00000016, source:raw]
    // ASSIGNMENT: Each processed primary element resets +28 and +36 to 0. [field:this:0x0000011C, source:raw]
    // LOOP: Tail secondary pass (guard this+0x120 > 0): stride-36 elements at array this+0x124 have their +8 word rewritten to this+0x11C + (old_value << 6). [guard:0, field:this:0x00000120, field:this:0x00000124, field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Tail flag pass (guard this+0x130 > 0): render flag word this+0x14 is ORed with unk_800000. [guard:1, field:this:0x00000130, field:this:0x00000014, global:0x00800000, source:raw]
    // CALL: On material-not-found failure: sub_53C590(-1, aSurfaceMatLibM); the function returns -1. [callee:0x0053C590, global:0x005DBFD0, source:raw]
    // RETURN: Successful completion returns 0. [function:0x0054C510, source:raw]

    // Conservative worker pseudocode:
    //   this+0x11C += this + a3;
    //   this+0x124 += this + a3;
    //   this+0x12C += this + a3;
    //   this+0x134 += this + a3;
    //   if (this+0x118 > 0) {
    //     for (each element in array this+0x11C, stride 64) {
    //       element+12 += this + a3; element+20 += this + a3; element+24 = this;
    //       key = sub_548850(a2, element+4);
    //       material = ArithmeticComparisonBinarySearch(*(dword_8B8F28 + 272), key);
    //       if (material == 0) goto FAILURE;
    //       element+4 = material;
    //       if (material+164 > 0)
    //         for (part at material+168+96, stride 148)
    //           if (part-24 > 1) this+22 |= 0x08;
    //           if ((material+156 & 0x40) || (part+2 & 0x20)) this+22 |= 0x10;
    //       element+28 = 0; element+36 = 0;
    //     }
    //   }
    //   if (this+0x130 > 0) this+0x14 |= 0x00800000;
    //   if (this+0x120 > 0)
    //     for (i = 0; i < this+0x120; i += 36)
    //       *(this+0x124 + i + 8) = this+0x11C + (*(this+0x124 + i + 8) << 6);
    //   return 0;
    //   FAILURE:
    //     sub_53C590(-1, aSurfaceMatLibM);
    //     return -1;
    // UNRESOLVED: Meaning of the delta (this + a3) applied to every array base pointer is unconfirmed.
    // UNRESOLVED: Per-element layout (stride 64; fields +4, +8, +12, +20, +24, +28, +36) is inferred, not independently evidenced.
    // UNRESOLVED: Offset 272 within global dword_8B8F28 is an unconfirmed array base for ArithmeticComparisonBinarySearch.
    // UNRESOLVED: Material object layout (v12+156, v12+164, v12+168; part stride 148) is inferred.
    // UNRESOLVED: sub_53C590(-1, aSurfaceMatLibM) failure semantics are unknown; likely error reporting.
    // UNRESOLVED: The break-on-NULL path skips the tail pass; whether that is intended or a stale fallthrough is unknown.
}
