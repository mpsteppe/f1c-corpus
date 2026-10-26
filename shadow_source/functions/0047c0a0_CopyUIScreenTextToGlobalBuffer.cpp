// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C0A0
// Canonical corpus name: sub_47C0A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47C0A0_0047c0a0.c

void UnknownObject::CopyUIScreenTextToGlobalBuffer()
{
    // UI text getter (__thiscall). Fetches the UI screen's text pointer via UIScreenTextAccessor(this); when it is non-null, copies the text with strcpy into the global buffer byte_7CD880 (invoking the accessor a second time for the copy), then returns the text pointer.
    // CALL: UIScreenTextAccessor(this) fetches the screen's text pointer and stores it as the result [callee:0x00489920, source:raw]
    // GUARD: The strcpy to the global buffer only runs when the fetched text pointer is non-null [source:raw]
    // ASSIGNMENT: strcpy(&byte_7CD880, UIScreenTextAccessor(this)) overwrites the global buffer with the current text; the accessor is invoked a second time for the copy source [global:0x007CD880, callee:0x00489920, source:raw]
    // RETURN: Return the text pointer fetched by the first UIScreenTextAccessor call [source:raw]

    // Conservative worker pseudocode:
    //   result = UIScreenTextAccessor(this);
    //   if (result)
    //     strcpy(&byte_7CD880, UIScreenTextAccessor(this));
    //   return result;
    // UNRESOLVED: The packet flags global 0x007CD880 access as read-only (rw=R) although the raw source writes to it as the strcpy destination; the discrepancy is unresolvable from this packet
    // UNRESOLVED: UIScreenTextAccessor is invoked twice and the two results are assumed equal; nothing in this packet proves they cannot differ
    // UNRESOLVED: The size and type of the byte_7CD880 buffer are unknown; strcpy implies a null-terminated destination
}
