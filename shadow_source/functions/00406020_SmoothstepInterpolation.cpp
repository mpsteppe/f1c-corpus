// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406020
// Canonical corpus name: SmoothstepInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmoothstepInterpolation_00406020.c

void UnknownObject::SmoothstepInterpolation()
{
    // Attenuation-style smoothstep helper (__thiscall, double result). Forms a linear parameter v2 = this[7]*a2 + this[8]; when v2 >= 1.0 it returns base scale this[16] multiplied by an inverse blend 1/v2 + (1/v2^3 - 1/v2)*this[9], otherwise it returns this[16] unchanged. Reads four struct fields and calls nothing.
    // CALCULATION: Compute the linear parameter v2 = this[7] * a2 + this[8], blending the input a2 against field values. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // GUARD: Branch on v2 >= 1.0: the interpolated branch is taken only above the 1.0 threshold. [source:raw]
    // CALCULATION: When v2 >= 1.0, compute inverse-blend attenuation (1.0 / v2 + (1.0 / v2^3 - 1.0 / v2) * this[9]) scaled by base value this[16] and return it. [field:this:0x00000024, field:this:0x00000040, source:raw]
    // RETURN: When v2 < 1.0, return this[16] (base scale) unchanged. [field:this:0x00000040, source:raw]
    // CALL: Called by F_3DSoundPositioningUpdate (0x00405B90) to evaluate attenuation smoothstep for 3D sound positioning. [caller:0x00405B90, source:raw]

    // Conservative worker pseudocode:
    //   double sub_406020(float* this, float a2) {
    //     double v2 = (double)this[7] * a2 + (double)this[8];
    //     if (v2 >= 1.0) {
    //       double r = 1.0 / v2;
    //       return (r + (r * r * r - r) * (double)this[9]) * (double)this[16];
    //     }
    //     return (double)this[16];
    //   }
    // UNRESOLVED: Global flt_59E43C (0x0059E43C) is flagged by packet facts as read but appears nowhere in the raw decompiled source; its role is unverifiable from this packet.
    // UNRESOLVED: Semantic role of this[9] blend factor and this[16] base scale outside the sound-positioning caller is caller-context dependent.
}
