int __cdecl sub_5121AE(
        int a1,
        int a2,
        unsigned int *a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        _DWORD *a8,
        _DWORD *a9)
{
  int v9; // eax

  if ( !a1 || !a2 || !a3 || !a4 || !a5 || !a6 )
    return 0;
  *a3 = *(_DWORD *)a2;
  *a4 = *(_DWORD *)(a2 + 4);
  *a5 = *(unsigned __int8 *)(a2 + 24);
  *a6 = *(unsigned __int8 *)(a2 + 25);
  if ( a8 )
    *a8 = *(unsigned __int8 *)(a2 + 26);
  if ( a9 )
    *a9 = *(unsigned __int8 *)(a2 + 27);
  if ( a7 )
    *a7 = *(unsigned __int8 *)(a2 + 28);
  if ( *a6 == 3 )
    v9 = 1;
  else
    v9 = *a6 & 2 | 1;
  if ( (*a6 & 4) != 0 )
    ++v9;
  if ( *a3 > 0x7FFFFFFFu / ((v9 * *a5 + 7) >> 3) )
    CallbackDispatch(a1, (int)"Width too large for libpng to process image data.");
  return 1;
}
