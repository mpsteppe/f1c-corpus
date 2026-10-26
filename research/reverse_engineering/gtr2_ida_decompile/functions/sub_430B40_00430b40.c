int __usercall sub_430B40@<eax>(_DWORD *a1@<ecx>, float a2@<edi>)
{
  int v2; // eax
  char v3; // bl
  char v4; // si

  *a1 = 5;
  while ( 1 )
  {
    sub_58F290(&unk_FB1E98);
    if ( (unsigned __int8)sub_473630(&dword_B6CBA8) )
    {
      v3 = 1;
      goto LABEL_4;
    }
    v2 = sub_4EBA60(&unk_B6F134);
    v3 = byte_B6F118;
    v4 = v2;
    if ( v2 != 5 )
      break;
LABEL_4:
    sub_527C40(&dword_BE1204);
    sub_527D10(&unk_BE1210);
    sub_47E050(&dword_B6CBA8);
    sub_5294E0(&dword_BE1204);
    sub_51C050(&dword_75B490);
    sub_403740((int)&flt_91BCA0);
    sub_556F90(&unk_FADD40);
    sub_463A40(&dword_B69668);
    sub_42EF60((int)&unk_920488);
    sub_51C0B0(&dword_82F4A0);
    sub_47E080(&dword_B6CBA8);
    sub_47BE00(&dword_B6CBA8);
    sub_529BA0(&dword_BE1204);
    sub_52A5E0(&unk_BE1210);
    sub_51C050(&dword_82F4A0);
    sub_54BBB0(&unk_BE27B0);
    sub_408730(dword_91BE2C, dbl_FB1D10);
    if ( !byte_FADD28 )
    {
      if ( v3 )
      {
        if ( !(unsigned __int8)sub_473630(&dword_B6CBA8) || (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
          sub_414DD0((int)&dword_91BF20);
      }
      else
      {
        sub_414DD0((int)&dword_91BF20);
        sub_51E980(&dword_BE10B0);
        sub_54AB10(&unk_BE2728);
        sub_5206C0(&unk_BE1198);
        sub_4E8030(&dword_B6E4D0);
      }
    }
    sub_540C90(&unk_BE1D30);
    sub_5900D0(&unk_FB1E98);
    if ( byte_B72DB4 )
      sub_53DCD0(&unk_BE1D00);
    sub_594840(&dword_FB1EF8);
    sub_4ED0E0();
    sub_42C070((int)&unk_91DC48, v3, a2);
    if ( (unsigned __int8)sub_473630(&dword_B6CBA8) )
      return 0;
  }
  if ( v2 == 4 )
    return 0;
  if ( v2 != 6
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\game.cpp", 1113) )
  {
    sub_561210((int)byte_FAE910, "Next state %d was not expected", v4);
  }
  return 1;
}
