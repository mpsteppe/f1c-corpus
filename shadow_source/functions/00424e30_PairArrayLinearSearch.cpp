// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424E30
// Canonical corpus name: PairArrayLinearSearch
// Owner: CommandQueue [DERIVED]
// Raw source: functions/PairArrayLinearSearch_00424e30.c

void CommandQueue::PairArrayLinearSearch()
{
    // Linear search over an array of 8-byte {commandID, param} pairs stored in the AI command queue (buffer pointer at this+0x44A8, entry count at this+0x44B0). Returns 1 if a pair's first dword equals a2, otherwise 0. Called by CommandQueueResponseHandler for duplicate-command detection.
    // GUARD: Read queue entry count from this+0x44B0. If negative, the queue is empty, so no duplicate is possible: return 0 immediately. [field:this:0x000044B0, source:raw]
    // ASSIGNMENT: Load the queue buffer pointer stored at this+0x44A8 as the scan base; each element is an 8-byte {commandID, param} pair. [field:this:0x000044A8, source:raw]
    // LOOP: Scan pairs with 8-byte stride, comparing the first dword of each pair against a2. [field:this:0x000044A8, source:raw]
    // CALCULATION: Increment probe index and compare against the count at this+0x44B0; if the probe exceeds the count, the search is exhausted and 0 is returned. [field:this:0x000044B0, source:raw]
    // RETURN: Return 1 when a matching command ID is found; CommandQueueResponseHandler consumes this as a deduplication signal before enqueueing a command. [function:0x00424E30, caller:0x00429EE0]

    // Conservative worker pseudocode:
    //   if (this->queue_count < 0) return 0;
    //   for (i = this->queue_buffer; i->command_id != a2; i += 2) {
    //       if (++probe_index > this->queue_count) return 0;
    //   }
    //   return 1;
    // UNRESOLVED: The command-queue interpretation of fields 0x44A8/0x44B0 is inferred from the caller name CommandQueueResponseHandler; not independently proven.
    // UNRESOLVED: How the caller consumes the duplicate result is not visible from this function.
    // UNRESOLVED: Exact meaning of the second dword (param) of each pair is not referenced here.
}
