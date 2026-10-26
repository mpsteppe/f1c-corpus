// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB730
// Canonical corpus name: FailureCategoryNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FailureCategoryNameLookup_004bb730.c

void UnknownObject::FailureCategoryNameLookup()
{
    // Maps a failure category identifier (1-9) to a human-readable component name string via a jump-table switch. Returns "Engine" for 1, "Gearbox" for 2, "Clutch" for 3 or 7, "Suspension" for 4, "Brakes" for 5, "Accident" for 6, "Electronics" for 8, "Fuel" for 9, and a default block for any other value. The category value is passed in the ecx/this register.
    // GUARD: Switch dispatch on the category value (passed as this) using the jump table jpt_4BB738. [global:0x004BB778, source:raw]
    // ASSIGNMENT: Case 1: select aEngine as the result string. [global:0x005C316C, source:raw]
    // ASSIGNMENT: Case 2: select aGearbox as the result string. [global:0x005C3164, source:raw]
    // ASSIGNMENT: Case 3 and case 7: select aClutch as the result string. [global:0x005C55CC, source:raw]
    // ASSIGNMENT: Case 4: select aSuspension as the result string. [global:0x005C317C, source:raw]
    // ASSIGNMENT: Case 5: select aBrakes as the result string. [global:0x005C3174, source:raw]
    // ASSIGNMENT: Case 6: select aAccident as the result string. [global:0x005D253C, source:raw]
    // ASSIGNMENT: Case 8: select aElectronics as the result string. [global:0x005D2530, source:raw]
    // ASSIGNMENT: Case 9: select aFuel_0 as the result string. [global:0x005D2528, source:raw]
    // ASSIGNMENT: Default case: select unk_5D2524 as the result for any out-of-range category. [global:0x005D2524, source:raw]
    // RETURN: Return the selected name string. [source:raw]

    // Conservative worker pseudocode:
    //   const char *FailureCategoryNameLookup(unsigned int category) {
    //     const char *result;
    //     switch (category) {
    //       case 1: result = aEngine; break;
    //       case 2: result = aGearbox; break;
    //       case 3: case 7: result = aClutch; break;
    //       case 4: result = aSuspension; break;
    //       case 5: result = aBrakes; break;
    //       case 6: result = aAccident; break;
    //       case 8: result = aElectronics; break;
    //       case 9: result = aFuel_0; break;
    //       default: result = (const char *)unk_5D2524; break;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The actual string contents of aEngine, aGearbox, aClutch, aSuspension, aBrakes, aAccident, aElectronics, aFuel_0 and unk_5D2524 are not present in the packet; component names are taken from existing_analysis labels.
    // UNRESOLVED: The exact pairing of switch cases to the jump table entries jpt_4BB738 is not individually verifiable from the raw source.
}
