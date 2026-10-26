// positive sp value has been detected, the output may be wrong!
int __fastcall sub_4BF737(int a1, char a2)
{
  int v5; // eax

  dword_75B17C = 5;
  if ( dword_B6E090 )
  {
    if ( !a1 )
    {
      dword_75B178 = 2;
      sub_45DDE0();
      if ( dword_B640C0 == 5 )
        ((void (__thiscall *)(void *))sub_4EB6B0)(&unk_B6F135);
      else
        sub_4EB100(&unk_B6F135);
LABEL_14:
      if ( dword_B640C0 == 5 && dword_BE1204 == 2 )
        sub_461600((char *)&dword_B69668);
      else
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_B6E090 + 36))(dword_B6E090);
      sub_4DE260(1);
    }
  }
  else
  {
    if ( (unsigned __int8)sub_473A90() )
    {
      dword_75B17C = -1;
      return -1;
    }
    if ( operator new(0x13DCu) )
      v5 = sub_4BEA50();
    else
      v5 = 0;
    dword_B6E090 = v5;
    sub_4DD750(v5, 0, 0, 1);
    ((void (__thiscall *)(int))sub_4DE100)(dword_B6E090);
    sub_519B50(&byte_B6F530);
    ((void (__thiscall *)(int))sub_4DFE10)(dword_B6E090);
    dword_75B174 = dword_B70948;
    sub_5407F0(&unk_BE1D30);
    sub_4EA860(&unk_B6F135);
    sub_45DDE0();
    sub_4787F0(&dword_B6CBA8);
    sub_479630(&dword_B6CBA8);
    if ( dword_75B17C == -1 )
      return -1;
    if ( !a1 )
      goto LABEL_14;
  }
  if ( byte_B763D4 )
  {
    byte_B763D4 = 0;
    sub_4E1810("POPUP_ADDPROFILE_FORCED", 0);
    sub_4DF410("ADD PROFILE FORCED");
  }
  ((void (__thiscall *)(int))sub_4E1050)(dword_B6E090);
  if ( dword_75B17C == 5 )
  {
    sub_4E1520(1);
    if ( dword_75B17C == 5 )
      dword_75B17C = 0;
  }
  sub_540850(-1.0);
  if ( a2 )
    dword_75B17C = -1;
  switch ( dword_75B17C )
  {
    case -1:
      ((void (__thiscall *)(int))sub_4E2220)(dword_B6E090);
      if ( dword_B6E090 )
        (**(void (__thiscall ***)(int, int))dword_B6E090)(dword_B6E090, 1);
      dword_B6E090 = 0;
      sub_510770(&byte_B6F530, 1);
      break;
    case 1:
      sub_4DED90();
      sub_45DE00();
      sub_4BE980();
      sub_4BF3A0();
      sub_4EA9D0(&unk_B6F135);
      break;
    case 2:
      ((void (__thiscall *)(void *))sub_4EAB20)(&unk_B6F135);
      break;
  }
  return dword_75B17C;
}
