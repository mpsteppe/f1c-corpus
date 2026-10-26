// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004673B0
// Canonical corpus name: MenuOptionValueDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuOptionValueDisplay_004673b0.c

void UnknownObject::MenuOptionValueDisplay()
{
    // Menu-option value display formatter. Seeds a 61-byte local format buffer with the first byte of byte_5EA438 then zeroes the rest, loads the option's selection type from this+0x32C and dispatches to VehicleSetupValueFormatter when it equals 4 or SetupValueFormatDispatcher otherwise, both writing into byte_7C56C0. Formats the option value string (this+0x320, text starting 30 bytes into the value block) into the local buffer with the "%s" format via StringFormatWithBufferOverflowCheck, then returns StringCompareAndConditionalReplace(v4), which replaces the displayed string only when it changed.
    // ASSIGNMENT: Local buffer seeding: first byte copied from byte_5EA438 into v4[0], the remaining 60 bytes zeroed via memset, then the 16-bit v5 and byte v6 tail fields zeroed [global:0x005EA438, source:raw]
    // ASSIGNMENT: Selection type loaded from this+0x32C into v2 to pick the formatter branch [field:this:0x0000032C, source:raw]
    // GUARD: Branch on selection type: vehicle-setup formatter path only when this+0x32C equals 4, otherwise generic dispatcher path [field:this:0x0000032C, source:raw]
    // CALL: VehicleSetupValueFormatter invoked with byte_7C56C0 as the output target and the string-pointer field at this+0x324 as the value source when the selection type equals 4 [callee:0x0042F470, field:this:0x00000324, global:0x007C56C0, source:raw]
    // CALL: SetupValueFormatDispatcher invoked with byte_7C56C0, the selection type loaded from this+0x32C, and the parameter field at this+0x328 for all non-4 selection types [callee:0x0042F2F0, field:this:0x0000032C, field:this:0x00000328, global:0x007C56C0, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the option value string into the local buffer using the "%s" literal at 0x005C2C18; the source string is read 30 bytes past the pointer stored at this+0x320 [callee:0x0058815F, field:this:0x00000320, global:0x005C2C18, source:raw]
    // CALL: Return value produced by StringCompareAndConditionalReplace on the formatted buffer, replacing the display only when the formatted value differs [callee:0x00467430, source:raw]
    // CALL: Invoked by the indexed dispatch driver IndexedCallWith1Increment as the value-display step of a menu option [caller:0x00467340, source:raw]

    // Conservative worker pseudocode:
    //   char v4[61];
    //   v4[0] = byte_5EA438[0];
    //   memset(&v4[1], 0, 0x3C);
    //   v5 = 0;
    //   v6 = 0;
    //   v2 = *(dword*)(this + 0x32C);
    //   if (v2 == 4) {
    //     VehicleSetupValueFormatter(&byte_7C56C0, *(char***)(this + 0x324));
    //   } else {
    //     SetupValueFormatDispatcher(&byte_7C56C0, v2, *(dword*)(this + 0x328));
    //   }
    //   StringFormatWithBufferOverflowCheck(v4, "%s", (char*)(*(dword*)(this + 0x320) + 30));
    //   return StringCompareAndConditionalReplace(v4);
    // UNRESOLVED: Identity and role of byte_7C56C0 (session-name buffer versus file-loader flag in prior analysis) not established from this packet alone
    // UNRESOLVED: Reason the first byte of byte_5EA438 is copied into the format buffer head is unclear; byte_5EA438 otherwise reads as a directory/path string
    // UNRESOLVED: Why the option value string begins 30 bytes into the block pointed to by this+0x320 is not resolvable without the value-block layout
    // UNRESOLVED: Semantics of the return value of StringCompareAndConditionalReplace (match indicator versus replace result) not confirmed
}
