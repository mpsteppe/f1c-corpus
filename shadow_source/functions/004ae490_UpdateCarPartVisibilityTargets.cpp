// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004AE490
// Canonical corpus name: CarPartVisibilityController
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarPartVisibilityController_004ae490.c

void UnknownObject::UpdateCarPartVisibilityTargets()
{
    // Updates clamped car-part visibility slider targets based on a mode selector at this+0x1AC8. Mode 1 slides the primary part groups toward hidden (integer targets 0, float targets 1028443341), mode 2 slides them toward visible (integer targets 1, float targets 1056964608); the mode-2 branch also applies FloatClamp to the second float target slot. A non-zero mode additionally drives six secondary part-group targets toward 1 (clamped), then runs a helper sequence: three ArithmeticComparison_20d0(2) calls, three ShortComputation_3060(dword_5EC3D0)-1 derived ArithmeticComparison_20d0 calls, and a final ArithmeticComparison_20d0(23).
    // GUARD: Guard on mode selector at this+0x1AC8 == 1 (mode 1, hide/minimize parts). [field:this:0x00001AC8, guard:0, source:raw]
    // CALCULATION: Mode 1: write slider target 0xB10 = 0 then clamp via ClampByRange against min bound 0xB18 and max bound 0xB1C. [field:this:0x00000B10, field:this:0x00000B18, field:this:0x00000B1C, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 1: write slider target 0xB34 = 0 then clamp against min 0xB3C and max 0xB40. [field:this:0x00000B34, field:this:0x00000B3C, field:this:0x00000B40, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 1: write slider target 0xB58 = 0 then clamp against min 0xB60 and max 0xB64. [field:this:0x00000B58, field:this:0x00000B60, field:this:0x00000B64, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 1: write slider target 0x1C30 = 1 then clamp against min 0x1C38 and max 0x1C3C. [field:this:0x00001C30, field:this:0x00001C38, field:this:0x00001C3C, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 1: write float slider target 0x2348 = 1028443341 then clamp via FloatClamp against float min 0x2350 and float max 0x2354. [field:this:0x00002348, field:this:0x00002350, field:this:0x00002354, callee:0x004646C0, source:raw]
    // ASSIGNMENT: Mode 1: write float slider target 0x236C = 1028443341 (second float part group). [field:this:0x0000236C, field:this:0x00002374, field:this:0x00002378, source:raw]
    // GUARD: Guard on mode selector at this+0x1AC8 != 2; when the selector is neither 1 nor 2 execution jumps to the shared post-switch path. [field:this:0x00001AC8, guard:1, source:raw]
    // CALCULATION: Mode 2: write slider target 0xB10 = 1 then clamp against min 0xB18 and max 0xB1C. [field:this:0x00000B10, field:this:0x00000B18, field:this:0x00000B1C, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 2: write slider target 0xB34 = 1 then clamp against min 0xB3C and max 0xB40. [field:this:0x00000B34, field:this:0x00000B3C, field:this:0x00000B40, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 2: write slider target 0xB58 = 1 then clamp against min 0xB60 and max 0xB64. [field:this:0x00000B58, field:this:0x00000B60, field:this:0x00000B64, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 2: write slider target 0x1C30 = 0 then clamp against min 0x1C38 and max 0x1C3C. [field:this:0x00001C30, field:this:0x00001C38, field:this:0x00001C3C, callee:0x0047F1F0, source:raw]
    // CALCULATION: Mode 2: write float slider target 0x2348 = 1056964608 then clamp via FloatClamp against float min 0x2350 and float max 0x2354. [field:this:0x00002348, field:this:0x00002350, field:this:0x00002354, callee:0x004646C0, source:raw]
    // ASSIGNMENT: Mode 2: write float slider target 0x236C = 1056964608 (second float part group). [field:this:0x0000236C, field:this:0x00002374, field:this:0x00002378, source:raw]
    // CALL: Shared path: clamp the second float slider target 0x236C via FloatClamp against float min 0x2374 and float max 0x2378 (the mode-dependent write to 0x236C is then re-clamped). [field:this:0x0000236C, field:this:0x00002374, field:this:0x00002378, callee:0x004646C0, source:raw]
    // GUARD: Post-switch guard on mode selector at this+0x1AC8 being non-zero; a non-zero selector drives the secondary part-group targets and helper sequence. [field:this:0x00001AC8, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x26F0 = 1 then clamp against min 0x26F8 and max 0x26FC. [field:this:0x000026F0, field:this:0x000026F8, field:this:0x000026FC, callee:0x0047F1F0, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x2714 = 1 then clamp against min 0x271C and max 0x2720. [field:this:0x00002714, field:this:0x0000271C, field:this:0x00002720, callee:0x0047F1F0, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x2738 = 1 then clamp against min 0x2740 and max 0x2744. [field:this:0x00002738, field:this:0x00002740, field:this:0x00002744, callee:0x0047F1F0, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x27EC = 1 then clamp against min 0x27F4 and max 0x27F8. [field:this:0x000027EC, field:this:0x000027F4, field:this:0x000027F8, callee:0x0047F1F0, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x2810 = 1 then clamp against min 0x2818 and max 0x281C. [field:this:0x00002810, field:this:0x00002818, field:this:0x0000281C, callee:0x0047F1F0, source:raw]
    // CALCULATION: Non-zero mode: write slider target 0x2834 = 1 then clamp against min 0x283C and max 0x2840. [field:this:0x00002834, field:this:0x0000283C, field:this:0x00002840, callee:0x0047F1F0, source:raw]
    // CALL: Non-zero mode: run three ArithmeticComparison_20d0(2) helper calls, then for each of three ShortComputation_3060(dword_5EC3D0) reads call ArithmeticComparison_20d0(result - 1), and finally return ArithmeticComparison_20d0(23). [callee:0x004B20D0, callee:0x00423060, global:0x005EC3D0, source:raw]
    // RETURN: Return the mode selector value at this+0x1AC8 as the function result. [field:this:0x00001AC8, source:raw]
    // CALL: Called by sub_472930 (0x00472930) and TrackEnvironmentSelect (0x004ADE20) to update car-part visibility slider targets. [caller:0x00472930, caller:0x004ADE20, source:raw]

    // Conservative worker pseudocode:
    //   int UpdateCarPartVisibilityTargets(int this) {
    //     if (*(DWORD*)(this + 0x1AC8) == 1) {
    //       ClampedWrite(0xB10, 0); ClampedWrite(0xB34, 0); ClampedWrite(0xB58, 0);
    //       ClampedWrite(0x1C30, 1); ClampedFloatWrite(0x2348, 1028443341);
    //       *(DWORD*)(this + 0x236C) = 1028443341;
    //     } else if (*(DWORD*)(this + 0x1AC8) == 2) {
    //       ClampedWrite(0xB10, 1); ClampedWrite(0xB34, 1); ClampedWrite(0xB58, 1);
    //       ClampedWrite(0x1C30, 0); ClampedFloatWrite(0x2348, 1056964608);
    //       *(DWORD*)(this + 0x236C) = 1056964608;
    //     } else goto skip_first;
    //     FloatClamp((float*)(this + 0x236C), *(float*)(this + 0x2374), *(float*)(this + 0x2378));
    //   skip_first:
    //     int r = *(DWORD*)(this + 0x1AC8);
    //     if (r) {
    //       ClampedWrite(0x26F0, 1); ClampedWrite(0x2714, 1); ClampedWrite(0x2738, 1);
    //       ClampedWrite(0x27EC, 1); ClampedWrite(0x2810, 1); ClampedWrite(0x2834, 1);
    //       ArithmeticComparison_20d0(2); ArithmeticComparison_20d0(2); ArithmeticComparison_20d0(2);
    //       int a = ShortComputation_3060(dword_5EC3D0); ArithmeticComparison_20d0(a - 1);
    //       int b = ShortComputation_3060(dword_5EC3D0); ArithmeticComparison_20d0(b - 1);
    //       int c = ShortComputation_3060(dword_5EC3D0); ArithmeticComparison_20d0(c - 1);
    //       return ArithmeticComparison_20d0(23);
    //     }
    //     return r;
    //   }
    // UNRESOLVED: Why the second float target 0x236C is written then immediately re-clamped by the shared FloatClamp, and why the final ArithmeticComparison_20d0 result is the function return value, is not explained by the packet.
    // UNRESOLVED: The relationship between the mode selector at 0x1AC8 and the six secondary group targets (0x26F0..0x2834) is inferred; the meaning of the ShortComputation_3060(dword_5EC3D0)-1 derived arguments is unknown here.
}
