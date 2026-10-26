// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005667B0
// Canonical corpus name: InPlaceStringShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InPlaceStringShift_005667b0.c

void UnknownObject::InPlaceStringShift()
{
    // In-place string range shift helper. Given a pointer to a string buffer (this), a destination index a2 and a source index a3, copies the substring from a3 through the terminator leftward by (a3 - a2), overwriting the range [a2, a3). Returns 0 on success and -1 when the buffer is null while a shift is requested, when a2 is negative, or when a3 exceeds the string length.
    // GUARD: Guard on the buffer pointer stored in this: the shift body runs only when the buffer is non-null. [field:this:0x00000000, source:raw]
    // CALL: Compute the length of the current buffer contents (strlen) into v5. [source:raw]
    // GUARD: Return -1 when destination index a2 is negative. [source:raw]
    // GUARD: Return -1 when source index a3 exceeds the computed string length v5. [source:raw]
    // LOOP: Shift the trailing substring left: for each cursor v6 from a3 through the terminator index v5, copy the character at index v6 to index v6 - (a3 - a2), then advance v6. [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on success; return -1 from the null-buffer branch when either a2 or a3 is non-zero (a shift was requested on a null buffer). [function:0x005667B0, abi:lead]

    // Conservative worker pseudocode:
    //   int InPlaceStringShift(char **buf, int dest, int src) {
    //     if (*buf) {
    //       int len = strlen(*buf);
    //       if (dest < 0) return -1;
    //       if (src > len) return -1;
    //       int i = src;
    //       do { (*buf)[i - (src - dest)] = (*buf)[i]; ++i; } while (i <= len);
    //     } else if (dest || src) {
    //       return -1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: a2/a3 meaning as destination/source indices is inferred; there is no guard for a2 > a3, so the copy direction and the caller's ordering constraint are unproven.
    // UNRESOLVED: The caller context that defines which range is being deleted or moved is not available in the packet.
}
