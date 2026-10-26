// bad sp value at call has been detected, the output may be wrong!
int sub_65DD1F(_DWORD *a1, int a2, int a3, char *Format, ...)
{
  char *v4; // esi
  size_t v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char *v11; // esi
  char Buffer[4096]; // [esp+0h] [ebp-1000h] BYREF
  int savedregs; // [esp+1000h] [ebp+0h]
  va_list va; // [esp+1018h] [ebp+18h] BYREF

  va_start(va, Format);
  sub_631BD0(0x1000u, savedregs);
  v4 = Buffer;
  v5 = 4094;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) )
    {
      v6 = sub_632041((int)Buffer, 4094, "%s", *(const char **)(a2 + 16));
      if ( v6 < 0 )
        v6 = 4094;
      v4 = &Buffer[v6];
      v5 = 4094 - v6;
    }
    v7 = *(_DWORD *)(a2 + 20);
    if ( !v7 )
      v7 = 1;
    v8 = sub_632041((int)v4, v5, "(%u): ", v7);
    if ( v8 < 0 )
      v8 = v5;
    v4 += v8;
    v5 -= v8;
  }
  if ( a3 )
  {
    v9 = sub_632041((int)v4, v5, "error X%u: ", a3);
    if ( v9 < 0 )
      v9 = v5;
    v4 += v9;
    v5 -= v9;
  }
  v10 = _vsnprintf(v4, v5, Format, va);
  if ( v10 < 0 )
    v10 = v5;
  v11 = &v4[v10];
  *v11 = 10;
  v11[1] = 0;
  ++a1[2];
  return sub_65D719(a1, Buffer);
}
