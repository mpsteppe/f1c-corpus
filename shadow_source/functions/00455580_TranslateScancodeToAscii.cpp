// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455580
// Canonical corpus name: sub_455580
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_455580_00455580.c

void UnknownObject::TranslateScancodeToAscii()
{
    // Scancode-to-ASCII keyboard translation. For scancode inputs in the negative signed-char range (from 0x80 upward), a large switch over jump table 0x00455868 maps each scancode to a fixed ASCII value. For all other inputs, when the extended-key flag (a2 & 0x8000) is clear the scancode passes through unchanged; otherwise a second switch over (a2 & 0xFFF) via jump table 0x00455A5C maps extended scancodes to ASCII, folding the shift modifier state carried in bits a2>>10 and a2>>11 into the result. Called by TranslateVirtualKey (0x00455B30).
    // GUARD: Switch on a1: negative scancodes (-128..-1) map to fixed ASCII characters, dispatched through the jump table at 0x00455868. [global:0x00455868, source:raw]
    // GUARD: For unlisted scancodes, test the extended-key flag: when (a2 & 0x8000) == 0, return a1 unchanged. [source:raw]
    // GUARD: When the extended-key flag is set, switch on (a2 & 0xFFF) through the jump table at 0x00455A5C, mapping extended scancodes to ASCII with the shift-state bits (a2 >> 10) and (a2 >> 11) folded into the result (e.g. uppercase base ORed with the 0x20/0x10 case bit). [global:0x00455A5C, source:raw]
    // RETURN: Return the translated ASCII character. [source:raw]
    // CALL: Invoked by TranslateVirtualKey (0x00455B30) to obtain the printable character for a virtual-key scancode. [caller:0x00455B30, abi:lead]

    // Conservative worker pseudocode:
    //   char TranslateScancodeToAscii(char scancode, unsigned int modifiers) {
    //     if (scancode < 0) return SCANCODE_TABLE[(unsigned char)scancode]; /* switch over jump table 0x00455868 * /
    //     if ((modifiers & 0x8000) == 0) return scancode;
    //     switch (modifiers & 0xFFF) { /* switch over jump table 0x00455A5C * /
    //       case 2: case 4: case 5: case 6:
    //         return (~(modifiers >> 11) & 0x10) | BASE;
    //       case 0x10: ... case 0x31:
    //         return ((~modifiers >> 10) & 0x20) | LETTER;
    //       case 0x33: case 0x34: case 0x35:
    //         return ((modifiers >> 11) & 0x10) | BASE;
    //       default: return scancode;
    //     }
    //   }
    // UNRESOLVED: The full 128-case first table is not enumerated here; only its structure (negative-scancode to ASCII via jump table 0x00455868) is represented.
    // UNRESOLVED: Exact scancode numbering scheme (e.g. DirectInput DIK codes) is not confirmed by packet evidence.
    // UNRESOLVED: Class identity / module owner of the translation is unknown.
}
