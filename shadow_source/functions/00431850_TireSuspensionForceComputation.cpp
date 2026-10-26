// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431850
// Canonical corpus name: TireSuspensionForceComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireSuspensionForceComputation_00431850.c

void UnknownObject::TireSuspensionForceComputation()
{
    // Computes a tire suspension force from compound properties, a mode selector and a session state value. Looks up the session state value (used as denominator) via SessionStateIndexedLookup, then returns 0 when tire brand data (unk_8ADB88) is unavailable or the compound data pointer cannot be resolved from the compound index at this+0xBC4. Selects a base force coefficient from the compound data according to the mode selector global dword_8AEEC0 (0 = aero field at +384 scaled by 0.98, 1 = blend of the +384 and +56 fields, 2 = suspension field at +56), returns 0 for any other selector value, scales the coefficient again by 0.98, and returns the scaled coefficient times the per-state suspension terms (int at this+0x1584 times double at this+0x1578 plus double at this+0x1570) divided by the session value, only while the scaled coefficient is positive.
    // CALL: Looks up the session state value (the eventual denominator) via SessionStateIndexedLookup on this with index a2 + 44 [callee:0x0042ED00, source:raw]
    // GUARD: Returns 0 when the tire brand data at unk_8ADB88 is not available, as reported by TireBrandLookup [callee:0x004D7880, global:0x008ADB88, source:raw]
    // CALL: Resolves the compound data pointer via CompoundIndexLookup using the compound index stored at this+0xBC4 [callee:0x004D7570, field:this:0x00000BC4, source:raw]
    // GUARD: Returns 0 when the compound data pointer could not be resolved [callee:0x004D7570, source:raw]
    // CALCULATION: Selects the base coefficient from the compound data by the mode selector global dword_8AEEC0: 0 uses the field at +384 scaled by 0.98, 1 blends the fields at +384 and +56, 2 uses the field at +56, and any other value returns 0 [global:0x008AEEC0, source:raw]
    // CALCULATION: Scales the selected coefficient twice by the suspension-force constant 0.98, backed by the referenced constant global dbl_59EA70 [global:0x0059EA70, source:raw]
    // CALCULATION: Blend mode averages the compound fields at +384 and +56 using the half-step constant 0.5, backed by the referenced constant global dbl_59E880 [global:0x0059E880, source:raw]
    // CALCULATION: Computes the final suspension force as the scaled coefficient times (int at this+0x1584 times double at this+0x1578 plus double at this+0x1570) divided by the session state value; the positivity guard uses the zero-sentinel constant, backed by the referenced constant global dbl_59E430 [global:0x0059E430, field:this:0x00001570, field:this:0x00001578, field:this:0x00001584, source:raw]
    // RETURN: Returns the computed force when the scaled coefficient is positive, otherwise 0 [function:0x00431850, source:raw]
    // STATE_TRANSITION: Called by sub_475A90 as part of the tire/suspension force computation path [caller:0x00475A90, source:raw]

    // Conservative worker pseudocode:
    //   sessionValue = SessionStateIndexedLookup(this, a2 + 44);
    //   if (!TireBrandLookup(&unk_8ADB88)) return 0.0;
    //   compound = CompoundIndexLookup(*(this + 0xBC4));
    //   if (!compound) return 0.0;
    //   if (dword_8AEEC0 == 0)
    //       coeff = *(double*)(compound + 0x180) * 0.98;
    //   else if (dword_8AEEC0 == 1)
    //       coeff = (*(double*)(compound + 0x180) + *(double*)(compound + 0x38)) * 0.5;
    //   else if (dword_8AEEC0 == 2)
    //       coeff = *(double*)(compound + 0x38);
    //   else
    //       return 0.0;
    //   scaled = coeff * 0.98;
    //   if (scaled <= 0.0) return 0.0;
    //   return scaled * ((double)*(int*)(this + 0x1584) * *(double*)(this + 0x1578) + *(double*)(this + 0x1570)) / sessionValue;
    // UNRESOLVED: The mode selector global dword_8AEEC0 and the compound fields at +384 and +56 are read by this function, but their authoritative names and units are defined by the owning subsystems outside this packet
    // UNRESOLVED: The per-state suspension terms at this+0x1570, this+0x1578 and this+0x1584 combine as int times double plus double, but the physical meaning of each term is not recoverable from this packet
    // UNRESOLVED: The mapping of the folded constants 0.98 and 0.5 to the referenced constant globals (dbl_59EA70, dbl_59E880, dbl_59E430) is DERIVED from the existing analysis and not confirmed by the raw function body
    // UNRESOLVED: The global dword_8AD254 is read by the function but does not appear in the Hex-Rays body; its role in the force computation is unresolved
}
