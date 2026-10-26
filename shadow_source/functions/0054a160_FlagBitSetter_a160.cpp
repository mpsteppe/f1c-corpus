// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A160
// Canonical corpus name: FlagBitSetter_a160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagBitSetter_a160_0054a160.c

void UnknownObject::FlagBitSetter_a160()
{
    // Two-valued mode/flag setter on the word at this+0xEC. If a2 is 4096, the word is rewritten with the two mode bits cleared (via mask 0xFFFFCFFF) and bit 0x1000 set. If a2 is 0x2000, the word is rewritten with the two mode bits cleared (via mask 0xFFFFCFFF) and bit 0x2000 set, and that new word becomes the return value. For any other a2 the field is untouched and a2 is returned.
    // ASSIGNMENT: result initialized to a2, the selector value [source:raw]
    // GUARD: Branch on a2 == 4096 selecting the 0x1000 mode bit [source:raw]
    // ASSIGNMENT: this[59] (this+0xEC) cleared of the two mode bits via mask 0xFFFFCFFF and set to 0x1000 [field:this:0x000000EC, source:raw]
    // GUARD: Alternate branch on a2 == 0x2000 selecting the 0x2000 mode bit [source:raw]
    // ASSIGNMENT: this[59] (this+0xEC) cleared of the two mode bits via mask 0xFFFFCFFF and set to 0x2000; result becomes the rewritten word [field:this:0x000000EC, source:raw]
    // RETURN: Return result: a2 for the 4096 branch and other values, or the rewritten field word for the 0x2000 branch [function:0x0054A160, source:raw]
    // UNKNOWN: Called by CameraModeViewportUpdate (0x00409A00) and SceneFileTopLevelParser (0x0055B200); the meaning of the two mode bits at +0xEC is not documented in this packet [caller:0x00409A00, caller:0x0055B200]

    // Conservative worker pseudocode:
    //   result = a2;
    //   if (a2 == 4096) this[59] = (this[59] & 0xFFFFCFFF) | 0x1000;
    //   else if (a2 == 0x2000) { result = (this[59] & 0xFFFFCFFF) | 0x2000; this[59] = result; }
    //   return result;
    // UNRESOLVED: Semantic meaning of the 0x1000 vs 0x2000 mode bits at +0xEC is unknown; the structural twin ByteFieldSetter suggests a shared setter pattern but its field semantics are not in this packet
    // UNRESOLVED: The field is only ever written by this function within the packet; no reader evidence shows how the mode word is consumed
}
