// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005932BA
// Canonical corpus name: sub_5932BA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5932BA_005932ba.c

void UnknownObject::ErrorCleanupAndExitDisplay()
{
    // Conditionally performs error cleanup and exit display. When dword_8D3EBC is 1, or when it is 0 and dword_5E65B4 is 1 (console attached), calls sub_5932F3(0xFC) for cleanup, invokes the optional callback stored in dword_8D41AC if non-null, then calls sub_5932F3(0xFF) for final exit display and returns that result. Otherwise returns dword_8D3EBC unchanged (no display path).
    // GUARD: Gate on dword_8D3EBC: enter the error-exit path only when it equals 1, or when it equals 0 and dword_5E65B4 (console attached flag) equals 1. [global:0x008D3EBC, global:0x005E65B4, source:raw]
    // CALL: Call sub_5932F3(0xFC) — error cleanup mode. [callee:0x005932F3, source:raw]
    // CALL: If dword_8D41AC is non-null, invoke it as a function pointer (optional registration/cleanup callback). [global:0x008D41AC, source:raw]
    // RETURN: Call sub_5932F3(0xFF) — final exit display — and return its result. [callee:0x005932F3, source:raw]
    // RETURN: Blocked path: return dword_8D3EBC unchanged when neither display condition holds. [global:0x008D3EBC, source:raw]
    // UNKNOWN: Error-path entry point reached from callers CRTAmsgExit and ErrorHandlerWithOptionalCleanupThenExit. [caller:0x0058A2A6, caller:0x0058A2CB]

    // Conservative worker pseudocode:
    //   int sub_5932BA() {
    //     int flag = dword_8D3EBC;
    //     if (flag == 1 || (flag == 0 && dword_5E65B4 == 1)) {
    //       sub_5932F3(0xFC);
    //       if (dword_8D41AC) dword_8D41AC();
    //       return sub_5932F3(0xFF);
    //     }
    //     return flag;
    //   }
    // UNRESOLVED: What sub_5932F3 modes 0xFC (cleanup) and 0xFF (final exit) do internally is not established here.
    // UNRESOLVED: Identity of the callback stored in dword_8D41AC and who registers it is unknown.
}
