int __stdcall sub_53D8E0(int a1, int a2)
{
  return StringFormatWithBufferOverflowCheck(
           a2,
           "%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X",
           *(_DWORD *)a1,
           *(unsigned __int16 *)(a1 + 4),
           *(unsigned __int16 *)(a1 + 6),
           *(unsigned __int8 *)(a1 + 8),
           *(unsigned __int8 *)(a1 + 9),
           *(unsigned __int8 *)(a1 + 10),
           *(unsigned __int8 *)(a1 + 11),
           *(unsigned __int8 *)(a1 + 12),
           *(unsigned __int8 *)(a1 + 13),
           *(unsigned __int8 *)(a1 + 14),
           *(unsigned __int8 *)(a1 + 15));
}

