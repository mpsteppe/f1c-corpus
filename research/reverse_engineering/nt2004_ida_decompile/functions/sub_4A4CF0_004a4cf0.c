int __thiscall sub_4A4CF0(_BYTE *this)
{
  int v2; // eax
  int v3; // ecx
  int v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h] BYREF

  if ( !sub_49D1D0(this) )
  {
    this[429] = 1;
    sub_4AE870(&v6, &v5);
    v2 = v6;
    v3 = v5;
    if ( v6 > *((_DWORD *)this + 86)
      && v6 < *((_DWORD *)this + 87)
      && v5 > *((_DWORD *)this + 94)
      && v5 < *((_DWORD *)this + 95) )
    {
      this[430] = 1;
    }
    if ( *((_DWORD *)this + 77) != 4 )
    {
      if ( v2 > *((_DWORD *)this + 80)
        && v2 < *((_DWORD *)this + 81)
        && v3 > *((_DWORD *)this + 88)
        && v3 < *((_DWORD *)this + 89) )
      {
        *((_DWORD *)this + 77) = 2;
        sub_4A56D0(-1);
        v3 = v5;
        v2 = v6;
        *((_DWORD *)this + 79) = 0;
      }
      if ( v2 > *((_DWORD *)this + 82)
        && v2 < *((_DWORD *)this + 83)
        && v3 > *((_DWORD *)this + 90)
        && v3 < *((_DWORD *)this + 91) )
      {
        *((_DWORD *)this + 77) = 3;
        sub_4A5740(-1);
        *((_DWORD *)this + 79) = 0;
      }
      ((void (__thiscall *)(_BYTE *))loc_4A5420)(this);
      v3 = v5;
      v2 = v6;
    }
    if ( v2 > *((_DWORD *)this + 84)
      && v2 < *((_DWORD *)this + 85)
      && v3 > *((_DWORD *)this + 92)
      && v3 < *((_DWORD *)this + 93) )
    {
      *((_DWORD *)this + 105) = *((_DWORD *)this + 104);
    }
    (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 44))(this, *((_DWORD *)this + 77));
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 144))(this);
  }
  return 0;
}
