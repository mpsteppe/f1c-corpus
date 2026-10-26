"""UserPromptSubmit hook: re-inject the project's iron rules every turn.

A 460-line CLAUDE.md decays over a long session; 5 lines injected per prompt
do not. Keep this SHORT — its whole value is being small and always present.
"""
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
print(
    "F1C iron rules (every turn): "
    "LOCATE code with tools/investigate.py (find/system/mod/dossier), never raw grep fan-out. "
    "MODS: read mods/_README.md ledger first; verify every fact with tools/preflight.py "
    "against the live game BEFORE writing code; memory write > byte redirect > detour; "
    "NEVER call game internals from injected code. "
    "Docs are GUESS tier - trust raw .c and the live process, not doc labels."
)
