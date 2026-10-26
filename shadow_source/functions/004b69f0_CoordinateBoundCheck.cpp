// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B69F0
// Canonical corpus name: CoordinateBoundCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CoordinateBoundCheck_004b69f0.c

void UnknownObject::CoordinateBoundCheck()
{
    // Returns TRUE when either of two int fields on the object is negative: this[622] (offset 0x9B8) or this[623] (offset 0x9BC). Existing analysis (DERIVED) interprets the two fields as circular buffer write/read indices and the function as a buffer-validity check (TRUE = uninitialized/invalid state); raw source supports only the two negative comparisons.
    // GUARD: Guard on write-index validity: test whether this[622] (offset 0x9B8) is negative. [guard:0, field:this:0x000009B8, source:raw]
    // GUARD: Guard on read-index validity: test whether this[623] (offset 0x9BC) is negative. [guard:1, field:this:0x000009BC, source:raw]
    // RETURN: Return the OR of the two negative checks; TRUE when either index field is negative, FALSE only when both are >= 0. [guard:0, guard:1, field:this:0x000009B8, field:this:0x000009BC, source:raw]
    // CALL: Called by CircularBufferCheck (0x004B68C0) and PitstopActionSet (0x004B6940) to test whether the object's indices are in a valid (non-negative) state. [caller:0x004B68C0, caller:0x004B6940]

    // Conservative worker pseudocode:
    //   BOOL CoordinateBoundCheck(int* this) {
    //     return this[622] < 0 || this[623] < 0;
    //   }
    // UNRESOLVED: Field meanings are only DERIVED from prose: offset 0x9B8/0x9BC as circular buffer write/read indices has no raw-source confirmation.
    // UNRESOLVED: The owning class is unknown; equal offsets on unrelated this pointers are not evidence of an identical type.
}
