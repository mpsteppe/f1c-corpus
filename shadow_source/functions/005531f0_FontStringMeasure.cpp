// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005531F0
// Canonical corpus name: sub_5531F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5531F0_005531f0.c

void UnknownObject::FontStringMeasure()
{
    // Measures a text string using this font descriptor. Computes a scale factor: default 1.0, or the float at this+0x5C when a5 is non-zero. When a4 (height out) is non-null it is assigned CRTFtol(scale). When a3 (width out) is non-null, accumulates a per-glyph width over a2 by indexing a width table at this + 8*char - 148, gated to chars in [0x20, this+0x44); the raw flow then overwrites *a3 with CRTFtol(scale). Returns the last scale-truncated value.
    // ASSIGNMENT: Initialize scale to 1.0 and result to a5. [source:raw]
    // GUARD: Guard on a5 non-zero: when set, load the scale factor float from this+0x5C. [field:this:0x0000005C]
    // GUARD: Guard on the height output pointer a4 being non-null. [source:raw]
    // CALL: Call CRTFtol(scale) to truncate the float scale to an integer and store it through a4. [callee:0x00587BDC]
    // GUARD: Guard on the width output pointer a3 being non-null. [source:raw]
    // LOOP: Iterate every character of a2, from index 0 up to strlen(a2). [source:raw]
    // GUARD: Guard per character: only chars >= 0x20 and below the glyph-count bound at this+0x44 contribute a width. [field:this:0x00000044, source:raw]
    // CALCULATION: Add the glyph width from the table at this + 8*char - 148 (8-byte stride per glyph) to the running width at *a3. [source:raw]
    // CALL: Call CRTFtol(scale) and store the result through a3, overwriting the accumulated width per the raw flow. [callee:0x00587BDC]
    // RETURN: Return the last CRTFtol(scale) result. [callee:0x00587BDC, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5531F0(int this, const char *s, int *width_out, int *height_out, int use_scale) {
    //     float scale = use_scale ? *(float *)(this + 0x5C) : 1.0f;
    //     int result = use_scale;
    //     if (height_out) { result = CRTFtol(scale); *height_out = result; }
    //     if (width_out) {
    //       *width_out = 0;
    //       for (unsigned i = 0; i < strlen(s); ++i) {
    //         unsigned char c = s[i];
    //         if (c >= 0x20 && c < *(int *)(this + 0x44))
    //           *width_out += *(unsigned char *)(this + 8*c - 148);
    //       }
    //       result = CRTFtol(scale);
    //       *width_out = result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The raw flow overwrites the accumulated width at *a3 with CRTFtol(scale) after the summing loop, discarding the per-glyph total; the intended width transform is ambiguous.
    // UNRESOLVED: Table anchor at this - 148 with an 8-byte glyph stride is inferred from the expression this + 8*char - 148 and is not a named packet field.
    // UNRESOLVED: global:0x0059E43C (flt_59E43C) is not referenced in the raw source; its role here is unknown.
    // UNRESOLVED: Object type of this (font descriptor with scale at +0x5C and glyph bound at +0x44) is a DERIVED interpretation from the usage pattern.
}
