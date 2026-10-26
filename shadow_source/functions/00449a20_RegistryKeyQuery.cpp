// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449A20
// Canonical corpus name: RegistryKeyQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RegistryKeyQuery_00449a20.c

void UnknownObject::RegistryKeyQuery()
{
    // Queries a value associated with a key string formatted by StringFormatWith0x40Size. Failure of formatting returns -1. Otherwise sub_59B760 fills a stack buffer with registry query results; on failure the handle is released via sub_58C331 and -1 is returned, and on success the captured value at TotalBytesAvail[7] is returned after releasing the handle. Called from SceneTrackFileLoader.
    // CALL: result = StringFormatWith0x40Size(this, 0) formats the key string; -1 signals failure. [callee:0x00595AE2, source:raw]
    // GUARD: Guard on result != -1; on formatting failure the function returns -1 directly. [function:0x00449A20, source:raw]
    // CALL: sub_59B760(result, TotalBytesAvail) fills the stack buffer; its boolean result decides success. [callee:0x0059B760, source:raw]
    // GUARD: When sub_59B760 returns non-zero (failure), release the handle with sub_58C331(v2) and return -1. [callee:0x0058C331, function:0x00449A20, source:raw]
    // ASSIGNMENT: v3 = TotalBytesAvail[7] captures the registry query result from the stack buffer. [function:0x00449A20, source:raw]
    // CALL: sub_58C331(v2) releases the query handle before returning the captured value. [callee:0x0058C331, source:raw]
    // RETURN: Return the captured value v3 on success, or -1 on any failure path. [function:0x00449A20, source:raw]

    // Conservative worker pseudocode:
    //   int sub_449A20(const CHAR *this) {
    //     int result = StringFormatWith0x40Size(this, 0);
    //     if (result == -1) return -1;
    //     DWORD TotalBytesAvail[9];
    //     if (sub_59B760(result, TotalBytesAvail)) {
    //       sub_58C331(result);
    //       return -1;
    //     }
    //     DWORD v3 = TotalBytesAvail[7];
    //     sub_58C331(result);
    //     return v3;
    //   }
    // UNRESOLVED: Exact roles of sub_59B760 (query execution) and sub_58C331 (handle release) are inferred from control flow only.
    // UNRESOLVED: Meaning of TotalBytesAvail[7] and the buffer layout are unknown.
    // UNRESOLVED: What registry key/value pair this queries and how the returned value is consumed by SceneTrackFileLoader are unverified.
}
