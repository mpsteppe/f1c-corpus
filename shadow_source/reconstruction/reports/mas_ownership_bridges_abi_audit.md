# MAS ownership bridges instruction/ABI audit

Date: 2026-08-06. Read-only disassembly of `F1 Challenge Online.exe` SHA-256 `1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`.

`0x00494FE0` reads its first stack argument from `[esp+4]`, saves the second from `[esp+8]` after its register push, forwards them to `0x0053CBC0` in reversed push order, conditionally clears the second argument's pointee when the result is nonzero, and executes `ret 8`. This confirms the two-stack-dword callee-cleanup ABI mechanically.

Before the root call, `0x00494FE4` loads dword `0x008AFE64` into `ECX`. The promoted bridge contract omitted that direct global read because it is absent from decompiler C. Root `0x0053CBC0` saves incoming `ECX` and restores it before calls to `0x0053C590`; that helper overwrites `CL` from the copied string byte before use and has no recovered object-field access. The value is therefore not proven semantically relevant in this binary, but exact bridging code must preserve it until ABI review decides whether the forwarding is vestigial.

`0x00495010` also loads `0x008AFE64` into `ECX`, then tail-jumps to `0x0053CE40`. The target takes its object value from the stack, ignores incoming `ECX`, returns zero on all recovered paths, and executes `ret 4`. Thus the bridge is mechanically a one-stack-dword tail-forwarder that inherits target result and cleanup, with the same direct-but-currently-unconsumed global read.

The promoted artifacts remain immutable. `promoted_contract_errata.json` is the machine-readable correction layer. This audit does not elevate either bridge to full ABI-reviewed status because the role and initialization/lifetime of `0x008AFE64`, binary variants, and replacement boundary conventions remain unresolved.
