FILE *__thiscall sub_4306B0(size_t *this, char *FileName)
{
  FILE *result; // eax
  FILE *v4; // ebx
  int v5; // eax
  int v6; // eax
  void *v7; // eax
  int v8; // edi
  int v9; // eax
  size_t v10; // eax
  void *v11; // ecx
  int v12; // edi
  int v13; // eax
  unsigned int v14; // [esp-8h] [ebp-338h]
  int v15; // [esp+10h] [ebp-320h] BYREF
  int v16; // [esp+14h] [ebp-31Ch] BYREF
  _BYTE v17[384]; // [esp+18h] [ebp-318h] BYREF
  int v18; // [esp+198h] [ebp-198h]
  char v19; // [esp+19Ch] [ebp-194h]
  int v20; // [esp+1A4h] [ebp-18Ch]
  int v21; // [esp+1A8h] [ebp-188h]
  int v22; // [esp+1ACh] [ebp-184h]
  char Str[384]; // [esp+1B0h] [ebp-180h] BYREF

  memset(Str, 0, sizeof(Str));
  v18 = 0;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 1;
  sub_430670(this);
  result = fopen(FileName, aR);
  v4 = result;
  if ( result )
  {
    if ( fgets(Str, 384, result) )
    {
      do
      {
        if ( !sub_577B60(v17) )
        {
          if ( strstr(Str, aGearRatios) )
          {
            *this = 0;
            while ( fgets(Str, 384, v4) )
            {
              v5 = sub_577B60(v17);
              if ( v5 == 1 || v5 == 4 )
                break;
              if ( !v5 && sub_578110(aRatio, (int)&v15, (int)&v16, 0, 0) )
                ++*this;
            }
          }
          else if ( strstr(Str, aFinalDrive) )
          {
            this[2] = 0;
            while ( fgets(Str, 384, v4) )
            {
              v6 = sub_577B60(v17);
              if ( v6 == 1 || v6 == 4 )
                break;
              if ( !v6 && sub_578110(aRatio, (int)&v15, (int)&v16, 0, 0) )
                ++this[2];
            }
          }
        }
      }
      while ( fgets(Str, 384, v4) );
    }
    v7 = operator new(8 * *this);
    v14 = 8 * this[2];
    this[1] = (size_t)v7;
    this[3] = (size_t)operator new(v14);
    fseek(v4, 0, 0);
    while ( fgets(Str, 384, v4) )
    {
      if ( !sub_577B60(v17) )
      {
        if ( strstr(Str, aGearRatios) )
        {
          if ( fgets(Str, 384, v4) )
          {
            v8 = 0;
            do
            {
              v9 = sub_577B60(v17);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 )
              {
                if ( sub_578110(aRatio, v8 + this[1], v8 + this[1] + 4, 0, 0) )
                  v8 += 8;
              }
            }
            while ( fgets(Str, 384, v4) );
          }
          v10 = *this;
          v11 = (void *)this[1];
LABEL_44:
          qsort(v11, v10, 8u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_4304C0);
          continue;
        }
        if ( strstr(Str, aFinalDrive) )
        {
          if ( fgets(Str, 384, v4) )
          {
            v12 = 0;
            do
            {
              v13 = sub_577B60(v17);
              if ( v13 == 1 || v13 == 4 )
                break;
              if ( !v13 )
              {
                sub_578110(aBevel, (int)(this + 4), (int)(this + 5), 0, 0);
                if ( sub_578110(aRatio, v12 + this[3], v12 + this[3] + 4, 0, 0) )
                  v12 += 8;
              }
            }
            while ( fgets(Str, 384, v4) );
          }
          v10 = this[2];
          v11 = (void *)this[3];
          goto LABEL_44;
        }
      }
    }
    return (FILE *)fclose(v4);
  }
  return result;
}
