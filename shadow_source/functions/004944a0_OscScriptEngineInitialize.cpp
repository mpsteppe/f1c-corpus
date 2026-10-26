// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004944A0
// Canonical corpus name: sub_4944A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4944A0_004944a0.c

void UnknownObject::OscScriptEngineInitialize()
{
    // Initializes and runs the OSC script engine. Guards on the script-data object parameter a2 (returns -1 when null), copies the script name out of a2's vtable (entry +12) into this+0xC, stores the parser flags a3/a4 into this+0x198/0x199, clears this+0x19A to 0, stores the script-data pointer into this+0x1A4, and opens the file streams via FileOpenWrapperWithModeCheck. On success it runs the parser sub_4920B0, and when the byte_5CC2CC flag is set builds paths (base from dword_5EC418 with byte_5EA438 fallback) to load eas.bik and eaintro.bik videos plus the legal.bmp resource, feeds the script object to sub_496380, runs the parser sub_492160, performs TripleFieldCleanup, clears byte_5CC2CC and calls FunctionCallWrapper_b970.
    // GUARD: When the script-data object a2 is null, return -1 immediately without touching any fields [source:raw]
    // CALL: Call a2's vtable entry +12 and strcpy the returned script-name string into this+0xC [source:raw]
    // ASSIGNMENT: Store parser flag a3 into this+0x198 and a4 into this+0x199; clear this+0x19A to literal 0; store the script-data pointer a2 into this+0x1A4 [field:this:0x00000198, field:this:0x00000199, field:this:0x0000019A, field:this:0x000001A4, source:raw]
    // CALL: Open the file streams on this via FileOpenWrapperWithModeCheck; the remainder of the function only runs when it does not return -1 [callee:0x00491EE0, source:raw]
    // CALL: Run the parser sub_4920B0 on this after the file streams are open [callee:0x004920B0, source:raw]
    // GUARD: When the byte_5CC2CC flag is set, perform the media loading block [global:0x005CC2CC, source:raw]
    // CALCULATION: Path base is dword_5EC418, falling back to byte_5EA438 when dword_5EC418 is null [global:0x005EC418, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds "%s%s" from the path base and aEasBik; FileLoadWithRetryLoop loads the resulting eas.bik file with index 0 [callee:0x0058815F, global:0x005CC9C0, callee:0x004F9B70, source:raw]
    // CALL: ResourceFileLoader loads the legal.bmp resource (aLegalBmp) with scale 3.0 and index 0 [callee:0x004F9D60, global:0x005CC9B4, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds "%s%s" from the path base and aEaintroBik; FileLoadWithRetryLoop loads the resulting eaintro.bik file with index 1 [callee:0x0058815F, global:0x005CC9A8, callee:0x004F9B70, source:raw]
    // CALL: Feed the script-data object a2 into sub_496380 [callee:0x00496380, source:raw]
    // CALL: Run the script parser sub_492160 on this; its result becomes the function return value on the success path [callee:0x00492160, source:raw]
    // CALL: TripleFieldCleanup tears down the opened streams/fields of this [callee:0x00491F60, source:raw]
    // STATE_TRANSITION: When byte_5CC2CC is set, clear it to 0 and call FunctionCallWrapper_b970 [global:0x005CC2CC, callee:0x0041B970, source:raw]
    // RETURN: Return the parser result (v9) on success, or the FileOpenWrapperWithModeCheck result when it failed; called by sub_485B90 (00485B90) [caller:0x00485B90, function:0x004944A0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == NULL) return -1;
    //   strcpy(this + 0xC, a2->vtable[3]());
    //   this[0x198] = a3; this[0x1A4] = a2;
    //   this[0x199] = a4; this[0x19A] = 0;
    //   result = FileOpenWrapperWithModeCheck(this);
    //   if (result != -1) {
    //     sub_4920B0(this);
    //     if (byte_5CC2CC) {
    //       base = dword_5EC418 ? dword_5EC418 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(buf, "%s%s", base, aEasBik);
    //       FileLoadWithRetryLoop(buf, 0);
    //       ResourceFileLoader(aLegalBmp, 3.0, 0);
    //       StringFormatWithBufferOverflowCheck(buf, "%s%s", base, aEaintroBik);
    //       FileLoadWithRetryLoop(buf, 1);
    //     }
    //     sub_496380(a2);
    //     v9 = sub_492160(this);
    //     TripleFieldCleanup(this);
    //     if (byte_5CC2CC) { byte_5CC2CC = 0; FunctionCallWrapper_b970(); }
    //     return v9;
    //   }
    //   return result;
    // UNRESOLVED: Globals dword_5EB978 and unk_8AFE18 are listed by packet facts but appear nowhere in the raw decompiled source of this function; their role is unverifiable from this packet
    // UNRESOLVED: The aSS global (005BE860) is not referenced by name in the raw source text; the packet treats it as the path-construction format string but this is a DERIVED label, not independently confirmable here
}
