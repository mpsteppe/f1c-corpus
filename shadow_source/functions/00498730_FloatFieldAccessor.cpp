// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498730
// Canonical corpus name: FloatFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFieldAccessor_00498730.c

void UnknownObject::FloatFieldAccessor()
{
    // Trivial __thiscall getter: reads float at this[48] (byte offset 0xC0) and returns it widened to double. No side effects, no branches, no callees.
    // RETURN: Read this[48] (float at byte offset 0xC0) and return it as a double. [field:this:0x000000C0, source:raw]

    // Conservative worker pseudocode:
    //   double FloatFieldAccessor(float* this) {
    //     return (double)this[48];   // float at byte offset 0xC0
    //   }
    // UNRESOLVED: The meaning of the float field at offset 0xC0 (what quantity the getter exposes) is not established by the packet.
    // UNRESOLVED: The owner type is unknown; the field is a float array element of some object that is read but never written by this function.
    // UNRESOLVED: The prelabel trusts this as a template getter with no side effects; only the 13 callers were recorded, not their usage of the value.
}
