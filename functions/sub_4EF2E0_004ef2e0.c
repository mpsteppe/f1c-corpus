void __thiscall sub_4EF2E0(int this)
{
  double v2; // st7
  int v3; // esi
  int v4; // eax
  bool v5; // al
  int v6; // ecx
  int v7; // eax
  __int16 v8; // dx
  int v9; // eax
  int v10; // edx
  int v11; // ebp
  int v12; // ecx
  int v13; // ecx
  int *v14; // edi
  _WORD *v15; // esi
  bool v16; // zf
  _DWORD *v17; // esi
  bool v18; // al
  int v19; // ecx
  int v20; // edx
  _DWORD *v21; // esi
  __int16 v22; // ax
  int v23; // [esp+0h] [ebp-44h]
  int v24; // [esp+0h] [ebp-44h]
  float v25; // [esp+18h] [ebp-2Ch]
  int v26; // [esp+1Ch] [ebp-28h] BYREF
  int v27; // [esp+20h] [ebp-24h]
  int v28; // [esp+24h] [ebp-20h]
  int v29; // [esp+28h] [ebp-1Ch]
  __int16 v30; // [esp+2Ch] [ebp-18h]
  _DWORD v31[4]; // [esp+30h] [ebp-14h] BYREF
  __int16 v32; // [esp+40h] [ebp-4h]

  v25 = dbl_8AFEA0;
  v2 = v25 - *(float *)(this + 4120);
  if ( v2 >= 0.125 )
  {
    if ( v2 <= 4.0 )
    {
      v6 = *(_DWORD *)(this + 4128);
      v31[0] = *(_DWORD *)(this + 4124);
      v7 = *(_DWORD *)(this + 4132);
      v31[1] = v6;
      v8 = *(_WORD *)(this + 4140);
      v31[3] = *(_DWORD *)(this + 4136);
      v31[2] = v7;
      v32 = v8;
      v9 = ForceFeedback(this + 1764);
      v10 = *(_DWORD *)(v9 + 4);
      v11 = *(_DWORD *)(v9 + 8);
      v26 = *(_DWORD *)v9;
      v12 = *(_DWORD *)(v9 + 12);
      v27 = v10;
      LOWORD(v10) = *(_WORD *)(v9 + 16);
      v29 = v12;
      v13 = 9;
      v14 = &v26;
      v15 = v31;
      v16 = 1;
      v28 = v11;
      v30 = v10;
      do
      {
        if ( !v13 )
          break;
        v16 = *v15++ == *(_WORD *)v14;
        v14 = (int *)((char *)v14 + 2);
        --v13;
      }
      while ( v16 );
      if ( !v16 )
      {
        *(float *)(this + 4120) = v25;
        v17 = (_DWORD *)dword_8AAE64;
        if ( dword_83EE60 < 1023 )
        {
          ++dword_83EE60;
          dword_8AAE64 += 432;
        }
        v18 = !BYTE2(v27) && !v11;
        *(float *)&v24 = dbl_8AFEA0;
        ProgressBarEventEncode(v17, 2, 2, v18 ? 6 : 18, *(_DWORD *)(this + 4), v24, 0);
        v19 = v27;
        v20 = v29;
        v21 = v17 + 2;
        *v21 = v26;
        v22 = v30;
        v21[1] = v19;
        v21[2] = v11;
        v21[3] = v20;
        *((_WORD *)v21 + 8) = v22;
      }
    }
    else
    {
      *(float *)(this + 4120) = v25;
      v3 = dword_8AAE64;
      if ( dword_83EE60 < 1023 )
      {
        ++dword_83EE60;
        dword_8AAE64 += 432;
      }
      v4 = ForceFeedback(this + 1764);
      *(_DWORD *)(v3 + 8) = *(_DWORD *)v4;
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(v4 + 4);
      *(_DWORD *)(v3 + 16) = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v3 + 20) = *(_DWORD *)(v4 + 12);
      *(_WORD *)(v3 + 24) = *(_WORD *)(v4 + 16);
      v5 = !*(_BYTE *)(v3 + 14) && !*(_DWORD *)(v3 + 16);
      *(float *)&v23 = dbl_8AFEA0;
      ProgressBarEventEncode((_DWORD *)v3, 2, 2, v5 ? 6 : 18, *(_DWORD *)(this + 4), v23, 0);
    }
  }
}
