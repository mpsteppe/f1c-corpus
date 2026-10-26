// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564410
// Canonical corpus name: sub_564410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564410_00564410.c

void UnknownObject::IsQueryIdOrFinal()
{
    // String-membership check: builds a local two-entry table of the string globals aQueryid (0x005E505C) and aFinal_0 (0x005E5054) and compares the argument string against both with strcmp. Returns 0 when the argument equals either entry, 1 when it matches neither. Deterministic extraction (strings_index) resolves aQueryid to "queryid" and aFinal_0 to "final". Called from AudioMixerPollingUpdateLoop (0x00564390), suggesting the audio poll loop recognizes one of these two literal command names.
    // CALCULATION: Initialize the local string table v4 with the two string globals in order: v4[0] = aQueryid, v4[1] = aFinal_0. [global:0x005E5054, global:0x005E505C, source:raw]
    // CALL: Call strcmp with the argument string and the v2-th table entry; a nonzero result means 'no match yet'. [global:0x005E5054, global:0x005E505C, source:raw]
    // LOOP: Iterate v2 from 0 upward while strcmp(this, v4[v2]) is nonzero; the table has exactly two entries. [global:0x005E5054, global:0x005E505C, source:raw]
    // GUARD: If incrementing v2 makes it reach 2, both table entries have been rejected and the function returns 1. [source:raw]
    // RETURN: Return 0 when a table entry equals the argument; return 1 when neither entry matches. [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_564410(const char *this) {
    //       const char *v4[2] = { aQueryid, aFinal_0 };
    //       int v2 = 0;
    //       while (strcmp(this, v4[v2])) {
    //           if (++v2 >= 2) return 1;
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: The semantic role of 'queryid' / 'final' inside the audio poll loop is not in the packet; the recognition use-case is DERIVED from the caller name AudioMixerPollingUpdateLoop.
    // UNRESOLVED: The argument is treated as a C string; its source, lifetime, and encoding are not evidenced here.
    // UNRESOLVED: Owner is unknown; no this field or owning class is evidenced in the packet.
}
