// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005596E0
// Canonical corpus name: FunctionPointerDispatchViaLinkedTraversal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionPointerDispatchViaLinkedTraversal_005596e0.c

void UnknownObject::FunctionPointerDispatchViaLinkedTraversal()
{
    // Dispatch function invoked on a context object a1. Walks a linked list of dispatch entries seeded from the list pointer at this+0x8; for each entry, compares the entry's selector field (entry object +0x14) against the target value held at obj+0x220 and, on a match, guards on the alternate handler-context function pointer (+0x14), writes the call argument (+0x18) into this+0x20, then makes an indirect __thiscall. A fallback path uses the direct handler object at obj+0x220 (function pointer +0x14, argument +0x18) when the walk produced no call.
    // GUARD: Guard on the linked-list head pointer at this+0x8; when null the linked-list dispatch walk is skipped. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Save the root context pointer read from this+0x0 into v2; used for selector comparisons and the fallback dispatch path. [field:this:0x00000000, source:raw]
    // LOOP: Walk the linked list of dispatch entries, seeding the cursor from the head pointer and following each node's next-link until null. [field:this:0x00000008, source:raw]
    // GUARD: Selector match: compare the dispatch entry's selector field (+0x14 on the entry object) against the target value held at obj+0x220; equality gates the handler invocation. [field:*(obj+0x220):0x00000014, field:obj:0x00000220, source:raw]
    // ASSIGNMENT: Load the alternate handler context pointer from this+0x230; it points at the handler struct whose function pointer and call argument are used for the invocation. [field:this:0x00000230, source:raw]
    // GUARD: Guard on the alternate-context function pointer (+0x14) being non-null before invoking the matched handler. [field:*(this+0x230):0x00000014, source:raw]
    // ASSIGNMENT: Write the handler call argument (alternate context +0x18) into the output/call-parameter field at this+0x20 before the indirect call. [field:*(this+0x230):0x00000018, field:this:0x00000020, source:raw]
    // CALL: Invoke the matched handler: indirect __thiscall through the function pointer at (alternate context +0x14) with a1 as this; store the returned pointer. [field:*(this+0x230):0x00000014, source:raw]
    // GUARD: Fallback path: when the saved root context v2 is non-null and the direct handler object at obj+0x220 exists, dispatch through it directly. [field:this:0x00000000, field:obj:0x00000220, source:raw]
    // GUARD: Guard on the fallback function pointer ((obj+0x220)+0x14) being non-null before the fallback call. [field:*(obj+0x220):0x00000014, source:raw]
    // ASSIGNMENT: Write the fallback call argument ((obj+0x220)+0x18) into the output/call-parameter field at this+0x20. [field:*(obj+0x220):0x00000018, field:this:0x00000020, source:raw]
    // CALL: Invoke the fallback handler: indirect __thiscall through the function pointer at ((obj+0x220)+0x14) with a1 as this, returning its result. [field:*(obj+0x220):0x00000014, source:raw]
    // RETURN: Return the last dispatch result: the matched handler return value, the fallback return value, or the trailing result pointer when no handler ran. [function:0x005596E0, source:raw]

    // Conservative worker pseudocode:
    //   void *__stdcall FunctionPointerDispatchViaLinkedTraversal(int *ctx) {
    //     void *result = (void *)ctx[2];
    //     int root = *ctx;
    //     if (result) {
    //       for (node = result[137]; node; node = node[1]) {
    //         entry = *node;
    //         if (*(entry + 20) == *(root + 544)) {
    //           handler = entry[6];
    //           if (*(handler + 20)) {
    //             ctx[8] = *(handler + 24);
    //             result = ((thiscall_fp)*(handler + 20))(ctx);
    //           }
    //         }
    //       }
    //     }
    //     if (root) {
    //       fallback = *(root + 544);
    //       if (fallback && fallback[5]) {
    //         ctx[8] = fallback[6];
    //         return ((thiscall_fp)*(root + 544 + 20))(ctx);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Object ownership of the dispatch entries, the alternate handler context at this+0x230, and the direct handler object at obj+0x220 is unknown.
    // UNRESOLVED: Purpose of alternate-context fields +0x2C and +0x30 is unresolved.
    // UNRESOLVED: Purpose of this+0x22C and this+0x234 is unresolved.
    // UNRESOLVED: The seed offset result[137] (548) has no dedicated packet field entry; node linkage beyond the next-link pointer is inferred.
}
