int *__thiscall sub_4D8DD0(char *this, float a2)
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
  _DWORD *v38; // [esp+10h] [ebp-1ACh]
  int v39; // [esp+14h] [ebp-1A8h]
  int v40; // [esp+14h] [ebp-1A8h]
  int *v41; // [esp+18h] [ebp-1A4h]
  _DWORD v42[3]; // [esp+1Ch] [ebp-1A0h] BYREF
  int Buffer[101]; // [esp+28h] [ebp-194h] BYREF

  v2 = this;
  for ( i = 0; i < 49; ++i )
  {
    v4 = sub_4D6DB0(v2, i, a2);
    v5 = v4;
    Buffer[i + 52] = (int)v4;
    if ( v4 )
    {
      if ( (unsigned __int8)sub_52E830(v4 + 37)
        && v5[92] <= (double)a2
        && (unsigned __int8)sub_52E850(v5 + 37)
        && v5[40] >= (double)a2 )
      {
        Buffer[i + 52] = 0;
      }
      else
      {
        sub_52E5C0(v5 + 37);
      }
      v2 = this;
    }
  }
  v38 = v2 + 2088;
  sub_4D4C00((int)(v2 + 2088), a2);
  v6 = (float **)*((_DWORD *)v2 + 235);
  if ( v6 && (v7 = *v6) != 0
    || (*((float *)v2 + 516) - *((float *)v2 + 515) + *((float *)v2 + 515) >= a2
      ? (v8 = (float **)*((_DWORD *)v2 + 233))
      : (v8 = (float **)*((_DWORD *)v2 + 234)),
        (*((_DWORD *)v2 + 235) = v8) != 0 && (v7 = *v8) != 0) )
  {
    if ( *v7 <= (double)a2 )
    {
      while ( 1 )
      {
        v13 = *((_DWORD *)v2 + 235);
        if ( !v13 )
          break;
        v14 = *(int **)(v13 + 4);
        *((_DWORD *)v2 + 235) = v14;
        if ( !v14 )
          break;
        v11 = *v14;
        if ( !*v14 )
          break;
        if ( *(float *)v11 >= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 234);
    }
    else
    {
      while ( 1 )
      {
        v9 = *((_DWORD *)v2 + 235);
        if ( !v9 )
          break;
        v10 = *(int **)(v9 + 8);
        *((_DWORD *)v2 + 235) = v10;
        if ( !v10 )
          break;
        v11 = *v10;
        if ( !*v10 )
          break;
        if ( *(float *)v11 <= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 233);
    }
    *((_DWORD *)v2 + 235) = v12;
    if ( v12 )
      v11 = *v12;
    else
      v11 = 0;
LABEL_34:
    v15 = (int *)*((_DWORD *)v2 + 235);
    j = -1;
    v41 = v15;
    if ( v15 )
    {
      v17 = (int *)*((_DWORD *)v2 + 233);
      for ( j = 0; v17; ++j )
      {
        if ( v17 == v15 )
          break;
        v17 = (int *)v17[1];
      }
    }
    if ( j < *((_DWORD *)v2 + 236) - 1 && v11 )
    {
      while ( *(float *)v11 < (double)a2 )
      {
        v18 = *((_DWORD *)v2 + 235);
        if ( v18 )
          *((_DWORD *)v2 + 235) = *(_DWORD *)(v18 + 4);
        v19 = (int *)*((_DWORD *)v2 + 235);
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
        sub_57A5B0(*(_DWORD *)(v11 + 4));
        sub_4D33B0(v42);
        sub_4D3400(v42, (int)(v2 + 884));
        if ( ++v39 > 64 )
          break;
        v20 = 0;
        if ( *(_WORD *)(v11 + 8) )
        {
          do
          {
            sub_4D32B0((int)(v2 + 884), *(float *)v11, (float *)Buffer);
            if ( (Buffer[0] & 0xF0000000) == 0x10000000 )
            {
              if ( (Buffer[0] & 0x3F0000) != 0 )
              {
                if ( (HIWORD(Buffer[0]) & 0x3F) <= 6u )
                  sub_4D4D60((int)v38, (int)Buffer);
              }
              else if ( (Buffer[0] & 0x3Fu) < 0x31 && Buffer[(Buffer[0] & 0x3F) + 52] )
              {
                sub_52E5D0(a2, (int)Buffer);
              }
            }
            ++v20;
          }
          while ( v20 < *(unsigned __int16 *)(v11 + 8) );
        }
        v21 = 0;
        while ( 1 )
        {
          v22 = Buffer[v21 + 52];
          if ( v22 )
          {
            if ( !(unsigned __int8)sub_52E830(v22 + 148) )
              break;
          }
          if ( ++v21 >= 49 )
          {
            if ( v39 >= 64 || sub_4D4CE0(v38) )
              goto LABEL_68;
            break;
          }
        }
        v23 = *((_DWORD *)v2 + 235);
        if ( v23 )
          *((_DWORD *)v2 + 235) = *(_DWORD *)(v23 + 8);
        v24 = (int *)*((_DWORD *)v2 + 235);
        if ( !v24 )
          break;
        v11 = *v24;
      }
      while ( *v24 );
    }
LABEL_68:
    *((_DWORD *)v2 + 235) = v41;
    if ( v41 )
      v25 = *v41;
    else
      v25 = 0;
    v26 = *((_DWORD *)v2 + 235);
    if ( v26 )
    {
      v27 = *((_DWORD *)v2 + 233);
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
            v29 = *((_DWORD *)v2 + 235);
            if ( v29 )
              *((_DWORD *)v2 + 235) = *(_DWORD *)(v29 + 8);
            v30 = (int *)*((_DWORD *)v2 + 235);
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
        sub_57A5B0(*(_DWORD *)(v25 + 4));
        sub_4D33B0(v42);
        sub_4D3400(v42, (int)(v2 + 884));
        if ( ++v40 > 64 )
          break;
        v31 = 0;
        if ( *(_WORD *)(v25 + 8) )
        {
          do
          {
            sub_4D32B0((int)(v2 + 884), *(float *)v25, (float *)Buffer);
            if ( (Buffer[0] & 0xF0000000) == 0x10000000 )
            {
              if ( (Buffer[0] & 0x3F0000) != 0 )
              {
                if ( (HIWORD(Buffer[0]) & 0x3F) <= 6u )
                  sub_4D4D60((int)v38, (int)Buffer);
              }
              else if ( (Buffer[0] & 0x3Fu) < 0x31 && Buffer[(Buffer[0] & 0x3F) + 52] )
              {
                sub_52E5D0(a2, (int)Buffer);
              }
            }
            ++v31;
          }
          while ( v31 < *(unsigned __int16 *)(v25 + 8) );
        }
        v32 = 0;
        while ( 1 )
        {
          v33 = Buffer[v32 + 52];
          if ( v33 )
          {
            if ( !(unsigned __int8)sub_52E850(v33 + 148) )
              break;
          }
          if ( ++v32 >= 49 )
          {
            if ( v40 >= 64 || sub_4D4D20(v38) )
              goto LABEL_105;
            break;
          }
        }
        v34 = *((_DWORD *)v2 + 235);
        if ( v34 )
          *((_DWORD *)v2 + 235) = *(_DWORD *)(v34 + 4);
        v35 = (int *)*((_DWORD *)v2 + 235);
        if ( !v35 )
          break;
        v25 = *v35;
      }
      while ( *v35 );
    }
  }
LABEL_105:
  sub_4D4EB0((int)v38);
  return sub_4D4FE0((int)v38);
}
