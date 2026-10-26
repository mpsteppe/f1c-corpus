// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D5D0
// Canonical corpus name: StructuredMemoryCopyWithHeaderPrepend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructuredMemoryCopyWithHeaderPrepend_0057d5d0.c

void UnknownObject::StructuredMemoryCopyWithHeaderPrepend()
{
    // Builds a structured packet in the output buffer: writes a header word (byte count derived from the bit count at source+0x24, then a value retrieved by FieldAccessor), copies the payload from source+0x14, then appends a second copy using the adjusted pointer/size pair returned by BufferQueryReturnPtrSizeIfValid; always returns 1.
    // ASSIGNMENT: Load the payload pointer stored at source+0x14 (a1 + 20). [field:this:0x00000014]
    // CALCULATION: Read the bit count dword at source+0x24 (a1 + 36) and convert to a byte count as (bits >> 3) plus (bits & 7) != 0, i.e. ceil(bits/8). [field:this:0x00000024]
    // ASSIGNMENT: Write the computed byte count as the first header word of the output buffer (*a2 = v5). [source:raw]
    // CALL: Call FieldAccessor on the dword pointer at source+8 and store the result in the second header word (v3[1]). [callee:0x0053D880]
    // ASSIGNMENT: Copy the byte count of payload bytes from source+0x14 into the output buffer after the two header words (v3 + 2). [field:this:0x00000014, source:raw]
    // CALL: Call BufferQueryReturnPtrSizeIfValid on the addresses of the output pointer and size to obtain an adjusted pointer/size pair for a further copy. [callee:0x00587580]
    // ASSIGNMENT: Copy the returned size of bytes from the adjusted source pointer into the output buffer at (char*)v3 + byteCount + 4. [source:raw]
    // RETURN: Return 1 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   payload = *(const void**)(a1 + 20);
    //   out = (word*)a2;
    //   byte_count = (*(dword*)(a1 + 36) >> 3) + ((*(dword*)(a1 + 36) & 7) != 0);
    //   out[0] = byte_count;
    //   out[1] = FieldAccessor(a1 + 8);
    //   qmemcpy(out + 2, payload, byte_count);
    //   BufferQueryReturnPtrSizeIfValid(&a2, &a1);
    //   qmemcpy((char*)out + byte_count + 4, a2, a1);
    //   return 1;
    // UNRESOLVED: The object type behind a1 is unknown; the recorded callers are sub_57D6C0 (0x0057D6C0) and NetworkPacketSendWithQueryMatching (0x0057D8D0).
    // UNRESOLVED: The adjusted pointer/size pair produced by BufferQueryReturnPtrSizeIfValid is only evidenced as the source of the final copy; its validity contract is not grounded here.
}
