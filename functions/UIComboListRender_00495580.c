void __thiscall sub_495580(int this)
{
  int v2; // eax
  const char *v3; // eax
  char *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebp
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  double v14; // st7
  int v15; // ebp
  int **v16; // eax
  double v17; // st6
  int v18; // esi
  int v19; // eax
  int **v20; // eax
  int v21; // [esp-8h] [ebp-38h]
  int v22; // [esp+10h] [ebp-20h]
  int v23; // [esp+14h] [ebp-1Ch] BYREF
  int v24; // [esp+18h] [ebp-18h] BYREF
  _DWORD v25[2]; // [esp+1Ch] [ebp-14h] BYREF
  _BYTE v26[4]; // [esp+24h] [ebp-Ch] BYREF
  _BYTE v27[4]; // [esp+28h] [ebp-8h] BYREF
  _BYTE v28[4]; // [esp+2Ch] [ebp-4h] BYREF

  if ( *(_BYTE *)(this + 5512)
    && *(float *)(this + 204) >= (double)*(float *)(this + 208)
    && (v2 = *(_DWORD *)(this + 5484)) != 0 )
  {
    v3 = *(const char **)(v2 + 192);
    if ( !v3 )
      v3 = byte_5EA438;
    if ( strlen(v3) )
    {
      if ( strlen((const char *)(this + 5432)) )
      {
        DriverNameStringHandler(this + 5432);
        sub_498560(this + 5432);
      }
      else
      {
        ShortComputation_8550(this);
      }
      v4 = *(char **)(*(_DWORD *)(this + 5484) + 192);
      if ( !v4 )
        v4 = byte_5EA438;
      TextRenderToSurface(v4, &v23, &v24, 1);
      v5 = v23 + 8;
      v6 = *(_DWORD *)(this + 5488);
      v7 = v24 + 4;
      v8 = *(_DWORD *)(this + 5484);
      v25[1] = v23 + 8;
      v22 = v24 + 4;
      if ( v6 != v8 )
      {
        *(_DWORD *)(this + 5516) = *(_DWORD *)(this + 92) - v5 / 2;
        *(_DWORD *)(this + 5488) = v8;
        (*(void (__thiscall **)(int, _BYTE *, _DWORD *, _BYTE *, _BYTE *))(*(_DWORD *)v8 + 8))(v8, v28, v25, v27, v26);
        v9 = *(_DWORD *)(this + 5516);
        v10 = v25[0] + 5;
        *(_DWORD *)(this + 5520) = v25[0] + 5;
        v11 = v9 < 0 ? 0 : v9;
        *(_DWORD *)(this + 5516) = v11;
        if ( 800 - v5 < v11 )
          v11 = 800 - v5;
        *(_DWORD *)(this + 5516) = v11;
        v12 = v10 < 0 ? 0 : v10;
        *(_DWORD *)(this + 5520) = v12;
        if ( 600 - v7 < v12 )
          v12 = 600 - v7;
        *(_DWORD *)(this + 5520) = v12;
      }
      v13 = *(_DWORD *)(this + 5516);
      v14 = *(float *)(this + 204) - *(float *)(this + 208);
      v15 = *(_DWORD *)(this + 5520);
      if ( *(float *)(this + 212) - v14 > 0.00000011920929 )
      {
        v17 = v14 / *(float *)(this + 212);
        v18 = CRTFtol(v17 * v17);
        v19 = CRTFtol(v17 * v17);
        if ( v18 > 2 && v19 > 2 )
        {
          v21 = v19 + 1;
          v20 = (int **)Accessor();
          RenderSurfaceFillCopy(v20, v13, v15, v21, v18 + 1);
        }
      }
      else
      {
        v16 = (int **)Accessor();
        RenderSurfaceFillCopy(v16, v13, v15, v5 + 10, v22 + 10);
      }
    }
  }
  else
  {
    *(_DWORD *)(this + 5488) = 0;
  }
}
