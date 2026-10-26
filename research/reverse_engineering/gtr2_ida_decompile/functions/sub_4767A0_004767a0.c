void __thiscall sub_4767A0(float *this)
{
  int v1; // ecx
  _DWORD *v2; // eax

  if ( this[532] >= 0.667 && !byte_B6F118 )
  {
    v1 = 58;
    v2 = &unk_B6C010;
    while ( !*v2 )
    {
      v2 += 11;
      ++v1;
      if ( (int)v2 > (int)dword_B6C19C )
        goto LABEL_8;
    }
    sub_476670();
LABEL_8:
    if ( (dword_B698E8 & 1) != 0 && (byte_B69A09 & 2) != 0 && (byte_B699EE & 2) != 0
      || (dword_B698E8 & 1) != 0
      && ((byte_B69A09 & 2) != 0 && (byte_B699EF & 2) != 0
       || (dword_B698E8 & 1) != 0
       && ((byte_B69A09 & 2) != 0 && (byte_B699F0 & 2) != 0
        || (dword_B698E8 & 1) != 0
        && ((byte_B69A09 & 2) != 0 && (byte_B699F1 & 2) != 0
         || (dword_B698E8 & 1) != 0
         && ((byte_B69A09 & 2) != 0 && (byte_B699F2 & 2) != 0
          || (dword_B698E8 & 1) != 0
          && ((byte_B69A09 & 2) != 0 && (byte_B699F3 & 2) != 0
           || (dword_B698E8 & 1) != 0
           && ((byte_B69A09 & 2) != 0 && (byte_B699F4 & 2) != 0
            || (dword_B698E8 & 1) != 0
            && ((byte_B69A09 & 2) != 0 && (byte_B699F5 & 2) != 0
             || (dword_B698E8 & 1) != 0
             && ((byte_B69A09 & 2) != 0 && (byte_B699F6 & 2) != 0
              || (dword_B698E8 & 1) != 0 && (byte_B69A09 & 2) != 0 && (byte_B699F7 & 2) != 0)))))))) )
    {
      sub_476670();
    }
  }
}
