int __stdcall sub_4AC0C0(int a1)
{
  int v1; // edi
  int i; // esi
  int v4; // eax
  int v5; // eax

  v1 = 0;
  if ( !a1 )
    return -1;
  for ( i = sub_4AEF80(a1); i; v1 += v4 )
  {
    v4 = sub_4AC110(i);
    i = *(_DWORD *)(i + 56);
  }
  v5 = sub_4AF0A0(a1);
  return v1 + sub_4AC120(v5);
}
