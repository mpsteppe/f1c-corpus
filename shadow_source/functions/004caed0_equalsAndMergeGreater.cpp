// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CAED0
// Canonical corpus name: sub_4CAED0
// Owner: SpecialFX [DERIVED]
// Raw source: functions/sub_4CAED0_004caed0.c

void SpecialFX::equalsAndMergeGreater()
{
    // Deep structural equality check between this object and a2 (a2 is the caller's candidate object). Compares the DWORD at this+0x4, all float fields from this+0xC through this+0x4C, and then dereferences the sub-object pointer at this+0x50 and compares its DWORD, string and float fields. On any mismatch the function returns 0. When everything matches, it copies a2's larger DWORD from a2+0x58 into this+0x58 (merge of the greater priority/version value) and returns 1. Called by SpecialFX_Init during deduplication.
    // GUARD: If this+0x4 (DWORD object identifier) differs from the corresponding a2+0x4 value, return 0 immediately. [field:this:0x00000004, source:raw]
    // GUARD: Compare every float field on this (offsets 0xC, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C, 0x44, 0x48, 0x4C) with the matching float on a2; any inequality returns 0. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALCULATION: Dereference this+0x50 and a2+0x50 to obtain the two sub-object pointers (v3 from this, v2 from a2) that the subsequent deep comparison is performed on. [field:this:0x00000050, source:raw]
    // GUARD: Compare the sub-objects pointed to by this+0x50 and a2+0x50: DWORD at sub+0x20, string fields via strcmp, DWORDs at sub+0x58, sub+0x5C, sub+0x60, sub+0x64, sub+0x68 and sub+0x6C, plus two more strcmp string comparisons. Any mismatch or non-zero strcmp returns 0. [field:*(this+0x50):0x00000020, field:*(this+0x50):0x00000058, field:*(this+0x50):0x0000005C, field:*(this+0x50):0x00000060, field:*(this+0x50):0x00000064, field:*(this+0x50):0x00000068, field:*(this+0x50):0x0000006C, source:raw]
    // ASSIGNMENT: Read the DWORD at a2+0x58; if it is greater than the DWORD at this+0x58, write it into this+0x58 (keep the larger priority/version value). [field:this:0x00000058, source:raw]
    // RETURN: Return 1 when every equality check passed and the greater-value merge at this+0x58 was applied. [source:raw]

    // Conservative worker pseudocode:
    //   char SpecialFX::equalsAndMergeGreater(SpecialFX* other) {
    //     if (id != other->id) return 0;
    //     for each float field f in {0xC..0x4C}: if (this.f != other.f) return 0;
    //     Sub* a = subObject; Sub* b = other->subObject;
    //     if (a->flags != b->flags) return 0;
    //     if (strcmp(a->name, b->name)) return 0;
    //     for each dword field in {0x58,0x5C,0x60,0x64,0x68,0x6C}: if (a->f != b->f) return 0;
    //     if (strcmp(a->name2, b->name2)) return 0;
    //     if (strcmp(a->name3, b->name3)) return 0;
    //     if (other->priority > priority) priority = other->priority;
    //     return 1;
    //   }
    // UNRESOLVED: The two sub-object string comparisons (strcmp) operate at sub-object offsets not present in the extracted field evidence (only the DWORD/float offsets 0x20 and 0x58-0x6C are listed); their exact offsets remain unproven.
    // UNRESOLVED: Semantics of the float block 0xC-0x4C and the merged DWORD at this+0x58 (named priority/version by prior analysis) are DERIVED labels, not runtime-verified.
}
