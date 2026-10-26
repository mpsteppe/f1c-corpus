int __thiscall sub_46E230(int this, int *a2, int *a3, int *a4, int *a5)
{
  unsigned int v6; // eax
  int v8; // ecx
  double v10; // st6
  double v11; // st7
  double v12; // st6
  unsigned __int16 v13; // cx
  int v14; // edi
  double v15; // st7
  int v16; // eax
  float v17; // [esp+0h] [ebp-28h]
  float v18; // [esp+0h] [ebp-28h]
  float v19; // [esp+0h] [ebp-28h]
  float v20; // [esp+0h] [ebp-28h]
  float v21; // [esp+4h] [ebp-24h]
  float v22; // [esp+4h] [ebp-24h]
  float v23; // [esp+4h] [ebp-24h]
  float v24; // [esp+4h] [ebp-24h]
  float v25; // [esp+18h] [ebp-10h]
  float v26; // [esp+1Ch] [ebp-Ch]
  int v27; // [esp+38h] [ebp+10h]

  if ( *(_BYTE *)(this + 420) )
  {
    if ( *(_DWORD *)(this + 268) )
    {
      v26 = *(float *)(this + 428) * 0.01745433;
      v25 = *(float *)(this + 424) * 0.01745433;
      sub_593820(v25, v26, 0);
    }
    if ( !dword_765590 )
      sub_46F0E0(this);
    v8 = dword_7656E0;
    if ( dword_7656E0 && !*(_DWORD *)(this + 268) )
    {
      *(_DWORD *)(this + 268) = sub_597290();
      v8 = dword_7656E0;
    }
    if ( dword_765590 && v8 && *(_DWORD *)(this + 268) )
    {
      sub_593AF0(1);
      sub_593B30(0.0, 0.0, 512.0, 384.0, 0);
      sub_593F30(*(_DWORD *)(dword_765590 + 16));
      sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
      sub_4A4380(a2, a3, a4, a5);
      if ( *(float *)(this + 272) >= 0.0 )
      {
        if ( *(float *)(this + 276) < (double)*(float *)(this + 272) )
          *(float *)(this + 272) = *(float *)(this + 276);
      }
      else
      {
        *(_DWORD *)(this + 272) = 0;
      }
      v10 = *(float *)(this + 272) / *(float *)(this + 276);
      v11 = v10 * v10;
      if ( v10 * v10 >= 0.0 )
      {
        if ( v11 > 1.0 )
          v11 = 1.0;
      }
      else
      {
        v11 = 0.0;
      }
      v12 = (1.0 - v11) * 255.0;
      v27 = (unsigned __int8)(__int64)(v11 * 255.0 + v12);
      LOBYTE(v13) = 0;
      HIBYTE(v13) = (__int64)(v11 * 0.0 + v12);
      v14 = v27 | ((v27 | ((v27 | v13) << 8)) << 8);
      v15 = sub_4AE720(*(_DWORD *)(this + 48), (unsigned __int64)(__int64)(v11 * 0.0 + v12) >> 32);
      if ( v15 >= 0.0 )
      {
        if ( v15 > 0.033333335 )
          v15 = 0.033333335;
      }
      else
      {
        v15 = 0.0;
      }
      *(float *)(this + 272) = *(float *)(this + 272) - v15;
      *a2 = (__int64)((double)*(int *)(this + 4) * (double)dword_6152EC * 0.0016666667);
      *a3 = (__int64)((double)*(int *)(this + 8) * (double)dword_6152EC * 0.0016666667);
      *a4 = (__int64)((double)*(int *)(this + 12) * (double)dword_6152E8 * 0.00125);
      *a5 = (__int64)((double)*(int *)(this + 16) * (double)dword_6152E8 * 0.00125);
      v21 = (float)*a2;
      v17 = (float)*a4;
      sub_5A16E0(dword_765594, 0, v17, v21, 0.0, 0.0, 0.0, v14);
      v22 = (float)*a3;
      v18 = (float)*a4;
      sub_5A16E0(dword_765594, 1, v18, v22, 0.0, 0.0, 1.0, v14);
      v23 = (float)*a3;
      v19 = (float)*a5;
      sub_5A16E0(dword_765594, 2, v19, v23, 0.0, 1.0, 1.0, v14);
      v24 = (float)*a2;
      v20 = (float)*a5;
      sub_5A16E0(dword_765594, 3, v20, v24, 0.0, 1.0, 0.0, v14);
      v16 = sub_4AB570(&unk_765B00);
      sub_5A1870(v16);
    }
  }
  else
  {
    v6 = *(_DWORD *)(this + 416) + 1;
    *(_DWORD *)(this + 416) = v6;
    if ( v6 > 5 )
    {
      *(_DWORD *)(this + 416) = 0;
      *(_BYTE *)(this + 420) = 1;
      return 0;
    }
  }
  return 0;
}
