// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BB60
// Canonical corpus name: IDToColorMaskMapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDToColorMaskMapper_0045bb60.c

void UnknownObject::IDToColorMaskMapper()
{
    // Maps a small identifier (1 or 2) to a 32-bit color mask constant; any other value returns the default mask -1. Called by TextLineWrappingAndRendering (0x0045BD10) on the frame path.
    // GUARD: If input a1 equals 1 [source:raw]
    // RETURN: Return color mask -65536 [source:raw, function:0x0045BB60]
    // GUARD: If input a1 equals 2 [source:raw]
    // RETURN: Return color mask -256 [source:raw, function:0x0045BB60]
    // RETURN: Default: return color mask -1 [source:raw, function:0x0045BB60]

    // Conservative worker pseudocode:
    //   if (a1 == 1) return -65536;
    //   if (a1 == 2) return -256;
    //   return -1;
    // UNRESOLVED: Semantic meaning of the mapped mask values is not grounded in packet evidence.
    // UNRESOLVED: Range of accepted identifiers beyond 1 and 2 is unknown.
}
