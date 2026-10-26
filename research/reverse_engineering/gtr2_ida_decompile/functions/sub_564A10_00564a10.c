int __usercall sub_564A10@<eax>(int a1@<edi>)
{
  double v1; // st7
  char *v2; // eax
  char *v3; // eax
  int v4; // eax
  char Buffer[8]; // [esp+4h] [ebp-48h] BYREF
  char v7[63]; // [esp+Ch] [ebp-40h] BYREF
  char v8; // [esp+4Bh] [ebp-1h]

  sub_564210(a1);
  if ( byte_B72478 )
    v1 = sub_4E4DE0();
  else
    v1 = sub_4E4E20();
  sprintf(Buffer, "%d", (unsigned int)(unsigned __int64)v1);
  sub_562B70((int)Buffer, 1230, 934, 16688384, 1, 4, 0.60000002, 0.60000002);
  if ( sub_4E4DD0() == -1 )
  {
    v2 = sub_41D840(&byte_91CC38, "R");
    sub_630FE0(v7, v2, 63);
    v8 = 0;
  }
  else if ( sub_4E4DD0() )
  {
    v4 = sub_4E4DD0();
    sprintf(v7, "%d", v4);
  }
  else
  {
    v3 = sub_41D840(&byte_91CC38, "N");
    sub_630FE0(v7, v3, 63);
    v8 = 0;
  }
  sub_562B70((int)v7, 1060, 894, 16688384, 2, 4, 1.0, 1.0);
  if ( (sub_4E4CB0(&unk_B6E79C) & 8) != 0 )
    return sub_562B70((int)&unk_7210AC, 1248, 875, -1, 2, 4, 2.0, 2.0);
  else
    return sub_562B70((int)&unk_7210A8, 1248, 875, -1, 2, 4, 2.0, 2.0);
}
