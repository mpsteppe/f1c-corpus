## LinkedListDereference_004c2850 — LinkedListCursorRead

**Summary:** Returns the data pointer at the current list cursor position by dereferencing the node at this+0x4. Saves the cursor node pointer to this+0x8 for later use. Returns 0 if cursor is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PerDriverRaceCommentary (00419c50), SeasonDisplayIDResolver (0041daf0), ScoringClassificationDisplay (0041e320), NestedDataSectionFieldAccessor (0041e840), AIEntrantLookupByName (0041e890), BestLapEntrantFinder (0041e920), ScoringSessionStatsAggregator (0041eb30), CRTMathHelper (0041ed30), ChampionshipScore (0041eda0), ArrayScanForValue10 (0041ef00), CountMatchingSeasonEntries (0041efe0), RelativePerformanceComparator (0041f070), TripleValueEqualityCheck (0041f100), SeasonRaceCountCheck (0041f150), ShortComputation_f190 (0041f190), ShortComputation_f1e0 (0041f1e0), ChampionshipPointsAccumulator (0041f220), sub_41F5D0 (0041f5d0), ConstructorChampionshipClinchDetection (0041f8a0), MemoryAllocation_fb10 (0041fb10), SessionStateSearch (0041fc60), ConfigSectionSearchByKeyValue (0041fe00), SceneElementScanWithConditionCheck (0041ff10), sub_4203F0 (004203f0), PositionChangeDetector (00420490), ShortComputation_12e0 (004212e0), CountActiveEntitiesByState (00421380), sub_47C360 (0047c360), sub_4A0590 (004a0590), SessionInit (004a06e0), sub_4A0760 (004a0760), sub_4A08E0 (004a08e0), SessionActiveCheck (004a09a0), LinkedListNodeRemovalWithCleanup (004c1820), DelegatedFieldGetter (004c2760), ArrayCheckInit (004c2810), ConditionalSeasonDataFree (004c2830), sub_4C2990 (004c2990), ConditionalCallWrapper_29b0 (004c29b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | list cursor/current node pointer, read for dereference |
| this | 0x8 | RW | — | snapshot of cursor node pointer, saved for later use |

**Written-by note (persistence):**
- this 0x8: set to this[1] value each call (unconditionally if non-null) — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this+0x4 (cursor) is null, returns 0 without writing to this+0x8. PASSES: non-null cursor at this+0x4.
