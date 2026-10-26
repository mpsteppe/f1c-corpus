# MAS root caller and ABI audit

Date: 2026-08-06. Static evidence only. Read-only disassembly of
`F1 Challenge Online.exe` SHA-256
`1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`.

## Mechanical boundary

`0x0053CBC0` reads its filename from entry `[ESP+8]`, its output slot from entry
`[ESP+4]`, and returns with `ret 8`. The output type is an optional pointer to a
32-bit object pointer. The filename is read and copied but not modified. The
portable replacement-facing declaration is therefore mechanically equivalent
to:

```c
int32_t __stdcall load_mas(void **output, const char *filename);
```

Pointer width remains fixed at 32 bits for binary bridging. An internal source
API should use typed handles and explicit result values rather than exporting
raw object layout.

## Incoming ECX audit

There are 23 direct call instructions to the root. Twenty-two load
`[0x008AFE64]` into `ECX` immediately before the call. The remaining instruction
is inside wrapper `0x0053CE10`, which preserves its incoming `ECX`; its sole
caller at `0x0055B3AE` supplies the scene parser's `EBX` value.

The root saves incoming `ECX` in `EBP`, but consumes it only by restoring it
before calls to `0x0053C590` on total-open failure or obsolete-version failure.
Instructions `0x0053C590..0x0053C5AA` never read the incoming value: `CL` is
overwritten from each source byte before being used as copy data, and the helper
otherwise consumes two stack arguments and executes `ret 8`. Root success,
unknown-header, and parser-result paths do not consume the saved value.

Consequently, incoming `ECX` is mechanically present but semantically dead in
this executable. Exact in-place observation may preserve arbitrary `ECX`, but a
replacement source ABI does not require a hidden context parameter. This closes
the root's calling-convention question for the exact reviewed binary; it does
not establish ABI portability to another executable variant.

## Wrapper consequence

`0x0053CE10` also has two callee-cleaned stack arguments and does not consume
incoming `ECX` itself. It may be represented as the same two-argument ABI plus
its success-side flagging behavior. Its known zero-without-object dereference
hazard remains a semantic issue, not an ABI issue, and replacement code must
validate the produced object before writing offset `0x114`.

## Status

The exact-binary root and mark-prunable wrapper ABI are instruction-reviewed.
Remaining implementation gates are path/handle lifetime policy, object/list
ownership, synchronization/thread admission, and negative-path tests. No claim
is made that the original functions are safe to invoke with malformed inputs.
