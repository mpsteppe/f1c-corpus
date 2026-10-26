int __stdcall sub_679600(int *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  _WORD *v8; // edi
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int result; // eax
  int v18; // [esp+14h] [ebp+8h]
  int v19; // [esp+18h] [ebp+Ch]

  v5 = a1[5];
  if ( v5 != 100 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 20;
    *(_DWORD *)(v6 + 24) = v5;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  if ( a2 >= 4 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 31;
    *(_DWORD *)(v7 + 24) = a2;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  if ( !a1[a2 + 18] )
    a1[a2 + 18] = sub_6B5F50(a1);
  v19 = a1[a2 + 18];
  v8 = (_WORD *)(v19 + 4);
  v9 = (_DWORD *)(a3 + 8);
  v18 = 16;
  do
  {
    v10 = (a4 * *(v9 - 2) + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( a5 && v10 > 255 )
      LOWORD(v10) = 255;
    v11 = a4 * *(v9 - 1);
    *(v8 - 2) = v10;
    v12 = (v11 + 50) / 100;
    if ( v12 > 0 )
    {
      if ( v12 > 0x7FFF )
        v12 = 0x7FFF;
    }
    else
    {
      v12 = 1;
    }
    if ( a5 && v12 > 255 )
      LOWORD(v12) = 255;
    v13 = a4 * *v9;
    *(v8 - 1) = v12;
    v14 = (v13 + 50) / 100;
    if ( v14 > 0 )
    {
      if ( v14 > 0x7FFF )
        v14 = 0x7FFF;
    }
    else
    {
      v14 = 1;
    }
    if ( a5 && v14 > 255 )
      LOWORD(v14) = 255;
    v15 = a4 * v9[1];
    *v8 = v14;
    v16 = (v15 + 50) / 100;
    if ( v16 > 0 )
    {
      if ( v16 > 0x7FFF )
        v16 = 0x7FFF;
    }
    else
    {
      v16 = 1;
    }
    if ( a5 && v16 > 255 )
      LOWORD(v16) = 255;
    v8[1] = v16;
    v9 += 4;
    v8 += 4;
    --v18;
  }
  while ( v18 );
  result = v19;
  *(_DWORD *)(v19 + 128) = 0;
  return result;
}
