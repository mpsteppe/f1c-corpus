// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B560
// Canonical corpus name: sub_48B560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48B560_0048b560.c

void UnknownObject::InputCharFilterByFieldType()
{
    // Filters an input character based on the field type stored at this+0x2E8. Returns 1 when the character is allowed and 0 when blocked. Non-classified characters are rejected early; mode 1 is text entry that blocks backslash, slash, colon, period, and leading spaces; mode 2 is a restricted mode allowing only characters accepted by sub_589B9E/sub_589B70 plus period and colon; any other mode passes all classified characters.
    // GUARD: Guard on CharacterClassificationQuery(a2) returning non-zero; unclassified characters are rejected with a 0 return before any mode logic. [callee:0x00589C49, source:raw]
    // GUARD: Branch on the field type at this+0x2E8: when it equals 1 the text-entry rule applies. [field:this:0x000002E8, guard:1, source:raw]
    // GUARD: In text mode, allow the character only when it is none of backslash (92), slash (47), colon (58) or period (46), and when a space (32) is permitted only if the string buffer at this+0x2F0 is non-empty (string length check on the stored buffer pointer). [field:this:0x000002E8, field:this:0x000002F0, guard:1, source:raw]
    // RETURN: Return 1 for an allowed text-mode character. [function:0x0048B560, guard:1, source:raw]
    // GUARD: In the else branch (field type not 1), when the field type at this+0x2E8 is not 2 either, return 1 and allow all classified characters. [field:this:0x000002E8, guard:0, guard:1, source:raw]
    // GUARD: In restricted mode (field type equals 2), allow the character when sub_589B9E(a2) or sub_589B70(a2) succeeds, or when the character is period (46) or colon (58). [field:this:0x000002E8, callee:0x00589B9E, callee:0x00589B70, guard:0, source:raw]
    // RETURN: Return 1 when a restricted-mode character passes the mode-2 allow rule. [function:0x0048B560, guard:0, source:raw]
    // RETURN: Return 0 for every character that failed classification or its mode's allow rule. [function:0x0048B560, source:raw]

    // Conservative worker pseudocode:
    //   char sub_48B560(int this, unsigned __int8 c) {
    //     if (CharacterClassificationQuery(c)) {
    //       if (*(int*)(this + 744) == 1) {
    //         if (c != 92 && c != 47 && c != 58 && c != 46 && (c != 32 || strlen(*(char**)(this + 752))))
    //           return 1;
    //       } else {
    //         if (*(int*)(this + 744) != 2) return 1;
    //         if (sub_589B9E(c) || sub_589B70(c) || c == 46 || c == 58) return 1;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the mode values (1 = text, 2 = restricted) is inferred from callers and not named by this packet.
    // UNRESOLVED: Precise character classes accepted by sub_589B9E and sub_589B70 are unknown; they are treated as black-box predicates.
    // UNRESOLVED: Identity of the owning edit-field object is unknown; only that it exposes field type at this+0x2E8 and a buffer pointer at this+0x2F0.
    // UNRESOLVED: The string-length check on the this+0x2F0 buffer is performed inline (strlen) rather than through a listed callee.
}
