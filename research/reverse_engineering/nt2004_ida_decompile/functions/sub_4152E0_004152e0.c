int __fastcall sub_4152E0(int a1, float *a2)
{
  int result; // eax
  int v4; // esi
  int v5; // ebp
  int j; // edi
  float *v7; // eax
  int i; // [esp+8h] [ebp-Ch]
  int v9; // [esp+10h] [ebp-4h]

  result = sub_59EFD0(a1);
  v9 = result;
  for ( i = 0; i < v9; ++i )
  {
    v4 = sub_59EFF0(i);
    v5 = sub_59CB20(v4);
    for ( j = 0; j < v5; v7[2] = v7[2] - a2[2] )
    {
      v7 = (float *)sub_59CB40(j++);
      *v7 = *v7 - *a2;
      v7[1] = v7[1] - a2[1];
    }
    *(_DWORD *)(v4 + 20) &= 0xFEFFFFDF;
    sub_59BF20(COERCE_FLOAT(1));
    sub_59CC90(v4);
    sub_59BA20(0);
    result = i + 1;
  }
  return result;
}
