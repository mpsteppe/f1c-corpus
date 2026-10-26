char __usercall sub_47DDB0@<al>(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  char result; // al
  unsigned int v6; // ebp
  bool v7; // zf
  char *v8; // edi
  int v9; // esi
  char v10; // cl
  int v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  unsigned int i; // esi
  int v17; // ecx
  char v18; // [esp+19h] [ebp-3EDh]
  int v19; // [esp+1Ah] [ebp-3ECh]
  float v20; // [esp+1Ah] [ebp-3ECh]
  char v21; // [esp+1Fh] [ebp-3E7h]
  int v22; // [esp+2Ah] [ebp-3DCh]
  int v23; // [esp+2Eh] [ebp-3D8h]
  int v24; // [esp+32h] [ebp-3D4h] BYREF
  int v25; // [esp+36h] [ebp-3D0h]
  int v26; // [esp+3Ah] [ebp-3CCh]
  int v27; // [esp+3Eh] [ebp-3C8h]
  _DWORD *v28; // [esp+42h] [ebp-3C4h]
  _DWORD v29[240]; // [esp+46h] [ebp-3C0h] BYREF

  result = *(_BYTE *)(a1 + 2112);
  if ( !result )
  {
    v24 = a2;
    v23 = a4;
    v22 = a3;
    v6 = 0;
    memset(&v29[2], 0, 0x68u);
    v7 = *(_DWORD *)(a1 + 112884) == 0;
    v29[0] = 0;
    BYTE1(v26) = 0;
    HIBYTE(v26) = 0;
    v27 = 0;
    if ( !v7 )
    {
      v28 = (_DWORD *)(a1 + 112052);
      v8 = (char *)(a1 + 2741);
      do
      {
        if ( (v8[11] & 2) != 0 )
        {
          sub_489F90(&dword_B6D67C, *v28, *v8, v22, v23, v24);
          v9 = *(v8 - 1);
          if ( v9 != -1 )
          {
            v28 = (_DWORD *)strlen(v8 - 449);
            if ( v28 )
            {
              if ( *((_BYTE *)v29 + v9) != 1 )
              {
                BYTE2(v24) = v10;
                *((_BYTE *)v29 + v9) = 1;
                if ( sub_47B870((char *)a1, v6, v9, (_BYTE *)&v24 + 2) )
                {
                  v11 = dword_923E84[5654 * v9];
                  ++v25;
                  if ( !v11 )
                    BYTE1(v24) = 1;
                }
                if ( BYTE2(v24) )
                  ++v27;
              }
            }
          }
        }
        v12 = *(_DWORD *)(a1 + 112884);
        ++v6;
        v8 += 528;
        v26 += 4;
      }
      while ( v6 < v12 );
      if ( v25 > 0 )
      {
        if ( *(_DWORD *)(dword_B6CBA8 + 113328) == 4 )
        {
          v13 = *(_DWORD *)(dword_B6CBA8 + 113316);
          if ( v13 )
          {
            if ( sub_59B670(v13) == 3 )
              *(_DWORD *)(dword_B6CBA8 + 113328) = 3;
          }
        }
        v14 = *(_DWORD *)(dword_B6CBA8 + 113328);
        if ( v14 != 2 && v14 != 1 )
        {
          v20 = dbl_FB1D18;
          sub_51B2A0(4, 51, 0, *(_DWORD *)(dword_91E084 + 22468), LODWORD(v20), 3);
          v21 = -1;
          v19 = -1;
          v18 = 0;
          sub_4745E0();
        }
      }
    }
    v15 = 0;
    for ( i = 0; i < 0x68; ++i )
    {
      if ( *((_BYTE *)&v25 + i) != 1 && sub_478FC0((_DWORD *)a1, i) )
        ++v15;
    }
    if ( v15 > 0 )
    {
      sub_479E60();
      dword_757C10 -= v15;
      sub_42CC30(&unk_920488);
    }
    if ( *(_DWORD *)(a1 + 113328) != 1 )
    {
      if ( *(_DWORD *)(dword_B6CBA8 + 113328) == 4 )
      {
        v17 = *(_DWORD *)(dword_B6CBA8 + 113316);
        if ( v17 )
        {
          if ( sub_59B670(v17) == 3 )
            *(_DWORD *)(dword_B6CBA8 + 113328) = 3;
        }
      }
      if ( !*(_DWORD *)(dword_B6CBA8 + 113328) || byte_B6F118 || dword_B640C0 != 5 )
      {
        if ( v21 )
          sub_540E90(&unk_BE1D30, 0, 1065353216);
        if ( v18 )
          sub_540E90(&unk_BE1D30, 2, 1065353216);
      }
    }
    result = v19;
    if ( v19 != dword_757C10 )
    {
      dword_757C10 = v19;
      return sub_42CC30(&unk_920488);
    }
  }
  return result;
}
