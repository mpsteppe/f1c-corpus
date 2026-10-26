void __userpurge sub_5D8DD0(int a1@<ecx>, char a2@<bl>, char a3)
{
  double v5; // st7
  float v6; // ecx
  float v8; // [esp+8h] [ebp+4h]

  if ( dword_FB2770 )
  {
    if ( a3 )
      sub_5F5AD0(1);
    if ( ++dword_FB2768 > dword_910EEC )
      sub_5D8C80(a1, (char *)0xFFFFFFFE, "Total scene callback ins count is incorrect", a2);
    v5 = (double)dword_FB2768 / (double)dword_910EEC * flt_FB276C;
    if ( flt_FB276C >= v5 )
      v8 = v5;
    else
      v8 = flt_FB276C;
    if ( a3 || 1.0 / flt_910EF0 < sub_5F5900(&unk_FB2D18) )
    {
      sub_5F5C70(1);
      v6 = v8;
      LOBYTE(v6) = a3;
      dword_FB2770(LODWORD(v6), LODWORD(v8));
    }
  }
}
