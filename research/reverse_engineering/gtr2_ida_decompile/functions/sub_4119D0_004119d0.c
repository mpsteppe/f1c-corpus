void __thiscall sub_4119D0(float *this)
{
  int v2; // ecx
  BOOL v3; // eax
  int v4; // eax
  int v5; // eax
  float v6; // [esp+8h] [ebp-18h]

  v2 = *((_DWORD *)this + 16);
  v3 = dword_B6BB40 || byte_B73A20 && dword_B6BB14 && dword_B6BAE8;
  *((_DWORD *)this + 16) = v3;
  v4 = *((_DWORD *)this + 13);
  if ( v4 == 5 || v4 == 6 )
    this[16] = 0.0;
  if ( v2 != *((_DWORD *)this + 16) )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)this + 16))(this);
    v5 = *((_DWORD *)dword_91E07C + 1436);
    if ( v5 == 1 || v5 == 2 || !v5 && *((_DWORD *)this + 13) == 2 )
    {
      if ( *((_DWORD *)this + 16) )
      {
        if ( *((_DWORD *)dword_91E07C + 678) )
        {
          sub_5DB320(1, 0, 1);
          sub_5DA8C0(0, 1);
        }
      }
      else
      {
        sub_56AE80(v5, 1);
      }
    }
  }
  v6 = 0.0;
  if ( *((_DWORD *)this + 13) <= 2u )
    v6 = flt_B714D0 * (flt_B6BE04 - flt_B6BE30);
  if ( this[17] == v6 )
    JUMPOUT(0x411B8C);
  sub_411B4F();
}
