// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461DE0
// Canonical corpus name: StartNetworkUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StartNetworkUpdate_00461de0.c

void UnknownObject::StartNetworkUpdate()
{
    // Network session startup dispatcher. Reads the network system pointer at obj+0x1B79C (obj is *this) and, when non-null, queries capability via sub_563E70 (setting a flag through SetFlagIfPointerNonNull if capable) and initialises it with DirectDrawDisplayModeInit. On DirectDrawDisplayModeInit success, branches on the global network type dword_7D0E74: value 1 takes the internet path (InitWrapper on the network pointer with mode 1), otherwise the LAN path (MultiStageInitializationChainWithErrorChecking over the port range word_7D0FE8..word_7D0FE8+99). Both paths gate developer logging on dword_7C569C != 5 and emit a StartInternetUpdate or StartLanUpdate debug message via StringSplitLoop/DebugLogWrite. Called by StateResetAndConditionalInit (00475530).
    // GUARD: Entire body gated on the network system pointer at obj+0x1B79C (obj = *this) being non-null; when null the function returns immediately with result = *this [field:obj:0x0001B79C, field:this:0x00000000, source:raw]
    // CALL: Capability query sub_563E70; when non-zero, SetFlagIfPointerNonNull is applied to the network system pointer at obj+0x1B79C [callee:0x00563E70, callee:0x00563DF0, field:obj:0x0001B79C, source:raw]
    // CALL: DirectDrawDisplayModeInit run on the network system pointer at obj+0x1B79C; its result drives the failure branch that still proceeds with network initialisation [callee:0x00563E00, field:obj:0x0001B79C, source:raw]
    // GUARD: Network type dispatch: global dword_7D0E74 equal to 1 selects the internet path, any other value selects the LAN path [global:0x007D0E74, source:raw]
    // CALL: Internet path: InitWrapper(network ptr, 1) initialises the internet network mode [callee:0x00562C80, field:obj:0x0001B79C, source:raw]
    // GUARD: Developer-logging gate: both init paths check global dword_7C569C != 5 (session type 5 suppressed) before emitting their start message [global:0x007C569C, source:raw]
    // CALL: Internet logging: StringSplitLoop(1, aDDevF119992002_1, 5776) gates a DebugLogWrite(&dword_8AD25C, aStartingIntern) "Starting internet update" message [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C5CE4, global:0x005C616C, global:0x008AD25C, source:raw]
    // CALL: LAN path: MultiStageInitializationChainWithErrorChecking(word_7D0FE8, word_7D0FE8+99, 1) initialises the LAN network across the port range of the session port base [callee:0x00563020, global:0x007D0FE8, source:raw]
    // CALL: LAN logging: StringSplitLoop(1, aDDevF119992002_1, 5765) gates a DebugLogWrite(&dword_8AD25C, aStartingLanUpd) "Starting LAN update" message [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C5CE4, global:0x005C6194, global:0x008AD25C, source:raw]
    // RETURN: Returns the last stored result: the DirectDrawDisplayModeInit return value, the logging gate result, or *this when the network pointer was null [source:raw]
    // CALL: Invoked by StateResetAndConditionalInit (00475530) as part of session/state conditional initialisation [caller:0x00475530, source:raw]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   net = *(obj + 0x1B79C);
    //   if (net) {
    //     if (sub_563E70()) SetFlagIfPointerNonNull(net);
    //     result = DirectDrawDisplayModeInit(net);
    //     if (!result) {
    //       if (dword_7D0E74 == 1) {
    //         result = InitWrapper(net, 1);
    //         if (dword_7C569C != 5) {
    //           result = StringSplitLoop(1, aDDevF119992002_1, 5776);
    //           if (result) return DebugLogWrite(&dword_8AD25C, aStartingIntern);
    //         }
    //       } else {
    //         result = MultiStageInitializationChainWithErrorChecking(word_7D0FE8, word_7D0FE8+99, 1);
    //         if (dword_7C569C != 5) {
    //           result = StringSplitLoop(1, aDDevF119992002_1, 5765);
    //           if (result) return DebugLogWrite(&dword_8AD25C, aStartingLanUpd);
    //         }
    //       }
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The network system object owning obj+0x1B79C is not named; the 0x1B79C offset is far outside any header-derived layout in this packet
    // UNRESOLVED: Constants 5776 and 5765 passed to StringSplitLoop are opaque verbosity/guard selectors with no documented meaning
    // UNRESOLVED: word_7D0FE8 is read as a raw 16-bit port base; the session/port semantics of dword_7D0FE8+99 are inferred from the skeleton, not proven here
    // UNRESOLVED: The exact meaning of dword_7C569C==5 (session type 5) is not defined within this packet
}
