// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052DF90
// Canonical corpus name: CPUIDFeatureCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CPUIDFeatureCheck_0052df90.c

void UnknownObject::CPUIDFeatureCheck()
{
    // Boot-time CPU feature probe: executes the CPUID instruction with leaf EAX=1 and tests EDX bit 23 (mask 0x800000). Returns 1 when the feature bit is set and 0 otherwise. When the feature is present, clears the MMX state via _m_empty() before returning 1. Identified as the MMX support check by the existing analysis fill; the bit-23-as-MMX label itself is DERIVED.
    // CALCULATION: Select CPUID input leaf: set EAX to 1 (feature information leaf). [source:raw]
    // CALCULATION: Execute the CPUID instruction with EAX=1, reading the feature flags into EDX (and the other output registers). [source:raw]
    // GUARD: Test the feature bit: when (EDX & 0x800000) == 0 (mask rendered by the decompiler as the unk_800000 constant at 0x00800000), take the early failure path. [global:0x00800000, source:raw]
    // RETURN: Return 0 when the tested feature bit is clear. [source:raw]
    // CALL: Clear the MMX state via _m_empty() (empty MMX/FP multimedia state) before the success return. [source:raw]
    // RETURN: Return 1 when the feature bit is set. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_52DF90() {
    //     _EAX = 1;
    //     __asm { cpuid }
    //     if (((unsigned int)&unk_800000 & _EDX) == 0) return 0;
    //     _m_empty();
    //     return 1;
    //   }
    // UNRESOLVED: The packet lists reads of globals ScriptFrameProcessor (0x0058895C) and stru_5B47F8 (0x005B47F8), but the raw source text renders no explicit reference to either; they are fill/analysis artifacts and no semantic role can be grounded here.
    // UNRESOLVED: The four TEB-range globals (0xFF00000000001692 read, 0xFF00000000001695 write, 0xFF00000000001699 read/write, 0xFF0000000000169B read/write) do not appear in the raw source; they are compiler SEH/TEB magic and carry no evidenced semantic role.
    // UNRESOLVED: Bit 23 of CPUID.1:EDX is identified as the MMX flag by the existing analysis fill; the feature label is DERIVED, not independently proven.
    // UNRESOLVED: The object or subsystem owning this probe is unknown.
}
