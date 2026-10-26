// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565400
// Canonical corpus name: sub_565400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565400_00565400.c

void UnknownObject::ConfigKeyTokenParser()
{
    // Parses a dot-delimited config key path on the object buffer. First copies the NUL-terminated source string from this+0x198 onto the object base (offset 0), then tokenizes it at the '.' delimiter held in asc_5C30AC, storing each segment pointer into this+0x180. Walks the hierarchy: while the current token matches a2 via sub_588410 it advances through further '.'-separated segments, and finishes with a segment produced with word_5C32D8 as the lookup context. Returns 0 on any empty or null result, 1 if the final token is non-null. On the frame path; called by five config-key consumers.
    // LOOP: NUL-terminated byte copy from this+0x198 to the object base (offset 0), advancing one byte per iteration until the copied byte is zero [field:this:0x00000198, source:raw]
    // CALL: First tokenization: sub_5897CA(this, asc_5C30AC) splits the copied key at the '.' delimiter; the resulting segment pointer is stored into this+0x180 [callee:0x005897CA, global:0x005C30AC, field:this:0x00000180, source:raw]
    // GUARD: If the first tokenization returned null (no '.' segment found), return 0 immediately [field:this:0x00000180, source:raw]
    // LOOP: While sub_588410(current token in this+0x180, a2) reports a match, advance: re-tokenize with sub_5897CA(0, &word_5C32D8), then with sub_5897CA(0, asc_5C30AC), storing each segment back into this+0x180 [callee:0x00588410, callee:0x005897CA, global:0x005C32D8, global:0x005C30AC, field:this:0x00000180, source:raw]
    // GUARD: Inside the match loop, if the second re-tokenization (asc_5C30AC delimiter) returns null, return 0 immediately [callee:0x005897CA, global:0x005C30AC, field:this:0x00000180, source:raw]
    // ASSIGNMENT: Final segment: sub_5897CA(0, &word_5C32D8) result is stored into this+0x180 and returned as non-zero [callee:0x005897CA, global:0x005C32D8, field:this:0x00000180, source:raw]
    // RETURN: Returns 1 when the final token is non-null, 0 on any empty/malformed path [source:raw]
    // CALL: On the frame path; invoked by sub_565520, sub_5655F0, sub_565760, sub_565870 and sub_565AA0 [caller:0x00565520, caller:0x005655F0, caller:0x00565760, caller:0x00565870, caller:0x00565AA0, source:raw]

    // Conservative worker pseudocode:
    //   src = this + 0x198; dst = this;
    //   do { *dst++ = *src; } while (*src++);
    //   tok = Tokenize(this, asc_5C30AC); this[0x180/4] = tok;
    //   if (!tok) return 0;
    //   while (LookupMatch(this[0x180/4], a2)) {
    //     this[0x180/4] = Tokenize(0, &word_5C32D8);
    //     this[0x180/4] = Tokenize(0, asc_5C30AC);
    //     if (!this[0x180/4]) return 0;
    //   }
    //   this[0x180/4] = Tokenize(0, &word_5C32D8);
    //   return this[0x180/4] != 0;
    // UNRESOLVED: The semantics of sub_588410 (match test) and the role of a2 are not established by this packet; the skeleton fill labels it a lookup-entry match, which is unverifiable here
    // UNRESOLVED: word_5C32D8 is used as a second tokenization context; the fill's 'HotExtension (.HOT)' reading is DERIVED and cannot be confirmed from this packet
    // UNRESOLVED: The destination string copy overwrites the object base (offset 0), whose field role is outside the packet's field evidence
}
