// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D310
// Canonical corpus name: ConditionalFontSurfaceCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFontSurfaceCall_0053d310.c

void UnknownObject::ConditionalFontSurfaceCall()
{
    // Conditional dispatcher: searches a linked list of wide strings with WideStringLinkedListSearch(a1). If the search succeeds (non-zero result), calls sub_5531F0(a2, a3, a4, 0) and returns its result; otherwise returns the zero search result directly. Caller is sub_4F9480.
    // CALL: WideStringLinkedListSearch(a1) searches a linked list of wide strings; the returned pointer is kept as the result and reused as the success guard. [callee:0x0053D1F0, source:raw]
    // GUARD: If the search result is non-zero, the sub_5531F0 branch runs; otherwise the function falls through and returns the zero search result. [source:raw]
    // CALL: sub_5531F0(a2, a3, a4, 0) is invoked only when the wide-string search matched; the fourth argument is a literal 0. [callee:0x005531F0, source:raw]
    // RETURN: Returns the sub_5531F0 result when the search matched, otherwise returns the (zero) search result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53D310(const char *a1, int a2, int a3, int a4) {
    //     int found = WideStringLinkedListSearch(a1);
    //     if (found)
    //       return sub_5531F0(a2, a3, a4, 0);
    //     return found;
    //   }
    // UNRESOLVED: Semantics of the wide-string list search are unknown; the list searched and the string key a1 are caller-supplied.
    // UNRESOLVED: Purpose of sub_5531F0 and of its literal 0 fourth argument are unknown here.
    // UNRESOLVED: Why a matching search result triggers the sub_5531F0 call while a miss returns 0 is unresolved.
}
