int __thiscall sub_5A6F80(int *this, LPCWCH lpWideCharStr, int a3, _DWORD *a4, _DWORD *a5, int a6, _DWORD *a7)
{
  int v8; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // ebp
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  bool v22; // cc
  int v23; // eax
  int v25[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v26; // [esp+1Ch] [ebp-Ch]
  int v27; // [esp+24h] [ebp-4h]
  LPCWCH lpWideCharStra; // [esp+2Ch] [ebp+4h]

  if ( a3 <= 0 )
    v8 = sub_53D6AA(lpWideCharStr, (int)v25);
  else
    v8 = sub_53D49B((int)lpWideCharStr, a3, (int)v25);
  *this = v8;
  if ( v8 )
  {
    sub_591C60((int)this, -1, aCouldNotGetIma);
    return -1;
  }
  if ( v27 != 4 )
  {
    v15 = v26;
    goto LABEL_37;
  }
  v10 = *((_DWORD *)lpWideCharStr + 3);
  v11 = *((_DWORD *)lpWideCharStr + 4);
  v12 = *((int *)lpWideCharStr + 22) >> 3;
  v13 = 1;
  v14 = 128;
  if ( *((int *)lpWideCharStr + 7) > 0 )
    v13 = *((_DWORD *)lpWideCharStr + 7);
  lpWideCharStra = (LPCWCH)v13;
  do
  {
    v15 = v26;
    if ( v26 > 861165636 )
    {
      if ( v26 == 877942852 || v26 == 894720068 )
      {
LABEL_22:
        v19 = 1;
        if ( v11 >> 2 >= 1 )
          v19 = v11 >> 2;
        v20 = v10 >> 2;
        if ( v10 >> 2 < 1 )
          v20 = 1;
        v18 = 16 * v19 * v20;
      }
      else
      {
LABEL_21:
        v18 = v10 * v11 * v12;
      }
      v14 += v18;
      goto LABEL_28;
    }
    if ( v26 == 861165636 )
      goto LABEL_22;
    if ( v26 != 827611204 && v26 != 844388420 )
      goto LABEL_21;
    v16 = 1;
    if ( v11 >> 2 >= 1 )
      v16 = v11 >> 2;
    v17 = v10 >> 2;
    if ( v10 >> 2 < 1 )
      v17 = 1;
    v14 += 8 * v16 * v17;
LABEL_28:
    v21 = v11 >> 1;
    v22 = v11 >> 1 < 1;
    v11 = 1;
    if ( !v22 )
      v11 = v21;
    v23 = v10 >> 1;
    v22 = v10 >> 1 < 1;
    v10 = 1;
    if ( !v22 )
      v10 = v23;
    lpWideCharStra = (LPCWCH)((char *)lpWideCharStra - 1);
  }
  while ( lpWideCharStra );
  if ( v14 != a3 )
  {
    sub_591C60((int)this, -1, aDdsFileSizeErr);
    return -1;
  }
LABEL_37:
  if ( a4 )
    *a4 = v25[0];
  if ( a5 )
    *a5 = v25[1];
  if ( a6 )
    sub_5B41C0(v15, 0, a6);
  if ( a7 )
    *a7 = v25[3];
  return 0;
}
