// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A200
// Canonical corpus name: MemcpyLikeCopyWithWordByteSplitSizeStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemcpyLikeCopyWithWordByteSplitSizeStore_0057a200.c

void UnknownObject::CopyBufferWithSizeStore()
{
    // Size-tagged buffer copy on the receiver (thiscall): copies a3 bytes from a2 into the payload area at this+0x2D (qmemcpy) and records the byte count a3 in the size byte at this+0x2C, returning the receiver pointer. Structural twin of CarFlagByteSetter per the packet prelabel. Called by DriverEntrantSetupEntry (0x00462550) and BufferSendWithLocks (0x00462760) to populate a size-prefixed byte buffer.
    // ASSIGNMENT: Set result = this so the receiver pointer is returned unchanged [source:raw]
    // ASSIGNMENT: Copy a3 bytes from a2 into the payload buffer starting at this+0x2D via qmemcpy [source:raw]
    // ASSIGNMENT: Store the byte count a3 (truncated to a byte) at this+0x2C as the size prefix [field:this:0x0000002C, source:raw]
    // RETURN: Return the receiver pointer this [source:raw]
    // CALL: Called by DriverEntrantSetupEntry (0x00462550) and BufferSendWithLocks (0x00462760) to build a size-tagged buffer on the receiver [caller:0x00462550, caller:0x00462760, source:raw]

    // Conservative worker pseudocode:
    //   byte* CopyBufferWithSizeStore(byte* this, const void* src, unsigned int n) {
    //     qmemcpy(this + 45, src, n);
    //     this[44] = (byte)n;
    //     return this;
    //   }
    // UNRESOLVED: Identity of the receiver object and the meaning of its +0x2C size byte / +0x2D payload are unknown from this packet
    // UNRESOLVED: The payload offset +0x2D is only reachable through the raw source text; the packet field list flags only +0x2C
}
