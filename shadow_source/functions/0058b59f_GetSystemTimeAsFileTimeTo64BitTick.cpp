// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B59F
// Canonical corpus name: GetSystemTimeAsFileTimeTo64BitTick
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetSystemTimeAsFileTimeTo64BitTick_0058b59f.c

void UnknownObject::GetSystemTimeAsFileTimeTo64BitTick()
{
    // Captures the current UTC system time as a FILETIME, folds its two 32-bit halves into a single 64-bit tick value via Allmul, stores that tick to global qword_8D3EC0, and returns it. Straight-line; no conditional branches.
    // CALL: Call the imported GetSystemTimeAsFileTime with a stack FILETIME buffer to capture the current UTC system time. [global:0x0059E1B8, source:raw]
    // CALL: Use Allmul, the 64-bit multiply helper, to multiply the high 32-bit FILETIME word by 0x100000000 so it lands in the upper half of the 64-bit tick. [callee:0x0058C6F0, source:raw]
    // CALCULATION: Combine the tick as the low FILETIME dword plus the shifted high dword. [source:raw]
    // ASSIGNMENT: Store the resulting 64-bit tick to global qword_8D3EC0 (0x008D3EC0). [global:0x008D3EC0]
    // ASSIGNMENT: The upper dword of the stored qword covers the overlapping byte at 0x008D3EC4. [global:0x008D3EC4]
    // RETURN: Return the computed 64-bit tick value. [source:raw, function:0x0058B59F]

    // Conservative worker pseudocode:
    //   unsigned __int64 GetSystemTimeAsFileTimeTo64BitTick() {
    //     _FILETIME ft;
    //     GetSystemTimeAsFileTime(&ft);
    //     unsigned __int64 tick = ft.dwLowDateTime + Allmul(ft.dwHighDateTime, 0x100000000LL);
    //     qword_8D3EC0 = tick;
    //     return tick;
    //   }
    // UNRESOLVED: Two TLS bytes at 0xFF00000000005394 and 0xFF00000000005395 are listed as read in the packet's global table but do not appear in the raw body; their role is unknown.
    // UNRESOLVED: GetSystemTimeAsFileTime is an IAT import pointer; its exact module binding is not reconstructed here.
}
