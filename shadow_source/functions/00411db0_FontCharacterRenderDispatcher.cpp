// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411DB0
// Canonical corpus name: FontCharacterRenderDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FontCharacterRenderDispatcher_00411db0.c

void UnknownObject::FontCharacterRenderDispatcher()
{
    // Dispatches font character rendering on the character code at a2+8. Special code 9875 (with a5 in {397, 426}) renders via sub_412490 then DecrementCounterWithFloorAtZero; special code 9876 (with a5 in 1..2) uses EnumValueTranslation then the same counter decrement. The general case resolves a field index with GlobalFieldSelectorByIndex(a1) (negative result returns -1), takes the string at *(a2) falling back to byte_5EA438 when null, copies it via StringCopyWithBufferRealloc, and writes the code, field index and a zero flag into the a4 output buffer (+8/+12/+16), returning 1. Called by FontRenderingPrep (00411840).
    // GUARD: Reads the character code at a2+8 and branches on it; codes 9875 and 9876 take dedicated paths [source:raw]
    // GUARD: Code 9875 with a5 outside {397, 426} returns -1 immediately [source:raw]
    // CALL: sub_412490(a4, 1, *(a3+20), 0, 0) renders the special 9875 character into the a4 buffer [callee:0x00412490, source:raw]
    // CALL: DecrementCounterWithFloorAtZero(a4) after the 9875 special render [callee:0x00414140, source:raw]
    // GUARD: Code 9876 with a5 not in the range 1..2 returns -1 immediately [source:raw]
    // CALL: EnumValueTranslation(a4, *(a3+20)) translates the value for special code 9876 [callee:0x00414010, source:raw]
    // CALL: DecrementCounterWithFloorAtZero(a4) after the 9876 translation [callee:0x00414140, source:raw]
    // CALL: GlobalFieldSelectorByIndex(a1) resolves the field index for the general case; a negative result returns -1 [callee:0x00414160, source:raw]
    // ASSIGNMENT: Source string v10 = *(a2); when *(a2) is null it defaults to byte_5EA438 [global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v10) copies the string into a reallocated buffer [callee:0x00566650, source:raw]
    // ASSIGNMENT: Writes mapped values into the output buffer a4: character code v11 to +8, field index v9 to +12, and zero flag to +16 [source:raw]
    // RETURN: Returns 1 on the general success path, v6/v8 on the two special-code paths, and -1 on every rejected path [source:raw]
    // CALL: Invoked by FontRenderingPrep as part of font rendering preparation [caller:0x00411840, source:raw]

    // Conservative worker pseudocode:
    //   code = *(a2 + 8);
    //   if (code == 9875) {
    //       if (a5 != 397 && a5 != 426) return -1;
    //       v = sub_412490(a4, 1, *(a3 + 20), 0, 0);
    //       DecrementCounterWithFloorAtZero(a4);
    //       return v;
    //   }
    //   if (code == 9876) {
    //       if (a5 <= 0 || a5 > 2) return -1;
    //       v = EnumValueTranslation(a4, *(a3 + 20));
    //       DecrementCounterWithFloorAtZero(a4);
    //       return v;
    //   }
    //   fieldIdx = GlobalFieldSelectorByIndex(a1);
    //   if (fieldIdx < 0) return -1;
    //   str = *(char**)a2;
    //   if (str == NULL) str = &byte_5EA438;
    //   code = *(a2 + 8);
    //   StringCopyWithBufferRealloc(str);
    //   *(a4 + 8)  = code;
    //   *(a4 + 12) = fieldIdx;
    //   *(byte)(a4 + 16) = 0;
    //   return 1;
    // UNRESOLVED: Offsets read on a2 (+8, +0) and a3 (+20) describe the font character state block and its parent data, but the packet declares no field evidence refs for them
    // UNRESOLVED: Writes at a4+8/+12/+16 describe an output buffer whose struct layout is not evidenced
    // UNRESOLVED: Literals 9875, 9876, 397, 426 are character-code/variant constants; their exact meaning is unproven
}
