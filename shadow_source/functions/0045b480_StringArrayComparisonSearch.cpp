// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B480
// Canonical corpus name: StringArrayComparisonSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringArrayComparisonSearch_0045b480.c

void UnknownObject::StringArrayComparisonSearch()
{
    // Searches a fixed 8-entry array of strings on the object. Each entry's name string lives at byte offset 60 with stride 92 and is compared against a2 via strcmp. On a match the per-entry payload float at byte offset 92 * v2 + 144 is set to 5.0 and 1 is returned; if all 8 entries are exhausted 0 is returned. Invoked by UtilityFunction_b9c0.
    // LOOP: Scan the 8-entry string array: start i at this + 60 (first entry name, byte offset 60) and advance by stride 92 while strcmp(i, a2) is non-zero. [source:raw]
    // GUARD: After each failed comparison increment the entry counter v2; when v2 reaches 8 return 0 (no matching entry). [source:raw]
    // ASSIGNMENT: On a match write the float 5.0 into the matched entry's payload at byte offset 92 * v2 + 144. [source:raw]
    // RETURN: Return 1 on a match, 0 when the scan exhausts all 8 entries without a match. [function:0x0045B480, source:raw]
    // CALL: Invoked by UtilityFunction_b9c0 (0045B9C0) to look up an entry by name and mark it selected. [caller:0x0045B9C0]

    // Conservative worker pseudocode:
    //   v2 = 0;
    //   for (i = this + 60; strcmp(i, a2) != 0; i += 92) {
    //     if (++v2 >= 8) return 0;
    //   }
    //   *(float *)(this + 92 * v2 + 144) = 5.0;
    //   return 1;
    // UNRESOLVED: Read-only global dword_59F07C is flagged by packet facts but does not appear in the decompiled body; its role (possible helper or selection state) is unknown.
    // UNRESOLVED: The semantic meaning of the payload float 5.0 and of the string entries (selectable settings/menu options) is not established; the entry layout beyond the name at +60 and payload float at +144 is unknown.
    // UNRESOLVED: strcmp is called by the loop but is absent from the packet callee list, so no callee evidence ref exists for it.
}
