// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588640
// Canonical corpus name: sub_588640
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588640_00588640.c

void UnknownObject::BoundedStringByteCompare()
{
    // Bounded case-sensitive byte-string comparison. Scans a1 for its first null byte within an a3-byte budget to derive an effective compare length v6 = a3 - v3, then compares a2 against a1 for that many bytes, stopping at the first mismatch. Returns a normalized -1/0/1 verdict based on the final compared byte pair: -1 when the a2 tail byte is greater, 1 when smaller, 0 when equal. When a3 is zero the body is skipped and 0 is returned. Its 14 static callers include path and scene parsers (PathDirectoryExtractionAndComparison, SceneFileTopLevelParser, CloudSceneObjectRandomSelector, SpecialFX_Init), consistent with a shared path/name comparison utility.
    // ASSIGNMENT: Load the length budget: v3 = a3. [function:0x00588640, source:raw]
    // GUARD: When a3 is zero the whole body is skipped and the function returns 0. [source:raw]
    // LOOP: Scan a1 for the first null byte, decrementing v3 per byte and stopping when a null is found or the budget runs out. [source:raw]
    // CALCULATION: Effective compare length: v6 = a3 - v3, i.e. how many leading non-null bytes of a1 fit within the budget. [source:raw]
    // LOOP: Compare a2 against a1 byte by byte for v6 iterations, stopping at the first mismatch. [source:raw]
    // CALCULATION: Compare the final bytes of both strings: v9 = *(a2 - 1) against *(v7 - 1). [source:raw]
    // RETURN: Return the normalized verdict: ~0 (-1) when the a2 tail byte is greater, ~(-2) (1) when smaller, 0 when equal. [source:raw]
    // CALL: Invoked as a path/name comparison by 14 static callers including PathDirectoryExtractionAndComparison, SceneFileTopLevelParser, CloudSceneObjectRandomSelector and SpecialFX_Init. [caller:0x00433290, caller:0x0055B200, caller:0x004FC2F0, caller:0x004CF070, source:raw]

    // Conservative worker pseudocode:
    //   int BoundedStringByteCompare(char* a1, char* a2, int a3) {
    //     if (a3) {
    //       int budget = a3;
    //       char* p = a1;
    //       while (budget && *p != 0) { ++p; --budget; }
    //       int len = a3 - budget;
    //       char* q = a1;
    //       while (len && (*a2++ == *q++)) --len;
    //       unsigned char c2 = *(a2 - 1);
    //       unsigned char c1 = *(q - 1);
    //       if (c2 > c1) return -1;
    //       if (c2 != c1) return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Caller contracts are not inspected here; the exact reason each of the 14 callers needs a bounded (not full-strlen) compare is unverified.
}
