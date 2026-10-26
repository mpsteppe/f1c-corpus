void __userpurge sub_47B550(int a1@<ecx>, const char *a2@<ebx>, float a3)
{
  int v4; // eax
  double v5; // st7
  int v6; // eax
  unsigned int v7; // ebx
  int *v8; // edi
  _BYTE *v9; // ebp
  double v10; // st7
  int v11; // edi
  const char *v12; // ecx
  double v13; // st7
  long double v14; // st7
  long double v15; // st6
  char *v16; // eax
  double v17; // st7
  char *v18; // eax
  const char *v19; // ecx
  unsigned int v20; // kr00_4
  __int32 v21; // ecx
  float v22; // [esp+0h] [ebp-3BCh]
  float v23; // [esp+Ch] [ebp-3B0h] BYREF
  float v24; // [esp+18h] [ebp-3A4h] BYREF
  long double v25; // [esp+1Ch] [ebp-3A0h] BYREF
  char *v26; // [esp+24h] [ebp-398h] BYREF
  _BYTE v27[4]; // [esp+28h] [ebp-394h] BYREF
  char Buffer[64]; // [esp+2Ch] [ebp-390h] BYREF
  _WORD v29[420]; // [esp+74h] [ebp-348h] BYREF

  v4 = *(_DWORD *)(a1 + 113328);
  if ( v4 == 2 || v4 == 1 )
  {
    v5 = a3 + *(float *)(a1 + 2136);
    *(float *)(a1 + 2136) = v5;
    if ( v5 > 5.0 )
    {
      v6 = *(_DWORD *)(a1 + 112884);
      v23 = *(float *)&a2;
      v7 = 0;
      *(_DWORD *)(a1 + 2136) = 0;
      if ( v6 )
      {
        v8 = (int *)(a1 + 112052);
        v9 = (_BYTE *)(a1 + 2752);
        do
        {
          if ( (*v9 & 1) == 0 && (*v9 & 2) != 0 )
          {
            if ( sub_47AC90((float *)(a1 + 292692), *v8, (int)&v25, 1) )
            {
              v22 = dbl_FB1D18;
              sub_51B2A0(4, 47, 2, 255, LODWORD(v22), 0);
              sub_4763B0(v29, *(float *)&v25);
              sub_4745E0();
            }
          }
          ++v7;
          ++v8;
          v9 += 528;
        }
        while ( v7 < *(_DWORD *)(a1 + 112884) );
      }
    }
  }
  else
  {
    v10 = *(float *)(a1 + 16) - a3;
    *(float *)(a1 + 16) = v10;
    if ( v10 < 0.0 )
    {
      if ( !*(_BYTE *)(a1 + 24) )
        sub_59B780(*(_DWORD *)(a1 + 113316));
      *(_DWORD *)(a1 + 16) = *(_DWORD *)(a1 + 12);
    }
    if ( (unsigned __int8)sub_59B410(&v24, &v26, v27) )
    {
      v11 = *v26;
      if ( (*(_DWORD *)dword_B640C8 != v11 || v26[1]) && v11 < 7 )
      {
        *(_BYTE *)(a1 + 2112) = 1;
        if ( !byte_B6F118 )
          sub_4EAD90(&unk_B6F135);
        sub_430F70(&dword_B640C0, v11);
        sub_4EA8F0(&unk_B6F134);
        *(_DWORD *)(a1 + 16) = 0x40000000;
      }
      v25 = v24;
      v13 = sub_58F2F0(&unk_FB1E98);
      v14 = v25 - v13;
      v15 = fabs(v14);
      if ( v15 <= 1.0 )
      {
        if ( v15 <= 0.5 )
        {
          *(long double *)(a1 + 2144) = v14;
        }
        else
        {
          v23 = *(float *)&v12;
          if ( v14 <= 0.0 )
          {
            v25 = v14 + 0.5;
            *(double *)(a1 + 2144) = -0.5;
            v17 = v24 + 0.5;
          }
          else
          {
            v25 = v14 - 0.5;
            *(double *)(a1 + 2144) = 0.5;
            v17 = v24 - 0.5;
          }
          v23 = v17;
          sub_58F340(v23);
          v23 = COERCE_FLOAT(sub_431910(v25 * 1000.0));
          v18 = sub_41D840(&byte_91CC38, "Synchronizing game");
          sub_41D810(Buffer, 0x3Fu, "%s (%d ms)", v18, v23);
          sub_4730C0((int **)&dword_B6CB98, Buffer, 3, (int)&byte_1020304, 1084227584);
        }
      }
      else
      {
        sub_42C920(v24);
        sub_58F340(v24);
        v23 = COERCE_FLOAT("Synchronizing game");
        *(double *)(a1 + 2144) = 0.0;
        v16 = sub_41D840(&byte_91CC38, (const char *)LODWORD(v23));
        sub_41D810(Buffer, 0x3Fu, "%s", v16);
        v23 = *(float *)&v19;
        v20 = __readeflags();
        v21 = dword_16C6D64 + 1325652481;
        __writeeflags(v20);
        _InterlockedExchange((volatile __int32 *)&v23, v21);
        sub_4730C0((int **)&dword_B6CB98, Buffer, 3, (int)&byte_1020304, SLODWORD(v23));
      }
    }
  }
}
