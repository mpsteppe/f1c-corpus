char __thiscall sub_4FC460(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // ecx
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+Ch] [ebp-4h]

  LOBYTE(v2) = *((_BYTE *)this + 748);
  if ( (_BYTE)v2 )
  {
    sub_4FF690(0);
    v3 = *this + 19272;
    *((_BYTE *)this + 748) = 0;
    ++*(_DWORD *)(v3 + 116);
    if ( dword_FADE78 == 2 && dword_B704D4 && *(_DWORD *)(*this + 14820) <= 1u )
    {
      if ( *(_DWORD *)dword_B640C8 == 6 )
        sub_52C000("Exiting Pits Under Red");
      else
        nullsub_6((int)"Exiting Pits Under Red", 1148846080);
    }
    LOBYTE(v2) = dword_FADE9C;
    if ( (unsigned int)dword_FADE9C >= 2 && dword_FADE9C != 7 )
    {
      v2 = *this;
      if ( !*(_DWORD *)(*this + 19380) )
      {
        v7 = sub_577D40(v2 + 16);
        if ( sub_52B3A0(&byte_9034D0) < v7 && *((_BYTE *)this + 764) )
          *(_DWORD *)(*this + 19552) = -1;
        else
          *(_DWORD *)(*this + 19552) = 0;
        v6 = dbl_FB1D18;
        LOBYTE(v2) = sub_552CA0(*this, LODWORD(v6));
      }
    }
  }
  v4 = (_DWORD *)this[5];
  if ( v4 )
  {
    LOBYTE(v2) = 0;
    v4[192] = 0;
    v4[195] = 0;
    if ( v4[34] )
      LOBYTE(v2) = sub_5DB320(0, 0, 1);
  }
  return v2;
}
