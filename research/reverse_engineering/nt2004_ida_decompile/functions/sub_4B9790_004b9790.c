int __thiscall sub_4B9790(void *this, char a2)
{
  int v3; // ecx
  char v4; // bl
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  bool v8; // cc
  _BYTE v10[432]; // [esp+Ch] [ebp-1B0h] BYREF

  v3 = dword_75CBA8;
  v4 = 0;
  if ( dword_75CBA8 == 5 )
  {
    dword_608F60 = 3;
    sub_42FA50(&dword_75CBA8, 0);
    v3 = dword_75CBA8;
  }
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 4:
      if ( v3 == 5 && dword_75CBB0 == 5 )
      {
        if ( sub_42DBA0() )
        {
          if ( *(int *)(dword_75AACC + 20848) > 0 )
          {
            v5 = sub_4E5DA0(&unk_76BB28);
            v6 = v5;
            if ( v5 )
            {
              sub_4E44C0(v5);
              sub_4E4ED0(v6);
            }
          }
        }
      }
      sub_4CDC80(0);
      break;
    case 5:
      if ( sub_463490(dword_764D70) )
        v4 = 1;
      sub_464C40(dword_764D70);
      sub_4CE820(&unk_7663E0);
      break;
    case 7:
      *(_DWORD *)dword_7689CC = 1;
      if ( dword_7689D4 <= 1 )
      {
        if ( dword_7689D8 < 1 )
          *(_DWORD *)dword_7689CC = dword_7689D8;
      }
      else
      {
        *(_DWORD *)dword_7689CC = dword_7689D4;
      }
      break;
    case 8:
      if ( v3 == 5 && dword_75CBB0 == 5 && sub_42DBA0() && *(int *)(dword_75AACC + 20848) > 0 )
      {
        sub_4E0EE0(v10);
        sub_4E1690(v10);
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 88))(dword_76BB24);
        nullsub_6(v10);
      }
      sub_4CDC80(0);
      break;
    default:
      break;
  }
  sub_419110(byte_6292D0);
  sub_4BA060(this);
  sub_42DD20();
  if ( sub_465840(dword_764D70) )
    sub_4BA6A0(&unk_76612C);
  if ( v4 )
  {
    if ( dword_7655CC )
    {
      if ( dword_75CBA8 == 5 )
        sub_4AD720((_DWORD *)dword_7655CC, aMplobby, a2);
      else
        sub_4AD720((_DWORD *)dword_7655CC, aMainMenu, a2);
    }
    v7 = dword_7689D8;
    *(_DWORD *)dword_7689CC = 5;
    if ( dword_7689D4 > 5 )
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
      goto LABEL_41;
    }
    v8 = dword_7689D8 < 5;
  }
  else
  {
    if ( dword_7655CC )
      sub_4AD720((_DWORD *)dword_7655CC, aMainMenu, a2);
    v7 = dword_7689D8;
    *(_DWORD *)dword_7689CC = 3;
    if ( dword_7689D4 > 3 )
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
      goto LABEL_41;
    }
    v8 = dword_7689D8 < 3;
  }
  if ( v8 )
    *(_DWORD *)dword_7689CC = v7;
LABEL_41:
  sub_4ED560(&dword_7D6B74);
  return 0;
}
