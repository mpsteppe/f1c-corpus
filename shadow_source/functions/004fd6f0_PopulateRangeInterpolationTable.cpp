// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FD6F0
// Canonical corpus name: RangeInterpolationTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RangeInterpolationTable_004fd6f0.c

void UnknownObject::PopulateRangeInterpolationTable()
{
    // Populates a 16-entry interpolation table in the object (this[25..40], byte offsets 0x64..0xA0) from the [min, max] range this[10..11] (offsets 0x28..0x2C): each entry is min + fraction * (max - min) at fixed fractions (0.05, 0.03, 0.01, 0.0, 0.01, 0.06, 0.14, 0.25, 0.37, 0.5, 0.63, 0.75, 0.86, 0.94, 0.99, 1.0). The fraction constants are read from a data-segment float pool (flt_59E440..flt_5AD2CC). Used by struct-init, audio-ADSR and car-position paths to precompute parameter curves.
    // CALCULATION: Load the range minimum v1 = this[10] (byte offset 0x28). [field:this:0x00000028, source:raw]
    // CALCULATION: Compute the range span v2 = this[11] - this[10] (byte offsets 0x2C minus 0x28). [field:this:0x0000002C, field:this:0x00000028, source:raw]
    // CALCULATION: Interpolate and store this[25] (0x64) = min + 0.05 * span and this[26] (0x68) = min + 0.03 * span. [field:this:0x00000064, field:this:0x00000068, source:raw]
    // CALCULATION: Store this[27] (0x6C) = min + 0.01 * span and reuse that value for this[29] (0x74); store this[28] (0x70) = min + 0.0 * span (the exact minimum). [field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, source:raw]
    // CALCULATION: Store the mid-range entries this[30..33] (0x78..0x84) at fractions 0.06, 0.14, 0.25 and 0.37. [field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, source:raw]
    // CALCULATION: Store the upper entries this[34..40] (0x88..0xA0) at fractions 0.5, 0.63, 0.75, 0.86, 0.94, 0.99 and 1.0. [field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A0, source:raw]
    // CALCULATION: The interpolation fractions are read from the data-segment float constant pool: flt_59E440, flt_59E444, flt_59E448, flt_59E450, flt_59E454, flt_59E7F8, flt_59E7FC, flt_5ACD48, flt_5ACDC0, flt_5AD150, flt_5AD2C0, flt_5AD2C4, flt_5AD2C8, flt_5AD2CC. [global:0x0059E440, global:0x0059E444, global:0x0059E448, global:0x0059E450, global:0x0059E454, global:0x0059E7F8, global:0x0059E7FC, global:0x005ACD48, global:0x005ACDC0, global:0x005AD150, global:0x005AD2C0, global:0x005AD2C4, global:0x005AD2C8, global:0x005AD2CC, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4FD6F0(float* this) {
    //     float min = this[10];
    //     float span = this[11] - min;
    //     this[25] = min + 0.05f * span;
    //     this[26] = min + 0.03f * span;
    //     this[27] = min + 0.01f * span;
    //     this[28] = min;
    //     this[29] = min + 0.01f * span;
    //     this[30] = min + 0.06f * span;
    //     this[31] = min + 0.14f * span;
    //     this[32] = min + 0.25f * span;
    //     this[33] = min + 0.37f * span;
    //     this[34] = min + 0.5f * span;
    //     this[35] = min + 0.63f * span;
    //     this[36] = min + 0.75f * span;
    //     this[37] = min + 0.86f * span;
    //     this[38] = min + 0.94f * span;
    //     this[39] = min + 0.99f * span;
    //     this[40] = min + 1.0f * span;
    //   }
    // UNRESOLVED: The exact mapping of each float-pool global (flt_59E440..flt_5AD2CC) to its interpolation fraction is unverified; the decompiled body shows literals while the packet flags these globals as read-only xrefs.
    // UNRESOLVED: The owning class and the consumer of the 16-entry table (offsets 0x64..0xA0) are inferred from the callers (struct init, audio ADSR, car-position check); owner remains UnknownObject.
    // UNRESOLVED: The asymmetric fraction sequence (0.05, 0.03, 0.01, 0.0, 0.01, 0.06, ...) suggests a hand-tuned curve rather than uniform quantisation; the intended application is not determinable from this packet alone.
}
