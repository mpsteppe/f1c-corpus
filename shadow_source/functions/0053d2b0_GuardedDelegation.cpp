// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D2B0
// Canonical corpus name: GuardedDelegation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedDelegation_0053d2b0.c

void UnknownObject::GuardedDelegation()
{
    // Guarded delegation: searches a wide-string linked list with WideStringLinkedListSearch (0x0053D1F0) on the first argument; when the search yields a non-zero result, delegates a2/a3 to TwoFieldSetter_3050 (0x00553050) and returns that result; otherwise returns the search result (zero). Used by sub_4F8D70 (0x004F8D70).
    // CALL: result = WideStringLinkedListSearch(a1): search the wide-string linked list using the first argument. [callee:0x0053D1F0, source:raw]
    // GUARD: Proceed to the delegation only when result is non-zero. [callee:0x0053D1F0, source:raw]
    // CALL: TwoFieldSetter_3050(a2, a3) is invoked with the second and third arguments when the search succeeds. [callee:0x00553050, source:raw]
    // RETURN: Return the TwoFieldSetter_3050 result on the success path, otherwise return the zero search result. [callee:0x0053D1F0, callee:0x00553050, source:raw]
    // CALL: Called by sub_4F8D70 as part of its lookup-then-set dispatch pattern. [caller:0x004F8D70, source:raw]

    // Conservative worker pseudocode:
    //   int GuardedDelegation(const char *a1, int a2, int a3) {
    //     int result = WideStringLinkedListSearch(a1);
    //     if (result)
    //       return TwoFieldSetter_3050(a2, a3);
    //     return result;
    //   }
    // UNRESOLVED: a1 is typed const char* but is searched by a wide-string routine; the exact string encoding and list structure are not proven by the packet.
    // UNRESOLVED: Semantic roles of a2/a3 and the fields written by TwoFieldSetter_3050 are not established.
}
