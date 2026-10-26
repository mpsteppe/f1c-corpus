// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561ED0
// Canonical corpus name: TickCountComparisonHandleInactivityTimeout
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TickCountComparisonHandleInactivityTimeout_00561ed0.c

void UnknownObject::InactivityTimeoutHandler()
{
    // Track a connection inactivity timeout using GetTickCount. When the identifier field at this+0x4 is not -1, reads the last activity timestamp at this+0xD8 and computes elapsed ticks. Within a valid window (elapsed <= 0x493E0, timestamp nonzero, TickCount >= timestamp) it runs retry logic: if the retry byte at this+0xE8 is above 0 and elapsed exceeds 0x7530, it calls sub_562AC0(this, 0), increments the retry byte, and resets it to 0 once it exceeds 10. When the window is invalid/expired it calls sub_562AC0(this, 0) to reset state. Called from StringLengthCheckDispatch (0045D4E0).
    // CALL: Capture the current system tick count via GetTickCount; the result also seeds the function return value. [callee:0x00564640, source:raw]
    // GUARD: Guard on the identifier field at this+0x4: when it equals 0xFFFFFFFF the timeout tracking is skipped entirely; otherwise the inactivity logic runs. [guard:0, field:this:0x00000004]
    // CALCULATION: Compute elapsed = TickCount - last activity timestamp at this+0xD8; the window is valid only when elapsed <= 0x493E0, the timestamp is nonzero, and TickCount >= timestamp. [field:this:0x000000D8, source:raw]
    // CALL: When the elapsed window is invalid or expired, call sub_562AC0(this, 0) to reset the connection/session state. [callee:0x00562AC0, source:raw]
    // GUARD: Retry condition: the retry byte at this+0xE8 must be above 0 and the elapsed value must exceed 0x7530 before a retry is performed. [field:this:0x000000E8, source:raw]
    // CALL: Perform the retry/resend action via sub_562AC0(this, 0). [callee:0x00562AC0]
    // ASSIGNMENT: Increment the retry byte stored at this+0xE8. [field:this:0x000000E8]
    // GUARD: Cap the retry byte: when the incremented value at this+0xE8 exceeds 10, reset it to 0. [field:this:0x000000E8]
    // RETURN: Return the char-truncated accumulator, which varies by path: the low byte of GetTickCount(), the char-truncated result of sub_562AC0, or the incremented retry counter. [source:raw]
    // CALL: Invoked from StringLengthCheckDispatch (0045D4E0) on the connection activity-check path. [caller:0x0045D4E0, source:raw]

    // Conservative worker pseudocode:
    //   char InactivityTimeoutHandler(int this) {
    //     DWORD ticks = GetTickCount();
    //     if (*(int*)(this + 4) != -1) {
    //       DWORD last = *(DWORD*)(this + 216);
    //       unsigned elapsed = ticks - last;
    //       if (elapsed <= 0x493E0 && last && ticks >= last) {
    //         char retry = *(char*)(this + 232);
    //         if (retry > 0 && elapsed > 0x7530) {
    //           sub_562AC0(this, 0);
    //           retry = (char)(retry + 1);
    //           *(char*)(this + 232) = retry;
    //           if (retry > 10) *(char*)(this + 232) = 0;
    //         }
    //       } else {
    //         ticks = (DWORD)sub_562AC0(this, 0);
    //       }
    //     }
    //     return (char)ticks;
    //   }
    // UNRESOLVED: Semantics of the sub_562AC0 reset/resend action and its parameter (0) are not documented inside this function.
    // UNRESOLVED: Meaning of the identifier field at this+0x4 (socket/connection validity) is DERIVED from the -1 guard.
    // UNRESOLVED: Where and when the last-activity timestamp at this+0xD8 is written is not visible here.
}
