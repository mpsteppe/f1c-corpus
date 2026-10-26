// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004987B0
// Canonical corpus name: CollisionResponseTypeClassification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResponseTypeClassification_004987b0.c

void UnknownObject::CollisionResponseTypeClassification()
{
    // Collision response-type classifier over a __thiscall object (decompiled as float* this; most field accesses use the alias v1 = ecx). Accumulates FloatFieldAccessor(this) (0x00498730) into a running float at byte offset 200, then selects a small integer response code from a chain of flag checks on the dword fields at byte offsets 100/104/108/112 and companion flags at 132/136/140. Some branches also overwrite the offset-200 accumulator with 0 or the literal 1059481191. Returns the selected code; the offset-112 field yields 12/13 when set.
    // CALL: Call FloatFieldAccessor(this) (0x00498730); the returned double v2 seeds the accumulator. [callee:0x00498730, source:raw]
    // CALCULATION: Compute v3 = v2 + float at v1+200 (running accumulation into the offset-200 float field). [source:raw]
    // CALCULATION: Read v4 = dword at v1+100 (first classification flag). [source:raw]
    // ASSIGNMENT: Store v3 (as float) back into v1+200, updating the accumulator unconditionally. [source:raw]
    // GUARD: When v4 is nonzero, test dword at v1+132: if set, response v5 = 5; otherwise v5 = 1 and, when v3 exceeds the 0.55 threshold (0x0059E970), zero the dword at v1+200, else set v5 = 2 and store literal 1059481191 into v1+200. [global:0x0059E970, source:raw]
    // GUARD: Else (v4 == 0): v5 = 4 - (dword at v1+132 != 0), yielding 3 or 4 depending on the offset-132 flag. [source:raw]
    // CALCULATION: Read v6 = dword at v1+136; when dword at v1+104 is set, override v5 = 2 * (v6 != 0) + 9 (9 or 11), else when v6 is set override v5 = 10. [source:raw]
    // CALCULATION: Read v7 = dword at v1+140; when dword at v1+108 is set, override v5 = 2 * (v7 != 0) + 6 (6 or 8), else when v7 is set override v5 = 7. [source:raw]
    // GUARD: Read v8 = dword at v1+112; if set, return (v8 <= 0) + 12 (12 or 13), otherwise return the accumulated v5. [function:0x004987B0, source:raw]
    // CALL: Invoked from UILargeRender (0x00496930) as the sole caller. [caller:0x00496930]

    // Conservative worker pseudocode:
    //   int CollisionResponseTypeClassification(float *this) {
    //     double v3 = FloatFieldAccessor(this) + *(float *)((char *)this + 200);
    //     int v4 = *(_DWORD *)((char *)this + 100);
    //     *(float *)((char *)this + 200) = v3;
    //     int v5;
    //     if (v4) {
    //       if (*(_DWORD *)((char *)this + 132)) v5 = 5;
    //       else {
    //         v5 = 1;
    //         if (v3 > flt_59E970) *(_DWORD *)((char *)this + 200) = 0;
    //         else { v5 = 2; *(_DWORD *)((char *)this + 200) = 1059481191; }
    //       }
    //     } else {
    //       v5 = 4 - (*(_DWORD *)((char *)this + 132) != 0);
    //     }
    //     if (*(_DWORD *)((char *)this + 104)) v5 = 2 * (*(_DWORD *)((char *)this + 136) != 0) + 9;
    //     else if (*(_DWORD *)((char *)this + 136)) v5 = 10;
    //     if (*(_DWORD *)((char *)this + 108)) v5 = 2 * (*(_DWORD *)((char *)this + 140) != 0) + 6;
    //     else if (*(_DWORD *)((char *)this + 140)) v5 = 7;
    //     if (*(_DWORD *)((char *)this + 112)) return (*(_DWORD *)((char *)this + 112) <= 0) + 12;
    //     return v5;
    //   }
    // UNRESOLVED: Decompiler shows v1 (ecx) uninitialized; under __thiscall the ecx alias is expected to be `this`, so all v1+offset accesses are treated as this-object accesses, but this is not independently verified.
    // UNRESOLVED: The packet field list is empty, so the offsets read here (100/104/108/112/132/136/140/200, decimal per raw source) carry no deterministic names; their meaning (flags and a running float) is inferred from raw source only.
    // UNRESOLVED: Literal 1059481191 stored as a dword into the offset-200 float field is not decoded to a float value, per policy of not synthesizing IEEE-754 bit patterns.
    // UNRESOLVED: flt_59E970 (0x0059E970) is read per the packet; its association with the 0.55 comparison threshold is inferred (DERIVED), not stated by the packet.
    // UNRESOLVED: The mapping of returned codes (1..13) to collision response types is unconfirmed; the ABI lead name is legacy.
}
