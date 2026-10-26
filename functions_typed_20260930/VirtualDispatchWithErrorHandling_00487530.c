int __thiscall VirtualDispatchWithErrorHandling(_BYTE *this)
{
  if ( !UIValueValidator(this) )
    return -1;
  sub_487260(this, 1);
  UIRadioCheckStateChangeHandler((int)this);
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this) )
    return -1;
  sub_486600(this);
  return 0;
}

