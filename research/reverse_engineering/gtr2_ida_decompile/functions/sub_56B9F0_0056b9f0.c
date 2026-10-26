char __thiscall sub_56B9F0(_DWORD *this, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  float v4; // edx
  int v5; // eax
  int v6; // ecx
  float v7; // eax
  float v8; // edx
  float *v9; // eax
  float v10; // ecx
  float v11; // edx
  float *v12; // eax
  float v13; // ecx
  float v14; // edx
  float v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // ebp
  int v19; // esi
  float v22; // [esp+18h] [ebp-60h] BYREF
  float v23; // [esp+1Ch] [ebp-5Ch]
  float v24; // [esp+20h] [ebp-58h]
  float v25; // [esp+24h] [ebp-54h] BYREF
  float v26; // [esp+28h] [ebp-50h]
  float v27; // [esp+2Ch] [ebp-4Ch]
  float v28; // [esp+30h] [ebp-48h] BYREF
  float v29; // [esp+34h] [ebp-44h]
  float v30; // [esp+38h] [ebp-40h]
  float v31[2]; // [esp+3Ch] [ebp-3Ch] BYREF
  int v32; // [esp+44h] [ebp-34h]
  float v33[3]; // [esp+48h] [ebp-30h] BYREF
  float v34[9]; // [esp+54h] [ebp-24h] BYREF

  v2 = *(_DWORD **)(a2 + 112);
  v3 = this;
  if ( v2 )
  {
    LOBYTE(v2) = *(_BYTE *)(a2 + 176);
    if ( (_BYTE)v2 )
    {
      v2 = (_DWORD *)this[637];
      if ( v2 )
      {
        v4 = *(float *)(a2 + 120);
        v5 = *(_DWORD *)(a2 + 124);
        v31[0] = *(float *)(a2 + 116);
        v6 = *(_DWORD *)(a2 + 292);
        v32 = v5;
        v7 = *(float *)(a2 + 224);
        v31[1] = v4;
        v8 = *(float *)(a2 + 212);
        v32 = v6;
        v22 = v8;
        v23 = v7;
        v24 = 0.0;
        if ( sub_4011C0(&v22) )
        {
          LOBYTE(v2) = off_16C9454(a2);
        }
        else
        {
          sub_401380(&v22);
          v28 = 0.0;
          v29 = 0.0;
          v30 = 1.0;
          v9 = sub_401320(&v22, &v28, v33);
          v10 = v9[1];
          v25 = *v9;
          v11 = v9[2];
          v26 = v10;
          v27 = v11;
          if ( sub_4011C0(&v25) )
          {
            v25 = 1.0;
            v26 = 0.0;
            v27 = 0.0;
          }
          else
          {
            sub_401380(&v25);
          }
          v12 = sub_401320(&v25, &v22, v33);
          v13 = *v12;
          v14 = v12[1];
          v15 = v12[2];
          v28 = v13;
          v30 = v15;
          v29 = v14;
          v34[2] = v13;
          v34[5] = v14;
          v34[0] = v25;
          v34[1] = v22;
          v34[8] = v15;
          v16 = *(_DWORD *)(a2 + 284);
          v34[3] = v26;
          v34[4] = v23;
          v17 = 0;
          v34[6] = v27;
          v34[7] = v24;
          if ( v16 > 0 )
          {
            v18 = 0;
            do
            {
              v19 = v18 + *(_DWORD *)(a2 + 288);
              sub_416420(v34, v31, (float *)(v19 + 12), &v28);
              ++v17;
              v18 += 32;
              **(float **)(v19 + 28) = (v28 - *(float *)v19) * *(float *)(v19 + 24) + *(float *)v19;
              *(float *)(*(_DWORD *)(v19 + 28) + 4) = (v29 - *(float *)(v19 + 4)) * *(float *)(v19 + 24)
                                                    + *(float *)(v19 + 4);
              *(float *)(*(_DWORD *)(v19 + 28) + 8) = (v30 - *(float *)(v19 + 8)) * *(float *)(v19 + 24)
                                                    + *(float *)(v19 + 8);
            }
            while ( v17 < *(_DWORD *)(a2 + 284) );
            v3 = this;
          }
          v2 = (_DWORD *)v3[637];
          *v2 &= ~0x800u;
        }
      }
    }
  }
  return (char)v2;
}
