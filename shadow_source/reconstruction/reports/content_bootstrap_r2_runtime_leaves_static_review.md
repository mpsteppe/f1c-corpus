# Static review: MAS dependency leaves

Three dependency-closed one-function packets produced three valid independent
candidates each. Raw-body adjudication retained only directly visible facts:

- `0x004B0170` is an empty extracted body; calling convention and intent remain
  unknown.
- `0x0053C2A0` returns its unused `this` pointer and zeroes exactly a DWORD at
  `0x008B6AB8` plus a byte at `0x008B6AC8`.
- `0x0053C590` copies a null-terminated source into the global byte buffer at
  `0x008B6AC8`, without a bounds check, and returns a one-past-source pointer.

Candidate lifecycle labels, owner guesses, and semantic global names were not
promoted. `RECONCILED` remains an evidence-grounded static state, not runtime or
ABI confirmation.
