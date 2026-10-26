// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D99E0
// Canonical corpus name: HUDVenue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HUDVenue_004d99e0.c

void UnknownObject::HUDVenue()
{
    // Venue/track-name HUD overlay. Timer-gated: this[4] is decremented by dbl_8AFE98 each call and the function hides (returns 1) once it drops below 0. When season races data is available it resolves a venue-name string and a secondary string from the race database via StringKeyedLinkedListSearch/DataEntryAccessor on off_5D4AF8 and off_5D4AFC. The venue name is rendered at (640, 818); a decorative separator is built by copying byte_5EA438 into the buffer and appending the byte_5D4AEC character 16 times, then rendered at y = 858; the secondary string is rendered at (640, 898). All text uses UITextRenderWithScale with color 0xFFFFFF, font 2, and text-rendering results go through a string-table dedupe check (BinarySearchInStringTable) into byte_5EC4CC.
    // GUARD: Timer hide gate: return 1 when this[4] < 0.0 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Decrement display timer: this[4] = this[4] - dbl_8AFE98 [field:this:0x00000010, global:0x008AFE98, source:raw]
    // CALL: SeasonRacesSectionFinder(0); when it returns 0 the venue-name branch is skipped [callee:0x004C5840, source:raw]
    // CALL: Resolve strings from the race database: StringKeyedLinkedListSearch(off_5D4AF8[0]) then DataEntryAccessor yields the venue name v2; StringKeyedLinkedListSearch(off_5D4AFC) then DataEntryAccessor yields the secondary string v10 [callee:0x005679C0, callee:0x00567970, global:0x005D4AF8, global:0x005D4AFC, source:raw]
    // CALL: Render venue name when v2 is present: BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC) and if matched strcpy(byte_5EC4CC, v2); sub_587DD0(v12, byte_5EC4CC, 127); then UITextRenderWithScale(v12, 640, 818, 0xFFFFFF, 2, 0, 1.0, 1.0) [callee:0x00423A00, callee:0x00587DD0, callee:0x004D7E40, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Build separator character: StringFormatWithBufferOverflowCheck(v11, "%c", byte_5D4AEC) formats the single separator character (format literal address held by the aC global) [callee:0x0058815F, global:0x005CCEF0, global:0x005D4AEC, source:raw]
    // LOOP: Copy byte_5EA438 string into v12 until the NUL terminator [global:0x005EA438, source:raw]
    // LOOP: Append the separator character 16 times: strcat(v12, v11) repeated while a 16-run counter is nonzero [source:raw]
    // CALL: Render separator line: UITextRenderWithScale(v12, v5, 858, 0xFFFFFF, 2, 3, 1.0, 1.0) [callee:0x004D7E40, source:raw]
    // CALL: Render secondary string when v10 is present: BinarySearchInStringTable(byte_5EC4C0, v10, byte_5EC4CC) and if matched strcpy(byte_5EC4CC, v10); sub_587DD0(v12, byte_5EC4CC, 127); then UITextRenderWithScale(v12, 640, 898, 0xFFFFFF, 2, 0, 1.0, 1.0) [callee:0x00423A00, callee:0x00587DD0, callee:0x004D7E40, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // RETURN: Return 0 after rendering (only the timer-hide path returns 1) [source:raw]

    // Conservative worker pseudocode:
    //   if (this[4] < 0.0) return 1;
    //   this[4] = this[4] - dbl_8AFE98;
    //   v2 = NULL; v10 = NULL;
    //   if (SeasonRacesSectionFinder(0)) {
    //     v3 = StringKeyedLinkedListSearch(off_5D4AF8[0]);
    //     if (v3) v2 = DataEntryAccessor(v3);
    //     v4 = StringKeyedLinkedListSearch(off_5D4AFC);
    //     if (v4) v10 = DataEntryAccessor(v4);
    //     if (v2) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC)) strcpy(byte_5EC4CC, v2);
    //       sub_587DD0(v12, byte_5EC4CC, 127);
    //       UITextRenderWithScale(v12, 640, 818, 0xFFFFFF, 2, 0, 1.0, 1.0);
    //     }
    //   }
    //   StringFormatWithBufferOverflowCheck(v11, "%c", byte_5D4AEC);
    //   i = 0; do { v12[i++] = byte_5EA438[i]; } while (v12[i-1]);
    //   n = 16; do { strcat(v12, v11); } while (--n);
    //   UITextRenderWithScale(v12, 640, 858, 0xFFFFFF, 2, 3, 1.0, 1.0);
    //   if (v10) {
    //     if (BinarySearchInStringTable(byte_5EC4C0, v10, byte_5EC4CC)) strcpy(byte_5EC4CC, v10);
    //     sub_587DD0(v12, byte_5EC4CC, 127);
    //     UITextRenderWithScale(v12, 640, 898, 0xFFFFFF, 2, 0, 1.0, 1.0);
    //   }
    //   return 0;
    // UNRESOLVED: Two read-only globals flagged by packet facts appear nowhere in the raw decompiled source (flt_59E440 and unk_8AC368); they carry physics-looking names in prior analysis and are likely spurious for this HUD function
    // UNRESOLVED: The uninitialized local v8 feeds v5 on the no-venue branch (LABEL_12); the x position used for the separator render in that path is not determinable from this packet
    // UNRESOLVED: No static callers are recorded, so the owner object and the HUD integration point are unknown
}
