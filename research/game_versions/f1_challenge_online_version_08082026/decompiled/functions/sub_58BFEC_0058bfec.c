_BYTE *__cdecl sub_58BFEC(double *a1, _BYTE *a2, int a3, int a4)
{
  int v4; // esi
  const char *v5; // edi
  double v7; // [esp+0h] [ebp-44h]
  _BYTE v8[24]; // [esp+1Ch] [ebp-28h] BYREF
  int v9; // [esp+34h] [ebp-10h] BYREF
  int v10; // [esp+38h] [ebp-Ch]

  v7 = *a1;
  sub_595621(SLOBYTE(v7), HIDWORD(v7), &v9, v8);
  v4 = v10 - 1;
  v5 = &a2[v9 == 45];
  sub_5955AA(v5, a3, &v9);
  if ( v10 - 1 < -4 || v10 - 1 >= a3 )
    return sub_58BE2E(a2, a3, a4, (int)&v9, 1);
  if ( v4 < v10 - 1 )
    v5[strlen(v5) - 1] = 0;
  return sub_58BF45(a2, a3, &v9, 1);
}
