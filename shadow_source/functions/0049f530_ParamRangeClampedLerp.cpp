// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F530
// Canonical corpus name: ParamRangeClampedLerp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParamRangeClampedLerp_0049f530.c

void UnknownObject::ParamRangeClampedLerp()
{
    // Parameter dispatch that reads a live parameter by mode index (0..4): 0 = speed multiplier, 1/2 = two temperature sources (Kelvin minus 273.16), 3 = a raw parameter, 4 = tire friction curve evaluation. Each mode selects a [v8, v9] clamp range. For temperature modes a Celsius-to-Fahrenheit-style linear transform (v5*1.8 - 40) is applied; for modes 3/4 the value is scaled by 0.14503774. The value is clamped into [v8, v9], the range width (v9 - v8) is stored at a2+32, and the normalized offset (v5 - v8) is passed through FieldSetterTrigger, GuardedCall, and sub_49ED20 on a2 with a3.
    // GUARD: Guard on mode index a1 <= 4 and a3 non-zero; otherwise return the (uninitialized) result. [source:raw]
    // GUARD: Outer switch on mode a1 selecting the parameter source and clamp range per case 0..4. [source:raw]
    // CALL: Mode 0: obtain live value from SpeedMultiplier(); range v8=0.0, v9=10000.0. [source:raw, callee:0x0049B8D0]
    // CALCULATION: Mode 1: compute dbl_7C91B4 - 273.16 as the live value; range v8=120.0, v9=280.0. [source:raw, global:0x007C91B4]
    // CALCULATION: Mode 2: compute dbl_7C9174 - 273.16 as the live value; range v8=120.0, v9=280.0. [source:raw, global:0x007C9174]
    // ASSIGNMENT: Mode 3: take dbl_7C919C as the live value; range v8=-3.0, v9=100.0. [source:raw, global:0x007C919C]
    // CALL: Mode 4: evaluate TireFrictionCurveEval on the global curve data at dbl_7C7428; range v8=0.0, v9=12.0. [source:raw, callee:0x00447BB0, global:0x007C7428]
    // CALCULATION: Inner switch unit conversion: modes 1/2 apply (v5 - -40.0) * 1.8 - 40.0; modes 3/4 multiply v5 by 0.14503774. [source:raw]
    // CALCULATION: Clamp v5 into [v8, v9]: if v5 < v8 then v5 = v8; else if v5 > v9 then v5 = v9. [source:raw]
    // ASSIGNMENT: Store the clamp range width at a2+32: *(float*)(a2 + 32) = v9 - v8. [source:raw]
    // CALCULATION: Compute the normalized offset v5 - v8 into a scratch dword. [source:raw]
    // CALL: Call FieldSetterTrigger(a2, v7) with the normalized offset. [source:raw, callee:0x0049ED00]
    // CALL: Call GuardedCall(a2, a3). [source:raw, callee:0x0049ED10]
    // CALL: Call sub_49ED20(a2, a3) and take its return value as the result. [source:raw, callee:0x0049ED20]
    // RETURN: Return the result (sub_49ED20 result in the handled cases, otherwise uninitialized). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49F530(unsigned int mode, int a2, int a3) {
    //     float v5, v8, v9;
    //     if (mode > 4 || !a3) return result;
    //     switch (mode) {
    //       case 0: v8 = 0.0f; v9 = 10000.0f; v5 = SpeedMultiplier(); break;
    //       case 1: v8 = 120.0f; v9 = 280.0f; v5 = dbl_7C91B4 - 273.16; break;
    //       case 2: v8 = 120.0f; v9 = 280.0f; v5 = dbl_7C9174 - 273.16; break;
    //       case 3: v8 = -3.0f; v9 = 100.0f; v5 = dbl_7C919C; break;
    //       case 4: v8 = 0.0f; v9 = 12.0f; v5 = TireFrictionCurveEval(&dbl_7C7428); break;
    //       default: return result;
    //     }
    //     if (mode == 1 || mode == 2) v5 = (v5 - -40.0) * 1.8 - 40.0;
    //     else if (mode == 3 || mode == 4) v5 = v5 * 0.14503774;
    //     if (v5 < v8) v5 = v8; else if (v5 > v9) v5 = v9;
    //     *(float*)(a2 + 32) = v9 - v8;
    //     int offset = v5 - v8;
    //     FieldSetterTrigger((int*)a2, offset);
    //     GuardedCall((int*)a2, a3);
    //     result = sub_49ED20((int*)a2, a3);
    //     return result;
    //   }
    // UNRESOLVED: Object type of a2 and the meaning of its field at +32 (clamp range width) are unknown; no field evidence exists in the packet.
    // UNRESOLVED: The exact conversion identity of factor 0.14503774 and the linear transform coefficients for modes 1/2 (a Celsius-style transform) are inferred from literals only.
    // UNRESOLVED: Jump-table globals jpt_49F55C and jpt_49F5F5 and helper constants dbl_59EAB0, dbl_59EAB8, dbl_59EAC0, flt_5ACAFC, flt_5ACB10 and unk_7CE234 are listed in the packet but do not appear in the raw source text.
}
