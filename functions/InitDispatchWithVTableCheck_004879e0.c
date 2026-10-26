int __thiscall InitDispatchWithVTableCheck(_BYTE *this)
{
  if ( !UIValueValidator(this) )
    return -1;
  StateDependentVTableDispatch_7760(this, 1);
  UIControlStateChangeHandler((int)this);
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this) )
    return -1;
  sub_486600(this);
  return 0;
}
