char __thiscall sub_4AE3F0(_DWORD *this, char *String2, int a3, int a4, int a5, int a6)
{
  const char **v7; // esi
  int v8; // edi
  const char *v9; // eax
  double v10; // st7
  CHAR *v11; // esi
  CHAR *v12; // ecx
  float v14; // [esp+8h] [ebp-8h]
  float v15; // [esp+Ch] [ebp-4h]

  if ( !String2 || (v7 = sub_4AD420(this, String2)) == 0 )
  {
    v7 = (const char **)this[91];
    if ( !v7 )
      return 0;
  }
  v8 = a3;
  if ( !a3 )
    return 0;
  sub_4AB430(&String2, &a3);
  v9 = v7[5];
  v15 = (double)a4 * 0.00125;
  v14 = (double)a5 * 0.0016666667;
  *(float *)&a5 = (double)(int)String2 * 0.00125 * *((float *)v7 + 6);
  v10 = (double)a3 * 0.0016666667 * *((float *)v7 + 7);
  v11 = (CHAR *)v7[2];
  *(float *)&a4 = v10;
  v12 = v11;
  if ( !v11 )
    v12 = &byte_629120;
  sub_505D00(v12, v8, LODWORD(v15), LODWORD(v14), v9, a6, a5, a4, 0);
  return 1;
}
