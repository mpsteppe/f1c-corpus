// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CE380
// Canonical corpus name: FloatComparisonWithConstantsTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatComparisonWithConstantsTable_004ce380.c

void UnknownObject::FloatComparisonWithConstantsTable()
{
    // Scans a table of constant entries starting at this+16 (array base at offset 0x40, count this[15] at offset 0x3C). Each entry is a pointer whose +4 DWORD is a type ID: type 0 terminates the scan, type 1 selects a2[10], type 5 selects a2[12], and any other non-zero type selects a2[11]. Returns 1 as soon as the selected float is non-zero; returns 0 when the table is empty, the scan exhausts the count, or all selected values are zero. On the per-frame tick path, invoked by sub_4EE2D0 (004EE2D0).
    // UNKNOWN: Identity: char __thiscall sub_4CE380(_DWORD *this, float *a2); ABI label 'Float Comparison with Constants Table' (LEGACY); packet marks on_frame_path [abi:lead, function:0x004CE380, source:raw]
    // ASSIGNMENT: v2 = this[15] (offset 0x3C): load the entry count of the constant table [field:this:0x0000003C, source:raw]
    // GUARD: When the entry count is non-positive (v2 <= 0), return 0: no entries to scan [field:this:0x0000003C, source:raw]
    // LOOP: Iterate entries starting at this + 16 (entry array base at offset 0x40); each element is a pointer, and the type ID is read at entry+4 (offset 0x4 within the object pointed to by this[16]) [field:this:0x00000040, field:*(this+0x40):0x00000004, source:raw]
    // GUARD: When the type ID is 0, break the scan (entry terminator) [field:*(this+0x40):0x00000004, source:raw]
    // ASSIGNMENT: Select the candidate float by type ID: type 1 reads a2[10], type 5 reads a2[12], any other non-zero type reads a2[11] [source:raw]
    // GUARD: When the selected candidate float is zero, continue to the next entry; when the index reaches the count, return 0 [field:this:0x0000003C, source:raw]
    // RETURN: Return 1 as soon as a non-zero candidate float is found [source:raw]
    // CALL: Invoked by sub_4EE2D0 (004EE2D0) on the per-frame tick path [caller:0x004EE2D0]

    // Conservative worker pseudocode:
    //   char sub_4CE380(_DWORD *this, float *a2) {
    //     int count = this[15];
    //     if (count <= 0) return 0;
    //     for (int i = 0; ; ++i) {
    //       _DWORD *entry = this[16 + i];
    //       int type = *(_DWORD*)(entry + 1);
    //       if (type == 0) break;
    //       double v7;
    //       if (type == 1)      v7 = a2[10];
    //       else if (type == 5) v7 = a2[12];
    //       else                v7 = a2[11];
    //       if (v7 == 0.0) { if (++i >= count) return 0; continue; }
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The flt_59E440 global (ZeroThreshold ~0.0f) is flagged by packet facts and prior analysis but appears nowhere in the raw decompiled source; the zero test here is against the literal 0.0
    // UNRESOLVED: The meaning of the type IDs (1 and 5) and the a2 float-field roles (a2[10], a2[11], a2[12]) are inferred from prior particle analysis, not proven in this scope
    // UNRESOLVED: The owning object is UnknownObject
}
