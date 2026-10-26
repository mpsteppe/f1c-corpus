// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0BA0
// Canonical corpus name: RaceFinishHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceFinishHandler_004a0ba0.c

void UnknownObject::RaceFinishHandler()
{
    // Handles race completion for a driver. Triggers per-driver race commentary, then (when the driver has not finished and qualifying DSQ is disabled) advances the game action state machine to post-race state 5, transitions the session state, and conditionally switches to menu mode based on the player vehicle's finish state, a timing expression and the session mode. Finally dispatches in-race event 19 when the driver finish flag is 1. Always returns 0.
    // CALL: Trigger per-driver race commentary for the finishing driver. [callee:0x00419C50, source:raw]
    // GUARD: Proceed only when the driver's finished flag (a2[3250]) is clear and the qualifying DSQ switch (dword_7CE814) is clear. [global:0x007CE814, source:raw]
    // CALL: Advance the game action state machine at dword_5EA510 to post-race state 5 with the parameter 1. [callee:0x0040CDE0, global:0x005EA510, source:raw]
    // CALL: Transition the session state machine to state 1. [callee:0x004EF5A0, source:raw]
    // GUARD: When the driver's finish flag (a2[4120]) is not 1, evaluate the menu-mode condition on the player vehicle. [source:raw]
    // CALCULATION: Locate the player vehicle slot via sub_4D1B50(0) into the vehicle array at unk_5EC6D8 using the array stride. [callee:0x004D1B50, global:0x005EC6D8, source:raw]
    // GUARD: Switch to menu mode when the vehicle finish flag is 1, the timing expression (vehicle float at index 4142 plus flt_8ACF90 minus dbl_8AFEA0) exceeds 60.0, and the session mode (dword_8AD298) is not 19. [global:0x008ACF90, global:0x008AFEA0, global:0x008AD298, source:raw]
    // CALL: Switch the session to menu/mode select. [callee:0x004A0C60, source:raw]
    // GUARD: When the driver finish flag (a2[4120]) equals 1, dispatch the in-race event for the race winner. [source:raw]
    // CALL: Dispatch in-race event 19 via sub_4D8760(19, 0). [callee:0x004D8760, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int RaceFinishHandler(void* this, Driver* driver) {
    //     PerDriverRaceCommentary(driver);
    //     if (!driver->finished && !dword_7CE814) {
    //       GameActionStateMachine(&dword_5EA510, 5, 1);
    //       SessionStateTransition(1, 0);
    //       if (driver->finish_flag != 1) {
    //         Vehicle* player = &unk_5EC6D8 + 18624 * sub_4D1B50(0);
    //         if (player->finish_flag == 1 && player->f32[4142] + flt_8ACF90 - dbl_8AFEA0 > 60.0f && dword_8AD298 != 19)
    //           SessionMenuModeSwitch(this);
    //       }
    //     }
    //     if (driver->finish_flag == 1) sub_4D8760(19, 0);
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_59F118, dword_5EB978, dword_7C54E8 and dword_8ACEE0 are listed by the packet but have no direct use in the raw source.
    // UNRESOLVED: Driver-relative indexing (a2[3250], a2[4120]) and vehicle indices (4121, 4142) refer to the caller's driver/vehicle record layouts, not resolved here.
    // UNRESOLVED: The exact meaning of the session mode gate 19 is not derivable from this packet.
}
