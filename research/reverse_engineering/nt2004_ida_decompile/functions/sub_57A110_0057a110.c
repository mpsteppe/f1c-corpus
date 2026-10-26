bool __thiscall sub_57A110(FILE **this, char *Source, FILE *a3, FILE *a4, char a5)
{
  bool result; // al
  FILE *v7; // eax
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // cl
  bool v14; // bl
  _DWORD v15[2]; // [esp+8h] [ebp-408h]
  char FileName[1024]; // [esp+10h] [ebp-400h] BYREF

  if ( !a5 || (result = sub_57A0C0(Source)) )
  {
    this[4] = a3;
    this[3] = a4;
    sub_57B040(Source, 1024);
    if ( a3 )
    {
      v15[1] = 0;
      v15[0] = dword_61B364;
      if ( this[4] == (FILE *)2 )
      {
        v12 = 0;
        do
        {
          v13 = byte_61B358[v12];
          *((_BYTE *)v15 + v12++) = v13;
        }
        while ( v13 );
      }
      else if ( this[4] == (FILE *)3 )
      {
        v10 = 0;
        do
        {
          v11 = byte_61B35C[v10];
          *((_BYTE *)v15 + v10++) = v11;
        }
        while ( v11 );
      }
      else if ( this[4] == (FILE *)4 )
      {
        v8 = 0;
        do
        {
          v9 = byte_61B360[v8];
          *((_BYTE *)v15 + v8++) = v9;
        }
        while ( v9 );
      }
      if ( this[3] == (FILE *)1 )
        BYTE1(v15[0]) = 116;
      v7 = (FILE *)sub_536110();
      *this = v7;
    }
    else
    {
      if ( this[3] )
        v7 = fopen(FileName, aWt_0);
      else
        v7 = fopen(FileName, aWb_0);
      *this = v7;
    }
    v14 = v7 != 0;
    if ( v7 )
    {
      *((_BYTE *)this + 24) = 0;
      sub_578600((int)(this + 1), FileName);
    }
    return v14;
  }
  return result;
}
