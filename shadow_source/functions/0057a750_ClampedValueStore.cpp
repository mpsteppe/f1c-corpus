// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A750
// Canonical corpus name: SingleFunctionCallWrapper_a750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_a750_0057a750.c

void UnknownObject::ClampedValueStore()
{
    // Dereferences the context pointer a1 to obtain an object base, computes a reference value by calling sub_587890(base + 300, a2), then stores min(a3, computed result) at obj+128 and returns the computed result. Acts as a clamp/saturate store with the caller's requested value a3 capped by the computed reference.
    // ASSIGNMENT: Read the context pointer a1 and dereference it to get the object base v3 = *a1. [source:raw, field:this:0x00000000]
    // CALCULATION: Form the argument to the helper: base + 300. [source:raw]
    // CALL: Call sub_587890(base + 300, a2) and store its return value as result. [source:raw]
    // GUARD: Branch on whether the caller's value a3 is at most the computed result (a3 <= result); this is a value clamp, not a control-flow guard. [source:raw]
    // ASSIGNMENT: Store the clamped value at obj+128: a3 when a3 <= result, otherwise result (i.e. min(a3, result)). [source:raw, field:obj:0x00000080]
    // RETURN: Return the computed result from sub_587890 regardless of which value was stored. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_57A750(int *ctx, int a2, int a3) {
    //     int base = *ctx;
    //     int result = sub_587890(base + 300, a2);
    //     *(int *)(base + 128) = (a3 <= result) ? a3 : result;
    //     return result;
    //   }
    // UNRESOLVED: Identity and semantics of the helper sub_587890 and of its a2 argument are unknown here.
    // UNRESOLVED: Meaning of the stored field obj+128 (a clamped cap or limit) depends on the owning object, which is unknown.
    // UNRESOLVED: The caller is SessionTypeSetter (0x00463F70); the meaning of a3 relative to session configuration is unresolved.
}
