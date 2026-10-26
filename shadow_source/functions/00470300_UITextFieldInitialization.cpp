// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470300
// Canonical corpus name: UITextFieldInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextFieldInitialization_00470300.c

void UnknownObject::UITextFieldInitialization()
{
    // Type-selected UI text field initializer. Switches on the text-field type selector at this+0x304 (cases 0x1AF..0x1B5). Each case clears a global buffer, binds that buffer to the text field through UtilityFunction_b7e0 (this, &buffer, length), sets the mode field this+0x2E8 (0 or 2), and for the password-mask types also sets the placeholder string pointer this+0x2FC to a mask literal. Case 0x1B3 instead routes through BoundedFieldSetter(this, 0xA0) and sets the flag byte this+0xE5 to 1. Case 0x1B5 clears its buffer and falls through to the default return 0. Always returns 0.
    // GUARD: Switch dispatch on the text-field type selector at this+0x304, selecting a case by the jump table at 0x004703E0. [field:this:0x00000304, global:0x004703E0, source:raw]
    // ASSIGNMENT: Case 0x1AF: clear the global buffer byte_7CD818 to 0. [global:0x007CD818, source:raw]
    // CALL: Case 0x1AF: bind the cleared buffer to the text field via UtilityFunction_b7e0(this, &byte_7CD818, 26). [callee:0x0048B7E0, global:0x007CD818, source:raw]
    // ASSIGNMENT: Case 0x1AF: point this+0x2FC at the mask/placeholder string aWwwwwwwwwwwwww, then fall to the shared return 0. [field:this:0x000002FC, global:0x005C6E2C, source:raw]
    // ASSIGNMENT: Case 0x1B0: clear byte_7CD834 to 0 and set the mode field this+0x2E8 to 0. [global:0x007CD834, field:this:0x000002E8, source:raw]
    // CALL: Case 0x1B0: bind the buffer via UtilityFunction_b7e0(this, &byte_7CD834, 26). [callee:0x0048B7E0, global:0x007CD834, source:raw]
    // ASSIGNMENT: Case 0x1B0: point this+0x2FC at the second mask/placeholder string aWwwwwwwwwwwwww_0, then fall to the shared return 0. [field:this:0x000002FC, global:0x005C6E40, source:raw]
    // ASSIGNMENT: Case 0x1B1: clear byte_7CD850 to 0 and set the mode field this+0x2E8 to 0. [global:0x007CD850, field:this:0x000002E8, source:raw]
    // CALL: Case 0x1B1: bind the buffer via UtilityFunction_b7e0(this, &byte_7CD850, 15), then fall to the shared return 0. [callee:0x0048B7E0, global:0x007CD850, source:raw]
    // CALL: Case 0x1B2: bind the uninitialized buffer via UtilityFunction_b7e0(this, &unk_7CD860, 32). [callee:0x0048B7E0, global:0x007CD860, source:raw]
    // ASSIGNMENT: Case 0x1B2: set the mode field this+0x2E8 to 2, then fall to the shared return 0. [field:this:0x000002E8, source:raw]
    // ASSIGNMENT: Case 0x1B3: set the mode field this+0x2E8 to 0. [field:this:0x000002E8, source:raw]
    // CALL: Case 0x1B3: run the bounded field setter BoundedFieldSetter(this, 0xA0). [callee:0x0048B8F0, source:raw]
    // ASSIGNMENT: Case 0x1B3: set the flag byte this+0xE5 to 1, then fall to the shared return 0. [field:this:0x000000E5, source:raw]
    // ASSIGNMENT: Case 0x1B5: clear byte_7CD880 to 0. [global:0x007CD880, source:raw]
    // CALL: Case 0x1B5: bind the buffer via UtilityFunction_b7e0(this, &byte_7CD880, 32), then fall through to the default. [callee:0x0048B7E0, global:0x007CD880, source:raw]
    // RETURN: Default/fall-through path and every case conclude with return 0. [function:0x00470300, source:raw]

    // Conservative worker pseudocode:
    //   int UITextFieldInitialization(int this) {
    //     switch (*(int*)(this + 0x304)) {
    //       case 0x1AF:
    //         byte_7CD818 = 0;
    //         UtilityFunction_b7e0(this, &byte_7CD818, 26);
    //         *(int*)(this + 0x2FC) = aWwwwwwwwwwwwww;
    //         break;
    //       case 0x1B0:
    //         byte_7CD834 = 0;
    //         *(int*)(this + 0x2E8) = 0;
    //         UtilityFunction_b7e0(this, &byte_7CD834, 26);
    //         *(int*)(this + 0x2FC) = aWwwwwwwwwwwwww_0;
    //         break;
    //       case 0x1B1:
    //         byte_7CD850 = 0;
    //         *(int*)(this + 0x2E8) = 0;
    //         UtilityFunction_b7e0(this, &byte_7CD850, 15);
    //         break;
    //       case 0x1B2:
    //         UtilityFunction_b7e0(this, &unk_7CD860, 32);
    //         *(int*)(this + 0x2E8) = 2;
    //         break;
    //       case 0x1B3:
    //         *(int*)(this + 0x2E8) = 0;
    //         BoundedFieldSetter(this, 0xA0);
    //         *(char*)(this + 0xE5) = 1;
    //         break;
    //       case 0x1B5:
    //         byte_7CD880 = 0;
    //         UtilityFunction_b7e0(this, &byte_7CD880, 32);
    //         break;
    //       default:
    //         break;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the object owning this text field and the exact meaning of the global buffers (byte_7CD818/7CD834/7CD850/7CD860/7CD880) is unknown; they appear to be track/multiplayer-input buffers per the existing analysis but are not proven here.
    // UNRESOLVED: What UtilityFunction_b7e0 does with (this, &buffer, length) and why case 0x1B3 uses the distinct BoundedFieldSetter path instead is unresolved.
    // UNRESOLVED: The type-selector enum values 0x1AF-0x1B5 are used as-is without a confirmed semantic mapping.
}
