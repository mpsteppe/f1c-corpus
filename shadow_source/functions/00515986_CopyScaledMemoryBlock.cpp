// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515986
// Canonical corpus name: sub_515986
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_515986_00515986.c

void UnknownObject::CopyScaledMemoryBlock()
{
    // Memory block copy helper: copies a3 * 128 bytes (a3 left-shifted by 7) from a1 into a2 and returns the byte count copied. The qmemcpy size is expressed in the raw source as 4 * ((a3 << 7) >> 2), which simplifies to a3 << 7 bytes. The single caller is an audio subband synthesis filterbank, suggesting the 128-byte unit is a per-subband sample block.
    // CALCULATION: result = a3 << 7: compute the copy size as 128 times a3 (scaling the caller-supplied block count by a 128-byte unit). [source:raw]
    // CALL: qmemcpy(a2, a1, 4 * ((unsigned int)(a3 << 7) >> 2)): copy (a3 << 7) bytes from the source a1 into the destination a2; the 4 * (>> 2) form is the same byte count re-expressed in 4-byte words. [source:raw]
    // RETURN: Return result (the number of bytes copied, a3 << 7). [function:0x00515986, source:raw]

    // Conservative worker pseudocode:
    //   int sub_515986(const void *src, void *dst, int blocks) {
    //     int size = blocks << 7;
    //     qmemcpy(dst, src, size);
    //     return size;
    //   }
    // UNRESOLVED: The 128-byte unit is inferred from the shift count and the audio subband caller; the element type and sample layout of the copied block are not proven.
    // UNRESOLVED: The legacy ABI name 'Bitfield_Controlled_Memory_Copy' (LEGACY trust) hints at bitfield-controlled copying but is not corroborated by the raw source, which shows a plain fixed-size block copy.
}
