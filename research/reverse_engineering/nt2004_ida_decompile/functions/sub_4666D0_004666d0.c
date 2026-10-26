char __thiscall sub_4666D0(int *this)
{
  int v1; // esi
  char result; // al
  void *v3; // ecx
  int v5; // eax
  int v6; // ecx

  v5 = *this;
  v6 = *(_DWORD *)(*this + 6708);
  if ( v6 )
  {
    sub_56A5E0(v6, *(_DWORD *)(v5 + 6936));
    sub_56A850(*this + 6708);
    *(_DWORD *)(*this + 6708) = 0;
  }
  v1 = *this + 30136;
  result = sub_45E840((_BYTE *)v1);
  v3 = *(void **)(v1 + 12);
  if ( v3 )
  {
    result = sub_5B9C40(v3);
    *(_DWORD *)(v1 + 12) = 0;
  }
  return result;
}
