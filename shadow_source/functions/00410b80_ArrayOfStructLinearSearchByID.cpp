// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410B80
// Canonical corpus name: ArrayOfStructLinearSearchByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfStructLinearSearchByID_00410b80.c

void UnknownObject::ArrayOfStructLinearSearchByID()
{
    // Linear search through an array of structs, comparing the first DWORD (ID field at offset 0x114 within each element) against a2. The search array base is this[17] (offset 0x44), first element at base+208, stride 198 DWORDs (0x318 bytes) per element; element count is this[15] (offset 0x3C). On match returns a pointer into a parallel result array this[16] (offset 0x40) with 36-byte stride per element. Returns 0 when the count is non-positive or the ID is not found. On the per-frame tick path, invoked by CollisionDetectionSystem (004EA970).
    // UNKNOWN: Identity: int __thiscall sub_410B80(_DWORD *this, int a2); ABI label 'Linear search through an array of structures for' (LEGACY); packet marks on_frame_path [abi:lead, function:0x00410B80, source:raw]
    // ASSIGNMENT: v2 = this[15] (offset 0x3C): load the element count of the search array [field:this:0x0000003C, source:raw]
    // GUARD: When the element count is non-positive (v2 <= 0), return 0 (not found): no elements to search [field:this:0x0000003C, source:raw]
    // LOOP: Linear scan: cursor i starts at the first search element (this[17] base at 0x44, element start at base+208) and advances 198 DWORDs (0x318 bytes) per element, comparing the element's first DWORD (ID field at offset 0x114) against a2 [field:this:0x00000044, field:this:0x00000114, source:raw]
    // GUARD: Increment the index; when the index reaches the element count without a match, return 0 (not found) [field:this:0x0000003C, source:raw]
    // CALCULATION: On ID match, return this[16] (offset 0x40) + 36 * index — a pointer into the parallel result array whose elements have a 36-byte stride [field:this:0x00000040, source:raw]
    // RETURN: Return 0 on the empty-table and not-found paths; return the result-array pointer on the match path [source:raw]
    // CALL: Invoked by CollisionDetectionSystem (004EA970) on the per-frame tick path [caller:0x004EA970]

    // Conservative worker pseudocode:
    //   int sub_410B80(_DWORD *this, int a2) {
    //     int count = this[15];
    //     if (count <= 0) return 0;
    //     for (int i = 0; ; ++i) {
    //       _DWORD *elem = (_DWORD*)(this[17] + 208 + 198 * i);
    //       if (*elem == a2) return this[16] + 36 * i;
    //       if (i + 1 >= count) return 0;
    //     }
    //   }
    // UNRESOLVED: The semantic names of the search array (this[17]), the result array (this[16]) and the ID field (offset 0x114) are inferred from prior analysis, not proven in this scope
    // UNRESOLVED: The owning object is UnknownObject; the ID field is the first DWORD of each element, consistent with prior analysis but not independently established here
}
