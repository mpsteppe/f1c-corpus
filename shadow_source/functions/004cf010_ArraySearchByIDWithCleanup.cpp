// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CF010
// Canonical corpus name: ArraySearchByIDWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArraySearchByIDWithCleanup_004cf010.c

void UnknownObject::ArraySearchByIDWithCleanup()
{
    // Searches a strided element array owned by the __thiscall object for an element whose second dword (i[1]) matches a2, then calls the cleanup helper sub_4CB5E0 on the matched element and returns its result. The count of elements to scan comes from this+0x10 and the array pointer from this+0x14. Returns the element count (0 when the count is non-positive) when no match is found before the scan limit.
    // ASSIGNMENT: Read element count v2 = this[4] (field at +0x10). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Initialize result = 0. [source:raw]
    // GUARD: If v2 <= 0, skip the scan and return 0. [source:raw]
    // ASSIGNMENT: Seed scan pointer i = this[5] (field at +0x14), the array base. [field:this:0x00000014, source:raw]
    // LOOP: Walk the array at stride 27 dwords (0x6C bytes) while i[1] != a2. [source:raw]
    // CALCULATION: Increment the scanned-element counter; if ++result >= v2 the array was exhausted without a match and result is returned. [source:raw]
    // CALL: On a match, call sub_4CB5E0(i) on the matched element and return its result. [callee:0x004CB5E0, source:raw]
    // RETURN: Return result: 0 for an empty/non-positive count, the element count when no match exists, or the cleanup helper's result on a match. [source:raw]
    // CALL: Invoked by AIWaypointPathCheckerRenderer (0x004024F0) as a lookup-and-cleanup over its element list. [caller:0x004024F0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CF010(_DWORD *this, int a2) {
    //     int count = this[4];
    //     int result = 0;
    //     if (count > 0) {
    //       for (_DWORD *i = (_DWORD *)this[5]; i[1] != a2; i += 27) {
    //         if (++result >= count) return result;
    //       }
    //       return sub_4CB5E0(i);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Field at +0x18 is read-only per static facts but is not referenced by the raw decompiled source; its role is unknown.
    // UNRESOLVED: What sub_4CB5E0 does to the matched element (removal/cleanup) is not visible here.
    // UNRESOLVED: Semantic role of the matched ID in i[1] and the owning container type are unknown.
}
