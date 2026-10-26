int __thiscall sub_412060(_DWORD *this)
{
  int v2; // edi
  int *v3; // ecx
  int v4; // edx
  float v6; // [esp+8h] [ebp-1Ch] BYREF
  float v7; // [esp+Ch] [ebp-18h] BYREF
  int v8; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+14h] [ebp-10h] BYREF
  _DWORD v10[3]; // [esp+18h] [ebp-Ch] BYREF

  (*(void (__thiscall **)(_DWORD *))(*this + 20))(this);
  v2 = this[3] + 164 * this[5];
  sub_5E5B70(0x2000);
  v10[0] = *((_DWORD *)dword_91E07C + 698);
  v10[1] = *((_DWORD *)dword_91E07C + 699);
  v10[2] = *((_DWORD *)dword_91E07C + 700);
  if ( byte_91BF50 )
    return ((int (__thiscall *)(_DWORD *))loc_40F7D0)(this);
  if ( v2 )
  {
    v6 = *(float *)(v2 + 144);
    if ( sub_46B270(v10) <= v6 )
      return ((int (__thiscall *)(_DWORD *))loc_40F7D0)(this);
  }
  sub_40F740(this, (int)v10, &v9, &v7);
  sub_40FD70((_DWORD *)this[2], (int)v10, &v8, &v6);
  if ( v6 >= (double)v7 )
  {
    this[5] = v9;
    return ((int (__thiscall *)(_DWORD))loc_40F7D0)(this);
  }
  dword_91BF28 = this[2];
  v3 = (int *)this[2];
  if ( v8 >= 0 && v8 < v3[4] )
  {
    v4 = *v3;
    v3[5] = v8;
    (*(void (**)(void))(v4 + 16))();
  }
  return ((int (__thiscall *)(_DWORD))loc_40FE00)(this[2]);
}
