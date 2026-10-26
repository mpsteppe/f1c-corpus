char *__thiscall sub_46E940(char *this)
{
  _BYTE *v2; // ebp
  void **v3; // esi
  int *v4; // edi
  int v5; // ebx
  char *result; // eax

  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)dword_FB27A4 + 432))(dword_FB27A4, "LensFlare");
  v2 = this + 1;
  v3 = (void **)(this + 1028);
  v4 = (int *)(this + 1096);
  v5 = 16;
  do
  {
    if ( *v4 )
    {
      sub_5EE1D0(dword_FB1CE0, *v4);
      *v4 = 0;
    }
    if ( *v3 )
    {
      sub_5E4BF0(dword_FB1CE0, *v3);
      *v3 = 0;
    }
    *v2 = 0;
    ++v3;
    v4 += 6;
    v2 += 64;
    --v5;
  }
  while ( v5 );
  result = this;
  *((_DWORD *)this + 370) = 0;
  *((_DWORD *)this + 273) = 0;
  *this = 0;
  return result;
}
