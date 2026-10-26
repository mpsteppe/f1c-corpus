// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058AE69
// Canonical corpus name: sub_58AE69
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58AE69_0058ae69.c

void UnknownObject::FdopenWithMode()
{
    // CRT-style _fdopen implementation: validates the open-file slot a1 against uNumber and the critical-section open flags, allocates a stream structure via sub_58C5AC, parses the mode string a2 ('r'/'w'/'a' with '+'/t'/b'/c'/n' modifiers), ORs in default mode flags, records the descriptor, bumps the global open-file count, leaves the address-range critical section, and returns the stream pointer (0 on any failure).
    // GUARD: Guard: if a1 >= uNumber (maximum open file handles) return 0. [global:0x008D4A20, source:raw]
    // GUARD: Guard: if the open bit (bit 0) of the per-handle entry (dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) is not set, the handle is not open and the function returns 0. [global:0x008D4920, source:raw]
    // CALL: Call sub_58C5AC() to allocate a FILE stream structure; if it returns 0, return 0. [callee:0x0058C5AC, source:raw]
    // STATE_TRANSITION: Dispatch on the mode string's first character: 'r' (114) sets flags at v2+12 to 1, 'w' (119) and 'a' (97) set it to 2; any other character invalidates the stream (v2 = 0) and jumps to the cleanup path. [source:raw]
    // ASSIGNMENT: OR the default mode flags dword_8D41BC into the stream flags field at v2+12. [global:0x008D41BC, source:raw]
    // LOOP: Loop over the remaining mode characters, breaking on end-of-string or after a parse error. [source:raw]
    // STATE_TRANSITION: Character '+' (v7-43 == 0): OR bit 0x80 into the flags dword at v2+12 (mask 0x7C | 0x80); if bit 0x80 was already set, treat as a parse error. [source:raw]
    // STATE_TRANSITION: Characters 'b' (v7 == 98) and 't' (v7 == 116): set the repeat-guard marker v14; if v14 was already set, treat as a parse error. [source:raw]
    // STATE_TRANSITION: Characters 'c' (v7 == 99) and 'n' (v7 == 110): clear bit 0x40 of the byte at v2+13; if the guard v5 was already set, treat as a parse error. [source:raw]
    // ASSIGNMENT: Increment the global open-file count dword_8D3EC8 after a successful parse. [global:0x008D3EC8, source:raw]
    // ASSIGNMENT: Store the source descriptor a1 into the stream structure at v2+16. [source:raw]
    // CALL: Call AddressRangeCriticalSectionLeave(v2) to release the critical section guarding the stream structure. [callee:0x0058C203, source:raw]
    // RETURN: Return the stream pointer v2 on success, or 0 on any earlier failure path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58AE69(int fd, BYTE* mode) {
    //     if (fd >= uNumber) return 0;
    //     if (!(*(BYTE*)(dword_8D4920[fd >> 5] + 36 * (fd & 0x1F) + 4) & 1)) return 0;
    //     int st = sub_58C5AC();
    //     if (!st) return 0;
    //     if (*mode == 'r') *(DWORD*)(st+12) = 1;
    //     else if (*mode == 'w' || *mode == 'a') *(DWORD*)(st+12) = 2;
    //     else { st = 0; goto cleanup; }
    //     *(DWORD*)(st+12) |= dword_8D41BC;
    //     // for each remaining mode char:
    //     //   '+' -> set bit 0x80 of flags (error if already set)
    //     //   'b'/'t' -> set marker v14 (error if already set)
    //     //   'c'/'n' -> clear bit 0x40 of byte (st+13) (error if already cleared)
    //     ++dword_8D3EC8;
    //     *(DWORD*)(st+16) = fd;
    //   cleanup:
    //     AddressRangeCriticalSectionLeave(st);
    //     return st;
    //   }
    // UNRESOLVED: The mode-parser guards use two markers (v14 for 'b'/'t', v5 for 'c'/'n') that only detect duplicates; the semantic difference these markers encode in the stream structure is not visible in this function.
    // UNRESOLVED: Field offsets of the stream structure (v2+12 flags, v2+13 byte, v2+16 descriptor) are raw byte offsets, not named fields.
    // UNRESOLVED: The critical-section array dword_8D4920 layout (36-byte entries, per-handle bit at +4) is taken from the raw source only.
    // UNRESOLVED: Semantics of dword_8D41BC default flags and the 0x80/0x40 bit meanings are unproven.
}
