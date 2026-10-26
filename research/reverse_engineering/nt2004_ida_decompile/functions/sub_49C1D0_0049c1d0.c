int __fastcall sub_49C1D0(int a1, char a2)
{
  int result; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  dword_608F60 = 5;
  if ( dword_7655CC )
  {
    if ( a1 )
      goto LABEL_25;
    dword_608F5C = 2;
    sub_451B50();
    if ( dword_75CBA8 == 5 )
      sub_4B9FF0(&byte_766124);
    else
      sub_4B96C0(&byte_766124);
    goto LABEL_20;
  }
  if ( sub_465860(dword_764D70) )
  {
    result = -1;
    dword_608F60 = -1;
    return result;
  }
  v5 = operator new(0x630u);
  if ( v5 )
    v6 = sub_493600(v5);
  else
    v6 = 0;
  dword_7655CC = (int)v6;
  sub_4AAB60(v6, 0, 0, 1);
  sub_4AC680(dword_7655CC);
  sub_4CD8D0(&unk_7663E0);
  if ( byte_76BB80 )
  {
    byte_76BB80 = 0;
    sub_4AD720(a2003PlayersGen, 0);
    sub_4AD720(aProfileAdd, 0);
  }
  *(_DWORD *)dword_7689CC = 3;
  if ( dword_7689D4 <= 3 )
  {
    if ( dword_7689D8 < 3 )
      *(_DWORD *)dword_7689CC = dword_7689D8;
  }
  else
  {
    *(_DWORD *)dword_7689CC = dword_7689D4;
  }
  sub_4ACAE0(dword_7655CC);
  dword_608F58 = dword_76782C;
  sub_4EF930(0);
  sub_47DE30(&byte_766124);
  sub_451B50();
  sub_465370(dword_764D70);
  sub_465790(dword_764D70);
  if ( dword_608F60 == -1 )
    return -1;
  if ( !a1 )
  {
LABEL_20:
    if ( dword_75CBA8 == 5 && dword_7D5DA4 == 2 )
      sub_455BD0(&ppvOut);
    else
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_7655CC + 36))(dword_7655CC);
    sub_4AD1C0(1);
  }
LABEL_25:
  sub_4ACB80(dword_7655CC);
  if ( dword_608F60 == 5 )
  {
    sub_4AD050(1);
    if ( dword_608F60 == 5 )
      dword_608F60 = 0;
  }
  sub_4EFA90(-1.0);
  if ( a2 )
    dword_608F60 = -1;
  switch ( dword_608F60 )
  {
    case -1:
      sub_4AC690(dword_7655CC);
      if ( dword_7655CC )
        (**(void (__thiscall ***)(int, int))dword_7655CC)(dword_7655CC, 1);
      dword_7655CC = 0;
      sub_4CDC80(1);
      break;
    case 1:
      sub_451B70();
      sub_4934C0();
      sub_493590();
      sub_4B9130(1);
      return dword_608F60;
    case 2:
      sub_4B9210(&byte_766124);
      return dword_608F60;
  }
  return dword_608F60;
}
