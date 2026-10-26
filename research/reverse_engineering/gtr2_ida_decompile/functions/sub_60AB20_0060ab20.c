int __stdcall sub_60AB20(_DWORD *a1)
{
  __int64 v1; // rax
  int v2; // esi
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx

  v1 = (unsigned int)a1;
  if ( (int)a1[90] > 0 )
  {
    v2 = 0;
    do
    {
      *(_DWORD *)(v2 + *(_DWORD *)(v1 + 364) + 44) = 0;
      if ( SHIDWORD(v1) >= *(_DWORD *)(v1 + 360) )
        v3 = 0;
      else
        v3 = v2 + a1[91];
      *(_DWORD *)(v3 + 52) = 0;
      if ( SHIDWORD(v1) >= *(_DWORD *)(v1 + 360) )
        v4 = 0;
      else
        v4 = v2 + a1[91];
      *(_DWORD *)(v4 + 48) = 0;
      if ( SHIDWORD(v1) >= *(_DWORD *)(v1 + 360) )
        v5 = 0;
      else
        v5 = v2 + a1[91];
      *(_DWORD *)(v5 + 56) = 0;
      ++HIDWORD(v1);
      v2 += 108;
    }
    while ( SHIDWORD(v1) < *(_DWORD *)(v1 + 360) );
  }
  *a1 &= 0xFFFEE7FF;
  return v1;
}
