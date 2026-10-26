// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461610
// Canonical corpus name: SessionConfigBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionConfigBuilder_00461610.c

void UnknownObject::SessionConfigBuilder()
{
    // Builds a compact session-configuration packet on the 'this' struct by copying global game state. Parses scene data, derives a track/level file name (walking a path table entry to the last backslash then stripping the extension) into this+0x20, and derives a directory path into this+0x40. Packs global settings into byte fields this+0x64..0x6A and this+0x6B..0x6D (0x6B is a session-count clamped to [dword_7D0EA0, dword_7D0EA4] and mirrored into dword_7D0E98), builds a bit-packed flags word at this+0x76 from low 6 bits of dword_7D0F70 plus 7 single-bit flags, copies pit-open/closed times into this+0x78/0x7A, a clamped thousand-scaled penetration limit into this+0x7C, a float UI value into this+0x60, and option/flag words. Ends by calling UtilityFunction_15c0 twice to finalize the packet, returning its second result.
    // CALL: Call NullSafePointerDereference on &dword_7CE5D0, then SceneDataParser(v2) with the dereferenced pointer to parse scene data. [source:raw, function:0x00461610, callee:0x00415C30, callee:0x004C5690, global:0x007CE5D0]
    // CALCULATION: Compute a path pointer v3 = 396 * dword_8AC48C + dword_8AC490 + 4 and walk backward from its end to the last backslash (92) to isolate the file name component. [source:raw, global:0x008AC48C, global:0x008AC490]
    // CALCULATION: Copy the isolated file name into buffer v20 via sub_587DD0 (max 31), terminate v20[31] = 0, then walk backward from the end to the last period (46) and truncate the extension by writing 0 there. [source:raw, callee:0x00587DD0]
    // ASSIGNMENT: Store the derived file name into this+0x20 via SafeStringCopy(this + 32, v20, 31). [source:raw, callee:0x004336D0]
    // CALL: NullSafePointerDereference on &dword_7D0434, ReversePathSearchForBackslash on the result, then SafeStringCopy(this + 64, path, 31) to store the directory path into this+0x40. [source:raw, callee:0x00415C30, callee:0x004618D0, callee:0x004336D0, global:0x007D0434]
    // ASSIGNMENT: Pack seven global bytes into this+0x64..0x6A: this+0x64 = dword_7D0A44, this+0x65 = 0 (reserved), this+0x66 = dword_7D0FC4, this+0x67 = dword_7D0C18, this+0x68 = dword_7D0D14, this+0x69 = dword_7D0014, this+0x6A = dword_7CEB10. [source:raw, field:this:0x00000064, field:this:0x00000065, field:this:0x00000066, field:this:0x00000067, field:this:0x00000068, field:this:0x00000069, field:this:0x0000006A, global:0x007D0A44, global:0x007D0FC4, global:0x007D0C18, global:0x007D0D14, global:0x007D0014, global:0x007CEB10]
    // CALCULATION: Build the bit-packed flags word at this+0x76: low 6 bits from dword_7D0F70 (& 0x3F), then accumulate single-bit flags at bit positions 6-12 from byte_7CE874, byte_7CE88C, dword_7CE958, byte_7CE97C, dword_7CED44, dword_7CEE40 and dword_7CEF3C. [source:raw, field:this:0x00000076, global:0x007D0F70, global:0x007CE874, global:0x007CE88C, global:0x007CE958, global:0x007CE97C, global:0x007CED44, global:0x007CEE40, global:0x007CEF3C]
    // ASSIGNMENT: Copy the pit times as words: this+0x78 = dword_7CEC30 and this+0x7A = dword_7CEC54. [source:raw, field:this:0x00000078, field:this:0x0000007A, global:0x007CEC30, global:0x007CEC54]
    // CALCULATION: Compute v15 = flt_7D108C * 1000.0, clamp it to [0.0, 65535.0], truncate to an integer, and store it as the word at this+0x7C. [source:raw, field:this:0x0000007C, global:0x007D108C]
    // STATE_TRANSITION: Switch on dword_7D0E50 (jump table jpt_461818): case 1 -> 8, case 2 -> 12, case 3 -> 14, case 4 -> 32, default -> 6, selecting a base count v16. [source:raw, global:0x007D0E50, global:0x004618B4]
    // CALCULATION: Mirror the count into dword_7D0E98, clamp v16 to the interval [dword_7D0EA0, dword_7D0EA4] (rewriting dword_7D0E98 after clamping), then store the clamped count as the byte at this+0x6B. [source:raw, field:this:0x0000006B, global:0x007D0E98, global:0x007D0EA0, global:0x007D0EA4]
    // ASSIGNMENT: Pack remaining config fields: this+0x6C = dword_7CF134, this+0x6D = dword_7CF038, this+0x60 (float) = flt_7D084C, and this+0x74 (word) = dword_7D0F4C. [source:raw, field:this:0x00000060, field:this:0x0000006C, field:this:0x0000006D, field:this:0x00000074, global:0x007CF134, global:0x007CF038, global:0x007D084C, global:0x007D0F4C]
    // CALL: Call UtilityFunction_15c0(this, 0, 0) to run the first finalization pass over the packet. [source:raw, callee:0x004615C0]
    // RETURN: Return the result of UtilityFunction_15c0(this, 1, dword_7D0134 != 0), the second finalization pass whose flag reflects dword_7D0134. [source:raw, callee:0x004615C0, global:0x007D0134]

    // Conservative worker pseudocode:
    //   char sub_461610(int this) {
    //     char *scene = NullSafePointerDereference(&dword_7CE5D0);
    //     SceneDataParser(scene);
    //     const char *entry = (const char *)(396 * dword_8AC48C + dword_8AC490 + 4);
    //     const char *p = entry + strlen(entry);
    //     while (p > entry && *p != 92) p--; if (*p == 92) p++;
    //     char name[32]; sub_587DD0(name, p, 31); name[31] = 0;
    //     char *q = name + strlen(name);
    //     while (q > name && *q != 46) q--; if (*q == 46) *q = 0;
    //     SafeStringCopy(this + 32, name, 31);
    //     char *dir = NullSafePointerDereference(&dword_7D0434);
    //     SafeStringCopy(this + 64, ReversePathSearchForBackslash(dir), 31);
    //     *(char*)(this+100) = dword_7D0A44; *(char*)(this+101) = 0; *(char*)(this+102) = dword_7D0FC4;
    //     *(char*)(this+103) = dword_7D0C18; *(char*)(this+104) = dword_7D0D14; *(char*)(this+105) = dword_7D0014; *(char*)(this+106) = dword_7CEB10;
    //     int flags = dword_7D0F70 & 0x3F;
    //     flags += (byte_7CE874 & 1) << 6;  flags += (byte_7CE88C & 1) << 7;  flags += (dword_7CE958 & 1) << 8;
    //     flags += (byte_7CE97C & 1) << 9;  flags += (dword_7CED44 & 1) << 10; flags += (dword_7CEE40 & 1) << 11;
    //     flags += (dword_7CEF3C & 1) << 12;
    //     *(short*)(this+118) = flags; *(short*)(this+120) = dword_7CEC30; *(short*)(this+122) = dword_7CEC54;
    //     double d = flt_7D108C * 1000.0;
    //     int lim = d < 0.0 ? 0 : (d > 65535.0 ? 65535 : (int)d);
    //     *(short*)(this+124) = lim;
    //     int count;
    //     switch (dword_7D0E50) { case 1: count = 8; break; case 2: count = 12; break; case 3: count = 14; break; case 4: count = 32; break; default: count = 6; break; }
    //     dword_7D0E98 = count;
    //     if (count < dword_7D0EA0) count = dword_7D0EA0; else if (count > dword_7D0EA4) count = dword_7D0EA4;
    //     dword_7D0E98 = count; *(char*)(this+107) = count;
    //     *(char*)(this+108) = dword_7CF134; *(char*)(this+109) = dword_7CF038;
    //     *(float*)(this+96) = flt_7D084C; *(short*)(this+116) = dword_7D0F4C;
    //     UtilityFunction_15c0((char*)this, 0, 0);
    //     return UtilityFunction_15c0((char*)this, 1, dword_7D0134 != 0);
    //   }
    // UNRESOLVED: The string targets this+0x20 and this+0x40 (the file-name and directory-path copies) are not present in the packet field list, so only the raw-source copy operations cover them.
    // UNRESOLVED: flt_59E440, flt_59E874, flt_59F120 and unk_8AC368 are listed as read globals but never appear in the raw source; they are likely accessed inside the finalization utility UtilityFunction_15c0.
    // UNRESOLVED: Semantics of most packed bytes and bit flags (weather, options, damage, etc.) are inferred from field position only and are not proven by this packet.
}
