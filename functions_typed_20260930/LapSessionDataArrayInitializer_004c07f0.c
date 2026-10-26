int __thiscall sub_4C07F0(int this)
{
  _DWORD *v1; // eax
  int v2; // edx
  int result; // eax

  v1 = (_DWORD *)(this + 216);
  v2 = 48;
  do
  {
    *(v1 - 48) = -1;
    *v1++ = -1;
    --v2;
  }
  while ( v2 );
  result = 0;
  *(_DWORD *)(this + 408) = 0;
  *(_DWORD *)(this + 412) = 0;
  *(_DWORD *)(this + 416) = 0;
  *(_DWORD *)(this + 424) = 0;
  *(_DWORD *)(this + 428) = -1;
  *(_BYTE *)(this + 432) = 0;
  return result;
}

