// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FF040
// Canonical corpus name: ValueClampRange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ValueClampRange_004ff040.c

void UnknownObject::ValueClampRange()
{
    // Writes a clamped range into two this-float fields: low (this[63], offset 0xFC) = 1 - a2 clamped to [0, 1]; high (this[64], offset 0x100) = 1 - a3, forced >= low and clamped to <= 1.0. Existing analysis labels it an audio-parameter range clamp; callers are sub_402690 and sub_4FCAA0.
    // ASSIGNMENT: Write the low bound candidate: this[63] = 1.0 - a2. [field:this:0x000000FC, source:raw]
    // GUARD: Clamp the low bound from below: when this[63] < 0.0, set this[63] = 0.0. [field:this:0x000000FC, source:raw]
    // GUARD: Clamp the low bound from above: when this[63] > 1.0, set this[63] = 1.0. [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Write the high bound candidate: this[64] = 1.0 - a3. [field:this:0x00000100, source:raw]
    // GUARD: When this[63] <= this[64], clamp the high bound from above: if this[64] > 1.0 then this[64] = 1.0. [field:this:0x000000FC, field:this:0x00000100, source:raw]
    // STATE_TRANSITION: When this[63] > this[64], force the high bound up to the low bound: this[64] = this[63]. [field:this:0x000000FC, field:this:0x00000100, source:raw]

    // Conservative worker pseudocode:
    //   void ValueClampRange(float *this, float a2, float a3) {
    //     this[63] = 1.0f - a2;
    //     if (this[63] >= 0.0f) { if (this[63] > 1.0f) this[63] = 1.0f; }
    //     else { this[63] = 0.0f; }
    //     this[64] = 1.0f - a3;
    //     if (this[63] <= this[64]) { if (this[64] > 1.0f) this[64] = 1.0f; }
    //     else { this[64] = this[63]; }
    //   }
    // UNRESOLVED: flt_59E43C and flt_59E440 are listed as read globals but do not appear in the raw source.
    // UNRESOLVED: Audio-parameter interpretation comes from existing analysis only; not confirmed by packet raw source.
}
