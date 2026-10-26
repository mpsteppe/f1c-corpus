// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D880
// Canonical corpus name: FieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldAccessor_0053d880.c

void UnknownObject::GetField8()
{
    // Thiscall getter with no side effects: returns the dword at byte offset 0x8 of this (field index 2) as an int. Matches the packet prelabel classification as a getter (DERIVED). Callers span rendering and memory-copy paths (RenderingContextSetup 0x00497750, sub_55BE80 0x0055BE80, StructuredMemoryCopyWithHeaderPrepend 0x0057D5D0, BoundedMemoryCopyWithSizeValidation 0x00586A10, sub_587120 0x00587120, DualQueryIntoTwoOutputParams 0x005871C0, AddConstantWrapper 0x00587250), so the owning class is not established.
    // CALCULATION: Read the dword at byte offset 0x8 of this (index this[2]) [field:this:0x00000008, source:raw]
    // RETURN: Return the field value at this+0x8 as an int [field:this:0x00000008, function:0x0053D880, source:raw]

    // Conservative worker pseudocode:
    //   int GetField8() {
    //     return this[2];
    //   }
    // UNRESOLVED: The owning class of this and the meaning of the field at offset 0x8 are unknown.
    // UNRESOLVED: Equal offset 0x8 on unrelated callers' objects does not prove identical classes; the caller set is heterogeneous.
}
