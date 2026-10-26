// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9FD0
// Canonical corpus name: sub_4B9FD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9FD0_004b9fd0.c

void UnknownObject::displayReplayActivationMessage()
{
    // One-shot replay status UI renderer. If replay recording is active (this+0x0 == 1) and the message has not yet been displayed (this+0x4 == 0), it renders a 'ReplayRecording' line via TextLineWrappingAndRendering, then, unless a session-state check fails, builds a longer 'ReplayActivati...' message (seeding a local buffer from byte_5EA438, appending word_5C32D8 and a module path from sub_455260) and renders that on a second line. Sets this+0x4 = 1 to prevent re-display.
    // GUARD: Guard: if this+0x4 (already-displayed flag) is nonzero, or this+0x0 is not 1 (replay recording active), the entire body is skipped and the current value of this+0x4 is returned. [guard:0, field:this:0x00000004, field:this:0x00000000, function:0x004B9FD0]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aReplayRecordin, byte_5EC4CC) looks up the 'ReplayRecording' string and, when found, copies it into byte_5EC4CC (message display buffer). [callee:0x00423A00, global:0x005EC4C0, global:0x005D2494, global:0x005EC4CC]
    // CALL: TextLineWrappingAndRendering(&dword_7CD204, byte_5EC4CC, 2, 16909060) renders the replay-recording status message. [callee:0x0045BD10, global:0x007CD204, global:0x005EC4CC]
    // CALL: result = SessionStateCheckWrapper(dword_7CD25C); a nonzero result skips the activation-message block below. [callee:0x00461DB0, global:0x007CD25C]
    // ASSIGNMENT: Seed local message buffer v11 with byte_5EA438[0] (directory/path prefix) and zero-initialize the remaining 0x4C bytes plus v12/v13. [global:0x005EA438, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aReplayActivati, byte_5EC4CC) looks up the 'ReplayActivati' string and, when found, copies it into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005D2480, global:0x005EC4CC]
    // LOOP: Copy the activation string from byte_5EC4CC into the local message buffer v11 (strcpy-style loop terminating on the null byte). [global:0x005EC4CC, source:raw]
    // CALCULATION: Append word_5C32D8 as a trailing WORD immediately after v11's terminating null (v11[strlen(v11)]), fusing a stored 16-bit value onto the message buffer. [global:0x005C32D8, source:raw]
    // CALL: v9 = sub_455260(dword_7D1D8C) retrieves a module path string (held in v10); a null result means no path is available. [callee:0x00455260, global:0x007D1D8C]
    // CALL: If the module path is non-null: BinarySearchInStringTable(byte_5EC4C0, v9, byte_5EC4CC) copies the path into byte_5EC4CC, then strcat(v11, byte_5EC4CC) appends it to the local message buffer. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: result = TextLineWrappingAndRendering(&dword_7CD204, v11, 3, 16909060) renders the full replay-activation message on a second line. [callee:0x0045BD10, global:0x007CD204, source:raw]
    // STATE_TRANSITION: this+0x4 = 1 marks the message as displayed so subsequent calls return early via the guard. [field:this:0x00000004]
    // RETURN: Return result — this+0x4 when the guard skipped the body, otherwise the last render/session-check result. [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   if (this[4] == 0 && this[0] == 1) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, "ReplayRecording", byte_5EC4CC)) copy;
    //       TextLineWrappingAndRendering(&dword_7CD204, byte_5EC4CC, 2, 16909060);
    //       result = SessionStateCheckWrapper(dword_7CD25C);
    //       if (!result) {
    //           messageBuffer = byte_5EA438[0]; memset(messageBuffer+1, 0, 0x4C);
    //           if (BinarySearchInStringTable(byte_5EC4C0, "ReplayActivati", byte_5EC4CC)) copy;
    //           copy byte_5EC4CC into messageBuffer;
    //           *(WORD*)&messageBuffer[strlen(messageBuffer)] = word_5C32D8;
    //           modulePath = sub_455260(dword_7D1D8C);
    //           if (modulePath) {
    //               if (BinarySearchInStringTable(byte_5EC4C0, modulePath, byte_5EC4CC)) copy;
    //               strcat(messageBuffer, byte_5EC4CC);
    //           }
    //           result = TextLineWrappingAndRendering(&dword_7CD204, messageBuffer, 3, 16909060);
    //       }
    //       this[4] = 1;
    //   }
    //   return result;
    // UNRESOLVED: Literal 16909060 passed to TextLineWrappingAndRendering and the line parameters 2 and 3 are unexplained.
    // UNRESOLVED: Appending a trailing WORD (word_5C32D8) immediately after the string terminator in the message buffer suggests embedding a short value (e.g. a file-extension word) but its exact meaning is unconfirmed.
    // UNRESOLVED: byte_5EA438 is labeled a directory/path prefix only from the skeleton fill (DERIVED); not runtime-confirmed.
    // UNRESOLVED: sub_455260 is treated as a module-path getter per the skeleton fill (DERIVED); role not runtime-confirmed.
    // UNRESOLVED: Semantics of this+0x0 value 1 (replay recording active) and this+0x4 (displayed flag) come from the skeleton fill (DERIVED), not runtime proof.
}
