void *__thiscall sub_5991C3(_DWORD *this, void *a2, int a3, int a4, int a5)
{
  int v6; // eax
  _DWORD *v7; // esi
  void *result; // eax
  _DWORD v9[6]; // [esp+8h] [ebp-20h] BYREF
  _DWORD v10[2]; // [esp+20h] [ebp-8h] BYREF

  v6 = this[20];
  if ( !v6 || sub_587F64(v6, a3, a4) || sub_58801D(this[20], (int)v10) )
  {
    v7 = (_DWORD *)sub_59942B(-1);
  }
  else
  {
    v9[0] = 0;
    v9[2] = v10[0];
    v9[3] = v10[1];
    v9[4] = this[16];
    v7 = v9;
  }
  result = a2;
  qmemcpy(a2, v7, 0x18u);
  return result;
}
