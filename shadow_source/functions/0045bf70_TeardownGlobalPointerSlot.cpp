// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BF70
// Canonical corpus name: sub_45BF70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45BF70_0045bf70.c

void UnknownObject::TeardownGlobalPointerSlot()
{
    // Global slot teardown routine: loads the pointer stored in global dword_7CD25C[0]; if it is non-null, runs a per-object teardown sub_45D730 on it and frees the object via the FreeWrapper_7bcf free wrapper, keeping the free result as the return value. The slot is unconditionally cleared to null at the end.
    // ASSIGNMENT: Capture the current pointer value stored in global dword_7CD25C[0] into a local. [global:0x007CD25C, source:raw]
    // GUARD: Guard on the stored global pointer being non-null before running the teardown/free path. [global:0x007CD25C, source:raw]
    // CALL: Call sub_45D730 on the stored global pointer to perform per-object teardown. [source:raw]
    // CALL: Call the FreeWrapper_7bcf free wrapper on the captured pointer and store its return value as the result. [source:raw]
    // ASSIGNMENT: Clear the global slot by storing 0 into dword_7CD25C[0]. [global:0x007CD25C, source:raw]
    // RETURN: Return the result produced by the free wrapper (or leave the result uninitialized when the guard failed). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_45BF70() {
    //     void *v0 = (void *)dword_7CD25C[0];
    //     int result;
    //     if (dword_7CD25C[0]) {
    //       sub_45D730(dword_7CD25C[0]);
    //       result = FreeWrapper_7bcf(v0);
    //     }
    //     dword_7CD25C[0] = 0;
    //     return result;
    //   }
    // UNRESOLVED: sub_45D730 and FreeWrapper_7bcf are absent from the packet callee evidence; their addresses and ownership are unknown.
    // UNRESOLVED: When the stored global pointer is null, result is returned uninitialized; whether the caller can observe this is unknown.
    // UNRESOLVED: The object type managed through global slot dword_7CD25C[0] is unknown.
}
