int __thiscall sub_567980(_DWORD *this)
{
  int v1; // ecx
  int result; // eax

  v1 = this[2];
  for ( result = 0; v1; ++result )
    v1 = *(_DWORD *)(v1 + 4);
  return result;
}
