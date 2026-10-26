// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E9E6
// Canonical corpus name: ColorMatrixTransformWithBlend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorMatrixTransformWithBlend_0050e9e6.c

void UnknownObject::ColorMatrixTransformWithBlend()
{
    // Transforms three color components at a1 (offsets 0x0/0x4/0x8) through a flag-selected matrix/thunk pipeline. A switch on the combined presence of flags a4/a5/a6 selects whether a transform thunk runs once (cases 3/5/6), twice (case 7), or not at all; a second transform thunk always runs. When blend data a3 is present, each component is blended against per-channel offset/scale values read from a3. Returns a1.
    // GUARD: Switch on (a4!=0) | 2*((a5!=0) | 2*(a6!=0)) backed by jump table jpt_50EA25: cases 3, 5 and 6 call the conditional thunk once, case 7 calls it twice, default (none or single flag) calls it not at all [global:0x0050EB53, source:raw]
    // CALL: ThunkToFUN0050cba3() runs once for switch cases 3/5/6 and twice for case 7; it is the conditional color-transform step [callee:0x0050CBB0, source:raw]
    // CALL: ThunkToThunkFUN0050c5b0() runs unconditionally after the switch; it is the always-applied color-transform step [callee:0x0050C5BD, source:raw]
    // GUARD: Blend applies only when a3 is non-null [source:raw]
    // CALCULATION: Component 0: a1[0] = (a1[0] + 1.0) * *(uint*)(a3+8) * 0.5 + *(uint*)a3 [field:this:0x00000000, source:raw]
    // CALCULATION: Component 1: a1[1] = (1.0 - a1[1]) * *(uint*)(a3+12) * 0.5 + *(uint*)(a3+4) [field:this:0x00000004, source:raw]
    // CALCULATION: Component 2: a1[2] = (*(float*)(a3+20) - *(float*)(a3+16)) * a1[2] + *(float*)(a3+16) [field:this:0x00000008, source:raw]
    // RETURN: Return the transformed a1 color vector [function:0x0050E9E6, source:raw]

    // Conservative worker pseudocode:
    //   switch ((a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0))))) {
    //     case 3: case 5: case 6:
    //       ThunkToFUN0050cba3();
    //       break;
    //     case 7:
    //       ThunkToFUN0050cba3();
    //       ThunkToFUN0050cba3();
    //       break;
    //   }
    //   ThunkToThunkFUN0050c5b0();
    //   if (a3) {
    //     a1[0] = (a1[0] + 1.0) * *(uint*)(a3+8) * 0.5 + *(uint*)a3;
    //     a1[1] = (1.0 - a1[1]) * *(uint*)(a3+12) * 0.5 + *(uint*)(a3+4);
    //     a1[2] = (*(float*)(a3+20) - *(float*)(a3+16)) * a1[2] + *(float*)(a3+16);
    //   }
    //   return a1;
    // UNRESOLVED: The three float globals flt_59E43C, flt_59E450 and flt_5ADB14 are flagged as read by packet facts but appear nowhere in the raw decompiled source; likely constants consumed inside the thunk callees
    // UNRESOLVED: The a3 blend layout (uint at +0/+4/+8/+12, float at +16/+20) is read directly but its semantic field names are not documented
    // UNRESOLVED: The meaning of the a4/a5/a6 flag combinations and the two thunk callees is unknown
    // UNRESOLVED: Parameter a2 is unused
}
