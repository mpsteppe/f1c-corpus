// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595A1F
// Canonical corpus name: sub_595A1F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595A1F_00595a1f.c

void UnknownObject::CRTFileHandleRead()
{
    // Returns the raw Windows handle for a CRT file descriptor entry. Guards the descriptor index against the open file count (uNumber), locates the entry as dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) (a block table with 32 entries per 36-byte stride), and returns the handle dword at the entry base when the open flag (bit 0 of the byte at entry + 4) is set. On an out-of-range index or a closed entry it writes TLS error 9 via TLSOffsetGetter and clears the extended error slot via TLSOffsetGetter_afd8, then returns -1.
    // GUARD: Descriptor index a1 is validated against the open file count uNumber; the table lookup only runs while a1 < uNumber [global:0x008D4A20, source:raw]
    // CALCULATION: Entry address = dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F): a1 selects one of the pointer slots (a1 >> 5), then an entry within a 32-entry block at 36-byte stride (a1 & 0x1F) [global:0x008D4920, source:raw]
    // GUARD: Open-flag test: the byte at entry + 4 must have bit 0 set; when set the function returns the handle dword stored at the entry base [global:0x008D4920, source:raw]
    // ASSIGNMENT: Failure path writes TLS error code 9 through the TLSOffsetGetter pointer and clears the extended error slot through TLSOffsetGetter_afd8 (literal 0) [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // RETURN: Returns the entry handle dword on success, or -1 on an out-of-range index or closed entry; called by HandleCloseWithErrorReporting (0058C38E), FileSeekViaSetFilePointer (0058C789), sub_592891 (00592891), FilePointerSeekWithErrorHandling (00595F82), sub_59797B (0059797B) and sub_59B650 (0059B650) [caller:0x0058C38E, caller:0x0058C789, caller:0x00592891, caller:0x00595F82, caller:0x0059797B, caller:0x0059B650, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 < uNumber) {
    //     entry = dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F);
    //     if (entry->flags & 1) return entry->handle;
    //   }
    //   *(int*)TLSOffsetGetter() = 9;
    //   *(int*)TLSOffsetGetter_afd8() = 0;
    //   return -1;
    // UNRESOLVED: The 36-byte entry layout (handle dword at offset 0, flags byte at offset 4) is inferred from the raw accesses only; the full CRT file-entry structure is not defined in this packet
    // UNRESOLVED: The meaning of the extended error slot written via TLSOffsetGetter_afd8 is not documented beyond the literal 0
}
