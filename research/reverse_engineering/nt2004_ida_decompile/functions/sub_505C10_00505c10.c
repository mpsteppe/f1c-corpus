_DWORD *__fastcall sub_505C10(int a1, int a2, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  int v7; // eax
  int v9; // esi
  bool v10; // zf
  _DWORD *result; // eax
  int v12; // [esp+Ch] [ebp+4h]
  _DWORD *v13; // [esp+10h] [ebp+8h]

  v7 = sub_592CD0(a1);
  v9 = v7;
  v10 = v7 == 0;
  result = a4;
  *a4 = 0;
  *a3 = 0;
  if ( !v10 )
  {
    v13 = *(_DWORD **)(v9 + 172);
    v12 = *(_DWORD *)(v9 + 176);
    *(_DWORD *)(v9 + 172) = a5;
    *(_DWORD *)(v9 + 176) = a6;
    sub_5A41F0(a2, a3, result, 1);
    result = v13;
    *(_DWORD *)(v9 + 172) = v13;
    *(_DWORD *)(v9 + 176) = v12;
  }
  return result;
}
