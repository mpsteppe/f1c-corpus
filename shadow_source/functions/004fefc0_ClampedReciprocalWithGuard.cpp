// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FEFC0
// Canonical corpus name: ClampedReciprocalWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedReciprocalWithGuard_004fefc0.c

void UnknownObject::ClampedReciprocalWithGuard()
{
    // Stores input a2 as a float blend factor at this+0xA8, clamps it to the range [0.01, 1.0] (floor literal 1008981770, ceiling literal 1065185444), then writes 1.0/factor at this+0xAC and 1.0/(1.0-factor) at this+0xB0. Crossfade/interpolation coefficient preparation.
    // ASSIGNMENT: Store input a2 as float into field this+0xA8 (blend factor). [field:this:0x000000A8]
    // GUARD: If factor at this+0xA8 is below 0.01f, clamp it up to 0.01f (literal 1008981770). [field:this:0x000000A8]
    // GUARD: If factor at this+0xA8 exceeds 0.99f, clamp it down to 1.0f (literal 1065185444). [field:this:0x000000A8]
    // CALCULATION: Write reciprocal 1.0/factor to field this+0xAC. [field:this:0x000000AC]
    // CALCULATION: Write reciprocal-of-complement 1.0/(1.0-factor) to field this+0xB0. [field:this:0x000000B0]

    // Conservative worker pseudocode:
    //   this->factor = a2;
    //   if (this->factor < 0.01f) this->factor = 1008981770;
    //   else if (this->factor > 0.99f) this->factor = 1065185444;
    //   this->inv_factor = 1.0f / this->factor;
    //   this->inv_complement = 1.0f / (1.0f - this->factor);
    // UNRESOLVED: Globals flt_59E43C, flt_59E444 and flt_5AD2C0 are listed as read by static analysis but are not referenced in the shown raw source of this function.
    // UNRESOLVED: Whether the owner type owns the A8/AC/B0 fields is unknown; offsets 0xA8-0xB0 may belong to different classes at the two call sites.
}
