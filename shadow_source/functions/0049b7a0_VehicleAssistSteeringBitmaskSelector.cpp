// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B7A0
// Canonical corpus name: sub_49B7A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49B7A0_0049b7a0.c

void UnknownObject::VehicleAssistSteeringBitmaskSelector()
{
    // Returns a steering-assist strength bitmask (0, 1, 2, 4, 8, 15). If the current vehicle exceeds a velocity threshold, the mask is chosen from session-time parity (full mask 0xF on odd parity, 0 on even). Otherwise, when the current and teammate vehicles share the same team field and a teammate-race flag is set, a time-derived pseudo-random mask (1, 2, 4, 8) is selected via a jump-table dispatch; else a fixed performance ratio of two vehicle dynamics fields selects a mask through a nested threshold ladder.
    // CALL: VelocityThresholdCheck(dword_7C54E0 + 12, this): test whether the current vehicle exceeds a velocity threshold. [callee:0x004F1AA0, global:0x007C54E0, source:raw]
    // CALCULATION: Session-time parity: CRTFtol(dbl_8AFEA0 + dbl_8AFEA0) & 1 decides the full-assist mask 0xF when odd, 0 when even. [callee:0x00587BDC, global:0x008AFEA0, source:raw]
    // RETURN: On the velocity-threshold path, return 0xF (all assist bits) for odd time parity, otherwise 0. [source:raw]
    // GUARD: Teammate path: taken when the team field at vehicle[dword_7C54DC] + 18580 equals vehicle[dword_7C54E4] + 18580 AND the teammate-race flag dword_7C9158 is set. [global:0x007C54F0, global:0x007C54DC, global:0x007C54E4, global:0x007C9158, source:raw]
    // CALCULATION: Time-derived pseudo-random dispatch through jump table jpt_49B818: CRTFtol(dbl_8AFEA0 * 3.0) % 6 maps to result 1 (case 0), 2 (cases 1 and 5), 4 (cases 2 and 4), or 8 (case 3). [callee:0x00587BDC, global:0x008AFEA0, global:0x0049B8B0, source:raw]
    // RETURN: The jump-table default returns 0 (no assist) when the modulo result is outside the handled cases. [source:raw]
    // CALCULATION: Non-teammate path: compute the performance ratio v2 = (float)(dword_7C54E0 + 14752) / (float)(dword_7C54E0 + 14756). [global:0x007C54E0, source:raw]
    // RETURN: Ratio below 0.9 returns 0 (no assist). [source:raw]
    // RETURN: Ratio in [0.9, 0.93) returns 1. [source:raw]
    // RETURN: Ratio in [0.93, 0.96) returns 3. [source:raw]
    // RETURN: Ratio in [0.96, 0.977) returns 7. [source:raw]
    // RETURN: Ratio at or above 0.977 returns 15 (full mask). [source:raw]
    // CALL: Invoked by WheelRotationAnimation (0x0049D280), UILayoutDispatchWithDataPrep (0x004DB550) and PositionOrderNameDisplay (0x004DB6F0). [caller:0x0049D280, caller:0x004DB550, caller:0x004DB6F0, source:raw]

    // Conservative worker pseudocode:
    //   int VehicleAssistSteeringBitmaskSelector(void *this) {
    //     if (VelocityThresholdCheck(dword_7C54E0 + 12, this))
    //       return (CRTFtol(dbl_8AFEA0 + dbl_8AFEA0) & 1) != 0 ? 0xF : 0;
    //     if (*(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) && dword_7C9158) {
    //       switch (CRTFtol(dbl_8AFEA0 * 3.0) % 6) {
    //         case 0: result = 1; break;
    //         case 1: case 5: result = 2; break;
    //         case 2: case 4: result = 4; break;
    //         case 3: result = 8; break;
    //         default: return 0;
    //       }
    //     } else {
    //       v2 = *(float *)(dword_7C54E0 + 14752) / *(float *)(dword_7C54E0 + 14756);
    //       v3 = v2;
    //       if (v2 >= 0.9) {
    //         if (v3 >= 0.93) {
    //           if (v3 >= 0.96) { result = 7; if (v3 >= 0.977) return 15; }
    //           else return 3;
    //         } else return 1;
    //       } else return 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The float globals flt_59E478, flt_59E824, flt_5ACAE8, flt_5ACAEC and flt_5ACAF0 are flagged by packet facts but appear nowhere in the raw decompiled source; their roles (possibly assist or aggression thresholds) are unverifiable here.
    // UNRESOLVED: The field at vehicle + 18580 is interpreted as a team identifier and dword_7C9158 as a teammate-race flag from call-site context; neither is established within this function.
    // UNRESOLVED: The ratio fields at dword_7C54E0 + 14752 and + 14756 and the ladder thresholds (0.9, 0.93, 0.96, 0.977) are used as a performance ratio, but their exact meaning and units are inferred.
    // UNRESOLVED: The this argument is unused beyond being forwarded to VelocityThresholdCheck; its role is unknown.
}
