// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BA50
// Canonical corpus name: FuelWeightComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FuelWeightComputation_0049ba50.c

void UnknownObject::FuelWeightComputation()
{
    // Boolean fuel-weight check in the pit subsystem: returns whether the fuel quantity dword_7D0B64 converted to weight (multiplied by 0.050000001) exceeds the product of two floats read from the structure pointed to by dword_7C54E0 at offsets 14724 and 14732. When dword_7D0B64 is not positive the function returns false without computing. ABI lead name Fuel_Weight_Computation; consumed as a boolean by three callers (sub_49D4C0, HUDFlagRendererMain, UIMessageCompose).
    // GUARD: If dword_7D0B64 <= 0, skip the computation and return false; the weight comparison only runs when the fuel quantity is positive. [global:0x007D0B64, source:raw]
    // CALCULATION: Convert the integer fuel quantity dword_7D0B64 to a weight by casting to double and multiplying by the constant 0.050000001. [global:0x007D0B64, source:raw]
    // CALCULATION: Read two floats from the structure pointed to by dword_7C54E0 at byte offsets 14724 and 14732 and multiply them together to form the comparison threshold. [global:0x007C54E0, source:raw]
    // RETURN: Return whether the computed fuel weight is greater than the product of the two floats; return false when dword_7D0B64 is not positive. [source:raw]

    // Conservative worker pseudocode:
    //   bool FuelWeightComputation() {
    //       if (dword_7D0B64 <= 0) return false;
    //       return (double)dword_7D0B64 * 0.050000001 >
    //              *(float *)(dword_7C54E0 + 14724) * *(float *)(dword_7C54E0 + 14732);
    //   }
    // UNRESOLVED: flt_59E448 (0x0059E448) is listed as a read global but does not appear in the raw source text; it may be where the compiler stored the 0.050000001 factor or another constant, but that link is not evidenced in the packet.
    // UNRESOLVED: Offsets 14724 and 14732 from the base pointer dword_7C54E0 are dereferenced as floats but the packet records no field names for them.
    // UNRESOLVED: The three callers (sub_49D4C0, HUDFlagRendererMain, UIMessageCompose) consume the boolean result; their exact HUD/UI usage is not described by the packet.
    // UNRESOLVED: Owner is unknown; the raw source has no this pointer and no owning class is evidenced.
}
