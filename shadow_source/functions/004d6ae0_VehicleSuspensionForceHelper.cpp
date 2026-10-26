// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D6AE0
// Canonical corpus name: VehicleSuspensionForceHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSuspensionForceHelper_004d6ae0.c

void UnknownObject::VehicleSuspensionForceHelper()
{
    // Computes a suspension force scaled by temperature: (this[35] + 273.16) * a2 * 0.002778858444950814 * this[8] + this[7]. Adds a Kelvin-conversion term (this[35] + 273.16), scales by input factor a2, a fixed constant, and the position/scaling field this[8], then adds offset term this[7].
    // CALCULATION: Convert temperature to Kelvin scale: this[35] + 273.16. [field:this:0x00000118, source:raw]
    // CALCULATION: Compute force: (this[35] + 273.16) * a2 * 0.002778858444950814 * this[8] + this[7], scaling by input a2 and fields this[8], then adding offset this[7]. [field:this:0x00000038, field:this:0x00000040, field:this:0x00000118, source:raw]
    // RETURN: Return the computed force. [source:raw]

    // Conservative worker pseudocode:
    //   return (this[35] + 273.16) * a2 * 0.002778858444950814 * this[8] + this[7];
    // UNRESOLVED: Globals 0x0059EAC8 and 0x0059EB40 are listed as read in the packet but do not appear in the raw decompiled source; they may be the .rdata slots backing the double literals 273.16 and 0.002778858444950814, but that mapping is not evidenced.
    // UNRESOLVED: Existing-analysis names (temperature at this[35], scaling at this[8], additive offset at this[7]) are DERIVED prose, not packet evidence.
}
