// f1c  0x005356a0  size=276
int __fastcall sub_5356A0(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  int v7; // eax
  int v8; // eax

  if ( !a3 || *a3 != a113_0[0] || a4 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v7 = a1[8];
  a1[6] = 0;
  if ( !v7 )
  {
    a1[8] = sub_536FD0;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = &sub_536FF0;
  v8 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1, 24);
  a1[7] = v8;
  if ( !v8 )
    return -4;
  *(_DWORD *)(v8 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    a2 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( a2 < 8 || a2 > 15 )
  {
    sub_535660(a1);
    return -2;
  }
  else
  {
    *(_DWORD *)(a1[7] + 16) = a2;
    *(_DWORD *)(a1[7] + 20) = sub_537070(1 << a2);
    if ( *(_DWORD *)(a1[7] + 20) )
    {
      sub_535620(a1);
      return 0;
    }
    else
    {
      sub_535660(a1);
      return -4;
    }
  }
}
