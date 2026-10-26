int __thiscall sub_644190(FILE **this)
{
  int v3; // edi
  int v4; // ebx

  if ( !this[1] )
    return -1;
  v3 = ((int (__thiscall *)(FILE **))(*this)[4]._ptr)(this);
  fseek(this[1], 0, 2);
  v4 = ((int (__thiscall *)(FILE **))(*this)[4]._ptr)(this);
  fseek(this[1], v3, 0);
  return v4;
}
