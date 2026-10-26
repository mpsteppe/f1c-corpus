// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E0A0
// Canonical corpus name: sub_57E0A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57E0A0_0057e0a0.c

void UnknownObject::MonitorConnectionTimeouts()
{
    // Per-frame connection maintenance: decrements a countdown timer at this+2724 (0xAA4) by the frame delta a2 and, on expiry, resets it to 0.05f (1028443341) and runs a maintenance pass. The pass reads the current time, takes a mutex-protected connection list, walks each node, and drops connections whose drop flag is set or whose idle time exceeds the threshold, optionally dispatching a format-timer callback chain first. Messages are formatted and dispatched through sub_57DE30. Releases the mutex before returning.
    // CALCULATION: Decrement the countdown timer at this+2724 (0xAA4) by the frame delta a2 and store the result back. [field:this:0x00000AA4]
    // GUARD: Branch on the decremented timer being less than or equal to zero (expired); the maintenance pass runs only when the guard holds. [field:this:0x00000AA4]
    // ASSIGNMENT: Reset the expired timer at this+2724 (0xAA4) to the float 0.05f, stored as integer 1028443341. [field:this:0x00000AA4]
    // CALL: MutexGuardedTimerRead(this) returns the current maintenance time, saved as v31. [callee:0x00584F90]
    // ASSIGNMENT: Load the connection idle threshold from the float field at this+232 (0xE8) into v32. [field:this:0x000000E8]
    // ASSIGNMENT: Prepare the mutex-protected list access: mutex handle from this+2748 (0xABC), wait timeout from this+2732+20 (0xAC0), and the list struct base at this+2732 (0xAAC). [field:this:0x00000ABC, field:this:0x00000AC0, field:this:0x00000AAC]
    // GUARD: Guard on the connection list state: when the mutex handle exists and WaitForSingleObject returns 0 or 128, the list struct at this+2732 (0xAAC) is used; otherwise the list pointer is null. [global:0x0059E1A0, field:this:0x00000ABC, guard:0]
    // ASSIGNMENT: Read the list head from *(this+2732) (field *(this+0xAAC):0x0) and seed the traversal cursor at this+2732+8 (0xAB4) with the head. [field:*(this+0xAAC):0x00000000, field:this:0x00000AB4]
    // LOOP: Walk the connection list node by node while the current node pointer is non-null, advancing the cursor to each node's successor. [field:*(*(this+0xAAC)+0x0):0x0000002C, field:this:0x00000AB4]
    // CALCULATION: Compute the node idle time as v31 (current time) minus the node's last activity float at node+44 (field +0x2C). [field:*(*(this+0xAAC)+0x0):0x0000002C]
    // GUARD: Continue the scan while the node idle time is within the threshold; break out of the traversal when the idle time exceeds v32. [field:*(*(this+0xAAC)+0x0):0x0000002C, field:this:0x000000E8]
    // GUARD: When the node drop flag byte at node+40 (field +0x28) is set, copy the aDropFlagSet string into the message buffer and drop the node. [field:*(*(this+0xAAC)+0x0):0x00000028, global:0x005E62E0]
    // CALCULATION: Dispatch check: when the node idle time has not yet exceeded half the threshold and v32 * 0.2 is smaller than the time since the node's last dispatch float at node+48 (field +0x30), schedule a timer callback. [field:*(*(this+0xAAC)+0x0):0x00000030, field:this:0x000000E8]
    // CALL: Resolve the node's dispatch arguments via sub_4B3DB0 and invoke VtableCallFormatDispatchTimerDispatchChain with them, then stamp the node's last-dispatch float (field +0x30) with the current time v31. [callee:0x004B3DB0, callee:0x0057DBB0, field:*(*(this+0xAAC)+0x0):0x00000030]
    // STATE_TRANSITION: Advance the traversal cursor at this+2732+8 (0xAB4) to the next node in the list. [field:this:0x00000AB4]
    // CALL: Format the maintenance drop message with StringFormatWithBufferOverflowCheck using the aMaintDropConet format string, the current time, the node last-activity float, and the idle time. [callee:0x0058815F, global:0x005E62F0, field:*(*(this+0xAAC)+0x0):0x0000002C]
    // CALL: sub_57DE30(this, node, message) performs the connection drop using the formatted message. [callee:0x0057DE30]
    // CALL: Release the mutex handle stored at this+2748 (0xABC) via ReleaseMutex when the maintenance pass completes. [global:0x0059E1A4, field:this:0x00000ABC]
    // RETURN: Return the release result (or the expiry-guard result when the pass did not run). [source:raw]
    // UNRESOLVED: SEH_57E0A0 is the SEH registration for this frame; its role is not expressed as an operation in the decompiled body.
    // UNRESOLVED: The float globals flt_59E440, flt_59E450 and flt_59E7E8 are data-referenced by this function but do not appear as named loads in the raw source; their exact use is not mapped.
    // UNRESOLVED: The socket-address structure reached through this+2744 (0xAB8) and its field at +0x2C are referenced in the fact store but no corresponding load is visible in the raw body.
    // UNRESOLVED: The format-timer callback semantics behind VtableCallFormatDispatchTimerDispatchChain and sub_57DE30 are defined in the callee functions, not here.
}
