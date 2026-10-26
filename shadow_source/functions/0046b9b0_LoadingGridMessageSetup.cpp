// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B9B0
// Canonical corpus name: sub_46B9B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46B9B0_0046b9b0.c

void UnknownObject::LoadingGridMessageSetup()
{
    // Sets up the Loading Grid message: runs state cleanup, resets the state/session field at this+0x178 to -1, and in championship mode (dword_7D0410 == 5) verifies the Loading Grid string is present in the string table, copies it into the display buffer byte_5EC4CC, and creates a UI menu item. Otherwise falls through returning the earlier cleanup result.
    // CALL: Run state cleanup via StateCleanupNotification(this) and retain its result for the fallthrough return. [source:raw, callee:0x00489CB0]
    // ASSIGNMENT: Reset the state/session identifier field at this+0x178 (this[94]) to -1. [source:raw, field:this:0x00000178]
    // GUARD: Enter the Loading Grid setup path only when the mode global dword_7D0410 equals 5 (championship mode). [source:raw, global:0x007D0410]
    // GUARD: Verify the Loading Grid string aLoadingGrid exists in the string table via BinarySearchInStringTable(byte_5EC4C0, aLoadingGrid, byte_5EC4CC). [source:raw, callee:0x00423A00, global:0x005EC4C0, global:0x005C6AA0, global:0x005EC4CC]
    // LOOP: Copy the Loading Grid string aLoadingGrid character by character into the display buffer byte_5EC4CC until the null terminator is reached. [source:raw, global:0x005C6AA0, global:0x005EC4CC]
    // RETURN: In championship mode, create the UI menu item via UIMenuItemCreator(this, byte_5EC4CC, byte_5EA438, byte_5EA438, byte_5EA438, 0) and return its result. [source:raw, callee:0x00489600, global:0x005EC4CC, global:0x005EA438]
    // RETURN: Outside championship mode, return the earlier StateCleanupNotification result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_46B9B0(int *this) {
    //     int result = StateCleanupNotification(this);
    //     this[94] = -1;
    //     if (dword_7D0410 == 5) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aLoadingGrid, byte_5EC4CC)) {
    //         int i = 0;
    //         char c;
    //         do { c = aLoadingGrid[i]; byte_5EC4CC[i++] = c; } while (c);
    //       }
    //       return UIMenuItemCreator(this, byte_5EC4CC, byte_5EA438, byte_5EA438, byte_5EA438, 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the three-argument BinarySearchInStringTable form and whether this copy loop is the only population path for byte_5EC4CC.
    // UNRESOLVED: Meaning of the three identical byte_5EA438 arguments passed to UIMenuItemCreator is defined by that callee.
    // UNRESOLVED: Whether the copy loop overwrites prior display-buffer content and how the buffer is bounded is unverified.
}
