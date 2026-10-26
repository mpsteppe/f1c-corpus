char *__thiscall sub_46E8C0(char *this)
{
  char *result; // eax
  _DWORD *v2; // esi
  _BYTE *v3; // edi
  _DWORD *v4; // edx
  int v5; // ecx

  result = this;
  v2 = this + 1028;
  v3 = this + 1;
  v4 = this + 1100;
  v5 = 16;
  do
  {
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[2] = 0;
    v4[1] = 1065353216;
    v4[3] = 1065353216;
    v4[4] = 0;
    *v3 = 0;
    *v2++ = 0;
    v4 += 6;
    v3 += 64;
    --v5;
  }
  while ( v5 );
  *((_DWORD *)result + 370) = 0;
  *((_DWORD *)result + 273) = 0;
  *((_DWORD *)result + 377) = 0;
  *result = 0;
  result[1512] = 0;
  *((_DWORD *)result + 373) = 0;
  *((_DWORD *)result + 374) = 0;
  *((_DWORD *)result + 375) = 0;
  *((_DWORD *)result + 376) = 0;
  *((_DWORD *)result + 372) = 0;
  return result;
}
