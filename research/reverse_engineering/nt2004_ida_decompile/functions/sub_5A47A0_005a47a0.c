int __stdcall sub_5A47A0(int a1, char *Buffer)
{
  return sprintf(
           Buffer,
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
