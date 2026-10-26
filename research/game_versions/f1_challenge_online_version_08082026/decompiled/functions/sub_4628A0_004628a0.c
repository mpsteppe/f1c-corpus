char sub_4628A0()
{
  float v1; // [esp+0h] [ebp-238h]
  _BYTE v2[128]; // [esp+8h] [ebp-230h] BYREF
  _DWORD v3[108]; // [esp+88h] [ebp-1B0h] BYREF

  sub_461550(v2);
  if ( !(unsigned __int8)sub_4630D0(v2) )
    return 0;
  sub_463760(0);
  sub_461610((int)v2);
  sub_462760(dword_7CD25C, (int)v2);
  v1 = dbl_8AFEA0;
  sub_4B33B0(4, 5, 0, 0, LODWORD(v1), 1);
  sub_462250(dword_7CD25C, v3, 2, -1, -1);
  sub_4A0DC0(&unk_7CE24D);
  return 1;
}
