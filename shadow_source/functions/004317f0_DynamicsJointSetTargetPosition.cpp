// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004317F0
// Canonical corpus name: DynamicsJointSetTargetPosition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynamicsJointSetTargetPosition_004317f0.c

void UnknownObject::DynamicsJointSetTargetPosition()
{
    // Computes a pointer into this at 4-byte-element index 4*a3+7336 and passes it as the second argument to sub_565870, with a4 as first argument and seven zero constants as the remaining arguments; returns sub_565870's result. Indexing pattern is consistent with a joint target-position array, but the callee's semantics are not evidenced in this packet.
    // CALCULATION: Computes the address &this[4 * a3 + 7336], treating this as an array of 4-byte elements with base index 7336 offset by a3. [function:0x004317F0, source:raw]
    // CALL: Calls sub_565870(a4, &this[4 * a3 + 7336], 0, 0, 0, 0, 0, 0, 0) and returns its integer result. [abi:lead, callee:0x00565870, source:raw]

    // Conservative worker pseudocode:
    //   int DynamicsJointSetTargetPosition(char *this, int a2, int a3, int a4) {
    //       return sub_565870(a4, &this[4 * a3 + 7336], 0, 0, 0, 0, 0, 0, 0);
    //   }
    // UNRESOLVED: sub_565870 behavior unknown; cannot confirm joint/target-position semantics from this packet alone.
    // UNRESOLVED: a2 is not referenced in the body.
    // UNRESOLVED: No field evidence recorded in packet, so the indexed region 7336*4..(7336+4*a3)*4 is left unnamed.
}
