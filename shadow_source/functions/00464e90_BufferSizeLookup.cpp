// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464E90
// Canonical corpus name: BufferSizeLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferSizeLookup_00464e90.c

void UnknownObject::BufferSizeLookup()
{
    // Buffer size lookup: maps the selector a1 to a fixed buffer size through a switch dispatched via the jump table at 0x00464ECC. a1 == 1 yields 2975, a1 == 2 yields 7200, a1 == 3 yields 28800, a1 == 4 yields 625000, and any other value yields the default 1487. Called by ConditionalDelegateBasedOnCounter (00464EE0) and ShortComputation_5430 (00465430) to size a buffer.
    // GUARD: Switch on the selector a1, dispatching through the jump table global at 0x00464ECC. [global:0x00464ECC, source:raw]
    // ASSIGNMENT: Case a1 == 1: result = 2975. [source:raw]
    // ASSIGNMENT: Case a1 == 2: result = 7200. [source:raw]
    // ASSIGNMENT: Case a1 == 3: result = 28800. [source:raw]
    // ASSIGNMENT: Case a1 == 4: result = 625000. [source:raw]
    // ASSIGNMENT: Default case: result = 1487. [source:raw]
    // RETURN: Return the looked-up buffer size. [source:raw]
    // CALL: Invoked by ConditionalDelegateBasedOnCounter (00464EE0) and ShortComputation_5430 (00465430) to obtain a buffer size for a given selector. [caller:0x00464EE0, caller:0x00465430, source:raw]

    // Conservative worker pseudocode:
    //   int sub_464E90(int selector) {
    //     switch (selector) {
    //       case 1: return 2975;
    //       case 2: return 7200;
    //       case 3: return 28800;
    //       case 4: return 625000;
    //       default: return 1487;
    //     }
    //   }
    // UNRESOLVED: The semantic meaning of the selector a1 and which buffers the returned sizes describe are not determinable from this function alone.
    // UNRESOLVED: The jump table global at 0x00464ECC is read for dispatch but its full layout is outside this function.
}
