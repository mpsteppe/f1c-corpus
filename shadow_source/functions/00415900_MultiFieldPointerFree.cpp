// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415900
// Canonical corpus name: StructDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructDestructor_00415900.c

void UnknownObject::MultiFieldPointerFree()
{
    // Destructor-style function. First re-initializes the object via TextFormatStructInitializer(this). Then four do-while loops sweep the pointer fields from high to low index: each loop starts at dword index 44, 34, 24, or 14, steps backward 5 per iteration for 2 iterations, and frees every non-null pointer found (indices 39/34, 29/24, 19/14, 9/4). Field 0 is freed if non-null, and the this allocation itself is freed when flag bit a2&1 is set. Returns this. Structural twin of MultiFieldPointerFree (00414380).
    // CALL: Call TextFormatStructInitializer(this) to reset/initialize the object before releasing its fields. [callee:0x004149A0, source:raw]
    // LOOP: Four sweep loops over pointer fields: starting dword index 44, 34, 24, 14, each stepping back 5 dwords for 2 iterations, so non-null pointers at indices 39/34, 29/24, 19/14, 9/4 are visited. [source:raw]
    // CALL: For every non-null pointer found in the sweep loops, call FreeWrapper_7bcf to release it. [callee:0x00587BCF, source:raw]
    // GUARD: Test the pointer field at this[0] (byte offset +0x0); free it only when non-null. [field:this:0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf(this[0]) to free the head pointer field when it is non-null. [callee:0x00587BCF, source:raw]
    // GUARD: Test flag bit a2 & 1; when set, free the this allocation itself. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to release the enclosing allocation when the flag bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer. [source:raw, function:0x00415900]

    // Conservative worker pseudocode:
    //   TextFormatStructInitializer(this);
    //   for (start in {44, 34, 24, 14})         // dword index
    //     for (i = 0; i < 2; i++)               // step -5 each
    //       if (this[start - 5 - 5*i]) FreeWrapper_7bcf(this[start - 5 - 5*i]);
    //   if (this[0]) FreeWrapper_7bcf(this[0]);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The 5-dword spacing between freed pointer fields (indices 39/34, 29/24, 19/14, 9/4) suggests a repeating sub-structure, but its layout and meaning are not established by this packet.
    // UNRESOLVED: What TextFormatStructInitializer writes into the object before the free pass is not shown here.
    // UNRESOLVED: Semantics of flag bit a2&1 (ownership/self-free flag) and the exact owner object type are unknown.
}
