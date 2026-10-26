// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460DD0
// Canonical corpus name: CollisionContactIteration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionContactIteration_00460dd0.c

void UnknownObject::CollisionContactIteration()
{
    // Iterates the 104-slot vehicle array (base unk_5EC6D8, stride 18624/0x48C0, ending at byte_7C54D8) and, for each vehicle whose live-state int32 at +0x32C8 equals 2, resolves collision-contact response: computes penetration ratio (per-vehicle float at a1+0x1A3D4 divided by flt_7D108C), consults the short-array contact lookup ShortArrayLookupAndZeroCheck, and on severe contact (ratio > 2.0 or contact flag set) releases AI control via VehicleAIControlFlag(0) and toggles driver visibility (hidden when ratio > 8.0 or |contact value| > 0.75, else shown); otherwise retains AI control via VehicleAIControlFlag(1) and shows the driver. Called from SessionScoringUpdate.
    // LOOP: Iterate the vehicle array from base unk_5EC6D8 stepping 18624 (0x48C0) bytes, one vehicle per index, until the running pointer reaches byte_7C54D8 (array end bound) [global:0x005EC6D8, global:0x007C54D8, source:raw]
    // GUARD: For each vehicle, test the live-state int32 at array element +0x32C8 (element base + 3250 dwords) == 2; only such vehicles get contact response [global:0x005EC6D8, source:raw]
    // CALL: Call ShortArrayLookupAndZeroCheck on the contact short array at a1+0x1A3C0 with the current vehicle index, writing an out float to v8 [callee:0x0045CBF0, field:this:0x0001A3D4, source:raw]
    // CALCULATION: Compute penetration ratio v5 = penetration float at a1+0x1A3D4 (per-vehicle, advanced per step) divided by flt_7D108C [field:this:0x0001A3D4, global:0x007D108C, source:raw]
    // GUARD: Severe-contact test: penetration ratio > 2.0 OR the short-array contact lookup returned nonzero [global:0x007D108C, source:raw]
    // CALL: On severe contact, call VehicleAIControlFlag(0) to release AI control [callee:0x004C7A70, source:raw]
    // GUARD: Visibility guard within severe contact: ratio > 8.0 OR fabs(v8) > 0.75 selects hiding the driver, else showing [global:0x007D108C, source:raw]
    // CALL: Call SetDriverVisibility(0) to hide the driver when the penetration/contact magnitude is large [callee:0x004C7AA0, source:raw]
    // CALL: Otherwise call SetDriverVisibility(1) to show the driver [callee:0x004C7AA0, source:raw]
    // CALL: On non-severe contact, call VehicleAIControlFlag(1) to retain AI control and SetDriverVisibility(1) [callee:0x004C7A70, callee:0x004C7AA0, source:raw]
    // CALL: Invoked by SessionScoringUpdate (004643c0) [caller:0x004643C0, source:raw]

    // Conservative worker pseudocode:
    //   for (veh = &unk_5EC6D8, i = 0; veh < byte_7C54D8; veh += 0x48C0, i++) {
    //     if (veh[+0x32C8] == 2) {
    //       contact = ShortArrayLookupAndZeroCheck(a1 + 0x1A3C0, i, &v8);
    //       ratio = penetration[i] / flt_7D108C;
    //       if (ratio > 2.0 || contact) {
    //         VehicleAIControlFlag(0);
    //         if (ratio > 8.0 || fabs(v8) > 0.75) SetDriverVisibility(0);
    //         else SetDriverVisibility(1);
    //       } else {
    //         VehicleAIControlFlag(1);
    //         SetDriverVisibility(1);
    //       }
    //     }
    //   }
    // UNRESOLVED: Globals flt_59E4DC, flt_59E800, and dbl_59EA60 are listed as read globals in the packet but do not appear in the raw function body; their role here is unconfirmed
    // UNRESOLVED: The exact meaning of the per-vehicle state 2 at +0x32C8 and the semantics of the short-array contact lookup values are inherited from the fill prose, not the raw body
}
