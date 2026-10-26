// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0180
// Canonical corpus name: sub_4B0180
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B0180_004b0180.c

void UnknownObject::BuildDirectoryPath()
{
    // Builds a directory path string into output buffer a2 by formatting "%s%s\\" with a directory prefix and input name a1. The directory prefix is dword_5EC440 when non-null, otherwise the byte_5EA438 default. Always returns 0.
    // ASSIGNMENT: Set v2 to the dword_5EC440 pointer. [global:0x005EC440, source:raw]
    // GUARD: If dword_5EC440 is null, fall back to v2 = byte_5EA438 as the directory prefix. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck with the "%s%s\\" format string (aSS_5), output buffer a2, directory prefix v2, and name a1. [callee:0x0058815F, global:0x005C6968, source:raw]
    // RETURN: Return 0. [source:raw, function:0x004B0180]

    // Conservative worker pseudocode:
    //   v2 = dword_5EC440;
    //   if (!dword_5EC440)
    //       v2 = byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(a2, "%s%s\\", v2, a1);
    //   return 0;
    // UNRESOLVED: Semantic role of dword_5EC440 (settings directory) and byte_5EA438 (default directory) is DERIVED in existing analysis, not packet-confirmed; treat as unknown.
    // UNRESOLVED: Whether output buffer a2 requires pre-existing capacity or a null-terminated convention is not evidenced in the packet.
}
