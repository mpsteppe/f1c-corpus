// Microsoft VisualC 2-14/net runtime
void *__thiscall unknown_libname_186(int this, int *a2, int Offset, int Origin, int a5)
{
  FILE *v6; // eax
  int *v7; // esi
  void *result; // eax
  int v9; // [esp+8h] [ebp-20h] BYREF
  fpos_t v10; // [esp+10h] [ebp-18h]
  int v11; // [esp+18h] [ebp-10h]
  fpos_t Position; // [esp+20h] [ebp-8h] BYREF

  v6 = *(FILE **)(this + 80);
  if ( !v6 || fseek(v6, Offset, Origin) || fgetpos(*(FILE **)(this + 80), &Position) )
  {
    v7 = (int *)std::fpos<int>::fpos<int>(-1);
  }
  else
  {
    v9 = 0;
    v10 = Position;
    v11 = *(_DWORD *)(this + 64);
    v7 = &v9;
  }
  result = a2;
  qmemcpy(a2, v7, 0x18u);
  return result;
}
