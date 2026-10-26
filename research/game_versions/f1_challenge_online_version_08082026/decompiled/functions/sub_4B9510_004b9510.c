void __thiscall sub_4B9510(int this, float a2, float a3, char a4)
{
  double v5; // st7
  double v6; // st7
  float **v7; // eax
  float *v8; // eax
  float **v9; // eax
  int v10; // eax
  float **v11; // eax
  float *v12; // eax
  int v13; // eax
  int *v14; // eax
  int v15; // esi
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // ebp
  _DWORD *v20; // ecx
  int v21; // eax
  int *v22; // eax
  _DWORD v23[3]; // [esp+4h] [ebp-1BCh] BYREF
  int v24[108]; // [esp+10h] [ebp-1B0h] BYREF

  if ( a2 != a3 )
  {
    if ( a4 )
    {
      v5 = a3 - 1.6670001;
      if ( a2 < v5 )
        a2 = v5;
    }
    else
    {
      v6 = a2 + 1.6670001;
      if ( a3 > v6 )
        a3 = v6;
    }
    if ( (v7 = *(float ***)(this + 1820)) != 0 && (v8 = *v7) != 0
      || (*(float *)(this + 3892) - *(float *)(this + 3888) + *(float *)(this + 3888) >= a2
        ? (v9 = *(float ***)(this + 1812))
        : (v9 = *(float ***)(this + 1816)),
          (*(_DWORD *)(this + 1820) = v9) != 0 && (v8 = *v9) != 0) )
    {
      if ( *v8 <= (double)a2 )
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)(this + 1820);
          if ( !v17 )
            break;
          v18 = *(int **)(v17 + 4);
          *(_DWORD *)(this + 1820) = v18;
          if ( !v18 )
            break;
          v15 = *v18;
          if ( !*v18 )
            break;
          if ( *(float *)v15 >= (double)a2 )
            goto LABEL_29;
        }
      }
      else
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(this + 1820);
          if ( !v10 )
            break;
          v11 = *(float ***)(v10 + 8);
          *(_DWORD *)(this + 1820) = v11;
          if ( !v11 )
            break;
          v12 = *v11;
          if ( !v12 )
            break;
          if ( *v12 < (double)a2 )
          {
            v13 = *(_DWORD *)(this + 1820);
            if ( v13 )
              *(_DWORD *)(this + 1820) = *(_DWORD *)(v13 + 4);
            v14 = *(int **)(this + 1820);
            if ( v14 )
            {
              v15 = *v14;
              goto LABEL_29;
            }
            return;
          }
        }
        v16 = *(int **)(this + 1812);
        *(_DWORD *)(this + 1820) = v16;
        if ( !v16 )
          return;
        v15 = *v16;
LABEL_29:
        if ( v15 )
        {
          do
          {
            if ( *(float *)v15 > (double)a3 )
              break;
            sub_566DB0(*(_DWORD *)(v15 + 4));
            sub_4B4450(v23);
            sub_4B44A0(v23, this + 1764);
            v19 = 0;
            if ( *(_WORD *)(v15 + 8) )
            {
              do
              {
                sub_4B4360(this + 1764, *(float *)v15, (int)v24);
                if ( (v24[0] & 0xE0000000) != 0x20000000 )
                {
                  if ( dword_83EE60 >= 1023 )
                  {
                    v20 = (_DWORD *)dword_8AAE64;
                  }
                  else
                  {
                    ++dword_83EE60;
                    v20 = (_DWORD *)dword_8AAE64;
                    dword_8AAE64 += 432;
                  }
                  sub_4B3A90(v20, v24);
                }
                ++v19;
              }
              while ( v19 < *(unsigned __int16 *)(v15 + 8) );
            }
            v21 = *(_DWORD *)(this + 1820);
            if ( v21 )
              *(_DWORD *)(this + 1820) = *(_DWORD *)(v21 + 4);
            v22 = *(int **)(this + 1820);
            if ( !v22 )
              break;
            v15 = *v22;
          }
          while ( *v22 );
        }
      }
    }
  }
}
