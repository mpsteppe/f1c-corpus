char __cdecl sub_51B37D(_DWORD *a1, int a2)
{
  _DWORD *v3; // esi
  bool v4; // zf
  bool v5; // cc
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  _WORD *v9; // ebx
  unsigned __int8 *v11; // [esp+Ch] [ebp-2Ch] BYREF
  int v12; // [esp+10h] [ebp-28h]
  int v13; // [esp+14h] [ebp-24h]
  int v14; // [esp+18h] [ebp-20h]
  int v15; // [esp+24h] [ebp-14h]
  _DWORD *v16; // [esp+28h] [ebp-10h]
  _DWORD *v17; // [esp+2Ch] [ebp-Ch]
  int v18; // [esp+34h] [ebp-4h]
  int v19; // [esp+40h] [ebp+8h]

  v3 = (_DWORD *)a1[101];
  v4 = a1[63] == 0;
  v18 = 1 << a1[93];
  if ( !v4 && !v3[13] && !CounterUpdateWithZero(a1) )
    return 0;
  v5 = a1[79] <= 0;
  v6 = a1[5];
  v16 = a1;
  v11 = *(unsigned __int8 **)v6;
  v12 = *(_DWORD *)(v6 + 4);
  v13 = a1[94];
  v7 = v3[4];
  v8 = v3[5];
  v17 = v3 + 6;
  v19 = 0;
  if ( !v5 )
  {
    do
    {
      v9 = *(_WORD **)(a2 + 4 * v19);
      if ( v8 < 1 )
      {
        if ( !sub_51A794(&v11, v7, v8, 1) )
          return 0;
        v7 = v14;
        v8 = v15;
      }
      if ( ((v7 >> --v8) & 1) != 0 )
        *v9 |= v18;
      ++v19;
    }
    while ( v19 < a1[79] );
  }
  *(_DWORD *)a1[5] = v11;
  *(_DWORD *)(a1[5] + 4) = v12;
  a1[94] = v13;
  --v3[13];
  v3[4] = v7;
  v3[5] = v8;
  return 1;
}
