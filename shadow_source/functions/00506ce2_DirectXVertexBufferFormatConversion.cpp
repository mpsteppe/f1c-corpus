// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00506CE2
// Canonical corpus name: DirectXVertexBufferFormatConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXVertexBufferFormatConversion_00506ce2.c

void UnknownObject::DirectXVertexBufferFormatConversion()
{
    // Converts per-vertex float data between normalized, signed, and direct coordinate ranges based on a destination format code this[2] and a source format code this[1042]. Reads 4 floats per element from a2 + 8 with a 16-byte stride, applies the (dest, source) conversion to each channel, writes the results to this[1043], and returns the output pointer this[1043]. Unhandled format combinations fall through without writing.
    // GUARD: Dispatch on the destination format selector this[2] via a switch with cases 1, 2 and 3. [field:this:0x00000008, source:raw]
    // GUARD: Within each destination case, dispatch on the source format selector this[1042]: case 1 accepts source 2 or 3, case 2 accepts source 1 or 3, case 3 accepts source 1 or 2; unmatched source combinations fall through. [guard:0, guard:1, guard:2, field:this:0x00001048, source:raw]
    // LOOP: Iterate over this[1046] elements; read 4 input floats per element starting at a2 + 8, advance the input pointer by 16 bytes (4 dwords) each iteration, and write the converted values into the output region at this[1043]. [field:this:0x00001058, field:this:0x0000104C, source:raw]
    // ASSIGNMENT: Destination format 1: map each channel from signed range to normalized range via (v + 1.0) * 0.5; the alpha channel is passed through unchanged when source format is 2, and also scaled when source format is 3. [source:raw]
    // ASSIGNMENT: Destination format 2: map each channel from normalized range to signed range via v * 2.0 - 1.0; the alpha channel is passed through unchanged when source format is 1, and mapped via (v + 1.0) * 0.5 when source format is 3. [source:raw]
    // ASSIGNMENT: Destination format 3: for source format 1 all four channels are mapped via v * 2.0 - 1.0; for source format 2 the RGB channels pass through unchanged and the alpha channel is mapped via v + v - 1.0. [source:raw]
    // RETURN: Return the output pointer this[1043]. [field:this:0x0000104C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_506CE2(this, int a2) {
    //     switch (this[2]) {
    //       case 1: if (this[1042] == 2 || this[1042] == 3) convert((v + 1.0) * 0.5, alpha per source); break;
    //       case 2: if (this[1042] == 1 || this[1042] == 3) convert(v * 2.0 - 1.0, alpha per source); break;
    //       case 3: if (this[1042] == 1 || this[1042] == 2) convert(per source); break;
    //     }
    //     // per element i < this[1046]: read 4 floats from (a2 + 8) + i*16, write to this[1043] + i*16
    //     return this[1043];
    //   }
    // UNRESOLVED: Float globals flt_59E43C (0x0059E43C), flt_59E450 (0x0059E450) and flt_59E800 (0x0059E800) are data xrefs of this function but are not named in the decompiled body; they likely hold the 1.0 / 2.0 / 0.5 constants, unverified.
    // UNRESOLVED: The format-code meanings (1 = normalized, 2 = signed, 3 = direct) are a DERIVED interpretation of the arithmetic, not a confirmed named enum.
}
