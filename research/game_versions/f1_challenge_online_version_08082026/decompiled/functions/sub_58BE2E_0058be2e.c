_BYTE *__cdecl sub_58BE2E(_BYTE *a1, int a2, int a3, int a4, char a5)
{
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  int v7; // ebx

  if ( a5 )
    sub_58C0D0(&a1[*(_DWORD *)a4 == 45], a2 > 0);
  v5 = a1;
  if ( *(_DWORD *)a4 == 45 )
  {
    *a1 = 45;
    v5 = a1 + 1;
  }
  if ( a2 > 0 )
  {
    *v5 = v5[1];
    *++v5 = byte_5E6BD8;
  }
  v6 = (_BYTE *)sub_58FCA0(&v5[(a5 == 0) + a2]);
  if ( a3 )
    *v6 = 69;
  if ( **(_BYTE **)(a4 + 12) != 48 )
  {
    v7 = *(_DWORD *)(a4 + 4) - 1;
    if ( v7 < 0 )
    {
      v7 = 1 - *(_DWORD *)(a4 + 4);
      v6[1] = 45;
    }
    if ( v7 >= 100 )
    {
      v6[2] += v7 / 100;
      v7 %= 100;
    }
    if ( v7 >= 10 )
    {
      v6[3] += v7 / 10;
      v7 %= 10;
    }
    v6[4] += v7;
  }
  return a1;
}
