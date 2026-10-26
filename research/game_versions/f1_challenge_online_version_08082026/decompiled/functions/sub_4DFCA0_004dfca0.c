LPVOID __thiscall sub_4DFCA0(LPVOID *this)
{
  _DWORD *v2; // esi
  int v3; // edi
  LPVOID result; // eax

  v2 = this + 2804;
  v3 = 11;
  do
  {
    v2 -= 187;
    sub_4DED20(v2);
    --v3;
  }
  while ( v3 );
  result = this[36];
  if ( result )
    return (LPVOID)sub_587BCF(this[36]);
  return result;
}
