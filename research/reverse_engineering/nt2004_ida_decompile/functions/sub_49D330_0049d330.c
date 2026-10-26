int __thiscall sub_49D330(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v11; // [esp+8h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-8h] BYREF
  int v13; // [esp+10h] [ebp-4h] BYREF

  v7 = sub_49CC70(this, a2);
  if ( !v7 )
    return 0;
  sub_4B04D0(&a2, &v11);
  sub_4B0560(&v12, &v13);
  v8 = a6;
  v9 = a4;
  if ( a2 != a6 || v11 != a4 )
    sub_4AFF20(a6, a4);
  if ( v12 != a7 - v8 || v13 != a5 - v9 )
    sub_4B0090(a7 - v8, COERCE_FLOAT(a5 - v9));
  return sub_4B03B0(v7);
}
