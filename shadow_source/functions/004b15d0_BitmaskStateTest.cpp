// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B15D0
// Canonical corpus name: BitmaskStateTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmaskStateTest_004b15d0.c

void UnknownObject::BitmaskStateTest()
{
    // State-gated bitmask test. Returns true immediately when the state field at this+0x1F78 is not 5; otherwise returns whether bit (1 << a2) is set in the bitmask field at this+0x2AB4. Used as a per-frame predicate by AIShiftPattern and BrakeBiasSetup.
    // GUARD: Short-circuit guard on state field this+0x1F78 != 5; when true the function returns true without testing the bitmask. [field:this:0x00001F78, guard:0, source:raw]
    // CALCULATION: Build the single-bit mask (1 << a2) from the char argument a2. [source:raw]
    // CALCULATION: Test whether (1 << a2) & this+0x2AB4 is non-zero. [field:this:0x00002AB4, source:raw]
    // RETURN: Return the OR of the guard (state != 5) and the bitmask test result. [source:raw]

    // Conservative worker pseudocode:
    //   bool BitmaskStateTest(int* this, char bitIndex) {
    //     if (this[2014] != 5) return true;
    //     return ((1 << bitIndex) & this[2733]) != 0;
    //   }
    // UNRESOLVED: Meaning of the state value 5 and of the bitmask at this+0x2AB4 is caller/object specific and not established here.
    // UNRESOLVED: Semantic role of the bit index a2 depends on the calling AIShiftPattern / BrakeBiasSetup context.
}
