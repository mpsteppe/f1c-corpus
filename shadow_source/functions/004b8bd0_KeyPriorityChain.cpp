// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8BD0
// Canonical corpus name: KeyPriorityChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyPriorityChain_004b8bd0.c

void UnknownObject::KeyPriorityChain()
{
    // Priority-ordered classification chain over the session-type flag byte_7CA594 (0x007CA594). Calls SessionTypeFlagGuard (0x0044F4A0) four times with the flag constants 203, 200, 208 and 205; the first matching flag short-circuits to a small integer key (0, 1, 3, 4 respectively), defaulting to 2 when none match. No fields or side effects; used by sub_4B9890 and ConditionalMultiPathDispatcher (0x004BA180).
    // GUARD: If SessionTypeFlagGuard(byte_7CA594, 203) is nonzero, return key 0. [callee:0x0044F4A0, global:0x007CA594, function:0x004B8BD0, source:raw]
    // GUARD: If SessionTypeFlagGuard(byte_7CA594, 200) is nonzero, return key 1. [callee:0x0044F4A0, global:0x007CA594, function:0x004B8BD0, source:raw]
    // GUARD: If SessionTypeFlagGuard(byte_7CA594, 208) is nonzero, return key 3. [callee:0x0044F4A0, global:0x007CA594, function:0x004B8BD0, source:raw]
    // RETURN: Final conditional: return 4 when SessionTypeFlagGuard(byte_7CA594, 205) is nonzero, otherwise return the default key 2. [callee:0x0044F4A0, global:0x007CA594, function:0x004B8BD0, source:raw]
    // CALL: Invoked from sub_4B9890 (0x004B9890) and ConditionalMultiPathDispatcher (0x004BA180). [caller:0x004B9890, caller:0x004BA180]

    // Conservative worker pseudocode:
    //   int KeyPriorityChain() {
    //     if (SessionTypeFlagGuard(byte_7CA594, 203)) return 0;
    //     if (SessionTypeFlagGuard(byte_7CA594, 200)) return 1;
    //     if (SessionTypeFlagGuard(byte_7CA594, 208)) return 3;
    //     return SessionTypeFlagGuard(byte_7CA594, 205) ? 4 : 2;
    //   }
    // UNRESOLVED: The mapping between session flag constants (200, 203, 205, 208) and the returned priority keys (0, 1, 2, 3, 4) is not decoded into named session types; the constant-to-session association is unconfirmed.
    // UNRESOLVED: byte_7CA594 structure (single byte flags vs bitfield) is unknown; only that SessionTypeFlagGuard consumes it.
    // UNRESOLVED: The returned key's consumer meaning (priority table index) is unconfirmed.
    // UNRESOLVED: Owner object identity is not established; the function is global-state only.
}
