import os

ROOT     = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
ANALYZED = os.path.join(ROOT, "analysis_pipeline", "analyzed")

FILES = [
    ("0x0056fa96__FUN_0056fa96.c", "docs/18-physics-dynamics.md"),
    ("0x00575bbd__FUN_00575bbd.c", "docs/18-physics-dynamics.md"),
    ("0x00578f76__FUN_00578f76.c",  "docs/18-physics-dynamics.md"),
]

HEADER = """You are documenting F1 Challenge 99-02 (x86 MSVC 2002 game engine).

Write a full ## FUN_ entry for EACH function below.

Format for each:
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp. One-line summary.

**Key logic:**
- bullet points describing behavior, branches, thresholds

**Globals:**
- `DAT_XXXXXXXX` or `dbl_XXXXXXXX` — meaning

**Calls:** FUN_XXXXXX (purpose per docs/NN)

**Moddability:** hardcoded | configurable | hookable

Known symbols:
- sub_58BB10 = memset
- sub_58BBA0 = memcpy
- dbl_ prefix = global double-precision float
- flt_ prefix = global single-precision float
- Physics globals 0x8D0000-0x8D9000 = physics simulation state block
- Neighbor context: FUN_0056f020 iterates physics bodies, FUN_0056f060 is batch counter
- All 3 functions are near each other in .text — likely physics/aerodynamics/dynamics

=== FUNCTIONS ===

"""

parts = [HEADER]
for fname, target in FILES:
    path = os.path.join(ANALYZED, fname)
    size = os.path.getsize(path)
    content = open(path, encoding="utf-8", errors="replace").read()
    if len(content) > 40000:
        content = content[:40000] + f"\n// [TRUNCATED — {len(content)-40000} bytes omitted]\n"
    parts.append(f"<!-- target: {target} -->\n")
    parts.append(f"// FILE: {fname} ({size} bytes)\n")
    parts.append(content)
    parts.append("\n\n")

prompt = "".join(parts)
out = os.path.join(ROOT, "work", "worker_gap3_prompt.md")
with open(out, "w", encoding="utf-8") as f:
    f.write(prompt)
print(f"Written: {out} ({os.path.getsize(out)//1024}KB)")
