// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564640
// Canonical corpus name: GetTickCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetTickCount_00564640.c

void UnknownObject::GetTickCount()
{
    // Compiler-generated import thunk for the Win32 GetTickCount API. Forwards directly to the resolved IAT entry __imp_GetTickCount (global 0x0059E0D4) and returns the resulting DWORD tick count. It has no local logic or side effects of its own.
    // CALL: Forward to the imported Win32 GetTickCount through the IAT slot __imp_GetTickCount (global 0x0059E0D4). [global:0x0059E0D4, source:raw]
    // RETURN: Return the DWORD tick count produced by the forwarded call. [source:raw]
    // CALL: Called by TickCountComparisonHandleInactivityTimeout (0x00561ED0), sub_562AC0, sub_5630D0, sub_563410 and sub_563AB0 for elapsed-time measurement. [caller:0x00561ED0, caller:0x00562AC0, caller:0x005630D0, caller:0x00563410, caller:0x00563AB0, function:0x00564640]

    // Conservative worker pseudocode:
    //   DWORD GetTickCount(void) {
    //     return __imp_GetTickCount();
    //   }
    // UNRESOLVED: The IAT entry __imp_GetTickCount is resolved at load time to the Win32 kernel; the exact target module is not evidenced in this packet.
    // UNRESOLVED: This is a plain import thunk with no owning game object.
}
