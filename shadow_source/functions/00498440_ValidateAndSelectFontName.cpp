// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498440
// Canonical corpus name: sub_498440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_498440_00498440.c

void UnknownObject::ValidateAndSelectFontName()
{
    // Selects a system font by name. On a non-empty requested name a2, runs DriverNameStringHandler to normalize the name, then searches the registered font-name array (base at 0x114, 80-byte entries, count at 0x1514) with sub_588410; on a match copies a2 to the active-font buffer at 0x166C. When no font is registered or no entry matches, shows an error MessageBox (aError title) and falls back to copying the first array entry into the active-font buffer. Called by sub_492160.
    // GUARD: Proceed only when a2 is non-null and strlen(a2) > 0; otherwise the function does nothing. [source:raw]
    // CALL: DriverNameStringHandler(this, a2) normalizes the requested font/driver name before the search. [callee:0x00497EC0, source:raw]
    // GUARD: If the registered font count at 0x1514 is <= 0, skip the search and show the generic error MessageBoxA(GetDesktopWindow(), ::Text, aError, 0). [guard:0, field:this:0x00001514, global:0x0059E2A0, global:0x0059E2A4, global:0x005CCAB4, global:0x005CC970, source:raw]
    // LOOP: Walk the font-name array starting at this + 0x114 with 80-byte stride, comparing each entry against a2 via sub_588410; when an entry matches (sub_588410 returns 0), strcpy a2 to the active-font buffer at 0x166C and return immediately. [field:this:0x00000114, field:this:0x0000166C, callee:0x00588410, source:raw]
    // STATE_TRANSITION: Fallback after no match (or an empty font list): format the message via StringFormatWithBufferOverflowCheck with the aSpecifiedSyste format string, show MessageBoxA(GetDesktopWindow(), Text, aError, 0), then byte-copy the first array entry at 0x114 into the active-font buffer at 0x166C. [global:0x005CCA78, callee:0x0058815F, global:0x0059E2A0, global:0x0059E2A4, global:0x005CC970, field:this:0x00000114, field:this:0x0000166C, source:raw]
    // RETURN: Void function; early return occurs only on the successful match path inside the search loop. [function:0x00498440, source:raw]
    // CALL: Invoked by sub_492160 (00492160) to validate and activate a requested font name. [caller:0x00492160, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2 || !strlen(a2)) return;
    //   DriverNameStringHandler(this, a2);
    //   count = *(this + 0x1514);
    //   if (count <= 0) {
    //     MessageBoxA(GetDesktopWindow(), ::Text, aError, 0);
    //   } else {
    //     for (i = 0; i < count; i++) {
    //       entry = this + 0x114 + 80*i;
    //       if (!sub_588410(entry, a2)) { strcpy(this + 0x166C, a2); return; }
    //     }
    //     StringFormatWithBufferOverflowCheck(Text, aSpecifiedSyste, a2, this + 0x114);
    //     MessageBoxA(GetDesktopWindow(), Text, aError, 0);
    //     copy bytes from this + 0x114 into this + 0x166C until NUL;
    //   }
    // UNRESOLVED: The exact semantics of DriverNameStringHandler and the 80-byte font-entry layout (name + style attributes) are not defined by this function alone
    // UNRESOLVED: The off-by-one structure of the decompiled loop (goto LABEL_8 when the post-loop count check fails) is compiler scheduling noise; the observable behavior is a single fallback path
}
