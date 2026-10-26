// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587260
// Canonical corpus name: DecompressionDecode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecompressionDecode_00587260.c

void UnknownObject::DecompressionDecode()
{
    // Validates output capacity via AddConstantWrapper, writes the resulting header word into the destination, copies a variable-length data block resolved by BufferQueryReturnPtrSizeIfValid, then appends three trailing struct fields (DWORD at 0x10, DWORD at 0x14, BYTE at 0x18). Returns the total written byte count through *a3.
    // CALL: Call AddConstantWrapper(this) to obtain the value v4 used for the capacity check. [callee:0x00587250]
    // GUARD: If v4 > *a3, the destination is too small; return 0 immediately. [source:raw]
    // ASSIGNMENT: Write v4 as a WORD header at the start of the destination buffer; set the write cursor to a2+2 and v14 = *a3 - 2. [source:raw]
    // CALL: Call BufferQueryReturnPtrSizeIfValid(&v15, &v14) to resolve the source pointer/size for the data block. [callee:0x00587580]
    // GUARD: If the buffer query succeeds, copy 4*(v14>>2) bytes from the resolved source, then the remaining v14&3 bytes; advance the destination cursor by the full copied size. [source:raw]
    // ASSIGNMENT: Append the first trailing DWORD read from this+0x10 at the destination cursor. [field:this:0x00000010]
    // ASSIGNMENT: Append the second trailing DWORD read from this+0x14 after the first trailing field. [field:this:0x00000014]
    // ASSIGNMENT: Append the trailing BYTE read from this+0x18 after the two DWORD fields. [field:this:0x00000018]
    // ASSIGNMENT: Store the total written size (final cursor minus start plus one) into *a3. [source:raw]
    // RETURN: Return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   w = AddConstantWrapper(this);
    //   if (w > *dstSize) return 0;
    //   *(WORD*)dst = w; cursor = dst + 2; remain = *dstSize - 2;
    //   if (BufferQueryReturnPtrSizeIfValid(&src, &remain)) {
    //       qmemcpy(cursor, src, 4 * (remain >> 2));
    //       qmemcpy(cursor + 4 * (remain >> 2), src + 4 * (remain >> 2), remain & 3);
    //       cursor += remain;
    //   }
    //   *(DWORD*)cursor = *(DWORD*)(this + 16); cursor += 4;
    //   *(DWORD*)cursor = *(DWORD*)(this + 20); cursor += 4;
    //   *cursor = *(BYTE*)(this + 24);
    //   *dstSize = (cursor - dst) + 1;
    //   return 1;
    // UNRESOLVED: Semantic meaning of the three trailing fields (two DWORDs + one BYTE) appended after the copied data block is unknown; they likely tag the decoded block but no consuming evidence is present.
    // UNRESOLVED: Relationship between AddConstantWrapper's return value and the header word written to the destination is unclear (capacity versus data size).
    // UNRESOLVED: The off-by-one in the reported size (*a3 = cursor - dst + 1) suggests a byte counting convention that is not explained by the packet.
}
