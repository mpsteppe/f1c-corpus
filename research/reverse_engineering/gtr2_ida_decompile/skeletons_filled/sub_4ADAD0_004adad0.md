## sub_4ADAD0_004adad0 — Store object record and dispatch by type

**Summary:** Copies two object fields (0x2E0, 0x2E4) into a global record table addressed as stride 28 * field-0x2D4 from dword_B74800, then, when field 0x2E0 == 1, dispatches on the field-0x2E4 type value: IDs 1-12, 40-51 and 132-139 run a common handler while any other value returns immediately. __usercall (ecx = this, extra args in ebx/ebp are forwarded into the handler's stack frame).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2D4 | R | — | Record index (a1[181]); multiplied by 28 to select the slot in the global table |
| this | 0x2E0 | R | — | Value copied to the table entry (+0); also the dispatch enable flag tested against 1 |
| this | 0x2E4 | R | — | Value copied to the table entry (+4); also the type selector switched on |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ade7c | jpt_4ADB1F | R | Switch jump table used to dispatch on the 0x2E4 type value |
| 004adf00 | byte_4ADF00 | R | Byte read on the switch dispatch path; exact role not visible in the provided decompile |
| 00b73afc | unk_B73AFC | R | unknown (not visible in provided decompile) |
| 00b74800 | dword_B74800 | W | Base of the global record table; entry at 28*index receives the 0x2E0 field value |
| 00b74804 | dword_B74804 | W | Table entry + 4; receives the 0x2E4 field value |
| 00b74f74 | unk_B74F74 | R | unknown (not visible in provided decompile) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499d90 | sub_499D90 | Helper invoked before the table record is written (arguments not visible in the decompile) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2E0 | == | 1 | Dispatch enable flag; only when set does the 0x2E4 switch run |

**Guard interpretation:** The two table writes happen unconditionally. The switch runs only when field 0x2E0 equals exactly 1; when it is any other value the function returns the computed result without further action. Inside the switch, selector values 1-12, 40-51 and 132-139 PASS to the common handler (stack frame setup plus interlocked-exchange path); all other selector values hit default and return early with v7-1.
