void __thiscall sub_426340(int this, int a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // edi
  double v6; // st7
  int v7; // eax
  int v8; // edx
  double v9; // st7
  int v10; // edx
  double v11; // st7
  int v12; // edx
  int v13; // eax
  int v14; // eax
  float v15; // [esp+10h] [ebp-10h]
  _DWORD *v16; // [esp+14h] [ebp-Ch]
  float v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  float v19; // [esp+24h] [ebp+4h]

  v3 = (a2 << 7) + this;
  if ( *(_BYTE *)(v3 + 21253) )
  {
    v15 = 2.25;
    v4 = 3;
  }
  else
  {
    v15 = 4.5;
    v4 = 1;
  }
  v5 = 0;
  v18 = v4;
  v16 = (_DWORD *)(v3 + 21260);
  v17 = -v15;
  do
  {
    *(_DWORD *)(v3 + 21296) = *v16;
    *(_DWORD *)(v3 + 21300) = v16[1];
    *(_DWORD *)(v3 + 21304) = v16[2];
    v6 = *(float *)(v3 + 21304);
    if ( dword_75CBB0 == 7
      && *(float *)(v3 + 21304) < 0.0
      && !dword_7D7540
      && *(_DWORD *)(*(_DWORD *)(v3 + 21256) + 20848) > *(_DWORD *)(this + 20848) )
    {
      *(_BYTE *)(this + 56) = 1;
    }
    v7 = *(_DWORD *)(*(_DWORD *)(v3 + 21256) + 24240);
    if ( v7 && v7 != *(_DWORD *)(this + 24240) )
      *(_BYTE *)(this + 56) = 1;
    if ( v6 <= v17 || v6 >= v15 )
    {
      if ( v6 > v17 || *(float *)(v3 + 21304) < -30.0 )
      {
        if ( v6 < v15 )
          goto LABEL_62;
        v19 = *(float *)(v3 + 21320);
        if ( *(float *)(v3 + 21304) < 10.0 )
          v19 = *(float *)(v3 + 21296);
        if ( v19 >= -2.0 && ((v12 = *(_DWORD *)(this + 24064), v12 == -1) || v19 >= 0.0) )
        {
          if ( v19 > 2.0 )
            goto LABEL_50;
          if ( v12 == -1 )
          {
            *(_DWORD *)(this + 24064) = a2;
            *(_DWORD *)(this + 24096) = v5;
            goto LABEL_62;
          }
          if ( v19 > 0.0 )
          {
LABEL_50:
            if ( a2 == v12 )
              return;
            v13 = *(_DWORD *)(this + 24072);
            if ( (v13 == -1 || *(float *)((v13 << 7) + this + 21344) > (double)*(float *)(v3 + 21344))
              && *(float *)(v3 + 21304) < 45.0
              && *(float *)(v3 + 21296) < 6.0 )
            {
              *(_DWORD *)(this + 24072) = a2;
              *(_DWORD *)(this + 24104) = v5;
            }
          }
        }
        else
        {
          if ( a2 == *(_DWORD *)(this + 24064) )
            return;
          v14 = *(_DWORD *)(this + 24068);
          if ( (v14 == -1 || *(float *)((v14 << 7) + this + 21344) > (double)*(float *)(v3 + 21344))
            && *(float *)(v3 + 21304) < 45.0
            && *(float *)(v3 + 21296) > -6.0 )
          {
            *(_DWORD *)(this + 24068) = a2;
            *(_DWORD *)(this + 24100) = v5;
          }
        }
      }
      else if ( *(float *)(v3 + 21296) >= -1.0 )
      {
        if ( *(float *)(v3 + 21296) > 1.0 && *(_DWORD *)(this + 24088) == -1 )
        {
          *(_DWORD *)(this + 24088) = a2;
          *(_DWORD *)(this + 24120) = v5;
        }
      }
      else if ( *(_DWORD *)(this + 24084) == -1 )
      {
        *(_DWORD *)(this + 24084) = a2;
        *(_DWORD *)(this + 24116) = v5;
      }
    }
    else if ( *(float *)(v3 + 21296) >= 0.0 )
    {
      if ( *(float *)(this + 24044) > (double)*(float *)(v3 + 21296) )
      {
        if ( *(float *)(v3 + 21296) < 6.0 )
        {
          v10 = *(_DWORD *)(v3 + 21256);
          if ( *(float *)(v10 + 23860) <= (double)*(float *)(this + 23860) )
            v11 = *(float *)(v10 + 23860);
          else
            v11 = *(float *)(this + 23860);
          *(float *)(this + 23860) = v11;
          *(_DWORD *)(this + 24080) = a2;
          *(_DWORD *)(this + 24112) = v5;
          *(_DWORD *)(this + 24696) = -1082130432;
        }
        *(_DWORD *)(this + 24044) = *(_DWORD *)(v3 + 21296);
      }
    }
    else if ( *(float *)(this + 24040) < (double)*(float *)(v3 + 21296) )
    {
      if ( *(float *)(v3 + 21296) > -6.0 )
      {
        v8 = *(_DWORD *)(v3 + 21256);
        if ( *(float *)(v8 + 23864) <= (double)*(float *)(this + 23864) )
          v9 = *(float *)(v8 + 23864);
        else
          v9 = *(float *)(this + 23864);
        *(float *)(this + 23864) = v9;
        *(_DWORD *)(this + 24076) = a2;
        *(_DWORD *)(this + 24108) = v5;
        *(_DWORD *)(this + 24696) = -1082130432;
      }
      *(_DWORD *)(this + 24040) = *(_DWORD *)(v3 + 21296);
    }
LABEL_62:
    ++v5;
    v16 += 3;
  }
  while ( v5 < v18 );
}
