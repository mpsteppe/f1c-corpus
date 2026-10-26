// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00435390
// Canonical corpus name: CategoryScoringStateInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CategoryScoringStateInitializer_00435390.c

void UnknownObject::initializeCategoryScoringState()
{
    // Constructor-like initializer: writes 25 consecutive DWORD fields of the object at `this` (offset 0x0..0x60) to fixed literals. Field 0x0 is set to -1; field 0x10 to the decimal literal 1072693248; all remaining fields to 0. No reads, no globals, no branches. Returns `this`. Called once from SuspensionSetupSectionReader (0x00435410).
    // ASSIGNMENT: this[0] (offset 0x0) = -1 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[1] (offset 0x4) = 0 [field:this:0x00000004]
    // ASSIGNMENT: this[2] (offset 0x8) = 0 [field:this:0x00000008]
    // ASSIGNMENT: this[3] (offset 0xC) = 0 [field:this:0x0000000C]
    // ASSIGNMENT: this[4] (offset 0x10) = 1072693248 [field:this:0x00000010]
    // ASSIGNMENT: this[5] (offset 0x14) = 0 [field:this:0x00000014]
    // ASSIGNMENT: this[6] (offset 0x18) = 0 [field:this:0x00000018]
    // ASSIGNMENT: this[7] (offset 0x1C) = 0 [field:this:0x0000001C]
    // ASSIGNMENT: this[8] (offset 0x20) = 0 [field:this:0x00000020]
    // ASSIGNMENT: this[9] (offset 0x24) = 0 [field:this:0x00000024]
    // ASSIGNMENT: this[10] (offset 0x28) = 0 [field:this:0x00000028]
    // ASSIGNMENT: this[11] (offset 0x2C) = 0 [field:this:0x0000002C]
    // ASSIGNMENT: this[12] (offset 0x30) = 0 [field:this:0x00000030]
    // ASSIGNMENT: this[13] (offset 0x34) = 0 [field:this:0x00000034]
    // ASSIGNMENT: this[14] (offset 0x38) = 0 [field:this:0x00000038]
    // ASSIGNMENT: this[15] (offset 0x3C) = 0 [field:this:0x0000003C]
    // ASSIGNMENT: this[16] (offset 0x40) = 0 [field:this:0x00000040]
    // ASSIGNMENT: this[17] (offset 0x44) = 0 [field:this:0x00000044]
    // ASSIGNMENT: this[18] (offset 0x48) = 0 [field:this:0x00000048]
    // ASSIGNMENT: this[19] (offset 0x4C) = 0 [field:this:0x0000004C]
    // ASSIGNMENT: this[20] (offset 0x50) = 0 [field:this:0x00000050]
    // ASSIGNMENT: this[21] (offset 0x54) = 0 [field:this:0x00000054]
    // ASSIGNMENT: this[22] (offset 0x58) = 0 [field:this:0x00000058]
    // ASSIGNMENT: this[23] (offset 0x5C) = 0 [field:this:0x0000005C]
    // ASSIGNMENT: this[24] (offset 0x60) = 0 [field:this:0x00000060]
    // RETURN: Return `this` (result initialized to this at entry) [function:0x00435390, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   void initializeCategoryScoringState(int *this) {
    //       this[0] = -1;
    //       for (int i = 1; i <= 24; i++) {
    //           this[i] = (i == 4) ? 1072693248 : 0;
    //       }
    //   }
    // UNRESOLVED: Object class unknown; field meanings not established. Literal at offset 0x10 is written as decimal 1072693248 per raw source; no IEEE-754 interpretation is asserted here.
    // UNRESOLVED: Purpose of the -1 sentinel at offset 0x0 and the nonzero literal at 0x10 is not known from this function alone.
}
