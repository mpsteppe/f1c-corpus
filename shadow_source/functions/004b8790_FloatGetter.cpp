// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8790
// Canonical corpus name: FloatGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatGetter_004b8790.c

void UnknownObject::FloatGetter()
{
    // Trivial thiscall getter with no side effects and no branches: reads element index 974 of the float array referenced by this (byte displacement 974 * 4 = 0xF38, field read R) and returns it as double. Prelabel template classifies it as a getter returning field 0xF38. Called by eight helpers in the same module (StateTriggerCheck, Delegation, FloatAccumulator, ConditionalMultiPathDispatcher, and four sub_* neighbors), so it is a shared field-accessor on a per-object float field.
    // CALCULATION: Element index 974 of a float array resolves to byte offset 0xF38 (974 * 4), the field identified by the packet as read-only [field:this:0x00000F38, source:raw]
    // RETURN: Returns this[974] (field +0xF38) as double; no writes, no calls, no branches [field:this:0x00000F38, function:0x004B8790, source:raw]

    // Conservative worker pseudocode:
    //   return (double)this[974];  // byte offset 0xF38
    // UNRESOLVED: The return type is double but the read is an element of a float array: whether +0xF38 holds a true double member or two adjacent floats re-read as 8 bytes is unresolved
    // UNRESOLVED: The owning object and what element 974 / offset 0xF38 represents in that object are unresolved
}
