// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004AE750
// Canonical corpus name: sub_4AE750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4AE750_004ae750.c

void UnknownObject::InitDamagePartState()
{
    // Vehicle damage/part-state initializer driven by a clamped mode selector. Clamps the input a2 between bounds read from this+0x1AF4/this+0x1AF8, stores it at this+0x1AEC, then writes a set of paired flag+part-type-ID fields at this+0x3670..0x3A2C according to the mode (cases 1/2/3 differ in which parts are enabled and which type IDs they use), plus a tire-grip multiplier (this+0x49C) set to 0.6f for mode 1. A second block of 19 flag(0)+ID pairs is applied whenever the selector is nonzero. Returns 0. Called from TrackEnvironmentSelect, PlayerFileInit and TextFileReader.
    // ASSIGNMENT: Store the mode selector argument a2 into this+0x1AEC, saving the clamp bounds from this+0x1AF8 and this+0x1AF4. [field:this:0x00001AEC, field:this:0x00001AF4, field:this:0x00001AF8, source:raw]
    // CALL: ClampByRange(&this+0x1AEC, this+0x1AF4, this+0x1AF8): clamp the selector between its lower and upper bounds in place. [callee:0x0047F1F0, field:this:0x00001AEC, field:this:0x00001AF4, field:this:0x00001AF8, source:raw]
    // STATE_TRANSITION: Switch on the clamped selector this+0x1AEC with cases 1, 2, 3 and a default that skips the case block. [field:this:0x00001AEC, source:raw]
    // ASSIGNMENT: Case 1: disable the six part flags (0) and set part type IDs 52/51/30/44/56/184 (offsets 0x36C8, 0x36AC, 0x3674, 0x3690, 0x36E4, 0x3700), then set the tire-grip multiplier this+0x49C to 1058642330 (0.6f). [field:this:0x000036C4, field:this:0x000036C8, field:this:0x000036A8, field:this:0x000036AC, field:this:0x00003670, field:this:0x00003674, field:this:0x0000368C, field:this:0x00003690, field:this:0x000036E0, field:this:0x000036E4, field:this:0x000036FC, field:this:0x00003700, field:this:0x0000049C, source:raw]
    // ASSIGNMENT: Case 2: enable the five part flags (1) and set part type IDs 1/2/4/3/13/14 (offsets 0x36C8, 0x36AC, 0x3674, 0x3690, 0x36E4, 0x3700). [field:this:0x000036C4, field:this:0x000036C8, field:this:0x000036A8, field:this:0x000036AC, field:this:0x00003670, field:this:0x00003674, field:this:0x0000368C, field:this:0x00003690, field:this:0x000036E0, field:this:0x000036E4, field:this:0x00003700, source:raw]
    // ASSIGNMENT: Case 3: enable the five part flags (1) and set part type IDs 30/31/33/32/42/43 (offsets 0x36C8, 0x36AC, 0x3674, 0x3690, 0x36E4, 0x3700). [field:this:0x000036C4, field:this:0x000036C8, field:this:0x000036A8, field:this:0x000036AC, field:this:0x00003670, field:this:0x00003674, field:this:0x0000368C, field:this:0x00003690, field:this:0x000036E0, field:this:0x000036E4, field:this:0x00003700, source:raw]
    // ASSIGNMENT: After cases 2 and 3 (not case 1, not default): set flag this+0x36FC to 1. [field:this:0x000036FC, source:raw]
    // GUARD: Guard on this+0x1AEC being nonzero before applying the second block of part state. [field:this:0x00001AEC, source:raw]
    // ASSIGNMENT: Second block: write 19 paired flag(0)+value pairs: (0x3734,0x3738)=16, (0x3750,0x3754)=28, (0x376C,0x3770)=31, (0x3788,0x378C)=200, (0x37A4,0x37A8)=208, (0x37C0,0x37C4)=205, (0x37DC,0x37E0)=203, (0x37F8,0x37FC)=24, (0x3814,0x3818)=53, (0x3830,0x3834)=38, (0x384C,0x3850)=26, (0x3868,0x386C)=27, (0x3884,0x3888)=47, (0x38A0,0x38A4)=49, (0x38BC,0x38C0)=48, (0x38F4,0x38F8)=19, (0x3910,0x3914)=25, (0x392C,0x3930)=21, (0x3A28,0x3A2C)=89. [field:this:0x00003734, field:this:0x00003738, field:this:0x00003750, field:this:0x00003754, field:this:0x0000376C, field:this:0x00003770, field:this:0x00003788, field:this:0x0000378C, field:this:0x000037A4, field:this:0x000037A8, field:this:0x000037C0, field:this:0x000037C4, field:this:0x000037DC, field:this:0x000037E0, field:this:0x000037F8, field:this:0x000037FC, field:this:0x00003814, field:this:0x00003818, field:this:0x00003830, field:this:0x00003834, field:this:0x0000384C, field:this:0x00003850, field:this:0x00003868, field:this:0x0000386C, field:this:0x00003884, field:this:0x00003888, field:this:0x000038A0, field:this:0x000038A4, field:this:0x000038BC, field:this:0x000038C0, field:this:0x000038F4, field:this:0x000038F8, field:this:0x00003910, field:this:0x00003914, field:this:0x0000392C, field:this:0x00003930, field:this:0x00003A28, field:this:0x00003A2C, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4AE750(int *this, int mode) {
    //     int hi = this[1726], lo = this[1725];
    //     this[1723] = mode;
    //     ClampByRange(&this[1723], lo, hi);
    //     switch (this[1723]) {
    //       case 1: /* disable flags 0; part IDs 52,51,30,44,56,184; this[295]=0.6f * / break;
    //       case 2: /* enable flags 1; part IDs 1,2,4,3,13,14 * / this[3519]=1; break;
    //       case 3: /* enable flags 1; part IDs 30,31,33,32,42,43 * / this[3519]=1; break;
    //       default: break;
    //     }
    //     if (this[1723]) {
    //       /* 19 flag(0)+value pairs: 16,28,31,200,208,205,203,24,53,38,26,27,47,49,48,19,25,21,89 * /
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Packet abi label 'HUD_Display_Frame_Range_Configuration' (LEGACY) conflicts with the existing_analysis reading of a vehicle damage/part-state initializer; not resolvable from this packet alone.
    // UNRESOLVED: The exact meaning of the part type IDs and flag pairs (offsets 0x3670..0x3A2C) is not determinable here; semantics are inferred from the paired-flag-plus-ID layout.
}
