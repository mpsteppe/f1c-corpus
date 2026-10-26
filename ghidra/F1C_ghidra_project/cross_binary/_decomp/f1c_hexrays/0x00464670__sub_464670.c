// f1c  0x00464670  size=66
char __thiscall sub_464670(int *this)
{
  int v1; // esi
  char result; // al
  void *v3; // ecx
  int v5; // eax
  int v6; // ecx

  v5 = *this;
  v6 = *(_DWORD *)(*this + 16312);
  if ( v6 )
  {
    sub_57A8B0(v6, *(_DWORD *)(v5 + 16764));
    sub_57AB20(*this + 16312);
    *(_DWORD *)(*this + 16312) = 0;
  }
  v1 = *this + 112528;
  result = sub_45D240((_BYTE *)v1);
  v3 = *(void **)(v1 + 12);
  if ( v3 )
  {
    result = sub_562C50(v3);
    *(_DWORD *)(v1 + 12) = 0;
  }
  return result;
}
