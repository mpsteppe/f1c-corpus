int __thiscall sub_438450(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))this[3];
  if ( v2 )
  {
    (**v2)(v2, 1);
    this[3] = 0;
  }
  *(_BYTE *)this = 0;
  this[1] = 0;
  this[7] = 0;
  this[8] = 0;
  *((_BYTE *)this + 2) = 0;
  this[10] = 0;
  this[11] = 0;
  this[2] = 0;
  this[3] = 0;
  this[13] = 0;
  *((_BYTE *)this + 1) = 1;
  return off_16C97A4();
}
