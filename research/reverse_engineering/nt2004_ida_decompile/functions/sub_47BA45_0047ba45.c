int __usercall sub_47BA45@<eax>(char a1@<al>, int a2@<ecx>)
{
  _DWORD v4[7]; // [esp+8h] [ebp-20h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  if ( a1 || (dword_761FF8 & 1) != 0 && dword_762A04 > 0 )
  {
    if ( !byte_76BB80 )
      goto LABEL_8;
  }
  else
  {
    memset(v4, 0, sizeof(v4));
    v5 = 0;
    sub_4AE8B0(v4);
    if ( v5 != 3 && v5 != 7 && v5 != 10 )
      return 0;
    if ( !byte_76BB80 )
    {
LABEL_8:
      sub_49D120(a2);
      return 0;
    }
  }
  byte_76BB80 = 0;
  sub_4AD720(aPopupAddprofil, 1);
  sub_4AE900(aAddProfileForc);
  return 0;
}
