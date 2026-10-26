int __thiscall sub_42F6C0(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebp
  bool v4; // bl
  int v5; // eax
  bool v6; // dl
  bool v7; // cl
  bool v8; // al
  int v9; // eax
  signed int k; // esi
  signed int v11; // esi
  int v12; // eax
  signed int m; // esi
  signed int v14; // esi
  int v15; // eax
  char v16; // bl
  signed int i; // esi
  int v18; // eax
  signed int j; // esi
  signed int v20; // esi
  int result; // eax
  char v22; // [esp+0h] [ebp-14h]

  v2 = this;
  if ( (unsigned __int8)sub_463490(&unk_764D70) )
  {
    v16 = sub_4634D0(&unk_764D70);
    if ( v16 )
    {
      if ( v2[2] == 5 )
      {
        for ( i = 0; i < (int)NumOfElements; ++i )
          sub_4DD140(dword_75AAD0[i] + 20836);
      }
    }
    v3 = a2;
    if ( a2 == 7 )
    {
      if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_2, 265) )
        sub_500FE0((int)&unk_7D7920, aMultiplayerMod, v22);
      if ( v16 )
        sub_464410(&unk_764D70);
      else
        sub_464830(&unk_764D70);
      v18 = NumOfElements;
      for ( j = 0; j < (int)NumOfElements; ++j )
      {
        sub_4DD150(dword_75AAD0[j] + 20836);
        v18 = NumOfElements;
      }
      v20 = 0;
      if ( v18 > 0 )
      {
        do
          sub_4EE300(dword_75AAD0[v20++]);
        while ( v20 < (int)NumOfElements );
      }
      sub_4BF870(0);
    }
  }
  else
  {
    v3 = a2;
    v4 = a2 == 2 || a2 == 3 || a2 == 4;
    v5 = v2[2];
    v6 = v5 == 4 && a2 == 5;
    v7 = v5 == 5 && a2 == 6;
    v8 = v5 == 6 && a2 == 7;
    if ( v4 || v6 )
    {
      sub_4E2FD0(&a2);
    }
    else if ( v7 )
    {
      v9 = NumOfElements;
      for ( k = 0; k < (int)NumOfElements; ++k )
      {
        sub_4DD140(dword_75AAD0[k] + 20836);
        v9 = NumOfElements;
      }
      v11 = 0;
      if ( v9 > 0 )
      {
        do
          sub_4EE300(dword_75AAD0[v11++]);
        while ( v11 < (int)NumOfElements );
      }
      sub_4BF870(0);
      if ( *(_DWORD *)dword_7689CC == 4 )
        sub_4E5D80(1);
    }
    else if ( v8 )
    {
      v12 = NumOfElements;
      for ( m = 0; m < (int)NumOfElements; ++m )
      {
        sub_4DD150(dword_75AAD0[m] + 20836);
        v12 = NumOfElements;
      }
      v14 = 0;
      if ( v12 > 0 )
      {
        do
        {
          v15 = dword_75AAD0[v14];
          *(_DWORD *)(v15 + 25264) = -1;
          *(_DWORD *)(v15 + 25268) = -1;
          sub_4EE300(dword_75AAD0[v14++]);
        }
        while ( v14 < (int)NumOfElements );
        v2 = this;
      }
    }
  }
  v2[2] = v3;
  result = dword_7685D8;
  dword_7685D0 = v3;
  if ( v3 >= dword_7685D8 )
  {
    if ( v3 > dword_7685DC )
      dword_7685D0 = dword_7685DC;
  }
  else
  {
    dword_7685D0 = dword_7685D8;
  }
  return result;
}
