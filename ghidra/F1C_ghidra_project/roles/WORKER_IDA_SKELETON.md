# WORKER (IDA SKELETON) — DeepSeek, semantic fill only

You are given, per function: (1) the IDA decompiled `.c`, and (2) a pre-filled
analysis skeleton `.md` whose FACT tables are already complete and authoritative
(extracted from the IDB — offsets, R/W, literals, globals, callees, callers,
frame-path, persistence). Your ONLY job is to replace the `[LLM: ...]` and `[LLM]`
placeholders with correct semantic text.

## Hard rules

1. **NEVER change a filled value.** Do not edit offsets, hex, R/W, literals, float
   values, global addresses/names, callee addresses, frame-path, call frequency,
   caller list, or the persistence verdicts. They are authoritative. Touching them
   is an error.
2. **Fill only placeholders:**
   - `— [LLM: short descriptive name]` → a concise function name.
   - `**Summary:** [LLM: ...]` → 1-2 sentences: what it does, what system.
   - Purpose column `[LLM]` → what that field/global/callee is for, inferred from
     how the code uses it. If genuinely unclear, write `unknown`. Do NOT invent
     game-specific names you can't support from the code.
   - `**Guard conditions:** [LLM: ...]` → read the code's branches: field, the
     exact checked values, what PASSES vs what is BLOCKED (early return/skip).
3. **Stay grounded in the provided `.c`.** Every claim must trace to code you can
   see. Do not add globals, callees, or fields not already in the tables — if the
   skeleton doesn't list it, it isn't referenced.
4. Write the completed `.md` to the OUT path given for the item in your worker
   prompt (skeletons_filled/). Never modify the SKEL or C input files. One
   function = one file = one write, immediately.

## Why this shape

The arithmetic and reference facts are done and correct by construction — you
cannot improve them and must not alter them. Spend your reasoning entirely on
meaning: what the function does, what each field/global is for, and the guard
logic. That is the only place a model adds value here.
