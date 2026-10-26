char __thiscall sub_56DF50(_DWORD *this, float *a2)
{
  int v2; // eax
  _DWORD *v3; // edx
  int v4; // eax
  _DWORD *v5; // edx
  _DWORD *i; // edx
  int v7; // edx
  int *v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  float v14; // eax
  float v16; // ecx

  v14 = *a2;
  if ( *(_DWORD *)a2 )
  {
    if ( !*((_BYTE *)a2 + 64) )
    {
      sub_5DAC60(LODWORD(v14), 0);
      sub_5DB2B0(*((_DWORD *)a2 + 1), *((_DWORD *)a2 + 2), *((_DWORD *)a2 + 3), a2[4], a2[5], a2[6]);
      *((_BYTE *)a2 + 64) = 1;
      LOBYTE(v14) = sub_56AE80(this, this[760], 1);
      v16 = *a2;
      if ( dword_BE1204 != 2 )
      {
        v2 = 0;
        if ( *(int *)&algn_91BF9C[52] <= 0 )
        {
LABEL_10:
          v4 = 0;
          if ( *(int *)&algn_91BF9C[64] <= 0 )
          {
LABEL_14:
            v14 = 0.0;
            if ( *(int *)&algn_91BF9C[76] <= 0 )
              return LOBYTE(v14);
            for ( i = (_DWORD *)(*(_DWORD *)&algn_91BF9C[84] + 216); LODWORD(v16) != *i; i += 202 )
            {
              ++LODWORD(v14);
              if ( SLODWORD(v14) >= *(int *)&algn_91BF9C[76] )
                return LOBYTE(v14);
            }
            v12 = 40 * LODWORD(v14);
            v8 = (int *)(40 * LODWORD(v14) + *(_DWORD *)&algn_91BF9C[80]);
            v13 = *v8;
            if ( *v8 != -1 )
            {
              --dword_91BF88;
              *(_DWORD *)(dword_91BF90 + 4 * v13) = *(_DWORD *)(dword_91BF90 + 4 * dword_91BF88);
              **(_DWORD **)(dword_91BF90 + 4 * v13) = v13;
              *v8 = -1;
              LOBYTE(v14) = sub_52F4B0(v12 + *(_DWORD *)&algn_91BF9C[80]);
              return LOBYTE(v14);
            }
          }
          else
          {
            v5 = (_DWORD *)(*(_DWORD *)&algn_91BF9C[72] + 216);
            while ( LODWORD(v16) != *v5 )
            {
              ++v4;
              v5 += 202;
              if ( v4 >= *(int *)&algn_91BF9C[64] )
                goto LABEL_14;
            }
            v10 = 40 * v4;
            v8 = (int *)(*(_DWORD *)&algn_91BF9C[68] + 40 * v4);
            v11 = *v8;
            if ( *v8 != -1 )
            {
              --dword_91BF88;
              *(_DWORD *)(dword_91BF90 + 4 * v11) = *(_DWORD *)(dword_91BF90 + 4 * dword_91BF88);
              **(_DWORD **)(dword_91BF90 + 4 * v11) = v11;
              *v8 = -1;
              LOBYTE(v14) = sub_52F4B0(v10 + *(_DWORD *)&algn_91BF9C[68]);
              return LOBYTE(v14);
            }
          }
        }
        else
        {
          v3 = (_DWORD *)(*(_DWORD *)&algn_91BF9C[60] + 216);
          while ( LODWORD(v16) != *v3 )
          {
            ++v2;
            v3 += 206;
            if ( v2 >= *(int *)&algn_91BF9C[52] )
              goto LABEL_10;
          }
          v7 = 40 * v2;
          v8 = (int *)(*(_DWORD *)&algn_91BF9C[56] + 40 * v2);
          if ( *v8 != -1 )
          {
            v9 = *v8;
            --dword_91BF88;
            *(_DWORD *)(dword_91BF90 + 4 * v9) = *(_DWORD *)(dword_91BF90 + 4 * dword_91BF88);
            **(_DWORD **)(dword_91BF90 + 4 * v9) = v9;
            *v8 = -1;
            LOBYTE(v14) = sub_52F4B0(v7 + *(_DWORD *)&algn_91BF9C[56]);
            return LOBYTE(v14);
          }
        }
        LOBYTE(v14) = sub_52F560(dword_BE1258, (int)v8);
      }
    }
  }
  return LOBYTE(v14);
}
