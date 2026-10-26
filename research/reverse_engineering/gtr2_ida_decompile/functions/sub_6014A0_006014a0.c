int __thiscall sub_6014A0(_DWORD *this, LPCWCH lpWideCharStr, int a3, _DWORD *a4, _DWORD *a5, int a6, _DWORD *a7)
{
  _DWORD *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // ebp
  int v13; // edx
  int v14; // esi
  int v15; // ecx
  int v16; // edi
  int v17; // ebx
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // eax
  bool v24; // cc
  int v25; // eax
  char v27; // [esp+0h] [ebp-38h]
  int v28; // [esp+Ch] [ebp-2Ch]
  int v29; // [esp+10h] [ebp-28h]
  int v30; // [esp+14h] [ebp-24h]
  int v32[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int v33; // [esp+2Ch] [ebp-Ch]
  int v34; // [esp+30h] [ebp-8h]
  int v35; // [esp+34h] [ebp-4h]
  int lpWideCharStra; // [esp+3Ch] [ebp+4h]

  v8 = this;
  if ( a3 <= 0 )
    v9 = sub_645876(lpWideCharStr, (int)v32);
  else
    v9 = sub_64479A(lpWideCharStr, a3, v32);
  v8[2] = v9;
  if ( v9 )
  {
    sub_5D8C80((int)(v8 + 1), (char *)0xFFFFFFFF, "Error reading image file info", v27);
    return -1;
  }
  if ( v35 != 4 )
    goto LABEL_40;
  v10 = *((_DWORD *)lpWideCharStr + 7);
  v11 = 1;
  lpWideCharStra = 1;
  v30 = *((int *)lpWideCharStr + 22) >> 3;
  v12 = 128;
  if ( v10 > 0 )
    lpWideCharStra = v10;
  if ( v34 == 5 )
    v11 = 6;
  v13 = *((_DWORD *)lpWideCharStr + 3);
  v14 = *((_DWORD *)lpWideCharStr + 4);
  v29 = v13;
  v28 = v11;
  do
  {
    v15 = lpWideCharStra;
    v16 = v29;
    v17 = v14;
    do
    {
      if ( v33 > 861165636 )
      {
        if ( v33 == 877942852 || v33 == 894720068 )
        {
LABEL_25:
          v21 = 1;
          if ( v17 >> 2 >= 1 )
            v21 = v17 >> 2;
          v22 = v16 >> 2;
          if ( v16 >> 2 < 1 )
            v22 = 1;
          v20 = 16 * v21 * v22;
        }
        else
        {
LABEL_24:
          v20 = v30 * v16 * v17;
        }
        v12 += v20;
        goto LABEL_31;
      }
      if ( v33 == 861165636 )
        goto LABEL_25;
      if ( v33 != 827611204 && v33 != 844388420 )
        goto LABEL_24;
      v18 = 1;
      if ( v17 >> 2 >= 1 )
        v18 = v17 >> 2;
      v19 = v16 >> 2;
      if ( v16 >> 2 < 1 )
        v19 = 1;
      v12 += 8 * v18 * v19;
LABEL_31:
      v23 = v17 >> 1;
      v24 = v17 >> 1 < 1;
      v17 = 1;
      if ( !v24 )
        v17 = v23;
      v25 = v16 >> 1;
      v24 = v16 >> 1 < 1;
      v16 = 1;
      if ( !v24 )
        v16 = v25;
      --v15;
    }
    while ( v15 );
    --v28;
  }
  while ( v28 );
  v8 = this;
  if ( v12 == a3 )
  {
LABEL_40:
    if ( a4 )
      *a4 = v32[0];
    if ( a5 )
      *a5 = v32[1];
    if ( a6 )
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, int))(*v8 + 172))(v8, v33, 0, a6);
    if ( a7 )
      *a7 = v32[3];
    return 0;
  }
  sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "DDS file size error for file", v27);
  return -1;
}
