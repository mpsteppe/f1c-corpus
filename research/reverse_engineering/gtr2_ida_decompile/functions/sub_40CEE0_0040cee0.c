void __thiscall sub_40CEE0(void *this)
{
  int v2; // ebx
  float *v3; // edi
  double v4; // st7
  double v5; // st6
  long double v6; // st5
  long double v7; // st4
  long double v8; // st5
  float v9; // eax
  float v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ebp
  float v14; // [esp+0h] [ebp-38h]
  float v15; // [esp+4h] [ebp-34h]
  float v16; // [esp+4h] [ebp-34h]
  float v17; // [esp+18h] [ebp-20h]
  float v18; // [esp+1Ch] [ebp-1Ch]
  float v19; // [esp+20h] [ebp-18h] BYREF
  float v20; // [esp+24h] [ebp-14h]
  float v21; // [esp+28h] [ebp-10h]
  float v22; // [esp+2Ch] [ebp-Ch]
  float v23; // [esp+30h] [ebp-8h]
  float v24; // [esp+34h] [ebp-4h]

  v2 = *((_DWORD *)this + 6);
  v17 = *((float *)this + 16);
  v13 = dword_16C9A28;
  v3 = (float *)(*((_DWORD *)this + 21) + 88);
  v18 = 0.5;
  if ( *((_DWORD *)this + 5) == dword_16C9A28 )
    v13 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 28))(this) != 1;
  v4 = *((float *)this + 10) - *v3;
  v20 = *((float *)this + 11) - v3[1];
  v5 = *((float *)this + 12) - v3[2];
  v6 = sqrt(v5 * v5 + v20 * v20 + v4 * v4);
  if ( (v2 & 8) == 0 )
  {
    v7 = v6 * *((float *)this + 7) + *((float *)this + 8);
    if ( v7 >= 1.0 )
      v17 = ((1.0 / v7 * (1.0 / v7) * (1.0 / v7) - 1.0 / v7) * *((float *)this + 9) + 1.0 / v7) * *((float *)this + 16);
    else
      v17 = *((float *)this + 16);
  }
  if ( v6 <= 0.0 )
    v8 = 1.0;
  else
    v8 = 1.0 / v6;
  v22 = v8 * v4;
  v19 = v22;
  v23 = v20 * v8;
  v20 = v23;
  v24 = v8 * v5;
  v21 = v24;
  if ( !v13 && (v2 & 1) == 0 )
    sub_40AC90((int)this, &v19);
  if ( (v2 & 4) == 0 || (v2 & 8) == 0 )
  {
    v9 = *(float *)(*((_DWORD *)this + 21) + 112);
    v10 = *(float *)(*((_DWORD *)this + 21) + 116);
    v24 = *(float *)(*((_DWORD *)this + 21) + 120);
    v23 = v10;
    v22 = v9;
    v18 = ((v21 * v24 + v20 * v10 + v19 * v9) * 0.60000002 + 1.0) * 0.5;
  }
  v15 = v18 * v17;
  v14 = (1.0 - v18) * v17;
  AIL_set_sample_volume_levels(*(_DWORD *)(*((_DWORD *)this + 22) + 16), LODWORD(v14), LODWORD(v15));
  v16 = *(float *)(*((_DWORD *)this + 21) + 140) * *((float *)this + 18) * *((float *)this + 17);
  v11 = sub_4015C0(v16);
  AIL_set_sample_playback_rate(*(_DWORD *)(*((_DWORD *)this + 22) + 16), v11);
  v12 = *((_DWORD *)this + 22);
  if ( v12 && *(_DWORD *)(v12 + 16) )
    sub_40C340();
  if ( v13 )
  {
    if ( (v2 & 0x10) != 0 )
      JUMPOUT(0x40D0C0);
    JUMPOUT(0x40D100);
  }
  JUMPOUT(0x40D10D);
}
