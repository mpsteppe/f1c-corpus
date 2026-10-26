## ?_CallSETranslator@@YAHPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAX2PBU_s_FuncInfo@@H1@Z_00630c00 — _CallSETranslator (SE translator dispatch)

**Summary:** MSVC C++ EH support: installs a TranslatorGuardHandler registration frame over the current TEB exception chain and invokes the per-thread translator callback (through __getptd's data block, offset +116) so foreign/structured exceptions can be translated; afterwards it restores the exception-list link. On the sentinel path (a1 == 291) it only rewires the caller's registration node and returns 1.

**Called by:** ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z (00630cc7), ?FindHandlerForForeignException@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@HH1@Z (0063630e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Exception record's ExceptionCode — read to pass into __getptd |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00630c9b | loc_630C9B | R | Continuation label inside this function, stored as the caller registration node's pNext on the sentinel path |
| 00630cc7 | ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z | R | Handler address installed into the temporary registration frame |
| 00912b08 | dword_912B08 | R | Catch-pass marker copied into the temporary frame so TranslatorGuardHandler can recognize this pass |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00636698 | __getptd | Returns the per-thread data block; this function then calls a callback through offset +116 of that block |

**Guard conditions:** First checks whether a1 (exception record pointer) equals 291: if so, writes &loc_630C9B into a2->pNext and returns 1 immediately — the translator is NOT invoked. Otherwise the temporary frame is built (handler = TranslatorGuardHandler, marker = dword_912B08, saved a5/a2/a6/a7 arguments, stack links, saved ExceptionList from the TEB), v10 is set to 1, the callback is invoked via __getptd, then v10 is cleared to 0; if v21 was set the chain head's Next is repaired from the TEB. Returns v10 (0 after a completed dispatch).
