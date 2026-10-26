// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059750A
// Canonical corpus name: ArrayOfStructLinearSearchByID_750a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfStructLinearSearchByID_750a_0059750a.c

void UnknownObject::LinearSearchByID()
{
    // Linear search for an ID. Given a search value a1 and an array base a2, scans an array of 12-byte records whose ID field sits at +4, for the first record whose ID equals a1. The element count is dword_5E7894 (the array span is a2 + 12 * dword_5E7894). Returns the address of the matching record, or 0 when no record matches or the scan leaves the array span. Matches the legacy ABI label Array_of_Struct_Linear_Search_by_ID.
    // CALCULATION: result = a2: start the scan at the array base. [source:raw]
    // GUARD: Short-circuit the loop when the first record already matches: *(a2+4) == a1. [source:raw]
    // LOOP: Linear scan: advance result by the 12-byte record stride while result stays below the array span a2 + 12 * dword_5E7894 and the ID field at result+4 does not equal a1. [global:0x005E7894, source:raw]
    // GUARD: Failure path: return 0 when the scan left the array span (result >= a2 + 12 * dword_5E7894) or the ID field at result+4 still does not equal a1. [global:0x005E7894, source:raw]
    // RETURN: Return the address of the matching record (result). [function:0x0059750A, source:raw]
    // RETURN: Return 0 when no record matches. [function:0x0059750A, source:raw]
    // CALCULATION: Legacy ABI label Array_of_Struct_Linear_Search_by_ID corroborates the scan shape: an array of 12-byte records, ID compared at +4, element count held in dword_5E7894. [abi:lead, global:0x005E7894, source:raw]
    // CALL: Invoked by sub_597388 (0x00597388). [caller:0x00597388, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int LinearSearchByID(int a1, unsigned int a2) {
    //       unsigned int result = a2;
    //       if (*(DWORD *)(a2 + 4) != a1) {
    //           do
    //               result += 12;
    //           while (result < a2 + 12 * dword_5E7894 && *(DWORD *)(result + 4) != a1);
    //       }
    //       if (result >= a2 + 12 * dword_5E7894 || *(DWORD *)(result + 4) != a1)
    //           return 0;
    //       return result;
    //   }
    // UNRESOLVED: The record layout beyond the ID field at +4 is unevidenced; only the 12-byte stride is known.
    // UNRESOLVED: dword_5E7894 is read as the record count, inferred from its use as the loop bound; its writer and initialization are unevidenced.
    // UNRESOLVED: What array a2 points at in the caller sub_597388's context is unevidenced.
}
