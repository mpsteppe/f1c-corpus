int __thiscall sub_4FF740(_DWORD *this)
{
  int v2; // edx
  bool v3; // cl
  int result; // eax
  int v5; // edi
  float v6; // [esp+0h] [ebp-10h]

  v2 = *this;
  v3 = (!*(_DWORD *)(*this + 21788) || !byte_B6F790) && *(_DWORD *)(v2 + 14820) == 1;
  result = this[188];
  if ( result )
  {
    if ( !--result )
    {
      v5 = off_9034A4;
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v6 = dbl_FB1D18;
      sub_51B2A0(6, 5, 1, this[1], LODWORD(v6), 0);
      *(_BYTE *)(v5 + 8) = 0;
      return sub_4FD580();
    }
  }
  else if ( !v3 )
  {
    result = this[2];
    if ( !result || (*(_BYTE *)(result + 12) & 1) == 0 )
    {
      if ( v2 != ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
        return sub_4FF690();
      result = sub_4FC350(this);
      if ( result != 1 && result != 2 && result != 3 )
        return sub_4FF690();
    }
  }
  return result;
}
