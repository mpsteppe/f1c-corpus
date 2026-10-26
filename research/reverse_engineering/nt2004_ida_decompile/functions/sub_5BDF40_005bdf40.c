_DWORD *__fastcall sub_5BDF40(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // edi
  int v8; // esi

  v7 = malloc(0x14u);
  v8 = 0;
  for ( *v7 = malloc(4 * a2); v8 < a2; *(_DWORD *)(*v7 + 4 * v8 - 4) = sub_5BE100(a6) )
    ++v8;
  v7[2] = a6;
  v7[1] = a2;
  v7[4] = a5;
  v7[3] = a4;
  return v7;
}
