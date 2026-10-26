int __fastcall sub_5BE2D0(int a1, int a2)
{
  int *v2; // esi
  int v3; // edi
  int v4; // ecx
  void *v5; // eax
  int result; // eax
  int v9; // edx
  const void *v10; // [esp-8h] [ebp-10h]
  size_t v11; // [esp-4h] [ebp-Ch]

  sub_5BE190(a1, a2);
  v9 = a2;
  v2 = (int *)a1;
  v3 = v9;
  if ( v9 < *v2 - 1 )
  {
    v11 = v2[2] * (*v2 - v9 - 1);
    v10 = (const void *)sub_5BE1B0((int)v2, v9 + 1);
    v5 = (void *)sub_5BE1B0(v4, v3);
    memcpy(v5, v10, v11);
  }
  result = *v2 - 1;
  *v2 = result;
  return result;
}
