// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005020BF
// Canonical corpus name: StreamBinaryRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamBinaryRead_005020bf.c

void UnknownObject::StreamBinaryRead()
{
    // Reads a3 bytes from a tracked binary buffer into the caller's destination a2. The buffer-tracking struct lives at this+0x54 and holds a current read pointer at +0 and a remaining-byte count at +4. If the requested length exceeds the remaining count, GuardedCallWithLongjmp raises a longjmp error with the "read error" string. Otherwise the bytes are copied from the current read pointer, the pointer is advanced by a3, the remaining count is decremented by a3, and a3 is returned as the byte count.
    // ASSIGNMENT: Load the buffer-tracking struct pointer v3 from a1+0x54 [field:this:0x00000054, source:raw]
    // GUARD: Underflow check: if the requested length a3 exceeds the remaining byte count at v3+4, raise the longjmp read error via GuardedCallWithLongjmp with the "read error" string [callee:0x00511869, field:*(this+0x54):0x00000004, global:0x005ADB4C, source:raw]
    // CALL: Error path: GuardedCallWithLongjmp invoked on buffer underflow; control does not return to normal flow [callee:0x00511869, global:0x005ADB4C, source:raw]
    // ASSIGNMENT: Copy a3 bytes from the current read position (pointer stored at v3+0) into the destination a2 [field:*(this+0x54):0x00000000, source:raw]
    // CALCULATION: Advance the read position: dword at v3+0 is incremented by a3 [field:*(this+0x54):0x00000000, source:raw]
    // CALCULATION: Decrement the remaining byte count: dword at v3+4 is reduced by a3 [field:*(this+0x54):0x00000004, source:raw]
    // RETURN: Return a3, the number of bytes read [source:raw]

    // Conservative worker pseudocode:
    //   v3 = *(dword*)(a1 + 0x54);
    //   if (a3 > *(dword*)(v3 + 4)) GuardedCallWithLongjmp(a1, "read error");
    //   memcpy(a2, *(void**)v3, a3);
    //   *(dword*)v3 += a3;
    //   *(dword*)(v3 + 4) -= a3;
    //   return a3;
    // UNRESOLVED: The type of the buffer-tracking struct at this+0x54 is unknown; only the read position (+0) and remaining count (+4) are evidenced
    // UNRESOLVED: The owner object behind the stream callbacks (this/a1) has no identified class or vtable semantics in this packet
    // UNRESOLVED: The longjmp error context (Guard error frame) is established elsewhere and not visible in this packet
}
