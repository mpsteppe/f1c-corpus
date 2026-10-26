// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457F90
// Canonical corpus name: sub_457F90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_457F90_00457f90.c

void UnknownObject::KeyframeArrayAllocInit()
{
    // Allocates and initializes a keyframe array on `this` from input 3D position data. Guards on a2 being non-null and a3 >= 4, runs a utility initializer, stores the keyframe count at this+0x4, allocates 28*a3+4 heap bytes (4-byte count header plus a3 elements of 28 bytes each), stores the element pointer at this+0x0, copies a3 DWORD-position triples into the elements, then pre-computes the accumulated keyframe arc lengths via sub_457EE0. Returns 0 on success, 1 on invalid input.
    // GUARD: Guard on (a2 != 0 && a3 >= 4); when false the function returns the result 1 immediately. [source:raw]
    // CALL: Call the utility initializer UtilityFunction_8020 with no arguments before allocation. [callee:0x00458020]
    // ASSIGNMENT: Store the requested keyframe count a3 at this+0x4. [field:this:0x00000004]
    // CALL: Allocate heap memory of size 28*a3 + 4 via OperatorNewNhMallocWrapper; the returned block holds a 4-byte count header followed by a3 keyframe elements of 28 bytes each. [callee:0x00587C03]
    // ASSIGNMENT: Write the count a3 into the header (first DWORD of the allocation) and store the element pointer (header + 4 bytes) at this+0x0; on allocation failure the stored element pointer is null. [field:this:0x00000000]
    // GUARD: Guard on the stored keyframe count at this+0x4 being greater than 0 before entering the copy loop. [guard:0, field:this:0x00000004]
    // LOOP: Loop over all a3 keyframes, copying each input DWORD position triple (v9[0..2]) into a 28-byte element of the array at this+0x0, advancing the source by three DWORDs and the destination by 28 bytes per iteration. [field:this:0x00000000, field:this:0x00000004]
    // CALL: Pre-compute the cumulative arc length for each keyframe in the newly allocated array by calling sub_457EE0 on the keyframe object. [callee:0x00457EE0]
    // RETURN: Return 0 on successful allocation and initialization, or 1 when the input guard (a2 null or a3 < 4) fails. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_457F90(int this, _DWORD *src, int count) {
    //     if (!src || count < 4) return 1;
    //     UtilityFunction_8020();
    //     *(int*)(this + 4) = count;
    //     int *mem = (int*)OperatorNewNhMallocWrapper(28 * count + 4);
    //     _DWORD *elements = mem ? (_DWORD*)(mem + 1) : 0;
    //     *(int*)this = (int)elements;
    //     if (*(int*)(this + 4) > 0) {
    //       _DWORD *dst = (_DWORD*)*(int*)this;
    //       _DWORD *in = src;
    //       for (int n = 0; n < *(int*)(this + 4); ++n) {
    //         dst[0] = in[0]; dst[1] = in[1]; dst[2] = in[2];
    //         in += 3; dst = (_DWORD*)((char*)dst + 28);
    //       }
    //     }
    //     sub_457EE0((float*)this);
    //     return 0;
    //   }
    // UNRESOLVED: The exact meaning of the three-DWORD position triple (world space vs. path-local coordinates) is caller-defined.
    // UNRESOLVED: The identity and behavior of UtilityFunction_8020 and the layout consumed by sub_457EE0 are not established here.
}
