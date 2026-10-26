void __thiscall sub_55EBA0(_DWORD *this, float *a2)
{
  int v3; // edi
  int v5; // ebp
  int v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  long double v10; // st5
  double v11; // st7
  double v12; // st6
  double v13; // st6
  bool v14; // cc
  float v15; // [esp+10h] [ebp-30h]
  int v16; // [esp+14h] [ebp-2Ch]
  int v17; // [esp+18h] [ebp-28h]
  float v18; // [esp+1Ch] [ebp-24h]
  float v19; // [esp+24h] [ebp-1Ch]
  float v20; // [esp+28h] [ebp-18h] BYREF
  float v21; // [esp+2Ch] [ebp-14h]
  float v22; // [esp+30h] [ebp-10h]
  float v23[3]; // [esp+34h] [ebp-Ch] BYREF
  int v24; // [esp+44h] [ebp+4h]

  v3 = 0;
  if ( a2 )
  {
    v5 = this[3];
    if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this[6] + 20)) != 0 )
    {
      v24 = v5 + 28;
      v6 = 16;
    }
    else
    {
      v24 = v5 + 12;
      v6 = 12;
    }
    v16 = 0;
    if ( (int)this[2] > 0 )
    {
      v17 = 4 * v6;
      do
      {
        (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          v5,
          v23,
          *(_DWORD *)(this[6] + 312) + 416);
        (**(void (__cdecl ***)(int, int, float *, int))dword_8B8F24)(
          dword_8B8F24,
          v24,
          &v20,
          *(_DWORD *)(this[6] + 312) + 276);
        v7 = v23[0] + a2[9];
        v8 = v23[1] + a2[10];
        v9 = v23[2] + a2[11];
        v19 = v9;
        v10 = 1.0 / sqrt(v9 * v19 + v8 * v8 + v7 * v7);
        v15 = v10;
        v18 = v10 * v7;
        v11 = v15 * v8;
        v12 = v15 * v19 * v22 + v21 * v11 + v20 * v18;
        v13 = v12 + v12;
        *(float *)(this[8] + v3 + 40) = (v20 * v13 - v18) * 0.5 + 0.5;
        *(float *)(this[8] + v3 + 44) = (v21 * v13 - v11) * 0.5 + 0.5;
        v5 += v17;
        v3 += 64;
        v14 = v16 + 1 < this[2];
        v24 += v17;
        ++v16;
      }
      while ( v14 );
    }
  }
}

