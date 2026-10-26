// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1B90
// Canonical corpus name: FileSettingsScanner
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSettingsScanner_004a1b90.c

void UnknownObject::ScanSettingsTokensForPathMatch()
{
    // Scans a settings-file token stream, stripping separators, compares each token against a reference path held at this+0x4 (falling back to a default directory string), and on a match invokes a virtual callback through the vtable at this+0x0. Returns 1 once a matching token was found, otherwise 0.
    // CALL: ResourceLookupDispatcher(a2) opens a resource lookup handle that feeds the config token stream. [callee:0x00566E20, source:raw]
    // CALL: ConditionalDispatchBasedOnFlag(v13, 384) reads the first configuration token line into the 384-byte buffer; failure skips straight to cleanup. [callee:0x00566CC0, source:raw]
    // LOOP: Repeatedly reads the next token line via ConditionalDispatchBasedOnFlag(v13, 384) until the stream is exhausted or a matching token is found. [callee:0x00566CC0, source:raw]
    // GUARD: sub_596C80(v13, &unk_5C30B8, 2) checks the token's leading bytes against the delimiter at 0x5C30B8 before stripping and comparing it. [callee:0x00596C80, global:0x005C30B8]
    // CALL: sub_587C20 locates the substring tokens at word_5C30B4 and asc_5C30B0 inside the buffer and truncates each one found (sets the located byte to 0), isolating the key portion. [callee:0x00587C20, global:0x005C30B4, global:0x005C30B0]
    // ASSIGNMENT: The reference path is loaded from this+0x4; when null it falls back to the default application directory string byte_5EA438. [field:this:0x00000004, global:0x005EA438]
    // CALCULATION: sub_596C80 compares the reference path against the stripped token with a length limit; a zero return (equal) breaks the scan as a match. [callee:0x00596C80, field:this:0x00000004]
    // CALL: sub_587C20 strips the trailing delimiter at unk_5C30B8 from the matched token, then a backward scan truncates the value at the first quote byte (34) past the path. [callee:0x00587C20, global:0x005C30B8]
    // CALL: A virtual callback is dispatched through the vtable pointer at this+0x0 with the extracted value pointer; a non-zero callback result is required for success. [field:this:0x00000000]
    // CALL: sub_566DB0(v12) releases the resource lookup handle on both the success and failure cleanup paths. [callee:0x00566DB0]
    // RETURN: Returns 1 once a matching token was processed (the success latch), otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   handle = ResourceLookupDispatcher(arg2)
    //   token = ""
    //   if not ConditionalDispatchBasedOnFlag(token, 384): return 0
    //   while ConditionalDispatchBasedOnFlag(token, 384):
    //       if Compare(token, delim_5C30B8, 2):
    //           strip(substring_5C30B4); strip(separator_5C30B0)
    //           if len(token):
    //               path = this[1] or default_dir_5EA438
    //               if Compare(path, token, len(path)) == 0: break
    //   strip(trailing_delim_5C30B8)
    //   value = token after path + 2, truncated at quote
    //   if vtable_callback(this, value) and match_counter == 1: return 1
    //   Cleanup(handle); return 0
    // UNRESOLVED: field obj+0x4 is the caller's linked-list node pointer; its role inside this scanner is not evidenced by this function's body.
    // UNRESOLVED: The success path also latches the return flag even when the callback fails or the match count is not exactly one; the precise intended return semantics on those mixed paths are ambiguous.
}
