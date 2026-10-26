int __thiscall sub_406840(void *this)
{
  int v2; // ebx
  BOOL v3; // ebp
  float *v4; // edi
  double v5; // st7
  long double v6; // st7
  double v8; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  double v11; // st7
  float v13; // [esp+0h] [ebp-48h]
  float v14; // [esp+4h] [ebp-44h]
  float v15; // [esp+18h] [ebp-30h]
  float v16; // [esp+1Ch] [ebp-2Ch]
  float v17; // [esp+20h] [ebp-28h]
  float v18; // [esp+20h] [ebp-28h]
  float v19; // [esp+24h] [ebp-24h]
  float v20; // [esp+28h] [ebp-20h]
  float v21; // [esp+2Ch] [ebp-1Ch]
  _DWORD v22[3]; // [esp+30h] [ebp-18h] BYREF
  float v23; // [esp+3Ch] [ebp-Ch]
  float v24; // [esp+40h] [ebp-8h]
  float v25; // [esp+44h] [ebp-4h]

  v2 = *((_DWORD *)this + 6);
  v17 = *((float *)this + 16);
  v3 = 1;
  v4 = (float *)(*((_DWORD *)this + 21) + 88);
  v16 = 0.5;
  if ( *((_DWORD *)this + 5) == 1 )
    v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 28))(this) != 1;
  v19 = *((float *)this + 10) - *v4;
  v20 = *((float *)this + 11) - v4[1];
  v5 = *((float *)this + 12) - v4[2];
  v21 = v5;
  v6 = sqrt(v5 * v21 + v20 * v20 + v19 * v19);
  v15 = v6;
  if ( (v2 & 8) == 0 )
  {
    sub_406CD0(v15);
    v17 = v6;
  }
  v8 = 1.0;
  if ( !(v9 | v10) )
    v8 = 1.0 / v15;
  v23 = v19 * v8;
  *(float *)v22 = v23;
  v24 = v20 * v8;
  *(float *)&v22[1] = v24;
  v25 = v8 * v21;
  *(float *)&v22[2] = v25;
  if ( !v3 && (v2 & 1) == 0 )
    sub_406C30(v22);
  if ( (v2 & 4) == 0 || (v2 & 8) == 0 )
    v16 = sub_406D10(v22);
  v14 = v16 * v17;
  v13 = (1.0 - v16) * v17;
  AIL_set_sample_volume_levels(*(_DWORD *)(*((_DWORD *)this + 22) + 16), LODWORD(v13), LODWORD(v14));
  v18 = *(float *)(*((_DWORD *)this + 21) + 140) * *((float *)this + 18) * *((float *)this + 17);
  AIL_set_sample_playback_rate(*(_DWORD *)(*((_DWORD *)this + 22) + 16), (int)v18);
  sub_406DB0(this);
  if ( v3 )
  {
    if ( (v2 & 0x10) != 0 )
    {
      v11 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
      AIL_set_sample_position(*(_DWORD *)(*((_DWORD *)this + 22) + 16), (__int64)(*((float *)this + 19) * v11));
      AIL_resume_sample(*(_DWORD *)(*((_DWORD *)this + 22) + 16));
      return 0;
    }
    AIL_start_sample(*(_DWORD *)(*((_DWORD *)this + 22) + 16));
  }
  return 0;
}
