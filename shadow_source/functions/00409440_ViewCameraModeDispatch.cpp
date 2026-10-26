// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409440
// Canonical corpus name: ViewCameraModeDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ViewCameraModeDispatch_00409440.c

void UnknownObject::ViewCameraModeDispatch()
{
    // Camera/view-mode dispatcher driven by player input. Resolves a mode override (forcing mode 2 when a replay or camera-lock condition holds), then dispatches on the mode: cycling cockpit/TV/external views (0-2) via a signed step with wrap and vehicle-index clamping; absolute selection for modes 1 and 2; TV mode 3; sub-mode option cycling for mode 4; and special modes 7-8 that copy UI-state globals into sub-objects and invoke a vtable method. Every active path converges on a shared tail that plays an audio effect and calls the subsystem call before returning the float-keyed field selector.
    // GUARD: Mode override: when byte_7CFE88, the mode request is not 3, the camera-lock byte at dword_7C54E0+13388 is clear, or dword_8AB6E4 equals 2, the request is used as-is; otherwise the mode is forced to 2 with a zero sub-step. [global:0x007CFE88, global:0x007C54E0, global:0x008AB6E4, source:raw]
    // STATE_TRANSITION: Dispatch to one of the cases 0-8 through the switch jump table jpt_409487 keyed on the resolved mode value. [global:0x004096AC, source:raw]
    // GUARD: Modes 0-2 (guard on mode +0x34 <= 2): the input is interpreted as either an absolute button press or a cycle step depending on a4. [guard:0, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Absolute selection: mode 1 stores 1 into +0x34 (mode) and +0x50 (position); mode 2 stores 2 into both and derives the audio index from dword_7CFCC8; mode 0 stores 0 into +0x50 with audio index 3. [field:this:0x00000034, field:this:0x00000050, global:0x007CFCC8]
    // CALL: When dword_7C54E0 is non-zero, play the audio sound effect with the selected index. [global:0x007C54E0, callee:0x004E0ED0]
    // CALL: When the mode at +0x34 is non-zero, invoke the conditional subsystem call with the dword_7CF680 parameter. [field:this:0x00000034, global:0x007CF680, callee:0x00408DE0]
    // RETURN: Return FloatKeyedFieldSelector driven by the mode float at +0x34. [field:this:0x00000034, callee:0x00408740]
    // CALCULATION: Cycle path with no button press: derive a -1/0/+1 step from the sign of the sub-step, then wrap the position +0x50 by that step within 0..2 while the mode at +0x34 is 0-2. [guard:0, field:this:0x00000050, field:this:0x00000034]
    // GUARD: Vehicle-index comparison: when the tracked vehicle index (dword_7C54F0[dword_7C54DC]) matches dword_7C54F0[dword_7C54E4], skip the position clamp. [global:0x007C54F0, global:0x007C54DC, global:0x007C54E4]
    // CALCULATION: Position clamp after a cycle: at +0x50 == 1, an upward step with dword_7CFCC8 set forces +0x50 to 2; at +0x50 == 2 with dword_7CFCC8 clear, reset +0x50 to 0. [field:this:0x00000050, global:0x007CFCC8]
    // ASSIGNMENT: Commit the cycled position back into the mode at +0x34 (1 or 2, deriving the audio index from dword_7CFCC8), or into mode 0 with audio index 3. [field:this:0x00000034, field:this:0x00000050, global:0x007CFCC8]
    // STATE_TRANSITION: Mode 3 (TV): set +0x34 to 3 and fall to the shared audio tail. [field:this:0x00000034, callee:0x004E0ED0]
    // GUARD: Mode 4 (sub-mode): only re-index when the mode at +0x34 equals 4 and the sub-step is non-zero (guard:1). [guard:1, field:this:0x00000034]
    // CALCULATION: Sub-mode cycling: an upward step increments the sub-index +0x3C, wrapping to 0 at the option count +0x38; a downward step decrements it, wrapping to +0x38 - 1. [field:this:0x0000003C, field:this:0x00000038]
    // GUARD: Enter sub-mode (set +0x34 to 4) only when the option count at +0x38 is positive (guard:2). [guard:2, field:this:0x00000038, field:this:0x00000034]
    // STATE_TRANSITION: Modes 5-8: store the requested mode directly into +0x34. [field:this:0x00000034]
    // ASSIGNMENT: Mode 7: copy UI-state globals dword_5EA550, dword_5EA554 and dword_5EA558 into the sub-object at +0x2C (base +188), and clear dword_5BE900. [field:this:0x0000002C, field:*(this+0x2C):0x000000BC, field:*(this+0x2C):0x000000C0, field:*(this+0x2C):0x000000C4, global:0x005EA550, global:0x005EA554, global:0x005EA558, global:0x005BE900]
    // ASSIGNMENT: Mode 8: copy UI-state globals dword_5EA500, dword_5EA504 and dword_5EA508 into the sub-object at +0x30 (base +188), and clear dword_5BE900. [field:this:0x00000030, field:*(this+0x30):0x000000BC, field:*(this+0x30):0x000000C0, field:*(this+0x30):0x000000C4, global:0x005EA500, global:0x005EA504, global:0x005EA508, global:0x005BE900]
    // CALL: Mode 8: invoke the __thiscall vtable method at vtable+0x1C on the sub-object at +0x30. [field:*(this+0x30):0x00000000, field:*(*(this+0x30)+0x0):0x0000001C]
    // CALL: Shared tail: when dword_7C54E0 is non-zero play audio effect index 0; then call the conditional subsystem call with parameter 0 and return the float-keyed field selector for the mode at +0x34. [global:0x007C54E0, callee:0x004E0ED0, callee:0x00408DE0, callee:0x00408740, field:this:0x00000034]

    // Conservative worker pseudocode:
    //   int ViewCameraModeDispatch(int this, int mode, int step, int pressed) {
    //     int v4 = mode;
    //     if (!(byte_7CFE88 || mode != 3 || !*(byte*)(dword_7C54E0 + 13388) || dword_8AB6E4 == 2)) {
    //       v4 = 2;
    //       step = 0;
    //     }
    //     switch (v4) {
    //       case 0: case 1: case 2:
    //         if (pressed) {
    //           if (v4 == 1) { *(int*)(this + 52) = 1; *(int*)(this + 80) = 1; }
    //           else if (v4 == 2) { *(int*)(this + 52) = 2; *(int*)(this + 80) = 2; }
    //           else { *(int*)(this + 80) = 0; *(int*)(this + 52) = 0; }
    //           goto tail;
    //         }
    //         {
    //           int v10 = 0;
    //           if (step) v10 = (step > 0) ? 1 : -1;
    //           if (*(int*)(this + 52) <= 2) {
    //             int v11 = v10 + *(int*)(this + 80);
    //             *(int*)(this + 80) = (v11 > 2) ? 0 : (v11 < 0 ? 2 : v11);
    //           }
    //           if (*(int*)(dword_7C54F0[dword_7C54DC] + 18580) != *(int*)(dword_7C54F0[dword_7C54E4] + 18580)) {
    //             int pos = *(int*)(this + 80);
    //             if (pos == 1) { if (v10 > 0 && dword_7CFCC8) *(int*)(this + 80) = 2; }
    //             else if (pos != 2 || dword_7CFCC8) {
    //               pos = *(int*)(this + 80);
    //               if (pos == 1) *(int*)(this + 52) = 1;
    //               else if (pos == 2) *(int*)(this + 52) = 2;
    //               else { *(int*)(this + 52) = 0; }
    //               goto tail;
    //             }
    //             *(int*)(this + 80) = 0;
    //           }
    //         }
    //         goto tail;
    //       case 3:
    //         *(int*)(this + 52) = 3;
    //         goto tail_silent;
    //       case 4:
    //         if (*(int*)(this + 52) == 4 && step) {
    //           if (step == 1) { int n = *(int*)(this + 60) + 1; *(int*)(this + 60) = (n >= *(int*)(this + 56)) ? 0 : n; }
    //           else { int n = *(int*)(this + 60) - 1; *(int*)(this + 60) = (n < 0) ? *(int*)(this + 56) - 1 : n; }
    //           goto tail_silent;
    //         }
    //         if (*(int*)(this + 56) <= 0) goto tail_silent;
    //         *(int*)(this + 52) = 4;
    //         goto tail_silent;
    //       case 5: case 6: case 7: case 8:
    //         *(int*)(this + 52) = v4;
    //         if (v4 == 7) {
    //           int sub7 = *(int*)(this + 44);
    //           if (sub7) { int* d = (int*)(sub7 + 188); d[0] = dword_5EA550; d[1] = dword_5EA554; d[2] = dword_5EA558; dword_5BE900 = 0; (*(void (__thiscall **)(int))(**(int**)sub7 + 28))(sub7); }
    //         } else if (v4 == 8) {
    //           int sub8 = *(int*)(this + 48);
    //           if (sub8) { int* d = (int*)(sub8 + 188); d[0] = dword_5EA500; d[1] = dword_5EA504; d[2] = dword_5EA508; dword_5BE900 = 0; (*(void (__thiscall **)(int))(**(int**)sub8 + 28))(sub8); }
    //         }
    //         goto tail_silent;
    //       default:
    //         return FloatKeyedFieldSelector(this, *(float*)(this + 52));
    //     }
    //   tail:
    //     if (dword_7C54E0) AudioSoundEffectController(v8);
    //     if (!*(int*)(this + 52)) { ConditionalSubsystemCallWithParameter(this, 0); return FloatKeyedFieldSelector(this, *(float*)(this + 52)); }
    //     ConditionalSubsystemCallWithParameter(this, dword_7CF680);
    //     return FloatKeyedFieldSelector(this, *(float*)(this + 52));
    //   tail_silent:
    //     if (dword_7C54E0) AudioSoundEffectController(0);
    //     ConditionalSubsystemCallWithParameter(this, 0);
    //     return FloatKeyedFieldSelector(this, *(float*)(this + 52));
    //   }
    // UNRESOLVED: The object identity behind this is unknown; sub-objects at +0x2C and +0x30 are typed only by their use in modes 7 and 8.
    // UNRESOLVED: dword_7CFCC8 gates both the audio index and the position clamp; its semantic meaning (a camera-mode option flag) is inferred.
    // UNRESOLVED: The vehicle-index comparison uses offsets +18580 on two array entries; the exact meaning of the stored field is external.
}
