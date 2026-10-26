// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005897CA
// Canonical corpus name: sub_5897CA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5897CA_005897ca.c

void UnknownObject::TokenizeStringByDelimiterSet()
{
    // String tokenizer: builds a 32-byte bit map of delimiter characters from a2, then scans a1 (or the thread-local default buffer at TLS+24) for the first character not in the set, advances to the next delimiter, truncates it with a NUL, and stores the new scan position back into TLS+24. Returns the token start, or 0 when no token is found.
    // CALL: v8 = TLSValueRetrievalWithInit() to obtain the thread-local state pointer. [callee:0x0058E0C7, source:raw]
    // CALL: memset(v7, 0, 32) zeroes the delimiter bitmap. [source:raw]
    // LOOP: For each character in a2 (until NUL), set its bit: v7[char >> 3] |= 1 << (char & 7). [source:raw]
    // ASSIGNMENT: v4 = a1; when a1 is NULL, v4 = the default pointer stored at TLS offset +24. [source:raw]
    // GUARD: Read the current buffer character via a1/this and test whether its bit is set in v7 while the character is nonzero. [field:this:0x00000000, source:raw]
    // LOOP: Advance v4 while the current character's bit is set in the delimiter bitmap and the character is not NUL (skips leading delimiters). [source:raw]
    // ASSIGNMENT: v5 = v4 records the start of the token. [source:raw]
    // LOOP: Scan from v5: while *v4 != 0, if the current character's bit is set in the bitmap, write 0 there (truncate) and stop. [source:raw]
    // ASSIGNMENT: Store the final scan position back at TLS offset +24 so the next call continues after this token. [source:raw]
    // RETURN: return v5 when a token was found (v4 != v5), otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *TokenizeStringByDelimiterSet(_BYTE *a1, char *a2) {
    //     char *v4; _BYTE *v5; _BYTE v7[32]; int v8;
    //     v8 = TLSValueRetrievalWithInit();
    //     memset(v7, 0, sizeof(v7));
    //     char v3;
    //     do { v3 = *a2; v7[(unsigned char)*a2 >> 3] |= 1 << (*a2 & 7); ++a2; } while ( v3 );
    //     v4 = a1; if ( !a1 ) v4 = *(_BYTE **)(v8 + 24);
    //     while ( ((unsigned char)(1 << (*v4 & 7)) & v7[(unsigned char)*v4 >> 3]) != 0 && *v4 ) ++v4;
    //     v5 = v4;
    //     while ( *v4 ) { if ( ((unsigned char)(1 << (*v4 & 7)) & v7[(unsigned char)*v4 >> 3]) != 0 ) { *v4++ = 0; break; } ++v4; }
    //     *(_DWORD *)(v8 + 24) = v4;
    //     return v4 != v5 ? v5 : 0;
    //   }
    // UNRESOLVED: Semantics of the thread-local slot at TLS+24 (persistent tokenizer state buffer) unknown.
    // UNRESOLVED: Cluster prelabel marks this as a structural twin of ConditionalFreeWithBit0Flag (00404f70); whether the twin shares this tokenizer semantics is unverified.
    // UNRESOLVED: Behavior when the input buffer contains no delimiter is caller-dependent; return of 0 for empty token is assumed.
}
