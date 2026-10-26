// f1c  0x0045bbe0  size=18
int __thiscall sub_45BBE0(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  _DWORD *v4; // ecx

  sub_45B950();
  v4 = (_DWORD *)*this;
  v1 = 0;
  v4[199] = 0;
  do
    result = sub_45B430(v4, v1++);
  while ( v1 < 8 );
  return result;
}
