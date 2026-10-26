int __thiscall sub_459D60(int *this, int a2)
{
  int v2; // edi
  void *v3; // esi
  int result; // eax
  int v5; // ecx

  v5 = *this;
  v2 = v5;
  v3 = *(void **)(v5 + 120);
  if ( v3 )
  {
    sub_45A550(*(_DWORD *)(v5 + 120));
    sub_5BE8AE(v3);
    result = a2;
    *(_DWORD *)(v2 + 120) = a2;
  }
  else
  {
    *(_DWORD *)(v5 + 120) = a2;
  }
  return result;
}
