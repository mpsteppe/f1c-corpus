char __thiscall sub_4DF290(_DWORD *this, int a2, int a3, int a4, int a5, int a6, char a7)
{
  int v8; // esi
  const char *v9; // edi
  float v10; // ebx
  char *v11; // eax
  const CHAR *v12; // ecx
  float v14; // [esp+8h] [ebp-8h]
  int v15; // [esp+Ch] [ebp-4h]

  if ( !a2 || (v8 = sub_4DEDE0(this, a2)) == 0 )
  {
    v8 = this[91];
    if ( !v8 )
      return 0;
  }
  v9 = (const char *)a3;
  if ( !a3 )
    return 0;
  sub_4DDEA0(&a2, &a3);
  v10 = *(float *)(v8 + 20);
  *(float *)&v15 = (double)a4 * 0.00125;
  v14 = (double)a5 * 0.0016666667;
  *(float *)&a5 = (double)a2 * 0.00125 * *(float *)(v8 + 24);
  *(float *)&a4 = (double)a3 * 0.0016666667 * *(float *)(v8 + 28);
  if ( a7 )
    v11 = sub_41D840(&byte_91CC38, v9);
  else
    v11 = (char *)v9;
  v12 = *(const CHAR **)(v8 + 8);
  if ( !v12 )
    v12 = WindowName;
  sub_5680F0((int)v12, (int)v11, v15, v14, v10, a6, a5, a4, 0);
  return 1;
}
