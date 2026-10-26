void __fastcall sub_4989E0(char *a1, int a2, const char *a3)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // ebp
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // eax
  int **v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  char v20; // al
  unsigned __int16 v21; // dx
  int v22; // kr08_4
  int v23; // esi
  int v24; // [esp-Ch] [ebp-88h]
  float v25; // [esp+10h] [ebp-6Ch]
  int v26; // [esp+14h] [ebp-68h] BYREF
  int v27; // [esp+18h] [ebp-64h] BYREF
  float v28; // [esp+1Ch] [ebp-60h] BYREF
  int v29; // [esp+20h] [ebp-5Ch]
  int v30; // [esp+24h] [ebp-58h]
  int v31; // [esp+28h] [ebp-54h]
  _BYTE v33[76]; // [esp+30h] [ebp-4Ch] BYREF

  v28 = *(float *)&a1;
  if ( a3 && strlen(a3) )
  {
    v4 = sub_497AD0(a1, aSavingreplay00, 0);
    v5 = v4;
    if ( v4 )
    {
      v6 = *(_DWORD *)(v4 + 12);
      v7 = *(_DWORD *)(v6 + 28);
      v8 = *(_DWORD *)(v6 + 32);
      v9 = sub_495150();
      sub_494A30(*(_DWORD *)(v5 + 12), 0, 0, v9, 0, 274, v7, v8, 0, 0);
      v10 = sub_53D1F0(aFtim28blk);
      sub_498560((char *)LODWORD(v28), aFtim28blk);
      if ( v10 )
      {
        v27 = 0;
        v28 = 0.0;
        sub_5531F0(a3, &v27, &v28, 1);
        v11 = 400 - v27 / 2;
        v12 = sub_495150();
        sub_553070(a3, v11, 281, v12);
      }
      sub_495080();
      v13 = (int **)sub_490920();
      sub_4918D0(v13, 0, 274, v7, v8);
    }
    else if ( sub_53D1F0(a1 + 5432) )
    {
      v26 = 0;
      v27 = 0;
      sub_5531F0(a3, &v26, &v27, 1);
      v31 = 400 - v26 / 2;
      v30 = 300 - v27 / 2;
      v29 = sub_495150();
      sub_568BA0(v33);
      sub_568BE0(1);
      sub_568C60(v33);
      do
      {
        v14 = sub_568D90(v33);
        v28 = v14;
        v15 = v14 * 2.2222223;
        v25 = v15;
        if ( v15 >= 0.0 )
        {
          if ( v25 > 1.0 )
            v25 = 1.0;
        }
        else
        {
          v25 = 0.0;
        }
        v16 = v25;
        if ( v25 >= 0.0 )
        {
          if ( v25 > 1.0 )
            v16 = 1.0;
        }
        else
        {
          v16 = 0.0;
        }
        v17 = sub_587BDC(v16) + 8;
        v18 = sub_587BDC(v16) + 8;
        v19 = (unsigned __int8)sub_587BDC(v16);
        v20 = sub_587BDC((1.0 - v16) * 0.0 + v16 * 0.0);
        LOBYTE(v21) = 0;
        HIBYTE(v21) = v20;
        v22 = v17;
        v24 = v17;
        v23 = v29;
        sub_494BF0(v29, 400 - v22 / 2, 300 - v18 / 2, v24, v18, v19 | ((v19 | ((v19 | v21) << 8)) << 8));
        sub_495080();
      }
      while ( v28 <= 0.44999999 );
      sub_553070(a3, v31, v30, v23);
      sub_495080();
      nullsub_3(v33);
    }
  }
}
