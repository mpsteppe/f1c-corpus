int __thiscall sub_60C0C0(
        void *this,
        char *Str,
        int a3,
        int *a4,
        char a5,
        int a6,
        int a7,
        void **a8,
        char a9,
        char a10)
{
  _DWORD *v10; // esi
  int v11; // eax
  _DWORD *v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // edi
  unsigned int v17; // eax
  unsigned int v18; // ebx
  char v19; // [esp+0h] [ebp-18h]
  int v20; // [esp+Ch] [ebp-Ch] BYREF
  void *Block; // [esp+10h] [ebp-8h] BYREF
  void *v22; // [esp+14h] [ebp-4h]

  v10 = 0;
  v22 = this;
  v20 = 0;
  Block = 0;
  if ( a4 && *a4 > 0 )
  {
    v10 = operator new(8 * *a4 + 8);
    v11 = 0;
    if ( *a4 > 0 )
    {
      v12 = a4 + 257;
      do
      {
        v10[2 * v11 + 1] = v12;
        v10[2 * v11++] = v12 - 256;
        v12 += 8;
      }
      while ( v11 < *a4 );
    }
    v10[2 * v11] = 0;
    v10[2 * v11 + 1] = 0;
  }
  if ( a10 )
  {
    if ( a9 )
      v13 = sub_645B85((LPCWCH)Str, v10, 0, a7, &v20, &Block);
    else
      v13 = sub_645C66(Str, a3, v10, 0, a7, &v20, &Block);
  }
  else
  {
    v14 = a7 | 0x400;
    if ( strstr(Str, "OptimizeOff") )
      v14 = a7 | 0x405;
    if ( a9 )
      v13 = sub_645D49((LPCWCH)Str, v10, 0, a5, a6, v14, &v20, &Block, 0);
    else
      v13 = sub_645E7A(Str, a3, v10, 0, a5, a6, v14, &v20, &Block, 0);
  }
  v15 = v13;
  if ( v10 )
    j__free(v10);
  if ( v15 )
  {
    if ( Block )
    {
      (*(void (__stdcall **)(void *))(*(_DWORD *)Block + 12))(Block);
      j__free(Block);
    }
    sub_5D8C80((int)v22 + 4, (char *)0xFFFFFFFF, "Fatal error assembling shader.", v19);
    return -1;
  }
  else
  {
    if ( a8 )
    {
      v17 = (*(int (__stdcall **)(int))(*(_DWORD *)v20 + 16))(v20);
      *a8 = operator new(4 * (v17 >> 2));
      v18 = (*(int (__stdcall **)(int))(*(_DWORD *)v20 + 16))(v20);
      qmemcpy(*a8, (const void *)(*(int (__stdcall **)(int))(*(_DWORD *)v20 + 12))(v20), v18);
      (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
    }
    return 0;
  }
}
