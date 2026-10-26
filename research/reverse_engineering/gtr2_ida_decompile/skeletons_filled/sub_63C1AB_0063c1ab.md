## sub_63C1AB_0063c1ab — CRT libm error-support dispatcher (errno EDOM/ERANGE)

**Summary:** MSVC CRT math-library error dispatcher: given a math-error code (a4), the argument pointer (a1) and the result slot (a3), it routes through one of several handler-invocation paths — calling the installed math error handler through the function pointer at off_913310 and passing the affected function's name from the adjacent CRT name-string table. When the handler reports failure it writes errno 33 (EDOM) or 34 (ERANGE) depending on the code class, and it restores or initializes the result value in *a3.

**Called by:** _floor (006332a0), _ceil (00634d10), __pow_pentium4 (0063c629), start_3 (006e077e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | The input argument value (element pointed to by a1), read and copied into the result slot *a3 on the "copy argument" error paths |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731d98 | aAtan | R | Name string "atan" from the CRT math function-name table, passed to the error handler for the atan-related code class |
| 00731da0 | aCeil | R | Name string "ceil" from the same table, for the ceil-related code class |
| 00731da8 | aFloor | R | Name string "floor" from the same table, for the floor-related code class |
| 00731db0 | aModf | R | Name string "modf" from the same table, for the modf-related code class |
| 00731db8 | aExp2_0 | R | Name string "exp2" from the same table, for the exp2-related code class |
| 00731dc0 | aExp10 | R | Name string "exp10" from the same table, for the exp10-related code class |
| 00731dc8 | aLog2 | R | Name string "log2" from the same table, for the log2-related code class |
| 00731dd0 | off_731DD0 | R | Pointer/name entry in the same CRT name table (second "log2"/"pow" entry area) used for its code class |
| 00731dd4 | off_731DD4 | R | Pointer/name entry in the same CRT name table used for its code class |
| 00731dd8 | aLog10 | R | Name string "log10" from the same table, for the log10-related code class |
| 00731de0 | off_731DE0 | R | Pointer/name entry in the same table (start of the "pow"/"log"/"exp" strings) used for its code class |
| 00913310 | off_913310 | R | Function pointer to the installed CRT math error handler invoked on every error path; a null/zero return from it triggers the errno write |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006349bb | sub_6349BB | CRT math helper invoked on an error path (its call site is not visible in the decompiled body) |
| 006351e0 | __errno | Returns the errno location; caller writes 33 (EDOM) or 34 (ERANGE) into it when the handler reports failure |
| 006ab05a | sub_6AB05A | Helper invoked on an error path (call site not visible in the decompiled body) |

**Guard conditions:** Pure dispatch on `a4` (no boolean guards). Group A (codes 2, 8, 14, 24, 27, 161, 162, 166, 170 → LABEL_39): original `*a3` saved, handler called; if it returns 0, errno is set to 34 (ERANGE); result slot restored and returned. Group B (codes 3, 9, 28, 171, 1006 → LABEL_48; and codes 29, 1000, 1001, 1002, 1003, 1004, 1005, 1007 → LABEL_49/50): `*a3 = *a1` for the LABEL_49 subset, then handler called; if it returns 0, errno is set to 33 (EDOM); result slot reloaded/returned. Code 25 (LABEL_26): handler called and `*a3` restored, but no errno is written on failure. Code 26: `*a3 = 1.0`, no handler call. Any other code falls through the switch chains and returns `a4 - 15`, `a4 - 29`, `a4 - 1007` or `a4 - 1001` (nonzero, no error handling performed). The body also brackets its work with `__readeflags`/`__writeeflags` (EFLAGS save/restore).

**String literals referenced (deterministic):**

- `atan`
- `ceil`
- `floor`
- `modf`
- `exp2`
- `exp10`
- `log2`
- `log2`
- `pow`
- `pow`
- `pow`
- `pow`
- `log`
- `log`
- `log`
- `log10`
- `log10`
- `log10`
- `exp`
- `exp`
- … +1 more
