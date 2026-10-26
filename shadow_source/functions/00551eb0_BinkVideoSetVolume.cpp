// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551EB0
// Canonical corpus name: sub_551EB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_551EB0_00551eb0.c

void UnknownObject::BinkVideoSetVolume()
{
    // Sets the playback volume on a Bink video object. Only updates when the new volume a2 differs from the stored float at this+0x10 and lies within the range bounded by the two stored double constants dbl_59E430 and dbl_59E420. The accepted value is stored back at this+0x10, scaled by the constant dbl_5B8990, truncated to an integer via CRTFtol, and passed to BinkSetVolume together with the Bink handle at this+0x0.
    // GUARD: If the stored volume at this+0x10 already equals a2, or a2 falls outside the range bounded by dbl_59E430 and dbl_59E420, skip the update. [field:this:0x00000010, global:0x0059E430, global:0x0059E420, source:raw]
    // ASSIGNMENT: Store a2 into this+0x10 as the current volume. [field:this:0x00000010, source:raw]
    // CALCULATION: Scale the volume by dbl_5B8990 and truncate to an integer via CRTFtol. [global:0x005B8990, callee:0x00587BDC, source:raw]
    // CALL: Call BinkSetVolume with the Bink handle at this+0x0, channel 0, and the scaled volume integer. [global:0x0059E33C, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   if (this->volume_10 == a2) return;
    //   if (a2 < dbl_59E430) return;
    //   if (a2 > dbl_59E420) return;
    //   this->volume_10 = a2;
    //   int scaled = CRTFtol(a2 * dbl_5B8990);
    //   BinkSetVolume(this->bink_handle_0, 0, scaled);
    // UNRESOLVED: The identity of the two bound constants (dbl_59E430 = 0.0 lower bound, dbl_59E420 = 1.0 upper bound) and of the scaling factor (dbl_5B8990 = 32768.0) comes from the embedded skeleton prose, not from the raw source, so the constant-to-global mapping is DERIVED.
    // UNRESOLVED: The exact semantics of the second argument to BinkSetVolume (channel/track index 0) are not explained by this packet.
}
