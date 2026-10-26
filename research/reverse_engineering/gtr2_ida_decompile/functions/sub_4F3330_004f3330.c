void __thiscall sub_4F3330(void *this)
{
  int v1; // esi
  float *v2; // edi
  int v3; // edx
  int v4; // eax
  double v5; // st7
  float *v6; // esi
  double v7; // st6
  float v8; // ebx
  float v9; // esi
  double v10; // st6
  int v11; // edx
  float *v12; // esi
  int v13; // ecx
  int v14; // eax
  double v15; // st7
  float v16; // [esp+8h] [ebp-Ch] BYREF
  float v17; // [esp+Ch] [ebp-8h]
  float v18; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)this;
  if ( *(int *)this >= 4 && v1 <= 5 )
  {
    v2 = (float *)*((_DWORD *)this + 43);
    if ( v2 )
    {
      v3 = **((_DWORD **)this + 1);
      v4 = dword_BE1BD8 + 2824 * *(_DWORD *)(v3 + 22472);
      if ( v1 == 4 )
      {
        v5 = *(float *)(v4 + 248);
        v6 = (float *)(v4 + 236);
      }
      else
      {
        v5 = *(float *)(v4 + 264);
        v6 = (float *)(v4 + 252);
      }
      v16 = *v6;
      v7 = v16 + *(float *)(v3 + 2780);
      v8 = v6[1];
      v9 = v6[2];
      v17 = v8;
      v16 = v7;
      v18 = v9;
      v17 = v8 + *(float *)(v3 + 2784);
      v10 = v9 + *(float *)(v3 + 2788);
      v2[11] = v16;
      v18 = v10;
      v2[12] = v17;
      v2[13] = v18;
      v2[14] = v5 * 0.01745433;
    }
  }
  v11 = *(_DWORD *)this;
  if ( *(int *)this >= 7 && v11 <= 8 )
  {
    v12 = (float *)*((_DWORD *)this + 59);
    if ( v12 )
    {
      v13 = **((_DWORD **)this + 1);
      v14 = dword_BE1BD8 + 2824 * *(_DWORD *)(v13 + 22472);
      v17 = 2.05;
      if ( v11 == 7 )
      {
        v15 = *(float *)(v14 + 244);
        v16 = 0.89999998;
      }
      else
      {
        v15 = *(float *)(v14 + 260);
        v16 = -0.89999998;
      }
      v18 = v15 + *(float *)(v13 + 2788);
      sub_4F26D0(v12, &v16);
    }
  }
}
