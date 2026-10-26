// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DA080
// Canonical corpus name: TimerValueComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerValueComparison_004da080.c

void UnknownObject::TimerValueComparison()
{
    // Reference time validation check. Requires the gap float at this+0x14 to be non-negative and the stored reference time at this+0x1C to be non-zero, then compares that stored value against the current player vehicle pointer (dword_7C54E0) at offset 16592 or 16596 depending on the type flag byte at this+0x18. Returns 1 on a matching comparison, otherwise 0. Called by sub_4D9F80.
    // GUARD: Gap guard: the float at this+0x14 must be >= 0.0 for validation to proceed; otherwise the function returns 0 without comparing [field:this:0x00000014, source:raw]
    // CALCULATION: Load the stored reference time value v1 from this+0x1C (dword) [field:this:0x0000001C, source:raw]
    // GUARD: Non-zero guard on the stored reference time v1: a zero value blocks the comparison and returns 0 [field:this:0x0000001C, source:raw]
    // GUARD: Type-flag branch on the byte at this+0x18: non-zero selects the vehicle+16592 comparison slot, zero selects vehicle+16596 [field:this:0x00000018, source:raw]
    // CALCULATION: Compare v1 against *(dword_7C54E0 + 16592), the first comparison slot of the current player vehicle pointer [global:0x007C54E0, source:raw]
    // CALCULATION: Compare v1 against *(dword_7C54E0 + 16596), the second comparison slot of the current player vehicle pointer [global:0x007C54E0, source:raw]
    // RETURN: Returns 1 when the selected comparison matches, otherwise 0; called by sub_4D9F80 [function:0x004DA080, caller:0x004D9F80, source:raw]

    // Conservative worker pseudocode:
    //   if (*(float*)(this + 0x14) < 0.0) return 0;
    //   v1 = *(_DWORD*)(this + 0x1C);
    //   if (v1 == 0) return 0;
    //   if (*(_BYTE*)(this + 0x18) != 0) return v1 == *(_DWORD*)(dword_7C54E0 + 16592);
    //   return v1 == *(_DWORD*)(dword_7C54E0 + 16596);
    // UNRESOLVED: flt_59E440 is listed as a referenced global by the packet but the raw source compares this+0x14 only against a literal 0.0; the existing analysis labels it a zero threshold (DERIVED) and its exact role is not provable from this packet alone
    // UNRESOLVED: The type-flag semantics of the byte at this+0x18 (which comparison slot is selected) follow the existing analysis and are DERIVED; the raw source only shows the branch on the byte
    // UNRESOLVED: Owner object identity and the purpose of the reference time slots at vehicle+16592/16596 are not established by this packet
}
