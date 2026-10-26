## ___sse2_available_init_0063c46e — CRT SSE2 availability detection (CPUID/OSFXSR)

**Summary:** VC8 CRT startup CPU-dispatch routine: probes whether the CPU supports CPUID (by toggling the EFLAGS ID bit), reads the vendor string and family/model/stepping plus EDX feature flags via CPUID leaf 0/1, then checks OSFXSR support and the AMD K8 vendor/family special case to set the two CRT SSE2-availability flags at dword_FBB5E4 and dword_FBB5E0. Always returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729138 | aAuthenticamd | R | The literal vendor string "AuthenticAMD" compared against the CPUID vendor string |
| 00912b08 | dword_912B08 | R | CRT data value read into the stack local v18 at entry (global guard/buffer-security cookie) |
| 00fbb5e0 | dword_FBB5E0 | W | Output flag: set to 1 when OSFXSR is present AND (vendor != AuthenticAMD OR CPU family != 15) — the "SSE2 usable on this CPU model" marker; cleared to 0 at entry |
| 00fbb5e4 | dword_FBB5E4 | W | Output flag: set to 1 when has_osfxsr_set reports the OS saves/restores XMM state; cleared to 0 at entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631d10 | _strncmp | Compares the CPUID vendor string (Str2) with "AuthenticAMD" (length 12) to detect an AMD CPU |
| 006349bb | sub_6349BB | CRT helper invoked from this routine (call not rendered in the decompiled body; sits with the CPUID/OSFXSR probe code) |
| 0063c439 | _has_osfxsr_set | Determines whether the OS has enabled FXSAVE/FXRSTOR (OSFXSR) using the CPUID leaf-1 EDX/ECX values; must be nonzero for the SSE2 flags to be set |

**Guard conditions:**
- CPUID support: EFLAGS bit 0x200000 (ID) is toggled and the result compared — only if `v2 != v0` (bit is writable → CPUID exists) are the flags restored and the two `cpuid` instructions executed (leaf 0 → vendor into Str2/v16/v17, leaf 1 → v13 = HIBYTE(EDX) feature bits, v14 = EAX). If CPUID is absent, v13 stays 0 and no flag can be set.
- SSE2 feature bit: `(v13 & 4) != 0` is required (CPUID.1:EDX bit 26, SSE2); if clear, both output flags remain 0.
- OS support: `has_osfxsr_set(...)` must return nonzero, else dword_FBB5E4 stays 0 and dword_FBB5E0 is not examined.
- Vendor/family exception: after OSFXSR passes, dword_FBB5E0 is set to 1 only if `strncmp("AuthenticAMD", Str2, 12) != 0` OR the computed family is not 15 — family = `((v14 >> 8) & 0xF) + (family==15 ? v14 >> 20 : 0)`. Thus AuthenticAMD CPUs reporting family 15 keep dword_FBB5E0 = 0.

**String literals referenced (deterministic):**

- `AuthenticAMD`
