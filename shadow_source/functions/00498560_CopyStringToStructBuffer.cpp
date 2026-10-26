// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498560
// Canonical corpus name: sub_498560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_498560_00498560.c

void UnknownObject::CopyStringToStructBuffer()
{
    // If the input string a2 is non-empty, copies up to 63 characters into a stack buffer, null-terminates it, passes it to a string-keyed lookup (sub_566810 against dword_5CC79C) clearing the first byte of any returned entry, then copies the sanitized buffer into the this struct at offset +5400.
    // GUARD: Guard: proceed only when a2 is non-null and strlen(a2) is non-zero. [source:raw]
    // CALL: Bounded copy into the 64-byte stack buffer v4: sub_587DD0(v4, a2, 63). [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Force null termination: v4[63] = 0. [source:raw]
    // CALL: String-keyed lookup: v3 = sub_566810(v4, &dword_5CC79C). [callee:0x00566810, global:0x005CC79C, source:raw]
    // GUARD: Guard: if the lookup returned a non-null entry v3, clear its first byte. [callee:0x00566810, source:raw]
    // ASSIGNMENT: Clear the returned entry's first byte: *v3 = 0. [callee:0x00566810, source:raw]
    // ASSIGNMENT: Copy the sanitized buffer into the struct: strcpy(this + 5400, v4). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_498560(char *this, const char *a2) {
    //     if (a2 && strlen(a2)) {
    //       char v4[64];
    //       sub_587DD0(v4, a2, 63);
    //       v4[63] = 0;
    //       byte *v3 = (byte*)sub_566810(v4, &dword_5CC79C);
    //       if (v3) *v3 = 0;
    //       strcpy(this + 5400, v4);
    //     }
    //   }
    // UNRESOLVED: Role of sub_566810 and the global dword_5CC79C (lookup/dedup semantics) and why the first byte of the found entry is cleared.
    // UNRESOLVED: Identity of the owning struct and meaning of the string buffer at this + 5400.
}
