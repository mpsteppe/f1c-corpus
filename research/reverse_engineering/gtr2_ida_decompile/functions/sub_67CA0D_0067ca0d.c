void __stdcall sub_67CA0D(int a1)
{
  if ( !*(_DWORD *)(a1 + 220) )
    sub_679F05(a1, (int)"NULL row buffer");
  if ( (*(_BYTE *)(a1 + 97) & 0x10) != 0 )
  {
    if ( *(_BYTE *)(a1 + 248) == 3 )
    {
      sub_67BF7B(
        (int *)(a1 + 240),
        *(_DWORD *)(a1 + 220) + 1,
        *(_DWORD *)(a1 + 260),
        *(_DWORD *)(a1 + 348),
        *(unsigned __int16 *)(a1 + 266));
    }
    else if ( *(_WORD *)(a1 + 266) )
    {
      sub_67C186((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1, (_WORD *)(a1 + 352));
    }
    else
    {
      sub_67C186((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1, 0);
    }
  }
  if ( (*(_BYTE *)(a1 + 97) & 0x20) != 0 && *(_BYTE *)(a1 + 278) != 3 )
    sub_67BC29(
      (int *)(a1 + 240),
      (_BYTE *)(*(_DWORD *)(a1 + 220) + 1),
      *(unsigned __int8 **)(a1 + 312),
      *(_DWORD *)(a1 + 324),
      *(_DWORD *)(a1 + 300));
  if ( (*(_BYTE *)(a1 + 97) & 4) != 0 )
    sub_67B9AA(a1 + 240, (_BYTE *)(*(_DWORD *)(a1 + 220) + 1));
  if ( (*(_BYTE *)(a1 + 96) & 0x40) != 0 )
  {
    sub_67C4DF((int *)(a1 + 240), (char *)(*(_DWORD *)(a1 + 220) + 1), *(_DWORD *)(a1 + 372), *(_DWORD *)(a1 + 376));
    if ( !*(_DWORD *)(a1 + 244) )
      sub_679F05(a1, (int)"png_do_dither returned rowbytes=0");
  }
  if ( (*(_BYTE *)(a1 + 96) & 8) != 0 )
    sub_67B82C(a1 + 240, (_BYTE *)(*(_DWORD *)(a1 + 220) + 1), (unsigned __int8 *)(a1 + 341));
  if ( (*(_BYTE *)(a1 + 96) & 4) != 0 )
    sub_67B719((int *)(a1 + 240), *(_DWORD *)(a1 + 220) + 1);
  if ( (*(_BYTE *)(a1 + 96) & 1) != 0 )
    sub_67B522((int *)(a1 + 240), (char *)(*(_DWORD *)(a1 + 220) + 1));
  if ( *(char *)(a1 + 97) < 0 )
    sub_67B9F4(a1 + 240, *(_DWORD *)(a1 + 220) + 1, *(unsigned __int16 *)(a1 + 286), *(_DWORD *)(a1 + 92));
  if ( (*(_BYTE *)(a1 + 96) & 0x10) != 0 )
    sub_67B4EF(a1 + 240, (char *)(*(_DWORD *)(a1 + 220) + 1));
}
