## sub_42DCC0_0042dcc0 — DynMan::Init (dynamics manager initialization)

**Summary:** Initializes the dynamics manager: resets its subsystems, scans the 104 vehicle-record slots (22616-byte stride) for a free one, wires the selected slot into the global pointer/index arrays, runs session-dependent setup calls, marks per-vehicle record state and refreshes the loading progress; logs "Entered DynMan::Init()".

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | Unknown — not referenced in the visible decompiled body |
| 006f16d0 | flt_6F16D0 | R | Unknown — not referenced in the visible decompiled body |
| 006f30e0 | flt_6F30E0 | R | Unknown — not referenced in the visible decompiled body |
| 006f37d0 | aDevSrcCopperhe_20 | R | Source path "…dynman.cpp" used in the log gate |
| 006f3928 | flt_6F3928 | R | Unknown — not referenced in the visible decompiled body |
| 006f392c | flt_6F392C | R | Unknown — not referenced in the visible decompiled body |
| 006f3930 | aEnteredDynmanI | R | Log message "Entered DynMan::Init()" |
| 00757c10 | dword_757C10 | R | Number of local session vehicles (loop count and progress denominator) |
| 00757c14 | dword_757C14 | R | Number of vehicle records in off_757C18 |
| 00757c18 | off_757C18 | R | Base pointer of the vehicle record array (22616-byte stride) |
| 0091bf88 | dword_91BF88 | R | Object passed as the first argument of the large sub_4188D0 call |
| 0091e078 | dword_91E078 | W | Index of the chosen record in the dword_91E088 array (first search) |
| 0091e07c | dword_91E07C | W | Pointer to the chosen record slot |
| 0091e080 | dword_91E080 | RW | Index of the chosen record (second search; later checked against 0x68) |
| 0091e084 | dword_91E084 | W | Pointer set to the chosen record slot base |
| 0091e088 | dword_91E088 | R | Array of 104 record pointers (searched for the slot) |
| 0091e228 | dword_91E228 | W | Array filled with the per-vehicle record pointers |
| 0091e234 | byte_91E234 | R | Flag selecting the alternate sub_531280 setup path |
| 0091e238 | dword_91E238 | RW | State variable: value 1 is advanced to 2 |
| 00920484 | byte_920484 | W | Cleared to 0 at the end of init |
| 00920485 | byte_920485 | W | Cleared to 0 at the end of init |
| 009204a0 | unk_9204A0 | R | Base of the record pool (first of the 104 22616-byte slots) |
| 00923e84 | dword_923E84 | R | Start of the record scan (slot data) |
| 00b62244 | dword_B62244 | R | End pointer guarding the record-pool scan |
| 00b640c8 | dword_B640C8 | R | Game mode checked for equality with 1 or 2 |
| 00b65ff8 | dword_B65FF8 | R | Object passed to sub_438020 |
| 00b66000 | dword_B66000 | R | Unknown — not referenced in the visible decompiled body |
| 00b6f530 | byte_B6F530 | R | Object passed to sub_501CC0 together with the session index |
| 00b6feec | byte_B6FEEC | R | Flag term in the session-3 condition selecting sub_531280 |
| 00b6ff04 | byte_B6FF04 | R | Flag term in the session-3 condition selecting sub_531280 |
| 00b722e4 | byte_B722E4 | R | Flag term in the session-3 condition selecting sub_531280 |
| 00b72314 | dword_B72314 | R | Pointer to the current session-type index (value 4 is special-cased) |
| 00be1204 | dword_BE1204 | R | State checked against 2 before the all-slots-used fallback runs |
| 00fae910 | byte_FAE910 | R | Logging context passed to the log gate/emit helpers |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004188d0 | sub_4188D0 | Large initialization call with the record/argument block |
| 0042cb90 | sub_42CB90 | First reset step of the dynamics manager |
| 0042cc30 | sub_42CC30 | Second reset step, called with the manager handle a1 |
| 0042d2c0 | sub_42D2C0 | Third reset step of the dynamics manager |
| 0042dab0 | sub_42DAB0 | Final update step of the initialization |
| 00438020 | sub_438020 | Update/notify call on dword_B65FF8 |
| 00438180 | sub_438180 | Activates/selects a record by index |
| 00501cc0 | sub_501CC0 | Setup call with the byte_B6F530 object and session index |
| 00531060 | sub_531060 | Default session setup call on the v30 block |
| 00531280 | sub_531280 | Alternate session setup call on the v30 block |
| 00533df0 | sub_533DF0 | Call with the a2 argument and v28 block |
| 00536cc0 | sub_536CC0 | Call with the v32 buffer |
| 0053f5d0 | sub_53F5D0 | Per-record call with (record, 1, 1) |
| 00561210 | sub_561210 | Log emit for "Entered DynMan::Init()" |
| 005612d0 | sub_5612D0 | Log-enabled gate (dynman.cpp, line 639) |
| 00590650 | sub_590650 | Loading progress update call (float-packed argument) |
| 006332a0 | _floor | floor() used to compute progress-bar positions |

**Guard conditions:** The "Entered DynMan::Init()" message appears only when the log gate sub_5612D0(byte_FAE910, 2, dynman.cpp, 639) passes. The slot scan walks records until the first empty one (or the dword_B62244 end pointer), writing "index + 1" into each record's +4496 field only when the session index != 4. The fallback to the first slot runs only when all 104 slots were checked (v6 == 104) AND dword_BE1204 != 2. Both index searches are bounded at 104 iterations. The setup branch depends on byte_91E234: when set, sub_531280 runs only if HIBYTE(v31) is non-zero AND the game mode is 1 or 2; when clear, sub_501CC0/sub_536CC0 run and sub_531280 is chosen only for session 3 with byte_B6FEEC, byte_B6FF04 or byte_B722E4 set, otherwise sub_531060. The final sub_438180 call runs only when dword_91E080 < 0x68 (104) AND the record's +14820 field is zero; dword_91E238 is advanced from 1 to 2 when it equals 1.

**String literals referenced (deterministic):**

- `\Dev\Src\Copperhead\App\Source\dynman.cpp`
