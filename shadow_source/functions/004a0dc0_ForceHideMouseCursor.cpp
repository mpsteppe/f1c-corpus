// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0DC0
// Canonical corpus name: SystemOSAPICall_0dc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SystemOSAPICall_0dc0_004a0dc0.c

void UnknownObject::ForceHideMouseCursor()
{
    // Sets the global cursor-hidden flag byte_7CE260 to 1, then repeatedly calls the ShowCursor OS API with a zero show-count (ShowCursor(0)) until its return value goes negative, and returns the final ShowCursor result. This is the standard forced-hide idiom that keeps decrementing the OS cursor display counter until it reports a negative count.
    // ASSIGNMENT: Set the global flag byte_7CE260 = 1, marking the cursor as hidden before the OS calls begin. [global:0x007CE260, source:raw]
    // LOOP: do-while loop that keeps re-issuing ShowCursor(0) while its return value is still >= 0, forcing the OS cursor display counter down until it reports negative. [global:0x0059E2C4, source:raw]
    // CALL: Call ShowCursor(0) through the import slot at 0x0059E2C4 to decrement the OS cursor display count; the return value is captured into result and drives the loop condition. [global:0x0059E2C4, source:raw]
    // RETURN: Return the final ShowCursor return value after the loop terminates. [source:raw]
    // CALL: Invoked by ClientGridDisplayTimer (00460380) and WeatherSurfaceUpdate (004628A0) to hide the OS mouse cursor before those paths draw. [caller:0x00460380, caller:0x004628A0, source:raw]

    // Conservative worker pseudocode:
    //   int ForceHideMouseCursor() {
    //     byte_7CE260 = 1;
    //     int r;
    //     do { r = ShowCursor(0); } while (r >= 0);
    //     return r;
    //   }
    // UNRESOLVED: The semantics of byte_7CE260 are asserted by this write only; no reader of that flag is visible in this packet.
    // UNRESOLVED: ShowCursor resolves through the import table slot at 0x0059E2C4; the exact OS API binding and its display-counter model are not evidenced in this packet.
}
