int __thiscall sub_416750(int this)
{
  int v2; // eax
  _WORD *v3; // ebx
  int v4; // esi
  int v5; // eax
  double *v6; // ecx
  __int16 v7; // ax
  double v8; // st7
  __int16 v9; // ax
  double v10; // st7
  __int16 v11; // ax
  __int16 v12; // ax
  double v13; // st7
  __int16 v14; // ax
  double v15; // st7
  int result; // eax
  float v17; // [esp+14h] [ebp-54h]
  int v18; // [esp+14h] [ebp-54h]
  int v19; // [esp+18h] [ebp-50h]
  float v20; // [esp+18h] [ebp-50h]
  float v21; // [esp+18h] [ebp-50h]
  float v22; // [esp+18h] [ebp-50h]
  float v23; // [esp+18h] [ebp-50h]
  float v24; // [esp+18h] [ebp-50h]
  float v25[3]; // [esp+1Ch] [ebp-4Ch] BYREF
  float v26; // [esp+28h] [ebp-40h]
  float v27; // [esp+2Ch] [ebp-3Ch]
  float v28; // [esp+30h] [ebp-38h]
  _BYTE v29[16]; // [esp+34h] [ebp-34h] BYREF
  _BYTE v30[36]; // [esp+44h] [ebp-24h] BYREF

  v2 = *(_DWORD *)(this + 12);
  *(_DWORD *)(this + 12) = 1;
  v3 = (_WORD *)dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  switch ( *(_DWORD *)(this + 32) )
  {
    case 0:
      sub_4D0D00(1, 1, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
      goto LABEL_10;
    case 1:
      sub_4D0D00(1, 2, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
      goto LABEL_10;
    case 2:
      sub_4D0D00(1, 3, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
      goto LABEL_10;
    case 3:
      sub_4D0D00(1, 4, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
      goto LABEL_10;
    case 4:
      sub_4D0D00(1, 5, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
      goto LABEL_10;
    case 5:
      sub_4D0D00(1, 6, 26, *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248), *(float *)(*(_DWORD *)(this + 36) + 36), v2);
LABEL_10:
      v4 = *(_DWORD *)(this + 36) + 216;
      break;
    default:
      v4 = v19;
      break;
  }
  v3[4] = *(_WORD *)(this + 8);
  v25[0] = *(double *)(v4 + 4);
  v25[1] = *(double *)(v4 + 12);
  v25[2] = *(double *)(v4 + 20);
  sub_4CF5A0(v25);
  v5 = 0;
  v6 = (double *)(v4 + 28);
  do
  {
    ++v5;
    *(float *)&v29[4 * v5 + 12] = *v6++;
  }
  while ( v5 < 9 );
  sub_579200(v30, v29);
  sub_4CF720(v29);
  v26 = *(double *)(v4 + 100);
  v27 = *(double *)(v4 + 108);
  v28 = *(double *)(v4 + 116);
  if ( v26 <= 511.98001 )
  {
    if ( v26 >= -511.98001 )
    {
      v17 = v26 * 64.0;
      v7 = (int)v17;
    }
    else
    {
      v7 = -32767;
    }
  }
  else
  {
    v7 = 0x7FFF;
  }
  v8 = v27;
  v3[11] = v7;
  if ( v8 <= 511.98001 )
  {
    if ( v27 >= -511.98001 )
    {
      v20 = v27 * 64.0;
      v9 = (int)v20;
    }
    else
    {
      v9 = -32767;
    }
  }
  else
  {
    v9 = 0x7FFF;
  }
  v10 = v28;
  v3[12] = v9;
  if ( v10 <= 511.98001 )
  {
    if ( v28 >= -511.98001 )
    {
      v21 = v28 * 64.0;
      v11 = (int)v21;
    }
    else
    {
      v11 = -32767;
    }
  }
  else
  {
    v11 = 0x7FFF;
  }
  v3[13] = v11;
  v26 = *(double *)(v4 + 124);
  v27 = *(double *)(v4 + 132);
  v28 = *(double *)(v4 + 140);
  if ( v26 <= 255.99001 )
  {
    if ( v26 >= -255.99001 )
    {
      v22 = v26 * 128.0;
      v12 = (int)v22;
    }
    else
    {
      v12 = -32767;
    }
  }
  else
  {
    v12 = 0x7FFF;
  }
  v13 = v27;
  v3[14] = v12;
  if ( v13 <= 255.99001 )
  {
    if ( v27 >= -255.99001 )
    {
      v23 = v27 * 128.0;
      v14 = (int)v23;
    }
    else
    {
      v14 = -32767;
    }
  }
  else
  {
    v14 = 0x7FFF;
  }
  v15 = v28;
  v3[15] = v14;
  if ( v15 <= 255.99001 )
  {
    if ( v28 >= -255.99001 )
    {
      v24 = v28 * 128.0;
      v18 = (int)v24;
      result = (__int16)v18;
      v3[16] = v18;
    }
    else
    {
      result = -32767;
      v3[16] = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    v3[16] = 0x7FFF;
  }
  return result;
}
