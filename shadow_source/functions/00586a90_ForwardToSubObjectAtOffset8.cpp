// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586A90
// Canonical corpus name: UtilityFunction_6a90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_6a90_00586a90.c

void UnknownObject::ForwardToSubObjectAtOffset8()
{
    // Trivial __thiscall forwarder: computes (this + 8), passes that pointer to callee sub_563E70, and returns the callee's result unchanged. Reads no fields itself and performs no other work.
    // CALCULATION: Compute the object pointer argument as (this + 8). [source:raw]
    // CALL: Call callee sub_563E70 with the derived (this + 8) pointer. [source:raw]
    // RETURN: Return the result of sub_563E70 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_586A90(int this) {
    //       return sub_563E70((void *)(this + 8));
    //   }
    // UNRESOLVED: Purpose and semantics of callee sub_563E70 are not evidenced in this packet.
    // UNRESOLVED: What object lives at (this + 8) and which owner class owns it is unknown.
    // UNRESOLVED: Why callers sub_584230 and sub_587730 invoke this forwarder is unresolved.
    // UNRESOLVED: Whether this+8 points to a member sub-object or a stored delegate is not evidenced.
}
