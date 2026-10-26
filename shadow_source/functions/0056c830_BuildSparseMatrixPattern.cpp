// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C830
// Canonical corpus name: sub_56C830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56C830_0056c830.c

void UnknownObject::BuildSparseMatrixPattern()
{
    // Builds a sparse-matrix (CSR-like) symbolic pattern from the dense connectivity matrix in a2, with dimension a4. Normalizes non-zero entries to a fixed value in a2/a3, counts non-zero entries (v44 rows, v46 entries), allocates four arrays into this[0]..this[3], then fills row-start pointers, per-row column indices and packed value offsets. Returns a4.
    // CALL: Free previously allocated sparse-matrix storage via QuadPointerFree() before rebuilding. [callee:0x0056CF10, source:raw]
    // LOOP: For a4 > 0, walk each row pointer in a2; for each of the a4 double entries that is not 0.0, write low dword 0 and high dword 1072693248 (normalizing to a fixed non-zero value). [source:raw]
    // ASSIGNMENT: For a4 > 0, initialize the dense pattern buffer a3: a3[0] = 0, a3[1] = 1072693248, then memcpy the rest of the (8 * a4 - 5) 4-byte units from a3. [source:raw]
    // CALCULATION: Initialize row/entry accumulators v44, v46, v42 to 0, then count non-zero entries across rows of a2 and fill per-row column slots, writing normalized 2.0 high dword 0x40000000 where a new non-zero pair is found. [source:raw]
    // LOOP: Count trailing non-zero entries in remaining rows (v46) across the a4 - 2..0 descending row range. [source:raw]
    // CALL: Allocate the row-pointer array: this[0] = OperatorNewNhMallocWrapper(8 * a4 + 8). [callee:0x00587C03, field:this:0x00000000, source:raw]
    // CALL: Allocate the column-index array: this[1] = OperatorNewNhMallocWrapper(8 * a4). [callee:0x00587C03, field:this:0x00000004, source:raw]
    // CALL: Allocate the per-row value-offset array: this[2] = OperatorNewNhMallocWrapper(8 * v44). [callee:0x00587C03, field:this:0x00000008, source:raw]
    // CALL: Allocate the packed column-index byte storage: this[3] = OperatorNewNhMallocWrapper(v46). [callee:0x00587C03, field:this:0x0000000C, source:raw]
    // LOOP: For k in 0..a4, write row starts into this[0] (byte 0 count, byte 1 reset to 0, dword at +4 = this[2] + 8 * row offset), then append column indices for non-zero entries into this[2] and this[3], tracking counts in v45/v28. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: For row v39 in a4-1..0, write this[1] entries (byte 0 = v39, byte 1 count, dword +4 = this[3] + v28) and append non-zero column indices m into this[3]. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // RETURN: Return a4 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   QuadPointerFree();
    //   normalize non-zero entries of a2 to value (0, 1072693248);
    //   if (a4 > 0) { a3[0] = 0; a3[1] = 1072693248; copy remaining pattern; }
    //   count rows (v44) and entries (v46) of the normalized pattern;
    //   this[0] = alloc(8 * a4 + 8); this[1] = alloc(8 * a4);
    //   this[2] = alloc(8 * v44); this[3] = alloc(v46);
    //   fill row starts in this[0], column indices in this[2], packed value offsets in this[3];
    //   return a4;
    // UNRESOLVED: Global dbl_59E430 (0x0059E430) is listed as read evidence but does not appear as an explicit name in the raw Hex-Rays body; its role in the pattern build is not grounded in this packet.
    // UNRESOLVED: The dense-matrix normalization value (1.0 / 2.0 via dwords 1072693248 and 0x40000000) is inferred from the IEEE-754 bit patterns in the source; the semantic meaning of the two distinct constants is not evidenced.
}
