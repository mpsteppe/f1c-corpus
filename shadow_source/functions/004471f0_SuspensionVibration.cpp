// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004471F0
// Canonical corpus name: SuspensionVibration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionVibration_004471f0.c

void UnknownObject::SuspensionVibration()
{
    // Updates suspension-vibration state each tick. Always sets the active flag this+0x1C59 to 1 and evaluates whether the accumulator this+0x1C5C is below the threshold this+0x1C84. In the trigger mode (a2 nonzero) and when below threshold, copies the source value this+0x1C84 into the accumulator this+0x1C5C and this+0x1C88 into the rate this+0x1C60. In the non-trigger mode and when below threshold, computes a noise-based vibration value from the table flt_8AB274 indexed by the byte counter dword_8AAE70 (incremented), writing this+0x1D10 = noise * this+0x1D20 + this+0x1D28 + this+0x1D18.
    // GUARD: Evaluate v2 = (this+0x1C5C < this+0x1C84), the accumulator-vs-threshold compare that gates both vibration modes. [source:raw, field:this:0x00001C5C, field:this:0x00001C84]
    // ASSIGNMENT: Set the active flag this+0x1C59 to 1 unconditionally. [source:raw, field:this:0x00001C59]
    // GUARD: Branch on the trigger argument a2: nonzero selects the source-copy mode, zero selects the noise mode. [source:raw]
    // STATE_TRANSITION: In trigger mode with v2 set, copy the vibration source into the running state: this+0x1C5C = this+0x1C84 and this+0x1C60 = this+0x1C88. [source:raw, field:this:0x00001C5C, field:this:0x00001C84, field:this:0x00001C60, field:this:0x00001C88]
    // GUARD: In non-trigger mode, proceed to the noise path only when v2 (below threshold) is set. [source:raw]
    // CALCULATION: Read the noise sample v4 = flt_8AB274[(byte)dword_8AAE70] and increment the byte counter dword_8AAE70. [source:raw, global:0x008AB274, global:0x008AAE70]
    // ASSIGNMENT: Accumulate the vibration output this+0x1D10 = v4 * this+0x1D20 + this+0x1D28 + this+0x1D18. [source:raw, field:this:0x00001D10, field:this:0x00001D20, field:this:0x00001D28, field:this:0x00001D18]
    // RETURN: Return void; no explicit return value is produced. [source:raw, function:0x004471F0]

    // Conservative worker pseudocode:
    //   void SuspensionVibration(void *this, char trigger) {
    //     bool below = this->acc(0x1C5C) < this->threshold(0x1C84);
    //     this->active(0x1C59) = 1;
    //     if (trigger) {
    //       if (below) {
    //         this->acc(0x1C5C) = this->threshold(0x1C84);
    //         this->rate(0x1C60) = this->source(0x1C88);
    //       }
    //     } else if (below) {
    //       double noise = flt_8AB274[(unsigned char)dword_8AAE70++];
    //       this->out(0x1D10) = noise * this->scale(0x1D20) + this->add(0x1D28) + this->offset(0x1D18);
    //     }
    //   }
    // UNRESOLVED: Which caller sets the trigger argument a2 and what the source-copy mode (this+0x1C84/0x1C88 into this+0x1C5C/0x1C60) models is not evidenced within this function.
    // UNRESOLVED: dword_8AAE70 is treated as the ring counter for the noise table here; whether other writers exist is not established from this function alone.
}
