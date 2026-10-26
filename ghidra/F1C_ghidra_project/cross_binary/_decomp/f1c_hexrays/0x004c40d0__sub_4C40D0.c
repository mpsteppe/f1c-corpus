// f1c  0x004c40d0  size=355
int __stdcall sub_4C40D0(char *a1, const char *a2, const char *a3, int a4)
{
  int v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  const char *v7; // eax
  _BYTE v9[256]; // [esp+4h] [ebp-100h] BYREF

  if ( !sub_587C20(a1, &word_5BEB48) )
    strcat(a1, a2);
  if ( a3 )
  {
    sub_58815F(v9, "%s%s", a3, a1);
    v4 = sub_587DB0(v9, aR);
    if ( v4 )
      goto LABEL_13;
  }
  v5 = (const char *)dword_5EC428;
  if ( !dword_5EC428 )
    v5 = byte_5EA438;
  v6 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v6 = byte_5EA438;
  sub_58815F(v9, "%s%s%s", v6, v5, a1);
  v4 = sub_587DB0(v9, aR);
  if ( v4 )
    goto LABEL_13;
  v7 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v7 = byte_5EA438;
  sub_58815F(v9, "%scommon\\%s", v7, a1);
  v4 = sub_587DB0(v9, aR);
  if ( v4 )
  {
LABEL_13:
    sub_587D02(v4);
    sub_566650(v9);
    return 0;
  }
  else
  {
    if ( dword_7C569C != 5 )
    {
      if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 704) )
        sub_4D7AA0(&unk_8AD25C, aCouldNotFindS);
    }
    return -1;
  }
}
