# MAS filename bounds and search-order validation

Date: 2026-08-06. Evidence combines read-only instruction inspection of
`F1 Challenge Online.exe` SHA-256
`1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`
with two read-only Frida captures. No target memory was written and no target
function was invoked by the probe.

## Static boundary result

The root at `0x0053CBC0` reserves a 256-byte filename buffer and a separate
256-byte formatted-path buffer. Instructions `0x0053CBF0..0x0053CBF8` copy the
input byte-by-byte through its terminator without a capacity check. The fallback
call at `0x0053CC43` formats prefix, backslash, and filename into the second
buffer. Its formatter `0x0058815F` initializes its remaining-count field to
`0x7FFFFFFF`, so the function name's “overflow check” does not bound either
256-byte caller buffer. A replacement must reject overlong or unbounded input
before copying and must perform checked joins.

The instruction order is exact: uppercase the local filename, try it directly,
then walk `0x008B8E30` entries at `0x008B5A3C` in ascending index order with
stride `0x84`, stopping at the first successful open. Total failure returns
`-2`. Each prefix is consumed as an unbounded `%s` by the original, so the
replacement must also require a terminator within its 132-byte record.

## Runtime result

The full trace `mas_path_runtime_20260806.jsonl` contains 49 events: 10 complete
root calls, 28 open attempts, no Frida errors, 10 direct root attempts and four
fallback root attempts. All ten root inputs had a terminator within the first
1,024 readable bytes; the longest observed filename was 48 bytes. Four logical
names (`CDB.MAS`, `CMAPS.MAS`, `DRIVERS.MAS`, and `TEAM.MAS`) failed directly
and then succeeded through the registry. The other observed root paths opened
directly and did not enter the fallback loop.

The registry was observed in these states:

- empty during early `OPTIONS` archive loads;
- one entry, `SEASONDATA\VEHICLES\`, for vehicle-wide archives;
- two ordered entries for `TEAM.MAS`: the 40-byte car directory first, then the
  20-byte vehicle directory.

All observed prefixes include a trailing backslash. Because the recovered
format is `%s\%s`, successful fallback attempts contained two consecutive
backslashes. Native Windows lookup accepted them. Compatibility validation must
not reject that spelling merely because a normalized path would use one.

The parser at `0x0055FC40` reopened each logical filename after the root's
12-byte header probe. For fallback cases it again attempted the direct logical
name and then the selected prefixed path. This establishes current behavior but
also creates a time-of-check/time-of-use question: retaining the first selected
handle/path would be safer, while reopening is more literal compatibility. That
choice remains explicitly unresolved rather than being silently changed.

## Trace integrity and preview correction

The full trace is 18,007 bytes with SHA-256
`9BC43EBDFE364D591DD09E659637046A80B1DEB9E58A9BF7425B9F550521747C`.
Capture v1 used a sized Frida string conversion after independently finding the
terminator, which rendered the terminator as a final replacement character in
the preview only. The terminator offsets and raw bounded scans are unaffected.
The deterministic summarizer records this normalization explicitly. The fixed
probe omits the size only after proving a readable terminator, consistent with
Frida's documented sized-string semantics.

The clean follow-up `mas_path_runtime_20260806_v3.jsonl` is 1,952 bytes with
SHA-256 `465287C4991BADB9D802FA5B6A74D1D1C688AEEAF06B3135D5372B4F75FA6834`.
It recorded the two registry paths without the preview artifact and one
48-byte fully-qualified direct load. The shorter follow-up supplements rather
than replaces the broader immutable trace.

## Safe test boundary

No unterminated or overlong pointer was injected into the original root. Its
instruction-proven unbounded copy could corrupt the stack, so deliberately
calling it with malformed memory is not a read-only probe. Those cases belong
in the replacement harness described by `mas_path_boundary_matrix.json`.
Direct-versus-prefixed and multi-prefix collision outcomes are instruction-
proven but still need controlled differential fixtures before implementation
promotion.
