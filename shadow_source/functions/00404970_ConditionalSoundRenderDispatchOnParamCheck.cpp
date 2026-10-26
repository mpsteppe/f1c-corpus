// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404970
// Canonical corpus name: ConditionalSoundRenderDispatchOnParamCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalSoundRenderDispatchOnParamCheck_00404970.c

void UnknownObject::ConditionalSoundRenderDispatchOnParamCheck()
{
    // Conditionally triggers sound/render setup steps. When the parameter field this+0x20 equals 1, runs a short-arithmetic step, sets an index to 1, computes a reciprocal with sign check for a 3.0 value, and when the render fade alpha flt_7CF380 is positive, initializes the audio mixer device from byte_8AC494 and configures a 3.0 audio parameter on it.
    // GUARD: Enter the dispatch only when the parameter field this+0x20 equals 1. [guard:0, field:this:0x00000020, source:raw]
    // CALL: ShortComputation_d360(1, 15) performs the first short-arithmetic setup step. [callee:0x0040D360, source:raw]
    // CALL: ConditionalIndexSetter(1) conditionally sets an index/parameter to 1. [callee:0x004D8840, source:raw]
    // CALL: ReciprocalWithSignCheck(3.0) computes a reciprocal of 3.0 with sign validation. [callee:0x00408420, source:raw]
    // GUARD: The audio mixer path is entered only while the render fade alpha flt_7CF380 is positive. [global:0x007CF380, source:raw]
    // CALL: AudioMixerDeviceInit(&byte_8AC494) initializes the audio mixer device from the scene-name buffer byte_8AC494. [callee:0x004C85D0, global:0x008AC494, source:raw]
    // CALL: sub_4C8830(3.0) configures the 3.0 audio parameter on the mixer. [callee:0x004C8830, source:raw]
    // CALL: Called by sub_404B60 as part of the parameter-driven sound/render dispatch. [caller:0x00404B60, source:raw]

    // Conservative worker pseudocode:
    //   void ConditionalSoundRenderDispatchOnParamCheck() {
    //     if (this[8] == 1) {
    //       ShortComputation_d360(1, 15);
    //       ConditionalIndexSetter(1);
    //       ReciprocalWithSignCheck(3.0);
    //       if (flt_7CF380 > 0.0) {
    //         AudioMixerDeviceInit(&byte_8AC494);
    //         sub_4C8830(3.0);
    //       }
    //     }
    //   }
    // UNRESOLVED: flt_59E440, flt_5EA4E8, dword_5EA510 and dword_8AD298 appear in the packet globals but are absent from the raw decompiled text; their role is unresolved.
    // UNRESOLVED: The meaning of the numeric arguments to ShortComputation_d360 and ConditionalIndexSetter (1, 15) is not established here.
    // UNRESOLVED: The owning class behind this+0x20 is unknown.
}
