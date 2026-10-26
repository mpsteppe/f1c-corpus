// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047AB35
// Canonical corpus name: AIOvertakeGapCalc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIOvertakeGapCalc_0047ab35.c

void UnknownObject::AIOvertakeGapCalc()
{
    // AI overtake gap calculation over an array object a4 (likely a per-AI-car state). Stores the input a1 into a4[60], computes a gap into a4[64] from a virtual call on a2 minus twice a4[62] minus the saved a4[3], then computes a4[69] from virtual calls at offsets 36 and 28 of the object, applying a threshold fallback and always returning 0.
    // ASSIGNMENT: Save the dword at index 3 of a4 into local v4. [source:raw]
    // ASSIGNMENT: Store the first argument a1 into dword index 60 of a4. [source:raw]
    // CALL: Invoke the virtual method at byte offset 24 of the object a2, passing a4. [source:raw]
    // CALCULATION: Store into dword index 64 of a4: virtual-call result minus twice a4[62] minus the saved a4[3]. [source:raw]
    // GUARD: Guard on ConditionalDelegation_6460(3); branch selects the fallback gap value. [callee:0x00486460, source:raw]
    // ASSIGNMENT: When the delegation check is true, set a4[70] to 20; otherwise set a4[70] to a3. [source:raw]
    // CALL: Invoke the virtual method at byte offset 36 of the object pointed to by a4's vtable. [source:raw]
    // CALCULATION: Compute v5 as the offset-36 virtual-call result minus a4[70]. [source:raw]
    // CALL: Invoke the virtual method at byte offset 28 of the object pointed to by a4's vtable. [source:raw]
    // CALCULATION: Compute v6 as v5 minus the offset-28 virtual-call result. [source:raw]
    // ASSIGNMENT: Store v6 into dword index 69 of a4. [source:raw]
    // GUARD: Guard on v6 being negative; a negative gap is invalid. [source:raw]
    // ASSIGNMENT: When v6 is negative, overwrite a4[69] with the fallback a3. [source:raw]
    // RETURN: Return constant 0. [source:raw]

    // Conservative worker pseudocode:
    //   int AIOvertakeGapCalc(int a1, void* a2, int a3, _DWORD* a4) {
    //     int v4 = a4[3];
    //     a4[60] = a1;
    //     a4[64] = (*(int (__thiscall **)(_DWORD*))(a2 + 24))(a4) - 2 * a4[62] - v4;
    //     a4[70] = ConditionalDelegation_6460(3) ? 20 : a3;
    //     int v5 = (*(int (__thiscall **)(_DWORD*))(*a4 + 36))(a4) - a4[70];
    //     int v6 = v5 - (*(int (__thiscall **)(_DWORD*))(*a4 + 28))(a4);
    //     a4[69] = v6;
    //     if (v6 < 0) a4[69] = a3;
    //     return 0;
    //   }
    // UNRESOLVED: Type and layout of array object a4; semantics of the stored dword indices 3, 60, 62, 64, 69, 70 are class-specific and not defined here.
    // UNRESOLVED: Identity and semantics of the virtual methods at byte offsets 24, 28 and 36 are unknown.
    // UNRESOLVED: Meaning of the threshold constant 20 and the fallback value a3 in the gap calculation is unknown.
}
