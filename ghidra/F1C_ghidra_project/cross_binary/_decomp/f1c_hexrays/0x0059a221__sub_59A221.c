// f1c  0x0059a221  size=175
void *__thiscall sub_59A221(_DWORD *this, int *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // edi
  int v11; // eax
  _DWORD *v12; // ecx
  int *v13; // esi
  void *result; // eax
  int v15; // [esp+8h] [ebp-8h] BYREF
  int v16; // [esp+Ch] [ebp-4h]

  v15 = a5;
  v10 = a3;
  v11 = this[20];
  v16 = a6;
  if ( !v11 || sub_59BAE8(v11, &v15) || v10 && sub_587F64(this[20], v10, 1) || sub_58801D(this[20], (int)&v15) )
  {
    v13 = sub_59942B(&a3, -1);
  }
  else
  {
    v12 = (_DWORD *)this[17];
    if ( v12 )
    {
      this[16] = a7;
      sub_599348(v12, 0, 0xFFFFFFFF);
    }
    a3 = 0;
    a5 = v15;
    a6 = v16;
    a7 = this[16];
    v13 = &a3;
  }
  result = a2;
  qmemcpy(a2, v13, 0x18u);
  return result;
}
