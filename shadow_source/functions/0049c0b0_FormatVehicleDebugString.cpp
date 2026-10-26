// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C0B0
// Canonical corpus name: sub_49C0B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C0B0_0049c0b0.c

void UnknownObject::FormatVehicleDebugString()
{
    // Copies the default string asc_5CCE54 into the caller buffer, then selects a vehicle struct pointer either by a sub_4D1B50 index lookup into the vehicle array base unk_5EC6D8 or directly from dword_7C54E0. If the selected pointer is non-null and a float field at offset 16552 (indexed by a value read from dword_7C54E0 + 16448) is greater than 0.0, formats a debug string from offset 18168 of the struct using off_5C3730 and outputs it through sub_589901. Returns 0 on every path.
    // ASSIGNMENT: Copy the default string asc_5CCE54 into the caller buffer lpSrcStr via strcpy and keep the destination as v2. [global:0x005CCE54, source:raw]
    // GUARD: Test bit 0 of byte_7CFFF0 (TextRenderFlag); if set, take the vehicle-index lookup path. [global:0x007CFFF0, source:raw]
    // CALL: Call sub_4D1B50(0) to retrieve a vehicle index v3 (range 0-254). [callee:0x004D1B50, source:raw]
    // GUARD: If v3 equals 255 (invalid/not-found), return 0 immediately. [source:raw]
    // CALCULATION: Select the vehicle struct as unk_5EC6D8 + 18624 * v3 (array base plus 18624-byte stride times index). [global:0x005EC6D8, source:raw]
    // ASSIGNMENT: Else-path: select v4 directly from dword_7C54E0 (postProcessInput pointer). [global:0x007C54E0, source:raw]
    // GUARD: If v4 is non-null AND the float at v4 + 4 * (dword value at dword_7C54E0 + 16448) + 16552 is greater than 0.0, proceed to format the debug string. [global:0x007C54E0, source:raw]
    // CALL: Format into v2 with the format pointer off_5C3730 and the struct string at v4 + 18168 via StringFormatWithBufferOverflowCheck. [global:0x005C3730, callee:0x0058815F, source:raw]
    // CALL: Output the formatted string v2 through sub_589901. [callee:0x00589901, source:raw]
    // RETURN: Return 0 on all paths. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatVehicleDebugString(char* out) {
    //     const CHAR* dst = strcpy(out, asc_5CCE54);
    //     char* veh;
    //     if ((byte_7CFFF0 & 1) != 0) {
    //       int idx = sub_4D1B50(0);
    //       if (idx == 255) return 0;
    //       veh = (char*)&unk_5EC6D8 + 18624 * idx;
    //     } else {
    //       veh = (char*)dword_7C54E0;
    //     }
    //     if (veh && *(float*)&veh[4 * *(int*)(dword_7C54E0 + 16448) + 16552] > 0.0f) {
    //       StringFormatWithBufferOverflowCheck(dst, &off_5C3730, veh + 18168);
    //       sub_589901(dst);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440 and dword_8ACEE0 are listed in the packet globals but are absent from the raw source body; their role in this function is unclear.
    // UNRESOLVED: Argument a2 is unused by the decompiled body.
    // UNRESOLVED: Identity of the float field at offset 16552 (analysis prose calls it a time field) and of the string at offset 18168 is only DERIVED from the fill.
}
