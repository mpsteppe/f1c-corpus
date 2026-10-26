// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD4E0
// Canonical corpus name: sub_4DD4E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DD4E0_004dd4e0.c

void UnknownObject::MaxChildClassIndex()
{
    // Iterates the scene-graph children of `this` and returns the maximum per-child classification value. Reads the child count via SceneGraphChildCount and fetches each child via LinkedListIndexedAccessor_c230. A child whose float at +244 is non-zero classifies as 0; a zero float classifies as 2 or 4 (minus one when bit 0x40 is set), depending on whether bit 0x2000000 of the dword at +20 is set. Returns the highest class seen, defaulting to 0. On frame path.
    // ASSIGNMENT: v1 = 0; initialize the running maximum. [function:0x004DD4E0, source:raw]
    // CALL: v2 = SceneGraphChildCount(this); query the number of children owned by this object. [callee:0x0054C210, function:0x004DD4E0, source:raw]
    // LOOP: for i in 0..v2-1: fetch each child and evaluate its class; v4 = LinkedListIndexedAccessor_c230(i). [callee:0x0054C230, function:0x004DD4E0, source:raw]
    // GUARD: If *(float*)(child+244) == 0.0 (zero constant sourced from flt_59E440), classify by flags; otherwise the child classifies as 0. Raw source documents the +244 float read. [global:0x0059E440, function:0x004DD4E0, source:raw]
    // CALCULATION: For the zero-float child: read flags dword at +20; if bit 0x2000000 set, v6 = 2 - (bit 0x40 set); else v6 = 4 - (bit 0x40 set). [function:0x004DD4E0, source:raw]
    // ASSIGNMENT: Else branch: v6 = 0 for children whose float at +244 is non-zero. [function:0x004DD4E0, source:raw]
    // ASSIGNMENT: If v6 > v1, v1 = v6; keep the maximum class value seen across all children. [function:0x004DD4E0, source:raw]
    // RETURN: Return the maximum child classification value v1. [function:0x004DD4E0, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   count = SceneGraphChildCount(this);
    //   for (i = 0; i < count; i++) {
    //     child = LinkedListIndexedAccessor_c230(i);
    //     if (*(float*)(child + 244) == 0.0) {
    //       flags = *(dword*)(child + 20);
    //       v = (flags & 0x2000000) ? 2 : 4;
    //       if (flags & 0x40) v--;
    //     } else v = 0;
    //     if (v > result) result = v;
    //   }
    //   return result;
    // UNRESOLVED: Meaning of classification values 0/1/2/3/4 (possible render/detail class) not grounded.
    // UNRESOLVED: Field offsets +244 and +20 on the child type have no packet field evidence; only the raw source documents them.
    // UNRESOLVED: flt_59E440 is treated as the 0.0 constant store, but its broader use is not confirmed.
    // UNRESOLVED: ABI recorded as PARTIAL_Unknown_4dd4e0 (LEGACY, __thiscall); prototype not confirmed.
}
