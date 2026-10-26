// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E5E0
// Canonical corpus name: DecodeHuffmanPair
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecodeHuffmanPair_0052e5e0.c

void UnknownObject::DecodeHuffmanPair()
{
    // Decodes two Huffman-coded symbols from a bitstream into 16-bit results. Reads per-symbol code lengths from the code table at a3, extracts (code length + 1) bits from the bitstream (buffer base this+0x24A4, bit position this+0x24A8) using lookup tables dword_5B4788 and dword_5B4820, advances the bit position per symbol, scales the combined value with tables at a4/a6 and a right-shift by 12, then writes the two decoded words to the output array at a5.
    // ASSIGNMENT: v7 = 0; default decoded value for the first symbol (taken when its code-length byte is zero) [source:raw]
    // CALCULATION: v8 = *(char*)(a3 + 2*a2); reads the first symbol's code length from the code table at a3 [source:raw]
    // GUARD: If the code-length byte at a3+2*a2 is nonzero, decode the first symbol from the bitstream; otherwise keep v7 = 0 [source:raw]
    // CALCULATION: Bit extraction for first symbol: v9 = dword_5B4788[v8+1] & (byteswap_ulong(*(DWORD*)((this[2346]>>3) + this[2345])) >> -(v8+1+(this[2346]&7))); reads bitstream base (this+0x24A4) and bit position (this+0x24A8), masks with the dword_5B4788 table [field:this:0x000024A4, field:this:0x000024A8, global:0x005B4788, source:raw]
    // STATE_TRANSITION: this[2346] += v8+1; advances the bitstream bit position (this+0x24A8) by the first symbol's code length plus one [field:this:0x000024A8, source:raw]
    // CALCULATION: v7 = ((v9 + dword_5B4820[v8]) * *(DWORD*)(a6 + 4*(((v8+1)<<6) + *(DWORD*)(a4 + 4*a2)))) >> 12; combines the dword_5B4820 hash-table base offset with the code index from a4, scales by the a6 table entry, shifts right by 12 [global:0x005B4820, source:raw]
    // ASSIGNMENT: *(WORD*)(a5 + 2*a2) = v7; writes the first decoded 16-bit symbol to the output array at a5 [source:raw]
    // ASSIGNMENT: result = 0; default decoded value for the second symbol (taken when its code-length byte is zero) [source:raw]
    // CALCULATION: v12 = *(char*)(a3 + 2*a2 + 1); reads the second symbol's code length from the code table at a3 [source:raw]
    // GUARD: If the code-length byte at a3+2*a2+1 is nonzero, decode the second symbol from the bitstream; otherwise result stays 0 [source:raw]
    // CALCULATION: Bit extraction for second symbol: v13 = dword_5B4788[v12+1] & (byteswap_ulong(*(DWORD*)((this[2346]>>3) + this[2345])) >> -(v12+1+(this[2346]&7))); same bitstream read and table mask as the first symbol [field:this:0x000024A4, field:this:0x000024A8, global:0x005B4788, source:raw]
    // STATE_TRANSITION: this[2346] += v12+1; advances the bitstream bit position (this+0x24A8) by the second symbol's code length plus one [field:this:0x000024A8, source:raw]
    // CALCULATION: result = ((v13 + dword_5B4820[v12]) * *(DWORD*)(a6 + 4*(((v12+1)<<6) + *(DWORD*)(a4 + 4*a2 + 128)))) >> 12; second symbol scale using code index from a4+4*a2+128 [global:0x005B4820, source:raw]
    // ASSIGNMENT: *(WORD*)(a5 + 2*a2 + 64) = result; writes the second decoded 16-bit symbol 64 bytes after the first in the output array [source:raw]
    // RETURN: Returns result (the second symbol's decoded value) [function:0x0052E5E0, source:raw]
    // CALL: Called by CompressedAudioDecoder (0x0052E6F0) [caller:0x0052E6F0, source:raw]

    // Conservative worker pseudocode:
    //   v7 = 0;
    //   v8 = *(char*)(a3 + 2*a2);
    //   if (*(BYTE*)(a3 + 2*a2)) { v9 = dword_5B4788[v8+1] & (byteswap_ulong(*(DWORD*)((this[2346]>>3) + this[2345])) >> -(v8+1+(this[2346]&7))); this[2346] += v8+1; v7 = ((v9 + dword_5B4820[v8]) * *(DWORD*)(a6 + 4*(((v8+1)<<6) + *(DWORD*)(a4 + 4*a2)))) >> 12; }
    //   *(WORD*)(a5 + 2*a2) = v7;
    //   result = 0;
    //   v12 = *(char*)(a3 + 2*a2 + 1);
    //   if (*(BYTE*)(a3 + 2*a2 + 1)) { v13 = dword_5B4788[v12+1] & (byteswap_ulong(*(DWORD*)((this[2346]>>3) + this[2345])) >> -(v12+1+(this[2346]&7))); this[2346] += v12+1; result = ((v13 + dword_5B4820[v12]) * *(DWORD*)(a6 + 4*(((v12+1)<<6) + *(DWORD*)(a4 + 4*a2 + 128)))) >> 12; }
    //   *(WORD*)(a5 + 2*a2 + 64) = result;
    //   return result;
    // UNRESOLVED: The negative shift count in the bit extraction (e.g. >> -(v8+1+(this[2346]&7))) is Hex-Rays rendering of a variable-width bit extract; the exact machine shift semantics are not resolved from this packet
    // UNRESOLVED: this[2345] (this+0x24A4) and this[2346] (this+0x24A8) roles as bitstream buffer base and bit position are DERIVED from existing analysis, not independently confirmed
    // UNRESOLVED: The a3/a4/a5/a6 roles (code table, index table, output array, scale table) have no field evidence refs; these are GUESS labels from usage patterns
    // UNRESOLVED: The exact layout of dword_5B4788 (VLC prefix table) and dword_5B4820 (hash base offsets) is DERIVED from existing analysis
}
