// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004998E0
// Canonical corpus name: sub_4998E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4998E0_004998e0.c

void UnknownObject::StateListSetupWithFallback()
{
    // Object/list setup with fallback. Initializes the receiver via SmallStructInit (0x00499850), then stores a2 into the object field at dword index 3. When a2 is non-zero, clears the field at dword index 0, reads a dword from a2+28 into field index 2, zeroes field indices 4 and 5, and if that read dword is zero falls back to sub_499910 (0x00499910) on the object. Returns the read dword (or a2 when a2 is zero). Called by RenderingContextSetup (0x00497750).
    // CALL: SmallStructInit (0x00499850) initializes the receiver object [callee:0x00499850, source:raw]
    // ASSIGNMENT: Object field at dword index 3 is set to a2 [source:raw]
    // GUARD: The rest of the setup runs only when a2 is non-zero [source:raw]
    // ASSIGNMENT: Object field at dword index 0 is cleared to 0 [source:raw]
    // ASSIGNMENT: Dword read from a2+28 is stored into object field at dword index 2 [source:raw]
    // ASSIGNMENT: Object fields at dword indices 4 and 5 are cleared to 0 [source:raw]
    // STATE_TRANSITION: When the dword read from a2+28 is zero, control falls through to sub_499910 (0x00499910) on the object instead of returning the read value [callee:0x00499910, source:raw]
    // RETURN: Returns the dword read from a2+28 when a2 is non-zero and the read is non-zero; returns a2 (zero) otherwise [source:raw]
    // CALL: Invoked by RenderingContextSetup (0x00497750), consistent with per-context state-list wiring [caller:0x00497750, source:raw]

    // Conservative worker pseudocode:
    //   SmallStructInit(this);
    //   obj[3] = a2;
    //   if (a2) {
    //       obj[0] = 0;
    //       result = *(a2 + 28);
    //       obj[2] = result;
    //       obj[4] = 0;
    //       obj[5] = 0;
    //       if (!result)
    //           return sub_499910(obj);
    //   }
    //   return result;
    // UNRESOLVED: The decompiler leaves v2 unassigned while all object field writes go through it; the writes are assumed to target the same object that SmallStructInit initializes, but that identity is not proven
    // UNRESOLVED: The layout of the object behind the dword indices (0, 2, 3, 4, 5) and the meaning of the a2+28 dword are not established from this packet
}
