char __thiscall sub_56BCC0(int this, int a2, float *a3, float *a4, float *a5, float a6, int a7)
{
  int v7; // edi
  int v8; // esi
  double v9; // st7
  double v10; // st7
  char result; // al
  _DWORD *i; // ebx
  float v13; // [esp+4h] [ebp-18h]
  float v14; // [esp+8h] [ebp-14h]
  float v15; // [esp+Ch] [ebp-10h]
  float v16[3]; // [esp+10h] [ebp-Ch] BYREF

  v7 = *(_DWORD *)(this + 3868);
  v8 = 0;
  v13 = *a3 - *(float *)(this + 76);
  v9 = a3[1] - *(float *)(this + 80);
  v16[0] = v13;
  v14 = v9;
  v10 = a3[2];
  v16[1] = v14;
  v15 = v10 - *(float *)(this + 84);
  result = LOBYTE(v15);
  v16[2] = v15;
  if ( v7 > 0 )
  {
    for ( i = (_DWORD *)(this + 3872); ; i += 187 )
    {
      result = sub_56A040(i, v16);
      if ( result )
        break;
      if ( ++v8 >= v7 )
        return result;
    }
    return sub_417460(a2, a3, a4, a5, a6, a7);
  }
  return result;
}
