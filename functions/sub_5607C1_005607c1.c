void __cdecl __spoils<> sub_5607C1(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _WORD *v8; // edi
  int v9; // ebp
  int v10; // eax
  int v11; // ebx
  int v12; // ebx
  bool v13; // cc

  dword_5DD814 = a4;
  dword_5DD878 = 32 * a8;
  dword_5DD898 = a8 << 6;
  v8 = (_WORD *)(a2 + a2 + a6 * a3 + a1);
  dword_5DD818 = a5;
  dword_5DD81C = a6 - 2 * a4;
  dword_5DD828 = 32 * ((unsigned __int8)a7 >> 4);
  dword_5DD824 = BYTE1(a7) >> 3 << 6;
  dword_5DD820 = 32 * (BYTE2(a7) >> 4);
  do
  {
    v9 = dword_5DD814;
    do
    {
      v10 = __ROR4__((unsigned __int16)*v8, 5);
      v11 = __ROR4__(
              (unsigned __int8)byte_5DECCC[dword_5DD878 + (unsigned __int8)byte_5DD8CC[dword_5DD828 + (*v8 & 0x1F)]],
              5);
      LOBYTE(v11) = byte_5E0CCC[dword_5DD898 + (unsigned __int8)byte_5DDCCC[dword_5DD824 + (v10 & 0x3F)]] | v11;
      v12 = __ROR4__(v11, 6);
      LOBYTE(v12) = byte_5DECCC[dword_5DD878 + (unsigned __int8)byte_5DD8CC[dword_5DD820 + (__ROR4__(v10, 6) & 0x1F)]]
                  | v12;
      *v8++ = __ROR4__(v12, 21);
      v13 = v9-- <= 1;
    }
    while ( !v13 );
    v8 = (_WORD *)((char *)v8 + dword_5DD81C);
    v13 = dword_5DD818-- <= 1;
  }
  while ( !v13 );
}
