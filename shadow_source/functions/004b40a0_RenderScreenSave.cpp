// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B40A0
// Canonical corpus name: RenderScreenSave
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderScreenSave_004b40a0.c

void UnknownObject::RenderScreenSave()
{
    // Per-frame screenshot handler. Scans the input keycode array word_7CB21C (dword_7CB218 entries) for key code 88 ('X'); when pressed, saves the screen via sub_551FD0 using the season directory dword_5EC478 (or the fallback byte_5EA438 when empty) and screen dimensions dword_8B8DD4/dword_8B8DD8. On success it localizes 'Screen Saved' (aScreenSaved) through BinarySearchInStringTable into buffer byte_5EC4CC and renders the message with TextLineWrappingAndRendering. Regardless of the key path it always runs CameraViewportRenderSetup on unk_8AFFC8, VehicleVisibilityCulling on this, and returns sub_557120(dword_8AFE88).
    // ASSIGNMENT: Initialize loop counter v1 = 0. [source:raw]
    // GUARD: Guard on input scan: proceed only if dword_7CB218 > 0. [global:0x007CB218, source:raw]
    // LOOP: do-while scan over the keycode array starting at word_7CB21C, iterating while v1 < dword_7CB218. [global:0x007CB218, global:0x007CB21C, source:raw]
    // GUARD: Guard on the current keycode: trigger screenshot path only when *v3 == 88 (ASCII 'X'). [source:raw]
    // ASSIGNMENT: Select the screenshot directory: v4 = dword_5EC478, falling back to byte_5EA438 when dword_5EC478 is null. [global:0x005EA438, global:0x005EC478, source:raw]
    // CALL: Call sub_551FD0(0, 0, dword_8B8DD4, dword_8B8DD8, v4) to save the screen; the message path runs only when it returns 0. [callee:0x00551FD0, global:0x008B8DD4, global:0x008B8DD8, source:raw]
    // CALL: Look up the 'Screen Saved' string aScreenSaved in the string table via BinarySearchInStringTable(byte_5EC4C0, aScreenSaved, byte_5EC4CC) for localization. [callee:0x00423A00, global:0x005D240C, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // LOOP: Copy aScreenSaved into the display buffer byte_5EC4CC, character by character, until the null terminator is copied. [global:0x005D240C, global:0x005EC4CC, source:raw]
    // CALL: Render the message with TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060). [callee:0x0045BD10, global:0x005EC4CC, global:0x007CD204, source:raw]
    // CALL: Call CameraViewportRenderSetup(&unk_8AFFC8) to set up the camera viewport. [callee:0x004FBD70, global:0x008AFFC8, source:raw]
    // CALL: Call VehicleVisibilityCulling(this) on the current object. [callee:0x004B3DC0, source:raw]
    // RETURN: Return the result of sub_557120(dword_8AFE88); sub_557120 appears in the raw source but is not present in the packet callee list. [global:0x008AFE88, source:raw]

    // Conservative worker pseudocode:
    //   int RenderScreenSave(char *this) {
    //     for (int i = 0; i < dword_7CB218; i++) {
    //       if (word_7CB21C[i] == 88) {
    //         char *path = dword_5EC478 ? (char*)dword_5EC478 : byte_5EA438;
    //         if (!sub_551FD0(0, 0, dword_8B8DD4, dword_8B8DD8, path)) {
    //           if (BinarySearchInStringTable(byte_5EC4C0, aScreenSaved, byte_5EC4CC)) {
    //             int j = 0;
    //             do { byte_5EC4CC[j] = aScreenSaved[j]; j++; } while (aScreenSaved[j-1]);
    //           }
    //           TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
    //         }
    //       }
    //     }
    //     CameraViewportRenderSetup(&unk_8AFFC8);
    //     VehicleVisibilityCulling(this);
    //     return sub_557120(dword_8AFE88);
    //   }
    // UNRESOLVED: sub_557120, called with dword_8AFE88 and returned, is not present in the packet callee list so its address cannot be recorded.
    // UNRESOLVED: The meaning of literal 16909060 passed to TextLineWrappingAndRendering and of keycode 88 mapping to 'X' is inferred from ASCII only.
    // UNRESOLVED: dword_8B8DC8 is listed among packet globals but does not appear in the raw source text, so its role here is unknown.
}
