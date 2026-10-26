// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E7B0
// Canonical corpus name: sub_49E7B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49E7B0_0049e7b0.c

void UnknownObject::RenderColoredBarFromNormalizedValue()
{
    // Renders a colored horizontal bar whose fill proportion and color depend on a normalized value for a vehicle corner. Guards on vehicle equality by comparing the +18580 field of the player vehicle (VehiclePtrArray[CurrentPlayerIndex]) with the same field of the current vehicle (VehiclePtrArray[CurrentVehicleIndex]). When equal, reads a per-corner value indexed by a1 (stride 1124 into a data region), normalizes it with (v - 0.75) * 4.0, clamps to [0,1], draws a fixed-color background bar, then draws a proportional fill bar whose color is chosen by the normalized level. When the vehicles differ, draws a full green bar.
    // GUARD: Vehicle equality check: compare the +18580 field of VehiclePtrArray[CurrentPlayerIndex] with the same field of VehiclePtrArray[CurrentVehicleIndex]. Equal vehicles take the value-driven bar path; different vehicles take the full-green-bar path. [global:0x007C54F0, global:0x007C54DC, global:0x007C54E4, source:raw]
    // CALCULATION: Read the per-corner value indexed by a1 (stride 1124 into a data region) and normalize it: v = (value - 0.75) * 4.0. [source:raw]
    // CALCULATION: Clamp the normalized value into [0.0, 1.0]: values below 0 are forced to 0, values above 1 are forced to 1. [source:raw]
    // CALL: Draw the background bar in a fixed dark color (-16777216) with the original dimensions via RenderDrawOperationWithClipping. [callee:0x00543440, source:raw]
    // GUARD: Only draw the fill bar when the normalized value is greater than 0.0; otherwise leave only the background. [source:raw]
    // CALCULATION: Select the fill color from the normalized value: -16711936 when greater than 0.8, -256 when between 0.5 and 0.8, otherwise -65536. [source:raw]
    // CALL: Convert the scaled fill width with CRTFtol((double)a4 * v9). [callee:0x00587BDC, source:raw]
    // CALL: Draw the proportional fill bar with the selected color and converted width via RenderDrawOperationWithClipping. [callee:0x00543440, source:raw]
    // CALL: When the compared vehicles differ, draw a full bar in green (-16711936) via RenderDrawOperationWithClipping. [callee:0x00543440, source:raw]

    // Conservative worker pseudocode:
    //   void sub_49E7B0(int a1, int a2, int a3, int a4, int a5) {
    //     if (*(int*)(VehiclePtrArray[CurrentPlayerIndex] + 18580) == *(int*)(VehiclePtrArray[CurrentVehicleIndex] + 18580)) {
    //       float v9 = (double)(*(double*)((char*)data + 1124 * a1) - 0.75) * 4.0;
    //       if (v9 >= 0.0) { if (v9 > 1.0) v9 = 1.0; } else v9 = 0.0;
    //       RenderDrawOperationWithClipping(a2, a3, a4, a5, -16777216);
    //       if (v9 > 0.0) {
    //         int color = -65536;
    //         if (v9 <= 0.80000001) { if (v9 > 0.5) color = -256; }
    //         else color = -16711936;
    //         RenderDrawOperationWithClipping(a2, a3, CRTFtol((double)a4 * v9), a5, color);
    //       }
    //     } else {
    //       RenderDrawOperationWithClipping(a2, a3, a4, a5, -16711936);
    //     }
    //   }
    // UNRESOLVED: The exact meaning of the value indexed by a1 is not proven by the raw body; prior analysis labels it suspension load, but that name is not grounded in this function alone.
    // UNRESOLVED: The fields at +18580 on each vehicle (compared for equality) are not otherwise identified.
    // UNRESOLVED: The source data region and the 1124 stride convention are not established.
    // UNRESOLVED: Six read globals (flt_59E43C, flt_59E440, flt_59E450, dbl_59E7D8, flt_59E8CC, dbl_59EA60) do not appear in the raw body; their exact use is unknown.
}
