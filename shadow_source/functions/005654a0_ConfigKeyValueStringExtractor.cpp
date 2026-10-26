// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005654A0
// Canonical corpus name: sub_5654A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5654A0_005654a0.c

void UnknownObject::ConfigKeyValueStringExtractor()
{
    // Duplicates the source string at this+0x198 into the object head, then extracts a config key value: tokenizes the string at the asc_5C30AC delimiter, stores the first token at this+0x180, rejects the request if the token matches the provided key via sub_588410, re-tokenizes at the asc_5C64D4 delimiter, stores that value at this+0x180, and copies it into the a3 output buffer, returning 1 on success or 0 on any failure.
    // LOOP: Copy the source string starting at this+0x198 byte-by-byte into this+0 until the null terminator, duplicating it into the object head. [field:this:0x00000198, source:raw]
    // CALL: Call sub_5897CA(this, asc_5C30AC) to tokenize the string at the asc_5C30AC delimiter and store the returned first-token pointer to this+0x180. [callee:0x005897CA, global:0x005C30AC, field:this:0x00000180, function:0x005654A0]
    // GUARD: If the first-token pointer stored at this+0x180 is null, return 0 (empty key path). [field:this:0x00000180, source:raw]
    // CALL: Call sub_588410(first_token, a2) to check the first token against the provided key. [callee:0x00588410]
    // GUARD: If sub_588410 returns true, return 0 (key already consumed/reserved). [callee:0x00588410, source:raw]
    // CALL: Call sub_5897CA(0, asc_5C64D4) and store the returned value pointer to this+0x180. [callee:0x005897CA, global:0x005C64D4, field:this:0x00000180]
    // GUARD: If the value pointer stored at this+0x180 is null, return 0. [field:this:0x00000180, source:raw]
    // ASSIGNMENT: Copy the retrieved value string into the a3 output buffer via strcpy. [source:raw]
    // RETURN: Return 1 on successful extraction. [function:0x005654A0, source:raw]

    // Conservative worker pseudocode:
    //   dst = this;
    //   src = this + 0x198;
    //   do { c = *src; *dst = *src; dst++; src++; } while (c);
    //   
    //   token = sub_5897CA(this, asc_5C30AC);
    //   *(int*)(this + 0x180) = token;
    //   if (!token) return 0;
    //   if (sub_588410(token, a2)) return 0;
    //   
    //   value = sub_5897CA(0, asc_5C64D4);
    //   *(int*)(this + 0x180) = value;
    //   if (!value) return 0;
    //   strcpy(a3, value);
    //   return 1;
    // UNRESOLVED: Second sub_5897CA call passes null as the first argument; exact meaning of tokenizing a null source is unknown.
    // UNRESOLVED: String-copy destination this+0 is not represented in the evidence field list, so its semantic role is unverified.
    // UNRESOLVED: Exact semantics of sub_588410 (key match vs reservation) are inferred from existing analysis prose, not from raw evidence.
    // UNRESOLVED: Content of asc_5C64D4 (alleged default-font string in analysis) is not confirmed by packet evidence alone.
}
