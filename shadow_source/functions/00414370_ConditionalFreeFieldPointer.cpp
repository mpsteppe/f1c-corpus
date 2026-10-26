// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414370
// Canonical corpus name: ShortComputation_4370
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4370_00414370.c

void UnknownObject::ConditionalFreeFieldPointer()
{
    // Conditional teardown helper (thiscall): reads the pointer field at this+0; if non-null, frees it through FreeWrapper_7bcf and returns that wrapper's result; otherwise returns the null field value. Structural twin of ConditionalFreeWithBit0Flag (00404F70). Widely used as a list/node/drawable cleanup primitive across many teardown paths.
    // ASSIGNMENT: result = *this: read the pointer stored at field this+0. [field:this:0x00000000, source:raw]
    // GUARD: Null guard on the field value: when *this is non-null the free path runs; otherwise the function returns the (null) field value directly. [field:this:0x00000000, source:raw]
    // CALL: When the field is non-null, call FreeWrapper_7bcf(*this) passing the stored pointer to be freed. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result in the non-null branch, or the original null field value in the null branch. [source:raw]
    // CALL: Invoked as a cleanup primitive by GlobalListTripleCleanupWithTimerRemoval (00414210), DrawableResourceCleanup (004150C0), NamedEntryLookupInFormatList (00415230), FunctionCallWrapper_1470 (00421470), SortedStringTableBuilder (00423530), sub_485EB0, sub_4963D0, StaticInitBulk (004A8B80), DoubleListCleanup (004C1700), MultiFieldCleanup (004C3130), FilterPropertiesListNodeRemover (004C6150), ArrayBlockCleanup (004D7050) and LinkedListDestructorWithChildCleanup (00565E20). [caller:0x00414210, caller:0x004150C0, caller:0x00415230, caller:0x00421470, caller:0x00423530, caller:0x00485EB0, caller:0x004963D0, caller:0x004A8B80, caller:0x004C1700, caller:0x004C3130, caller:0x004C6150, caller:0x004D7050, caller:0x00565E20, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID sub_414370(LPVOID *this) {
    //     LPVOID result = *this;
    //     if (*this)
    //       return (LPVOID)FreeWrapper_7bcf(*this);
    //     return result;
    //   }
    // UNRESOLVED: The behavior of FreeWrapper_7bcf (whether it nulls the field after freeing, and what allocation type it releases) is not verifiable here.
    // UNRESOLVED: The meaning of the pointer at this+0 varies per caller; no shared element type is established.
    // UNRESOLVED: The prelabel cluster relationship to ConditionalFreeWithBit0Flag (00404F70) is DERIVED from structure, not proven.
}
