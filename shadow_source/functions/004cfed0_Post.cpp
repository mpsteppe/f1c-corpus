// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CFED0
// Canonical corpus name: SpecialFX_Post
// Owner: SpecialFX [DERIVED]
// Raw source: functions/SpecialFX_Post_004cfed0.c

void SpecialFX::Post()
{
    // Special-effects teardown. Optionally logs entry via a debug-log gate, then frees every allocated array (a 60-byte-stride emitter array and two 108-byte-stride arrays, each with a count word stored 4 bytes before the pointer), cleans the collision tree nodes, and zeroes all twelve fields. Called from Game_Post when leaving the game session.
    // GUARD: Debug-log gate: if StringSplitLoop(2, aDDevF119992002_25, 3371) is nonzero, run the entry log write. [global:0x005D3624, callee:0x004D7A50, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredSpecial_3) writes the 'entered special' message to the global log channel. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D39F0]
    // ASSIGNMENT: Zero this+0x0, the emitter count field. [field:this:0x00000000]
    // GUARD: If this+0x4 is non-null, the 60-byte-stride array is live and is freed. [field:this:0x00000004]
    // LOOP: Walk the 60-byte-stride emitter array backwards (count stored at ptr-4, element i at ptr + 60*i), calling sub_4CA280 on each element as a per-element destructor/cleanup. [field:this:0x00000004, callee:0x004CA280]
    // CALL: FreeWrapper_7bcf(ptr-4) releases the count-header buffer of the emitter array, then this+0x4 is zeroed. [callee:0x00587BCF, field:this:0x00000004]
    // CALL: CollisionTreeNodeCleanup((int)dbl_7C9360) tears down the collision tree node pool referenced by the global. [callee:0x0044C470, global:0x007C9360]
    // GUARD: If this+0xC is non-null, the first 108-byte-stride array is live and is freed. [field:this:0x0000000C]
    // LOOP: Walk the 108-byte-stride array backwards (27 dwords per element), calling FreeIfNonNull on each element. [field:this:0x0000000C, callee:0x00499AE0]
    // CALL: FreeWrapper_7bcf(ptr-4) releases the count-header buffer of the first 108-byte-stride array. [callee:0x00587BCF, field:this:0x0000000C]
    // ASSIGNMENT: Before the element loop this+0x8 and this+0xC are zeroed (count fields for the 108-byte arrays). [field:this:0x00000008, field:this:0x0000000C]
    // LOOP: For this+0x10 iterations, call MultiFieldFree on each 108-byte-stride element of the array whose base is this+0x14. [field:this:0x00000010, field:this:0x00000014, callee:0x004CB4F0]
    // GUARD: If this+0x14 is non-null, the second 108-byte-stride array is live and is freed. [field:this:0x00000014]
    // LOOP: Walk the 108-byte-stride array backwards calling sub_4CA410 on each element as a per-element destructor. [field:this:0x00000014, callee:0x004CA410]
    // CALL: FreeWrapper_7bcf(ptr-4) releases the count-header buffer of the second 108-byte-stride array. [callee:0x00587BCF, field:this:0x00000014]
    // ASSIGNMENT: Zero the remaining fields this+0x14, 0x10, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, resetting the special-effects system to a pristine state. [field:this:0x00000014, field:this:0x00000010, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // RETURN: Return the value carried through by the last FreeWrapper_7bcf call (result). [source:raw]

    // Conservative worker pseudocode:
    //   // SpecialFX::Post - teardown of the special-effects system.
    //   if (StringSplitLoop(2, aDDevF119992002_25, 3371))
    //       DebugLogWrite(&dword_8AD25C, aEnteredSpecial_3);
    //   this->count_emitter = 0;                 // this+0x00
    //   if (this->pArray60) {                    // this+0x04, 60-byte stride
    //       for (i = count; i > 0; --i) sub_4CA280(&this->pArray60[(i-1)*15]);
    //       FreeWrapper_7bcf((char*)this->pArray60 - 4);
    //       this->pArray60 = 0;
    //   }
    //   CollisionTreeNodeCleanup(dbl_7C9360);
    //   if (this->pArray108a) {                  // this+0x0C, 108-byte stride
    //       for (i = count; i > 0; --i) FreeIfNonNull(&this->pArray108a[(i-1)*27]);
    //       FreeWrapper_7bcf((char*)this->pArray108a - 4);
    //   }
    //   this->pArray108a = 0; this->count108a = 0; // this+0x0C, this+0x08
    //   for (i = 0; i < this->count108b; ++i)       // this+0x10 count, this+0x14 base
    //       MultiFieldFree(&this->pArray108b[i*27]);
    //   if (this->pArray108b) {                  // this+0x14
    //       for (i = count; i > 0; --i) sub_4CA410(&this->pArray108b[(i-1)*27]);
    //       FreeWrapper_7bcf((char*)this->pArray108b - 4);
    //   }
    //   this->pArray108b = 0; this->count108b = 0;
    //   this->field_0x18 = this->field_0x1C = this->field_0x20 = 0;
    //   this->field_0x24 = this->field_0x28 = this->field_0x2C = 0;
    // UNRESOLVED: sub_4CA280 and sub_4CA410 per-element destructors have unknown semantics (likely different emitter sub-types).
    // UNRESOLVED: The count word stored 4 bytes before each array pointer suggests a custom counted allocation layout that is not independently confirmed.
    // UNRESOLVED: Field this+0x8 is only observed being zeroed; its role as a count is inferred from the surrounding free loops.
    // UNRESOLVED: Field this+0x10 is read as the loop bound but its writer is elsewhere.
}
