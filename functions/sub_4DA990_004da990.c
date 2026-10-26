int __thiscall sub_4DA990(_DWORD *this)
{
  __int64 v1; // rax
  int v2; // ecx

  v1 = 0;
  if ( dword_5C329C > 0 )
  {
    v2 = this[9];
    do
    {
      if ( *(_DWORD *)(dword_7C54F0[HIDWORD(v1)] + 16444) >= v2 )
        LODWORD(v1) = v1 + 1;
      ++HIDWORD(v1);
    }
    while ( SHIDWORD(v1) < dword_5C329C );
  }
  return v1;
}
