// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058EF2E
// Canonical corpus name: BufferedByteReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferedByteReader_0058ef2e.c

void UnknownObject::ReadNextByteFromBuffer()
{
    // Reads the next byte from a buffered I/O context. Decrements the remaining-count dword at this+4; when the decremented count is negative (buffer exhausted), calls sub_58C255(this) to refill and returns its result. Otherwise returns the byte at the cursor pointer stored at this+0 and advances that pointer.
    // CALCULATION: Decrement the remaining-byte-count dword at this+4. [field:this:0x00000004, source:raw]
    // GUARD: When the decremented count is negative (buffer exhausted), call sub_58C255(this) to refill and return its result. [field:this:0x00000004, callee:0x0058C255, source:raw]
    // RETURN: Return the byte at the current cursor pointer (dword at this+0) and advance the cursor pointer by one. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58EF2E(int a1) {
    //     if (--*(DWORD *)(a1 + 4) < 0)
    //       return sub_58C255((unsigned char **)a1);
    //     return *(* (unsigned char **)a1)++;
    //   }
    // UNRESOLVED: sub_58C255 refill semantics and whether its return encodes EOF are not established here.
    // UNRESOLVED: Owner of the buffered I/O object and the meaning of cursor/count fields are unknown.
    // UNRESOLVED: Legacy ABI label Buffered_Byte_Reader is not an owner name.
}
