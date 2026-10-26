int *__thiscall sub_4B9000(char *this, float a2)
{
  char *v2; // ebx
  int i; // edi
  float *v4; // eax
  float *v5; // esi
  float **v6; // eax
  float *v7; // eax
  float **v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // esi
  int *v12; // eax
  int v13; // eax
  int *v14; // eax
  int *v15; // edx
  int j; // ecx
  int *v17; // eax
  int v18; // eax
  int *v19; // eax
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int *v24; // eax
  int v25; // esi
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int *v30; // eax
  int v31; // edi
  int v32; // esi
  int v33; // eax
  int v34; // eax
  int *v35; // eax
  _DWORD *v38; // [esp+10h] [ebp-368h]
  int v39; // [esp+14h] [ebp-364h]
  int v40; // [esp+14h] [ebp-364h]
  int *v41; // [esp+18h] [ebp-360h]
  _DWORD v42[3]; // [esp+1Ch] [ebp-35Ch] BYREF
  int v43[212]; // [esp+28h] [ebp-350h] BYREF

  v2 = this;
  for ( i = 0; i < 104; ++i )
  {
    v4 = sub_4B72A0(v2, i, a2);
    v5 = v4;
    v43[i + 108] = (int)v4;
    if ( v4 )
    {
      if ( (unsigned __int8)sub_5001D0(v4 + 36)
        && v5[147] <= (double)a2
        && (unsigned __int8)sub_5001F0(v5 + 36)
        && v5[39] >= (double)a2 )
      {
        v43[i + 108] = 0;
      }
      else
      {
        sub_4FFFA0(v5 + 36);
      }
      v2 = this;
    }
  }
  v38 = v2 + 3908;
  sub_4B5380((int)(v2 + 3908), a2);
  v6 = (float **)*((_DWORD *)v2 + 455);
  if ( v6 && (v7 = *v6) != 0
    || (*((float *)v2 + 973) - *((float *)v2 + 972) + *((float *)v2 + 972) >= a2
      ? (v8 = (float **)*((_DWORD *)v2 + 453))
      : (v8 = (float **)*((_DWORD *)v2 + 454)),
        (*((_DWORD *)v2 + 455) = v8) != 0 && (v7 = *v8) != 0) )
  {
    if ( *v7 <= (double)a2 )
    {
      while ( 1 )
      {
        v13 = *((_DWORD *)v2 + 455);
        if ( !v13 )
          break;
        v14 = *(int **)(v13 + 4);
        *((_DWORD *)v2 + 455) = v14;
        if ( !v14 )
          break;
        v11 = *v14;
        if ( !*v14 )
          break;
        if ( *(float *)v11 >= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 454);
    }
    else
    {
      while ( 1 )
      {
        v9 = *((_DWORD *)v2 + 455);
        if ( !v9 )
          break;
        v10 = *(int **)(v9 + 8);
        *((_DWORD *)v2 + 455) = v10;
        if ( !v10 )
          break;
        v11 = *v10;
        if ( !*v10 )
          break;
        if ( *(float *)v11 <= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 453);
    }
    *((_DWORD *)v2 + 455) = v12;
    if ( v12 )
      v11 = *v12;
    else
      v11 = 0;
LABEL_34:
    v15 = (int *)*((_DWORD *)v2 + 455);
    j = -1;
    v41 = v15;
    if ( v15 )
    {
      v17 = (int *)*((_DWORD *)v2 + 453);
      for ( j = 0; v17; ++j )
      {
        if ( v17 == v15 )
          break;
        v17 = (int *)v17[1];
      }
    }
    if ( j < *((_DWORD *)v2 + 456) - 1 && v11 )
    {
      while ( *(float *)v11 < (double)a2 )
      {
        v18 = *((_DWORD *)v2 + 455);
        if ( v18 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v18 + 4);
        v19 = (int *)*((_DWORD *)v2 + 455);
        if ( !v19 )
        {
          v11 = 0;
          break;
        }
        v11 = *v19;
        if ( !*v19 )
          break;
      }
    }
    v39 = 0;
    if ( v11 )
    {
      do
      {
        sub_566DB0(*(_DWORD *)(v11 + 4));
        sub_4B4450(v42);
        sub_4B44A0(v42, (int)(v2 + 1764));
        if ( ++v39 > 64 )
          break;
        v20 = 0;
        if ( *(_WORD *)(v11 + 8) )
        {
          do
          {
            sub_4B4360((int)(v2 + 1764), *(float *)v11, (int)v43);
            if ( (v43[0] & 0xE0000000) == 0x20000000 )
            {
              if ( (((unsigned int)v43[0] >> 18) & 0x3F) != 0 )
              {
                if ( (((unsigned int)v43[0] >> 18) & 0x3F) <= 6 )
                  sub_4B54E0((int)v38, (int)v43);
              }
              else if ( LOBYTE(v43[0]) < 0x68u && v43[LOBYTE(v43[0]) + 108] )
              {
                sub_4FFFB0(a2, (int)v43);
              }
            }
            ++v20;
          }
          while ( v20 < *(unsigned __int16 *)(v11 + 8) );
        }
        v21 = 0;
        while ( 1 )
        {
          v22 = v43[v21 + 108];
          if ( v22 )
          {
            if ( !(unsigned __int8)sub_5001D0(v22 + 144) )
              break;
          }
          if ( ++v21 >= 104 )
          {
            if ( v39 >= 64 || sub_4B5460(v38) )
              goto LABEL_68;
            break;
          }
        }
        v23 = *((_DWORD *)v2 + 455);
        if ( v23 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v23 + 8);
        v24 = (int *)*((_DWORD *)v2 + 455);
        if ( !v24 )
          break;
        v11 = *v24;
      }
      while ( *v24 );
    }
LABEL_68:
    *((_DWORD *)v2 + 455) = v41;
    if ( v41 )
      v25 = *v41;
    else
      v25 = 0;
    v26 = *((_DWORD *)v2 + 455);
    if ( v26 )
    {
      v27 = *((_DWORD *)v2 + 453);
      v28 = 0;
      if ( v27 )
      {
        do
        {
          if ( v27 == v26 )
            break;
          v27 = *(_DWORD *)(v27 + 4);
          ++v28;
        }
        while ( v27 );
        if ( v28 > 0 && v25 )
        {
          while ( *(float *)v25 > (double)a2 )
          {
            v29 = *((_DWORD *)v2 + 455);
            if ( v29 )
              *((_DWORD *)v2 + 455) = *(_DWORD *)(v29 + 8);
            v30 = (int *)*((_DWORD *)v2 + 455);
            if ( !v30 )
            {
              v25 = 0;
              break;
            }
            v25 = *v30;
            if ( !*v30 )
              break;
          }
        }
      }
    }
    v40 = 0;
    if ( v25 )
    {
      do
      {
        sub_566DB0(*(_DWORD *)(v25 + 4));
        sub_4B4450(v42);
        sub_4B44A0(v42, (int)(v2 + 1764));
        if ( ++v40 > 64 )
          break;
        v31 = 0;
        if ( *(_WORD *)(v25 + 8) )
        {
          do
          {
            sub_4B4360((int)(v2 + 1764), *(float *)v25, (int)v43);
            if ( (v43[0] & 0xE0000000) == 0x20000000 )
            {
              if ( (((unsigned int)v43[0] >> 18) & 0x3F) != 0 )
              {
                if ( (((unsigned int)v43[0] >> 18) & 0x3F) <= 6 )
                  sub_4B54E0((int)v38, (int)v43);
              }
              else if ( LOBYTE(v43[0]) < 0x68u && v43[LOBYTE(v43[0]) + 108] )
              {
                sub_4FFFB0(a2, (int)v43);
              }
            }
            ++v31;
          }
          while ( v31 < *(unsigned __int16 *)(v25 + 8) );
        }
        v32 = 0;
        while ( 1 )
        {
          v33 = v43[v32 + 108];
          if ( v33 )
          {
            if ( !(unsigned __int8)sub_5001F0(v33 + 144) )
              break;
          }
          if ( ++v32 >= 104 )
          {
            if ( v40 >= 64 || sub_4B54A0(v38) )
              goto LABEL_105;
            break;
          }
        }
        v34 = *((_DWORD *)v2 + 455);
        if ( v34 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v34 + 4);
        v35 = (int *)*((_DWORD *)v2 + 455);
        if ( !v35 )
          break;
        v25 = *v35;
      }
      while ( *v35 );
    }
  }
LABEL_105:
  sub_4B5630((int)v38);
  return sub_4B5760((int)v38);
}
