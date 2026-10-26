int __thiscall sub_4D2F50(char *this, int a2, float a3, float a4)
{
  char v6; // al
  float ***v7; // edi
  float **v8; // eax
  bool v9; // zf
  float *v10; // ecx
  float **v11; // esi
  float **v12; // eax
  float **v13; // eax
  float **v14; // eax
  _BYTE *v15; // eax
  _BYTE *v16; // esi
  _DWORD *v17; // eax
  _BYTE *v18; // eax
  _BYTE *v19; // esi
  _DWORD *v20; // eax
  int result; // eax
  int v22; // ecx
  float **v23; // edx
  char v24; // [esp+Bh] [ebp-1h]
  char v25; // [esp+10h] [ebp+4h]

  v25 = sub_4D2EE0(this, a2, a3);
  v6 = sub_4D2EE0(this, a2, a4);
  v7 = (float ***)&this[16 * a2 + 2304];
  v24 = v6;
  v8 = *v7;
  v9 = *v7 == 0;
  v7[2] = *v7;
  if ( !v9 )
  {
    v10 = *v8;
    if ( *v8 )
    {
      do
      {
        if ( *v10 < (double)a3 || *v10 > (double)a4 )
        {
          v13 = v7[2];
          if ( v13 )
            v7[2] = (float **)v13[1];
        }
        else
        {
          v11 = *v7;
          v12 = 0;
          if ( *v7 )
          {
            while ( *v11 != v10 )
            {
              v12 = v11;
              v11 = (float **)v11[1];
              if ( !v11 )
                goto LABEL_19;
            }
            if ( v11 == v7[2] )
              v7[2] = (float **)v11[1];
            if ( v12 )
              v12[1] = v11[1];
            else
              *v7 = (float **)v11[1];
            if ( v7[1] == v11 )
              v7[1] = v12;
            v7[3] = (float **)((char *)v7[3] - 1);
            sub_4A82F0((int)v11);
            sub_5BE8AE(v11);
          }
        }
LABEL_19:
        v14 = v7[2];
        if ( !v14 )
          break;
        v10 = *v14;
      }
      while ( *v14 );
    }
  }
  if ( !v25 )
  {
    v15 = operator new(8u);
    if ( v15 )
    {
      *(float *)v15 = a3;
      v15[4] = 1;
      v16 = v15;
    }
    else
    {
      v16 = 0;
    }
    if ( v16 )
    {
      v17 = operator new(0xCu);
      if ( v17 )
      {
        *v17 = v16;
        v17[1] = 0;
        *((_BYTE *)v17 + 8) = 1;
      }
      else
      {
        v17 = 0;
      }
      if ( *v7 )
      {
        v7[1][1] = (float *)v17;
      }
      else
      {
        *v7 = (float **)v17;
        v7[2] = (float **)v17;
      }
      v7[1] = (float **)v17;
      v7[3] = (float **)((char *)v7[3] + 1);
    }
  }
  if ( !v24 )
  {
    v18 = operator new(8u);
    if ( v18 )
    {
      *(float *)v18 = a4;
      v18[4] = 0;
      v19 = v18;
    }
    else
    {
      v19 = 0;
    }
    if ( v19 )
    {
      v20 = operator new(0xCu);
      if ( v20 )
      {
        *v20 = v19;
        v20[1] = 0;
        *((_BYTE *)v20 + 8) = 1;
      }
      else
      {
        v20 = 0;
      }
      if ( *v7 )
      {
        v7[1][1] = (float *)v20;
      }
      else
      {
        *v7 = (float **)v20;
        v7[2] = (float **)v20;
      }
      v7[1] = (float **)v20;
      v7[3] = (float **)((char *)v7[3] + 1);
    }
  }
  result = sub_4DB170(*v7);
  *v7 = (float **)result;
  if ( result && (v22 = *(_DWORD *)(result + 4)) != 0 )
  {
    do
    {
      v23 = (float **)v22;
      v22 = *(_DWORD *)(v22 + 4);
    }
    while ( v22 );
    v7[1] = v23;
    v7[2] = (float **)result;
  }
  else
  {
    v7[1] = (float **)result;
    v7[2] = (float **)result;
  }
  return result;
}
