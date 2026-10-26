// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D5D0
// Canonical corpus name: sub_49D5D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49D5D0_0049d5d0.c

void UnknownObject::DispatchRaceStateHUD()
{
    // Dispatches HUD rendering by race session state (dword_7CE048) and session type (dword_7C56A4). Renders a clipped rectangle backdrop from the display context, then routes to timing/sector, timestamped-string, format-batch, brake/water-temperature, or session-specific display functions; session state 2 routes to a separate handler. Invoked from the steering-wheel animation frame path.
    // GUARD: Outer dispatch on dword_7CE048 race session state: cases 0/1/3/4 proceed to HUD rendering, case 2 routes to sub_49DE40, default returns immediately. [global:0x007CE048, global:0x0049D6AC, callee:0x0049DE40]
    // GUARD: Require display context A (this[5]), display context B (this[6]) and render resource pointer (this[2]) all non-null before rendering. [field:this:0x00000014, field:this:0x00000018, field:this:0x00000008]
    // CALL: Render clipped backdrop via ClippedRectRender(0.0, 0.0, *(this[5] + 84), 0.0, 0.0, 1.0, 1.0, 0, 0), using a width sourced from display context A. [callee:0x005432F0, field:this:0x00000014, source:raw]
    // GUARD: When the a2 flag is nonzero, skip the HUD sub-dispatch entirely and return the current result. [source:raw]
    // CALL: Second dispatch on dword_7CE048: session state 1 routes to ConditionalDispatch(this). [global:0x007CE048, callee:0x0049E3E0]
    // CALL: Session state 0 sub-switch on dword_7C56A4 session type: cases 0-5 route to UtilityFunction_d8b0, case 6 to TimestampedRenderStringUpdate, case 7 to sub_49D700. [global:0x007C56A4, global:0x0049D6C0, global:0x0049D6D4, callee:0x0049D8B0, callee:0x0049DA60, callee:0x0049D700]
    // GUARD: Session state 3 requires the format string context pointer this[3] to be non-null before formatting. [field:this:0x0000000C]
    // CALL: Session state 3 routes to FormatStringBatchDisplay(this) for batch string display. [callee:0x0049E170, field:this:0x0000000C]
    // CALL: Session state 4 routes to BrakeWaterTemperatureHUDDisplay(this) for brake/water temperature display. [callee:0x0049DB80]
    // CALL: Invoked from the SteeringWheelAnimation frame path as the race-state HUD render step. [caller:0x0049D070]
    // RETURN: Return the last dispatch result (selector value or callee return). [source:raw]

    // Conservative worker pseudocode:
    //   // dword_7CE048 = race session state; dword_7C56A4 = session type
    //   switch (dword_7CE048) {
    //     case 0: case 1: case 3: case 4:
    //       if (this[5] && this[6] && this[2]) {
    //         ClippedRectRender(0.0, 0.0, *(this[5] + 84), 0.0, 0.0, 1.0, 1.0, 0, 0);
    //         if (!a2) {
    //           switch (dword_7CE048) {
    //             case 0:
    //               switch (dword_7C56A4) {
    //                 case 0..5: UtilityFunction_d8b0(this); break;
    //                 case 6:    TimestampedRenderStringUpdate(this); break;
    //                 case 7:    sub_49D700(this); break;
    //               }
    //               break;
    //             case 1: ConditionalDispatch(this); break;
    //             case 3: if (this[3]) FormatStringBatchDisplay(this); break;
    //             case 4: BrakeWaterTemperatureHUDDisplay(this); break;
    //           }
    //         }
    //       }
    //       break;
    //     case 2: sub_49DE40(a2); break;
    //   }
    //   return v2;
    // UNRESOLVED: Field this+0x68 is listed in the packet but not referenced by the raw body; its purpose is unresolved.
    // UNRESOLVED: Meaning of the a2 flag (suppresses the HUD sub-dispatch when nonzero) is caller-specific.
    // UNRESOLVED: Object type behind this[5]+84 used as the clipped-rect width source is unresolved.
    // UNRESOLVED: The three jump tables at 0x0049D6AC, 0x0049D6C0 and 0x0049D6D4 back the dispatch switches; exact case layouts follow Hex-Rays.
    // UNRESOLVED: Return value semantic is a low-trust selector artifact, not a contract.
}
