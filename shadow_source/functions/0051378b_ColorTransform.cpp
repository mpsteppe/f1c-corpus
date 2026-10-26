// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051378B
// Canonical corpus name: TextureImageColorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureImageColorTransform_0051378b.c

void UnknownObject::ColorTransform()
{
    // Two-pass texture/audio data transformation on a shared buffer. Pass 1, gated by the address value of global unk_602000 (0x602000) being a set bitmask in the flags dword at this+0x60, regenerates engine sound wave tables via EngineSoundWaveTableGenerator and then, when the format byte at this+0x116 equals 3, remaps each pixel's three RGB bytes at the buffer (this+0x104) through a lookup table (this+0x138). Pass 2, gated by flags bit 3 (0x8) at this+0x60 and the same format value 3, computes per-channel shift amounts as 8 minus the amplitude bytes at this+0x150/0x151/0x152, clamps oversize shifts to 0, and right-shifts each pixel's R/G/B channels by those amounts. Both passes iterate the pixel count WORD at this+0x108.
    // GUARD: Read the format indicator byte at this+0x116; a value of 3 is required by both pixel loops. [field:this:0x00000116, source:raw]
    // GUARD: Pass 1 gate: the address value of unk_602000 (0x602000) is used as a bitmask; when it has any bits set against the flags dword at this+0x60 the pass runs. [global:0x00602000, field:this:0x00000060, source:raw]
    // CALL: Regenerate the engine sound wave tables via EngineSoundWaveTableGenerator, which also supplies the lookup table pointer consumed by the remap pass. [callee:0x00513482, source:raw]
    // GUARD: Pass 1 remap runs only when the format byte at this+0x116 equals 3. [field:this:0x00000116, source:raw]
    // LOOP: Iterate the pixel count WORD at this+0x108; for each pixel remap three consecutive bytes at the buffer pointed to by this+0x104 through the lookup table at this+0x138. [field:this:0x00000108, field:this:0x00000104, field:this:0x00000138, source:raw]
    // ASSIGNMENT: Rewrite the third channel (B) byte of the first pixel at *(this+0x104)+2 with the lookup-table result. [field:*(this+0x104):0x00000002, source:raw]
    // GUARD: Pass 2 gate: the flags byte at this+0x60 has bit 3 (0x8) set and the format byte at this+0x116 equals 3. [field:this:0x00000060, field:this:0x00000116, source:raw]
    // CALCULATION: Compute per-channel right-shift amounts as 8 minus the amplitude bytes at this+0x150 (red), this+0x151 (green) and this+0x152 (blue). [field:this:0x00000150, field:this:0x00000151, field:this:0x00000152, source:raw]
    // GUARD: Clamp each computed shift amount to 0 when the 8-minus-amplitude value exceeds 8. [source:raw]
    // LOOP: Iterate the pixel count WORD at this+0x108; right-shift each pixel's R/G/B channels at the buffer pointed to by this+0x104 by the respective clamped shift amounts. [field:this:0x00000108, field:this:0x00000104, source:raw]
    // CALCULATION: Legacy ABI label Texture_Image_Color_Transform corroborates the texture color-transformation role. [abi:lead, source:raw]
    // CALL: Invoked by AudioBufferSizeCalc (0x0051868C) to transform audio/texture buffer data. [caller:0x0051868C, source:raw]

    // Conservative worker pseudocode:
    //   void ColorTransform(int a1) {
    //     int format = *(unsigned __int8*)(a1 + 0x116);
    //     if (0x602000 & *(int*)(a1 + 0x60)) {
    //       EngineSoundWaveTableGenerator(a1);
    //       if (format == 3) {
    //         int n = *(unsigned __int16*)(a1 + 0x108);
    //         if (n) {
    //           unsigned __int8* p = *(unsigned __int8**)(a1 + 0x104) + 2;
    //           do {
    //             p[-2] = lookup[ p[-2] ];
    //             p[-1] = lookup[ p[-1] ];
    //             p[0]  = lookup[ p[0] ];
    //             p += 3;
    //           } while (--n);
    //         }
    //       }
    //     }
    //     if ((*(unsigned __int8*)(a1 + 0x60) & 8) && format == 3) {
    //       int shR = 8 - *(unsigned __int8*)(a1 + 0x150); if (shR > 8) shR = 0;
    //       int shG = 8 - *(unsigned __int8*)(a1 + 0x151); if (shG > 8) shG = 0;
    //       int shB = 8 - *(unsigned __int8*)(a1 + 0x152); if (shB > 8) shB = 0;
    //       int n = *(unsigned __int16*)(a1 + 0x108);
    //       for (int i = 0; i < n; i++) {
    //         *(unsigned __int8*)(i + *(int*)(a1 + 0x104) + 0) >>= shR;
    //         *(unsigned __int8*)(i + *(int*)(a1 + 0x104) + 1) >>= shG;
    //         *(unsigned __int8*)(i + *(int*)(a1 + 0x104) + 2) >>= shB;
    //       }
    //     }
    //   }
    // UNRESOLVED: The lookup table at this+0x138 is produced by EngineSoundWaveTableGenerator, but the exact table layout and index domain are not visible in this function.
    // UNRESOLVED: The meaning of the address of unk_602000 used as a bitmask (pass-1 gate) is a deterministically observed pattern; its semantic flag name is unknown.
    // UNRESOLVED: Whether the buffer at this+0x104 holds texture pixels, audio samples, or shared data depends on the caller AudioBufferSizeCalc context, not resolvable here.
}
