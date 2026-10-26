// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D280
// Canonical corpus name: WheelRotationAnimation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelRotationAnimation_0049d280.c

void UnknownObject::WheelRotationAnimation()
{
    // Triggers up to four wheel-rotation audio effects for a driver. Requires all four audio-source handles at this+0x20..0x2C to be non-null and one of the two activity flags at dword_7C54E0+3984 / +3964 to be non-zero; then reads a driver appearance bitmask via sub_49B7A0(&unk_7CE234) and calls AudioEffectTrigger once per wheel (bits 0..3 of the bitmask) with the corresponding handle. Called by SteeringWheelAnimation.
    // GUARD: Early return unless this[8] (audio source handle at +0x20) is non-null. [field:this:0x00000020, source:raw]
    // GUARD: Early return unless this[9] (audio source handle at +0x24) is non-null. [field:this:0x00000024, source:raw]
    // GUARD: Early return unless this[10] (audio source handle at +0x28) is non-null. [field:this:0x00000028, source:raw]
    // GUARD: Early return unless this[11] (audio source handle at +0x2C) is non-null. [field:this:0x0000002C, source:raw]
    // GUARD: Block audio unless one of the two activity flags at dword_7C54E0+3984 or dword_7C54E0+3964 is non-zero (wheels spinning/moving). [global:0x007C54E0, source:raw]
    // CALL: Read the driver appearance bitmask: bitmask = sub_49B7A0(&unk_7CE234). [callee:0x0049B7A0, global:0x007CE234, source:raw]
    // CALL: Wheel 0: AudioEffectTrigger(bitmask & 1, this[8]). [callee:0x0049E4E0, field:this:0x00000020, source:raw]
    // CALL: Wheel 1: AudioEffectTrigger((bitmask >> 1) & 1, this[9]). [callee:0x0049E4E0, field:this:0x00000024, source:raw]
    // CALL: Wheel 2: AudioEffectTrigger((bitmask >> 2) & 1, this[10]). [callee:0x0049E4E0, field:this:0x00000028, source:raw]
    // CALL: Wheel 3: return AudioEffectTrigger((bitmask >> 3) & 1, this[11]); its result is the function return value. [callee:0x0049E4E0, field:this:0x0000002C, source:raw]
    // RETURN: Any early-exit path returns the last propagated result (a null handle, or dword_7C54E0 when the activity-flag guard fails). [function:0x0049D280, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49D280(int this) {
    //     int result = this[8];
    //     if (result) {
    //       result = this[9];
    //       if (result) {
    //         result = this[10];
    //         if (result) {
    //           result = this[11];
    //           if (result) {
    //             if (*(int*)(dword_7C54E0 + 3984) || *(int*)(dword_7C54E0 + 3964)) {
    //               unsigned int bitmask = sub_49B7A0(&unk_7CE234);
    //               AudioEffectTrigger(bitmask & 1, this[8]);
    //               AudioEffectTrigger((bitmask >> 1) & 1, this[9]);
    //               AudioEffectTrigger((bitmask >> 2) & 1, this[10]);
    //               return AudioEffectTrigger((bitmask >> 3) & 1, this[11]);
    //             }
    //           }
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The two activity flags at dword_7C54E0+3984 and +3964 are unnamed; their identification as wheelSpin/wheelMoving is existing-analysis DERIVED, not independently verified.
    // UNRESOLVED: The exact meaning of the bitmask returned by sub_49B7A0(&unk_7CE234) and the one-bit-per-wheel mapping are unverified.
    // UNRESOLVED: The owner class is unknown; the handles at this+0x20..0x2C are audio-source handles per existing analysis (DERIVED).
}
