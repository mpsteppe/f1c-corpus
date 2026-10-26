// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592C46
// Canonical corpus name: sub_592C46
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592C46_00592c46.c

void UnknownObject::CommandLineTokenParser()
{
    // Parses a command-line style string (a1) into a flattened argument-string buffer (a3) and an argv-style pointer array (a2), producing a token count at a4 and a byte count at a5. Handles quoted tokens (34 = double quote), backslash escapes (92), and whitespace delimiters (32 = space, 9 = tab), using the character-class table byte_8D47E1 (bit 4 = quote/whitespace class). Returns a4 after incrementing it.
    // ASSIGNMENT: Initialize outputs: set the byte count *a5 to 0 and the token count *a4 to 1 (counting the initial entry). [source:raw]
    // GUARD: Guard: if the argv pointer-array a2 is non-null, store the buffer base a3 as the first argv entry and advance the argv write pointer. [source:raw]
    // GUARD: Guard: if the current input char is 34 (double quote), the leading token is parsed in quoted mode. [guard:0]
    // LOOP: Quoted-token scan: read chars until a closing quote (34) or NUL; each char is copied to the output buffer and counted into *a5, and a char marked by the class table (byte_8D47E1 bit 4) also causes the following char to be copied literally. [guard:0, field:this:0x00000000, global:0x008D47E1]
    // ASSIGNMENT: Terminate the quoted token with a NUL byte in the output buffer; if the current char is still a closing quote (34), consume it. [source:raw]
    // LOOP: Unquoted-token scan: copy each char and count it into *a5; a char marked by the class table (byte_8D47E1 bit 4) consumes the next char as well; the token ends at a space (32), a tab (9) or NUL, and is terminated by overwriting the last copied output char with NUL. [guard:1, guard:2, global:0x008D47E1]
    // LOOP: Outer argument loop: skip leading spaces/tabs; if the argv write pointer is live, record the current token start into it; increment the token count at *a4 for each new argument. [source:raw]
    // LOOP: Inner token scan: count a run of backslashes (92); a quote (34) with an even backslash count toggles the in-quote flag, and when already in quote mode a doubled quote (current and next char both 34) is consumed as an escaped literal; backslashes and class-table (byte_8D47E1 bit 4) chars are copied into the output buffer; the token ends on NUL or on whitespace (32/9) outside quotes. [guard:3, guard:4, field:this:0x00000001, global:0x008D47E1]
    // ASSIGNMENT: Terminate each token with a NUL byte in the output buffer; NUL-terminate the argv array through the write pointer; increment *a4 and return the a4 pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_592C46(u8* input, u8** argv, u8* buf, _DWORD* argc, _DWORD* used) {
    //     *used = 0;
    //     *argc = 1;
    //     u8* out = buf;
    //     u8** ap = argv;
    //     u8* p = input;
    //     if (argv) { *argv = buf; ap = argv + 1; }
    //     if (*p == 34) {
    //       /* quoted leading token * /
    //       do { u8 c = *++p; if (c == 34 || !c) break;
    //            if (class[c] & 4) { ++*used; if (out) *out++ = *p++; }
    //            ++*used; if (out) *out++ = *p;
    //       } while (1);
    //       ++*used; if (out) *out++ = 0;
    //       if (*p == 34) ++p;
    //     } else {
    //       /* unquoted leading token * /
    //       do { ++*used; if (out) *out++ = *p;
    //            u8 c = *p++;
    //            if (class[c] & 4) { ++*used; if (out) *out++ = *p; ++p; }
    //            if (c == 32) break;
    //            if (!c) { --p; goto args; }
    //       } while (c != 9);
    //       if (out) *(out - 1) = 0;
    //     }
    //   args:
    //     while (*p) {
    //       while (*p == 32 || *p == 9) ++p;
    //       if (!*p) break;
    //       if (ap) *ap++ = out;
    //       ++*argc;
    //       /* token scan with backslash/quote handling (v18 toggle) * /
    //       if (out) *out++ = 0;
    //       ++*used;
    //     }
    //     if (ap) *ap = 0;
    //     ++*argc;
    //     return argc;
    //   }
    // UNRESOLVED: The exact meaning of byte_8D47E1 bit 4 (quote/whitespace class) is inferred from usage and is not independently proven.
    // UNRESOLVED: The caller contract of sub_592BAD for the produced argv array, token count and buffer byte count is unknown.
    // UNRESOLVED: The fields this+0x0 and this+0x1 are deterministic facts describing the current and next input characters rather than a struct; their object identity is unknown.
}
