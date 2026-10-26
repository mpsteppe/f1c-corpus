// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005438B0
// Canonical corpus name: AudioPanUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioPanUpdate_005438b0.c

void UnknownObject::AudioPanUpdate()
{
    // Updates left/right audio pan values on the audio object and marks it dirty. Left pan (this+0x194) is written from a2 only when a2 is non-negative (compared against the zero constant dbl_59E430). Right pan (this+0x198) becomes the left pan when a3 < left pan, otherwise a3. In both paths bit 0x10000 is OR'd into the flags field (this+0xEC) to signal an update.
    // GUARD: Guard against negative pan: only when a2 >= 0.0 (zero constant global dbl_59E430) is a2 stored as the left pan float at this+0x194. [field:this:0x00000194, global:0x0059E430, source:raw]
    // GUARD: When right pan input a3 is less than the current left pan (this+0x194), copy the left pan value into the right pan field (this+0x198) and OR bit 0x10000 into the flags field (this+0xEC). [field:this:0x00000194, field:this:0x00000198, field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Otherwise store a3 directly as the right pan float (this+0x198) and OR bit 0x10000 into the flags field (this+0xEC). [field:this:0x00000198, field:this:0x000000EC, source:raw]
    // RETURN: Return the updated flags word of this+0xEC. [field:this:0x000000EC, source:raw]

    // Conservative worker pseudocode:
    //   void AudioPanUpdate(float* this, float a2, float a3) {
    //     if (a2 >= 0.0) this[0x194/4] = a2;
    //     if (a3 < this[0x194/4]) {
    //       this[0x198/4] = this[0x194/4];
    //       *(int*)(this + 0xEC) |= 0x10000;
    //       return *(int*)(this + 0xEC) | 0x10000;
    //     }
    //     this[0x198/4] = a3;
    //     int flags = *(int*)(this + 0xEC) | 0x10000;
    //     *(int*)(this + 0xEC) = flags;
    //     return flags;
    //   }
    // UNRESOLVED: The meaning of flag bit 0x10000 in this+0xEC (UI update / dirty marker) is inferred from the existing analysis, not proven here.
    // UNRESOLVED: The dbl_59E430 zero constant is read as the boundary for the non-negative left-pan guard.
    // UNRESOLVED: The audio object's class and the role of sub_4FCEE0 (the only caller) are unknown.
}
