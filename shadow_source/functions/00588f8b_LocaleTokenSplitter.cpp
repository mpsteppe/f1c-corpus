// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588F8B
// Canonical corpus name: sub_588F8B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588F8B_00588f8b.c

void UnknownObject::LocaleTokenSplitter()
{
    // Splits a locale string into up to three tokens delimited by any of the characters '_' (0x5F), '.' (0x2E), ',' (0x2C). Each token is copied into a fixed slot of the 136-byte output buffer: primary token at offset 0, secondary token at offset 64, remainder token at offset 128. Returns 0 on success (including empty input and a leading-dot remainder path) and -1 on malformed input or tokens longer than 63 bytes. The buffer is zero-filled before tokenization.
    // CALL: Zero-fill the 136-byte output buffer via sub_58BB10(a1, 0, 136) before any token is written [callee:0x0058BB10, source:raw]
    // GUARD: Empty input string (*a2 == 0) returns 0 immediately [source:raw]
    // GUARD: Input beginning with '.' (0x2E) followed by at least one more character is a leading-dot/relative form: sub_58FCA0 processes the remainder buffer at a1+128 and the function returns 0 [callee:0x0058FCA0, source:raw]
    // LOOP: Iterate token by token: sub_58FC20 locates the next delimiter character using the delimiter set held by the packet global asc_5B8C7C (the raw source shows the inline literal "_.,") [callee:0x0058FC20, global:0x005B8C7C, source:raw]
    // GUARD: Per-token length and delimiter validation: primary token fails if v4 >= 64 or the delimiter is '.'; secondary token fails if v4 >= 64 or the delimiter is '_'; remainder slot fails for any third delimiter other than ',' or end-of-string - all failures return -1 [source:raw]
    // CALL: sub_587DD0 copies the token substring of length v4 from the input into the current slot: primary at a1+0, secondary at a1+64, remainder at a1+128 [callee:0x00587DD0, source:raw]
    // RETURN: After a token, a ',' delimiter or end-of-string ends the parse successfully and returns 0; the loop otherwise advances the read pointer past the delimiter [source:raw]
    // RETURN: Reaching end of input with no further delimiter (loop exits) returns -1; invoked from the locale setup path sub_588E4E (00588e4e) [caller:0x00588E4E, function:0x00588F8B, source:raw]

    // Conservative worker pseudocode:
    //   sub_58BB10(a1, 0, 136);
    //   if (!*a2) return 0;
    //   if (*a2 == 0x2E && a2[1]) { sub_58FCA0(a1 + 128); return 0; }
    //   for (i = 0; ; ++i) {
    //     off = sub_58FC20(cur, "_.,");
    //     if (!off) break;
    //     delim = cur[off];
    //     if (i == 0) { if (off >= 64 || delim == 0x2E) return -1; sub_587DD0(a1, cur, off); }
    //     else if (i == 1) { if (off >= 64 || delim == 0x5F) return -1; sub_587DD0(a1 + 64, cur, off); }
    //     else { if (delim && delim != 0x2C) return -1; sub_587DD0(a1 + 128, cur, off); }
    //     if (delim == 0x2C || !delim) return 0;
    //     cur = &cur[off] + 1;
    //   }
    //   return -1;
    // UNRESOLVED: The exact token semantics of the three slots (primary/secondary/remainder) and the leading-dot special case depend on the caller sub_588E4E's expectations, which are outside this packet
    // UNRESOLVED: Packet global asc_5B8C7C is flagged as the delimiter string but the raw source compiles the delimiter set as the inline literal "_.,"; whether the global is a duplicate or an alternate is not verifiable from this packet
}
