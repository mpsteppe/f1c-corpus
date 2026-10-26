int __thiscall sub_45BDF0(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  _DWORD *v3; // ecx

  v3 = (_DWORD *)*this;
  v1 = 0;
  v3[199] = 0;
  do
    result = PerIndexStructFieldResetter(v3, v1++);
  while ( v1 < 8 );
  return result;
}

