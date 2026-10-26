// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2FC0
// Canonical corpus name: sub_4C2FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C2FC0_004c2fc0.c

void UnknownObject::MultiFieldArrayCleanup()
{
    // Cleanup routine for an array of multi-field records. Guarded by a non-null global pointer (named dword_8AC394 in the raw source, adjacent to the packet's global evidence at 0x008AC388). Reads the record count from the 4-byte header immediately preceding that pointer, walks count records of stride 1060 backwards from the end, invokes MultiFieldCleanup on each record, then releases the allocation base (the header pointer) via FreeWrapper_7bcf.
    // GUARD: Guard: the global pointer (dword_8AC394 in the raw source) is tested for non-null; the entire cleanup is skipped when it is null. [global:0x008AC388, source:raw]
    // CALCULATION: Load the record count from the 4-byte header at (global - 4) and compute the record cursor as global + 1060 * count, one stride past the last record. [global:0x008AC388, source:raw]
    // LOOP: Loop exactly count times: move the cursor back by the 1060-byte record stride, clean the record at the cursor via MultiFieldCleanup, and decrement the loop counter until it reaches zero. [global:0x008AC388, source:raw]
    // CALL: Call MultiFieldCleanup on each 1060-byte record to release its owned sub-resources. [source:raw]
    // CALL: Call FreeWrapper_7bcf on the allocation base (global - 4) to release the whole array allocation after all records were cleaned. [global:0x008AC388, source:raw]
    // RETURN: Void return; the function performs cleanup side effects only. [function:0x004C2FC0, source:raw]

    // Conservative worker pseudocode:
    //   void MultiFieldArrayCleanup(void) {
    //     if (dword_8AC394) {
    //       int count = *(int *)(dword_8AC394 - 4);
    //       char *cursor = (char *)dword_8AC394 + 1060 * count;
    //       int remaining = count;
    //       while (remaining--) {
    //         cursor -= 1060;
    //         MultiFieldCleanup(cursor);
    //       }
    //       FreeWrapper_7bcf((void *)(dword_8AC394 - 4));
    //     }
    //   }
    // UNRESOLVED: The raw source names the guarded global dword_8AC394, while the packet's single global evidence is unk_8AC388 at 0x008AC388; the exact binding and the ownership of the 4-byte count header at (global - 4) are unresolved.
    // UNRESOLVED: Callee identities MultiFieldCleanup and FreeWrapper_7bcf are named only inside the raw source text; the packet carries no callee evidence, so no numeric call targets are asserted.
    // UNRESOLVED: The owner object/allocator of the 1060-byte record array is unknown; the record stride (1060) is preserved from the source only.
}
