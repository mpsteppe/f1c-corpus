"""
Cross-binary function matching via shared strings.
Uses IDA exports (functions + strings) from both binaries.

Step 1: Export strings+xrefs from NASCAR 2003 via IDA
Step 2: Match against F1C's ida_strings.csv
"""
import csv
import re
from collections import defaultdict

def load_ida_strings(path):
    """Load ida_strings.csv format: address,string,length,type,referencing_functions"""
    strings = {}
    with open(path) as f:
        reader = csv.DictReader(f)
        for row in reader:
            s = row.get('string', '')
            refs = row.get('referencing_functions', '')
            if s and refs:
                func_addrs = [a.strip() for a in refs.split(';') if a.strip()]
                strings[s] = func_addrs
    return strings

def match_binaries(f1c_strings, nascar_strings):
    """Find functions that reference identical strings in both binaries."""
    matches = []
    shared_strings = set(f1c_strings.keys()) & set(nascar_strings.keys())
    
    # Filter to meaningful strings (not CRT, not single chars)
    meaningful = [s for s in shared_strings 
                  if len(s) > 8 
                  and not s.startswith('1#')
                  and '\Source\' not in s  # exclude path strings themselves
                  and not s.startswith('_')]
    
    print(f"Total shared strings: {len(shared_strings)}")
    print(f"Meaningful shared strings (>8 chars): {len(meaningful)}")
    
    # For strings referenced by exactly 1 function in each binary = strong match
    strong = []
    for s in meaningful:
        f1c_funcs = f1c_strings[s]
        nascar_funcs = nascar_strings[s]
        if len(f1c_funcs) == 1 and len(nascar_funcs) == 1:
            strong.append((s, f1c_funcs[0], nascar_funcs[0]))
    
    print(f"Strong 1:1 string matches: {len(strong)}")
    return strong

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 3:
        print("Usage: cross_binary_match.py <f1c_strings.csv> <nascar_strings.csv>")
        sys.exit(1)
    
    f1c = load_ida_strings(sys.argv[1])
    nascar = load_ida_strings(sys.argv[2])
    matches = match_binaries(f1c, nascar)
    
    for s, f1c_addr, nascar_addr in sorted(matches, key=lambda x: x[1]):
        print(f"  {f1c_addr} <-> {nascar_addr}  via \"{s[:60]}\"")
