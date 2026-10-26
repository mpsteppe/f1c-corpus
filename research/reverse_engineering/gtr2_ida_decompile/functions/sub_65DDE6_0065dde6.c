// bad sp value at call has been detected, the output may be wrong!
int sub_65DDE6(_DWORD *a1, int a2, const char *a3, char *Format, ...)
{
  char *v4; // esi
  size_t v5; // edi
  int result; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  char *v14; // esi
  _DWORD *v15; // eax
  char Buffer[4096]; // [esp+0h] [ebp-100Ch] BYREF
  int v17; // [esp+1000h] [ebp-Ch]
  const char *v18; // [esp+1004h] [ebp-8h]
  unsigned int v19; // [esp+1008h] [ebp-4h] BYREF
  int savedregs; // [esp+100Ch] [ebp+0h]
  va_list va; // [esp+1024h] [ebp+18h] BYREF

  va_start(va, Format);
  sub_631BD0(0x100Cu, savedregs);
  v4 = Buffer;
  v5 = 4094;
  result = sub_65D5D6((int)a1, (unsigned int)a3, &v19);
  if ( result >= 0 )
  {
    v7 = 4 * v19;
    v17 = *(_DWORD *)(4 * v19 + a1[7]);
    if ( (v17 & 0xF) == 0xF )
    {
      v18 = "error";
      v19 = (unsigned int)(a1 + 2);
    }
    else
    {
      v19 = (unsigned int)(a1 + 3);
      v8 = a1[4];
      v18 = "warning";
      if ( !v8 || (v17 & 0xF) == 0 || v8 < (v17 & 0xFu) || (v17 & 0x10) != 0 && (v17 & 0x20) != 0 )
        return 0;
      *(_DWORD *)(v7 + a1[7]) |= 0x20u;
    }
    if ( a2 )
    {
      if ( *(_DWORD *)(a2 + 16) )
      {
        v9 = sub_632041((int)Buffer, 4094, "%s", *(const char **)(a2 + 16));
        if ( v9 < 0 )
          v9 = 4094;
        v4 = &Buffer[v9];
        v5 = 4094 - v9;
      }
      v10 = *(_DWORD *)(a2 + 20);
      if ( !v10 )
        v10 = 1;
      v11 = sub_632041((int)v4, v5, "(%u): ", v10);
      if ( v11 < 0 )
        v11 = v5;
      v4 += v11;
      v5 -= v11;
    }
    if ( a3 )
    {
      v12 = sub_632041((int)v4, v5, "%s X%u: ", a3, a3);
      if ( v12 < 0 )
        v12 = v5;
      v4 += v12;
      v5 -= v12;
    }
    v13 = _vsnprintf(v4, v5, Format, va);
    if ( v13 < 0 )
      v13 = v5;
    v14 = &v4[v13];
    v15 = (_DWORD *)v19;
    *v14 = 10;
    v14[1] = 0;
    ++*v15;
    return sub_65D719(a1, Buffer);
  }
  return result;
}
