char __thiscall sub_507460(_BYTE *this)
{
  bool v2; // zf
  char result; // al

  v2 = this[21] == 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 1065353216;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  this[20] = 0;
  if ( !v2 )
  {
    result = sub_502060(&dword_7D7978, 1);
    this[21] = 0;
  }
  return result;
}
