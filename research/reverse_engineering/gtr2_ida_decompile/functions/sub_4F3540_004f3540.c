void __usercall sub_4F3540(int a1@<ecx>, int a2@<edi>)
{
  int v3; // ebp
  int v4; // edi
  char v5; // al
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // edi
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // edi
  int v15; // ecx
  int v16; // edx
  _DWORD *v17; // edi
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // edi
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  char v34; // [esp+1h] [ebp-21h]
  int v35; // [esp+2h] [ebp-20h]
  char v36; // [esp+5h] [ebp-1Dh]
  int v37; // [esp+6h] [ebp-1Ch]
  int v38; // [esp+Ah] [ebp-18h]
  char v39; // [esp+11h] [ebp-11h]
  char v40; // [esp+15h] [ebp-Dh]

  v3 = *(_DWORD *)(a1 + 160);
  if ( v3 )
  {
    v38 = a2;
    v4 = *(_DWORD *)(a1 + 168);
    if ( v4 )
    {
      v37 = *(_DWORD *)(a1 + 168);
      v5 = sub_405250();
      v6 = *(_DWORD *)(a1 + 192);
      if ( v6 && (!v5 || *(float *)(v4 + 40) <= (double)*(float *)(v3 + 52) && *(float *)(v3 + 52) <= *(double *)v4) )
      {
        *(_BYTE *)(v6 + 12) = 0;
        if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
          *(_BYTE *)(*(_DWORD *)(a1 + 192) + 13) = 1;
        if ( *(_DWORD *)a1 == 2 || *(_DWORD *)a1 == 3 )
        {
          v7 = *(_DWORD *)(a1 + 192);
          if ( *(_BYTE *)(v7 + 10) && *(_BYTE *)(v7 + 13) )
            sub_4EE320(92, **(_DWORD **)(a1 + 4));
          else
            sub_4EE320(91, **(_DWORD **)(a1 + 4));
        }
        v8 = *(_DWORD **)(a1 + 216);
        *(_DWORD *)(a1 + 192) = 0;
        if ( v8 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD, int, int))(*v8 + 20))(v8, 0, v37, v38);
          v8[5] = 0;
        }
      }
      v9 = *(_DWORD *)(a1 + 196);
      if ( v9 )
      {
        if ( !v40
          || (v10 = *(_DWORD *)(a1 + 168),
              v11 = *(_DWORD *)(a1 + 160),
              *(float *)(v10 + 40) <= (double)*(float *)(v11 + 64))
          && *(float *)(v11 + 64) <= *(double *)v10 )
        {
          *(_BYTE *)(v9 + 12) = 0;
          if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
            *(_BYTE *)(*(_DWORD *)(a1 + 196) + 13) = 1;
          if ( *(_DWORD *)a1 == 2 || *(_DWORD *)a1 == 3 )
          {
            v12 = *(_DWORD *)(a1 + 196);
            if ( *(_BYTE *)(v12 + 10) && *(_BYTE *)(v12 + 13) )
              sub_4EE320(92, **(_DWORD **)(a1 + 4));
            else
              sub_4EE320(91, **(_DWORD **)(a1 + 4));
          }
          v13 = *(_DWORD **)(a1 + 220);
          *(_DWORD *)(a1 + 196) = 0;
          if ( v13 )
          {
            (*(void (__thiscall **)(_DWORD *, _DWORD))(*v13 + 20))(v13, 0);
            v13[5] = 0;
          }
        }
      }
      v14 = *(_DWORD *)(a1 + 200);
      if ( v14 )
      {
        if ( !v39
          || (v15 = *(_DWORD *)(a1 + 168),
              v16 = *(_DWORD *)(a1 + 160),
              *(float *)(v15 + 40) <= (double)*(float *)(v16 + 76))
          && *(float *)(v16 + 76) <= *(double *)v15 )
        {
          *(_BYTE *)(v14 + 12) = 0;
          if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
            *(_BYTE *)(*(_DWORD *)(a1 + 200) + 13) = 1;
          v17 = *(_DWORD **)(a1 + 224);
          *(_DWORD *)(a1 + 200) = 0;
          if ( v17 )
          {
            (*(void (__thiscall **)(_DWORD *, _DWORD))(*v17 + 20))(v17, 0);
            v17[5] = 0;
          }
          if ( *(_DWORD *)a1 == 2 || *(_DWORD *)a1 == 3 )
            sub_4EE320(90, **(_DWORD **)(a1 + 4));
        }
      }
      v18 = *(_DWORD *)(a1 + 160);
      v19 = *(_DWORD *)(v18 + 44);
      if ( v19 )
      {
        v20 = *(_DWORD *)(a1 + 192);
        if ( v20 != v19 )
        {
          if ( HIBYTE(v38) )
          {
            v21 = *(_DWORD *)(a1 + 168);
            if ( *(float *)(v21 + 40) <= (double)*(float *)(v18 + 48) && *(float *)(v18 + 48) <= *(double *)v21 )
            {
              if ( v20 )
              {
                *(_BYTE *)(v20 + 12) = 0;
                if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
                  *(_BYTE *)(*(_DWORD *)(a1 + 192) + 13) = 1;
              }
              v22 = *(_DWORD *)(*(_DWORD *)(a1 + 160) + 44);
              *(_DWORD *)(a1 + 192) = v22;
              *(_BYTE *)(v22 + 12) = 1;
              if ( *(_DWORD *)(a1 + 216) )
                sub_4F08B0(*(_DWORD *)(a1 + 192));
            }
          }
        }
      }
      v23 = *(_DWORD *)(a1 + 160);
      v24 = *(_DWORD *)(v23 + 56);
      if ( v24 )
      {
        v25 = *(_DWORD *)(a1 + 196);
        if ( v25 != v24 )
        {
          if ( HIBYTE(v37) )
          {
            v26 = *(_DWORD *)(a1 + 168);
            if ( *(float *)(v26 + 40) <= (double)*(float *)(v23 + 60) && *(float *)(v23 + 60) <= *(double *)v26 )
            {
              if ( v25 )
              {
                *(_BYTE *)(v25 + 12) = 0;
                if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
                  *(_BYTE *)(*(_DWORD *)(a1 + 196) + 13) = 1;
              }
              v27 = *(_DWORD *)(*(_DWORD *)(a1 + 160) + 56);
              *(_DWORD *)(a1 + 196) = v27;
              *(_BYTE *)(v27 + 12) = 1;
              if ( *(_DWORD *)(a1 + 220) )
                sub_4F08B0(*(_DWORD *)(a1 + 196));
            }
          }
        }
      }
      v28 = *(_DWORD *)(a1 + 160);
      v29 = *(_DWORD *)(v28 + 68);
      if ( v29 )
      {
        v30 = *(_DWORD *)(a1 + 200);
        if ( v30 != v29 )
        {
          if ( v36 )
          {
            v31 = *(_DWORD *)(a1 + 168);
            if ( *(float *)(v31 + 40) <= (double)*(float *)(v28 + 72) && *(float *)(v28 + 72) <= *(double *)v31 )
            {
              if ( v30 )
              {
                *(_BYTE *)(v30 + 12) = 0;
                if ( !*(_BYTE *)(*(_DWORD *)(a1 + 160) + 80) )
                  *(_BYTE *)(*(_DWORD *)(a1 + 200) + 13) = 1;
              }
              v32 = *(_DWORD *)(*(_DWORD *)(a1 + 160) + 68);
              *(_DWORD *)(a1 + 200) = v32;
              *(_BYTE *)(v32 + 12) = 1;
              if ( *(_DWORD *)(a1 + 224) )
                sub_4F08B0(*(_DWORD *)(a1 + 200));
            }
          }
        }
      }
      v35 = *(_DWORD *)(*(_DWORD *)(a1 + 160) + 108);
      if ( v35 )
      {
        if ( v34 )
        {
          v33 = *(_DWORD *)(a1 + 168);
          if ( (double)v35 >= *(float *)(v33 + 40) && (double)v35 <= *(double *)v33 )
            *(_BYTE *)(a1 + 14) = 1;
        }
      }
    }
  }
}
