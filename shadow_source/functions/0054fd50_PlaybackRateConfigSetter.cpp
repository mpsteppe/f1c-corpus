// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FD50
// Canonical corpus name: PlaybackRateConfigSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaybackRateConfigSetter_0054fd50.c

void UnknownObject::PlaybackRateConfigSetter()
{
    // Mode-and-rate configuration setter for the object. Encodes a two-bit mode field at this+0x40 (mask 0xFFFFFFF3 preserves the other bits): a2==8 sets mode bits to 8, a2==4 sets them to 4, otherwise the mode bits are cleared. The rate field this+0x44 receives a3 for modes 8/4 (with -1 sentinel when a3 < 1 in mode 8) or 1 in the default branch. Returns the selected rate in the mode branches and a2 in the default branch.
    // ASSIGNMENT: Initialize the result to a2 [source:raw]
    // GUARD: a2 == 8 selects the mode-8 branch; the mode field this+0x40 is set to (this+0x40 & 0xFFFFFFF3) | 8 and the result becomes a3 [field:this:0x00000040, source:raw]
    // GUARD: Inside mode 8, a3 < 1 writes the -1 sentinel to the rate field this+0x44 and returns the result immediately [field:this:0x00000044, source:raw]
    // GUARD: a2 == 4 selects the mode-4 branch; the mode field this+0x40 is set to (this+0x40 & 0xFFFFFFF3) | 4 and the result becomes a3 [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Write the rate field this+0x44 = result (a3) for both the mode-8 (a3 >= 1) and mode-4 paths [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Default branch (a2 neither 8 nor 4): clear the mode bits, this+0x40 &= 0xFFFFFFF3 [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Default branch: write the rate field this+0x44 = 1 (matches the field init literal) [field:this:0x00000044, source:raw]
    // RETURN: Return the result: a3 in the mode branches, a2 in the default branch [source:raw]
    // CALL: Invoked by DirectXMeshVertexBufferParsingAndLoading (00547b40) and D3DTextureResourceCreation (00548190) [caller:0x00547B40, caller:0x00548190, source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   if (a2 == 8) {
    //     this[0x40/4] = (this[0x40/4] & 0xFFFFFFF3) | 8;
    //     result = a3;
    //     if (a3 < 1) {
    //       this[0x44/4] = -1;
    //       return result;
    //     }
    //     goto writeRate;
    //   }
    //   if (a2 == 4) {
    //     result = a3;
    //     this[0x40/4] = (this[0x40/4] & 0xFFFFFFF3) | 4;
    //   writeRate:
    //     this[0x44/4] = result;
    //     return result;
    //   }
    //   this[0x40/4] &= 0xFFFFFFF3;
    //   this[0x44/4] = 1;
    //   return result;
    // UNRESOLVED: The meaning of the two-bit mode field at this+0x40 (0/4/8) and of the rate field this+0x44 is DERIVED from the skeleton fill (playback rate/mode selector) and not verifiable from this packet
    // UNRESOLVED: The exact semantics of the -1 sentinel and the default rate of 1 are not documented in this function
}
