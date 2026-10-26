const char *__thiscall sub_4ECF20(const char ****this, char *String1, int a3, int a4)
{
  const char ***v5; // eax
  bool v6; // zf
  const char **v7; // edi
  const char *v8; // eax
  const char ***v9; // eax
  const char ***v10; // eax
  const char **v11; // eax
  const char ***v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  const char *result; // eax
  int v17; // esi
  _DWORD *v18; // eax

  v5 = *this;
  v6 = *this == 0;
  this[2] = *this;
  if ( v6 || (v7 = *v5) == 0 )
  {
LABEL_9:
    v11 = (const char **)operator new(0x28u);
    if ( v11 )
    {
      *v11 = 0;
      v11[1] = (const char *)-1;
      v11[2] = 0;
      v11[3] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v11[8] = 0;
      v11[9] = 0;
      v7 = v11;
    }
    else
    {
      v7 = 0;
    }
    sub_578600(String1);
    if ( v7 )
    {
      v12 = (const char ***)operator new(0xCu);
      if ( v12 )
      {
        *v12 = v7;
        v12[1] = 0;
        *((_BYTE *)v12 + 8) = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *this )
      {
        this[1][1] = (const char **)v12;
      }
      else
      {
        *this = v12;
        this[2] = v12;
      }
      this[1] = v12;
      this[3] = (const char ***)((char *)this[3] + 1);
    }
  }
  else
  {
    while ( 1 )
    {
      v8 = *v7;
      if ( !*v7 )
        v8 = &byte_629120;
      if ( !_strcmpi(String1, v8) )
        break;
      v9 = this[2];
      if ( v9 )
      {
        v10 = (const char ***)v9[1];
        this[2] = v10;
        if ( v10 )
        {
          v7 = *v10;
          if ( *v10 )
            continue;
        }
      }
      goto LABEL_9;
    }
  }
  v13 = operator new(8u);
  v14 = v13;
  if ( v13 )
  {
    *v13 = 0;
    v13[1] = -1;
    sub_578600(a3);
  }
  else
  {
    v14 = 0;
  }
  if ( v14 )
  {
    v15 = operator new(0xCu);
    if ( v15 )
    {
      *v15 = v14;
      v15[1] = 0;
      *((_BYTE *)v15 + 8) = 1;
    }
    else
    {
      v15 = 0;
    }
    if ( v7[2] )
    {
      *((_DWORD *)v7[3] + 1) = v15;
    }
    else
    {
      v7[2] = (const char *)v15;
      v7[4] = (const char *)v15;
    }
    v7[3] = (const char *)v15;
    ++v7[5];
  }
  result = (const char *)operator new(8u);
  v17 = (int)result;
  if ( result )
  {
    *(_DWORD *)result = 0;
    *((_DWORD *)result + 1) = -1;
    result = (const char *)sub_578600(a4);
  }
  else
  {
    v17 = 0;
  }
  if ( v17 )
  {
    v18 = operator new(0xCu);
    if ( v18 )
      result = (const char *)sub_4DB610(v18, v17, 1);
    else
      result = 0;
    if ( v7[6] )
    {
      *((_DWORD *)v7[7] + 1) = result;
    }
    else
    {
      v7[6] = result;
      v7[8] = result;
    }
    v7[7] = result;
    ++v7[9];
  }
  return result;
}
