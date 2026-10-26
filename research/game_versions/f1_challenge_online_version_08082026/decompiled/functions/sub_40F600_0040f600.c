int __thiscall sub_40F600(int this)
{
  char v2; // bl
  int v3; // eax
  _WORD *v4; // ebx
  int v5; // esi
  double v6; // st7
  double v7; // st7
  long double v8; // st6
  long double v9; // st5
  __int16 v10; // ax
  double v11; // st7
  __int16 v12; // ax
  double v13; // st7
  __int16 v14; // ax
  __int16 v15; // ax
  double v16; // st7
  __int16 v17; // ax
  double v18; // st7
  __int16 v19; // ax
  __int16 v20; // ax
  double v21; // st7
  __int16 v22; // ax
  double v23; // st7
  int result; // eax
  float v25; // [esp+18h] [ebp-20h]
  int v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  float v28; // [esp+1Ch] [ebp-1Ch]
  float v29; // [esp+1Ch] [ebp-1Ch]
  float v30; // [esp+1Ch] [ebp-1Ch]
  float v31; // [esp+1Ch] [ebp-1Ch]
  float v32; // [esp+1Ch] [ebp-1Ch]
  float v33; // [esp+1Ch] [ebp-1Ch]
  float v34; // [esp+1Ch] [ebp-1Ch]
  float v35; // [esp+1Ch] [ebp-1Ch]
  float v36[3]; // [esp+20h] [ebp-18h] BYREF
  float v37; // [esp+2Ch] [ebp-Ch]
  float v38; // [esp+30h] [ebp-8h]
  float v39; // [esp+34h] [ebp-4h]

  v2 = *(_BYTE *)(this + 10);
  *(_BYTE *)(this + 10) = 0;
  v3 = v2 != 0 ? 0 : 2;
  v4 = (_WORD *)dword_8AAE64;
  if ( dword_83EE60 < 1023 )
  {
    ++dword_83EE60;
    dword_8AAE64 += 432;
  }
  switch ( *(_DWORD *)(this + 28) )
  {
    case 0:
      sub_4B33B0(1, 1, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
      goto LABEL_10;
    case 1:
      sub_4B33B0(1, 2, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
      goto LABEL_10;
    case 2:
      sub_4B33B0(1, 3, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
      goto LABEL_10;
    case 3:
      sub_4B33B0(1, 4, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
      goto LABEL_10;
    case 4:
      sub_4B33B0(1, 5, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
      goto LABEL_10;
    case 5:
      sub_4B33B0(1, 6, 29, *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580), *(float *)(*(_DWORD *)(this + 32) + 36), v3);
LABEL_10:
      v5 = *(_DWORD *)(this + 32) + 212;
      break;
    default:
      v5 = v27;
      break;
  }
  v4[4] = *(_WORD *)(this + 8);
  v36[0] = *(double *)(v5 + 4);
  v36[1] = *(double *)(v5 + 12);
  v36[2] = *(double *)(v5 + 20);
  sub_4B21F0(v36);
  v6 = *(double *)(v5 + 68);
  sub_588570();
  v7 = -v6;
  if ( fabs(*(double *)(v5 + 68)) == 1.0 )
  {
    v8 = atan2(-*(double *)(v5 + 76), *(double *)(v5 + 28));
    v9 = 0.0;
  }
  else
  {
    v8 = atan2(*(double *)(v5 + 44), *(double *)(v5 + 92));
    v9 = atan2(*(double *)(v5 + 52), *(double *)(v5 + 60));
  }
  v37 = v7;
  v38 = v8;
  v39 = v9;
  if ( v37 <= 15.999 )
  {
    if ( v37 >= -15.999 )
    {
      v25 = v37 * 2048.0;
      v10 = (int)v25;
    }
    else
    {
      v10 = -32767;
    }
  }
  else
  {
    v10 = 0x7FFF;
  }
  v11 = v38;
  *(_WORD *)((char *)v4 + 19) = v10;
  if ( v11 <= 15.999 )
  {
    if ( v38 >= -15.999 )
    {
      v28 = v38 * 2048.0;
      v12 = (int)v28;
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
  v13 = v39;
  *(_WORD *)((char *)v4 + 21) = v12;
  if ( v13 <= 15.999 )
  {
    if ( v39 >= -15.999 )
    {
      v29 = v39 * 2048.0;
      v14 = (int)v29;
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
  *(_WORD *)((char *)v4 + 23) = v14;
  v37 = *(double *)(v5 + 100);
  v38 = *(double *)(v5 + 108);
  v39 = *(double *)(v5 + 116);
  if ( v37 <= 511.98001 )
  {
    if ( v37 >= -511.98001 )
    {
      v30 = v37 * 64.0;
      v15 = (int)v30;
    }
    else
    {
      v15 = -32767;
    }
  }
  else
  {
    v15 = 0x7FFF;
  }
  v16 = v38;
  *(_WORD *)((char *)v4 + 25) = v15;
  if ( v16 <= 511.98001 )
  {
    if ( v38 >= -511.98001 )
    {
      v31 = v38 * 64.0;
      v17 = (int)v31;
    }
    else
    {
      v17 = -32767;
    }
  }
  else
  {
    v17 = 0x7FFF;
  }
  v18 = v39;
  *(_WORD *)((char *)v4 + 27) = v17;
  if ( v18 <= 511.98001 )
  {
    if ( v39 >= -511.98001 )
    {
      v32 = v39 * 64.0;
      v19 = (int)v32;
    }
    else
    {
      v19 = -32767;
    }
  }
  else
  {
    v19 = 0x7FFF;
  }
  *(_WORD *)((char *)v4 + 29) = v19;
  v37 = *(double *)(v5 + 124);
  v38 = *(double *)(v5 + 132);
  v39 = *(double *)(v5 + 140);
  if ( v37 <= 255.99001 )
  {
    if ( v37 >= -255.99001 )
    {
      v33 = v37 * 128.0;
      v20 = (int)v33;
    }
    else
    {
      v20 = -32767;
    }
  }
  else
  {
    v20 = 0x7FFF;
  }
  v21 = v38;
  *(_WORD *)((char *)v4 + 31) = v20;
  if ( v21 <= 255.99001 )
  {
    if ( v38 >= -255.99001 )
    {
      v34 = v38 * 128.0;
      v22 = (int)v34;
    }
    else
    {
      v22 = -32767;
    }
  }
  else
  {
    v22 = 0x7FFF;
  }
  v23 = v39;
  *(_WORD *)((char *)v4 + 33) = v22;
  if ( v23 <= 255.99001 )
  {
    if ( v39 >= -255.99001 )
    {
      v35 = v39 * 128.0;
      v26 = (int)v35;
      result = (__int16)v26;
      *(_WORD *)((char *)v4 + 35) = v26;
    }
    else
    {
      result = -32767;
      *(_WORD *)((char *)v4 + 35) = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    *(_WORD *)((char *)v4 + 35) = 0x7FFF;
  }
  return result;
}
