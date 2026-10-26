// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FF130
// Canonical corpus name: sub_4FF130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FF130_004ff130.c

void UnknownObject::ParameterCurveEvaluate()
{
    // Evaluates a time-based parameter curve stored as a linked list of keyframe nodes hanging off this+0x38, using the current session time (global 0x008AFEA0): when the head node is non-null it linearly interpolates between the head and next keyframe when the current time falls inside that interval, otherwise returns the head or next keyframe value directly, all through ThresholdBasedReturn (callee 0x004FEAA0); when no curve is set it falls back to integer status codes 2-5 selected from this+0x20 and this+0x24.
    // GUARD: Load the curve chain head pointer from this+0x38; when non-null take the keyframe-evaluation path, otherwise fall back to the status-code path driven by this+0x20 and this+0x24. [function:0x004FF130, field:this:0x00000038, source:raw]
    // ASSIGNMENT: Load the current session time from global dbl_8AFEA0 (0x008AFEA0) into the comparison variable. [global:0x008AFEA0, source:raw]
    // GUARD: Proceed along the curve only when the current time is greater than the head keyframe's time (field +0x0) AND the next keyframe node pointer (field +0xC) is non-null; otherwise fall through to returning the head's value. [field:*(this+0x38):0x00000000, field:*(this+0x38):0x0000000C, source:raw]
    // GUARD: When the current time is below the next keyframe's time, enter the linear-interpolation branch; when it is at or beyond it, take the direct next-keyframe-value branch. [field:*(this+0x38):0x00000000, source:raw]
    // CALCULATION: Compute the interpolation fraction v5 = (currentTime - headTime) / (nextTime - headTime), clamped to 0.0 when the time span is non-positive. [field:*(this+0x38):0x00000000, source:raw]
    // CALCULATION: Blend the head keyframe value (field +0x8) with the next keyframe's value using v5: v7 = (1.0 - v5) * headValue + v5 * nextValue. [field:*(this+0x38):0x00000008, source:raw]
    // CALL: Convert the interpolated float to its integer return code via ThresholdBasedReturn (callee 0x004FEAA0). [callee:0x004FEAA0, source:raw]
    // CALL: When the current time is at or beyond the next keyframe's time, return the next keyframe node's value (v2[2], +0x8 of the node reached through field +0xC) via ThresholdBasedReturn. [callee:0x004FEAA0, source:raw]
    // CALL: When no next keyframe exists or the current time does not exceed the head's start time, return the head keyframe's value (field +0x8) via ThresholdBasedReturn. [callee:0x004FEAA0, field:*(this+0x38):0x00000008, source:raw]
    // GUARD: Fallback path when no curve is set: if the fallback value at this+0x20 is 0.0, return status 2. [field:this:0x00000020, source:raw]
    // GUARD: Fallback path: if the threshold at this+0x24 is 0.0 return status 3; if it is >= 0.60000002 return status 5; otherwise return status 4. [field:this:0x00000024, source:raw]
    // RETURN: Return the status code (2, 3, 4 or 5) selected by the fallback guards on this+0x20 / this+0x24. [field:this:0x00000020, field:this:0x00000024, source:raw]

    // Conservative worker pseudocode:
    //   head = *(this+0x38);
    //   if (head) {
    //     t = dbl_8AFEA0;
    //     if (t > *(float*)head && (next = *(float**)(head+0xC)) != 0) {
    //       if (t < (double)*next) {
    //         span = *next - *(float*)head;
    //         f = (span <= 0.0) ? 0.0 : (t - *(float*)head) / span;
    //         v = (1.0 - f) * *(float*)(head+0x8) + f * next[2];
    //         return ThresholdBasedReturn(v);
    //       }
    //       return ThresholdBasedReturn(next[2]);
    //     }
    //     return ThresholdBasedReturn(*(float*)(head+0x8));
    //   }
    //   if (*(float*)(this+0x20) == 0.0) return 2;
    //   if (*(float*)(this+0x24) == 0.0) return 3;
    //   return (*(float*)(this+0x24) >= 0.60000002) ? 5 : 4;
    // UNRESOLVED: Globals 0x0059E43C and 0x0059E440 are listed as read by this function in the packet's global evidence but never appear in the raw Hex-Rays text; their role is unknown.
    // UNRESOLVED: The next keyframe node's value read as v2[2] (node reached via field +0xC, value at its +0x8) has no dedicated packet field evidence ref; the closest refs describe the head node's fields.
    // UNRESOLVED: Only one caller is known (PitRaceStatusMessageDispatcher 0x0041BE60); the owning object, call frequency and frame placement are unestablished.
    // UNRESOLVED: ThresholdBasedReturn's exact threshold-to-code mapping is not defined by this packet.
    // UNRESOLVED: The meaning of fallback status codes 2-5 is unknown.
}
