// f1c  0x005425a0  size=171
int __thiscall sub_5425A0(_DWORD *this, int a2, int *a3)
{
  double v4; // st7
  int v5; // eax
  int v6; // edx
  int result; // eax
  int v8; // ecx
  float v9[3]; // [esp+8h] [ebp-Ch] BYREF

  (*(void (__cdecl **)(int, int, float *, _DWORD *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, a2, v9, this + 87);
  v4 = 1.0 / v9[2];
  *a3 = sub_587BDC(v4);
  a3[1] = sub_587BDC(v4);
  v5 = *a3;
  if ( *a3 <= this[26] )
    v5 = this[26];
  *a3 = v5;
  v6 = this[26];
  if ( v5 >= v6 + this[21] )
    v5 = v6 + this[21];
  *a3 = v5;
  result = a3[1];
  if ( result <= this[25] )
    result = this[25];
  a3[1] = result;
  v8 = this[25] + this[22];
  if ( result >= v8 )
    a3[1] = v8;
  else
    a3[1] = result;
  return result;
}
