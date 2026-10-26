void __thiscall sub_537D80(int *this)
{
  int v2; // edi
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  _DWORD *v10; // eax
  char *v11; // eax

  if ( !(_BYTE)dword_757C1C || dword_BE1204 == 2 )
    return;
  v2 = dword_BE1CD8 + 396 * dword_BE1CD4;
  if ( v2 )
    v3 = sub_534F70();
  else
    v3 = (int)this;
  v4 = dword_91E084;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 28) += *(_DWORD *)(dword_91E084 + 19284);
    v4 = dword_91E084;
    if ( *(float *)(dword_91E084 + 19436) > 0.0
      && (*(float *)(v3 + 32) > (double)*(float *)(dword_91E084 + 19436) || *(float *)(v3 + 32) <= 0.0) )
    {
      *(_DWORD *)(v3 + 32) = *(_DWORD *)(dword_91E084 + 19436);
      v4 = dword_91E084;
    }
  }
  if ( v2 )
  {
    v5 = sub_537BA0(this + 39, v2 + 4, v4 + 21808, dword_B72338);
    if ( v5 )
    {
      *(_DWORD *)(v5 + 28) += *(_DWORD *)(dword_91E084 + 19284);
      v4 = dword_91E084;
      if ( *(float *)(dword_91E084 + 19468) <= 0.0
        || *(float *)(v5 + 32) <= (double)*(float *)(dword_91E084 + 19468) && *(float *)(v5 + 32) > 0.0 )
      {
        goto LABEL_18;
      }
      *(_DWORD *)(v5 + 32) = *(_DWORD *)(dword_91E084 + 19468);
    }
    v4 = dword_91E084;
  }
LABEL_18:
  v6 = *(_DWORD *)(v4 + 19284);
  this[9] += v6;
  if ( v6 > 0 )
    this[dword_B72338 + 44] += v6;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    v7 = *(_DWORD *)(dword_91E084 + 19324);
    sub_535110((int)this, v7);
    v8 = dword_91E084;
    if ( *(_DWORD *)(dword_91E084 + 19380) == 2 )
    {
      if ( v7 == 1 )
      {
        ++this[14];
        ++this[dword_B72338 + 59];
        v8 = dword_91E084;
      }
      if ( *(_DWORD *)dword_B72314 == 4 || *(_DWORD *)dword_B72314 == 3 )
      {
        v9 = 0;
        if ( *(_DWORD *)(v8 + 19380) != 3
          && *(_DWORD *)(v8 + 19284) >= (int)(unsigned __int64)((double)dword_FADE18 * 0.2)
          && sub_616840("SeasonScoringInfo") )
        {
          v10 = (_DWORD *)sub_616610(v7 - 1);
          if ( v10 )
          {
            v11 = sub_48D380(v10);
            v9 = atol(v11);
          }
        }
        sub_535050(this, v9);
      }
    }
  }
}
