# SKILL.md Template

Copy this structure exactly. Replace all `<...>` placeholders. Delete unused optional
sections only if truly empty. Keep ≤ ~150 lines.

```markdown
---
name: f1c-<name>
description: <One sentence what this does. Use when <concrete trigger phrases a task would contain>. Do NOT use for <adjacent workflow> — use f1c-<other> instead.
---

# <Title — verb phrase>

## When to use / when not

<2–4 lines. Positive triggers. Route-outs to sibling skills by name.>

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| <e.g. knowledge graph built> | `<command>` | <what success looks like> |

## Procedure

### Step 1: <verb phrase>

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && <exact command>
```
Expected output: <short snippet or description of shape>
If instead you see <symptom> → <recovery action or STOP>.

### Step 2: <verb phrase>
<... repeat. Prefix any step that needs the running game with `LIVE:`.>

## STOP — do not proceed if

- <hard condition> → <what to do instead>
- <hard condition> → <what to do instead>

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| <exact error text or observable> | <cause> | <action> |

## Deep reference

Read `reference.md` in this skill's directory for <topics covered there>.

---
Canonical sources: <path §Section>; <path §Section>
Last validated: <YYYY-MM-DD> against <git short-hash>
```
