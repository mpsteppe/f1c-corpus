// f1c  0x00599e71  size=101
void __usercall sub_599E71(int a1@<ebp>)
{
  int v1; // ecx
  _DWORD *v2; // esi
  bool v3; // zf
  _DWORD *v4; // edi

  sub_58A5D8();
  v2 = (_DWORD *)v1;
  *(_DWORD *)(a1 - 16) = v1;
  *(_DWORD *)v1 = &off_5B9C68;
  v3 = *(_BYTE *)(v1 + 72) == 0;
  *(_DWORD *)(a1 - 4) = 1;
  if ( !v3 )
    sub_59A44C();
  v4 = (_DWORD *)v2[17];
  if ( v4 )
  {
    sub_5993AF(v4, 1);
    sub_587BCF(v4);
  }
  sub_598C70(v2 + 19);
  *v2 = &std::basic_streambuf<unsigned short>::`vftable';
  sub_598C70(v2 + 13);
}
