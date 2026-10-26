int __thiscall sub_509AE0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  int result; // eax

  v1 = this + 3673;
  v2 = 15;
  do
  {
    v1 -= 187;
    result = sub_508930(v1);
    --v2;
  }
  while ( v2 );
  return result;
}
