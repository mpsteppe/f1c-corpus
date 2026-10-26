int __thiscall sub_42D370(char *this)
{
  const char *v3; // eax
  const char *v4; // eax
  char *v5; // eax
  int i; // eax
  char *v7; // eax
  int j; // eax
  _BYTE v9[256]; // [esp+4h] [ebp-100h] BYREF

  *(_DWORD *)this = 1;
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_11, 360) )
    sub_4D7AA0(&unk_8AD25C, aEnteredGameEnt);
  if ( sub_4A18D0(&unk_7CE2A4) )
    return 1;
  if ( sub_42D260(this) )
    return 1;
  if ( sub_4FA000(&unk_8AFE18) )
    return 1;
  sub_4CEE90(&unk_8ACEA0);
  sub_42C130();
  sub_4B1820(&unk_7CE498);
  v3 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v3 = &byte_5EA438;
  sub_58815F(v9, "%s%s", v3, (const char *)dword_7D0434);
  if ( !(unsigned __int8)sub_567F40(v9, 0) )
  {
    sub_566650(aF12002Gdb);
    v4 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v4 = &byte_5EA438;
    sub_58815F(v9, "%s%s", v4, (const char *)dword_7D0434);
    sub_567F40(v9, 0);
  }
  v5 = (char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v5 = &byte_5EA438;
  sub_565F80(aRcd, 1, (int)v5, 0);
  for ( i = sub_5662D0(&unk_8AD3B0); i; i = sub_5662D0(&unk_8AD3B0) )
  {
    sub_567F40(i, 0);
    sub_565F20(&unk_8AD3B0);
  }
  v7 = (char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v7 = &byte_5EA438;
  sub_565F80(aPit, 1, (int)v7, 0);
  for ( j = sub_5662D0(&unk_8AD3B0); j; j = sub_5662D0(&unk_8AD3B0) )
  {
    sub_567F40(j, 0);
    sub_565F20(&unk_8AD3B0);
  }
  if ( sub_4C8A20(&byte_8AC494) )
    return 1;
  if ( sub_455BF0(&ppvOut) )
    return 1;
  nullsub_3(&unk_7CE24D);
  nullsub_3(&dword_8AB6E4);
  sub_49EF40(&dword_7CE048);
  nullsub_3(&unk_8ACEE0);
  sub_463E20(&unk_7CD25C);
  return 0;
}
