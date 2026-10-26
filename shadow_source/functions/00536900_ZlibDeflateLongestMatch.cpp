// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536900
// Canonical corpus name: ZlibDeflateLongestMatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZlibDeflateLongestMatch_00536900.c

void UnknownObject::ZlibDeflateLongestMatch()
{
    // LZ77 longest-match search over a hash chain. Reads window and chain parameters from the deflate state a1, walks the prev-hash chain from candidate a2, probes candidates with a prefix comparison, extends matches byte-by-byte with an 8-byte unrolled loop, records the best match origin and length in the state, and returns the best length clamped to the lookahead. Matches the classic deflate longest_match structure.
    // ASSIGNMENT: Load the working set from the deflate state a1: window size at a1+34, string position at a1+98, nice-match limit at a1+134, window base at a1+46, chain budget at a1+114, and current best length at a1+110. [source:raw]
    // CALCULATION: Compute the chain-search lower bound v34: 0 when the position fits inside window_size - 262, otherwise position - window_size + 262, so candidates below it are out of the valid window. [source:raw]
    // ASSIGNMENT: Snapshot the current best-match suffix bytes from the window at the best-length positions (v5[result - 1] and v5[result]) and record the scan end pointer v5 + 258. [source:raw]
    // GUARD: Guard on the current best length reaching the threshold at a1+130; when true, quarter the chain budget (v32 >>= 2) to shorten the remaining search. [source:raw]
    // CALCULATION: Cap the nice-match limit v33 at the lookahead stored in a1+106, so the search stops once the nice length is reached. [source:raw]
    // LOOP: Hash-chain walk: each iteration advances candidate a2 through the prev chain at a1+54 indexed by a2 & mask(a1+42); the loop exits when the candidate falls at or below the lower bound v34 or the chain budget v32 is exhausted. [source:raw]
    // GUARD: Candidate prefix probe: compare the window bytes at the candidate for positions result, result - 1 and 0 against the current best-match bytes; only equal candidates proceed to full extension. [source:raw]
    // LOOP: Byte-by-byte match extension: advance the scan pointer (starting at window position + 2) and the candidate pointer together, comparing 8 bytes per unrolled pass, stopping on the first mismatch or when the scan reaches the end pointer v5 + 258. [source:raw]
    // STATE_TRANSITION: On a longer match (extended length v29 greater than the current best): record the match origin into a1+102, promote v29 as the new best length, refresh the best-match suffix bytes, and break the whole search when the length reaches the nice limit v33. [source:raw]
    // RETURN: Return the final best match length clamped to the lookahead v35: v35 when the best length exceeds it, otherwise the best length itself. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_536900(int s, unsigned int cur_match) {
    //     unsigned int pos = *(unsigned int *)(s + 98);
    //     unsigned int window_size = *(unsigned int *)(s + 34);
    //     unsigned int lower = (pos <= window_size - 262) ? 0 : pos - window_size + 262;
    //     unsigned char *scan = (unsigned char *)(pos + *(unsigned int *)(s + 46));
    //     unsigned int best = *(unsigned int *)(s + 110);
    //     unsigned int budget = *(unsigned int *)(s + 114);
    //     unsigned int nice = *(unsigned int *)(s + 134);
    //     unsigned char prev_byte = scan[best - 1];
    //     unsigned char cur_byte = scan[best];
    //     unsigned int lookahead = *(unsigned int *)(s + 106);
    //     if (best >= *(unsigned int *)(s + 130)) budget >>= 2;
    //     if (nice > lookahead) nice = lookahead;
    //     do {
    //       unsigned char *match = (unsigned char *)(cur_match + *(unsigned int *)(s + 46));
    //       if (match[best] == cur_byte && match[best - 1] == prev_byte && *match == *scan && match[1] == scan[1]) {
    //         unsigned char *p = scan + 2;
    //         unsigned char *q = match + 1;
    //         do { if (*++p != *++q) break; if (*++p != *++q) break;
    //              if (*++p != *++q) break; if (*++p != *++q) break;
    //              if (*++p != *++q) break; if (*++p != *++q) break;
    //              if (*++p != *++q) break; if (*++p != *++q) break; } while (p < scan + 258);
    //         unsigned int len = (unsigned int)(p - scan);
    //         if (len > best) {
    //           *(unsigned int *)(s + 102) = cur_match;
    //           best = len;
    //           if (len >= nice) break;
    //           prev_byte = scan[len - 1];
    //           cur_byte = scan[len];
    //         }
    //       }
    //       cur_match = *(unsigned short *)(*(unsigned int *)(s + 54) + 2 * (cur_match & *(unsigned int *)(s + 42)));
    //       if (cur_match <= lower) break;
    //       --budget;
    //     } while (budget);
    //     return (best > lookahead) ? lookahead : best;
    //   }
    // UNRESOLVED: The exact roles of the state fields (offsets 34, 42, 46, 54, 98, 102, 106, 110, 114, 130, 134) are inferred functionally from this function; canonical zlib deflate_state names are not evidenced by this packet.
    // UNRESOLVED: Whether this longest-match serves the shipped archive/compression path is inferred from the corpus name only; callers here are the inflate paths ZlibInflateDecompressionCore and InflateDecompressionLoop.
    // UNRESOLVED: The head hash-table lookup and insertion side of the deflate state are not present in this function, so the chain origin of a2 is external.
}
