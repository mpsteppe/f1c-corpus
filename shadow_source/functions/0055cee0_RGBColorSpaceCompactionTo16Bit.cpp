// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CEE0
// Canonical corpus name: RGBColorSpaceCompactionTo16Bit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGBColorSpaceCompactionTo16Bit_0055cee0.c

void UnknownObject::RGBColorSpaceCompactionTo16Bit()
{
    // Packs separate R/G/B color channels into a single 16-bit word. When the format selector a1 is 6 the function produces an RGB565 value: red (5 bits from a2), green (6 bits from a3) and blue (5 bits from a4). When a1 is 5 it produces an RGB555 value: red (5 bits from a2), green (5 bits from a3) and blue (5 bits from a4). For any other format selector it returns 0.
    // ASSIGNMENT: Initialize result to 0 before any format check. [source:raw]
    // GUARD: When the format selector a1 equals 6, take the RGB565 packing path. [source:raw]
    // CALCULATION: RGB565 packing: red occupies the top five bits of a2 (a2 & 0xF8) shifted into bit range 11-15, green occupies six bits of a3 (a3 & 0xFC) shifted into bit range 5-10, and blue occupies the top five bits of a4 ((a4 >> 3) & 0x1F) in bit range 0-4; all OR-merged into the result. [source:raw]
    // GUARD: When the format selector a1 equals 5, take the RGB555 packing path. [source:raw]
    // CALCULATION: RGB555 packing: red occupies the top five bits of a2 (a2 & 0xF8) shifted into bit range 10-14, green occupies the top five bits of a3 (a3 & 0xF8) shifted into bit range 5-9, and blue occupies the top five bits of a4 ((a4 >> 3) & 0x1F) in bit range 0-4; all OR-merged into the result. [source:raw]
    // RETURN: Return the packed 16-bit color word for supported formats, or 0 when a1 is neither 5 nor 6. [function:0x0055CEE0]

    // Conservative worker pseudocode:
    //   int sub_55CEE0(int format, int r, int g, int b) {
    //     if (format == 6)
    //       return ((b >> 3) & 0x1F) | (((g & 0xFC) | ((r & 0xF8) << 5)) << 3);
    //     if (format == 5)
    //       return ((b >> 3) & 0x1F) | (((g & 0xF8) | ((r & 0xF8) << 5)) << 2);
    //     return 0;
    //   }
    // UNRESOLVED: Channel-to-argument mapping (which of a2/a3/a4 is red, green or blue) is inferred from the bit widths of the masks, not proven by call-site evidence.
    // UNRESOLVED: The caller at 0x0055CEB0 that supplies the format selector and channel values is not analyzed here.
    // UNRESOLVED: It is not established whether the 16-bit result feeds a texture, a palette entry or a pixel buffer consumer.
}
