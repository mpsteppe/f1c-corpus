_DWORD *__thiscall SlotArrayInit(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // edx
  int v3; // esi

  result = this;
  v2 = this + 6;
  v3 = 3;
  do
  {
    v2[3] = 0;
    *v2 = 0;
    *(v2 - 6) = -1;
    *(v2 - 3) = -1;
    ++v2;
    --v3;
  }
  while ( v3 );
  return result;
}

