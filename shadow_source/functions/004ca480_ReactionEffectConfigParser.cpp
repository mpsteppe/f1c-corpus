// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CA480
// Canonical corpus name: MaterialShaderReactionEffectParser
// Owner: MaterialReactionEffectParser [DERIVED]
// Raw source: functions/MaterialShaderReactionEffectParser_004ca480.c

void MaterialReactionEffectParser::ReactionEffectConfigParser()
{
    // Parses a reaction-effect configuration block: reads the 'reaction' token and maps it to an effect type id (dust/smokes/flames/skid/spray/rain etc) stored at this+4, then reads scale/growth/growthvel/duration/asdenvelope/power/rampspeed/offsetvel numeric fields, a waypoint-count token, and builds a 176-byte renderer sub-object at this+80 with texture/.MTS/.BMP filename buffers, vertex/pixel shader flag bitmasks, particle flags, chroma/color values and source/destination blend modes.
    // ASSIGNMENT: Initialize the local 256-byte token buffer: v12[0] = 0. [source:raw]
    // CALL: FloatStructInitializer(this): zero-initialize the float structure backing this. [callee:0x004CA430, source:raw]
    // GUARD: sub_565520(aReaction, v12, 0): read the 'reaction' token into the buffer; the whole effect-type mapping only runs when the token is present. [callee:0x00565520, global:0x005D36D8, source:raw]
    // STATE_TRANSITION: strcmp(v12, aDust): set effect type this+4 = 0. [field:this:0x00000004, global:0x005D36D0, source:raw]
    // STATE_TRANSITION: strcmp(v12, aWhitesmoke): set effect type this+4 = 1. [field:this:0x00000004, global:0x005D36C4, source:raw]
    // STATE_TRANSITION: strcmp(v12, aBluesmoke): set effect type this+4 = 2. [field:this:0x00000004, global:0x005D36B8, source:raw]
    // STATE_TRANSITION: strcmp(v12, aBlacksmoke): set effect type this+4 = 3. [field:this:0x00000004, global:0x005D36AC, source:raw]
    // STATE_TRANSITION: strcmp(v12, aFlames): set effect type this+4 = 4. [field:this:0x00000004, global:0x005D36A4, source:raw]
    // STATE_TRANSITION: strcmp(v12, aSpray): set effect type this+4 = 5. [field:this:0x00000004, global:0x005D3688, source:raw]
    // STATE_TRANSITION: strcmp(v12, aSkid): set effect type this+4 = 6. [field:this:0x00000004, global:0x005D369C, source:raw]
    // STATE_TRANSITION: strcmp(v12, aSoftskid): set effect type this+4 = 7. [field:this:0x00000004, global:0x005D3690, source:raw]
    // STATE_TRANSITION: strcmp(v12, aWetskid): set effect type this+4 = 8. [field:this:0x00000004, global:0x005D3680, source:raw]
    // STATE_TRANSITION: strcmp(v12, aGroove): set effect type this+4 = 9. [field:this:0x00000004, global:0x005D3678, source:raw]
    // STATE_TRANSITION: strcmp(v12, aWetgroove): set effect type this+4 = 10. [field:this:0x00000004, global:0x005D366C, source:raw]
    // STATE_TRANSITION: strcmp(v12, aParticle): set effect type this+4 = 11. [field:this:0x00000004, global:0x005D3660, source:raw]
    // STATE_TRANSITION: strcmp(v12, aSpark): set effect type this+4 = 12. [field:this:0x00000004, global:0x005D3658, source:raw]
    // STATE_TRANSITION: strcmp(v12, aRain): set effect type this+4 = 13. [field:this:0x00000004, global:0x005D3650, source:raw]
    // GUARD: Fallback when no known reaction name matches: StringSplitLoop(1, aDDevF119992002_25, 615) decides whether to write the 'unrecognized reaction' warning via DebugLogWrite(&dword_8AD25C, aUnrecognizedRe). [callee:0x004D7A50, global:0x005D3624, callee:0x004D7AA0, global:0x008AD25C, global:0x005D3608, source:raw]
    // CALL: sub_565870(aScale, this+12, this+16, this+20, 0...): parse the 'scale' scalar/range into the first float triplet. [callee:0x00565870, global:0x005D3600, source:raw]
    // CALL: sub_565870(aGrowth, this+24, this+28, this+32, 0...): parse the 'growth' scalar/range. [callee:0x00565870, global:0x005D35F8, source:raw]
    // CALL: sub_565870(aGrowthvel, this+36, this+40, this+44, 0...): parse the 'growthvel' scalar/range. [callee:0x00565870, global:0x005D35EC, source:raw]
    // CALL: sub_565870(aDuration, this+48, 0...): parse the 'duration' scalar into this+48. [callee:0x00565870, global:0x005D35E0, field:this:0x00000030, source:raw]
    // CALL: sub_565870(aAsdenvelope, this+52, this+56, this+60, 0...): parse the 'asdenvelope' attack/sustain/decay triple. [callee:0x00565870, global:0x005D35D4, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // GUARD: When the asdenvelope token parsed: if effect type this+4 == 5 (spray) and PathDispatch(&unk_8AFE18) < 24, scale all three envelope components by 0.30000001; then this+48 = sum of the three components. [callee:0x00565870, callee:0x004F9230, global:0x008AFE18, guard:0, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000030, source:raw]
    // CALL: sub_565870(aPower, this+68, 0...): parse the 'power' scalar. [callee:0x00565870, global:0x005D35CC, source:raw]
    // CALL: sub_565870(aRampspeed, this+72, 0...): parse the 'rampspeed' scalar into this+72. [callee:0x00565870, global:0x005D35C0, field:this:0x00000048, source:raw]
    // CALCULATION: Clamp the parsed rampspeed this+72 into [1.0, 3.4028235e38] when present. [callee:0x00565870, field:this:0x00000048, source:raw]
    // CALL: sub_565870(aOffsetvel, this+76, 0...): parse the 'offsetvel' scalar. [callee:0x00565870, global:0x005D35B4, source:raw]
    // ASSIGNMENT: sub_565520(&off_5C67A8, v12, 0): if the waypoint token matches aNumwaypoints use dword_5EA3F0, else resolve through sub_587ECE(v12); store the result in this+88. [callee:0x00565520, global:0x005C67A8, global:0x005D35A4, global:0x005EA3F0, callee:0x00587ECE, field:this:0x00000058, source:raw]
    // GUARD: Free an existing renderer sub-object at this+80: EmptyStub_0170(), FreeWrapper_7bcf(v8), this+80 = 0. [callee:0x004B0170, callee:0x00587BCF, field:this:0x00000050, source:raw]
    // ASSIGNMENT: If this+80 is null, allocate a 176-byte sub-object with OperatorNewNhMallocWrapper(176), construct it via sub_557350 and store the pointer in this+80. [callee:0x00587C03, callee:0x00557350, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Set sub-object defaults: byte at +112/+56/+144 = 0; dword at +88 = 16432; +92 = 0; +96 = -2130706433; +32 = 529; +100 = 262146. [field:*(this+0x50):0x00000070, field:*(this+0x50):0x00000038, field:*(this+0x50):0x00000090, field:*(this+0x50):0x00000058, field:*(this+0x50):0x0000005C, field:*(this+0x50):0x00000060, field:*(this+0x50):0x00000020, field:*(this+0x50):0x00000064, field:*(this+0x50):0x00000066, source:raw]
    // ASSIGNMENT: Texture filename tokens: strcpy into +112/.BMP for off_5D35A0, +56/.MTS for aMts_0, +144/.BMP for aEmap; each appends the extension only when sub_587C20(&word_5BEB48) says no extension is present. [callee:0x00565520, callee:0x00587C20, global:0x005BEB48, global:0x005D35A0, global:0x005D359C, global:0x005D3594, field:*(this+0x50):0x00000070, field:*(this+0x50):0x00000038, field:*(this+0x50):0x00000090, source:raw]
    // ASSIGNMENT: Vertex shader flags: aVertex token resets +88 to 0 then ORs bit flags via sub_566810 - noshade=4, flatshade=8, gouraudshade=16, alphachannel=32, specular=64, envirmap=128, globalshadow=16384. [callee:0x00565520, callee:0x00566810, global:0x005D358C, global:0x005D3584, global:0x005D3578, global:0x005D3568, global:0x005D3558, global:0x005D354C, global:0x005D3540, global:0x005D3530, field:*(this+0x50):0x00000058, source:raw]
    // ASSIGNMENT: Pixel shader flags: aPixel token resets +92 to 0 then ORs noreducedetail=1 and chromakey=128 via sub_566810. [callee:0x00565520, callee:0x00566810, global:0x005D3528, global:0x005D3518, global:0x005D350C, field:*(this+0x50):0x0000005C, source:raw]
    // ASSIGNMENT: Color tokens: aChroma value goes to sub-object +104 and aColor value to +96, both parsed by HexStringParser(v12). [callee:0x00565520, callee:0x004CAD30, global:0x005D3504, global:0x005C57F4, field:*(this+0x50):0x00000068, field:*(this+0x50):0x00000060, source:raw]
    // ASSIGNMENT: Particle flags: aParticle token resets +32 to 0 then ORs plane=1, cross=2, mtsfile=8, stamps=16, billboards=32, deformable=128, singlesided=512, alphafade=2048 via sub_566810 (off_5D34F8 supplies the cross bit). [callee:0x00565520, callee:0x00566810, global:0x005D3660, global:0x005D34FC, global:0x005D34F8, global:0x005D34F0, global:0x005D34E8, global:0x005D34E0, global:0x005D34D4, global:0x005D34C8, global:0x005D34BC, global:0x005D34B0, field:*(this+0x50):0x00000020, source:raw]
    // ASSIGNMENT: Destblend: zero the +102 word then OR sub_4CADA0(v12) shifted by 16 into the +100 blend-mode dword. [callee:0x00565520, callee:0x004CADA0, global:0x005D34A4, field:*(this+0x50):0x00000064, field:*(this+0x50):0x00000066, source:raw]
    // ASSIGNMENT: Srcblend: zero the +100 word then OR sub_4CADA0(v12) into the +100 blend-mode dword; the function's return value is this token-lookup result. [callee:0x00565520, callee:0x004CADA0, global:0x005D3498, field:*(this+0x50):0x00000064, field:*(this+0x50):0x00000066, source:raw]
    // RETURN: Returns the presence/result of the final aSrcblend token lookup (0 when the token was absent). [callee:0x00565520, source:raw]

    // Conservative worker pseudocode:
    //   FloatStructInitializer(this);
    //   if (sub_565520(aReaction, v12, 0)) {
    //       if (!strcmp(v12, aDust)) this[1] = 0;
    //       else if (!strcmp(v12, aWhitesmoke)) this[1] = 1;
    //       ... // 14 effect-type mappings ...
    //       else if (StringSplitLoop(1, aDDevF119992002_25, 615)) DebugLogWrite(&dword_8AD25C, aUnrecognizedRe);
    //   }
    //   sub_565870(aScale, this+12, this+16, this+20, 0, 0, 0, 0, 0);
    //   // growth, growthvel, duration, asdenvelope, power, rampspeed, offsetvel likewise
    //   if (!this[20]) this[20] = sub_557350(OperatorNewNhMallocWrapper(176));
    //   // filename buffers, shader flag bitmasks, chroma/color, particle flags, blend modes
    // UNRESOLVED: Read-only globals flt_59E43C, flt_59E8B4, flt_59EAE0, dword_5CC79C, byte_5CC7A0, aMts (0x005CD5EC), byte_5CD5F0 are packet-flagged xrefs with no visible read in the raw body (likely adjacent-data block).
    // UNRESOLVED: The 176-byte sub-object layout is only partially covered by named fields; offsets such as chroma at +104 and blend words +100/+102 have no dedicated field evidence.
    // UNRESOLVED: The return-value contract (aSrcblend token presence) with caller SpecialFX_Init (0x004CF070) is not resolved.
}
