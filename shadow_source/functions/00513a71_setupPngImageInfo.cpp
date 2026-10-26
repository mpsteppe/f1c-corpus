// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513A71
// Canonical corpus name: sub_513A71
// Owner: PngImageSetup [DERIVED]
// Raw source: functions/sub_513A71_00513a71.c

void PngImageSetup::setupPngImageInfo()
{
    // Populates a PNG-style image-descriptor struct (a2) from scalar arguments: width, height, bit depth, color-type and flag bytes, then computes a row factor and rowbytes. If the width would overflow row-size arithmetic it dispatches the error string aWidthTooLargeT ("Width too large to process image data; rowbytes will overflow.") via CallbackDispatch and stores rowbytes as 0. No-op unless both a1 and a2 are non-null.
    // GUARD: Only proceed when a1 and a2 are both non-null; otherwise do nothing. [source:raw]
    // ASSIGNMENT: byte at a2+26 = a8. [source:raw]
    // ASSIGNMENT: dword at a2+4 = a4 (height). [source:raw]
    // ASSIGNMENT: byte at a2+27 = a9. [source:raw]
    // ASSIGNMENT: dword at a2+0 = a3 (width). [source:raw]
    // ASSIGNMENT: byte at a2+24 = a5 (bit depth). [source:raw]
    // ASSIGNMENT: byte at a2+25 = a6 (color-type byte). [source:raw]
    // ASSIGNMENT: byte at a2+28 = a7. [source:raw]
    // CALCULATION: byte at a2+29 = 1 when a6 equals 3 or (a6 & 2) is zero, otherwise 3. [source:raw]
    // CALCULATION: If (a6 & 4) is non-zero, increment byte at a2+29. [source:raw]
    // CALCULATION: byte at a2+30 = v9 = a5 * byte at a2+29 (bit depth scaled by row factor). [source:raw]
    // GUARD: When a3 <= 0x7FFFFFFF / ((v9 + 7) >> 3), store rowbytes = (a3 * v9 + 7) >> 3 at a2+12; otherwise dispatch the aWidthTooLargeT string ("Width too large to process image data; rowbytes will overflow.") via CallbackDispatch(a1, ...) and store rowbytes = 0. [source:raw, global:0x005AF484, callee:0x00511887]

    // Conservative worker pseudocode:
    //   setup_image_info(a1, a2, a3, a4, a5, a6, a7, a8, a9)
    //       if (!a1 || !a2)
    //           return;
    //       dword(a2+0) = a3;  dword(a2+4) = a4;
    //       byte(a2+24) = a5;  byte(a2+25) = a6;
    //       byte(a2+26) = a8;  byte(a2+27) = a9;  byte(a2+28) = a7;
    //       byte(a2+29) = (a6 == 3 || (a6 & 2) == 0) ? 1 : 3;
    //       if (a6 & 4) byte(a2+29)++;
    //       byte(a2+30) = a5 * byte(a2+29);
    //       if (a3 <= 0x7FFFFFFF / ((byte(a2+30) + 7) >> 3))
    //           dword(a2+12) = (a3 * byte(a2+30) + 7) >> 3;
    //       else {
    //           CallbackDispatch(a1, aWidthTooLargeT);
    //           dword(a2+12) = 0;
    //       }
    // UNRESOLVED: Exact semantics of the flag bytes a6/a7/a8/a9 and of descriptor fields at a2+29 and a2+30.
    // UNRESOLVED: The relation of the row-factor derivation to a concrete PNG color type.
    // UNRESOLVED: Role of the error-string global aWidthTooLargeT beyond being the dispatched message.
}
