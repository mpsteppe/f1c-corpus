// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562710
// Canonical corpus name: sub_562710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562710_00562710.c

void UnknownObject::SendBufferChunkedOnBackslash()
{
    // Recursive helper that sends a string over a socket in backslash-safe chunks. When the concatenation of the remaining string a4 with the current buffer buf fits in 0x546 bytes it appends it with strcat. Otherwise it scans up to 1350 characters for backslash characters (0x5C), remembering the last even-indexed consecutive backslash as a candidate split point so escaped backslash pairs are not cut apart; if no split point exists in the window it returns the scan end pointer. At a split point it temporarily terminates the string, recurses to flush the buffer, restores the backslash, advances to the split point and repeats. Once the remainder fits, it flushes the accumulated buffer through sub_562610 and copies the remaining tail into buf, then returns.
    // GUARD: If strlen(a4) + strlen(buf) < 0x546 the whole remaining tail fits: strcat(buf, v5) appends it and the function returns 0. [source:raw]
    // LOOP: Otherwise loop while strlen(v5) > 0x546, scanning up to 1350 characters of the tail for backslash bytes. [source:raw]
    // CALCULATION: During the scan count consecutive backslashes in v4; each time the current count is even (v4 % 2 == 0) record v7 = current position as the candidate split point. [source:raw]
    // GUARD: If no backslash was found in the window (v7 == v5) return the scan end pointer instead of splitting. [source:raw]
    // ASSIGNMENT: At a valid split point temporarily write *v7 = 0 to terminate the buffer. [source:raw]
    // CALL: Recursively call sub_562710(buf, (int)v5) to flush the completed prefix through the same chunking logic. [callee:0x00562710, source:raw]
    // ASSIGNMENT: Restore the backslash byte *v7 = 92 after the recursive flush returns. [source:raw]
    // ASSIGNMENT: Advance the remaining tail to the split point: v5 = v7, reset v4 = 0, and re-check whether the buffer plus remainder now fits. [source:raw]
    // CALL: When the remainder finally fits, flush the accumulated buffer through sub_562610(a1, a2, buf) (the socket send path). [callee:0x00562610, source:raw]
    // ASSIGNMENT: Copy the final tail into the buffer with strcpy(buf, v5). [source:raw]
    // RETURN: Return the scan end pointer from the no-split path, or 0 on the appending path. [function:0x00562710, source:raw]

    // Conservative worker pseudocode:
    //   char* SendBufferChunkedOnBackslash(SOCKET* a1, const struct sockaddr* a2, char* buf, const char* a4) {
    //     const char* tail = a4;
    //     if (strlen(a4) + strlen(buf) < 0x546) {
    //       strcat(buf, tail);
    //       return 0;
    //     }
    //     while (strlen(tail) > 0x546) {
    //       int backslashCount = 0;
    //       char* split = (char*)tail;
    //       for (int i = 0; i < 1350; ++i) {
    //         if (tail[i] == 92) {            // backslash '\\'
    //           if (!(backslashCount % 2)) split = &tail[i];  // even backslash = split point
    //           ++backslashCount;
    //         }
    //       }
    //       if (split == tail) return &tail[i];   // no split point in window
    //       *split = 0;
    //       SendBufferChunkedOnBackslash(a1, a2, buf, tail);
    //       *split = 92;
    //       tail = split;
    //       if (strlen(buf) + strlen(split) < 0x546) {
    //         strcat(buf, split);
    //         return 0;
    //       }
    //     }
    //     sub_562610(a1, a2, buf);  // flush accumulated buffer
    //     strcpy(buf, tail);
    //     return 0;
    //   }
    // UNRESOLVED: The constant 0x546 and the scan window of 1350 characters are structural limits whose packet-level meaning is not established; 0x546 may be a wire-packet size limit.
    // UNRESOLVED: The purpose of keeping backslash pairs intact (even/odd counting) suggests escaping conventions in the transmitted data, but the underlying protocol is not documented in the packet.
    // UNRESOLVED: The two named callers (StackBufferZeroInitWithCallback, StackBufferZeroInitWithVTableCall) and the four anonymous ones are not analyzed here; their names look like pipeline heuristics.
    // UNRESOLVED: The return value of the recursive flush is ignored at the call site in the packet source.
    // UNRESOLVED: sub_562610's parameter meaning (socket, sockaddr, buffer) is only inferred from the declared prototype.
}
