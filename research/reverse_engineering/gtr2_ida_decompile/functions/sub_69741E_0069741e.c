_DWORD *__thiscall sub_69741E(_DWORD *this, int a2, int a3, double a4, const void *a5)
{
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  int v15; // [esp+1Ch] [ebp-4h]

  v15 = 2;
  if ( a2 )
  {
    if ( a2 > 0 )
    {
      if ( a2 <= 4 )
      {
        v15 = 1;
      }
      else if ( a2 <= 8 )
      {
        v15 = 2;
      }
      else if ( a2 <= 12 )
      {
        v15 = 3;
      }
    }
  }
  else
  {
    v15 = 0;
  }
  v5 = (_DWORD *)sub_65B229(80);
  if ( v5 )
    v6 = sub_67F5FE(v5, 0, 0, 0, 0, 1, a5);
  else
    v6 = 0;
  if ( !v6 )
    return 0;
  v7 = (_DWORD *)sub_65B229(36);
  v8 = v7 ? sub_67F2D4(v7, 0, a2, 1, 1, 512) : 0;
  v6[4] = v8;
  if ( !v8 )
    return 0;
  v9 = (_DWORD *)sub_65B229(64);
  if ( v15 != 3 )
  {
    if ( v9 )
    {
      v10 = sub_67F780(v9, v15, a3, a5);
      goto LABEL_24;
    }
LABEL_23:
    v10 = 0;
    goto LABEL_24;
  }
  if ( !v9 )
    goto LABEL_23;
  v10 = (_DWORD *)sub_67F74B(v9, 3, a4, a5);
LABEL_24:
  v6[8] = v10;
  if ( !v10 )
    return 0;
  v11 = (_DWORD *)sub_65B229(20);
  v12 = v11 ? sub_67ED1B(v11, v6[8], 0, (int)"Value") : 0;
  if ( !v12 )
    return 0;
  v6[8] = v12;
  sub_695BDE(this, v6);
  return v6;
}
