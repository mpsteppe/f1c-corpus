# Scene MAS mark-wrapper call-site instruction audit

Date: 2026-08-06. Static analysis only. Read-only source: `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe`, 3,141,632 bytes, SHA-256 `1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`. The executable was inspected with GNU `objdump`; it was not modified and the IDA database was not reopened.

## Scene-parser argument mapping

After the `0x0055B200` prologue, let `S` be the stable stack pointer following the three saved-register pushes. The decompiled locals map `v12` to `[S+0x20]` and the 256-byte string `v13` to `[S+0x24]`. At the scene `masfile` directive path:

- `0x0055B3A2: lea eax,[esp+0x24]` forms `&v13`, then `0x0055B3A6` pushes the filename.
- With the stack now four bytes lower, `0x0055B3A7: lea ecx,[esp+0x24]` forms `[S+0x20]`, exactly `&v12`, then `0x0055B3AB` pushes the output slot.
- `0x0055B3AC: mov ecx,ebx` restores the scene-parser `this` value before `0x0055B3AE` calls `0x0053CE10`.
- `0x0053CE10` consumes and callee-cleans the two stack arguments (`ret 8`). It does not read incoming `ECX`; it forwards the same unchanged register into `0x0053CBC0`.

The root loader saves incoming `ECX` and restores it before two calls to `0x0053C590`, but that helper overwrites the low byte `CL` before using it and otherwise consumes only its stack arguments. The inspected instruction path therefore does not establish a hidden semantic context parameter. The promoted two-stack-argument signatures remain the conservative ABI description, with full ABI review still outstanding.

## Output-slot initialization

No instruction from the `0x0055B200` prologue through the call at `0x0055B3AE` initializes `[S+0x20]`. The slot is used only by address at this call site. A normal recognized 410 MAS path writes the newly allocated object through the slot before the wrapper tests the root result. However, the root contract also has zero-return paths for null/empty input and unrecognized headers that do not establish an output object.

Consequently, a zero root result does not independently prove that `v12` is valid. `0x0053CE10` tests `&v12`, which is necessarily non-null here, loads the uninitialized/stale dword from `v12`, and ORs `0x8` at that value plus `0x114`. This is a statically evidenced unsafe original path for a zero result without output assignment. Whether scene files can reach it in deployed content is not runtime-confirmed.

## Replacement consequence

Code generation remains blocked until the replacement policy distinguishes successful object production from legacy zero-return/no-output cases. The safe design options include making zero-without-object an error, initializing and validating the output slot, or changing the loader result contract; choosing among them requires compatibility tests against real scene content.
