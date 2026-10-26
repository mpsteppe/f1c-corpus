// f1c  0x004b3dc0  size=624
int __thiscall sub_4B3DC0(_BYTE *this)
{
  int result; // eax
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int i; // ecx
  float *v8; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st7
  int j; // ecx
  int v16; // edi
  int v17; // ebx
  char v18; // cl
  float v19; // [esp+Ch] [ebp-3F4h]
  float v20; // [esp+Ch] [ebp-3F4h]
  float v21; // [esp+10h] [ebp-3F0h]
  float v22; // [esp+14h] [ebp-3ECh]
  float v23; // [esp+1Ch] [ebp-3E4h]
  float v24; // [esp+20h] [ebp-3E0h]
  float v25; // [esp+24h] [ebp-3DCh]
  int v26; // [esp+28h] [ebp-3D8h] BYREF
  float v27; // [esp+2Ch] [ebp-3D4h]
  int v28; // [esp+30h] [ebp-3D0h]
  float v29[9]; // [esp+34h] [ebp-3CCh] BYREF
  _BYTE v30[520]; // [esp+58h] [ebp-3A8h] BYREF
  float v31[104]; // [esp+260h] [ebp-1A0h] BYREF

  result = sub_40C870(&dword_5EA510);
  v3 = dword_5C329C;
  if ( *(_DWORD *)(result + 112) || dword_5C329C <= dword_7CFC8C )
  {
    if ( dword_5C329C > 0 )
    {
      result = 16843009;
      memset(v30, 1u, dword_5C329C);
    }
  }
  else
  {
    if ( !dword_7C54E0 )
      return result;
    v23 = *(float *)(dword_7C54E0 + 13536);
    v24 = *(float *)(dword_7C54E0 + 13540);
    v4 = result + 24;
    v5 = *(_DWORD *)v4;
    v25 = *(float *)(dword_7C54E0 + 13544);
    v27 = *(float *)(v4 + 4);
    v26 = v5;
    v28 = *(_DWORD *)(v4 + 8);
    v27 = 3.1415927 - v27;
    sub_566E40(&v26, v29);
    v6 = dword_5C329C;
    for ( i = 0; i < v6; *(_DWORD *)&v30[4 * i + 516] = *(_DWORD *)&v30[4 * i + 100] )
    {
      v8 = (float *)dword_7C54F0[i];
      v9 = v8[3384];
      v8 += 3384;
      v10 = v9 - v23;
      v11 = v8[1] - v24;
      v12 = v8[2] - v25;
      v21 = v29[6] * v12 + v29[3] * v11 + v10 * v29[0];
      v22 = v29[7] * v12 + v29[4] * v11 + v29[1] * v10;
      v13 = v29[5] * v11 + v29[2] * v10 + v29[8] * v12;
      v14 = v13;
      v19 = v22 * v22 + v21 * v21;
      *(float *)&v30[4 * i + 104] = v19;
      if ( v13 < 0.0 )
        v14 = v13 * 0.40000001;
      ++i;
      *(float *)&v30[4 * i + 100] = v14 * v14 + v19;
    }
    result = sub_5890AA(v31, v6, 4, sub_4B3D70);
    v3 = dword_5C329C;
    v20 = v31[dword_7CFC8C];
    for ( j = 0; j < v3; ++j )
    {
      result = *(float *)&v30[4 * j + 104] < (double)v20;
      v30[j] = result;
    }
  }
  v16 = 0;
  if ( v3 > 0 )
  {
    v17 = this - v30;
    do
    {
      v18 = v30[v16];
      result = (int)&v30[v16];
      if ( v18 != v30[v16 + v17] )
      {
        *(_BYTE *)(v17 + result) = v18;
        if ( v18 )
        {
          result = sub_4E0ED0(*(_DWORD *)(dword_7C54F0[v16] + 4180));
        }
        else
        {
          sub_54C030(0, 0, 1, 0);
          sub_54C030(1, 0, 0, 0);
          result = sub_54C1B0(0, 1, 0);
        }
        v3 = dword_5C329C;
      }
      ++v16;
    }
    while ( v16 < v3 );
  }
  return result;
}
