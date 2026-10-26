// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411B50
// Canonical corpus name: CharacterCodeMapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharacterCodeMapper_00411b50.c

void UnknownObject::CharacterCodeMapper()
{
    // Maps a character code (a1) to an event ID. Special codes 9875 and 9876 map based on the variant selector a4 (397/426 to 45/46; 1/2 to 42/43). Otherwise the code is indexed into a lookup table selected by a2 (0 selects unk_5BEE08, 1 selects unk_5BF4C0). On a successful mapping it copies a path string into byte_5EA438 via StringCopyWithBufferRealloc, writes (a1, mapped id) to the output buffer at a3+8/a3+12 and returns 0; returns 1 when the code/variant is unmapped or out of range.
    // GUARD: For the special code a1 == 9875 the variant a4 must be 397 or 426; for a1 == 9876 it must be 1 or 2. Any other a1/a4 combination returns 1 immediately without writing output. [source:raw]
    // ASSIGNMENT: Special-case mapping: 9875 maps a4==397 to 45 and a4==426 to 46; 9876 maps a4==1 to 42 and a4==2 to 43. [source:raw]
    // GUARD: Selects the lookup table by a2: unk_5BEE08 when a2==0, unk_5BF4C0 when a2==1; any other a2 leaves v4 at its default -1 and falls through to the range check. [source:raw, global:0x005BEE08, global:0x005BF4C0]
    // ASSIGNMENT: Indexes the selected character-to-event lookup table: v4 = table[a1]. [source:raw, global:0x005BEE08, global:0x005BF4C0]
    // GUARD: Success requires a1 >= 0 and the mapped value v4 >= 0; otherwise the function returns 1 (unmapped). [source:raw]
    // CALL: On a successful mapping, copies a path string via StringCopyWithBufferRealloc into the buffer at byte_5EA438. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Writes the character code a1 to the output buffer at a3+8 and the mapped event ID v4 at a3+12, then returns 0. [source:raw]
    // CALL: Invoked by FontRenderingPrep (00411840) while preparing font rendering state. [caller:0x00411840, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 == 9875) {
    //     v4 = (a4 == 397) ? 45 : ((a4 == 426) ? 46 : -1);
    //   } else if (a1 == 9876) {
    //     v4 = (a4 == 1) ? 42 : ((a4 == 2) ? 43 : -1);
    //   } else if (a2 == 0) {
    //     v4 = unk_5BEE08[a1];
    //   } else if (a2 == 1) {
    //     v4 = unk_5BF4C0[a1];
    //   }
    //   if (a1 >= 0 && v4 >= 0) {
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(DWORD*)(a3 + 8) = a1;
    //     *(DWORD*)(a3 + 12) = v4;
    //     return 0;
    //   }
    //   return 1;
    // UNRESOLVED: Purpose of the lookup tables unk_5BEE08 and unk_5BF4C0 (the fill names them SoundBankIndexMap and Setup_OptionTable_5BF4C0) is DERIVED only; the a2 selector semantics are unconfirmed
    // UNRESOLVED: Role of the byte_5EA438 buffer is unknown; the fill calls it a path string but that is unverifiable from this packet
    // UNRESOLVED: Meaning of the variant selectors (397/426/1/2) and the mapped IDs (42-46) is unknown
}
