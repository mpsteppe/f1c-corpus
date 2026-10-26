// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469DD0
// Canonical corpus name: AnimationFrameTimer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationFrameTimer_00469dd0.c

void UnknownObject::AnimationFrameTimer()
{
    // Accumulates per-frame delta time read from a sub-object (this+0x40) and advances an animation frame counter when the accumulation exceeds the 2.0 threshold. On each advance the counter increments by 2, wraps to 0.0 at the dword_7D2DCC limit, the accumulator resets to 0.0, and a vtable callback at offset 0xA0 (160) is invoked to trigger the animation update. Returns 0.
    // CALL: Calls FloatFieldAccessor on the object referenced by this+0x40 (this[16]) to read the frame delta time. [callee:0x00498730, field:this:0x00000040]
    // CALCULATION: Adds the returned frame delta time to the accumulated animation time at this+0x174 (this[93]). [field:this:0x00000174, callee:0x00498730]
    // ASSIGNMENT: Stores the new accumulated time back into this+0x174 (this[93]). [field:this:0x00000174]
    // GUARD: Checks whether accumulated time at this+0x174 exceeds the 2.0 threshold; only then advances the animation frames. [field:this:0x00000174, function:0x00469DD0]
    // STATE_TRANSITION: Resets the accumulated time at this+0x174 to 0.0 when the 2.0 threshold is exceeded. [field:this:0x00000174]
    // CALCULATION: Computes the next frame value by adding 2 to the frame counter at this+0x178 (this[94]). [field:this:0x00000178]
    // ASSIGNMENT: Writes the computed value into the frame counter at this+0x178 (this[94]). [field:this:0x00000178]
    // GUARD: Checks whether the frame counter at this+0x178 has reached the wrap limit dword_7D2DCC. [global:0x007D2DCC, field:this:0x00000178]
    // STATE_TRANSITION: Wraps the frame counter at this+0x178 to 0.0 when the dword_7D2DCC limit is reached. [field:this:0x00000178, global:0x007D2DCC]
    // CALL: Invokes the vtable callback at offset 0xA0 (160) on the object to trigger the animation update. [field:obj:0x000000A0, field:this:0x00000000]
    // RETURN: Returns 0. [function:0x00469DD0, source:raw]

    // Conservative worker pseudocode:
    //   accumulated_time = FloatFieldAccessor(this->field_0x40) + this->field_0x174;
    //   this->field_0x174 = accumulated_time;
    //   if (accumulated_time > 2.0) {
    //       this->field_0x174 = 0.0;
    //       next_frame = this->field_0x178 + 2;
    //       this->field_0x178 = next_frame;
    //       if (next_frame >= dword_7D2DCC) this->field_0x178 = 0.0;
    //       vtable[0xA0](this);
    //   }
    //   return 0;
    // UNRESOLVED: global:0x0059E800 (flt_59E800) is listed as a referenced global but does not appear in the raw decompiled source; its role here is unclear.
    // UNRESOLVED: The threshold literal 2.0 and the +2 frame step are raw-source literals; no connection to flt_59E800 is evidenced.
}
