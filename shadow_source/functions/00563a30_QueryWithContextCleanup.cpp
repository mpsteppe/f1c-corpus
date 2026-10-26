// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563A30
// Canonical corpus name: QueryWithContextCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QueryWithContextCleanup_00563a30.c

void UnknownObject::QueryWithContextCleanup()
{
    // Query helper called from sub_563870. Computes sub_564110(a3, a4, this+0x94) where this+0x94 supplies per-query context, stores the result into local a4, then routes a4 by address through SingleFunctionCallWrapper_48c0 using the invocable target held at this+0x4. Returns the value a4 carries after the wrapper runs.
    // CALL: Call sub_564110(a3, a4, this[37]) passing the context value at this+0x94. [callee:0x00564110, field:this:0x00000094, source:raw]
    // ASSIGNMENT: Load the invocable target from this+0x4 into v6. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the sub_564110 result into a4 so the wrapper can receive it by address. [source:raw]
    // CALL: Call SingleFunctionCallWrapper_48c0(v6, &a4), passing a4 by reference. [callee:0x005648C0, source:raw]
    // RETURN: Return a4, which holds the final value after the wrapper invocation. [source:raw]

    // Conservative worker pseudocode:
    //   int QueryWithContextCleanup(int *self, int arg2, int arg3, int arg4) {
    //     arg4 = sub_564110(arg3, arg4, self[37]);
    //     SingleFunctionCallWrapper_48c0(self[1], &arg4);
    //     return arg4;
    //   }
    // UNRESOLVED: Semantics of the unused parameter a2 are unknown.
    // UNRESOLVED: Meaning of the value computed by sub_564110 from this+0x94 is unknown.
    // UNRESOLVED: Whether SingleFunctionCallWrapper_48c0 writes the final result back through the address of a4 is unknown.
    // UNRESOLVED: Semantics of the invocable target stored at this+0x4 are unknown.
}
