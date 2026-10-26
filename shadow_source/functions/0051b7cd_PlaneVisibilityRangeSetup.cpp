// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051B7CD
// Canonical corpus name: sub_51B7CD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51B7CD_0051b7cd.c

void UnknownObject::PlaneVisibilityRangeSetup()
{
    // Validates a per-plane visibility range configuration and commits it to the decoder output object. Reads range start/end, a mode flag and a set value from the caller object, rejects invalid combinations through the error-reporting object, fills each plane's 256-byte-stride lookup-table row over the requested index range with the set value, selects one of four decoder callbacks based on mode and bitstream-absence flags, then configures per-plane decode parameters and zeroes the output object fields before returning a stored result value.
    // ASSIGNMENT: Load configuration: range start from this+0x168, range end from this+0x16C, mode flag from this+0x170, set value from this+0x174, and the output configuration object pointer from this+0x194. [field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000174, field:this:0x00000194]
    // CALCULATION: Derive the bitstream-absent flag v24 as (range start == 0); the flag later selects between decoder variants and between the two per-plane parameter read paths. [field:this:0x00000168]
    // GUARD: Range-shape validation: when range start is non-zero, accept only if range end is no larger than start and below 64, and plane count equals 1; when range start is zero, accept only if range end is also zero. Any failure sets the validation error flag. [guard:0, guard:2, field:this:0x00000120, field:this:0x00000168, field:this:0x0000016C]
    // GUARD: Mode consistency check: when the mode flag is non-zero, the set value must equal mode minus 1, otherwise the validation error flag is set. [field:this:0x00000170, field:this:0x00000174]
    // GUARD: Set-value bound check: set value greater than 13 (guard 3) marks the configuration invalid. [guard:3, field:this:0x00000174]
    // STATE_TRANSITION: On validation failure, write error record into the error-reporting object pointed to by this+0x0: error code 14 at obj+0x14, range start at obj+0x18, range end at obj+0x1C, mode flag at obj+0x20, set value at obj+0x24, then dispatch the error callback through the object vtable stored at obj+0x0. [field:this:0x00000000, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024]
    // LOOP: First pass over the per-plane descriptor array: iterate while the plane counter is below plane count (this+0x120, guard 1), walking the descriptor pointer array anchored at this+0x124. [guard:1, field:this:0x00000120, field:this:0x00000124]
    // CALCULATION: For each plane descriptor, read its plane index from descriptor offset 4 and compute the lookup-table row as lookup base (this+0x8C) plus the index shifted left by 8, giving a 256-byte-stride row. [field:*(this+0x124):0x00000004, field:this:0x0000008C]
    // GUARD: Pre-fill mismatch guard: when the bitstream-absent flag is false and the first entry of the plane's lookup row is negative, report a decode mismatch for the plane. [field:this:0x00000168, field:this:0x0000008C]
    // STATE_TRANSITION: Decode-mismatch reporting path: write error code 111 at obj+0x14, the plane index at obj+0x18 and a detail index (0 or the inner loop index) at obj+0x1C, then dispatch through the second vtable slot (obj+0x4) with a -1 argument. [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C]
    // LOOP: Inner range fill loop: for each index from range start (this+0x168) through range end (this+0x16C), clamp the existing table entry to at least zero, compare it against the mode flag (this+0x170, reporting error 111 on mismatch), then write the set value (this+0x174) into the table entry. [field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000174]
    // ASSIGNMENT: Select and assign the decoder callback into the output object's callback slot this+0x198: mode flag non-zero selects PlaneVisibilityTestWithBitfieldOutput when the bitstream-absent flag holds, else sub_51B45F; mode flag zero selects BitstreamDecoder when the bitstream-absent flag holds, else sub_51B154. [field:this:0x00000198, global:0x0051AF57, global:0x0051B154, global:0x0051B37D, global:0x0051B45F, field:this:0x00000170, field:this:0x00000168]
    // LOOP: Second pass over the plane descriptor array (guard 1, plane count this+0x120), reading each descriptor pointer from this+0x124 and zeroing the matching output slot array at this+0x1B8 (output object offset 36) for every plane. [guard:1, field:this:0x00000120, field:this:0x00000124, field:this:0x000001B8]
    // CALL: Bitstream-absent, mode-zero path: read the per-plane parameter index from descriptor offset 0x14, validate it is below 4 and that the parameter object at a1[index + 40] is present (else write error 49 to obj and dispatch through the vtable), then call sub_51A5EA with the parameter object and an output buffer at output object offset 56 plus four times the index. [field:*(this+0x124):0x00000014, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000024, callee:0x0051A5EA]
    // CALL: Bitstream-present path: read the per-plane parameter index from descriptor offset 0x18, validate it is below 4 and that the parameter object at a1[index + 44] is present (else write error 49 to obj and dispatch through the vtable), call sub_51A5EA with the parameter object and the output buffer, then copy the decoded value into output object offset 72 (this+0x1DC). [field:*(this+0x124):0x00000018, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000024, callee:0x0051A5EA, field:this:0x000001DC]
    // ASSIGNMENT: Finalize the output object: zero the fields at this+0x1A4, this+0x1A8, this+0x1AC and this+0x1B4 (output object offsets 16, 20, 24 and 32). [field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B4]
    // RETURN: Copy the stored result value from this+0xFC into output object offset 52 (this+0x1C8) and return it as the function result. [field:this:0x000000FC, field:this:0x000001C8, function:0x0051B7CD]

    // Conservative worker pseudocode:
    //   int sub_51B7CD(int* this_) {
    //     int start = this_[90]; int end = this_[91];
    //     int mode = this_[92]; int value = this_[93];
    //     int* out = (int*)this_[101];
    //     bool noBitstream = (start == 0);
    //     bool bad = false;
    //     if (start) { if (start > end || end >= 64) bad = true; if (this_[72] != 1) bad = true; }
    //     else if (end != 0) bad = true;
    //     if (mode && value != mode - 1) bad = true;
    //     if (value > 13) bad = true;
    //     if (bad) reportError(*this_, 14, start, end, mode, value);
    //     for (int p = 0; p < this_[72]; ++p) {
    //       int* desc = (int*)this_[73 + p];
    //       int idx = desc[1];
    //       int* row = (int*)(this_[35] + (idx << 8));
    //       if (!noBitstream && row[0] < 0) reportError(*this_, 111, idx, 0);
    //       for (int i = start; i <= end; ++i) {
    //         int e = row[i]; if (e < 0) e = 0;
    //         if (mode != e) reportError(*this_, 111, idx, i);
    //         row[i] = value;
    //       }
    //     }
    //     out[1] = selectDecoder(mode, noBitstream);
    //     for (int p = 0; p < this_[72]; ++p) {
    //       int* desc = (int*)this_[73 + p];
    //       int slot = noBitstream ? desc[5] : desc[6];
    //       if (slot >= 4 || !this_[slot + (noBitstream ? 40 : 44)]) reportError(*this_, 49, slot);
    //       sub_51A5EA(this_, this_[slot + (noBitstream ? 40 : 44)], (int*)out + 14 + slot);
    //       if (!noBitstream) out[18] = *(int*)((char*)out + 56 + 4 * slot);
    //       out[9 + p] = 0;
    //     }
    //     *(char*)((char*)out + 24) = 0; out[5] = 0; out[4] = 0; out[8] = 0;
    //     out[13] = this_[63];
    //     return this_[63];
    //   }
    // UNRESOLVED: The error-reporting object at this+0x0 and the output configuration object at this+0x194 are distinct objects sharing similar field offsets; their type relationship is unknown.
    // UNRESOLVED: The semantic meaning of the mode flag (zero vs non-zero) and the bitstream-absent flag at the subsystem level is inferred from code shape, not confirmed.
    // UNRESOLVED: The 256-byte-stride per-plane lookup table layout (256 entries per plane) is inferred from the index shift by 8, not confirmed by a named structure.
    // UNRESOLVED: Error codes 14, 49 and 111 have meanings outside this function that are not established.
    // UNRESOLVED: Decoder callback pair (BitstreamDecoder / sub_51B154 for mode zero; PlaneVisibilityTestWithBitfieldOutput / sub_51B45F otherwise) is inferred from the assignment structure.
}
