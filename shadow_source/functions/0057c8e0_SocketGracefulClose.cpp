// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057C8E0
// Canonical corpus name: SocketGracefulClose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketGracefulClose_0057c8e0.c

void UnknownObject::SocketGracefulClose()
{
    // Gracefully closes a socket handle passed by pointer. If the handle is not INVALID_SOCKET (-1) and the graceful flag is set, calls shutdown(SD_SEND) and drains pending data via recv until it returns 0 or an error, then calls closesocket and marks the stored handle as -1 (INVALID_SOCKET). Returns the closesocket result.
    // ASSIGNMENT: Read the socket handle from *a1 into the result register before any state change. [field:this:0x00000000, source:raw]
    // GUARD: If *a1 equals -1 (INVALID_SOCKET), the socket is already closed and the function returns without acting. [guard:0, field:this:0x00000000, source:raw]
    // GUARD: Graceful path only runs when flag a2 is non-zero and shutdown() returns 0. [global:0x0059E328, source:raw]
    // CALL: Call shutdown on the socket to disable further sends. [global:0x0059E328, source:raw]
    // LOOP: Drain loop: call recv(*a1, buf, 256, 0) repeatedly until it returns -1 or 0, discarding any remaining inbound data. [global:0x0059E304, source:raw]
    // CALL: Call closesocket(*a1) to close the socket handle. [global:0x0059E2E8, source:raw]
    // ASSIGNMENT: Write -1 (INVALID_SOCKET) back to *a1 to mark the handle closed. [field:this:0x00000000, source:raw]
    // RETURN: Return the closesocket result. [source:raw]

    // Conservative worker pseudocode:
    //   SOCKET SocketGracefulClose(SOCKET *s, char graceful) {
    //     SOCKET h = *s;
    //     if (h == -1) return h;
    //     if (graceful && shutdown(h, 1) == 0) {
    //       char buf[256];
    //       int n;
    //       do { n = recv(*s, buf, 256, 0); } while (n != -1 && n != 0);
    //     }
    //     SOCKET r = closesocket(*s);
    //     *s = -1;
    //     return r;
    //   }
    // UNRESOLVED: Which module/object owns the SOCKET pointer a1 and when it is valid to call.
    // UNRESOLVED: Whether the 256-byte drain buffer size has protocol-specific significance.
}
