// Microsoft VisualC 2-14/net runtime
void *__thiscall unknown_libname_192(int this, int *a2, int a3, int a4, fpos_t a5, int a6, int a7, int a8)
{
  int v9; // edi
  FILE *v10; // eax
  _DWORD *v11; // ecx
  int *v12; // esi
  void *result; // eax
  fpos_t Position; // [esp+8h] [ebp-8h] BYREF

  Position = a5;
  v9 = a3;
  v10 = *(FILE **)(this + 80);
  if ( !v10
    || fsetpos(v10, &Position)
    || v9 && fseek(*(FILE **)(this + 80), v9, 1)
    || fgetpos(*(FILE **)(this + 80), &Position) )
  {
    v12 = std::fpos<int>::fpos<int>(&a3, -1);
  }
  else
  {
    v11 = *(_DWORD **)(this + 68);
    if ( v11 )
    {
      *(_DWORD *)(this + 64) = a6;
      std::string::erase(v11, 0, 0xFFFFFFFF);
    }
    a3 = 0;
    a5 = Position;
    a6 = *(_DWORD *)(this + 64);
    v12 = &a3;
  }
  result = a2;
  qmemcpy(a2, v12, 0x18u);
  return result;
}
