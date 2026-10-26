// f1c  0x0040e1f0  size=178
int __fastcall sub_40E1F0(int a1, float *a2)
{
  int result; // eax
  int v4; // esi
  int v5; // ebp
  int j; // edi
  float *v7; // eax
  int i; // [esp+8h] [ebp-Ch]
  int v9; // [esp+10h] [ebp-4h]

  result = sub_54C210();
  v9 = result;
  for ( i = 0; i < v9; ++i )
  {
    v4 = sub_54C230(i);
    v5 = sub_54E100(v4);
    for ( j = 0; j < v5; v7[2] = v7[2] - a2[2] )
    {
      v7 = (float *)sub_54E120(j++);
      *v7 = *v7 - *a2;
      v7[1] = v7[1] - a2[1];
    }
    *(_DWORD *)(v4 + 20) &= 0xFEFFFFDF;
    sub_54D520(COERCE_FLOAT(1));
    sub_54E270(v4);
    sub_54D080(0);
    result = i + 1;
  }
  return result;
}
