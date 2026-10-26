// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC400
// Canonical corpus name: sub_4FC400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FC400_004fc400.c

void UnknownObject::TextureVariantPathBuilder()
{
    // Builds up to four texture-variant paths with a letter suffix and submits each to TextureAdjuster. Copies the incoming filename a2 into a local buffer, splits it at the first '.' (v2 = sub_589DB0(v11, 46)); when a dot is found the extension (dot included) is copied into v12 and v11 is truncated at the dot, otherwise v12 is filled from the default-extension string global byte_5D6F48. When the base name's last character is in 'A'..'D' (ASCII 65..68) it is stripped from v11. Then, for v7 = 65..68 and exactly 4 iterations, formats the variant path '%s%c%s' into v14, the plain name+extension '%s%s' into v15, restores v16 = a2, formats the prefix+letter '%s%c' into v13, and calls TextureAdjuster(v13, 1, v14, v15, v16, 0, 0), keeping the last result as the return value.
    // ASSIGNMENT: Copies the incoming filename a2 into the local buffer v11 via strcpy. [source:raw]
    // CALL: sub_589DB0(v11, 46) searches v11 for the '.' character (46); its result v2 is used to split name from extension. [callee:0x00589DB0, source:raw]
    // GUARD: When v2 is non-null the filename contained a dot; otherwise v11 has no extension and the default-extension path is taken. [source:raw]
    // ASSIGNMENT: Dot path: copies the extension starting at v2 (dot included) into v12, then nulls *v2 so v11 is truncated at the extension dot. [source:raw]
    // ASSIGNMENT: No-dot path: copies the default extension string from the global byte_5D6F48 into v12. [global:0x005D6F48, source:raw]
    // CALCULATION: Computes v5 = strlen(v11) to test whether the base name is non-empty. [source:raw]
    // GUARD: When the base name is non-empty and its last character is in the range 65..68 ('A'..'D'), that trailing letter is stripped by nulling it. [source:raw]
    // LOOP: Loop of exactly 4 iterations: v7 runs from 65 to 68 ('A'..'D') while v8 counts down from 4; the loop does not exit early. [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v14, aSS, v11, v7, v12) formats the variant path '%s%c%s' (base name + letter + extension); aSS (0x005BE860) is the read-only format-string global the raw source renders as that literal. [callee:0x0058815F, global:0x005BE860, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v15, aSC, v11, v12) formats the plain '%s%s' name+extension string; aSC (0x005D6F38) is the read-only format-string global for that literal. [callee:0x0058815F, global:0x005D6F38, source:raw]
    // ASSIGNMENT: strcpy(v16, a2) restores a fresh copy of the original filename for each variant iteration. [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v13, aSCS, a1, v7) formats the '%s%c' prefix+letter string; aSCS (0x005D6F40) is the read-only format-string global for that literal. [callee:0x0058815F, global:0x005D6F40, source:raw]
    // CALL: TextureAdjuster(v13, 1, v14, v15, v16, 0, 0) registers/adjusts the texture for the current letter variant; the last call's result is kept as the function return value. [callee:0x004DC770, source:raw]
    // CALL: Invoked by sub_4FC550 (0x004FC550), the callers list entry. [caller:0x004FC550, source:raw]

    // Conservative worker pseudocode:
    //   strcpy(v11, a2);
    //   v2 = sub_589DB0(v11, 46);
    //   if (v2) { strcpy(v12, v2); *v2 = 0; }
    //   else { v12 = byte_5D6F48; }
    //   if (strlen(v11) > 0 && v11[len-1] in 65..68) v11[len-1] = 0;
    //   for (v7 = 65, v8 = 4; v8 > 0; ++v7, --v8) {
    //     StringFormatWithBufferOverflowCheck(v14, "%s%c%s", v11, v7, v12);
    //     StringFormatWithBufferOverflowCheck(v15, "%s%s", v11, v12);
    //     strcpy(v16, a2);
    //     StringFormatWithBufferOverflowCheck(v13, "%s%c", a1, v7);
    //     result = TextureAdjuster(v13, 1, v14, v15, v16, 0, 0);
    //   }
    //   return result;
    // UNRESOLVED: The exact pairing of the three read-only format-string globals (aSS 0x005BE860, aSC 0x005D6F38, aSCS 0x005D6F40) with the '%s%c%s' / '%s%s' / '%s%c' literals in the raw source is inferred, not directly evidenced by this packet.
    // UNRESOLVED: The meaning of the TextureAdjuster second literal argument (1) and the trailing two zeros is not established from this packet.
    // UNRESOLVED: byte_5D6F48's content (the default extension) is only described as a copy source; its value is not evidenced.
}
