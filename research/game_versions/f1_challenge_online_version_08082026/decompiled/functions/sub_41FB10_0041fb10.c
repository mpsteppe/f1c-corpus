bool __thiscall sub_41FB10(void *this)
{
  char v2; // bl
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  bool v11; // [esp+13h] [ebp-51h]
  _BYTE v12[80]; // [esp+14h] [ebp-50h] BYREF

  v2 = 0;
  v11 = 0;
  v3 = sub_4C2990(&unk_7D2DB0);
  v4 = sub_4C2850(&unk_7D2DB0);
  sub_4C1390(v4);
  sub_4C0A20(v12, 80);
  if ( sub_566810(v12, this) )
  {
    v5 = sub_4C2850(&unk_7D2DB0);
    if ( *(_DWORD *)(sub_4C1390(v5) + 4 * v3 + 212) == 10 )
    {
      v2 = 1;
    }
    else
    {
      v6 = sub_4C2850(&unk_7D2DB0);
      v11 = *(_DWORD *)(sub_4C1390(v6) + 4 * v3 + 212) == 6;
    }
  }
  v7 = 0;
  v8 = sub_4C2850(&unk_7D2DB0);
  if ( sub_4C1370(v8) > 0 )
  {
    do
    {
      sub_4C2850(&unk_7D2DB0);
      sub_4C13A0(v7);
      sub_4C0A20(v12, 80);
      if ( sub_566810(v12, this) )
      {
        sub_4C2850(&unk_7D2DB0);
        if ( *(_DWORD *)(sub_4C13A0(v7) + 4 * v3 + 212) == 10 )
          v2 = 1;
        sub_4C2850(&unk_7D2DB0);
        if ( *(_DWORD *)(sub_4C13A0(v7) + 4 * v3 + 212) == 6 )
          v11 = 1;
      }
      ++v7;
      v9 = sub_4C2850(&unk_7D2DB0);
    }
    while ( v7 < sub_4C1370(v9) );
  }
  return v2 && v11;
}
