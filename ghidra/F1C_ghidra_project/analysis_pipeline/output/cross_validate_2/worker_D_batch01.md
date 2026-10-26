# Cross-Validation Results: worker_D_batch01
# Functions 1056-1107 from docs/01-engine-architecture.md
# 52 functions validated against .c source files

## Summary
- **PASS:** 49 functions
- **FAIL:** 3 functions
  - FUN_005938B4 — wrong call count (3 vs 4)
  - FUN_00586C90 — byte order reversed
  - FUN_0057A0F0 — wrong total copy size (32 vs 48 bytes)

---

## FUN_004C8AE0 — PASS

## FUN_004541D0 — PASS

## FUN_00465D70 — PASS

## FUN_00587A60 — PASS

## FUN_0057AA10 — PASS

## FUN_0059C81A — PASS

## FUN_00595AC0 — PASS

## FUN_0057A570 — PASS

## FUN_004562C0 — PASS

## FUN_004A1B70 — PASS

## FUN_005836A0 — PASS

## FUN_005938B4 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [WRONG_CALL_COUNT] Doc says "Calls FUN_0058e0c7() three times (TLS value retrieval)" but .c shows 4 calls to FUN_0058e0c7 (lines 22, 23, 24, 26)

**Corrected entry:**
## FUN_005938b4 — SEH Wrapper Around CRT Function Call

Source: unknown | Confidence: medium
SEH-guarded wrapper that sets up TLS values then calls a function.

**Key logic:**
- Sets up SEH handler (pushes ExceptionList stack frame)
- Calls FUN_0058e0c7() four times (TLS value retrieval)
- Sets TLS[+0x6c] = param_1 and TLS[+0x70] = param_3
- Calls FUN_0058a3b6(param_2, param_4, param_5, param_6, param_7)
- SEH cleanup via FUN_00593981() then restores ExceptionList

**Calls:**
- FUN_0058e0c7 — TLS value retrieval (×4)
- FUN_0058a3b6 — Target function
- FUN_00593981 — SEH cleanup/destroy

**Used by system:** docs/01-engine-architecture.md — SEH-guarded function call

**Moddability:** hardcoded

## FUN_00583D40 — PASS

## FUN_0053D850 — PASS

## FUN_0058BBD2 — PASS

## FUN_00586C90 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [BYTE_ORDER_REVERSED] Doc says "Returns (incremented < 6) as boolean in upper byte, value in lower 3 bytes" but .c shows CONCAT31 puts boolean in LOWER byte and value in upper 3 bytes

**Corrected entry:**
## FUN_00586c90 — Counter Increment with Cap Check

Source: unknown | Confidence: medium
Increment a counter, return overflow flag.

**Key logic:**
- Reads counter from *param_1, increments by 1
- Stores incremented value back
- Returns (incremented < 6) as boolean in lowest byte, value in upper 3 bytes
- Acts as a bounded counter that saturates/is checked at threshold 6

**Algorithm family:** Bounded counter — increment with limit check

**Used by system:** docs/01-engine-architecture.md — state machine step counter or retry limiter

**Moddability:** hardcoded

## FUN_0045D500 — PASS

## FUN_0048E0B0 — PASS

## FUN_004D8950 — PASS

## FUN_005474D0 — PASS

## FUN_00587460 — PASS

## FUN_00597321 — PASS

## FUN_0058A755 — PASS

## FUN_00599348 — PASS

## FUN_0058DFEA — PASS

## FUN_0057A0F0 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [WRONG_TOTAL_SIZE] Doc says "Copies 32 bytes (0x20)" but actual total is 48 bytes (first loop 16 bytes + second loop 32 bytes = 48 bytes)

**Corrected entry:**
## FUN_0057a0f0 — Byte-Aligned Memory Copy with Offset

Source: unknown | Confidence: high
Copies 48 bytes from source to destination with a byte-level offset.

**Key logic:**
- Copies 16 bytes in first loop: `param_1[i] = param_1[param_2 - param_1 + i]` for i=0..15
- Copies 32 bytes in second loop: param_1+0x10[i] = (param_1+0x10)[param_2 - param_1 + i] for i=0..31
- Effectively: src = param_2, dest = param_1, copy parameter is the byte offset between them

**Used by system:** docs/01-engine-architecture.md — low-level byte-aligned memory copy utility

**Algorithm family:** memory copy (memcpy variant)

**Moddability:** hardcoded

## FUN_00563000 — PASS

## FUN_00470670 — PASS

## FUN_0058AB31 — PASS

## FUN_0055D530 — PASS

## FUN_0059C666 — PASS

## FUN_004646F0 — PASS

## FUN_004B1AC0 — PASS

## FUN_00516937 — PASS

## FUN_0057B7D0 — PASS

## FUN_0057A950 — PASS

## FUN_0059A541 — PASS

## FUN_0059D248 — PASS

## FUN_0059D470 — PASS

## FUN_0059C956 — PASS

## FUN_004C8B20 — PASS

## FUN_004B1870 — PASS

## FUN_0040ACC6 — PASS

## FUN_00476050 — PASS

## FUN_00470400 — PASS

## FUN_00567BA2 — PASS

## FUN_0051176B — PASS

## FUN_0046FCF9 — PASS

## FUN_0049B030 — PASS

## FUN_0053B000 — PASS

## FUN_00405020 — PASS

## FUN_0044C9F4 — PASS
