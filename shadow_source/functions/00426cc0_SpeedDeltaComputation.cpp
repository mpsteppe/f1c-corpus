// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00426CC0
// Canonical corpus name: SpeedDeltaComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpeedDeltaComputation_00426cc0.c

void UnknownObject::SpeedDeltaComputation()
{
    // Returns the speed difference between the AI's target vehicle pointer stored at this[4309] (this+0x4354) and a caller-supplied vehicle a2, each read as a float at +76. Returns 0.0 when a2 is null, -1.0 when no target vehicle is set, otherwise (float)(a2+76) - (float)(v3+76). On the frame path, used by AI overtaking / nearest-vehicle logic; called by sub_4A4110 (0x004A4110) and FindNearestVehicle (0x004A4710).
    // GUARD: if a2 == 0 (null vehicle pointer) return 0.0 immediately (zero threshold constant flt_59E440) [global:0x0059E440, source:raw]
    // CALCULATION: v3 = this[4309]: load target/lead vehicle pointer from field this+0x4354 [field:this:0x00004354, source:raw]
    // GUARD: if v3 == 0 (no target vehicle set) skip the delta computation and fall through to the -1.0 sentinel return (sentinel constant flt_59E670) [global:0x0059E670, source:raw]
    // CALCULATION: Return speed delta: *(float*)(a2 + 76) - *(float*)(v3 + 76) [abi:lead, source:raw]
    // RETURN: Default return -1.0 when the target vehicle pointer is null [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return 0.0;
    //   v3 = this[4309];
    //   if (v3 == 0) return -1.0;
    //   return *(float*)(a2 + 76) - *(float*)(v3 + 76);
    // UNRESOLVED: The float at +76 in each of the two vehicles is not proven to be the same quantity; equal offsets on unrelated this pointers are not proof of identical fields.
    // UNRESOLVED: Field this+0x43A0 is present in the IDB as an accessed field but does not appear in the decompiled body; its role is unresolved.
    // UNRESOLVED: flt_59E440 / flt_59E670 are bound to the 0.0 / -1.0 literals only via the existing analysis (DERIVED); they are not named in the raw source text.
}
