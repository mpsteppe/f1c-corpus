// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042EC00
// Canonical corpus name: MessageStringFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MessageStringFormatter_0042ec00.c

void UnknownObject::MessageStringFormatter()
{
    // Formats a UI message string. Selects a format template based on the flag at this+0x4 (value 1 selects the main format buffer byte_5C3738, anything else selects the alternate byte_5C3734), resolves the selected template through BinarySearchInStringTable into the shared display buffer byte_5EC4CC (copying it in when the lookup succeeds, clearing it otherwise), then applies the format arguments with StringFormatWithBufferOverflowCheck against the argument table off_5C3730 and returns the result. Called by MenuCommandDispatcher (004674E0).
    // ASSIGNMENT: Default the format template pointer v2 to the main format buffer byte_5C3738 [global:0x005C3738, source:raw]
    // GUARD: When the selection flag this[1] != 1, retarget v2 to the alternate format buffer byte_5C3734 [guard:0, field:this:0x00000004, global:0x005C3734, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC): look the selected format template up in the game string table, writing the found entry into the display buffer byte_5EC4CC [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: When the lookup returns a match, copy the template v2 into byte_5EC4CC (strcpy); otherwise clear the first byte of byte_5EC4CC so the buffer is empty [global:0x005EC4CC, source:raw]
    // CALL: Return the result of StringFormatWithBufferOverflowCheck(a2, &off_5C3730, byte_5EC4CC): format the selected template with the argument table off_5C3730 into a2 under overflow protection [callee:0x0058815F, global:0x005C3730, global:0x005EC4CC, source:raw]
    // CALL: Invoked by MenuCommandDispatcher (004674E0) [caller:0x004674E0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = &byte_5C3738;
    //   if (this[1] != 1)
    //     v2 = &byte_5C3734;
    //   if (BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC)) {
    //     if (v2)
    //       strcpy(byte_5EC4CC, v2);
    //     else
    //       byte_5EC4CC[0] = 0;
    //   }
    //   return StringFormatWithBufferOverflowCheck(a2, &off_5C3730, byte_5EC4CC);
    // UNRESOLVED: The selection flag at this+0x4 is only observed as binary (1 vs else); the set of meaningful values is not evident from this packet
    // UNRESOLVED: off_5C3730 is passed as the format-arguments source but its element layout is not defined here
    // UNRESOLVED: byte_5EC4C0 serves as the string-table lookup source while byte_5EC4CC doubles as both lookup result and format template; exact roles are inferred from call order
}
