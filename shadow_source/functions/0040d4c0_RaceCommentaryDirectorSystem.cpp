// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D4C0
// Canonical corpus name: RaceCommentaryDirectorSystem
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceCommentaryDirectorSystem_0040d4c0.c

void UnknownObject::RaceCommentaryDirectorSystem()
{
    // Initializes a race commentary/cinematic director state from a configuration data block. Parses a config list into an action type (camera select/target/acquire/release/set-last, commentary start/stop, fly-over, gridwalk, wait, script-end), then optional probability, time, iterations and wait tokens, and finally resolves the target entity (camera name, grid position, driver, or commentary topic). Returns 1 on success and 0 (after re-initializing the struct) on failure. Not on the per-frame path; called by session/cinematic handlers.
    // CALL: StructFieldInit(this) resets the director struct before configuration parsing [callee:0x0040D490, source:raw]
    // ASSIGNMENT: Set this+40 (0x28) result code to -1, then store the config data block pointer a2 into this+4 (0x4) [field:this:0x00000028, field:this:0x00000004, source:raw]
    // GUARD: If a2 is zero, skip parsing and jump directly to the result path LABEL_73 [source:raw]
    // CALL: StringKeyedLinkedListSearch(aType_0) (0x005BEB08) locates the 'Type' config list; if not found, jump to LABEL_73 [callee:0x005679C0, global:0x005BEB08, source:raw]
    // CALL: DataEntryAccessor(v3) resolves the matched list node into the data entry v4 used by all token tests [callee:0x00567970, source:raw]
    // GUARD: Nested sub_588410 token tests on the data entry, evaluated first-match-wins in priority order: aCameraSelect (0x005BEAF8), aCameraTargetSe (0x005BEAE0), aCameraAcquireC (0x005BEAC8), aCameraReleaseC (0x005BEAB0), aCameraSetLast (0x005BEAA0), aCommentaryStar (0x005BEA8C), aCommentaryStop (0x005BEA7C), aFlyOver (0x005BEA70), aGridwalk (0x005BEA64), aWait (0x005BEA5C), aScriptEnd (0x005BEA50) [callee:0x00588410, global:0x005BEAF8, global:0x005BEAE0, global:0x005BEAC8, global:0x005BEAB0, global:0x005BEAA0, global:0x005BEA8C, global:0x005BEA7C, global:0x005BEA70, global:0x005BEA64, global:0x005BEA5C, global:0x005BEA50, source:raw]
    // ASSIGNMENT: The first matching token selects the action type written to this+36 (0x24): aScriptEnd->0, aWait->12, aGridwalk->11, aFlyOver->10, aCommentaryStop->9, aCommentaryStar->8, aCameraSetLast->7, aCameraReleaseC->6, aCameraAcquireC->3, aCameraTargetSe->2, aCameraSelect->5, no match->4 [field:this:0x00000024, source:raw]
    // GUARD: Optional-token parsing runs only when the resolved action type at this+36 (0x24) is non-zero [field:this:0x00000024, source:raw]
    // CALL: Probability token: StringKeyedLinkedListSearch(aProbability) (0x005BEA44) -> DataEntryAccessor -> sub_58850F parses the float into this+12 (0xC); when the token is absent this+12 is set to the literal 1065353216 (1.0) [callee:0x005679C0, callee:0x00567970, callee:0x0058850F, global:0x005BEA44, field:this:0x0000000C, source:raw]
    // CALL: Time token: StringKeyedLinkedListSearch(aTime) (0x005BEA3C) -> DataEntryAccessor -> sub_58850F parses the value into this+16 (0x10); when the token is absent this+16 is set to 0 [callee:0x005679C0, callee:0x00567970, callee:0x0058850F, global:0x005BEA3C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Time mode: if the time token's first byte is the '+' literal (43) the mode is relative (this+20/0x14 = 2), otherwise absolute (this+20 = 1); a missing time token leaves this+20 = 2 and this+16 = 0 [field:this:0x00000014, field:this:0x00000010, source:raw]
    // CALL: Iterations token: StringKeyedLinkedListSearch(aIterations) (0x005BEA30) -> DataEntryAccessor -> sub_587ECE parses the repeat count into this+24 (0x18); a missing token or a value below 1 is clamped to 1 [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, global:0x005BEA30, field:this:0x00000018, source:raw]
    // CALL: Wait flag: StringKeyedLinkedListSearch(aWait_0) (0x005BEA28) -> DataEntryAccessor -> sub_588410 tests against aNo (0x005BEA24); the byte at this+32 (0x20) is set to 1 when the token is absent or equals aNo [callee:0x005679C0, callee:0x00567970, callee:0x00588410, global:0x005BEA28, global:0x005BEA24, field:this:0x00000020, source:raw]
    // STATE_TRANSITION: Dispatch on the action type at this+36 (0x24) through the jump table jpt_40D72B (0x0040D950) [field:this:0x00000024, global:0x0040D950, source:raw]
    // STATE_TRANSITION: Action types 2, 3, 8, 9, 0xA, 0xB and 0xC converge on the shared path LABEL_54 and set this+40 (0x28) = 2 [field:this:0x00000028, source:raw]
    // STATE_TRANSITION: Camera-target actions (types 4 and 6): this+44 (0x2C) starts at 0, then StringKeyedLinkedListSearch(aCamera) (0x005BEA1C) -> DataEntryAccessor -> CameraTargetNameResolver resolves the camera target into this+44; this+40 (0x28) = 2 * (this+44 == 0) + 2, gated on the equality guard [field:this:0x0000002C, field:this:0x00000028, callee:0x005679C0, callee:0x00567970, callee:0x0040DB00, global:0x005BEA1C, guard:0, source:raw]
    // STATE_TRANSITION: Position-target action (type 5): this+40 = 4 and this+44 = -1, then StringKeyedLinkedListSearch(aPosition_0) (0x005BEA10) -> DataEntryAccessor -> SingleFunctionCallWrapper_7f59 resolves a position value; when in range [1, dword_5C329C] the array dword_7C54F0 is scanned until a vehicle whose 16480 field equals the value is found, writing that vehicle's 18580 field into this+44 (0x2C); the success path LABEL_54 sets this+40 = 2 [field:this:0x00000028, field:this:0x0000002C, callee:0x005679C0, callee:0x00567970, callee:0x00587F59, global:0x005BEA10, global:0x005C329C, global:0x007C54F0, source:raw]
    // GUARD: When aPosition_0 is absent, StringKeyedLinkedListSearch(aDriver_0) (0x005BEA08) -> DataEntryAccessor runs; if the driver token is not aPlayer_0 (0x005BE9FC), this+44 (0x2C) becomes the 18580 field of dword_7C54E8 and this+40 = 2 [callee:0x005679C0, callee:0x00567970, callee:0x00588410, global:0x005BEA08, global:0x005BE9FC, global:0x007C54E8, field:this:0x0000002C, field:this:0x00000028, source:raw]
    // STATE_TRANSITION: Commentary-target action (type 7): this+40 = 4 and this+44 = -1, then StringKeyedLinkedListSearch(aCommentary) (0x005BE9F0) runs nested sub_588410 tests aGreeting (0x005BE9E4) -> aWelcomeToCount (0x005BE9D0) -> aTrackInfo (0x005BE9C4) -> aWeather_0 (0x005BE9BC) -> not aCrowd (0x005BE9B4) assigning this+44 (0x2C) = 4/3/2/1/0; when this+44 >= 0 (non-negative guard) this+40 = 2 [field:this:0x00000028, field:this:0x0000002C, callee:0x005679C0, callee:0x00567970, callee:0x00588410, global:0x005BE9F0, global:0x005BE9E4, global:0x005BE9D0, global:0x005BE9C4, global:0x005BE9BC, global:0x005BE9B4, guard:1, source:raw]
    // STATE_TRANSITION: Default and type 1: this+36 (0x24) is reset to 0, then LABEL_72 sets this+40 (0x28) = 4 [field:this:0x00000024, field:this:0x00000028, source:raw]
    // RETURN: LABEL_73 result path: v30 = this+40 (0x28); when v30 == 4, this+24 (0x18) is zeroed; when v30 != -1 return 1 (success), otherwise StructFieldInit(this), reset this+40 = -1 and return 0 (failure) [field:this:0x00000028, field:this:0x00000018, callee:0x0040D490, source:raw]
    // CALL: Invoked by ConditionalDelegation (0040DD30) and CinematicEventStateMachine (0040DDF0) to initialize a commentary director state from a config block [caller:0x0040DD30, caller:0x0040DDF0, source:raw]

    // Conservative worker pseudocode:
    //   StructFieldInit(this);
    //   this[0x28] = -1;
    //   this[0x4] = a2;
    //   if (!a2) goto LABEL_73;
    //   list = StringKeyedLinkedListSearch(aType_0);
    //   if (!list) goto LABEL_73;
    //   entry = DataEntryAccessor(list);
    //   // first-match-wins token chain selects the action type:
    //   if (sub_588410(entry, aCameraSelect)) this[0x24] = 5;
    //   else if (sub_588410(entry, aCameraTargetSe)) this[0x24] = 2;
    //   else if (sub_588410(entry, aCameraAcquireC)) this[0x24] = 3;
    //   else if (sub_588410(entry, aCameraReleaseC)) this[0x24] = 6;
    //   else if (sub_588410(entry, aCameraSetLast)) this[0x24] = 7;
    //   else if (sub_588410(entry, aCommentaryStar)) this[0x24] = 8;
    //   else if (sub_588410(entry, aCommentaryStop)) this[0x24] = 9;
    //   else if (sub_588410(entry, aFlyOver)) this[0x24] = 10;
    //   else if (sub_588410(entry, aGridwalk)) this[0x24] = 11;
    //   else if (sub_588410(entry, aWait)) this[0x24] = 12;
    //   else if (sub_588410(entry, aScriptEnd)) this[0x24] = 0;
    //   else this[0x24] = 4;
    //   if (this[0x24] != 0) {
    //     parse probability token into this[0xC] or 1065353216;
    //     parse time token into this[0x10] (default 0);
    //     this[0x14] = (time token first byte is '+') ? 2 : 1;
    //     this[0x18] = max(parse iterations token, 1);
    //     this[0x20] = !aWait_0_token || sub_588410(entry, aNo);
    //   }
    //   switch (this[0x24]) {
    //     case 1: goto LABEL_72;
    //     case 2: case 3: case 8: case 9: case 0xA: case 0xB: case 0xC: goto LABEL_54;
    //     case 4: case 6: resolve camera target into this[0x2C]; this[0x28] = 2*(this[0x2C]==0)+2; break;
    //     case 5: resolve position/driver target into this[0x2C] via dword_7C54F0/dword_7C54E8; this[0x28] = 2; break;
    //     case 7: resolve commentary topic into this[0x2C]; if (this[0x2C] >= 0) this[0x28] = 2; break;
    //     default: this[0x24] = 0; LABEL_72: this[0x28] = 4; break;
    //     LABEL_54: this[0x28] = 2; break;
    //   }
    //   LABEL_73:
    //   if (this[0x28] == 4) this[0x18] = 0;
    //   if (this[0x28] != -1) return 1;
    //   StructFieldInit(this);
    //   this[0x28] = -1;
    //   return 0;
    // UNRESOLVED: sub_588410 token-match semantics (string containment vs equality) are not documented in this packet
    // UNRESOLVED: sub_58850F (float) and sub_587ECE (integer) config-entry parsing formats are unverified
    // UNRESOLVED: SingleFunctionCallWrapper_7f59's conversion of the position value is unverified
    // UNRESOLVED: The vehicle-array fields at offsets 16480 and 18580 used with dword_7C54F0 and dword_7C54E8 are unlabeled
    // UNRESOLVED: Action type 1 is not produced by the token chain (assigned types are 0 and 2..12), so its dispatch path is unreachable through normal parsing
    // UNRESOLVED: this+0x2C is both the gated result field (==0 and >=0 guards) and the resolved target-entity id
}
