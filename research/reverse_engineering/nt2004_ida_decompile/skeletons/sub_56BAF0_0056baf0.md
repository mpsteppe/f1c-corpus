## sub_56BAF0_0056baf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_56C740 (0056c740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x58 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x5D | R | — | [LLM] |
| this | 0x5C4 | RW | 1 | [LLM] |
| this | 0x5C8 | RW | 0 | [LLM] |
| this | 0x618 | R | — | [LLM] |
| this | 0x61C | R | — | [LLM] |
| this | 0x640 | R | — | [LLM] |
| this | 0x644 | R | — | [LLM] |
| this | 0x910 | R | — | [LLM] |
| this | 0x938 | R | — | [LLM] |
| this | 0x93C | R | — | [LLM] |
| this | 0xBE4 | R | — | [LLM] |
| this | 0xBEC | RW | 0 | [LLM] |
| this | 0xBF0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5C8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0056c388 | jpt_56C308 | R | [LLM] |
| 005d3b59 | SEH_56BAF0 | R | [LLM] |
| 005d513c | Sleep | R | [LLM] |
| 005d516c | WaitForSingleObject | R | [LLM] |
| 005d5170 | ReleaseMutex | R | [LLM] |
| 005d5368 | __imp_htonl | R | [LLM] |
| 005d536c | __imp_getsockname | R | [LLM] |
| 005d5370 | getpeername | R | [LLM] |
| 005d5374 | __imp_ntohs | R | [LLM] |
| 005d537c | WSAGetLastError | R | [LLM] |
| 005d5380 | __imp_connect | R | [LLM] |
| 005d5384 | __imp_sendto | R | [LLM] |
| 005d5398 | __imp_htons | R | [LLM] |
| 0060217c | aSSD | R | [LLM] |
| 0061a1ec | off_61A1EC | R | [LLM] |
| 0061a1f4 | off_61A1F4 | R | [LLM] |
| 0061a1f8 | off_61A1F8 | R | [LLM] |
| 0061a1fc | off_61A1FC | R | [LLM] |
| 0061a25c | aD_5 | R | [LLM] |
| 0061a268 | aDDDDDD | R | [LLM] |
| 0061a27c | aSSDDDDDD | R | [LLM] |
| 0061a294 | aS_11 | R | [LLM] |
| 007e0600 | byte_7E0600 | RW | [LLM] |
| 007e0604 | dword_7E0604 | RW | [LLM] |
| ff00000000005e85 | byte_FF00000000005E85 | W | [LLM] |
| ff00000000005e86 | byte_FF00000000005E86 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414470 | ShortComputation_a780 [exact] | [LLM] |
| 0056acd0 | NetworkPacketConstructor [structural] | [LLM] |
| 0056b260 | F_16ByteStructCopy [exact] | [LLM] |
| 0056b280 | PointerAdvance [exact] | [LLM] |
| 0056b2a0 | Setter [exact] | [LLM] |
| 0056bad0 | NetworkSocketCreate [exact] | [LLM] |
| 0056c3a0 | SocketBindPortScan [exact] | [LLM] |
| 0056c4d0 | SocketGracefulClose [exact] | [LLM] |
| 0056dc20 | sub_56DC20 | [LLM] |
| 00571810 | LinkedListNodeRemovalByValue [structural] | [LLM] |
| 00572ea0 | LinkedListNodeRemovalWithCleanupCallback [structural] | [LLM] |
| 005730b0 | sub_5730B0 | [LLM] |
| 00573530 | sub_573530 | [LLM] |
| 00574ce0 | ThreadSafeCallWithMutex [structural] | [LLM] |
| 00575090 | ArithmeticComparison_5020 [exact] | [LLM] |
| 00575290 | StatusCheckViaVTableDispatch [exact] | [LLM] |
| 00575d40 | ThreadSafeWriteWithMutex [exact] | [LLM] |
| 00575d90 | MutexProtectedPointerReadRelease [exact] | [LLM] |
| 00576880 | sub_576880 | [LLM] |
| 00576a80 | sub_576A80 | [LLM] |
| 00577170 | FieldResetWithSubCall [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005bee90 | _strncmp | [LLM] |
| 005beec8 | _sprintf | [LLM] |
| 005bf71b | _sscanf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5D | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s%d`
- `%d %[^`
- ` %d %d.%d.%d.%d:%d`
- `%s%s %d %d.%d.%d.%d:%d`
- ` (%s)`
