// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D320
// Canonical corpus name: TrackPositionNameFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackPositionNameFormatter_0049d320.c

void UnknownObject::FormatGearIndicatorText()
{
    // Reads a value from EngineRevValueAccessor. For a positive value it formats the number as "%d" into a small stack buffer via StringFormatWithBufferOverflowCheck and renders it to the HUD via sub_553070 at screen position (49, 43), passing *(this[4] + 84) as the display context. For value 0 it looks up the neutral string aN in the string table and copies it into the display buffer byte_5EC4CC. For a negative value it looks up and copies the error string byte_5CCEC4 into byte_5EC4CC. The non-positive cases converge on copying at most 3 characters from byte_5EC4CC into the stack buffer (NUL-terminated) and rendering it the same way. Called from SteeringWheelAnimation.
    // CALL: Read the value to display via EngineRevValueAccessor(). [callee:0x0049B8F0]
    // GUARD: Branch on the sign of the value: >= 0 selects numeric/neutral formatting, < 0 selects the error-text path. [source:raw]
    // GUARD: Within the >= 0 branch a non-zero value is formatted as a number while zero selects the neutral 'N' text. [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%d", value) formats the positive value into the 4-byte stack buffer v8. [callee:0x0058815F]
    // RETURN: Render the formatted number via sub_553070(v8, 49, 43, *(this[4] + 84)). [callee:0x00553070, field:this:0x00000010]
    // GUARD: For value 0, BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC) locates the neutral entry in the string table before copying. [callee:0x00423A00, global:0x005EC4C0, global:0x005C36FC, global:0x005EC4CC]
    // LOOP: Copy the aN ('N') string into byte_5EC4CC until the NUL terminator. [global:0x005C36FC, global:0x005EC4CC]
    // GUARD: For negative values, BinarySearchInStringTable(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC) locates the error string in the string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCEC4, global:0x005EC4CC]
    // LOOP: Copy the byte_5CCEC4 error string into byte_5EC4CC until the NUL terminator. [global:0x005CCEC4, global:0x005EC4CC]
    // CALL: sub_587DD0(v8, byte_5EC4CC, 3) copies at most 3 characters from the display buffer into v8; then v8[3] is forced to 0. [callee:0x00587DD0, global:0x005EC4CC]
    // RETURN: Render the buffered text via sub_553070(v8, 49, 43, *(this[4] + 84)). [callee:0x00553070, field:this:0x00000010]

    // Conservative worker pseudocode:
    //   int sub_49D320() {
    //     int value = EngineRevValueAccessor();
    //     if (value >= 0) {
    //       if (value != 0) {
    //         StringFormatWithBufferOverflowCheck(v8, "%d", value);
    //         return sub_553070(v8, 49, 43, *(int*)(this[4] + 84));
    //       }
    //       if (BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC))
    //         copy_string(aN, byte_5EC4CC);
    //     } else if (BinarySearchInStringTable(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC)) {
    //       copy_string(byte_5CCEC4, byte_5EC4CC);
    //     }
    //     sub_587DD0(v8, byte_5EC4CC, 3);
    //     v8[3] = 0;
    //     return sub_553070(v8, 49, 43, *(int*)(this[4] + 84));
    //   }
    // UNRESOLVED: field this+0x64 and globals aD_1 (0x005C3280) and unk_7CE234 (0x007CE234) appear in the packet's field/global lists but are not referenced by the decompiled body.
    // UNRESOLVED: The meaning of the EngineRevValueAccessor value (inferred to be a gear number) and of the constant screen position (49, 43) is inferred, not confirmed.
    // UNRESOLVED: What *(this[4] + 84) points to (a display/render context) is unknown.
}
