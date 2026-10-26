// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B86E0
// Canonical corpus name: AngleClampWrap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AngleClampWrap_004b86e0.c

void UnknownObject::AngleClampWrap()
{
    // __thiscall helper that updates an angle (float at this+0xF38) while preserving the previous value (this+0xF3C), constraining the new value to the range [this+0xF30, this+0xF34]. When the mode byte at this+0xF81 is zero the value is wrapped: it is repeatedly shifted by the range span (upper - lower) until it lands inside the range. When the mode byte is non-zero the value is hard-clamped to the nearer bound. Likely part of the steering/angle animation path; callers include loading and pit-service steering animation code.
    // ASSIGNMENT: Save the current angle into the previous-angle slot: *(DWORD*)(this+0xF3C) = *(DWORD*)(this+0xF38). [field:this:0x00000F38, field:this:0x00000F3C, source:raw]
    // ASSIGNMENT: Store the incoming angle a2 into the current-angle float at this+0xF38. [field:this:0x00000F38, source:raw]
    // GUARD: Branch on the mode flag byte at this+0xF81: zero selects wrap mode (loop below), non-zero selects hard clamp mode (final block). [field:this:0x00000F81, source:raw]
    // LOOP: Wrap mode: infinite loop that shifts v2 by the range span (this+0xF34 - this+0xF30) until v2 lies inside [this+0xF30, this+0xF34]. [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // GUARD: In-range test at the top of the wrap loop: if v2 <= upper (this+0xF34) and v2 >= lower (this+0xF30), the value is already in range and the function returns. [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // CALCULATION: Wrap upward: when v2 < lower (this+0xF30), compute v2 = v2 + (this+0xF34 - this+0xF30). [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // CALCULATION: Wrap downward: when v2 > upper (this+0xF34), compute v2 = v2 - (this+0xF34 - this+0xF30). [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // ASSIGNMENT: After each wrap shift, rotate the pair: previous = old current, current = wrapped v2 (performed as DWORD copies). [field:this:0x00000F38, field:this:0x00000F3C, source:raw]
    // RETURN: Exit the wrap loop once the shifted v2 lands inside [lower, upper]; the function then returns with the wrapped value stored. [function:0x004B86E0]
    // ASSIGNMENT: Clamp mode, upper bound: when v2 > upper (this+0xF34), set the current angle at this+0xF38 to the upper bound. [field:this:0x00000F34, field:this:0x00000F38, source:raw]
    // ASSIGNMENT: Clamp mode, lower bound: when v2 < lower (this+0xF30), set the current angle at this+0xF38 to the lower bound. [field:this:0x00000F30, field:this:0x00000F38, source:raw]
    // CALL: Called by GameDataFileIO (0x004B7300), LoadingPhase1 (0x004B87C0), LoadingPhase2 (0x004B8940), sub_4B8C40 (0x004B8C40), PitServiceSteeringAnimationStep (0x004B9E40) and sub_4BA1F0 (0x004BA1F0) to constrain an angle to its configured range. [caller:0x004B7300, caller:0x004B87C0, caller:0x004B8940, caller:0x004B8C40, caller:0x004B9E40, caller:0x004BA1F0, source:raw]

    // Conservative worker pseudocode:
    //   void AngleClampWrap(int this, float a2) {
    //     double v2 = a2;
    //     *(float*)(this + 0xF3C) = *(float*)(this + 0xF38);
    //     *(float*)(this + 0xF38) = a2;
    //     if (*(BYTE*)(this + 0xF81) == 0) {
    //       for (;;) {
    //         float lower = *(float*)(this + 0xF30);
    //         float upper = *(float*)(this + 0xF34);
    //         if (v2 <= upper) {
    //           if (v2 >= lower) return;
    //           v2 += upper - lower;
    //         } else {
    //           v2 -= upper - lower;
    //         }
    //         *(float*)(this + 0xF3C) = *(float*)(this + 0xF38);
    //         *(float*)(this + 0xF38) = v2;
    //       }
    //     }
    //     if (v2 <= *(float*)(this + 0xF34)) {
    //       if (v2 < *(float*)(this + 0xF30))
    //         *(float*)(this + 0xF38) = *(float*)(this + 0xF30);
    //     } else {
    //       *(float*)(this + 0xF38) = *(float*)(this + 0xF34);
    //     }
    //   }
    // UNRESOLVED: Owning class of `this` is not identified; owner is left as UnknownObject.
    // UNRESOLVED: Mode flag semantics at this+0xF81 (zero = wrap, non-zero = hard clamp) are derived from the control flow, not independently confirmed.
    // UNRESOLVED: Range bound roles (this+0xF30 = lower, this+0xF34 = upper) are inferred from the comparison structure of the raw source.
    // UNRESOLVED: Whether the value at this+0xF38 is specifically an angle (e.g. radians) or a generic scalar is unconfirmed; existing analysis ties the field pair to steering/angle animation.
}
