# Proposed MAS replacement failure policy

Date: 2026-08-06. Status: implementation policy proposed from static contracts plus read-only installed-content evidence. This is not a runtime-equivalence claim and does not authorize code generation while remaining ownership, synchronization, and ABI gates are open.

## Compatibility target

Use a strict, transactional 410 loader internally while preserving the legacy public return distinctions that are supported by recovered callers:

- `0`: a valid object was completely produced, or an explicitly documented optional no-op adapter accepted null/empty input.
- `-2`: the archive could not be found or opened through the configured search order.
- `-1`: invalid/obsolete header, short read, malformed size fields, allocation failure, parser failure other than open failure, arithmetic overflow, or any zero-result path that failed to produce an object where the caller requires one.

The internal object-producing operation must never report success without a non-null output. If compatibility requires the root adapter to retain null/empty input as a zero-return no-op, it must clear the caller's output slot first and expose the distinction internally; object-consuming wrappers must convert zero-without-object to `-1`.

## Transactional rules

1. Clear a supplied output slot before any file or allocation operation.
2. Reject overlong paths before copying or formatting. Preserve direct-path-first and ordered registered-prefix fallback behavior within bounded buffers.
3. Require an exact 12-byte header read. Accept `CUBEMAS4.10\0` for the recovered scene/resource loader. Report 4.00, 4.01, unknown, empty, and truncated headers as `-1` on this path.
4. Allocate and initialize only after the header is accepted. Stop immediately on allocation failure; never invoke the parser with null object context.
5. Validate shifted and multiplied size fields before allocation, require full reads, and reject directory or per-record ranges extending beyond the file. Treat the offset-20 header total as advisory and permit bytes after the final declared record; 111 installed archives have a stale total and one has 18,286 trailing bytes.
6. Treat only parser result `0` plus a valid object as success. Propagate `-2`; normalize all other nonzero or unexpected results to `-1` after local cleanup.
7. Link the object and increment the global/live-object count only after complete parser success. A failure must leave the list, count, and output unchanged from their cleared-entry state.
8. A consuming wrapper such as `0x0053CE10` or `0x00494FE0` must validate the produced object before flagging it or transferring it to another owner.

## Evidence and compatibility rationale

The original root explicitly reports 4.00/4.01 as incorrect versions but accidentally returns zero for unknown headers. It also invokes the parser after allocation failure and can register a null object. Those behaviors violate the root's own object-producing caller assumptions and are treated as defects, not compatibility requirements.

The installed tree contains 664 `.MAS` files, all with `CUBEMAS4.10\0`. The narrower scene audit found the same header across every one of 458 candidate archives referenced by 1,391 directives. Therefore rejecting obsolete or unknown versions does not exclude any archive observed in this installation. A full bounds audit also shows that the offset-20 header total differs from the actual payload in 111 archives, while per-record stored sizes bound the payload in 663. The remaining archive has 18,286 trailing bytes. Consequently, header-total equality and exact EOF equality are not compatibility-safe global checks. The existing `font_mas_tool.py` can parse 4.00/4.01 containers for tooling purposes, but that broader offline-reader support does not override the recovered root loader's explicit old-version rejection.

## Required tests before implementation promotion

- Exact 410 success with empty and non-empty live-object lists; output, links, count, and flag preservation checked.
- Missing file and exhausted search paths produce `-2` without allocation or list mutation.
- Null/empty adapter input clears output and performs no I/O; every object-consuming wrapper rejects the absent object.
- 4.00, 4.01, unknown, empty, and 1-11-byte headers produce `-1` without allocation or list mutation.
- Allocation failure, payload-allocation failure, short reads, shifted-size overflow, out-of-file ranges, and unexpected parser results clean up exactly once.
- Differential runs against representative installed scenes, fonts, cockpit, pit-animation, special-effects, cloud, and bitmap archive call sites.
- The checked-in `fixtures/mas_negative` corpus must verify byte-for-byte before tests run; it includes stale-total and trailing-byte acceptance controls as well as malformed inputs.

## Remaining gate

This policy closes the semantic choice for the known null/invalid-output hazards. Code generation still requires a reviewed synchronization/ownership boundary for the live archive list and ABI review of the public bridge functions.
