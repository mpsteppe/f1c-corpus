// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D4C0
// Canonical corpus name: TestAndFreeWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TestAndFreeWrapper_0053d4c0.c

void UnknownObject::testAndFreeResource()
{
    // Calls GlobalResourceCleanup on the object pointed to by field this+0x0 and returns -1 on non-zero result. Otherwise, if the object pointer is non-null, frees it via FreeWrapper_7bcf and returns 0.
    // CALL: GlobalResourceCleanup(*this) — global resource cleanup on the object at field this+0x0 [callee:0x0053C4D0, field:this:0x00000000]
    // GUARD: If GlobalResourceCleanup returns non-zero, the failure path is taken [callee:0x0053C4D0]
    // RETURN: Returns -1 when the cleanup reported failure [source:raw]
    // GUARD: If the object pointer at field this+0x0 is non-null, the free path is taken [field:this:0x00000000]
    // CALL: FreeWrapper_7bcf(*this) — frees the wrapped resource object [callee:0x00587BCF, field:this:0x00000000]
    // RETURN: Returns 0 on the success path [source:raw]

    // Conservative worker pseudocode:
    //   int testAndFreeResource(void** this) {
    //     if (GlobalResourceCleanup(*this)) return -1;
    //     if (*this) FreeWrapper_7bcf(*this);
    //     return 0;
    //   }
    // UNRESOLVED: Relationship between GlobalResourceCleanup and the freed object at field this+0x0 is unknown.
    // UNRESOLVED: Object type is unknown; caller VidMan_Exit (0x004FAD00) suggests video-manager shutdown path but this is not established.
    // UNRESOLVED: Structural-twin prelabel to MultiFieldPointerFree (00414380) is DERIVED and unverified; it does not confirm this object's type.
}
