// f1_2002_full  0x004315e0  size=603
int __thiscall sub_4315E0(_DWORD *this, int a2)
{
  char v3; // al
  int v4; // edi
  bool v5; // bl
  int v6; // eax
  bool v7; // dl
  bool v8; // cl
  bool v9; // al
  signed int k; // esi
  signed int m; // esi
  const char *v12; // eax
  signed int i; // esi
  signed int j; // esi
  int result; // eax

  v3 = sub_45CD40(&unk_636C78);
  v4 = a2;
  if ( v3 )
  {
    if ( a2 < 6 || a2 > 7 )
    {
      sub_4B7530(&a2);
      if ( dword_63136C != 5 && sub_4CA4A0(dword_6BD838, 2, aDDevCommonSour_1, 181) )
        sub_4CA4F0((int)dword_6BD838, aMultiplayerMod_0);
    }
    else
    {
      if ( dword_63136C != 5 && sub_4CA4A0(dword_6BD838, 2, aDDevCommonSour_1, 189) )
      {
        v12 = aWarmup;
        if ( v4 != 6 )
          v12 = aRace_0;
        sub_4CA4F0((int)dword_6BD838, "Multiplayer mode: setting vehicle places for %s", v12);
      }
      if ( (unsigned __int8)sub_45CD50(&unk_636C78) )
      {
        if ( this[2] == 5 )
        {
          for ( i = 0; i < (int)ArgList; ++i )
            sub_4B1F10(dword_631270[i] + 4804);
        }
        for ( j = 0; j < (int)ArgList; ++j )
          sub_4B1F20(dword_631270[j] + 4804);
      }
      else
      {
        sub_45D8A0(&unk_636C78);
      }
    }
  }
  else
  {
    v5 = a2 == 2 || a2 == 3 || a2 == 4;
    v6 = this[2];
    v7 = v6 == 4 && a2 == 5;
    v8 = v6 == 5 && a2 == 6;
    v9 = v6 == 6 && a2 == 7;
    if ( v5 || v7 )
    {
      sub_4B7530(&a2);
    }
    else if ( v8 )
    {
      if ( byte_638148 || dword_6392F4 == 4 )
      {
        for ( k = 0; k < (int)ArgList; ++k )
          sub_4B1F10(dword_631270[k] + 4804);
        if ( dword_6392F4 == 4 )
          sub_4B97A0(1);
      }
    }
    else if ( v9 )
    {
      for ( m = 0; m < (int)ArgList; ++m )
        sub_4B1F20(dword_631270[m] + 4804);
    }
  }
  this[2] = v4;
  result = dword_6390C8;
  dword_6390C0 = v4;
  if ( v4 >= dword_6390C8 )
  {
    if ( v4 > dword_6390CC )
      dword_6390C0 = dword_6390CC;
  }
  else
  {
    dword_6390C0 = dword_6390C8;
  }
  return result;
}
