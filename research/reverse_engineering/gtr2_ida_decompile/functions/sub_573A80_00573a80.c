int __thiscall sub_573A80(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  int result; // eax

  this[711] = *a2;
  this[712] = a2[1];
  this[713] = a2[2];
  v3 = this + 714;
  *v3 = *a3;
  v3[1] = a3[1];
  result = a3[2];
  v3[2] = result;
  return result;
}
