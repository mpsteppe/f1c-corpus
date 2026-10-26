int sub_4B9210()
{
  int v0; // edi
  const char *v2; // eax
  char Buffer[432]; // [esp+4h] [ebp-1B0h] BYREF

  v0 = 0;
  sub_451B70();
  if ( dword_7655CC )
    sub_4AC980((_DWORD *)dword_7655CC);
  if ( *(_DWORD *)dword_7689CC == 3 )
    goto LABEL_6;
  if ( *(_DWORD *)dword_7689CC != 4 )
  {
    if ( *(_DWORD *)dword_7689CC != 8 )
      goto LABEL_9;
LABEL_6:
    if ( dword_75CBB0 == 5 && sub_42DBA0() )
      goto LABEL_8;
    goto LABEL_9;
  }
  if ( dword_75CBB0 == 7 )
  {
    if ( dword_7688E8 == 1 )
    {
      v2 = (const char *)dword_62A0A8;
      if ( !dword_62A0A8 )
        v2 = &byte_629120;
      sprintf(Buffer, "%s%s", v2, aSeasonBik);
      v0 = sub_527460(Buffer, 1);
    }
  }
  else if ( dword_75CBB0 == 5 )
  {
LABEL_8:
    sub_4E0EE0(Buffer);
    sub_4E1690(Buffer);
    nullsub_6(Buffer);
  }
LABEL_9:
  sub_465D00(dword_764D70);
  if ( sub_42DBC0() )
  {
    sub_4EEC20(1);
    sub_4EEC50(1);
    sub_4EECE0(1);
  }
  sub_4BA5F0(0);
  sub_42FA50(&dword_75CBA8, 0);
  sub_527950(0);
  if ( dword_7655CC )
    sub_4AD7C0((_DWORD *)dword_7655CC);
  sub_4582E0(&ppvOut);
  sub_455BD0(&ppvOut);
  sub_42DB40(dword_75AAC8);
  sub_40C3F0((_DWORD **)&dword_6291CC);
  sub_5074D0(0.0);
  sub_4AB3C0();
  nullsub_6(&unk_765B00);
  sub_45D290(&byte_764D68);
  sub_4DA2E0(&dword_7D5DA4);
  if ( sub_42DBC0() && *(_DWORD *)dword_7689CC != 7 )
  {
    sub_51F3D0(0, 8);
    sub_436D40((char **)&dword_75E8F0, v0);
    sub_4EE160(0.0);
    if ( dword_75CBB0 != 7 || dword_75CBB4 != 2 && dword_75CBB4 != 3 && dword_75CBB4 != 4 )
      sub_51C0E0(0);
    sub_50FD00(dword_75AACC + 84);
    sub_51F3D0(1, 4);
  }
  sub_4FD8A0(&dword_7D78FC);
  sub_4ED570(&dword_7D6B74);
  return v0;
}
