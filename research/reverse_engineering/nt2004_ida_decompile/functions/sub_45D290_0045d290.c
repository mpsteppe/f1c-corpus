int __thiscall sub_45D290(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  _DWORD *v3; // ecx

  v3 = (_DWORD *)(*this + 8);
  v1 = 0;
  v3[297] = 0;
  do
    result = sub_45C6C0(v3, v1++);
  while ( v1 < 8 );
  return result;
}
