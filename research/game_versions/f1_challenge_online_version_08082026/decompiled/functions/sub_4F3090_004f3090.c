int __thiscall sub_4F3090(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  for ( result = sub_5351D0(384); result; result = sub_5351D0(384) )
  {
    result = sub_5651B0(a4);
    if ( result == 1 )
      break;
    if ( !result )
    {
      if ( sub_565AA0(aFendercenter, this + 60, this + 68, this + 76, 0) )
        *this = 1;
      sub_565AA0(aFenderdragpara, this + 4, this + 12, this + 20, 0);
      sub_565AA0(aFenderliftpara, this + 28, this + 36, this + 44, 0);
      sub_565AA0(aFendersideways, this + 52, 0, 0, 0);
      sub_42E1F0((char *)((a2 << 6) + a5 + 2992), a4, (int)aFenderflareran, (int)aFenderflareset, 1.0);
    }
  }
  return result;
}
