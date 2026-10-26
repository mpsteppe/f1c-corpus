int *__thiscall sub_40E5E0(_DWORD *this)
{
  _DWORD *v1; // ebp
  __int16 v2; // di
  int v3; // eax
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // eax
  _DWORD *v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  int *result; // eax
  int i; // esi
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v21; // [esp+14h] [ebp-18h]
  int v22; // [esp+18h] [ebp-14h]
  int v23; // [esp+1Ch] [ebp-10h]
  int v24; // [esp+20h] [ebp-Ch]
  int v25; // [esp+24h] [ebp-8h]
  float v26; // [esp+28h] [ebp-4h]

  v1 = 0;
  v2 = -1;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v26 = 100000.0;
  v25 = 0;
  if ( (int)NumOfElements > 0 )
  {
    v3 = 0;
    do
    {
      v4 = dword_75AAD0[v3];
      if ( *(_DWORD *)(v4 + 20876) == 1 )
        v21 = dword_75AAD0[v3];
      if ( *(_DWORD *)(v4 + 20884) == 1 )
        v22 = dword_75AAD0[v3];
      if ( (unsigned __int8)sub_4DEB90(v4 + 20836) )
        v23 = v4;
      if ( *(float *)(v4 + 20960) > 0.0 && *(float *)(v4 + 20960) < (double)v26 )
      {
        v24 = v4;
        v26 = *(float *)(v4 + 20960);
      }
      if ( (__int16)(*(_WORD *)(v4 + 20876) - *(_WORD *)(v4 + 20884)) > v2 )
      {
        v25 = v4;
        v2 = *(_WORD *)(v4 + 20876) - *(_WORD *)(v4 + 20884);
      }
      v1 = (_DWORD *)((char *)v1 + 1);
      v3 = (unsigned __int16)v1;
    }
    while ( (unsigned __int16)v1 < (int)NumOfElements );
    v1 = 0;
  }
  v5 = operator new(0x50u);
  if ( v5 )
  {
    *v5 = 0;
    v5[1] = -1;
    v5[2] = 0;
    v5[3] = -1;
    v5[4] = 0;
    v5[5] = 0;
    v5[6] = -1;
    v5[7] = 0;
    v5[8] = 0;
    v5[9] = -1;
    v5[10] = 0;
    v5[11] = 0;
    v5[12] = -1;
    v5[13] = 0;
    v5[14] = 0;
    v5[15] = -1;
    v5[16] = 0;
    v5[17] = 0;
    v5[18] = -1;
    v5[19] = 0;
    v1 = v5;
  }
  v6 = *this;
  v7 = (*(int (__thiscall **)(_DWORD *))(*this + 36))(this);
  v8 = this;
  v9 = (*(int (__thiscall **)(_DWORD *, int))(v6 + 56))(this, v7);
  sub_578600(v9);
  if ( v21 )
  {
    sub_578600(v21 + 24772);
    sub_578600(v21 + 24772);
    v8 = this;
    v1[4] = sub_40E9D0(aPolepositionbo);
  }
  if ( v22 )
  {
    sub_578600(v22 + 24772);
    v1[7] = sub_40E9D0(aRacewinnerbonu);
  }
  if ( v23 )
  {
    sub_578600(v23 + 24772);
    v1[10] = sub_40E9D0(aMostlapsledbon);
  }
  if ( v24 )
  {
    sub_578600(v24 + 24772);
    v1[13] = sub_40E9D0(aBestlapbonus);
  }
  if ( v25 )
  {
    sub_578600(v25 + 24772);
    v1[19] = sub_40E9D0(aMostimprovemen_0);
  }
  if ( v1 )
  {
    v10 = operator new(0xCu);
    if ( v10 )
    {
      *v10 = v1;
      v10[1] = 0;
      *((_BYTE *)v10 + 8) = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( v8[5] )
    {
      *(_DWORD *)(v8[6] + 4) = v10;
    }
    else
    {
      v8[5] = v10;
      v8[7] = v10;
    }
    v8[6] = v10;
    ++v8[8];
  }
  result = (int *)v8[1];
  v8[3] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( v21 && *(_DWORD *)(i + 28) )
      {
        v13 = *(const char **)i;
        if ( !*(_DWORD *)i )
          v13 = &byte_629120;
        if ( !_strcmpi(v13, (const char *)(v21 + 24992)) )
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(i + 28) + 16))(*(_DWORD *)(i + 28), v1[4]);
      }
      if ( v22 && *(_DWORD *)(i + 28) )
      {
        v14 = *(const char **)i;
        if ( !*(_DWORD *)i )
          v14 = &byte_629120;
        if ( !_strcmpi(v14, (const char *)(v22 + 24992)) )
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(i + 28) + 20))(*(_DWORD *)(i + 28), 0);
      }
      if ( v23 )
      {
        if ( *(_DWORD *)(i + 28) )
        {
          v15 = *(const char **)i;
          if ( !*(_DWORD *)i )
            v15 = &byte_629120;
          if ( !_strcmpi(v15, (const char *)(v23 + 24992)) )
            (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(i + 28) + 24))(*(_DWORD *)(i + 28), v1[10]);
        }
        v16 = *(const char **)i;
        if ( !*(_DWORD *)i )
          v16 = &byte_629120;
        if ( !_strcmpi(v16, (const char *)(v23 + 24992)) && sub_40EFA0(i) )
        {
          v17 = sub_40EFA0(i);
          *(_DWORD *)(v17 + 12) += 5;
        }
      }
      if ( v24 && *(_DWORD *)(i + 28) )
      {
        v18 = *(const char **)i;
        if ( !*(_DWORD *)i )
          v18 = &byte_629120;
        if ( !_strcmpi(v18, (const char *)(v24 + 24992)) )
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(i + 28) + 28))(*(_DWORD *)(i + 28), v1[13]);
      }
      if ( v25 && *(_DWORD *)(i + 28) )
      {
        v19 = *(const char **)i;
        if ( !*(_DWORD *)i )
          v19 = &byte_629120;
        if ( !_strcmpi(v19, (const char *)(v25 + 24992)) )
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(i + 28) + 36))(*(_DWORD *)(i + 28), v1[19]);
      }
      result = (int *)v8[3];
      if ( !result )
        break;
      result = (int *)result[1];
      v8[3] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
