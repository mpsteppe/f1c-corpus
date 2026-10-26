// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493480
// Canonical corpus name: sub_493480
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_493480_00493480.c

void UnknownObject::ParseUIActionCommand()
{
    // Parses UI action commands from a token stream. Initializes a local token buffer from the byte_5EA438 global, requires a2 (token stream) and a3 (event/trigger spec) to be non-null else returns -1, and increments a reentrancy counter at this+0x194. Loops while sub_491FB0 reports more tokens: it breaks early when the token buffer matches the asc_5CC4F4 compare string, otherwise matches the token against a chain of command keyword literals via sub_5654A0 (DoPage, DoPageTransition variants, TransitionAttr, DoLayer, SetSymbol, DropPopups, ExitGame, SimulateClick). Each command allocates a 28-byte node (OperatorNewNhMallocWrapper + F_7FieldSentineInit), tags it with a type value 1..12, and copies the token string in via StringCopyWithBufferRealloc. The node is appended to an event-linked action chain using one of four list helpers selected by which trigger keyword (Click/Release/Focus/Lostfocus) a3 matches through sub_588410. Decrements the reentrancy counter and returns 0.
    // ASSIGNMENT: Initialize the local token buffer: first byte from global byte_5EA438, then clear the remaining bytes and trailing fields with memset. [global:0x005EA438, source:raw]
    // GUARD: Guard on a2 and a3: return -1 immediately when either the token stream or the event/trigger spec is null. [source:raw]
    // CALCULATION: Increment the reentrancy/entry counter this[101] at offset 0x194 on entry. [field:this:0x00000194, source:raw]
    // LOOP: do-while loop over the token stream; sub_491FB0 advances the parser and reports whether more tokens remain. [callee:0x00491FB0, source:raw]
    // GUARD: Break the parse loop when sub_587C20 reports the token buffer matches the asc_5CC4F4 compare string. [callee:0x00587C20, global:0x005CC4F4, global:0x007CDB70, source:raw]
    // CALL: DoPage command (aDoPage keyword): allocate a 28-byte node tagged with type 1. [callee:0x005654A0, global:0x005CC908, source:raw]
    // CALL: DoPageTransition command (aDoPageTransiti keyword): allocate a 28-byte node tagged with type 2. [callee:0x005654A0, global:0x005CC8EC, source:raw]
    // CALL: DoPageTransition variant command (aDoPageTransiti_0 keyword): allocate a 28-byte node tagged with type 3. [callee:0x005654A0, global:0x005CC8D0, source:raw]
    // CALL: DoPageTransition variant command (aDoPageTransiti_1 keyword): allocate a 28-byte node tagged with type 4. [callee:0x005654A0, global:0x005CC8B0, source:raw]
    // CALL: DoPageTransition variant command (aDoPageTransiti_2 keyword): allocate a 28-byte node tagged with type 5. [callee:0x005654A0, global:0x005CC890, source:raw]
    // CALL: DoPageTransition variant command (aDoPageTransiti_3 keyword): allocate a 28-byte node tagged with type 6. [callee:0x005654A0, global:0x005CC870, source:raw]
    // CALL: TransitionAttr command (aTransitionAttr keyword): store a string-matched lookup result into the node field via StringMatchedLinkedListSearch. [callee:0x005654A0, global:0x005CC858, callee:0x0049A210, source:raw]
    // CALL: DoLayer command (aDoLayer keyword): allocate a 28-byte node tagged with type 7. [callee:0x005654A0, global:0x005CC84C, source:raw]
    // CALL: SetSymbol command (aSetSymbol keyword): split the token on the ':' plus tab delimiter via sub_5897CA and copy both parts; node tagged with type 9. [callee:0x005654A0, global:0x005CC544, callee:0x005897CA, source:raw]
    // CALL: DropPopups command (aDropPopups keyword): allocate a 28-byte node tagged with type 10. [callee:0x005654A0, global:0x005CC838, source:raw]
    // CALL: ExitGame command (aExitGame keyword): allocate a 28-byte node tagged with type 11. [callee:0x005654A0, global:0x005CC82C, source:raw]
    // CALL: SimulateClick command (aSimulateclick keyword): allocate a 28-byte node tagged with type 12. [callee:0x005654A0, global:0x005CC81C, source:raw]
    // CALL: Node allocation and initialization: OperatorNewNhMallocWrapper allocates 28 bytes, F_7FieldSentineInit initializes the node, and the first DWORD receives the command type tag. [callee:0x00587C03, callee:0x0049A580, source:raw]
    // CALL: Copy the current token string into the node buffer via StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // GUARD: Determine the event trigger from a3: sub_588410 matches a3 against the Click, Release, Focus and Lostfocus keyword literals in order. [callee:0x00588410, global:0x005CC844, global:0x005CC814, global:0x005CC80C, global:0x005CC800, source:raw]
    // CALL: Append the parsed node to the event-linked action chain (chain tail tracked at this+0x14): AppendToLinkedListTail for Click, LinkedListAppend for Release, LinkedListTailAppend for Focus, and LinkedListAppend_6540 for Lostfocus. [callee:0x00486480, callee:0x004864C0, callee:0x00486500, callee:0x00486540, field:this:0x00000014, source:raw]
    // CALCULATION: Decrement the reentrancy counter this[101] at offset 0x194 before returning. [field:this:0x00000194, source:raw]
    // RETURN: Return 0 on a successful parse, or -1 when either input argument was null. [source:raw]

    // Conservative worker pseudocode:
    //   int ParseUIActionCommand(_DWORD *this, _DWORD *tokens, _DWORD *trigger) {
    //     char token[128];
    //     token[0] = byte_5EA438[0];
    //     memset(token + 1, 0, 0x7C);
    //     if (!tokens || !trigger) return -1;
    //     ++this[101];
    //     if (sub_491FB0(this)) {
    //       do {
    //         if (sub_587C20(&unk_7CDB70, asc_5CC4F4)) break;
    //         int type = 0;
    //         if (sub_5654A0(aDoPage, token))           type = 1;
    //         else if (sub_5654A0(aDoPageTransiti, token))      type = 2;
    //         else if (sub_5654A0(aDoPageTransiti_0, token))    type = 3;
    //         else if (sub_5654A0(aDoPageTransiti_1, token))    type = 4;
    //         else if (sub_5654A0(aDoPageTransiti_2, token))    type = 5;
    //         else if (sub_5654A0(aDoPageTransiti_3, token))    type = 6;
    //         else if (sub_5654A0(aTransitionAttr, token))      { node[5] = StringMatchedLinkedListSearch(token); }
    //         else if (sub_5654A0(aDoLayer, token))    type = 7;
    //         else if (sub_5654A0(aSetSymbol, token))  { strcpy(tmp, ":\t"); split(token); type = 9; }
    //         else if (sub_5654A0(aDropPopups, token)) type = 10;
    //         else if (sub_5654A0(aExitGame, token))   type = 11;
    //         else if (sub_5654A0(aSimulateclick, token)) type = 12;
    //         if (type) {
    //           node = F_7FieldSentineInit(OperatorNewNhMallocWrapper(28));
    //           *node = type;
    //           StringCopyWithBufferRealloc(token);
    //           if (sub_588410(trigger, aClick))      AppendToLinkedListTail(tokens, node);
    //           else if (sub_588410(trigger, aRelease))   LinkedListAppend(tokens, node);
    //           else if (sub_588410(trigger, aFocus))     LinkedListTailAppend(tokens, node);
    //           else if (!sub_588410(trigger, aLostfocus)) LinkedListAppend_6540(tokens, node);
    //         }
    //       } while (sub_491FB0(this));
    //     }
    //     --this[101];
    //     return 0;
    //   }
    // UNRESOLVED: The exact semantics of the node type tags 1..12 beyond command identity are unknown; the node layout (28-byte, 7-field sentinel init) is not further interpreted here.
    // UNRESOLVED: Globals word_5CC540, byte_5CC542 and unk_7CD9D8 are listed as accessed but do not appear in the visible decompiled body; their role in this function is unestablished (likely adjacent string/state data).
    // UNRESOLVED: Whether this+0x14 is the chain tail written by the four list-append helpers, or an unrelated field, is not provable from this body alone (the helpers receive the chain pointer a2).
}
