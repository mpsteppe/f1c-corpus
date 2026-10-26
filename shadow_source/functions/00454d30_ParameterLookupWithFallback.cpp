// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00454D30
// Canonical corpus name: ParameterLookupWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParameterLookupWithFallback_00454d30.c

void UnknownObject::ParameterLookupWithFallback()
{
    // Tries two parameter lookup strategies in order. First attempts sub_454350; on success writes (1, value) to the caller's DWORD pair and returns 1. Otherwise attempts PAUSEStringCopier; on success writes (0, value) to the pair and returns 1. If both fail, returns 0.
    // CALL: Call sub_454350(this, a2, &a4, a4); a4 is passed both by reference (for output) and by value. [abi:lead, callee:0x00454350, function:0x00454D30, source:raw]
    // GUARD: If sub_454350 returns nonzero, take the named-parameter success path. [function:0x00454D30, source:raw]
    // ASSIGNMENT: v5 = a4 (captured value); *a3 = 1; a3[1] = v5. Writes flag 1 and the resolved value into the caller's DWORD pair. [function:0x00454D30, source:raw]
    // RETURN: Return 1 on the named-parameter success path. [function:0x00454D30, source:raw]
    // CALL: Fallback call to PAUSEStringCopier(this, a2, &a4). [callee:0x004541D0, function:0x00454D30, source:raw]
    // GUARD: If PAUSEStringCopier returns nonzero, take the numeric fallback success path. [function:0x00454D30, source:raw]
    // ASSIGNMENT: v7 = a4 (captured value); *a3 = 0; a3[1] = v7. Writes flag 0 and the resolved value into the caller's DWORD pair. [function:0x00454D30, source:raw]
    // RETURN: Return 1 on the fallback success path. [function:0x00454D30, source:raw]
    // RETURN: Return 0 when both lookup strategies fail. [function:0x00454D30, source:raw]

    // Conservative worker pseudocode:
    //   bool ParameterLookupWithFallback(void* this, char* key, DWORD* outPair, int a4) {
    //     if (sub_454350(this, key, &a4, a4)) {
    //       outPair[0] = 1;
    //       outPair[1] = a4;
    //       return true;
    //     } else if (PAUSEStringCopier(this, key, &a4)) {
    //       outPair[0] = 0;
    //       outPair[1] = a4;
    //       return true;
    //     }
    //     return false;
    //   }
    // UNRESOLVED: Meaning of the flag written to *a3 (1 for named-parameter path, 0 for pause/numeric path) is not established.
    // UNRESOLVED: Why a4 is passed to sub_454350 both by address and by value is unclear from the raw source alone.
    // UNRESOLVED: Semantics of the two lookup strategies (named parameter vs pause string) and their object type are unresolved.
}
