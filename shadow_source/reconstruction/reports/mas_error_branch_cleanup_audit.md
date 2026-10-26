# MAS root error-branch cleanup audit

Date: 2026-08-06. Evidence: recovered raw C plus read-only disassembly of `F1 Challenge Online.exe` SHA-256 `1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`. Static analysis only.

## Branch matrix

| Path | Return | Object/list effects | Output-slot effect | Finding |
|---|---:|---|---|---|
| Null or empty filename | `0` | None | Untouched | Success-shaped no-output result; unsafe for consuming wrappers. |
| Direct and prefixed open failure | `-2` | None | Untouched | Root itself does not clear output; checked bridge clears, ordinary direct callers may retain stale locals. |
| Short 12-byte header read | Indeterminate | File closes | Depends on later dispatch | Read count is unchecked; `strcmp` can inspect uninitialized stack bytes and read beyond the intended header terminator. |
| Exact 4.00 or 4.01 header | `-1` | None | Untouched | Explicit obsolete-version rejection; output is not cleared by root. |
| Unknown header | `0` | None | Untouched | Accidental zero/no-output path. |
| 410 object allocation failure | Unsafe before return | Parser called with null `ECX` | Not safely reached for nonempty filename | Instruction-proven null-derived write beginning at address `0x14`. |
| Parser returns `-2` or `-1` | Same negative code | Allocated object is forwarded to the empty stub and freed; it was never registered | **Freed pointer is then written to output** | Instruction sequence `0x0053CD64..0x0053CD9D` frees `ESI`; `0x0053CDA9` still stores `ESI` through output. |
| Parser returns `0` | `0` | Appends object and increments count | Writes live object | Intended successful transaction, except null allocation would already have made this path unsafe. |
| Unexpected parser result | Existing local zero | Object is neither registered nor freed | Writes allocated object | Success-shaped leak/orphan; current parser return-domain audit found only `-2`, `-1`, and `0`. |

## Cleanup implications

The negative parser branches do release their locally allocated object exactly once, but they publish its freed address afterward. `0x00494FE0` masks this for its bitmap caller by clearing output on nonzero return. Scene wrapper `0x0053CE10` does not clear it, but its caller immediately takes the parse-failure exit and does not visibly consume the local afterward. Fourteen direct resource loaders have mixed return checking; many subsequently pass the returned value to single-node removal. The recovered removal routine searches the live list by address and does not dereference the requested object unless it finds that address, so an immediately freed, never-registered value normally becomes a not-found no-op rather than a second free. That behavior is fragile and must not become a replacement ownership convention.

The parser's own negative branches close any handle they successfully opened before returning. On invalid header it closes directly; on payload allocation failure it also closes. Open failure has no handle. Root-level object release therefore does not need the full teardown helper on those currently reachable negative paths. Payload reads and header-field reads remain unchecked, so malformed successful-looking archives can still retain incomplete data and an open handle.

## Required replacement behavior

- Clear output before entry and leave it null on every failure or no-object path.
- Never publish a pointer after freeing it.
- Never call the parser without an allocated/initialized object.
- Validate every read count and all shifted/range arithmetic before committing ownership.
- Register and publish only after complete parse success.
- Normalize unexpected parser results to failure with cleanup.
- Make caller cleanup operate on explicit ownership tokens or nullable objects, not on stale addresses searched in a global list.

This closes the static error-branch inventory. Runtime differential work remains necessary to validate compatibility with real failure cases and to observe thread confinement.
