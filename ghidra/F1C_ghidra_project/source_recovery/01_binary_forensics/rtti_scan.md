# BF-02: RTTI Pattern Scan

**Status:** DONE (2026-07-16)

## Results

20 `.?AV` hits — **all STL/CRT classes**, zero ISI game classes.

| Offset | Demangled Name |
|--------|---------------|
| 0x1e9f00 | std::ios_base |
| 0x1e9f20 | std::basic_ios<char> |
| 0x1e9f58 | std::basic_istream<char> |
| 0x1e9f98 | std::basic_ostream<char> |
| 0x1e9fd8 | std::basic_streambuf<char> |
| 0x1ea018 | std::basic_filebuf<char> |
| 0x1ea058 | std::basic_ios<wchar_t> |
| 0x1ea090 | std::basic_istream<wchar_t> |
| 0x1ea0d0 | std::basic_ostream<wchar_t> |
| 0x1ea110 | std::basic_filebuf<wchar_t> |
| 0x1ea150 | std::basic_streambuf<wchar_t> |
| 0x1ea190 | exception |
| 0x1ea1a8 | std::runtime_error |
| 0x1ea1c8 | std::ios_base::failure |
| 0x1ea1f0 | std::locale::facet |
| 0x1ea210 | std::locale::_Locimp |
| 0x1ea238 | std::logic_error |
| 0x1ea258 | std::length_error |
| 0x1ea278 | std::out_of_range |
| 0x1ea298 | type_info |

Zero `.?AU` (struct RTTI) hits.

## Conclusion

**CLAUDE.md `/GR-` claim CONFIRMED.** Game code compiled without RTTI.
The 20 hits come from the statically-linked MSVC STL/CRT, which always has RTTI.
No ISI class names recoverable from RTTI. This avenue is closed for F1C.

Cross-binary check (F1 2002 WIP Demo, Sports Car GT) may still yield results
if those binaries used different compiler flags.
