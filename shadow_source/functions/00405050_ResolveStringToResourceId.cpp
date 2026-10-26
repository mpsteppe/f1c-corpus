// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405050
// Canonical corpus name: ShortComputation_5050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5050_00405050.c

void UnknownObject::ResolveStringToResourceId()
{
    // Resolves the string a1 to a numeric resource ID written to *a2, returning 1 on success and 0 on failure: tries a direct name lookup via ResourceIDLookupByNameString first; on miss, attempts a prefix parse (strlen >= 5, prefix asc_5BE820, numeric substring a1+4 parsed via SingleFunctionCallWrapper_7f59, then ResourceNodeLookupByStringOrID), and finally falls back to formatting the string via StringFormatWith0x40Size.
    // CALL: Obtain the resource manager singleton via OneTimeInitializationWithAtexitStyleRegistration (callee 0x00404FE0). [callee:0x00404FE0, function:0x00405050, source:raw]
    // CALL: Attempt direct name lookup of a1 via ResourceIDLookupByNameString (callee 0x00407F10). [callee:0x00407F10, source:raw]
    // ASSIGNMENT: On a direct hit (result != -1), write the resolved ID to *a2 and return 1. [source:raw]
    // GUARD: The prefix-parse fallback requires a1 non-null and strlen(a1) >= 5. [source:raw]
    // CALL: Test whether a1 starts with the prefix asc_5BE820 (global 0x005BE820) via sub_566810 (callee 0x00566810). [callee:0x00566810, global:0x005BE820, source:raw]
    // CALL: Parse the numeric substring starting at a1+4 via SingleFunctionCallWrapper_7f59 (callee 0x00587F59). [callee:0x00587F59, source:raw]
    // CALL: Look up a resource node by the parsed numeric string/ID via ResourceNodeLookupByStringOrID (callee 0x00407E40); on success write the node's field at +0x10 to *a2 and return 1. [callee:0x00407E40, source:raw]
    // CALL: When the prefix path fails, format the string via StringFormatWith0x40Size (callee 0x00595AE2) with inline parameters 0x8000 and 256; on -1 return 0, otherwise store the result in *a2 and return 1. [callee:0x00595AE2, source:raw]

    // Conservative worker pseudocode:
    //   ctx = OneTimeInitializationWithAtexitStyleRegistration();
    //   id = ResourceIDLookupByNameString(ctx, a1);
    //   if (id != -1) { *a2 = id; return 1; }
    //   if (a1 && strlen(a1) >= 5 && sub_566810(a1, asc_5BE820)) {
    //     n = SingleFunctionCallWrapper_7f59(a1+4);
    //     node = ResourceNodeLookupByStringOrID(OneTimeInitializationWithAtexitStyleRegistration(), 0, n);
    //     if (node) { *a2 = *(node+0x10); return 1; }
    //   }
    //   fmt = StringFormatWith0x40Size(a1, 0x8000, 256);
    //   if (fmt == -1) return 0;
    //   *a2 = fmt; return 1;
    // UNRESOLVED: The prefix asc_5BE820's content and the meaning of the parse offset a1+4 are not established by this packet.
    // UNRESOLVED: Inline formatting constants 0x8000 and 256 are used verbatim but their semantics are unknown.
    // UNRESOLVED: sub_566810 is assumed to be a prefix check based on its arguments; not independently evidenced.
    // UNRESOLVED: No owner or caller evidence exists; the function's owning object and invocation context are unknown.
    // UNRESOLVED: ABI lead name Short_Computation_405050 carries no semantic signal.
}
