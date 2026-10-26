// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462410
// Canonical corpus name: DataTableRowAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DataTableRowAccessor_00462410.c

void UnknownObject::DataTableRowAccessor()
{
    // Copies one fixed-size row (140 bytes) from a data table out of the object whose pointer is stored at this+0, and reads a parallel per-row scalar into *a4. Bounds-checked against the row count stored at obj+0x3E14.
    // GUARD: If a2 < 0 or a2 >= *(*(this) + 15892) (row count field at obj+0x3E14), fail; otherwise proceed. Dereferences this+0 to obtain the table object base. [abi:lead, function:0x00462410, field:this:0x00000000, field:obj:0x00003E14, source:raw]
    // CALCULATION: Row source address = 140 * a2 + *(this) + 916; 140 is the row stride and 916 the data-array offset. [function:0x00462410, field:this:0x00000000, source:raw]
    // CALL: qmemcpy(a3, row source, 0x8C); copies a full 140-byte row into the caller's buffer. [function:0x00462410, source:raw]
    // ASSIGNMENT: *a4 = *(*(this) + 4 * a2 + 15476); copies the per-row scalar at 4*a2 into the caller's DWORD output. [function:0x00462410, field:this:0x00000000, source:raw]
    // RETURN: Return 1 on success. [function:0x00462410, source:raw]
    // RETURN: Return 0 when the row index is out of bounds. [function:0x00462410, source:raw]

    // Conservative worker pseudocode:
    //   bool DataTableRowAccessor(void* this, int row, void* outRow, DWORD* outScalar) {
    //     if (row < 0 || row >= *(DWORD*)(*(DWORD*)this + 15892)) return false;
    //     qmemcpy(outRow, (void*)(140 * row + *(DWORD*)this + 916), 0x8C);
    //     *outScalar = *(DWORD*)(*(DWORD*)this + 4 * row + 15476);
    //     return true;
    //   }
    // UNRESOLVED: Meaning of the parallel 4-byte-per-row scalar array at offset 15476 is unresolved.
    // UNRESOLVED: Semantics of the 916 and 15476 base offsets (not individually tagged as fields) are unresolved.
    // UNRESOLVED: The concrete type of the table object and the row layout are unresolved.
}
