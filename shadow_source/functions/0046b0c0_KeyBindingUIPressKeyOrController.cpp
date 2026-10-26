// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B0C0
// Canonical corpus name: KeyBindingUIPressKeyOrController
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyBindingUIPressKeyOrController_0046b0c0.c

void UnknownObject::KeyBindingUIPressKeyOrController()
{
    // State machine for the key-binding UI entry that prompts the user to press a key or controller button and finalizes the binding. Reads the currently selected entry index via FieldGetter, validates it against the entry array bound dword_7D1424, and fetches the entry name through ArrayIndexedAccessor on the ppvOut table. State this+0x1FC drives three branches: (1) state 1 shows the popup via LookupDispatch(aPopupControlSe), resets the child panel visibility byte *(this+0x40)+0x1589, loads the 'Press Key or Controller' prompt and the entry name into the this+0x174 string through BinarySearchInStringTable, and moves to state 2; (2) state 2 captures a raw parameter via ParameterLookupWithFallback, maps it with EnumToIDMappingWithDefaultFallthrough (default 89), rejecting reserved keys by repromising with aReservedKey and SpriteTextureEnumeration, and stores the captured value into this+0x200 and the mapped ID into this+0x204 before moving to state 3; (3) state 3 commits the binding through the shifted ControllerShifterMapping call, restores the child panel visibility byte, resets the state to 0. Returns the running value accumulator v5. Called by UIClickHandlerWithBoundsCheck (0046B070).
    // CALL: FieldGetter() returns the currently selected entry index, stored in v4 [callee:0x00489940, source:raw]
    // STATE_TRANSITION: If the a2 flag is nonzero, write state 1 into this+0x1FC (enter prompt state) [field:this:0x000001FC, source:raw]
    // GUARD: Entry index v4 must be in range 0..dword_7D1424 for the body to run [global:0x007D1424, source:raw]
    // CALL: ArrayIndexedAccessor(&ppvOut, v4) fetches the selected entry name; null entry skips the body [callee:0x00455560, global:0x007CA590, source:raw]
    // ASSIGNMENT: Seed the local parameter buffer with byte_5EA438[0] and zero the remaining 76 bytes plus trailing word/byte [global:0x005EA438, source:raw]
    // GUARD: State this+0x1FC == 1 (prompt state) selects the first branch [guard:1, field:this:0x000001FC, source:raw]
    // ASSIGNMENT: Write the selected entry index v4 into this+0x1F4 [field:this:0x000001F4, source:raw]
    // CALL: this+0x1F8 = BitmapSpriteAccessor(this+0x40), capturing the child panel's sprite handle [callee:0x00497980, field:this:0x00000040, field:this:0x000001F8, source:raw]
    // CALL: LookupDispatch(aPopupControlSe, -1) shows the popup control [callee:0x00497940, global:0x005C69E0, source:raw]
    // ASSIGNMENT: Clear the child panel visibility byte at *(this+0x40)+0x1589 [field:*(this+0x40):0x00001589, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aPressKeyOrCont, this+0x174) loads the 'Press Key or Controller' prompt string into the key-name buffer [callee:0x00423A00, global:0x005EC4C0, global:0x005C69B8, source:raw]
    // ASSIGNMENT: Append the word_5C32D8 terminator at the end of the this+0x174 prompt string [global:0x005C32D8, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, entryName, byte_5EC4CC) and on success copy the entry name into the byte_5EC4CC buffer, then strcat it onto the this+0x174 prompt [callee:0x00423A00, global:0x005EC4CC, source:raw]
    // STATE_TRANSITION: Write accumulator 1 into this+0x208 and move state this+0x1FC to 2 (wait for input) [field:this:0x00000208, field:this:0x000001FC, source:raw]
    // GUARD: State this+0x1FC == 2 (input capture) selects the second branch [guard:2, field:this:0x000001FC, source:raw]
    // CALL: ParameterLookupWithFallback(&ppvOut, localBuffer, &v13, this+0x208) captures the pressed key/button; v13 is initialized to 0 and v14 holds the default 89 [callee:0x00454D30, global:0x007CA590, field:this:0x00000208, source:raw]
    // ASSIGNMENT: Reset the lookup accumulator this+0x208 to 0 after the capture call [field:this:0x00000208, source:raw]
    // STATE_TRANSITION: If the capture succeeded, move state this+0x1FC to 3 (finalize) and if v13 is zero map the default with EnumToIDMappingWithDefaultFallthrough [callee:0x00454C20, field:this:0x000001FC, source:raw]
    // GUARD: A mapped ID below zero is a reserved key: copy the aReservedKey string into byte_5EC4CC, call SpriteTextureEnumeration(byte_5EC4CC), revert the mapping to 89, and set state this+0x1FC back to 2 [global:0x005C69F4, global:0x005EC4CC, callee:0x00498950, field:this:0x000001FC, source:raw]
    // ASSIGNMENT: Store the captured raw value into this+0x200 and the mapped ID into this+0x204 [field:this:0x00000200, field:this:0x00000204, source:raw]
    // GUARD: State this+0x1FC == 3 (finalize) selects the third branch (also reachable as state minus 3) [guard:0, field:this:0x000001FC, source:raw]
    // CALL: Commit the binding: call ControllerShifterMapping (via the shifted address of unk_46A9BF), restore the child panel visibility byte *(this+0x40)+0x1589 to 1, call sub_4988C0(1), and dispatch the captured sprite via LookupDispatch(this+0x1F8, -1) [callee:0x0046A9C0, field:*(this+0x40):0x00001589, callee:0x004988C0, callee:0x00497940, field:this:0x000001F8, source:raw]
    // STATE_TRANSITION: After the finalize branch runs, reset state this+0x1FC to 0 (idle) [field:this:0x000001FC, source:raw]
    // RETURN: Return the running value accumulator v5 as the function result [function:0x0046B0C0, source:raw]
    // CALL: Invoked by UIClickHandlerWithBoundsCheck (0046B070) when the user clicks the key-binding UI entry [caller:0x0046B070, source:raw]

    // Conservative worker pseudocode:
    //   idx = FieldGetter();
    //   if (a2) this[0x1FC] = 1;
    //   if (idx >= 0 && idx < dword_7D1424) {
    //     name = ArrayIndexedAccessor(&ppvOut, idx);
    //     if (name) {
    //       zero buffer v15;
    //       if (this[0x1FC] == 1) {
    //         this[0x1F4] = idx;
    //         this[0x1F8] = BitmapSpriteAccessor(this[0x40]);
    //         LookupDispatch(aPopupControlSe, -1);
    //         *(this[0x40])[0x1589] = 0;
    //         BinarySearchInStringTable(byte_5EC4C0, aPressKeyOrCont, this[0x174]);
    //         append word_5C32D8 to this[0x174];
    //         if (BinarySearchInStringTable(byte_5EC4C0, name, byte_5EC4CC))
    //           strcpy(byte_5EC4CC, name);
    //         strcat(this[0x174], byte_5EC4CC);
    //         this[0x208] = 1; this[0x1FC] = 2;
    //       } else if (this[0x1FC] == 2) {
    //         ok = ParameterLookupWithFallback(&ppvOut, v15, &raw, this[0x208]);
    //         this[0x208] = 0;
    //         if (ok) {
    //           this[0x1FC] = 3;
    //           if (raw == 0) {
    //             mapped = EnumToIDMappingWithDefaultFallthrough(89);
    //             if (mapped >= 0) { if (mapped != 89) mapped = 89; }
    //             else {
    //               copy aReservedKey to byte_5EC4CC;
    //               SpriteTextureEnumeration(byte_5EC4CC);
    //               mapped = 89; this[0x1FC] = 2;
    //             }
    //           }
    //           this[0x200] = raw;
    //           this[0x204] = mapped;
    //         }
    //       } else if (this[0x1FC] == 3) {
    //         ControllerShifterMapping(this);
    //         *(this[0x40])[0x1589] = 1;
    //         sub_4988C0(1);
    //         LookupDispatch(this[0x1F8], -1);
    //         this[0x1FC] = 0;
    //       }
    //     }
    //   }
    //   return accumulator;
    // UNRESOLVED: The mapped ID, raw captured value, and the exact semantics of the 89 default and of EnumToIDMappingWithDefaultFallthrough are unknown; the condition chain for a mapped value >= 0 but != 89 falls through to keeping 89
    // UNRESOLVED: The this+0x174 key-name buffer, the child panel offset 0x1589 base relation, and the internals of sub_4988C0 and SpriteTextureEnumeration are not defined by this packet
    // UNRESOLVED: The exact meaning of the byte_5EC4CC string table lookup and the aReservedKey conflict path depends on the string-table format not described here
}
