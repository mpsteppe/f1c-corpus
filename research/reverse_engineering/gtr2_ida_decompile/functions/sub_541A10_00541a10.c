int __thiscall sub_541A10(float *this)
{
  int v1; // esi
  float v4; // [esp+18h] [ebp-18h] BYREF
  float v5; // [esp+1Ch] [ebp-14h] BYREF
  float v6; // [esp+20h] [ebp-10h] BYREF
  float v7; // [esp+24h] [ebp-Ch]
  float v8; // [esp+28h] [ebp-8h]
  float v9; // [esp+2Ch] [ebp-4h]

  v1 = dword_BE1D0C;
  if ( dword_BE1D0C )
  {
    (*(void (__thiscall **)(int, float *, float *, float *))(*(_DWORD *)dword_BE1D0C + 36))(dword_BE1D0C, &v4, &v5, &v6);
    v7 = v4 - this[2];
    v8 = v5 - this[3];
    v9 = v6 - this[4];
    if ( v9 * v9 + v8 * v8 + v7 * v7 < 100.0 )
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v1 + 40))(v1, 1, 1065353216, 1051931443);
  }
  return 0;
}
