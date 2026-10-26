int __thiscall sub_4189F0(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v3; // ecx
  int v4; // edx

  LOBYTE(result) = 0;
  v3 = this + 537;
  v4 = 20;
  do
  {
    if ( *v3 == a2 )
    {
      result = sub_4144D0(v3);
      LOBYTE(result) = 1;
    }
    v3 += 8;
    --v4;
  }
  while ( v4 );
  return result;
}
