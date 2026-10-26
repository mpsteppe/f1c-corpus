int __thiscall sub_404E90(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx

  result = this[89];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = 0;
    do
    {
      sub_529080(v4 + this[90]);
      result = this[89];
      ++v3;
      v4 += 348;
    }
    while ( v3 < result );
  }
  return result;
}
