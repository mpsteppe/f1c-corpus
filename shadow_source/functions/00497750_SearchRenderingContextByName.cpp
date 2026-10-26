// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497750
// Canonical corpus name: RenderingContextSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderingContextSetup_00497750.c

void UnknownObject::SearchRenderingContextByName()
{
    // Initializes a stack-based rendering context via PassthroughWrapper, processes the instance through sub_4998E0, then searches the context for an item whose name string (at +0x34) matches the input a2. When an item's name pointer is null the global default string byte_5EA438 is substituted before comparison via sub_588410. Returns the matching item pointer, or 0 when the context is empty or no item matches.
    // CALL: Initialize the stack-based context buffer v6 via PassthroughWrapper. [callee:0x00499840, source:raw]
    // CALL: Process the instance (this) into the rendering context via sub_4998E0. [callee:0x004998E0, source:raw]
    // ASSIGNMENT: Fetch the current item pointer: v3 = FieldAccessor(v6). [callee:0x0053D880, source:raw]
    // GUARD: If the item pointer v3 is null, skip the search loop and go to cleanup, returning 0 (not found). [source:raw]
    // LOOP: Walk the context items: read the name pointer stored at item +0x34; when it is null substitute the global default string byte_5EA438; compare the name against a2 with sub_588410 and stop the walk when the comparison returns zero (match). [callee:0x00588410, global:0x005EA438, source:raw]
    // CALL: Advance the context iterator to the next item via sub_499910. [callee:0x00499910, source:raw]
    // ASSIGNMENT: Re-fetch the current item pointer after advancing: v3 = FieldAccessor(v6). [callee:0x0053D880, source:raw]
    // GUARD: If the re-fetched item pointer is null, exit to cleanup (not found). Otherwise continue the loop. [source:raw]
    // CALL: Run context cleanup via EmptyStub_0170 on both the found and not-found exit paths. [callee:0x004B0170, source:raw]
    // RETURN: Return the matching item pointer v3 when the name matched, otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   // 0x00497750
    //   PassthroughWrapper(context);
    //   sub_4998E0(this);
    //   item = FieldAccessor(context);
    //   if (!item) { EmptyStub_0170(context); return 0; }
    //   for (;;) {
    //       name_ptr = *(char **)(item + 52);
    //       if (!name_ptr) name_ptr = byte_5EA438;
    //       if (!sub_588410(name_ptr, target_name)) break;
    //       sub_499910(context);
    //       item = FieldAccessor(context);
    //       if (!item) break;
    //   }
    //   EmptyStub_0170(context);
    //   return item ? item : 0;
    // UNRESOLVED: The context buffer layout produced by PassthroughWrapper is unknown; only the item accessor FieldAccessor and the iterator advance sub_499910 are observed.
    // UNRESOLVED: The item structure holding the name pointer at +0x34 is not identified; the +0x34 access has no independent field evidence beyond the raw source.
    // UNRESOLVED: The rendering context (stack buffer) is a worker-registered type with no owner evidence in this packet.
}
