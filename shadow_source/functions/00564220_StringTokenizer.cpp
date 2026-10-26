// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564220
// Canonical corpus name: StringTokenizer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringTokenizer_00564220.c

void UnknownObject::StringTokenizer()
{
    // Stateful single-byte-delimiter string tokenizer (strtok-like) over the shared scan-state global dword_8CFAE4. If a1 is non-null it becomes the new scan state, otherwise a1 is reloaded from dword_8CFAE4 to resume a previous tokenization. Scans for the first byte equal to delimiter a2 or the end of string; if the scan never advanced the result is NULL, otherwise the delimiter is overwritten with a NUL terminator, the saved state advances past it, and the token start pointer is returned.
    // GUARD: If a1 is non-null, persist it as the new scan position in global dword_8CFAE4; otherwise reload a1 from dword_8CFAE4 to resume the previous tokenization. [global:0x008CFAE4, source:raw]
    // ASSIGNMENT: Remember the scan start as the token candidate v3 = a1 and load its first character v2 = *a1. [source:raw]
    // GUARD: If the string is empty (*a1 == 0), no token exists and the result is NULL. [source:raw]
    // LOOP: do-while scan advancing a1 until the current character equals delimiter a2 or the end of string is reached, storing each new position into global dword_8CFAE4. [global:0x008CFAE4, source:raw]
    // GUARD: If the scan never advanced (a1 == v3, delimiter at the first position), the produced token is empty so v3 becomes NULL. [source:raw]
    // ASSIGNMENT: When a delimiter was reached (current character non-zero), terminate the token by writing 0 at a1 and advance global dword_8CFAE4 past the delimiter. [global:0x008CFAE4, source:raw]
    // RETURN: Return the token start pointer v3, or NULL when no token was produced. [source:raw]
    // CALL: Called by sub_564110 (0x00564110) and AudioMixerPollingUpdateLoop (0x00564390), which share the scan-state global. [caller:0x00564110, caller:0x00564390, function:0x00564220]

    // Conservative worker pseudocode:
    //   const char *tokenize(const char *buffer, char delimiter) {
    //     if (buffer) dword_8CFAE4 = (int)buffer;
    //     else buffer = (const char *)dword_8CFAE4;
    //     const char *start = buffer;
    //     if (!*buffer) return 0;
    //     do {
    //       if (*buffer == delimiter) break;
    //       dword_8CFAE4 = (int)++buffer;
    //     } while (*buffer);
    //     if (buffer == start) start = 0;
    //     if (*buffer) { *buffer = 0; ++dword_8CFAE4; }
    //     return start;
    //   }
    // UNRESOLVED: Global dword_8CFAE4 is shared tokenizer state; the owning object that resets it between sessions is unknown.
    // UNRESOLVED: Only a single-byte delimiter is supported; the delimiter-set semantics used by the callers are unknown.
    // UNRESOLVED: The exact callers' token-consumption context (which string, which delimiter) is not evidenced here.
}
