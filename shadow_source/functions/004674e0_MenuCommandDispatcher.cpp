// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004674E0
// Canonical corpus name: MenuCommandDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuCommandDispatcher_004674e0.c

void UnknownObject::MenuCommandDispatcher()
{
    // Menu command dispatcher. After a state cleanup notification, switches on a command id stored at this+0x174 (values 446-458): command 446 builds an integer-format menu item, commands 447-450 build date/angle or message-formatted items depending on the flag byte_7D048C and the sub-type this+0x178, commands 451-454 jump out through a static jump table (jpt_467506), and commands 455-458 make an indirect call feeding the result into the menu item creator. The default path returns this+0x174 minus 446.
    // CALL: StateCleanupNotification(this) runs before any dispatch. [callee:0x00489CB0]
    // CALCULATION: result = this[93] - 446; the command id is read from this+0x174. [field:this:0x00000174, source:raw]
    // STATE_TRANSITION: switch on the command id this[93] (this+0x174) with cases 446, 447-450, 451-454, 455-458 and a default that returns this[93] - 446. [field:this:0x00000174, source:raw]
    // CALL: Case 446: SetupIntegerFormatDS(&byte_7C56C0, *(float*)&dword_7C737C, v3) formats the integer into the local buffer, byte_7C7378 is cleared to 0, then UIMenuItemCreator builds the menu item from the formatted text. [callee:0x00431950, global:0x007C56C0, global:0x007C737C, global:0x007C7378, callee:0x00489600]
    // GUARD: Cases 447-450 branch on the flag byte_7D048C: when set a single date/angle item (mode 3) is produced, otherwise a message path and a three-mode date/angle sequence are produced. [global:0x007D048C, source:raw]
    // CALL: When byte_7D048C is set: SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], v3, 3) followed by UIMenuItemCreator. [callee:0x00431AA0, global:0x007C56C0, field:this:0x00000178, callee:0x00489600]
    // GUARD: Else branch: when this[94] (this+0x178) equals 1 the message formatting path is taken before the date/angle sequence. [guard:0, field:this:0x00000178]
    // CALL: When this[94] == 1: MessageStringFormatter(&byte_7C56C0, v3) then UIMenuItemCreator for the message item. [callee:0x0042EC00, global:0x007C56C0, callee:0x00489600]
    // CALL: SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], v3, mode) is invoked with modes 2, 1 and 0, each followed by a UIMenuItemCreator call. [callee:0x00431AA0, global:0x007C56C0, field:this:0x00000178, callee:0x00489600]
    // STATE_TRANSITION: Cases 451-454 JUMPOUT(0x4675E5) through the static jump table jpt_467506 (global:0x00467674) with auxiliary data at byte_467684. [global:0x00467674, global:0x00467684, source:raw]
    // CALL: Cases 455-458 call an indirect handler (loc_4319DF+1) with &byte_7C56C0 and this[94], and feed its formatted output into UIMenuItemCreator. [global:0x007C56C0, field:this:0x00000178, callee:0x00489600, source:raw]
    // RETURN: Default case returns this[93] - 446 (this+0x174 minus 446). [field:this:0x00000174, function:0x004674E0]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this);
    //   cmd = this[93];
    //   switch (cmd) {
    //     case 446:
    //       SetupIntegerFormatDS(&byte_7C56C0, *(float*)&dword_7C737C, buf);
    //       byte_7C7378 = 0;
    //       UIMenuItemCreator(this, buf, 0, 0, 0, 0); break;
    //     case 447 ... 450:
    //       if (byte_7D048C) {
    //         SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], buf, 3);
    //         UIMenuItemCreator(this, buf, 0, 0, 0, 0);
    //       } else {
    //         if (this[94] == 1) {
    //           MessageStringFormatter(&byte_7C56C0, buf);
    //           UIMenuItemCreator(this, buf, 0, 0, 0, 0);
    //         }
    //         for (mode = 2; mode >= 0; --mode) {
    //           SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], buf, mode);
    //           UIMenuItemCreator(this, buf, 0, 0, 0, 0);
    //         }
    //       } break;
    //     case 451 ... 454: JUMPOUT(0x4675E5);
    //     case 455 ... 458:
    //       ((thiscall)(&loc_4319DF + 1))(&byte_7C56C0, this[94], buf);
    //       UIMenuItemCreator(this, buf, 0, 0, 0, 0); break;
    //     default: return cmd - 446;
    //   }
    // UNRESOLVED: The JUMPOUT(0x4675E5) target for cases 451-454 is not statically resolved here; the jump table contents at jpt_467506 are unknown.
    // UNRESOLVED: The indirect handler called for cases 455-458 (loc_4319DF+1) is not identified.
    // UNRESOLVED: byte_467684 is referenced as auxiliary jump-table data; its precise role is unconfirmed.
}
