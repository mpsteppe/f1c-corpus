int __cdecl sub_51A4F2(int a1, char a2)
{
  _DWORD *v3; // ebx
  int v4; // eax
  int *v5; // edi
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int *v10; // ecx
  int result; // eax
  int *v12; // ecx
  int v13; // edx
  int v14; // [esp-8h] [ebp-18h]
  int v15; // [esp-4h] [ebp-14h]
  _DWORD *v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+18h] [ebp+8h]
  int *v18; // [esp+1Ch] [ebp+Ch]

  v3 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 116);
  *(_DWORD *)(a1 + 388) = v3;
  v16 = v3;
  *v3 = sub_5199C5;
  v3[2] = sub_51A4B7;
  v3[28] = 0;
  if ( a2 )
  {
    v4 = *(_DWORD *)(a1 + 196);
    v17 = 0;
    if ( *(int *)(a1 + 32) > 0 )
    {
      v5 = (int *)(v4 + 12);
      v18 = v3 + 18;
      do
      {
        v6 = *v5;
        if ( *(_BYTE *)(a1 + 200) )
          v6 *= 3;
        v7 = *(_DWORD *)(a1 + 4);
        v15 = v6;
        v14 = sub_515927(v5[5], *v5);
        v8 = sub_515927(v5[4], *(v5 - 1));
        v9 = (*(int (__cdecl **)(int, int, int, int, int, int))(v7 + 20))(a1, 1, 1, v8, v14, v15);
        v10 = v18++;
        ++v17;
        *v10 = v9;
        v5 += 21;
      }
      while ( v17 < *(_DWORD *)(a1 + 32) );
      v3 = v16;
    }
    result = (int)(v3 + 18);
    v3[1] = sub_519BB2;
    v3[3] = sub_519D51;
    v3[4] = v3 + 18;
  }
  else
  {
    result = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, 1280);
    v12 = v3 + 8;
    v13 = 10;
    do
    {
      *v12++ = result;
      result += 128;
      --v13;
    }
    while ( v13 );
    v3[1] = sub_519BAF;
    v3[3] = sub_5199D5;
    v3[4] = 0;
  }
  return result;
}
