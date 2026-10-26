// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0B20
// Canonical corpus name: sub_4B0B20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B0B20_004b0b20.c

void UnknownObject::PlayerNameOrModulePathExtractor()
{
    // Extracts a player/.plr filename into the output buffer a2. First attempts to read a string length from the game module manager via NullTerminatedStringLengthAt0x11c(dword_7CD25C); when non-zero, that string is copied into a2 with a length limit of a3-1. Otherwise the object's own name string is recovered via ShortComputation_0b10, trimmed to the portion after the last backslash, truncated at the '.plr' suffix match found by sub_566810, and copied into a2 with the same length limit.
    // CALL: Call NullTerminatedStringLengthAt0x11c(dword_7CD25C) to get the module-manager string length into v4. [callee:0x00463C40, global:0x007CD25C, source:raw]
    // GUARD: If v4 is non-zero, use the module-manager path: copy via sub_587DD0(a2, v4, a3 - 1) and terminate the output at a2[a3 - 1] = 0. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Otherwise clear the output buffer with *a2 = 0. [source:raw]
    // CALL: Recover the object name string via ShortComputation_0b10(this) and copy it into the local v10 buffer. [callee:0x004B0B10, source:raw]
    // CALCULATION: Advance v9 to the start of the filename after the last backslash (0x5C) in the local name copy; if none is found keep v9 at the buffer start. [source:raw]
    // CALL: Call sub_566810(v9, aPlr) to locate the '.plr' suffix; if found, terminate the string there. [callee:0x00566810, global:0x005CC1F4, source:raw]
    // CALL: Copy the resulting filename via sub_587DD0(a2, v9, a3 - 1) and terminate the output at a2[a3 - 1] = 0. [callee:0x00587DD0, source:raw]
    // RETURN: Return the result of the last copy/write operation. [source:raw]

    // Conservative worker pseudocode:
    //   len = NullTerminatedStringLengthAt0x11c(dword_7CD25C);
    //   if (len != 0) {
    //     sub_587DD0(a2, len, a3 - 1);
    //     a2[a3 - 1] = 0;
    //   } else {
    //     *a2 = 0;
    //     str = ShortComputation_0b10(this);
    //     copy str into local v10;
    //     v9 = after last '\\' in v10;
    //     if (sub_566810(v9, aPlr)) *result = 0;
    //     sub_587DD0(a2, v9, a3 - 1);
    //     a2[a3 - 1] = 0;
    //   }
    //   return result;
    // UNRESOLVED: The interpretation of the self-referential copy loop (v6[(v10 - v6)] = *v6) as copying the object name into the local v10 buffer is DERIVED from the surrounding backslash-trim and '.plr'-suffix logic; the loop's exact intent is not stated.
    // UNRESOLVED: The byte comparison against 92 (0x5C, backslash) is only visible in the raw source; the character identity is an observation, not an attributed field.
    // UNRESOLVED: The exact type of the value copied in the v4-non-zero branch (the second sub_587DD0 argument) is not fully resolvable from this packet.
}
