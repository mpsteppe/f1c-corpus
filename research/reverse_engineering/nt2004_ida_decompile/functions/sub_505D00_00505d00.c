void __fastcall sub_505D00(int a1, int a2, float *a3, float a4, float a5, int a6, int a7, int a8, int a9)
{
  int v9; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  int v13; // ebp
  int v14; // eax
  float v15; // [esp+0h] [ebp-24h]
  float v16; // [esp+4h] [ebp-20h]
  float v17; // [esp+8h] [ebp-1Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  int v19; // [esp+20h] [ebp-4h]

  v9 = a9;
  if ( !a9 )
    v9 = dword_7E8CDC;
  if ( a1 )
  {
    if ( a2 )
    {
      v11 = (_DWORD *)sub_592CD0(a1);
      v12 = v11;
      if ( v11 )
      {
        v19 = v11[44];
        v13 = v11[38];
        v18 = v11[43];
        v14 = a8;
        v17 = a5;
        v12[43] = a7;
        v12[44] = v14;
        sub_5A3F10(LODWORD(v17));
        if ( v9 )
          a9 = *(_DWORD *)(v9 + 28);
        else
          a9 = dword_6152E8;
        a5 = (float)a9;
        if ( v9 )
          a7 = *(_DWORD *)(v9 + 32);
        else
          a7 = dword_6152EC;
        a8 = 0;
        a9 = 0;
        sub_5A41F0(a2, &a8, &a9, 1);
        v16 = (double)a9 / (double)a7;
        v15 = (double)a8 / a5;
        sub_505990(a6, (float *)&a3, a3, a4, v15, v16, &a4);
        sub_5A41A0(a2, *(float *)&a3, a4, v9, 0x2000);
        v12[38] = v13;
        v12[43] = v18;
        v12[44] = v19;
      }
    }
  }
}
