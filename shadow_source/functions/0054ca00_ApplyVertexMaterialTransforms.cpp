// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054CA00
// Canonical corpus name: sub_54CA00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54CA00_0054ca00.c

void UnknownObject::ApplyVertexMaterialTransforms()
{
    // Processes a scene-graph mesh object's vertex element array, applying material-based vertex/UV transforms. Guarded by a re-entry bit (0x8000000) in this+0x14; a sub-object byte at this+0x138+60 selects a stride constant (18 vs 34). For each element in the this[71] array (count this[70]), it waits on audio resources, runs per-element wrappers, and either follows a 16-DWORD vertex stride path (flag 0x800000 set) that ORs a packed color into vertices and applies per-material 37-float transforms via jump table jpt_54CBC0, or a 12-DWORD stride path via jpt_54CE21. Material entries are deduplicated through sub_54FC70. Copies index data, updates UI context via sub_55D720, and finally sets done flags (this+0x14 |= 0x9000020). Returns 0 normally, -1 on audio wait failure.
    // GUARD: Re-entry guard: if bit 27 (0x8000000) of this+0x14 is set, the function is blocked and returns 0 immediately. [field:this:0x00000014]
    // ASSIGNMENT: Default the stride constant v85 to 18; override to 34 when byte at (this+0x138)+60 has bit 4 (0x10) set. [field:this:0x00000138, source:raw]
    // GUARD: If the element count this+0x118 (this[70]) is <= 0, skip processing, set done flags and return 0. [field:this:0x00000118, source:raw]
    // LOOP: Main loop over vertex elements: iterate this+0x11C (this[71]) array entries at 64-byte stride (v4 += 64) until v86 reaches the count. This function is invoked per node by PriorityQueueRecursiveProcess during recursive scene-graph traversal. [field:this:0x0000011C, caller:0x00544DB0, source:raw]
    // ASSIGNMENT: Write the selected stride constant v85 into the element header at offset 56. [source:raw]
    // CALL: Call sub_540940(dword_8B78A0, element) to check/wait on audio resource state for the element; a nonzero return aborts the whole function with -1. [callee:0x00540940, global:0x008B78A0]
    // CALL: Call SingleCallWrapper_e0e0(element, 12) to run the element's single-call wrapper. [callee:0x0054E0E0]
    // GUARD: Per-element guard: only process vertex data when the pointer stored at element offset 32 is non-null. [source:raw]
    // CALL: Call FloatToIntSwitch(vertex_ptr, 2, &v83) to convert source floats into a packed int value v83, then shift it left by 24 bits (packed color/flag word). [callee:0x005472D0, source:raw]
    // GUARD: Path selector: when this+0x14 bit 23 (0x800000) is set (tested via constant unk_800000) take the 16-DWORD vertex stride path; otherwise the 12-DWORD stride path. [field:this:0x00000014, global:0x00800000, source:raw]
    // LOOP: 16-DWORD stride path: for each vertex, OR the packed v83 into the color field and zero the adjacent fields, advancing through the vertex array; switch on the selected case via jump table jpt_54CBC0 to apply the per-material UV/color transform (D3D-transformed data layout). [global:0x0054D00C, abi:lead, source:raw]
    // LOOP: Material dedup loop (16-DWORD path): compare each material's 3-float triple against previously seen entries; when no match, call sub_54FC70(++v81) to register a new material index. [callee:0x0054FC70, source:raw]
    // LOOP: 12-DWORD stride path: copy six source DWORDs per vertex, OR packed flags into field 6, zero field 7, advancing 12 DWORDs in and 16 DWORDs out; case switch uses jump table jpt_54CE21 for untransformed vertex data. [global:0x0054D01C, source:raw]
    // LOOP: Material dedup loop (12-DWORD path): match materials by 4-float comparison against previously seen entries; call sub_54FC70(v50) for an existing match or sub_54FC70(v84) when allocating a new index, then apply the transform per switch case. [callee:0x0054FC70, global:0x0054D01C, source:raw]
    // CALL: Copy element index data: if the pointer at element offset 40 is non-null, qmemcpy it from element offset 20 with size 2 * element offset 16. [source:raw]
    // CALL: Call sub_55D720(*(dword_8B8F28 + 248), 0) to update the UI/context state pointer. [callee:0x0055D720, global:0x008B8F28]
    // CALL: Call Wrapper_e0f0(element, 12) for element post-processing. [callee:0x0054E0F0]
    // ASSIGNMENT: Set bit 0x200 in the element header at offset 56 to mark the element as processed. [source:raw]
    // STATE_TRANSITION: On loop completion set done flags on the object: this+0x14 |= 0x9000020 (bits 5, 21, 24). [field:this:0x00000014, source:raw]
    // RETURN: Return 0 on the normal/completed paths and -1 when the audio wait sub_540940 fails. [function:0x0054CA00, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54CA00(DWORD* this) {
    //     int strideConst = 18;
    //     if (this[5] & 0x8000000) return 0;
    //     if (*(BYTE*)(this[78] + 60) & 0x10) strideConst = 34;
    //     int count = this[70];
    //     if (count <= 0) { this[5] |= 0x9000020; return 0; }
    //     for (int i = 0; i < count; ++i) {
    //       BYTE* elem = (BYTE*)this[71] + i * 64;
    //       *(DWORD*)(elem + 56) = strideConst;
    //       if (sub_540940(g_soundMgr, elem)) return -1;
    //       SingleCallWrapper_e0e0(elem, 12);
    //       if (*(DWORD*)(elem + 32)) {
    //         FloatToIntSwitch((float*)elem4, 2, &packed); packed <<= 24;
    //         if (this[5] & 0x800000) {
    //           // 16-DWORD stride path (jpt_54CBC0): OR packed color, apply 37-float material transforms
    //         } else {
    //           // 12-DWORD stride path (jpt_54CE21): copy 6 DWORDs, OR flags, apply transforms
    //         }
    //       }
    //       if (*(void**)(elem + 40))
    //         qmemcpy(*(void**)(elem + 40), *(const void**)(elem + 20), 2 * *(DWORD*)(elem + 16));
    //       sub_55D720(*(DWORD*)(g_uiContext + 248), 0);
    //       Wrapper_e0f0(elem, 12);
    //       *(DWORD*)(elem + 56) |= 0x200;
    //     }
    //     this[5] |= 0x9000020;
    //     return 0;
    //   }
    // UNRESOLVED: this+0x174 appears in the packet fields but is not visible in the raw body; its read site is unresolved (noted by the fill as a sub-object property used by callers).
    // UNRESOLVED: The 37-float material entry layout and the exact meaning of the four switch cases (0..3) are inferred from loop structure, not proven.
    // UNRESOLVED: Whether the 16-DWORD path is D3D-transformed and the 12-DWORD path untransformed is DERIVED from the legacy ABI name only.
}
