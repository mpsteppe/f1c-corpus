// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F9F0
// Canonical corpus name: UIWindowTextSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWindowTextSetup_0048f9f0.c

void UnknownObject::SetupTextWindowConfig()
{
    // Configures a UI text-window object 'this': copies the directory path (this+0xB8, or the default byte_5EA438 when null) into a local 63-byte buffer via sub_587DD0, searches for token word_5C32D8 with sub_5897CA, loads two resource objects through SingleFunctionCallWrapper_7f59 into this+0x154 and this+0x150, then classifies the layout mode written to this+0xE0 (0, 1 or 2) by comparing the found token against byte_5CC21C, aC_0 and aR with sub_588410. Returns the last search result.
    // CALL: Build the directory path: copy the string at this+0xB8 into a local 63-byte buffer with sub_587DD0 (max length 63); when this+0xB8 is NULL, copy the default byte_5EA438 instead. [callee:0x00587DD0, field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: Search for token word_5C32D8 within the built path using sub_5897CA; when a match (v3) is found, store SingleFunctionCallWrapper_7f59(v3) into this+0x154. [callee:0x005897CA, callee:0x00587F59, global:0x005C32D8, field:this:0x00000154, source:raw]
    // CALL: Search again for token word_5C32D8 with sub_5897CA on the default buffer (0); when a match (v4) is found, store SingleFunctionCallWrapper_7f59(v4) into this+0x150. [callee:0x005897CA, callee:0x00587F59, global:0x005C32D8, field:this:0x00000150, source:raw]
    // GUARD: Take a third sub_5897CA(0, &word_5C32D8) result; when non-null, classify the layout mode written to this+0xE0: compare against byte_5CC21C (no match -> 0), aC_0 (no match -> 1) and aR (no match -> 2) using sub_588410. [callee:0x005897CA, callee:0x00588410, global:0x005C32D8, global:0x005CC21C, global:0x005CC210, global:0x005C36F0, field:this:0x000000E0, source:raw]
    // RETURN: Return the last sub_5897CA result (the value used for layout classification). [source:raw]

    // Conservative worker pseudocode:
    //   int SetupTextWindowConfig(_DWORD* this) {
    //     char path[63];
    //     char* dir = (char*)this[46];
    //     if (!dir) dir = byte_5EA438;
    //     sub_587DD0(path, dir, 63);
    //     int r1 = sub_5897CA(path, &word_5C32D8);
    //     if (r1) this[85] = SingleFunctionCallWrapper_7f59(r1);
    //     int r2 = sub_5897CA(0, &word_5C32D8);
    //     if (r2) this[84] = SingleFunctionCallWrapper_7f59(r2);
    //     int r3 = sub_5897CA(0, &word_5C32D8);
    //     if (r3) {
    //       if (!sub_588410(r3, &byte_5CC21C)) this[56] = 0;
    //       if (!sub_588410(r3, aC_0)) this[56] = 1;
    //       if (!sub_588410(r3, aR)) this[56] = 2;
    //     }
    //     return r3;
    //   }
    // UNRESOLVED: word_5C32D8 is treated as a search/extraction token; the existing analysis labels it '.HOT' but its exact string content and sub_5897CA's contract are not evidenced in this packet.
    // UNRESOLVED: SingleFunctionCallWrapper_7f59's behavior (resource load/create from the matched token) is inferred from the existing analysis; this packet only shows its result being stored.
    // UNRESOLVED: The meaning of the this+0xE0 layout-mode values (0, 1, 2) and of the token strings byte_5CC21C / aC_0 / aR is unresolved.
    // UNRESOLVED: The legacy ABI name UI_Window_Text_Setup is supplied by the packet but is not corroborated by static evidence here.
}
