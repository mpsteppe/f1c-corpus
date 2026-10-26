// f1c  0x004958d0  size=79
int __stdcall sub_4958D0(int a1)
{
  int v1; // edi
  int i; // esi
  int v4; // eax
  int v5; // eax

  v1 = 0;
  if ( !a1 )
    return -1;
  for ( i = sub_498E30(a1); i; v1 += v4 )
  {
    v4 = sub_495920(i);
    i = *(_DWORD *)(i + 72);
  }
  v5 = sub_498F60(a1);
  return v1 + sub_495930(v5);
}
