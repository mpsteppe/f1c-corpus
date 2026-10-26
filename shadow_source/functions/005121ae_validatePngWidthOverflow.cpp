// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005121AE
// Canonical corpus name: sub_5121AE
// Owner: PngImageValidation [DERIVED]
// Raw source: functions/sub_5121AE_005121ae.c

void PngImageValidation::validatePngWidthOverflow()
{
    // Reads PNG-style image dimensions and color-description bytes from a source struct (a2) into output pointers, computes a bytes-per-row factor, and validates that the width does not overflow row-size arithmetic. On overflow it dispatches the error string aWidthTooLargeF ("Width too large for libpng to process image data.") via CallbackDispatch and still returns 1. Returns 0 immediately if any of the first six arguments is null.
    // GUARD: If any of a1..a6 is null, return 0 immediately. [source:raw]
    // ASSIGNMENT: Output a3 = dword at a2+0 (image width). [source:raw]
    // ASSIGNMENT: Output a4 = dword at a2+4 (image height). [source:raw]
    // ASSIGNMENT: Output a5 = byte at a2+24 (bit depth). [source:raw]
    // ASSIGNMENT: Output a6 = byte at a2+25 (color-type byte). [source:raw]
    // ASSIGNMENT: If a8 non-null, output a8 = byte at a2+26. [source:raw]
    // ASSIGNMENT: If a9 non-null, output a9 = byte at a2+27. [source:raw]
    // ASSIGNMENT: If a7 non-null, output a7 = byte at a2+28. [source:raw]
    // CALCULATION: v9 = 1 when byte a2+25 equals 3, otherwise v9 = (byte a2+25 & 2) | 1. [source:raw]
    // CALCULATION: If (byte a2+25 & 4) is non-zero, increment v9. [source:raw]
    // GUARD: If width (*a3) > 0x7FFFFFFF / ((v9 * *a5 + 7) >> 3), dispatch the aWidthTooLargeF string ("Width too large for libpng to process image data.") via CallbackDispatch(a1, ...). [global:0x005AF3F0, callee:0x00511887]
    // RETURN: Return 1 after validation regardless of the overflow result. [function:0x005121AE, source:raw]

    // Conservative worker pseudocode:
    //   validate_png_dimensions(a1, a2, a3, a4, a5, a6, a7, a8, a9)
    //       if (!a1 || !a2 || !a3 || !a4 || !a5 || !a6)
    //           return 0;
    //       *a3 = dword(a2+0);  *a4 = dword(a2+4);
    //       *a5 = byte(a2+24);  *a6 = byte(a2+25);
    //       if (a8) *a8 = byte(a2+26);
    //       if (a9) *a9 = byte(a2+27);
    //       if (a7) *a7 = byte(a2+28);
    //       row_factor = (*a6 == 3) ? 1 : (*a6 & 2) | 1;
    //       if (*a6 & 4) row_factor++;
    //       if (*a3 > 0x7FFFFFFF / ((row_factor * *a5 + 7) >> 3))
    //           CallbackDispatch(a1, aWidthTooLargeF);
    //       return 1;
    // UNRESOLVED: Exact field meaning of bytes at a2+24..28 (bit depth, color type, interlace) and why a7/a8/a9 reads are optional.
    // UNRESOLVED: Relationship between the row-factor computation and a concrete PNG pixel layout.
    // UNRESOLVED: Role of the error-string global aWidthTooLargeF beyond being the dispatched message.
}
