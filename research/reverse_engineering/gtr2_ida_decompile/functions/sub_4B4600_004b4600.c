int __thiscall sub_4B4600(int this)
{
  int v2; // eax
  bool v3; // cc

  sub_4AEB30((_DWORD *)this);
  if ( dword_B6CBBC )
  {
    byte_B6CBC0 = 0;
    CINet::Logout((CINet *)dword_B6CBB0);
    dword_B6CBBC = 0;
  }
  if ( byte_B6CBC1 )
  {
    byte_B6CBC1 = 0;
    CINet::Logout((CINet *)dword_B6CBB0);
    byte_B6CBC2 = 0;
  }
  v2 = dword_B73248;
  if ( *(_BYTE *)(this + 280) )
  {
    dword_B73240 = 1;
    if ( dword_B73248 <= 1 )
    {
      v2 = dword_B7324C;
      v3 = dword_B7324C < 1;
      goto LABEL_10;
    }
LABEL_11:
    dword_B73240 = v2;
    return 0;
  }
  dword_B73240 = 0;
  if ( dword_B73248 > 0 )
    goto LABEL_11;
  v2 = dword_B7324C;
  v3 = dword_B7324C < 0;
LABEL_10:
  if ( v3 )
    goto LABEL_11;
  return 0;
}
