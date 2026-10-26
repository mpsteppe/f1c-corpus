// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004988C0
// Canonical corpus name: sub_4988C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4988C0_004988c0.c

void UnknownObject::setByteField18F5()
{
    // Char-returning thiscall that writes the byte argument a2 to the single-byte field at this+0x18F5 and returns a2 unchanged. Serves as a simple flag/toggle setter. Invoked by KeyBindingUIPressKeyOrController (0x0046B0C0) and sub_46BF10 (0x0046BF10).
    // ASSIGNMENT: Store the byte value a2 into the field at this+0x18F5 (byte-array index 6389), overwriting it unconditionally. [field:this:0x000018F5, function:0x004988C0, source:raw]
    // RETURN: Return the input byte a2 unchanged as the function result. [function:0x004988C0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4988C0(_BYTE* this, char a2) {
    //     this[6389] = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Meaning of the byte flag at this+0x18F5 is unknown; likely a boolean/toggle given both callers are UI/key-binding related.
    // UNRESOLVED: Caller contexts (KeyBindingUIPressKeyOrController 0x0046B0C0, sub_46BF10 0x0046BF10) not reconstructed; caller evidence preserved below.
}
