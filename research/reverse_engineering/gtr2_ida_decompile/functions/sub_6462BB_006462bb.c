int __thiscall sub_6462BB(int this, char *lpBuffer, unsigned int a3, LPDWORD lpNumberOfBytesWritten)
{
  int v5; // eax
  int v6; // eax
  int result; // eax
  unsigned int v8; // esi
  size_t v9; // eax
  int v10; // edx
  DWORD v11; // eax
  char *v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // [esp+Ch] [ebp-4h]
  char *lpBuffera; // [esp+18h] [ebp+8h]

  v16 = 0;
  v5 = *(_DWORD *)(this + 16);
  if ( !v5 )
    return 0;
  v6 = v5 - 1;
  if ( !v6 )
  {
    v10 = *(_DWORD *)(this + 28);
    if ( v10 + a3 > 0x10000 )
    {
      if ( v10 == 0x10000 || !v10 )
      {
        v12 = lpBuffer;
      }
      else
      {
        qmemcpy((void *)(v10 + *(_DWORD *)(this + 24)), lpBuffer, 0x10000 - v10);
        v10 = *(_DWORD *)(this + 28);
        v12 = &lpBuffer[-v10 + 0x10000];
      }
      lpBuffera = v12;
      if ( v10 )
      {
        if ( !WriteFile(*(HANDLE *)this, *(LPCVOID *)(this + 24), 0x10000u, lpNumberOfBytesWritten, 0) )
          return -2147467259;
        *(_DWORD *)(this + 32) += 0x10000;
        v13 = 0x10000 - *(_DWORD *)(this + 28);
        *(_DWORD *)(this + 28) = 0;
        v16 = v13;
      }
      v14 = (a3 - v16) >> 16;
      if ( v14 )
      {
        v15 = v14 << 16;
        if ( !WriteFile(*(HANDLE *)this, lpBuffera, v14 << 16, lpNumberOfBytesWritten, 0) )
          return -2147467259;
        *(_DWORD *)(this + 32) += v15;
        v16 += v15;
        lpBuffera += v15;
      }
      if ( v16 < a3 )
      {
        qmemcpy(*(void **)(this + 24), lpBuffera, a3 - v16);
        *(_DWORD *)(this + 28) = a3 - v16;
      }
      v11 = a3;
    }
    else
    {
      v11 = a3;
      qmemcpy((void *)(v10 + *(_DWORD *)(this + 24)), lpBuffer, a3);
      *(_DWORD *)(this + 28) += a3;
    }
    *lpNumberOfBytesWritten = v11;
    return 0;
  }
  if ( v6 != 1 )
    return -2147467259;
  if ( a3 + *(_DWORD *)(this + 32) <= (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 20) + 16))(*(_DWORD *)(this + 20))
    || ((v8 = *(_DWORD *)(this + 32) + a3,
         v8 <= 2 * (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 20) + 16))(*(_DWORD *)(this + 20)))
      ? (v9 = 2 * (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 20) + 16))(*(_DWORD *)(this + 20)))
      : (v9 = v8),
        result = sub_677187(v9),
        result >= 0) )
  {
    qmemcpy(
      (void *)(*(_DWORD *)(this + 32)
             + (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 20) + 12))(*(_DWORD *)(this + 20))),
      lpBuffer,
      a3);
    *lpNumberOfBytesWritten = a3;
    *(_DWORD *)(this + 32) += a3;
    return 0;
  }
  return result;
}
