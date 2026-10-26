int __stdcall sub_6D7FE0(int *a1)
{
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // edi
  int v7; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  bool v11; // cc
  int result; // eax
  int v13; // eax
  int v14; // [esp+Ch] [ebp-Ch]
  _DWORD *v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]
  _DWORD *v17; // [esp+20h] [ebp+8h]

  v16 = 1;
  v2 = (_DWORD *)(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 52);
  v3 = a1[47];
  v15 = v2;
  a1[91] = (int)v2;
  *v2 = pfnAPC;
  v2[1] = sub_6D7640;
  v2[2] = 0;
  if ( v3 )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 25;
    (*(void (__stdcall **)(int *))v4)(a1);
  }
  v14 = 0;
  if ( a1[15] > 0 )
  {
    v5 = (_DWORD *)(a1[17] + 12);
    v17 = v5;
    v6 = v2 + 3;
    do
    {
      v7 = *(v5 - 1);
      v8 = a1[60];
      if ( v7 == v8 && *v5 == a1[61] )
      {
        if ( a1[48] )
        {
          *v6 = sub_6D7DA0;
          v15[2] = 1;
        }
        else
        {
          *v6 = sub_6D7800;
        }
      }
      else
      {
        if ( 2 * v7 != v8 )
          goto LABEL_18;
        v9 = *v5 == a1[61];
        v5 = v17;
        if ( v9 )
        {
          v16 = 0;
          *v6 = sub_6D7F20;
        }
        else
        {
          if ( 2 * v7 != v8 || 2 * *v17 != a1[61] )
          {
LABEL_18:
            if ( v8 % v7 || a1[61] % *v5 )
            {
              v10 = *a1;
              *(_DWORD *)(v10 + 20) = 38;
              (*(void (__stdcall **)(int *))v10)(a1);
            }
            else
            {
              v16 = 0;
              *v6 = sub_6D76E0;
            }
            goto LABEL_22;
          }
          if ( a1[48] )
          {
            *v6 = sub_6D7B30;
            v15[2] = 1;
          }
          else
          {
            *v6 = sub_6D7F80;
          }
        }
      }
LABEL_22:
      v5 += 21;
      ++v6;
      v11 = ++v14 < a1[15];
      v17 = v5;
    }
    while ( v11 );
  }
  result = a1[48];
  if ( result )
  {
    result = v16;
    if ( !v16 )
    {
      v13 = *a1;
      *(_DWORD *)(v13 + 20) = 99;
      return (*(int (__stdcall **)(int *, _DWORD))(v13 + 4))(a1, 0);
    }
  }
  return result;
}
