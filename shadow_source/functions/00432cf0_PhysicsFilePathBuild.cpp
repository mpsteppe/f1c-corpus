// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432CF0
// Canonical corpus name: PhysicsFilePathBuild
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsFilePathBuild_00432cf0.c

void UnknownObject::PhysicsFilePathBuild()
{
    // Builds a physics file path into an output buffer: obtains an identifier from ShortComputation_0b10(), formats it into a local 256-byte buffer, strips the last dot-suffix, appends the extension string off_5C3F84[0], and copies the composed path into caller buffer a2 bounded to a3-1 bytes. Returns 0 on success and 1 on failure (null a1, or composed length reaching 0x100).
    // GUARD: Return error code 1 when input a1 is null; no path is built. [source:raw, function:0x00432CF0]
    // CALL: Call ShortComputation_0b10() to obtain the identifier used as the path's base name source. [callee:0x004B0B10]
    // CALL: Call sub_587DD0 to write the identifier into local buffer v6 with limit 255. [callee:0x00587DD0]
    // ASSIGNMENT: Force NUL at v6[255] so the local 256-byte buffer is always terminated. [source:raw]
    // CALCULATION: Advance to the end of the string in v6, then scan back to the last '.' (46) and truncate there, removing the existing suffix (extension). [source:raw]
    // GUARD: Return error code 1 if the stripped name length plus the length of off_5C3F84[0] reaches 0x100. [global:0x005C3F84, source:raw]
    // CALCULATION: Append the extension string at off_5C3F84[0] to the truncated base name in v6. [global:0x005C3F84, source:raw]
    // CALL: Call sub_587DD0 to copy the composed path from v6 into output buffer a2 with limit a3-1. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: NUL-terminate the output at (a3-1)+a2 after the copy. [source:raw]
    // RETURN: Return 0 to signal the path was built successfully. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return 1;
    //   v3 = ShortComputation_0b10();
    //   sub_587DD0(v6, v3, 255);
    //   v6[255] = 0;
    //   scan from end of v6 back to last '.'; if found, truncate there;
    //   if (strlen(v6) + strlen(off_5C3F84[0]) >= 0x100) return 1;
    //   append off_5C3F84[0] to v6;
    //   sub_587DD0(a2, v6, a3 - 1);
    //   a2[a3 - 1] = 0;
    //   return 0;
    // UNRESOLVED: Meaning of the value produced by ShortComputation_0b10 (likely a numeric id/file base name) is not established by the packet.
    // UNRESOLVED: Semantics of sub_587DD0 (string copy vs formatted write) are unconfirmed; only its buffer-limit behaviour is evidenced.
    // UNRESOLVED: The content of off_5C3F84[0] (presumably a file extension such as .rcd) is a pointer dereference not resolvable from this packet.
    // UNRESOLVED: Return-code convention (0 success / 1 failure) is inferred from local control flow only.
}
