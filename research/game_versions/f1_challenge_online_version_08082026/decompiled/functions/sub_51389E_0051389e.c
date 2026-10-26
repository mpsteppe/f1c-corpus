void __cdecl sub_51389E(int a1)
{
  if ( !*(_DWORD *)(a1 + 220) )
    sub_511869(a1, (int)"NULL row buffer");
  if ( (*(_BYTE *)(a1 + 97) & 0x10) != 0 )
  {
    if ( *(_BYTE *)(a1 + 248) == 3 )
    {
      sub_512E1A(
        (int *)(a1 + 240),
        *(_DWORD *)(a1 + 220) + 1,
        *(_DWORD *)(a1 + 260),
        *(_DWORD *)(a1 + 348),
        *(unsigned __int16 *)(a1 + 266));
    }
    else if ( *(_WORD *)(a1 + 266) )
    {
      sub_513022((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1, (_WORD *)(a1 + 352));
    }
    else
    {
      sub_513022((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1, 0);
    }
  }
  if ( (*(_BYTE *)(a1 + 97) & 0x20) != 0 && *(_BYTE *)(a1 + 278) != 3 )
    sub_512ACC(
      (int *)(a1 + 240),
      (_BYTE *)(*(_DWORD *)(a1 + 220) + 1),
      *(unsigned __int8 **)(a1 + 312),
      *(_DWORD *)(a1 + 324),
      *(_DWORD *)(a1 + 300));
  if ( (*(_BYTE *)(a1 + 97) & 4) != 0 )
    sub_512850(a1 + 240, (_BYTE *)(*(_DWORD *)(a1 + 220) + 1));
  if ( (*(_BYTE *)(a1 + 96) & 0x40) != 0 )
  {
    sub_513374((int *)(a1 + 240), (char *)(*(_DWORD *)(a1 + 220) + 1), *(_DWORD *)(a1 + 372), *(_DWORD *)(a1 + 376));
    if ( !*(_DWORD *)(a1 + 244) )
      sub_511869(a1, (int)"png_do_dither returned rowbytes=0");
  }
  if ( (*(_BYTE *)(a1 + 96) & 8) != 0 )
    sub_5126D9((int *)(a1 + 240), (_BYTE *)(*(_DWORD *)(a1 + 220) + 1), (unsigned __int8 *)(a1 + 341));
  if ( (*(_BYTE *)(a1 + 96) & 4) != 0 )
    sub_5125C9((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1);
  if ( (*(_BYTE *)(a1 + 96) & 1) != 0 )
    sub_5123E0((int *)(a1 + 240), (char *)(*(_DWORD *)(a1 + 220) + 1));
  if ( *(char *)(a1 + 97) < 0 )
    sub_512894(a1 + 240, *(_DWORD *)(a1 + 220) + 1, *(unsigned __int16 *)(a1 + 286), *(_DWORD *)(a1 + 92));
  if ( (*(_BYTE *)(a1 + 96) & 0x10) != 0 )
    sub_5123B3(a1 + 240, (char *)(*(_DWORD *)(a1 + 220) + 1));
}
