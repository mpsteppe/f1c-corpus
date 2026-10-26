// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1A50
// Canonical corpus name: ParseMidiBitstream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParseMidiBitstream_004d1a50.c

void UnknownObject::ParseMidiBitstream()
{
    // Decodes a packed parameter-update stream. The header DWORD masked with 0xFC0000 is tested against 2621440 (reset command); when it matches, every entry of the state array (count from field this+0x10C, base from field this+0x110, 8 bytes per entry) is cleared via ShortComputation_0f00(entry, 0). Then, when the count field (*a2 >> 9) & 0x1FF is non-zero, that many packed WORDS starting at a2+2 are decoded; each WORD supplies an index (>> 6) and a value (& 0x3F) used to update the state entry via ShortComputation_0f00. Invoked by sub_4B3400 (004B3400).
    // GUARD: Header reset check: result = *a2 & 0xFC0000; the reset branch runs when result equals 2621440 [source:raw]
    // LOOP: Reset pass: for i in [0, count), re-reading count = this[67] (field this+0x10C) each iteration, call ShortComputation_0f00(this[68] + 8*i, 0) to clear each 8-byte state entry [callee:0x004D0F00, field:this:0x0000010C, field:this:0x00000110, source:raw]
    // GUARD: Update count decode: v6 = (*a2 >> 9) & 0x1FF; the packed update words are processed when v6 is non-zero [source:raw]
    // LOOP: Update pass: for each of the v6 packed WORDS starting at a2+2, compute index = (word >> 6) and value = word & 0x3F, then call ShortComputation_0f00(this[68] + 8*index, value) to apply the parameter update to the state array [callee:0x004D0F00, field:this:0x00000110, source:raw]
    // RETURN: Returns the trailing value of result: the last ShortComputation_0f00 return when updates ran, the entry count when only the reset ran, or the masked header value *a2 & 0xFC0000 when neither branch executed [function:0x004D1A50, source:raw]
    // CALL: Invoked by sub_4B3400 (004B3400) to apply a packed parameter stream to this object's state [caller:0x004B3400]

    // Conservative worker pseudocode:
    //   header = *a2 & 0xFC0000;
    //   if (header == 2621440) {
    //     count = this[67];
    //     for (i = 0; i < count; i++) {
    //       ShortComputation_0f00(this[68] + 8*i, 0);
    //     }
    //   }
    //   count = (*a2 >> 9) & 0x1FF;
    //   word_ptr = a2 + 2;
    //   while (count-- > 0) {
    //     word = *word_ptr; word_ptr += 2;
    //     ShortComputation_0f00(this[68] + 8*(word >> 6), word & 0x3F);
    //   }
    // UNRESOLVED: The update loop advances its WORD cursor with v7 = (v8 + 2) where v8 is an uninitialized register, a Hex-Rays artifact of a 2-byte pointer increment; the real stride per packed WORD is 2 bytes
    // UNRESOLVED: The encoding of the 2621440 header marker as a reset command (mask 0xFC0000) is taken from existing_analysis; the command semantics are not confirmed by this packet alone
}
