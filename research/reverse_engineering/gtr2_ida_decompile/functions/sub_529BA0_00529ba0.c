char __thiscall sub_529BA0(int this)
{
  int v2; // eax
  int i; // edx
  float v5; // [esp+0h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)this;
  if ( *(_DWORD *)this == 1 )
  {
    if ( !byte_B6413C && (*(_DWORD *)dword_B72314 != 8 || !byte_B6F118) )
    {
      v6 = dbl_FB1D18;
      sub_528C70(*(_DWORD *)(this + 8), COERCE_FLOAT(&dword_82F4A0), (int)&unk_9204A0, v6, 0);
    }
    if ( !(unsigned __int8)sub_4735A0() && dword_B6E4D0 != 5 && dword_B6BA38 )
    {
      *(_BYTE *)(this + 5) = 1;
      v5 = (float)dword_B71E88;
      sub_529390((_DWORD *)(this + 8), v5, (_DWORD *)this);
    }
    for ( i = 0; ; ++i )
    {
      v2 = (dword_B698E8 & 1) != 0 ? dword_B6A2F4 : 0;
      if ( i >= v2 )
        break;
    }
  }
  else if ( v2 == 2 )
  {
    LOBYTE(v2) = *(_BYTE *)(*(_DWORD *)(this + 8) + 2892961);
    if ( !(_BYTE)v2 )
      LOBYTE(v2) = sub_54AB10(&unk_BE2728);
  }
  return v2;
}
