// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B903
// Canonical corpus name: SemaphoreGuardedQueryCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SemaphoreGuardedQueryCall_0058b903.c

void UnknownObject::SemaphoreGuardedQueryCall()
{
    // Critical-section-guarded query wrapper: enters a lazily-initialized critical section (key 12), calls sub_58B92A(0, a1, a2) to perform the guarded query, leaves the section, and returns the query result.
    // CALL: CriticalSectionLazyInitEnter(12): lazily initializes and enters the critical section identified by key 12. [callee:0x0058DFEA]
    // CALL: sub_58B92A(0, a1, a2): performs the query protected by the critical section; return value held in v2. [callee:0x0058B92A]
    // CALL: CritSectLeave(12): leaves the critical section identified by key 12 before returning. [callee:0x0058E04B]
    // RETURN: Returns the query result v2 from sub_58B92A. [source:raw]

    // Conservative worker pseudocode:
    //   CriticalSectionLazyInitEnter(12);
    //   result = sub_58B92A(0, a1, a2);
    //   CritSectLeave(12);
    //   return result;
    // UNRESOLVED: Meaning of the critical-section key value 12 is unresolved.
    // UNRESOLVED: Nature of the guarded sub_58B92A query and the role of its first argument 0 are unresolved.
    // UNRESOLVED: Caller context (sub_565F80) is unknown; owner class is unknown.
}
