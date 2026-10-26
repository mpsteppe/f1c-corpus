int __cdecl sub_51C3E2(int a1)
{
  int result; // eax
  int v3; // ebx
  _DWORD *v4; // ecx
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // [esp-4h] [ebp-28h]
  _DWORD *v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]
  bool v18; // [esp+2Fh] [ebp+Bh]

  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 160);
  v3 = result;
  *(_DWORD *)(a1 + 412) = result;
  *(_BYTE *)(result + 8) = 0;
  *(_DWORD *)result = sub_51BFA6;
  *(_DWORD *)(result + 4) = sub_51BFC0;
  v14 = result;
  if ( *(_BYTE *)(a1 + 264) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 23;
    result = (**(int (__cdecl ***)(int))a1)(a1);
  }
  v18 = *(_BYTE *)(a1 + 72) && *(int *)(a1 + 276) > 1;
  v16 = 0;
  if ( *(int *)(a1 + 32) > 0 )
  {
    v4 = (_DWORD *)(v3 + 52);
    v5 = *(_DWORD *)(a1 + 196) + 36;
    v13 = (_DWORD *)(v3 + 52);
    do
    {
      v6 = *(_DWORD *)(a1 + 276);
      v15 = *(_DWORD *)v5 * *(_DWORD *)(v5 - 28) / v6;
      v7 = *(_DWORD *)v5 * *(_DWORD *)(v5 - 24) / v6;
      v8 = *(_DWORD *)(a1 + 268);
      v17 = *(_DWORD *)(a1 + 272);
      v4[12] = v7;
      if ( *(_BYTE *)(v5 + 12) )
      {
        if ( v15 != v8 || v7 != v17 )
        {
          if ( 2 * v15 == v8 )
          {
            if ( v7 == v17 )
            {
              if ( v18 && *(_DWORD *)(v5 + 4) > 2u )
                *v4 = sub_51C237;
              else
                *v4 = sub_51C176;
LABEL_30:
              v12 = *(_DWORD *)(a1 + 272);
              v9 = *(_DWORD *)(a1 + 4);
              v10 = sub_515927(*(_DWORD *)(a1 + 92), *(_DWORD *)(a1 + 268));
              v11 = (*(int (__cdecl **)(int, int, int, int))(v9 + 8))(a1, 1, v10, v12);
              v4 = v13;
              *(v13 - 10) = v11;
              goto LABEL_31;
            }
            if ( 2 * v15 == v8 && 2 * v7 == v17 )
            {
              if ( v18 && *(_DWORD *)(v5 + 4) > 2u )
              {
                *v4 = sub_51C2DB;
                *(_BYTE *)(v14 + 8) = 1;
              }
              else
              {
                *v4 = sub_51C1CD;
              }
              goto LABEL_30;
            }
          }
          if ( v8 % v15 || v17 % v7 )
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 37;
            (**(void (__cdecl ***)(int))a1)(a1);
          }
          else
          {
            *v4 = sub_51C099;
            *(_BYTE *)(v16 + v14 + 140) = v8 / v15;
            *(_BYTE *)(v16 + v14 + 150) = v17 / v7;
          }
          goto LABEL_30;
        }
        *v4 = sub_51C086;
      }
      else
      {
        *v4 = sub_51C091;
      }
LABEL_31:
      result = ++v16;
      ++v4;
      v5 += 84;
      v13 = v4;
    }
    while ( v16 < *(_DWORD *)(a1 + 32) );
  }
  return result;
}
