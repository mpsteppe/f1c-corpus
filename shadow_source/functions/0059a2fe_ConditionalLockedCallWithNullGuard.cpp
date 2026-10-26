// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A2FE
// Canonical corpus name: sub_59A2FE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A2FE_0059a2fe.c

void UnknownObject::ConditionalLockedCallWithNullGuard()
{
    // Conditional delegate call guarded by a member pointer. Reads this+0x50; when nonzero, invokes LockCallUnlockWrapper(this+0x50) and returns -1 if that call reports failure (result < 0), otherwise returns 0. Structural twin of ConditionalDelegateCallWithNullGuard (00599232) per the DERIVED cluster prelabel, which also names the lock wrapper as the delegate callee.
    // GUARD: Read this[20] (this+0x50); if nonzero, proceed to the wrapped call, otherwise skip straight to the success return. [field:this:0x00000050, source:raw]
    // CALL: Call LockCallUnlockWrapper(this+0x50) with the gated member as its argument; interpret a result < 0 as failure. [callee:0x00589FFD, field:this:0x00000050, source:raw]
    // RETURN: Return -1 when the wrapped call returned a negative value, 0 otherwise (null member also yields 0). [function:0x0059A2FE, source:raw]

    // Conservative worker pseudocode:
    //   if (this->member_0x50 != 0) {
    //     if (LockCallUnlockWrapper(this->member_0x50) < 0) return -1;
    //   }
    //   return 0;
    // UNRESOLVED: Semantics of the -1 return (error signal vs. cancel) are inferred from the comparison against 0 only.
    // UNRESOLVED: Owner object identity is not established by the packet.
    // UNRESOLVED: The DERIVED prelabel names this a structural twin of ConditionalDelegateCallWithNullGuard (00599232); the twin relationship is cluster-derived, not independently confirmed here.
}
