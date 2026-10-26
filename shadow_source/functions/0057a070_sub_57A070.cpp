// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A070
// Canonical corpus name: StringCopyWithBytewiseORTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithBytewiseORTransform_0057a070.c

void UnknownObject::sub_57A070()
{
    // Copies 9 bytes from a2 into the this buffer via sub_587DD0, then ORs each of the first four bytes with a byte sourced from an address derived from argument a4 (the decompiler renders the source index as v6[&a4 - this]), then copies 4 bytes from a3 into this+16 via sub_587DD0 and returns that call's result. The bytewise OR transform is confirmed by the raw source; the caller and the purpose of the transform are unknown.
    // CALL: sub_587DD0(this, a2, 9) — copy 9 bytes from a2 into the this buffer [callee:0x00587DD0, field:this:0x00000000, source:raw]
    // LOOP: do { *v6 |= v6[&a4 - this]; ++v6; --v7; } while (v7) — four iterations OR each of the first four bytes of this with a byte read from an address computed from the a4 argument location [field:this:0x00000000, source:raw]
    // RETURN: return sub_587DD0(this + 16, a3, 4) — copy 4 bytes from a3 into this+16 and return the call's result [callee:0x00587DD0, field:this:0x00000000, function:0x0057A070, source:raw]

    // Conservative worker pseudocode:
    //   sub_587DD0(this, a2, 9);
    //   v6 = this;
    //   v7 = 4;
    //   do { *v6 |= v6[&a4 - this]; ++v6; --v7; } while (v7);
    //   return sub_587DD0(this + 16, a3, 4);
    // UNRESOLVED: Base address of the OR source (rendered as &a4 - this) is not fully resolved; the indexed source is this[i] + &a4 - this, i.e. relative to the a4 argument home.
    // UNRESOLVED: Purpose of the bytewise OR transform is unknown; StringCopyWithBytewiseORTransform is a DERIVED cluster-copy name from structural twin 0040d470.
    // UNRESOLVED: Semantics of sub_587DD0 (called with lengths 9 and 4) are unknown.
    // UNRESOLVED: Relationship to the single caller 0x0057A040 and the unused parameter a5 is unknown.
}
