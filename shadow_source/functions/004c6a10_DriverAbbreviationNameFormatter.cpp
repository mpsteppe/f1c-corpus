// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6A10
// Canonical corpus name: DriverAbbreviationNameFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverAbbreviationNameFormatter_004c6a10.c

void UnknownObject::DriverAbbreviationNameFormatter()
{
    // Formats a driver name into an abbreviated display string and stores it in the object's name-output field (copied to this+18168, NUL-terminated at this+18183 / +0x4707). Primary path, gated by an AudioChannelStop(this+17952) validity probe, looks up an "Abbreviation" data section through StringKeyedLinkedListSearch, resolves its data entry with DataEntryAccessor, binary-searches the string table, and emits the "%-.13s" format. Fallback path binary-searches the driver-name source field directly, bounded-copies it into a 64-byte scratch buffer, extracts the character following the word_5C32D8 marker via sub_587C20 to emit an initial-dot "%c. %-.11s" form (or plain "%-.13s" when no marker exists). Finalizes the buffer with sub_589901 and stores it. Invoked from SetDriverName (caller 0x004C6980).
    // GUARD: Entry guard: skip the whole body when this equals the sentinel value -17952 (null/heap sentinel check on the __thiscall receiver). Function is the abbreviation formatter invoked from SetDriverName (caller 0x004C6980) during driver-name setup. [source:raw, abi:lead, caller:0x004C6980]
    // CALCULATION: Compute v2 = this + 17952, the pointer to the driver-name source field used by the fallback lookup. [source:raw]
    // CALL: AudioChannelStop(this + 17952): invoked as an object/field validity probe; a nonzero result selects the abbreviation-section path. [callee:0x00568210, source:raw]
    // CALL: StringKeyedLinkedListSearch(aAbbreviation): search the data linked list for the "Abbreviation" section key; result stored as v3. [callee:0x005679C0, global:0x005D3214, source:raw]
    // CALL: DataEntryAccessor(v3): resolve the linked-list search result into the abbreviation data entry string (v4). [callee:0x00567970, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, v4, byte_5EC4CC): lookup the abbreviation entry in the string table, reporting whether a match was found. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: On a match, copy v4 into byte_5EC4CC; otherwise clear byte_5EC4CC[0] to empty the buffer. [global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", byte_5EC4CC): format the full abbreviation (the a13s "%-.13s" format) into the 16-byte output buffer. [callee:0x0058815F, global:0x005D320C, global:0x005EC4CC, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC): fallback lookup of the driver-name source field in the string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: On a fallback match, copy v2 into byte_5EC4CC; otherwise clear byte_5EC4CC[0] to empty the buffer. [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v7, byte_5EC4CC, 63): bounded copy (max 63 chars) of the resolved name into the 64-byte scratch buffer v7. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: v7[63] = 0: force NUL termination of the scratch buffer. [source:raw]
    // CALL: sub_587C20(v7, &word_5C32D8): locate the marker (word_5C32D8) inside v7 and return its position as v5. [callee:0x00587C20, global:0x005C32D8, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(SrcStr, "%c. %-.11s", v7[0], v5 + 1): emit the initial-dot abbreviated form using the character following the marker (the aC11s "%c. %-11s" format). [callee:0x0058815F, global:0x005D3200, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", v7): fallback full-name format when no marker was found (the a13s format). [callee:0x0058815F, global:0x005D320C, source:raw]
    // CALL: sub_589901(SrcStr): post-process the formatted output buffer (unknown finalization step). [callee:0x00589901, source:raw]
    // CALL: sub_587DD0(this + 18168, SrcStr, 15): bounded copy (max 15 chars) of the final abbreviation into the object's name-output field. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Write 0 to the byte at this + 18183 (field +0x4707): NUL-terminate the object's output name buffer. [field:this:0x00004707, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C6A10(char *this) {
    //     const char *nameSrc = this + 17952;
    //     if (this == (char *)-17952) return;
    //     int found;
    //     const char *entry;
    //     if (AudioChannelStop(this + 17952) &&
    //         (found = StringKeyedLinkedListSearch(aAbbreviation)) != 0) {
    //       entry = DataEntryAccessor(found);
    //       if (BinarySearchInStringTable(byte_5EC4C0, entry, byte_5EC4CC)) {
    //         if (entry) strcpy(byte_5EC4CC, entry);
    //         else byte_5EC4CC[0] = 0;
    //       }
    //       StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", byte_5EC4CC);
    //     } else {
    //       if (BinarySearchInStringTable(byte_5EC4C0, nameSrc, byte_5EC4CC)) {
    //         if (nameSrc) strcpy(byte_5EC4CC, nameSrc);
    //         else byte_5EC4CC[0] = 0;
    //       }
    //       sub_587DD0(v7, byte_5EC4CC, 63);
    //       v7[63] = 0;
    //       int at = sub_587C20(v7, &word_5C32D8);
    //       if (at)
    //         StringFormatWithBufferOverflowCheck(SrcStr, "%c. %-.11s", v7[0], (char *)(at + 1));
    //       else
    //         StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", v7);
    //     }
    //     sub_589901(SrcStr);
    //     sub_587DD0(this + 18168, SrcStr, 15);
    //     *((char *)this + 18183) = 0;
    //   }
    // UNRESOLVED: Semantics of sub_589901 applied to SrcStr are unknown (finalization/encoding step).
    // UNRESOLVED: AudioChannelStop is reused here as a validity probe; its real audio semantics and why it gates the abbreviation path are unexplained.
    // UNRESOLVED: Meaning of the word_5C32D8 marker matched by sub_587C20, and why the format skips the character after it (v5 + 1), is unknown.
    // UNRESOLVED: global:0x008AD3B4 (dword_8AD3B4) is listed in the packet but absent from the decompiled source text; its role here is unresolved.
}
