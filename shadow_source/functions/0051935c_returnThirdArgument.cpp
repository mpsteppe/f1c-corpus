// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051935C
// Canonical corpus name: ShortComputation_935c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_935c_0051935c.c

void UnknownObject::returnThirdArgument()
{
    // Trivial passthrough that returns its third argument unchanged; the first two arguments are unused. Single caller is DirectXTextureSurfaceAllocation (0x0051629F).
    // RETURN: return argument a3 unchanged; arguments a1 and a2 are accepted but never read [source:raw, function:0x0051935C]

    // Conservative worker pseudocode:
    //   int returnThirdArgument(int a1, int a2, int a3) { return a3; }
    // UNRESOLVED: Why a1 and a2 are accepted but unused is unknown; this may be a stub or a tail-end of a larger interface
    // UNRESOLVED: How the returned a3 value is used by the caller DirectXTextureSurfaceAllocation is not inferable from this function alone
}
