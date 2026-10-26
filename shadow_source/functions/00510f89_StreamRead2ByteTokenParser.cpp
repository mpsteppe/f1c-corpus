// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00510F89
// Canonical corpus name: StreamRead2ByteTokenParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamRead2ByteTokenParser_00510f89.c

void UnknownObject::StreamRead2ByteTokenParser()
{
    // Reads a 2-byte big-endian size field followed by a 2-byte big-endian token value from a byte stream, refilling the stream via a callback whenever the remaining-byte count hits zero. Requires the size to equal exactly 4; on mismatch it sets the dispatcher state to 9 and invokes the vtable entry 0 error path. On success it sets the dispatcher state to 81, stores the parsed value at obj+0x18 and this+0xFC, invokes vtable entry 4 with (v1, 1), advances the read pointer, decrements the remaining count, and returns 1.
    // ASSIGNMENT: Load stream state: v2 = *(this+0x14) (the stream read-state struct), v3 = its remaining-byte count at offset 0x4, v4 = its read pointer at offset 0x0. [field:this:0x00000014, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // GUARD: If the remaining-byte count is zero, call the refill callback v2[3] (offset 0xC of the stream state) and reload read pointer and count; abort with return 0 when the refill fails. [field:*(this+0x14):0x0000000C, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // CALCULATION: Read the first byte at the read pointer (field *(*(this+0x14)+0x0)) as the high byte of a 16-bit big-endian size and decrement the remaining count by one. [field:*(*(this+0x14)+0x0):0x00000000, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // GUARD: If the remaining count reaches zero before the second size byte is read, refill again via v2[3] and abort with return 0 on failure. [field:*(this+0x14):0x0000000C, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // CALCULATION: Combine the second size byte into the 16-bit size value; if the size does not equal 4, set the dispatcher state obj+0x14 to 9 and invoke the vtable entry at obj+0x0 (the state dispatcher object is reached through the pointer at this+0x0). [field:*(*(this+0x14)+0x0):0x00000000, field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: If the remaining count reaches zero before reading the token high byte, refill again via v2[3] and abort with return 0 on failure. [field:*(this+0x14):0x0000000C, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // CALCULATION: Read the token value as a 16-bit big-endian quantity from the stream's remaining two bytes at the read pointer. [field:*(*(this+0x14)+0x0):0x00000000, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, source:raw]
    // ASSIGNMENT: Commit the token: set the dispatcher state obj+0x14 to 81, store the parsed value at obj+0x18, invoke the vtable entry at obj+0x4 with (v1, 1), store the value at this+0xFC, advance the read pointer (field 0x0 of the stream state) and decrement the remaining count (field 0x4), then return 1. [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000004, field:this:0x000000FC, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000004, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   char sub_510F89(int a1) {
    //     byte *stream = *(byte **)(a1 + 20);
    //     byte *p = stream[0]; int remaining = stream[1];
    //     if (remaining == 0) { if (!stream[3](a1)) return 0; p = stream[0]; remaining = stream[1]; }
    //     int size = (*p) << 8; p++; remaining--;
    //     if (remaining == 0) { if (!stream[3](a1)) return 0; p = stream[0]; remaining = stream[1]; }
    //     size += *p; p++; remaining--;
    //     if (size != 4) { *(DWORD *)(*(DWORD *)a1 + 20) = 9; (*(vtable*)*a1)(a1); }
    //     if (remaining == 0) { if (!stream[3](a1)) return 0; p = stream[0]; remaining = stream[1]; }
    //     int token = (*p) << 8; p++; remaining--;
    //     if (remaining == 0) { if (!stream[3](a1)) return 0; p = stream[0]; remaining = stream[1]; }
    //     token += *p; p++; remaining--;
    //     *(DWORD *)(*(DWORD *)a1 + 20) = 81;
    //     *(DWORD *)(*(DWORD *)a1 + 24) = token;
    //     (*(vtable*)*(DWORD *)a1 + 4)(a1, 1);
    //     *(DWORD *)(a1 + 252) = token;
    //     stream[0] = p; stream[1] = remaining;
    //     return 1;
    //   }
    // UNRESOLVED: Layout and refill callback semantics of the stream read-state struct (offset 0xC of *(this+0x14)) are unverified.
    // UNRESOLVED: Meaning of the dispatcher states 81 (token) and 9 (size mismatch) and the vtable entry 0/4 calls depends on the caller CommandDispatchStateMachine (0x0051126A), not analyzed here.
    // UNRESOLVED: Owner class of the stream object is unknown.
}
