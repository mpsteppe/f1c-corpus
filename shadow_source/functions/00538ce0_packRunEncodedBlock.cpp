// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00538CE0
// Canonical corpus name: CompressionBitstreamPacker
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CompressionBitstreamPacker_00538ce0.c

void UnknownObject::packRunEncodedBlock()
{
    // Run-length / literal encoder that consumes a word stream a2 (initial symbol word at +2, following words from +6) and writes a packed bitstream into the encoder state a1. It scans runs of equal symbols (threshold v6), emits short runs (v4 < v7) as repeated literals through the per-symbol code table at +2674/+2676, emits nonzero runs as symbol (when changed) plus a run count v4-3 via the +2738/+2740 table with two appended residual bits, and emits zero runs either short (v4-3 via +2742/+2744, three residual bits) or long (v4-11 via +2746/+2748, seven residual bits). All writes use a 16-bit accumulator at +5803 (high byte +5804) with a bit-count dword at +5805, flushing the two buffered bytes into the output buffer at cursor +20 over base pointer +8 whenever the accumulated bit count crosses 16. ABI leads the Compression_Bitstream_Packer cluster; the prelabel marks it a DERIVED structural twin of RunLengthAnalyzer (005389b0), and it is invoked by BitBufferWriter (0x00538A90).
    // ASSIGNMENT: Load the initial run symbol v3 from the input word stream at a2+2 [field:this:0x00000002, source:raw]
    // CALCULATION: Seed run thresholds: default max run v6=7 and min-RLE v7=4; when the run symbol v3 is zero, use v6=138 and v7=3 [source:raw]
    // GUARD: When a3 < 0 there is no data to pack and a1 is returned unchanged [source:raw]
    // LOOP: Scan the stream from a2+6, counting consecutive words equal to v3 into v4, breaking when the run reaches the max v6 or a differing symbol is read; v74 holds that first differing symbol [field:this:0x00000006, source:raw]
    // GUARD: When the run is too short (v4 < v7), emit each symbol as a literal: for each of v4 items, pack the code/length pair at +2674/+2676 into the accumulator [source:raw]
    // CALCULATION: Bit-write primitive shared by every emit: OR (table code << bitpos) into the accumulator word at +5803 tracking bitpos at +5805; when bitpos + code length exceeds 16, flush the two accumulator bytes to the output buffer at cursor +20 over base +8, advance the cursor by two, rebase the accumulator, and carry the overflow bit position [source:raw]
    // STATE_TRANSITION: Nonzero run: when the run symbol differs from the previous one (v3 != v73) emit the symbol itself via +2674/+2676; in both cases emit the run count v4-3 via the +2738/+2740 table, appending two residual bits to the packed value [source:raw]
    // STATE_TRANSITION: Zero run: long runs (v4 > 10) emit the count v4-11 via the +2746/+2748 table with seven appended residual bits; otherwise emit v4-3 via the +2742/+2744 table with three appended residual bits [source:raw]
    // STATE_TRANSITION: After each run, reset v4 to zero, record v73 = v3 as the last emitted symbol, and recompute thresholds from the next symbol v74: v6=6/v7=3 when v3 equals v74, v6=7/v7=4 otherwise, and v6=138/v7=3 when v74 is zero [source:raw]
    // LOOP: Advance the stream pointer by one word; when the last element (i == 1) was consumed, return a1, otherwise set v3 = v74 and resume scanning the next run [source:raw]
    // RETURN: Return the encoder state a1, which carries the accumulator and cursor after all packing [source:raw]
    // CALL: Invoked by BitBufferWriter (0x00538A90) as the run/literal bitstream packer that serializes the analyzed symbol data [caller:0x00538A90]

    // Conservative worker pseudocode:
    //   v3 = *(u16*)(a2 + 2); v4 = 0; prev = -1;
    //   v6 = v3 ? 7 : 138; v7 = v3 ? 4 : 3;
    //   if (a3 < 0) return a1;
    //   v72 = (u16*)(a2 + 6);
    //   for (i = a3 + 1; ;) {
    //     ++v4; next = *v72;
    //     if (v4 >= v6) break;
    //     if (v3 != *v72) break;
    //   advance: v72 += 2; if (i == 1) return a1; v3 = next;
    //   }
    //   if (v4 < v7) { do emitLiteral(v3) via table +2674/+2676; while (--v4); goto next_run; }
    //   if (v3) { if (v3 != prev) emitLiteral(v3); emitCount(v4 - 3) via +2738/+2740 (+2 residual bits); }
    //   else if (v4 > 10) emitZeroLong(v4 - 11) via +2746/+2748 (+7 residual bits);
    //   else emitZeroShort(v4 - 3) via +2742/+2744 (+3 residual bits);
    //   next_run: v4 = 0; prev = v3;
    //   v6 = next ? (v3 == next ? 6 : 7) : 138; v7 = next ? (v3 == next ? 3 : 4) : 3;
    //   goto advance;
    // UNRESOLVED: The contents of the four code/length tables at +2674, +2738, +2742 and +2746 are not defined in this function, so the exact codes emitted cannot be reconstructed
    // UNRESOLVED: The residual-bit counts (2, 3, 7) and the run-count values v4-3 / v4-11 are inferred from the bit-position arithmetic and the subtraction constants in raw source; the table-to-run-length mapping is not resolvable from this packet
    // UNRESOLVED: The prelabel claim that this function is a structural twin of RunLengthAnalyzer (005389b0) is DERIVED and no coupling evidence appears in this packet
    // UNRESOLVED: The owner object is unknown; the encoder-state offsets (+8, +20, +5803, +5804, +5805) and code-table offsets are inferred from pointer arithmetic, not from named field evidence
}
