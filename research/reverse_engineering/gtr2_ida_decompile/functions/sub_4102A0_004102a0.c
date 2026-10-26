int __thiscall sub_4102A0(_DWORD *this)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  int v6; // eax
  float v7; // [esp+8h] [ebp-1Ch] BYREF
  float v8; // [esp+Ch] [ebp-18h] BYREF
  int v9; // [esp+10h] [ebp-14h] BYREF
  int v10; // [esp+14h] [ebp-10h] BYREF
  _DWORD v11[3]; // [esp+18h] [ebp-Ch] BYREF

  sub_5E5B70(0x2000);
  (*(void (__thiscall **)(_DWORD *))(*this + 20))(this);
  v2 = this[5];
  v3 = this[3] + 272 * v2;
  v11[0] = *((_DWORD *)dword_91E07C + 698);
  v11[1] = *((_DWORD *)dword_91E07C + 699);
  v11[2] = *((_DWORD *)dword_91E07C + 700);
  if ( byte_91BF50 )
    return ((int (__thiscall *)(_DWORD *))loc_40FE00)(this);
  if ( v3 )
  {
    v7 = *(float *)(v3 + 144);
    if ( sub_46B270(v11) <= v7 )
      return ((int (__thiscall *)(_DWORD *))loc_40FE00)(this);
  }
  sub_40FD70(this, (int)v11, &v10, &v8);
  sub_40F740((_DWORD *)this[2], (int)v11, &v9, &v7);
  if ( v7 >= (double)v8 )
  {
    v6 = v10;
    if ( v10 >= 0 )
    {
      if ( v10 > this[4] - 1 )
        v6 = this[4] - 1;
    }
    else
    {
      v6 = 0;
    }
    this[5] = v6;
    if ( v6 != v2 )
      (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
    return ((int (__thiscall *)(_DWORD))loc_40FE00)(this);
  }
  dword_91BF28 = this[2];
  v4 = this[2];
  if ( v9 >= 0 && v9 < *(_DWORD *)(v4 + 16) )
    *(_DWORD *)(v4 + 20) = v9;
  return ((int (__thiscall *)(_DWORD))loc_40F7D0)(this[2]);
}
