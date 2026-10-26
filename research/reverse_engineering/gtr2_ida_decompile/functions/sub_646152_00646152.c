int __stdcall sub_646152(int a1, int a2, _DWORD *a3)
{
  int v3; // ecx
  const char *v4; // eax
  int v5; // edx

  v3 = 44;
  v4 = "vs_3_0";
  while ( 1 )
  {
    v5 = *((_DWORD *)v4 - 4);
    v4 -= 12;
    --v3;
    if ( v5 == a1 && (a2 & *(_DWORD *)v4) == a2 )
      break;
    if ( v4 <= (const char *)dword_736888 )
      return -2147467259;
  }
  if ( a3 )
  {
    *a3 = (&off_736880)[3 * v3];
    a3[1] = *((_DWORD *)&unk_736884 + 3 * v3);
    a3[2] = dword_736888[3 * v3];
  }
  return 0;
}
