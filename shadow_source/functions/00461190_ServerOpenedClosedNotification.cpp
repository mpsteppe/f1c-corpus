// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461190
// Canonical corpus name: ServerOpenedClosedNotification
// Owner: ServerSessionManager [DERIVED]
// Raw source: functions/ServerOpenedClosedNotification_00461190.c

void ServerSessionManager::ServerOpenedClosedNotification()
{
    // Server track open/close notification. Chooses the 'opened'/'closed' message verb from flag a2 and stores related session state on `this` (a float timer at +0x2C and a flag at +0x29 cleared on close). When debug logging is enabled (dword_7D0398 nonzero), reads the track name, formats '*** The server {opened|closed} {trackname}', copies it into a heap buffer, appends a node to the debug-log linked list owned by `this` (head +0x1B770, tail +0x1B774, first +0x1B778, count +0x1B77C), renders the message to the UI resource, and conditionally writes it to the debug log via DebugLogWrite (skipped for server sessions, dword_7C569C == 5).
    // GUARD: Branch on opened flag a2: nonzero takes the 'opened' path, zero takes the 'closed' path. [source:raw]
    // ASSIGNMENT: Opened path: select aOpened as message verb and set this+0x2C to 1084227584. [global:0x005C612C, field:this:0x0000002C]
    // ASSIGNMENT: Closed path: select aClosed as message verb, set this+0x2C to -1082130432 (-1.0f), and clear this+0x29 to 0. [global:0x005C6124, field:this:0x0000002C, field:this:0x00000029]
    // GUARD: Entire notification body gated on global dword_7D0398; when zero, skip the whole block and return. [global:0x007D0398]
    // CALL: OperatorNewNhMallocWrapper(8) allocates the message-buffer wrapper (char**). [callee:0x00587C03]
    // ASSIGNMENT: On allocation success the buffer wrapper v5 is initialized (*v5 = 0, v5[1] = -1); on failure v6 is set to 0. [source:raw]
    // CALL: TrackNameReader(v10, 63) reads the current track name into the 64-byte stack buffer. [callee:0x004C5920]
    // CALL: StringFormatWithBufferOverflowCheck(v11, '*** The server %s %s', message_text, track_name) formats the notification string. [callee:0x0058815F, global:0x005C610C]
    // CALL: StringCopyWithBufferRealloc(v11) copies the formatted message into a reallocating buffer. [callee:0x00566650]
    // GUARD: Only when the buffer wrapper v6 is non-null, allocate and append a debug-log linked-list node. [source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates the 12-byte linked-list node. [callee:0x00587C03]
    // ASSIGNMENT: Node v7 initialized: [0] = v6 (buffer wrapper), [4] = 0 (next pointer), [8] = 0 (flag byte). [source:raw]
    // GUARD: Branch on the existing list head stored at this+0x1B770 to pick append vs first-node path. [field:this:0x0001B770]
    // ASSIGNMENT: Append path: *(*(this+0x1B774)+4) = v7 links the current tail node's next pointer to the new node. [field:*(this+0x1B774):0x00000004]
    // ASSIGNMENT: First-node path: this+0x1B770 = v7 (head) and this+0x1B778 = v7 (first). [field:this:0x0001B770, field:this:0x0001B778]
    // ASSIGNMENT: Tail update: this+0x1B774 = v7; increment the node count at this+0x1B77C. [field:this:0x0001B774, field:this:0x0001B77C]
    // ASSIGNMENT: v8 = *v6 (message string from buffer); when null, fall back to byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: TextLineWrappingAndRendering(&dword_7CD204, v8, 3, 16909060) renders the notification message to the UI resource. [callee:0x0045BD10, global:0x007CD204]
    // GUARD: Dev-log write only executed when session type dword_7C569C != 5 (not a server session). [global:0x007C569C]
    // CALL: StringSplitLoop(1, aDDevF119992002_1, 4935) checks the dev-path verbosity condition. [callee:0x004D7A50, global:0x005C5CE4]
    // GUARD: Only when StringSplitLoop returned nonzero, write the debug log entry. [source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, v9) appends the message to the debug log; v9 falls back to byte_5EA438 when *v6 is null. [callee:0x004D7AA0, global:0x008AD25C, global:0x005EA438]
    // RETURN: Return the accumulated result value (the dword_7D0398 guard value, or the last call result). [source:raw]

    // Conservative worker pseudocode:
    //   // this = session owner; a2 = opened flag
    //   if (a2) { msg = aOpened; this->+0x2C = 1084227584; }
    //   else    { msg = aClosed; this->+0x2C = -1082130432; this->+0x29 = 0; }
    //   
    //   if (!dword_7D0398) return;
    //   
    //   buf = OperatorNewNhMallocWrapper(8);            // message buffer wrapper
    //   TrackNameReader(track_name, 63);
    //   StringFormatWithBufferOverflowCheck(formatted, "*** The server %s %s", msg, track_name);
    //   StringCopyWithBufferRealloc(formatted);
    //   
    //   if (buf) {
    //       node = OperatorNewNhMallocWrapper(12);      // debug-log list node
    //       node[0] = buf; node[1] = 0; node[2] = 0;
    //       if (this->+0x1B770)                         // list head
    //           *(this->+0x1B774)[1] = node;            // link old tail -> new node
    //       else { this->+0x1B770 = node; this->+0x1B778 = node; }
    //       this->+0x1B774 = node;                      // tail
    //       this->+0x1B77C++;                           // count
    //   }
    //   
    //   text = (buf && *buf) ? *buf : byte_5EA438;
    //   TextLineWrappingAndRendering(&dword_7CD204, text, 3, 16909060);
    //   
    //   if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 4935))
    //       DebugLogWrite(&dword_8AD25C, text);
    //   return;
    // UNRESOLVED: Global flt_59F0B4 (0x0059F0B4) is listed in the packet as referenced but does not appear in the raw Hex-Rays body text; role unknown.
    // UNRESOLVED: Global unk_8AC368 (0x008AC368) is listed in the packet as referenced but does not appear in the raw Hex-Rays body text; role unknown.
    // UNRESOLVED: Exact class/type name of the `this` owner is a DERIVED proposal (ABI lead 'Server_Opened_Closed_Notification' + sole caller ConditionalStateDispatch); no CONFIRMED type from static corpus.
    // UNRESOLVED: Semantics of this+0x2C (1084227584 on opened, -1.0f on closed) and this+0x29 are inferred as track open/close progress/flag state from the surrounding code; not independently confirmed.
}
