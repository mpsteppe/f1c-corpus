int __stdcall sub_680715(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // esi
  void *v4; // ebx
  int v5; // esi

  v3 = 16 * a2;
  v4 = operator new(16 * a2);
  if ( v4 )
  {
    memset(v4, 0, v3);
    v5 = sub_68024C(a1, (char *)v4, v3, 6, a3);
  }
  else
  {
    v5 = -2147024882;
  }
  j__free(v4);
  return v5;
}
