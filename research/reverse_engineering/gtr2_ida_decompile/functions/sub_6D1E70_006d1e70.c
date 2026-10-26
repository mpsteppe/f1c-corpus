int __stdcall sub_6D1E70(int *a1)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // eax
  int result; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  int v8; // edi
  bool v9; // zf
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  bool v17; // cc
  int v18; // [esp-4h] [ebp-24h]
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  _DWORD *v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+1Ch] [ebp-4h]
  _DWORD *v24; // [esp+28h] [ebp+8h]

  v2 = (_DWORD *)(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 160);
  v3 = a1[76];
  v22 = v2;
  a1[114] = (int)v2;
  *v2 = sub_6D0FF0;
  v2[1] = sub_6D1020;
  v2[2] = 0;
  if ( v3 )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 25;
    (*(void (__stdcall **)(int *))v4)(a1);
  }
  if ( !a1[19] || (v23 = 1, a1[80] <= 1) )
    v23 = 0;
  result = a1[55];
  v21 = 0;
  if ( a1[9] > 0 )
  {
    v6 = (_DWORD *)(result + 36);
    v24 = v6;
    v7 = v2 + 13;
    while ( 1 )
    {
      v8 = a1[80];
      v20 = *v6 * *(v6 - 7) / v8;
      v9 = v24[3] == 0;
      v10 = a1[79];
      v11 = *v6 * *(v24 - 6) / v8;
      v12 = a1[78];
      v7[12] = v11;
      if ( v9 )
      {
        *v7 = sub_6D1130;
        goto LABEL_31;
      }
      if ( v20 == v12 && v11 == v10 )
      {
        *v7 = sub_6D1110;
        goto LABEL_31;
      }
      if ( 2 * v20 != v12 )
        break;
      if ( v11 == v10 )
      {
        if ( v23 && v24[1] > 2u )
          *v7 = sub_6D1D70;
        else
          *v7 = sub_6D1240;
      }
      else
      {
        if ( 2 * v20 != v12 || 2 * v11 != v10 )
          break;
        if ( v23 && v24[1] > 2u )
        {
          *v7 = sub_6D1DF0;
          v22[2] = 1;
        }
        else
        {
          *v7 = sub_6D12A0;
        }
      }
LABEL_30:
      v15 = a1[1];
      v18 = (2 * (v22[2] == 1) + 1) * a1[79];
      v16 = sub_6B5FD0(a1[28], a1[78]);
      *(v7 - 10) = (*(int (__stdcall **)(int *, int, int, int))(v15 + 8))(a1, 1, v16, v18);
LABEL_31:
      result = v21 + 1;
      ++v7;
      v17 = ++v21 < a1[9];
      v24 += 21;
      if ( !v17 )
        return result;
      v6 = v24;
    }
    v19 = v12 / v20;
    if ( v12 % v20 || (v13 = a1[79] / v11, a1[79] % v11) )
    {
      v14 = *a1;
      *(_DWORD *)(v14 + 20) = 38;
      (*(void (__stdcall **)(int *))v14)(a1);
    }
    else
    {
      *v7 = sub_6D1150;
      *((_BYTE *)v22 + v21 + 140) = v19;
      *((_BYTE *)v22 + v21 + 150) = v13;
    }
    goto LABEL_30;
  }
  return result;
}
