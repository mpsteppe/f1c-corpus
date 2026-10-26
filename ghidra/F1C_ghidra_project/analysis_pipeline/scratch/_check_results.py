#!/usr/bin/env python3
"""Check the extracted JSON data and report stats."""
import json

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\_extracted_fun_data.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

entries = data['entries']
print(f'Total entries after 960: {len(entries)}')

with_key = [e for e in entries if e['key_logic_summary'].strip()]
no_key = [e for e in entries if not e['key_logic_summary'].strip()]
print(f'With key logic: {len(with_key)}')
print(f'Without key logic: {len(no_key)}')

print('\n--- 10 samples WITHOUT key logic ---')
for e in no_key[:10]:
    print(f'  {e["address"]} line {e["line"]}: {e["description"][:80]}')

print('\n--- 5 samples WITH key logic ---')
for e in with_key[:5]:
    print(f'  {e["address"]}: {e["key_logic_summary"][:150]}')

# Check target doc distribution
from collections import Counter
targets = Counter(e['target'] for e in entries)
print('\n--- Target doc distribution ---')
for tgt, cnt in targets.most_common():
    print(f'  {tgt}: {cnt}')

# Count unique globals
all_globals = set()
for e in entries:
    for g in e['globals']:
        all_globals.add(g)
print(f'\nUnique globals referenced: {len(all_globals)}')
print(f'Sample globals: {sorted(list(all_globals))[:20]}')
