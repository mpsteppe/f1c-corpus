// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005006A4
// Canonical corpus name: FourCCDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FourCCDecoder_005006a4.c

void UnknownObject::FourCCDecoder()
{
    // FourCC-to-format-identifier decoder. Dispatches on the incoming 32-bit value a1: four specific FourCC constants (909200416, 909200449, 909201952, 909201985) map to small format identifiers 50, 51, 20 and 21 respectively; any other value is returned unchanged. Used during surface-format negotiation by DirectXSurfaceFormatNegotiation (0x00502A15).
    // GUARD: Dispatch switch on a1; only the four listed constant cases take the mapping path, everything else falls to the identity default. [source:raw]
    // RETURN: Case 909200416 maps to format identifier 50. [source:raw]
    // RETURN: Case 909200449 maps to format identifier 51. [source:raw]
    // RETURN: Case 909201952 maps to format identifier 20. [source:raw]
    // RETURN: Case 909201985 maps to format identifier 21. [source:raw]
    // RETURN: Default path returns the original value a1 unchanged when it matches no mapped FourCC; the function is invoked from DirectXSurfaceFormatNegotiation (0x00502A15). [caller:0x00502A15, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5006A4(int a1) {
    //     switch (a1) {
    //       case 909200416: return 50;
    //       case 909200449: return 51;
    //       case 909201952: return 20;
    //       case 909201985: return 21;
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: The concrete DirectX (or other) surface formats represented by the four FourCC constants are not documented in this packet.
    // UNRESOLVED: Why these particular formats map to 20/21/50/51 (rather than a contiguous range) is unknown from this function alone.
    // UNRESOLVED: The owning class or subsystem is unidentified (no fields, globals or callees in the packet).
}
