// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586A10
// Canonical corpus name: BoundedMemoryCopyWithSizeValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedMemoryCopyWithSizeValidation_00586a10.c

void UnknownObject::BoundedMemoryCopyWithSizeValidation()
{
    // Validates an incoming size against a stored field, resolves a source buffer pointer and size, copies the buffer into the caller-provided destination, and optionally reports the copied size back.
    // CALCULATION: v4 = FieldAccessor(this + 2): reads the stored size/limit field used for validation. [callee:0x0053D880]
    // GUARD: If v4 > a3, return 4: incoming size exceeds the stored field. [source:raw]
    // CALL: BufferQueryReturnPtrSizeIfValid(&v7, &a3): resolves the source pointer and the effective size. [callee:0x00587580]
    // GUARD: If the buffer query fails, return 1. [source:raw]
    // CALL: Copies a3 bytes from the resolved source v7 into destination a2. [source:raw]
    // ASSIGNMENT: If a4 is non-null, stores the copied size v6 (a3 after the buffer query) at *a4. [source:raw]
    // RETURN: Returns 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = FieldAccessor(this + 2);
    //   if (v4 > a3) return 4;
    //   if (!BufferQueryReturnPtrSizeIfValid(&v7, &a3)) return 1;
    //   qmemcpy(a2, v7, a3);
    //   if (a4) *a4 = a3;
    //   return 0;
    // UNRESOLVED: Semantic of the value read by FieldAccessor(this + 2) unknown.
    // UNRESOLVED: Which buffer v7 aliases and how the buffer query validates its size unknown.
    // UNRESOLVED: Return-code meanings (4, 1, 0) inferred from control flow only.
}
