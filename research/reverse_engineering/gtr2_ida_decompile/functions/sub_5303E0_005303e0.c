int __thiscall sub_5303E0(int this)
{
  _DWORD *v1; // eax
  int v2; // edx
  int result; // eax

  v1 = (_DWORD *)(this + 216);
  v2 = 48;
  do
  {
    *(v1 - 48) = -1;
    *v1 = -1082130432;
    v1[48] = -1;
    v1[96] = -1082130432;
    ++v1;
    --v2;
  }
  while ( v2 );
  result = 0;
  *(_DWORD *)(this + 836) = -1;
  *(_DWORD *)(this + 792) = 0;
  *(_DWORD *)(this + 800) = 0;
  *(_DWORD *)(this + 796) = 0;
  *(_DWORD *)(this + 804) = 0;
  *(_DWORD *)(this + 808) = 0;
  *(_DWORD *)(this + 816) = 0;
  *(_DWORD *)(this + 820) = 0;
  *(_DWORD *)(this + 824) = 0;
  *(_BYTE *)(this + 840) = 0;
  return result;
}
