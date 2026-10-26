_DWORD *__thiscall sub_4E4A30(_DWORD *this, int a2)
{
  _DWORD *v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  const char *v8; // ebp
  int i; // edi
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  int v24; // [esp+10h] [ebp-4h]

  v3 = 0;
  v4 = sub_57AE50(aRaceorder);
  v5 = sub_57AE50(aSeasonraces);
  v6 = v5;
  v24 = 0;
  if ( v4 )
  {
    if ( !v5 )
      return v3;
    v7 = sub_57A700(a2);
    if ( v7 )
    {
      v8 = (const char *)sub_57A6C0(v7);
      if ( v8 )
      {
        for ( i = 0; i < sub_57A6E0(v6); ++i )
        {
          v10 = sub_57A700(i);
          if ( v10 )
          {
            v11 = (const char *)sub_57A6C0(v10);
            if ( !_strcmpi(v8, v11) )
              v24 = i;
          }
        }
      }
    }
  }
  if ( !v6 )
    return 0;
  v12 = sub_57A700(v24);
  if ( !v12 )
    return 0;
  v13 = sub_57A6C0(v12);
  sub_4E8C80(v13);
  v14 = dword_7D6B58 + 400 * dword_7D6B54;
  v3 = this + 7732;
  sub_578600(v14 + 260);
  sub_578600(v14 + 4);
  v15 = sub_57A720(aQualifylaps);
  if ( v15 )
  {
    v16 = (const char *)sub_57A6D0(v15);
    this[7736] = atol(v16);
  }
  else
  {
    this[7736] = -1;
  }
  v17 = sub_57A720(aQualifytime);
  if ( v17 )
  {
    v18 = (const char *)sub_57A6D0(v17);
    this[7737] = atol(v18);
  }
  else
  {
    this[7737] = -1;
  }
  v19 = sub_57A720(aRacelaps);
  if ( v19 )
  {
    v20 = (const char *)sub_57A6D0(v19);
    this[7738] = atol(v20);
  }
  else
  {
    this[7738] = -1;
  }
  v21 = sub_57A720(aRacetime);
  if ( v21 )
  {
    v22 = (const char *)sub_57A6D0(v21);
    this[7739] = atol(v22);
  }
  else
  {
    this[7739] = -1;
  }
  if ( v24 < this[7742] )
  {
    this[7740] = this[v24 + 7627];
    return v3;
  }
  this[7740] = -1;
  return this + 7732;
}
