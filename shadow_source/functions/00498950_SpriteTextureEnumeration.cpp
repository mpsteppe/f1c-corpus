// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498950
// Canonical corpus name: SpriteTextureEnumeration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpriteTextureEnumeration_00498950.c

void UnknownObject::SpriteTextureEnumeration()
{
    // Scans up to 4 sprite/texture entry slots stored on the this object, comparing the caller-supplied string a2 against each active entry's string via sub_588410; on a match it returns 0 immediately. If exactly 3 entries are active and the loop ends (4th slot inactive), it resets global byte_5EA438 via StringFieldSetter and invokes sub_495B60. Otherwise it sets the string field on a2 from this+0xD8. A null a2 returns 0 unchanged.
    // RETURN: If input a2 is null, return 0 immediately without any entry scan. [function:0x00498950, source:raw]
    // ASSIGNMENT: Initialize loop counter v4 to 0 and entry pointer v5 to this + 1407 dwords, the base of the entry-slot array. [source:raw]
    // LOOP: do-while loop over up to 4 entry slots, advancing v5 by 3 dwords per iteration while v4 < 4. [source:raw]
    // GUARD: FloatThresholdCheck(v5) returning 0 marks the slot inactive and breaks the loop early. [callee:0x00499A50, source:raw]
    // CALL: StringPointerDereference(v5) retrieves the entry's string pointer into v6. [callee:0x0049A2B0, source:raw]
    // CALL: sub_588410(a2, v6) compares the input string against the entry string; a 0 result indicates a match. [callee:0x00588410, source:raw]
    // GUARD: If the comparison result is 0 (match found), return 0 immediately, skipping the remaining slots. [source:raw]
    // STATE_TRANSITION: When the loop ends with v4 == 3 (exactly 3 active entries, 4th inactive): StringFieldSetter resets global byte_5EA438 to 0, then sub_495B60 is invoked on this. [callee:0x00499A30, callee:0x00495B60, global:0x005EA438, source:raw]
    // RETURN: Final path: StringFieldSetter(a2, this[54]) writes the value of this+0xD8 into the target's string field and returns its result. [callee:0x00499A30, field:this:0x000000D8, source:raw]

    // Conservative worker pseudocode:
    //   int sub_498950(int *this, int a2) {
    //     if (a2 == 0) return 0;
    //     int v4 = 0;
    //     int *v5 = this + 1407;
    //     do {
    //       if (!FloatThresholdCheck(v5)) break;
    //       int v6 = StringPointerDereference(v5);
    //       int result = sub_588410(a2, v6);
    //       if (result == 0) return 0;
    //       ++v4;
    //       v5 += 3;
    //     } while (v4 < 4);
    //     if (v4 == 3) {
    //       StringFieldSetter(byte_5EA438, 0);
    //       sub_495B60((int)this);
    //     }
    //     return StringFieldSetter(a2, this[54]);
    //   }
    // UNRESOLVED: The entry-slot array layout (base this + 1407, 3-dword stride) is inferred from the decompiled pointer arithmetic; the element structure is not evidenced.
    // UNRESOLVED: Meaning of the this+0xD8 value written into a2's string field is not established.
    // UNRESOLVED: Identity of the global byte_5EA438 and the purpose of sub_495B60 beyond this single call site are unknown.
}
