// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046DD30
// Canonical corpus name: MultiplayerPasswordValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiplayerPasswordValidation_0046dd30.c

void UnknownObject::MultiplayerPasswordValidation()
{
    // Multiplayer password/entrant validation for the session join flow. Creates (or fetches) UI element ID 34 through a vtable call on a UI factory object at this+0x40, retrieves the entered text via UIScreenTextAccessor_9950, converts it to an entrant identifier with sub_587ECE, prepares a scenario buffer with FAILWRONGDESCRIPTION, and validates the entrant against the game module manager (dword_7CD25C) through a thiscall function pointer. When validation passes, the password buffer is empty, and the flag at offset 0x6E of the result is set, the password entry UI is shown (LookupDispatch + sub_4988D0). Otherwise, if SendJoinRequest succeeds, this+0xE4 is set to 4.0f. Always finishes with EmptyStub_0170 and returns -1.
    // CALL: Call the UI object factory via the vtable at this+0x40 (vtable offset 28 = 0x1C) with element ID 34; store the resulting UI object. [field:this:0x00000040, field:*(this+0x40):0x00000000, field:*(*(this+0x40)+0x0):0x0000001C, abi:lead, source:raw]
    // GUARD: If the UI object factory returned null (v2 == 0), skip the entire validation body. [source:raw]
    // CALL: Call FieldGetter(v2); its result must be >= 0 to continue. [callee:0x00489940]
    // CALL: Call UIScreenTextAccessor_9950(v3) to retrieve the entered text content; if it returns null, skip the remaining body. [callee:0x00489950]
    // CALL: Call sub_587ECE(v4) to convert the UI text into an entrant identifier. [callee:0x00587ECE]
    // CALL: Call FAILWRONGDESCRIPTION(v8) to prepare the failure/wrong-description scenario buffer. [callee:0x00461550]
    // CALL: Invoke the entrant-validation thiscall through the function pointer at loc_462010 with (dword_7CD25C, v5, v8, 0, 0, &v7). The direct call target loc_462010 is not listed among packet callees. [global:0x007CD25C, source:raw]
    // GUARD: Validation succeeds only if BitFlagTestAt0x6E(v8, 2) is nonzero, i.e. bit 2 of the result buffer flag is set. [callee:0x004615F0]
    // GUARD: Require the MultiClientPassword buffer byte_7CD850 to be empty (strlen == 0) before showing the password entry UI. [global:0x007CD850, source:raw]
    // CALL: Branch A: LookupDispatch(aMultiClientPas, -1) looks up the multiplayer password entry screen by string identifier. [callee:0x00497940, global:0x005C6C70]
    // CALL: Branch A: sub_4988D0(aClientPassword) triggers the password entry dialog with the 'ClientPassword' prompt string. [callee:0x004988D0, global:0x005C6C58]
    // CALL: Branch B: SendJoinRequest(dword_7CD25C, v5, &byte_7CD850) submits a join request with the current password buffer. [callee:0x00462C00, global:0x007CD25C, global:0x007CD850]
    // ASSIGNMENT: When SendJoinRequest succeeds, write 1082130432 (4.0f) to this+0xE4. [field:this:0x000000E4, source:raw]
    // CALL: Call EmptyStub_0170(v8) after either branch; a stub/cleanup call. [callee:0x004B0170]
    // RETURN: Return -1 on every path. [function:0x0046DD30, source:raw]

    // Conservative worker pseudocode:
    //   obj = uiFactory(this+0x40).createOrGet(34);
    //   if (!obj) return -1;
    //   if (FieldGetter(obj) < 0) return -1;
    //   text = UIScreenTextAccessor_9950(obj);
    //   if (!text) return -1;
    //   id = sub_587ECE(text);
    //   FAILWRONGDESCRIPTION(buf);
    //   if (ValidateEntrant(g_moduleMgr, id, buf, 0, 0, &out) && BitFlagTestAt0x6E(buf, 2) && strlen(g_password) == 0) {
    //     LookupDispatch(aMultiClientPas, -1);
    //     sub_4988D0(aClientPassword);
    //   } else if (SendJoinRequest(g_moduleMgr, id, g_password)) {
    //     this->field_E4 = 4.0f;
    //   }
    //   EmptyStub_0170(buf);
    //   return -1;
    // UNRESOLVED: The entrant-validation call target loc_462010 is a thiscall function pointer inside the function; it is present in the raw source but absent from the packet callee list, so its identity is unresolved.
    // UNRESOLVED: Semantics of FAILWRONGDESCRIPTION, LookupDispatch, sub_4988D0 and EmptyStub_0170 are only inferred from names and call shape.
    // UNRESOLVED: Meaning of the 4.0f value written to this+0xE4 and the exact role of byte_7CD850 (password buffer) are not proven.
}
