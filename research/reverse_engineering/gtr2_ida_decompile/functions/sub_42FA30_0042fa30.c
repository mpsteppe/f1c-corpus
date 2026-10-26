char __thiscall sub_42FA30(int this, int a2, int a3, _DWORD *a4)
{
  char result; // al
  int v6; // ecx
  bool v7; // al
  int v8; // ecx

  result = sub_407400(a2, a3);
  if ( result )
  {
    if ( a3 )
      *(_DWORD *)(a3 + 4) |= 0x20u;
    v6 = a4[1];
    if ( !v6 || !((a4[2] - v6) >> 2) )
      sub_42F9A0(a4);
    sub_4090E0();
    *(_DWORD *)(this + 76) = this;
    v7 = sub_409950();
    v8 = a4[1];
    if ( v7 )
    {
      if ( !v8 || (unsigned int)((a4[2] - v8) >> 2) <= 1 )
        sub_42F9A0(a4);
    }
    else if ( !v8 || (unsigned int)((a4[2] - v8) >> 2) <= 2 )
    {
      sub_42F9A0(a4);
    }
    sub_4090E0();
    *(_DWORD *)(this + 96) = this;
    sub_54B280(this + 60);
    *(float *)(this + 104) = sub_42F680((_DWORD *)this);
    sub_5570C0(this);
    return 1;
  }
  return result;
}
