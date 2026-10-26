// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059508D
// Canonical corpus name: sub_59508D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59508D_0059508d.c

void UnknownObject::MaskedBitFieldMerge()
{
    // One-statement wrapper: AND-masks the second argument with 0xFFF7FFFF, then returns BitFieldMaskMerge (0x00595058) applied to the first argument and the masked second argument. No guards, no globals, no locals. Only recorded caller is TwoArgCallWrapper (0x0058BC56).
    // CALCULATION: Compute a2 AND 0xFFF7FFFF, clearing the bit positions masked out by that constant before the merge [source:raw, function:0x0059508D]
    // CALL: Call BitFieldMaskMerge (0x00595058) with a1 and the masked a2 value [callee:0x00595058, source:raw]
    // RETURN: Return the result of BitFieldMaskMerge directly to the caller [function:0x0059508D, source:raw]
    // CALL: Invoked by TwoArgCallWrapper (0x0058BC56), the only recorded caller, which supplies the two arguments [caller:0x0058BC56]

    // Conservative worker pseudocode:
    //   return BitFieldMaskMerge(a1, a2 & 0xFFF7FFFF);
    // UNRESOLVED: The meaning of the bit cleared by mask 0xFFF7FFFF inside a2 is unknown; the masked-out flag is never read in this function
    // UNRESOLVED: BitFieldMaskMerge's exact merge policy (which argument wins on conflicting bits) is not evidenced here
    // UNRESOLVED: The owning object or module is unknown
}
