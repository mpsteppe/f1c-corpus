// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434420
// Canonical corpus name: DoublePointerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublePointerFree_00434420.c

void UnknownObject::DoublePointerFree()
{
    // Destructor-style teardown for a small object owning a double pointer. Reads the flag byte at this+8; when it is set and the owning pointer at this+0 is non-null, the inner allocation (*v2) is freed first via FreeWrapper_7bcf, then the outer pointer v2 itself is freed. Returns the flag value read at entry; when the flag is clear the object is left untouched.
    // GUARD: Reads the flag byte at this+8; if it is zero the function returns immediately without freeing anything. [source:raw, field:this:0x00000008]
    // GUARD: When the flag is set, loads the owning pointer from this+0 and proceeds only if it is non-null. [source:raw, field:this:0x00000000]
    // GUARD: If the inner allocation (*v2, first pointer of the object at this+0) is non-null, it is freed first with FreeWrapper_7bcf. [source:raw, field:obj:0x00000000, callee:0x00587BCF]
    // CALL: Frees the outer pointer v2 with FreeWrapper_7bcf and returns the saved flag value. [source:raw, callee:0x00587BCF]
    // CALL: Invoked by sub_431BE0, DirectoryFileEnumerator (00431DB0) and StandingsDisplay (0046A560) as a teardown helper. [caller:0x00431BE0, caller:0x00431DB0, caller:0x0046A560]

    // Conservative worker pseudocode:
    //   flag = this[8];
    //   if (!flag) return flag;
    //   outer = *(LPVOID**)this;
    //   if (*(DWORD*)this) {
    //     if (*outer) FreeWrapper_7bcf(*outer);
    //     return FreeWrapper_7bcf(outer);
    //   }
    //   return flag;
    // UNRESOLVED: Whether the byte at this+8 is a reference count or an ownership flag, and what the inner/outer allocations own, is unknown
    // UNRESOLVED: The prelabel structural twin DestructorWithDoubleFreePattern (00418d60) is DERIVED; the owning class is unconfirmed
}
