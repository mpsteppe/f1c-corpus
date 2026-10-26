int __fastcall sub_5BA230(_DWORD *a1, int a2)
{
  int v3; // ecx
  int result; // eax
  int v5; // edx
  int i; // esi
  CHAR *v7; // edi
  int v8; // edx

  v3 = a2 + 1;
  LOBYTE(a2) = 92;
  result = sub_5BA300(v3, a2);
  for ( i = result; result; i = result )
  {
    LOBYTE(v5) = 92;
    v7 = (CHAR *)sub_5BA300(0, v5);
    if ( !v7 )
      v7 = &byte_629120;
    if ( sub_5BA290(i) )
      sub_5BA0E0(a1, (int)v7);
    LOBYTE(v8) = 92;
    result = sub_5BA300(0, v8);
  }
  return result;
}
