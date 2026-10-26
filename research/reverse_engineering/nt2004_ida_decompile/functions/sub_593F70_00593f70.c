int __thiscall sub_593F70(int this, int a2, int *a3)
{
  double v4; // st7
  double v5; // st6
  int v6; // eax
  int v7; // edx
  int result; // eax
  int v9; // ecx
  float v10[3]; // [esp+8h] [ebp-Ch] BYREF

  (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(dword_7E8E58, a2, v10, this + 348);
  v4 = 1.0 / v10[2];
  v5 = v10[1];
  *a3 = (__int64)(v10[0] * *(float *)(this + 12) * v4 + *(float *)(this + 20));
  a3[1] = (__int64)(v5 * *(float *)(this + 16) * v4 + *(float *)(this + 24));
  v6 = *a3;
  if ( *a3 <= *(_DWORD *)(this + 104) )
    v6 = *(_DWORD *)(this + 104);
  *a3 = v6;
  v7 = *(_DWORD *)(this + 104);
  if ( v6 >= v7 + *(_DWORD *)(this + 84) )
    v6 = v7 + *(_DWORD *)(this + 84);
  *a3 = v6;
  result = a3[1];
  if ( result <= *(_DWORD *)(this + 100) )
    result = *(_DWORD *)(this + 100);
  a3[1] = result;
  v9 = *(_DWORD *)(this + 100) + *(_DWORD *)(this + 88);
  if ( result >= v9 )
    a3[1] = v9;
  else
    a3[1] = result;
  return result;
}
