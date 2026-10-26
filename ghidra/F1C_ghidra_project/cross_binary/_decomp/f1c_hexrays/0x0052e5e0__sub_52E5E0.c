// f1c  0x0052e5e0  size=262
int __thiscall sub_52E5E0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // eax
  int v8; // ebx
  unsigned __int32 v9; // eax
  int v10; // ecx
  int result; // eax
  int v12; // ebx
  unsigned __int32 v13; // eax

  LOWORD(v7) = 0;
  v8 = *(char *)(a3 + 2 * a2);
  if ( *(_BYTE *)(a3 + 2 * a2) )
  {
    v9 = dword_5B4788[v8 + 1]
       & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v8 + 1 + (this[2346] & 7)));
    this[2346] += v8 + 1;
    v7 = (int)((v9 + dword_5B4820[v8]) * *(_DWORD *)(a6 + 4 * (((v8 + 1) << 6) + *(_DWORD *)(a4 + 4 * a2)))) >> 12;
  }
  v10 = a5;
  *(_WORD *)(a5 + 2 * a2) = v7;
  result = 0;
  v12 = *(char *)(a3 + 2 * a2 + 1);
  if ( *(_BYTE *)(a3 + 2 * a2 + 1) )
  {
    v13 = dword_5B4788[v12 + 1]
        & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v12 + 1 + (this[2346] & 7)));
    this[2346] += v12 + 1;
    v10 = a5;
    result = (int)((v13 + dword_5B4820[v12]) * *(_DWORD *)(a6 + 4 * (((v12 + 1) << 6) + *(_DWORD *)(a4 + 4 * a2 + 128)))) >> 12;
  }
  *(_WORD *)(v10 + 2 * a2 + 64) = result;
  return result;
}
