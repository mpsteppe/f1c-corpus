// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406640
// Canonical corpus name: ConditionalMatchTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalMatchTrigger_00406640.c

void UnknownObject::ConditionalMatchTrigger()
{
    // Conditional mutex trigger. Reads the DWORD at this+0xC (index 3); if it equals the argument a2 it acquires a mutex (MutexLockWithTimeout(1)) and returns the lock result; otherwise returns the field value unchanged. Despite the DERIVED 'getter' prelabel, raw source shows a guarded mutex-acquire side effect, so this is not a pure getter.
    // CALCULATION: Read field this[3] (this+0xC) into result. [field:this:0x0000000C, source:raw]
    // GUARD: Branch: if result == a2, take the mutex path; otherwise fall through to return the field value. [field:this:0x0000000C, source:raw]
    // CALL: MutexLockWithTimeout(1): acquire a mutex with the literal argument 1 and return its result. [source:raw]
    // RETURN: Return the unmodified field value this+0xC when it does not match a2. [field:this:0x0000000C, source:raw, function:0x00406640]

    // Conservative worker pseudocode:
    //   result = this->field0xC;
    //   if (result == a2) return MutexLockWithTimeout(1);
    //   return result;
    // UNRESOLVED: MutexLockWithTimeout is named in raw source but has no callee address evidence in the packet, so it is described from source text only.
    // UNRESOLVED: Whether this+0xC is a mutex handle/id to compare against, or a state token, is unconfirmed.
    // UNRESOLVED: Owner object identity is not established by the packet.
    // UNRESOLVED: The DERIVED prelabel 'getter / no side effects' is contradicted by the guarded MutexLockWithTimeout call; raw source outranks the prelabel.
}
