void __fastcall sub_5BA350(_DWORD *a1, _BYTE *a2, int a3)
{
  _BYTE *v4; // esi
  int v6; // eax
  _BYTE *v7; // esi
  int v8; // ebp
  int v9; // eax
  u_short *v10; // esi
  int v11; // ebp
  u_short v12; // ax
  _BYTE *v13; // esi
  u_short v14; // di
  int v15; // ebp
  unsigned int v16; // eax
  int v17; // eax
  const char *v18; // ebx
  int v19; // edi
  int v20; // [esp-4h] [ebp-B0h]
  int i; // [esp+10h] [ebp-9Ch]
  int v22; // [esp+14h] [ebp-98h]
  int v23; // [esp+18h] [ebp-94h]
  int v24; // [esp+1Ch] [ebp-90h]
  int v26; // [esp+24h] [ebp-88h]
  const char *v27; // [esp+28h] [ebp-84h]
  char Buffer[128]; // [esp+2Ch] [ebp-80h] BYREF

  v4 = a2;
  if ( *a2 )
  {
    while ( 1 )
    {
      v6 = sub_5BC130(v4, a3);
      if ( v6 < 0 )
        break;
      v7 = &v4[v6];
      v8 = a3 - v6;
      v9 = sub_5BC130(v7, v8);
      if ( v9 < 0 )
        break;
      v20 = (int)v7;
      v4 = &v7[v9];
      a3 = v8 - v9;
      sub_5BA0E0(a1, v20);
      if ( !*v4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v10 = (u_short *)(v4 + 1);
    v11 = a3 - 1;
    v23 = 0;
    while ( v11 >= 2 )
    {
      v12 = ntohs(*v10);
      v13 = v10 + 1;
      v14 = v12;
      v15 = v11 - 2;
      v27 = v13;
      for ( i = 0; *v13; ++i )
      {
        v16 = sub_5BC130(v13, v15);
        if ( v16 > 0x64 )
          return;
        v13 += v16;
        v15 -= v16;
      }
      v10 = (u_short *)(v13 + 1);
      v11 = v15 - 1;
      v17 = v14;
      v22 = 0;
      v26 = v14;
      if ( v14 )
      {
        while ( 1 )
        {
          v18 = v27;
          v24 = 0;
          if ( i > 0 )
            break;
LABEL_15:
          if ( ++v22 >= v17 )
            goto LABEL_16;
        }
        while ( 1 )
        {
          v19 = sub_5BC130(v10, v11);
          if ( v19 < 0 )
            return;
          sprintf(Buffer, "%s%d", v18, v22);
          sub_5BA0E0(a1, (int)v10);
          v10 = (u_short *)((char *)v10 + v19);
          v11 -= v19;
          ++v24;
          v18 += strlen(v18) + 1;
          if ( v24 >= i )
          {
            v17 = v26;
            goto LABEL_15;
          }
        }
      }
LABEL_16:
      if ( ++v23 >= 2 )
        return;
    }
  }
}
