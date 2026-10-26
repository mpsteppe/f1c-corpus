_BYTE *__usercall _cftoe2@<eax>(int a1@<eax>, _BYTE *a2@<ebx>, int a3, int a4, char a5)
{
  _BYTE *v6; // eax
  char *v7; // eax
  _BYTE *v8; // ecx
  int v9; // eax
  _BYTE *v10; // ecx
  _BYTE *v11; // ecx

  if ( a5 )
    _shift(&a2[*(_DWORD *)a1 == 45], a3 > 0);
  v6 = a2;
  if ( *(_DWORD *)a1 == 45 )
  {
    *a2 = 45;
    v6 = a2 + 1;
  }
  if ( a3 > 0 )
  {
    *v6 = v6[1];
    *++v6 = byte_9131A4;
  }
  v7 = strcpy(&v6[(a5 == 0) + a3], "e+000");
  if ( a4 )
    *v7 = 69;
  v8 = v7 + 1;
  if ( **(_BYTE **)(a1 + 12) != 48 )
  {
    v9 = *(_DWORD *)(a1 + 4) - 1;
    if ( v9 < 0 )
    {
      v9 = 1 - *(_DWORD *)(a1 + 4);
      *v8 = 45;
    }
    v10 = v8 + 1;
    if ( v9 >= 100 )
    {
      *v10 += v9 / 100;
      v9 %= 100;
    }
    v11 = v10 + 1;
    if ( v9 >= 10 )
    {
      *v11 += v9 / 10;
      LOBYTE(v9) = v9 % 10;
    }
    v11[1] += v9;
  }
  return a2;
}
