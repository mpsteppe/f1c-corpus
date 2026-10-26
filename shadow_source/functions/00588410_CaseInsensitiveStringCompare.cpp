// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588410
// Canonical corpus name: sub_588410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588410_00588410.c

void UnknownObject::CaseInsensitiveStringCompare()
{
    // Case-insensitive comparison of two null-terminated byte strings (a1, a2), returning <0 / 0 / >0 in strcmpi order. Two paths selected by a mode flag dword_8D3F30: a locale-aware path that serializes access via a refcount (dword_8D5A5C) plus critical section 19 and folds each byte through sub_58B4D4, and a simple ASCII fast path that folds A-Z inline with the 0x20 bit. Called from ~126 name/string lookup sites, consistent with a general-purpose case-insensitive string-compare utility.
    // GUARD: If dword_8D3F30 (locale-aware-mode flag) is nonzero take the locale-aware path with refcount/critical-section serialization and sub_58B4D4 folding; otherwise take the inline-ASCII path. [global:0x008D3F30, source:raw]
    // CALL: InterlockedIncrement(&dword_8D5A5C): acquire the refcount that keeps the compare table/critical-section state alive during the locale-aware path. [global:0x008D5A5C, source:raw]
    // GUARD: If dword_8D5A58 > 0, release the refcount and serialize via critical section 19 (v10 = 1); otherwise stay on the refcount path (v10 = 0). [global:0x008D5A58, source:raw]
    // CALL: InterlockedDecrement(&dword_8D5A5C): drop the refcount before entering critical section 19. [global:0x008D5A5C, source:raw]
    // CALL: CriticalSectionLazyInitEnter(19): lazily initialized critical section 19 guards the locale-aware compare. [callee:0x0058DFEA, source:raw]
    // ASSIGNMENT: v10 = 1 when critical-section mode was entered, else 0; selects the exit path (CritSectLeave vs InterlockedDecrement). [source:raw]
    // LOOP: Byte-by-byte compare: read chars from a2 and a1, fold each through sub_58B4D4, compare the folded bytes; terminates on NUL or first mismatch. [callee:0x0058B4D4, source:raw]
    // CALCULATION: On folded mismatch compute the sign result: -1 when folded(a1) < folded(a2), +1 when greater. [source:raw]
    // CALL: Exit the locale-aware path: CritSectLeave(19) if v10, else InterlockedDecrement(&dword_8D5A5C) to release the refcount. [callee:0x0058E04B, global:0x008D5A5C, source:raw]
    // RETURN: Return the locale-aware compare result. [source:raw]
    // LOOP: ASCII fast path: byte-by-byte compare over a2 and a1 with inline case folding; terminates on NUL or first mismatch. [source:raw]
    // CALCULATION: Inline tolower: if a char is in 'A'..'Z' ((char - 65) < 0x1A) add 0x20, else leave unchanged. [source:raw]
    // CALCULATION: On folded mismatch compute the sign result: -1 when folded(a1) < folded(a2), +1 when greater. [source:raw]
    // RETURN: Return the ASCII-path compare result. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3F30) {
    //       InterlockedIncrement(&dword_8D5A5C);
    //       v10 = (dword_8D5A58 > 0) ? (InterlockedDecrement(&dword_8D5A5C), CriticalSectionLazyInitEnter(19), 1) : 0;
    //       for (a = 255; a != 0; ) {
    //           b = fold(*a2++); a = fold(*a1++);
    //           if (a != b) { result = (a < b) ? -1 : 1; break; }
    //       }
    //       if (v10) CritSectLeave(19); else InterlockedDecrement(&dword_8D5A5C);
    //       return result;
    //   } else {
    //       for (a = 255; a != 0; ) {
    //           a = tolower(*a2++); b = tolower(*a1++);
    //           if (a != b) return (a < b) ? -1 : 1;
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: The raw source labels the locale-mode guard dword_8D3F38 while the packet globals table lists 0x008D3F30 (dword_8D3F30); the packet table address is used and the spelling discrepancy is noted.
    // UNRESOLVED: dword_8D5A58 threshold semantics (critical-section vs refcount-only mode) are not named; no writer evidence is in the packet.
    // UNRESOLVED: sub_58B4D4's exact folding transform (character-type table / locale handling) is not described by the packet.
    // UNRESOLVED: Function is __cdecl (no this pointer); its ~126 callers span name/string lookup sites but no owning class is evidenced, so owner stays UNKNOWN.
    // UNRESOLVED: Literals 65, 0x1A, 0x20, 255 and 19 come only from the raw source text and have no independent evidence entry.
}
