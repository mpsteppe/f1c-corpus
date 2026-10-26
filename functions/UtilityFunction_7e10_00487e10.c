int __thiscall UtilityFunction_7e10(_BYTE *this)
{
  _DWORD *v2; // eax

  if ( !UIValueValidator(this) )
    return -1;
  sub_487260(this, 1);
  UIRadioCheckStateChangeHandler((int)this);
  v2 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
  if ( v2 )
    *v2 = *v2 == 0;
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this) )
    return -1;
  sub_486600(this);
  return 0;
}
