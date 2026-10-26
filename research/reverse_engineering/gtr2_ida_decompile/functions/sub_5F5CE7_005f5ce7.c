// positive sp value has been detected, the output may be wrong!
_DWORD *__stdcall sub_5F5CE7(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi

  v1 = operator new(0x60u);
  v2 = 0;
  if ( v1 )
    v2 = sub_5F56F0(v1);
  sub_5F5AD0((int)v2, a1);
  return v2;
}
