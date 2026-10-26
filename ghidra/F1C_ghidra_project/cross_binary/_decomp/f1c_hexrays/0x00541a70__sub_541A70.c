// f1c  0x00541a70  size=245
int __thiscall sub_541A70(float *this)
{
  _BYTE *v2; // esi
  _DWORD *v3; // eax
  int v4; // edi
  _DWORD *v5; // ecx
  int v6; // edx
  int v7; // ebp
  float *v8; // esi
  float *v9; // edi
  int result; // eax
  double v11; // st7
  double v12; // st6
  float v13; // [esp+10h] [ebp-58h] BYREF
  float v14; // [esp+14h] [ebp-54h]
  float v15; // [esp+18h] [ebp-50h]
  _DWORD v16[3]; // [esp+1Ch] [ebp-4Ch] BYREF
  _BYTE v17[64]; // [esp+28h] [ebp-40h] BYREF

  v2 = v17;
  v3 = this + 87;
  v4 = 4;
  do
  {
    v5 = v2;
    v6 = 4;
    do
    {
      *v5 = *v3;
      v5 += 4;
      ++v3;
      --v6;
    }
    while ( v6 );
    v2 += 4;
    --v4;
  }
  while ( v4 );
  v7 = 0;
  v8 = this + 65;
  do
  {
    v9 = v8 - 2;
    result = (**(int (__cdecl ***)(int, int, int, _BYTE *))dword_8B8F24)(
               dword_8B8F24,
               (int)(v8 - 26),
               (int)(v8 - 2),
               v17);
    if ( v7 >= 4 )
    {
      *(float *)&v16[2] = *(v8 - 23);
      v16[1] = 0;
      v16[0] = 0;
      result = (*(int (__cdecl **)(int, _DWORD *, float *, _BYTE *))(*(_DWORD *)dword_8B8F24 + 4))(
                 dword_8B8F24,
                 v16,
                 &v13,
                 v17);
      v13 = v13 + this[9];
      v14 = v14 + this[10];
      v15 = v15 + this[11];
      v11 = v14 * *(v8 - 1) + v15 * *v8;
      v12 = v13;
    }
    else
    {
      v11 = *(v8 - 1) * this[10] + *v8 * this[11];
      v12 = this[9];
    }
    ++v7;
    v8 += 4;
    *(v8 - 3) = v11 + v12 * *v9;
  }
  while ( v7 < 6 );
  return result;
}
