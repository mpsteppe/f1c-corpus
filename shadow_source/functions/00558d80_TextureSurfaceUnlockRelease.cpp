// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558D80
// Canonical corpus name: TextureSurfaceUnlockRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureSurfaceUnlockRelease_00558d80.c

void UnknownObject::TextureSurfaceUnlockRelease()
{
    // Release a texture surface by index a2. Reads the flags dword at this+0x20; when bit 0x100 is set, clears that bit, releases the audio resource for the surface descriptor at this+0x50 (stride 0x40 bytes) via ArithmeticComparison_0f90 with the sound-manager global dword_8B78A0, and zeroes the +0x20 offset within the descriptor. Otherwise does nothing.
    // CALCULATION: Reads the flags dword v3 from this+0x20 [field:this:0x00000020, source:raw]
    // GUARD: Release path runs only while bit 0x100 (bit 8) is set in the flags dword at this+0x20 [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Clears bit 0x100: writes v3 & 0xFFFFFEFF back into this+0x20 [field:this:0x00000020, source:raw]
    // CALCULATION: Selects the surface descriptor: this+0x50 (pointer to 0x40-byte-stride descriptors) + (a2 << 6) + 0x1C [field:this:0x00000050, source:raw]
    // CALL: Releases the descriptor's audio resource: ArithmeticComparison_0f90(dword_8B78A0, *(descriptor + 0x1C)) [callee:0x00540F90, global:0x008B78A0, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Zeroes the +0x20 field of the selected surface descriptor [field:this:0x00000050, source:raw]
    // CALL: Invoked by sub_558E70 (00558E70) [caller:0x00558E70, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this->flags;
    //   if (v3 & 0x100) {
    //       this->flags = v3 & ~0x100;
    //       ArithmeticComparison_0f90(dword_8B78A0, *(dword*)(this->descriptors + (a2 << 6) + 0x1C));
    //       *(dword*)(this->descriptors + (a2 << 6) + 0x20) = 0;
    //   }
    // UNRESOLVED: ArithmeticComparison_0f90's precise behavior (release vs other audio-resource handling) is not established from this packet alone
    // UNRESOLVED: The 0x40-byte descriptor stride and the meaning of the +0x1C/+0x20 descriptor fields are inferred only from raw-source arithmetic
    // UNRESOLVED: dword_8B78A0 as sound-manager global is carried from prior analysis as DERIVED, not confirmed by this packet
}
