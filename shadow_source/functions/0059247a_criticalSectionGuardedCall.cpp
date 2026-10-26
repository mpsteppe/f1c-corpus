// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059247A
// Canonical corpus name: CriticalSectionGuardedCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CriticalSectionGuardedCall_0059247a.c

void UnknownObject::criticalSectionGuardedCall()
{
    // Critical-section guarded call wrapper: enter critical section 11 via CriticalSectionLazyInitEnter(11), run the guarded inner call sub_59249B(a1), leave critical section 11 via CritSectLeave(11), and return the inner result. The critical-section id 11 is a fixed decimal literal shared by the enter/leave pair.
    // CALL: Enter (lazily initializing) critical section id 11 with CriticalSectionLazyInitEnter(11) to begin the guarded region. [callee:0x0058DFEA, source:raw]
    // CALL: Run the guarded inner call: v1 = sub_59249B(a1), forwarding a1 unchanged; v1 holds the result returned to the caller. [callee:0x0059249B, source:raw]
    // CALL: Leave critical section id 11 with CritSectLeave(11) after the guarded inner call completes. [callee:0x0058E04B, source:raw]
    // CALL: Used by sub_589E6C and sub_591EDF as a shared guarded-call primitive; the caller evidence does not resolve the meaning of a1. [caller:0x00589E6C, caller:0x00591EDF]
    // RETURN: Return v1, the inner sub_59249B result, unchanged after the critical section is left. [source:raw, function:0x0059247A]

    // Conservative worker pseudocode:
    //   int criticalSectionGuardedCall(int a1) {
    //     int result;
    //     CriticalSectionLazyInitEnter(11);
    //     result = sub_59249B(a1);
    //     CritSectLeave(11);
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the fixed critical-section id 11 and which resource it guards is not established from this packet.
    // UNRESOLVED: sub_59249B's body is not in this packet; the guarded operation's semantics and the meaning of a1 are unknown.
}
