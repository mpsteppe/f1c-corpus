char __thiscall sub_4E6000(int this)
{
  char result; // al
  int v3; // edi
  double v4; // st7
  float v5; // edi
  int v6; // ebx
  int v7; // eax
  const char *v8; // eax
  float v9; // [esp+0h] [ebp-10h]

  result = sub_42DBA0();
  if ( result )
  {
    if ( dword_7D5DA4 != 2 && *(_DWORD *)dword_7689CC != 6 )
    {
      sub_4E5EE0((_DWORD *)this);
      result = *(_BYTE *)(this + 84);
      if ( result )
      {
        result = dword_75CBB0;
        if ( dword_75CBB0 != 7 )
        {
LABEL_32:
          *(_BYTE *)(this + 84) = 0;
          return result;
        }
        v3 = *(_DWORD *)(dword_75AACC + 20876);
        sub_4E61A0(this);
        sub_4E61F0(v3);
        if ( *(_DWORD *)dword_7689CC == 8 )
        {
          v4 = (double)dword_7687EC;
        }
        else if ( *(_DWORD *)dword_7689CC == 4 )
        {
          v4 = (double)dword_768834;
        }
        else
        {
          if ( dword_7690A4 <= 0 )
          {
LABEL_13:
            sub_4E62D0(flt_768DF8);
            result = dword_7689CC[0];
            if ( (*(_DWORD *)dword_7689CC == 4 || *(_DWORD *)dword_7689CC == 3 || *(_DWORD *)dword_7689CC == 8)
              && v3 == 1 )
            {
              result = sub_4E61E0(this);
            }
            if ( dword_75CBB0 == 7 )
            {
              v5 = *(float *)(dword_75AACC + 20884);
              sub_4E6250(v5);
              if ( LODWORD(v5) == 1 )
                sub_4E61D0(this);
              result = dword_7689CC[0];
              if ( *(_DWORD *)dword_7689CC == 4 || *(_DWORD *)dword_7689CC == 3 || *(_DWORD *)dword_7689CC == 8 )
              {
                v6 = 0;
                if ( sub_57AE50(aSeasonscoringi) )
                {
                  v7 = sub_57A700(LODWORD(v5) - 1);
                  if ( v7 )
                  {
                    v8 = (const char *)sub_57A6D0(v7);
                    v6 = atol(v8);
                  }
                }
                if ( sub_4DEBD0((_DWORD *)(dword_75AACC + 20836)) )
                  v6 += 5;
                if ( sub_4DEB90((_DWORD *)(dword_75AACC + 20836)) )
                  v6 += 5;
                result = sub_4E61B0(v6);
              }
            }
            goto LABEL_32;
          }
          v4 = (double)dword_768684;
        }
        v9 = v4;
        sub_4E6360(v9);
        goto LABEL_13;
      }
    }
  }
  return result;
}
