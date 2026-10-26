// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8FB0
// Canonical corpus name: sub_4D8FB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D8FB0_004d8fb0.c

void UnknownObject::ReleaseGlobalResourceHandles()
{
    // Releases up to four global resource handles by calling StringCompareLinkedListSearch on each non-null handle and nulling the handle afterwards. Handles dword_8AD388, dword_8AD38C and dword_8AD390 are each independently guarded, released and nulled; dword_8AD394 is read into result first, then released and nulled when non-null. The final result is the last release return value (or the pre-read dword_8AD394 value when it was null).
    // GUARD: dword_8AD388 non-null guard: release and null only when the handle is set. [global:0x008AD388, source:raw]
    // CALL: StringCompareLinkedListSearch(dword_8AD388) releases/destructs handle 1; despite its name it acts as a resource release per the existing fill. [callee:0x0053D130, global:0x008AD388, source:raw]
    // ASSIGNMENT: Nulls dword_8AD388 after release. [global:0x008AD388, source:raw]
    // GUARD: dword_8AD38C non-null guard: release and null only when the handle is set. [global:0x008AD38C, source:raw]
    // CALL: StringCompareLinkedListSearch(dword_8AD38C) releases/destructs handle 2. [callee:0x0053D130, global:0x008AD38C, source:raw]
    // ASSIGNMENT: Nulls dword_8AD38C after release. [global:0x008AD38C, source:raw]
    // GUARD: dword_8AD390 non-null guard: release and null only when the handle is set. [global:0x008AD390, source:raw]
    // CALL: StringCompareLinkedListSearch(dword_8AD390) releases/destructs handle 3. [callee:0x0053D130, global:0x008AD390, source:raw]
    // ASSIGNMENT: Nulls dword_8AD390 after release. [global:0x008AD390, source:raw]
    // GUARD: dword_8AD394 non-null guard: release and null only when the handle is set; the value is pre-read into result so the null path returns it unchanged. [global:0x008AD394, source:raw]
    // CALL: StringCompareLinkedListSearch(dword_8AD394) releases/destructs handle 4; its result is the function return value. [callee:0x0053D130, global:0x008AD394, source:raw]
    // ASSIGNMENT: Nulls dword_8AD394 after release. [global:0x008AD394, source:raw]
    // RETURN: Returns the last StringCompareLinkedListSearch result, or the pre-read dword_8AD394 value when that handle was null. [global:0x008AD394, source:raw]
    // CALL: Invoked by UtilityFunction_8720 (0x004D8720) and sub_4D8AB0 (0x004D8AB0), the callers list entries. [caller:0x004D8720, caller:0x004D8AB0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8AD388) { StringCompareLinkedListSearch(dword_8AD388); dword_8AD388 = 0; }
    //   if (dword_8AD38C) { StringCompareLinkedListSearch(dword_8AD38C); dword_8AD38C = 0; }
    //   if (dword_8AD390) { StringCompareLinkedListSearch(dword_8AD390); dword_8AD390 = 0; }
    //   result = dword_8AD394;
    //   if (dword_8AD394) { result = StringCompareLinkedListSearch(dword_8AD394); dword_8AD394 = 0; }
    //   return result;
    // UNRESOLVED: global:0x008AFE64 (dword_8AFE64) is listed as a read-only global in the packet but never appears in the raw decompiled source; it is left unresolved rather than inferred.
    // UNRESOLVED: StringCompareLinkedListSearch is named as a string-compare/linked-list search but the existing fill reads it as a resource release/destructor at DERIVED trust; that reading is adopted as context, not independently proven.
    // UNRESOLVED: The legacy ABI label 'FAIL_4d8fb0' (abi:lead) gives no semantic content and is not adopted.
    // UNRESOLVED: The resource type behind the four handles (audio/render per the existing fill, DERIVED) is not established from this packet alone.
}
