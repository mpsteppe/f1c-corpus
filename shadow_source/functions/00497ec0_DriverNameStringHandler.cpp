// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497EC0
// Canonical corpus name: DriverNameStringHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverNameStringHandler_00497ec0.c

void UnknownObject::DriverNameStringHandler()
{
    // Parses and stores a driver name string from a path-like input a2. Defaults the result to -1, then normalizes a copy of the string with sub_589901, rejects it with -1 if StringArrayMatchSearch (00497f90) blacklist-matches, otherwise resolves it via StringNormalizeLookup (00495810). When the string is not a known registered key (lookup returns 0), sub_587C20 truncates it at the path separator word_5BEB48 and the extracted component is copied into a per-instance name storage slot indexed by this[1349] (this+0x1514). Returns the lookup index, or -1 on a null/empty input or a blacklist match. Called by UICustomRenderDispatch (00489fd0), sub_493060 (00493060), UIComboListRender (00495580) and sub_498440 (00498440).
    // ASSIGNMENT: v2 is initialized to -1 as the default (failure) result [source:raw]
    // GUARD: If a2 is null the function returns -1 immediately [source:raw]
    // GUARD: If strlen(a2) is 0 the body is skipped and the function returns -1 (empty input blocked) [source:raw]
    // ASSIGNMENT: The input string is copied into the local SrcStr buffer (80 bytes) with strcpy [source:raw]
    // CALL: sub_589901 normalizes SrcStr (lowercase / path-separator normalization) in place [callee:0x00589901]
    // CALL: StringArrayMatchSearch(SrcStr) checks the normalized string against a blocked-name array; a match returns -1 immediately [callee:0x00497F90]
    // CALL: StringNormalizeLookup(SrcStr) looks the string up in a registered-key table, returning its index in v2 (0 means not registered) [callee:0x00495810]
    // GUARD: Only when the lookup returned 0 (string is not a known registered key) does the function extract and store a component [callee:0x00495810, source:raw]
    // CALL: sub_587C20(SrcStr, &word_5BEB48) locates the path-separator character; if found it is truncated to a null terminator in place [callee:0x00587C20, global:0x005BEB48]
    // ASSIGNMENT: The extracted component is copied with strcpy into the per-instance name storage slot indexed by this[1349] (counter at this+0x1514), which is post-incremented [field:this:0x00001514]
    // RETURN: Return v2: the registered-key lookup index, or -1 for null/empty input, blacklist match, or an unregistered (newly stored) string [source:raw]

    // Conservative worker pseudocode:
    //   v2 = -1;
    //   if (!a2) return -1;
    //   if (strlen(a2)) {
    //     strcpy(SrcStr, a2);
    //     sub_589901(SrcStr);
    //     if (StringArrayMatchSearch(SrcStr)) return -1;
    //     v2 = StringNormalizeLookup(SrcStr);
    //     if (!v2) {
    //       v5 = (_BYTE *)sub_587C20(SrcStr, &word_5BEB48);
    //       if (v5) *v5 = 0;
    //       strcpy((char *)&this[20 * this[1349]++ + 69], SrcStr);
    //     }
    //   }
    //   return v2;
    // UNRESOLVED: The destination of the stored name is a per-instance array slot addressed as this[20 * this[1349]++ + 69]; the exact backing array size and fixed base offset are not evidenced in the packet
    // UNRESOLVED: strlen/strcpy are standard CRT calls used by the raw source but have no packet evidence references, so their behavior relies on standard library semantics
}
