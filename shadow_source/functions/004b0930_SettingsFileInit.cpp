// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0930
// Canonical corpus name: SettingsFileInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SettingsFileInit_004b0930.c

void UnknownObject::SettingsFileInit()
{
    // Settings-file initialization: copies vehicle data fields onto the settings object, builds a settings file path into a local buffer seeded from byte_5EA438 via NamePathFormatterWithLengthCheck, clears the file read-only attribute with mask 128, reads the career section data from that file via CareerSectionReader, and returns 0. Straight-line, no guards.
    // CALL: VehicleDataFieldCopy(this): copy the vehicle data fields onto the settings object before path building. [callee:0x004B0E30, source:raw]
    // ASSIGNMENT: Seed FileName[0] with the first byte of the global byte_5EA438, establishing the base of the path buffer. [global:0x005EA438, source:raw]
    // CALL: memset(&FileName[1], 0, 0xFC): zero-fill the remaining 0xFC bytes of the path buffer. [source:raw]
    // ASSIGNMENT: Clear the trailing stack bytes v4 and v5 after the buffer, keeping the path region zero-terminated. [source:raw]
    // CALL: NamePathFormatterWithLengthCheck(this, FileName, 0x100): format a settings file path from the object's name into FileName with the 0x100-byte capacity limit. [callee:0x004B02B0, source:raw]
    // CALL: ToggleFileReadOnlyAttributeViaWin32API(FileName, 128): toggle the file read-only attribute on the formatted path using attribute mask 128. [callee:0x0058BA36, source:raw]
    // CALL: CareerSectionReader(FileName): read the career section data from the settings file. [callee:0x004C2700, source:raw]
    // RETURN: Return 0 as success; the function is invoked by sub_4B0770 (0x004B0770) and NameCompareAndFormat (0x004B1410). [source:raw, caller:0x004B0770, caller:0x004B1410]

    // Conservative worker pseudocode:
    //   int SettingsFileInit(void* this) {
    //     VehicleDataFieldCopy(this);
    //     FileName[0] = byte_5EA438[0];
    //     memset(&FileName[1], 0, 0xFC);
    //     v4 = 0;
    //     v5 = 0;
    //     NamePathFormatterWithLengthCheck(this, FileName, 0x100);
    //     ToggleFileReadOnlyAttributeViaWin32API(FileName, 128);
    //     CareerSectionReader(FileName);
    //     return 0;
    //   }
    // UNRESOLVED: The role and content of byte_5EA438 beyond seeding FileName[0] (directory prefix or default application path) is unverified.
    // UNRESOLVED: The class owning this settings-file initialization is unknown; abi legacy name Settings_File_Init is unconfirmed.
    // UNRESOLVED: The exact effect of attribute mask 128 in ToggleFileReadOnlyAttributeViaWin32API (likely FILE_ATTRIBUTE_NORMAL) is not established from this packet.
}
