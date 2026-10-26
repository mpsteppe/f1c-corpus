# MAS call-flow and teardown instruction audit

Date: 2026-08-06. Source database: `analysis/sdk_lab_idb/F1_Challenge_Online_sdk_lab.i64`. Evidence export: `mas_callflow_ida_export.json`. Static analysis only; no runtime or ABI-reviewed claim.

## Root-to-parser argument mapping

The machine instructions resolve the pseudocode omission at the `0x0053CBC0` to `0x0055FC40` call:

- `0x0053CCED: E8 11 AF 04 00` calls the 308-byte allocation wrapper.
- On success, `0x0053CCF9: 8B C8` moves the allocation to `ECX`, `0x0053CCFB` calls the initializer, and `0x0053CD00: 8B F0` saves its returned object in `ESI`.
- On allocation failure, `0x0053CD04: 33 F6` zeroes `ESI`.
- `0x0053CD06` forms the local filename address, `0x0053CD0A: 51` pushes it as the stack argument, `0x0053CD0B: 8B CE` moves `ESI` into `ECX`, and `0x0053CD0D` calls `0x0055FC40`.

Therefore the parser is a one-stack-argument thiscall: object in `ECX`, filename on the stack. The decompiler rendered only the explicit filename argument.

## Allocation failure

Allocation failure is not handled before the parser call. It supplies `ECX=0`. The parser saves `ECX` in `EBX` at `0x0055FC4F`; for a non-empty filename it executes `lea esi, [ebx+14h]` at `0x0055FC60` and writes through that derived destination beginning at address `0x14`. This is a statically proven unsafe original path. Whether the allocator can return null in deployed configurations is not established.

## Parser return domain

The parser's recovered exits return only `-2`, `-1`, or `0`: total open failure returns `-2`; invalid input, bad version, or payload-allocation failure returns `-1`; successful payload read returns zero. The root nevertheless contains a nonzero/default branch, which remains worth preserving defensively in replacement behavior.

## Teardown

`0x0055FE30` conditionally closes the field at `+0x10`, clears it, conditionally frees the field at `+0x128`, clears it, and returns zero.

`0x0053CE40` walks the list rooted at `0x008B8F14` through `+0x130`, unlinks a found node using `+0x12C/+0x130`, invokes `0x0055FE30`, the forwarding stub at `0x00557470`, and the CRT free wrapper, then decrements `0x008B6AC0`. Empty-list and not-found paths return zero without mutation.

## Database handling note

The first autonomous export attempt exited through a script exception and left the database hash unchanged. After correcting the exit API, IDA flushed/repacked the `.i64` database on exit even though the script made no database API edits; its file hash changed from `8A16A430CDABA270ABFD2C5171B65BDDE2737E29BB337A3745A257FB3A2DB9E0` to `BDBE1E509F54D36AE87D44B75BCE99D53C15F0BB543BD84BCAD8CAEB8BE0262F`. The database is preserved as written and was not opened again. The original executable was not modified.
