int __thiscall sub_52BF50(_DWORD *this, char a2)
{
  int v3; // esi
  int result; // eax
  int v5; // [esp+4h] [ebp-10h]

  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    sub_54F160(&byte_FADF20, *this);
    v3 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v5 = dbl_FB1D18;
    if ( a2 )
    {
      result = sub_51B2A0((_DWORD *)v3, 4, 24, 1, this[1], v5, 3);
      *(_BYTE *)(v3 + 8) = *((_BYTE *)this + 112);
    }
    else
    {
      return sub_51B2A0((_DWORD *)v3, 4, 25, 0, this[1], v5, 3);
    }
  }
  return result;
}
