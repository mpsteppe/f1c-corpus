// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FC60
// Canonical corpus name: sub_58FC60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58FC60_0058fc60.c

void UnknownObject::FindFirstCharInSet()
{
    // __cdecl helper that returns the first character of byte string a1 which also appears in byte string a2. It first builds a 256-bit membership set (32-byte bit array v6, zeroed via memset) from the characters of a2 using _bittestandset, then scans a1 with _bittest until the first match. On a match it returns the byte-cast value (_BYTE)a1 - 1 (a Hex-Rays degradation of the original pointer/offset return); if no character matches it returns 0. Only known caller is sub_588A34.
    // LOOP: Loop over byte string a2, inserting each character into a 32-byte (256-bit) set v6 via _bittestandset until the terminating NUL is reached [function:0x0058FC60, source:raw]
    // LOOP: Loop over byte string a1, testing each character against the set v6 via _bittest until the terminating NUL is reached [function:0x0058FC60, source:raw]
    // RETURN: On the first match, return the byte-cast value (_BYTE)a1 - 1; otherwise break on a1's NUL and return 0 [function:0x0058FC60, source:raw]

    // Conservative worker pseudocode:
    //   char FindFirstCharInSet(_BYTE* a1, _BYTE* a2) {
    //     byte set[32] = {0};
    //     for (_BYTE* p = a2; *p; ++p)
    //       set[*p >> 3] |= 1 << (*p & 7);   // _bittestandset on 256-bit v6
    //     for (_BYTE* p = a1; *p; ++p)
    //       if (set[*p >> 3] & (1 << (*p & 7)))  // _bittest
    //         return (_BYTE)p - 1;          // match (degraded pointer return)
    //     return 0;
    //   }
    // UNRESOLVED: field:this:0x00000000 is a spurious getter prelabel artifact: the function is __cdecl with two pointer arguments and no 'this' object
    // UNRESOLVED: The prelabel template 'returns field 0x0 of this, no side effects' is inaccurate for this two-string set-membership search
    // UNRESOLVED: Return semantics are unclear: Hex-Rays renders the match result as (byte)a1 - 1, likely a degraded pointer-returning strpbrk-like helper
    // UNRESOLVED: Caller sub_588A34 is the only known caller; how it consumes the return value is not established
}
