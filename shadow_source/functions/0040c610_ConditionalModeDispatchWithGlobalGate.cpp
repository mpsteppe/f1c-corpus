// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C610
// Canonical corpus name: ConditionalModeDispatchWithGlobalGate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalModeDispatchWithGlobalGate_0040c610.c

void UnknownObject::ConditionalModeDispatchWithGlobalGate()
{
    // Conditional camera-mode dispatch gated by the global dword_7CFCC8 (0x007CFCC8, queued-mode flag). When the flag is set, only a requested mode of 1 passes: it stores 1 into this+0x14 (this[5]) and returns GameActionStateMachine(2, 0); anything else returns 1 (blocked). When the flag is clear, requested modes 1 and 2 pass: the value is stored into this+0x14 (this[5]) and GameActionStateMachine(0, 0) is returned; anything else returns the requested mode this+0xC (this[3]) unchanged. Called from CameraViewAssignment (0x0040C650).
    // GUARD: Branch on the global dword_7CFCC8 (0x007CFCC8, queued-mode flag): non-zero selects the queued dispatch path, zero the immediate dispatch path. [global:0x007CFCC8, source:raw]
    // ASSIGNMENT: On the queued path, initialize result to 1 (the default blocked return value). [source:raw]
    // GUARD: Queued path: allow the dispatch only when the requested mode this[3] (offset 0xC) equals 1. [guard:0, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Queued path: store the dispatched mode 1 into this[5] (offset 0x14). [field:this:0x00000014, source:raw]
    // CALL: Queued path: return GameActionStateMachine(2, 0) (0x0040CDE0), dispatching mode 2 with the immediate flag clear. [callee:0x0040CDE0, source:raw]
    // ASSIGNMENT: Immediate path: initialize result to the requested mode this[3] (offset 0xC). [field:this:0x0000000C, source:raw]
    // GUARD: Immediate path: allow the dispatch only when the requested mode is 1 or 2. [source:raw]
    // ASSIGNMENT: Immediate path: store the requested mode value into this[5] (offset 0x14). [field:this:0x00000014, source:raw]
    // CALL: Immediate path: return GameActionStateMachine(0, 0) (0x0040CDE0), dispatching the mode with the immediate flag clear. [callee:0x0040CDE0, source:raw]
    // RETURN: Return result: 1 on the blocked queued path, the requested mode on the blocked immediate path, or the GameActionStateMachine result on a dispatch path. [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalModeDispatchWithGlobalGate(int* this) {
    //     if (dword_7CFCC8) {
    //       if (this[3] == 1) {
    //         this[5] = 1;
    //         return GameActionStateMachine(2, 0);
    //       }
    //       return 1;
    //     } else {
    //       int mode = this[3];
    //       if (mode == 1 || mode == 2) {
    //         this[5] = mode;
    //         return GameActionStateMachine(0, 0);
    //       }
    //       return mode;
    //     }
    //   }
    // UNRESOLVED: The writer and semantics of dword_7CFCC8 (queued-mode flag) are outside this packet; the queued/immediate distinction is DERIVED from its use.
    // UNRESOLVED: The mapping of the stored mode to the first argument of GameActionStateMachine (2 vs 0) and the meaning of its second argument are not grounded here.
    // UNRESOLVED: The caller context in CameraViewAssignment (0x0040C650) that determines when this dispatcher is invoked is outside this packet.
}
