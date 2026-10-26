// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FF1D0
// Canonical corpus name: AudioFilterParameterCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioFilterParameterCalculation_004ff1d0.c

void UnknownObject::AudioFilterParameterCalculation()
{
    // Computes an audio filter parameter by walking a keyframe linked list (head at this+0x38) up to a target time of session time (dbl_8AFEA0) plus 5400.0 for session type 7 or 3000.0 otherwise, tracking min/max of node values at +8 until a node time at +0 exceeds the target. Returns ThresholdBasedReturn of the average (min+max)*0.5 offset by this+0x104, clamped to [0,1] (0.0 when the average is negative). When no curve is set (this+0x38 is null), falls back to status codes based on this+0x20 / this+0x24: 2 when this+0x20 is 0.0, 3 when this+0x24 is 0.0, 5 when this+0x24 is >= 0.6, else 4.
    // GUARD: Read the keyframe list head at this + 0x38; when non-null take the curve path, otherwise fall through to the status-code fallback. [field:this:0x00000038, source:raw]
    // CALCULATION: Target time v8 = dbl_8AFEA0 + (dword_7C56A4 == 7 ? 5400.0 : 3000.0); the session-type global selects the horizon. [global:0x008AFEA0, global:0x007C56A4, source:raw]
    // CALCULATION: Initialize min (v3) and max (v6) from the head node value at +8. [field:*(this+0x38):0x00000008, source:raw]
    // LOOP: Traverse the keyframe chain via the next pointer at +12: update v6 = max(v6, node value) and v3 = min(v3, node value), break when the node time at +0 exceeds the target time v8. [field:*(*(this+0x38)+0xC):0x0000000C, field:*(this+0x38):0x00000000, field:*(this+0x38):0x00000008, source:raw]
    // CALCULATION: v4 = (v3 + v6) * 0.5 + *(this + 0x104): average of min/max offset by the this field. [field:this:0x00000104, source:raw]
    // GUARD: Clamp v7 to the [0,1] range (force 0 when v4 is negative, 1.0 when it exceeds 1.0). [source:raw]
    // CALL: Return ThresholdBasedReturn(v7) on the positive path, or ThresholdBasedReturn(0.0) when the average is negative. [callee:0x004FEAA0, source:raw]
    // GUARD: Null-curve fallback chain on this fields: return 2 when *(this + 0x20) == 0.0; return 3 when *(this + 0x24) == 0.0; else result = 4, upgraded to 5 when *(this + 0x24) >= 0.6. [field:this:0x00000020, field:this:0x00000024, source:raw]
    // RETURN: Return the status code (2, 3, 4 or 5) selected by the fallback chain when no keyframe curve is configured. [source:raw]

    // Conservative worker pseudocode:
    //   head = *(this + 0x38);
    //   if (head) {
    //       target = dbl_8AFEA0 + (dword_7C56A4 == 7 ? 5400.0 : 3000.0);
    //       mn = mx = *(head + 8);
    //       do {
    //           mx = max(mx, *(node + 8));
    //           mn = min(mn, *(node + 8));
    //           if (*(float*)node > target) break;
    //           node = *(node + 12);
    //       } while (node);
    //       avg = (mn + mx) * 0.5 + *(this + 0x104);
    //       if (avg >= 0.0)
    //           return ThresholdBasedReturn(min(avg, 1.0));
    //       return ThresholdBasedReturn(0.0);
    //   }
    //   if (*(this + 0x20) == 0.0) return 2;
    //   if (*(this + 0x24) == 0.0) return 3;
    //   result = 4;
    //   if (*(this + 0x24) >= 0.6) return 5;
    //   return result;
    // UNRESOLVED: The packet lists globals 0x0059E43C, 0x0059E440, 0x0059E450, 0x005AD338 and 0x005AD33C as read by this function, but none appears literally in the rendered raw source; they likely back the float literals (0.0, 0.6, 5400.0/3000.0 related constants) but the mapping is not established.
    // UNRESOLVED: The keyframe node layout (time at +0, value at +8, next at +12) and the meaning of this + 0x104 are interpretations of the fill, not independently evidenced.
    // UNRESOLVED: The fallback status-code semantics (2/3/4/5) are not named in the packet; the caller PitRaceStatusMessageDispatcher may interpret them, but that mapping is not in this packet.
    // UNRESOLVED: The legacy ABI label Audio_Filter_Parameter_Calculation (abi:lead) matches the canonical name and is not adopted as a separate owner claim.
}
