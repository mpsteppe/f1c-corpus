// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CDD80
// Canonical corpus name: TrackSurfaceMaterialLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSurfaceMaterialLoader_004cdd80.c

void UnknownObject::TrackSurfaceMaterialLoader()
{
    // Track surface material loader invoked from SpecialFX_Init. Parses a surface material definition from config entries (legal flag, base friction plus wet modifier, resistance, bump amplitude/wavelength, spring, damper, collision friction, sparks/scraping sound flags, sink depth, tire surface sound IDs) into a material struct, and resolves a material-name string into the same buffer.
    // GUARD: Read the 'Legal' property via sub_565520 into SrcStr; when present and sub_588410 reports it is not equal to 'true', set the byte at this+0x60 to 1. [callee:0x00565520, callee:0x00588410, global:0x005D38F0, global:0x005C596C, field:this:0x00000060, source:raw]
    // ASSIGNMENT: Parse the token at off_5D38EC into the float at this+8 (base friction) via sub_4CDC70; on success copy it into the float at this+12. [callee:0x004CDC70, global:0x005D38EC, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALCULATION: Parse the 'Wet' token into v13; on success recompute this+12 as (base friction at this+8) minus v13 (wet modifier). [callee:0x004CDC70, global:0x005D38E8, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Parse the 'Resistance' token into the float at this+16 (result discarded). [callee:0x004CDC70, global:0x005D38DC, source:raw]
    // CALCULATION: Parse the 'Bumpamp' token into the float at this+20; on success scale it by 0.25 (bump amplitude). [callee:0x004CDC70, global:0x005D38D4, field:this:0x00000014, source:raw]
    // CALCULATION: Parse the 'Bumpwavelen' token into v13; on success clamp v13 to a minimum of 3.0 and store 6.283185307179586 / v13 (bump wave frequency) at this+24. [callee:0x004CDC70, global:0x005D38C8, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Parse the 'Spring' token into the float at this+28 (result discarded). [callee:0x004CDC70, global:0x005D38C0, source:raw]
    // ASSIGNMENT: Parse the 'Damper' token into the float at this+32 (result discarded). [callee:0x004CDC70, global:0x005D38B8, source:raw]
    // ASSIGNMENT: Parse the 'Collfrict' token into the float at this+36 (result discarded). [callee:0x004CDC70, global:0x005D38AC, source:raw]
    // CALL: Resolve the 'Sparks' token via sub_565760 into the string at this+40. [callee:0x00565760, global:0x005D38A4, source:raw]
    // ASSIGNMENT: Resolve the 'Scraping' token via sub_565760 into v14; on success set the byte at this+44 to (v14 != 0). [callee:0x00565760, global:0x005D3898, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Parse the 'Sink' token into v13; on success store it as a double at this+100 (sink depth). [callee:0x004CDC70, global:0x005D3890, field:this:0x00000064, source:raw]
    // GUARD: Read the 'Sound' property via sub_565520 into SrcStr; then strcmp against off_5D38EC (default), 'Wet', 'Dirt', 'Grass', 'Gravel', 'Rumble', 'Tirewall', and 'Solidwall'/'Guardrail' to select a triple of tire surface sound IDs written to this+48/+52/+56 (default 6,21,27; wet 7,22,27; dirt 9,24,32; grass 8,23,32; gravel 10,25,32; rumble 11,21,27; tirewall 32,32,32; solidwall/guardrail 27,27,27). A non-matching string leaves the existing values untouched. [callee:0x00565520, global:0x005D3888, global:0x005D38EC, global:0x005D38E8, global:0x005D3880, global:0x005D3878, global:0x005D3870, global:0x005D3868, global:0x005D385C, global:0x005D3850, global:0x005D3844, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: Look up the 'Materials' token via sub_5654A0 into SrcStr; the non-zero result gates the material-string normalization below. [callee:0x005654A0, global:0x005D3838, source:raw]
    // LOOP: When SrcStr is non-empty, normalize it: shift the buffer left over each space character and over each comma not followed by another comma or the terminator, until the terminator is reached, then call sub_589901 on the buffer. [callee:0x00589901, source:raw]
    // CALL: Return StringCopyWithBufferRealloc(&SrcStr) when the 'Materials' lookup succeeded, copying the normalized material-name string into a reallocated buffer. [callee:0x00566650, source:raw]
    // RETURN: Return the copied material string on the success path, or the (non-zero) lookup result otherwise. [function:0x004CDD80, source:raw]

    // Conservative worker pseudocode:
    //   int TrackSurfaceMaterialLoader(int this, int a2, int a3) {
    //     if (getString(aLegal, SrcStr, 0) && !strEq(SrcStr, aTrue)) this[96] = 1;
    //     if (getFloat(a2, off_5D38EC, (float*)&this[8], a3)) this[12] = this[8];
    //     if (getFloat(a2, aWet, &v13, a3)) this[12] = this[8] - v13;
    //     getFloat(a2, aResistance, (float*)&this[16], a3);
    //     if (getFloat(a2, aBumpamp, (float*)&this[20], a3)) this[20] *= 0.25;
    //     if (getFloat(a2, aBumpwavelen, &v13, a3)) {
    //       if (v13 < 3.0) v13 = 3.0;
    //       this[24] = 6.283185307179586 / v13;
    //     }
    //     getFloat(a2, aSpring_0, (float*)&this[28], a3);
    //     getFloat(a2, aDamper, (float*)&this[32], a3);
    //     getFloat(a2, aCollfrict, (float*)&this[36], a3);
    //     getSound(aSparks, &this[40], 0, 0, 0);
    //     if (getSound(aScraping, &v14, 0, 0, 0)) this[44] = v14 != 0;
    //     if (getFloat(a2, aSink, &v13, a3)) *(double*)&this[100] = v13;
    //     if (getString(aSound, SrcStr, 0)) {
    //       if (!strcmp(SrcStr, off_5D38EC)) { this[48]=6; this[52]=21; this[56]=27; }
    //       else if (!strcmp(SrcStr, aWet)) { this[48]=7; this[52]=22; this[56]=27; }
    //       else if (!strcmp(SrcStr, aDirt)) { this[48]=9; this[52]=24; this[56]=32; }
    //       else if (!strcmp(SrcStr, aGrass)) { this[48]=8; this[52]=23; this[56]=32; }
    //       else if (!strcmp(SrcStr, aGravel)) { this[48]=10; this[52]=25; this[56]=32; }
    //       else if (!strcmp(SrcStr, aRumble)) { this[48]=11; this[52]=21; this[56]=27; }
    //       else if (!strcmp(SrcStr, aTirewall)) { this[48]=this[52]=this[56]=32; }
    //       else if (!strcmp(SrcStr, aSolidwall) || !strcmp(SrcStr, aGuardrail))
    //         { this[48]=this[52]=this[56]=27; }
    //     }
    //     result = getString(aMaterials, SrcStr);
    //     if (result) {
    //       stripSpacesAndCollapseCommas(SrcStr);
    //       return copyStringRealloc(SrcStr);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Data globals flt_59E478, flt_59E7F8 and dbl_59ED28 appear as read references in the packet but have no visible use in the decompiled source text; possibly compiler-materialized constant-pool values whose mapping to a literal is unresolved.
    // UNRESOLVED: Parameters a2 and a3 are only known to be the config source handle and a passthrough to sub_4CDC70; their exact types/roles are unresolved.
    // UNRESOLVED: A sound string matching none of the branches leaves the this+48/+52/+56 sound IDs at their pre-existing struct values (no default assignment branch).
    // UNRESOLVED: The material-string normalization loop is interpreted as removing spaces and collapsing adjacent commas; the intended material-name grammar is DERIVED from code, not confirmed.
}
