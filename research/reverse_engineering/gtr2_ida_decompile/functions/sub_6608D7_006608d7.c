int __thiscall sub_6608D7(
        _DWORD *this,
        _DWORD *a2,
        int a3,
        int a4,
        char *ArgList,
        int a6,
        _DWORD *a7,
        unsigned int a8,
        _DWORD *a9)
{
  unsigned int v9; // kr00_4
  __int32 v10; // eax
  char *v11; // ebx
  int result; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // edi
  int v16; // eax
  const char *v17; // eax
  _DWORD *v18; // edi
  int v19; // eax
  int *v20; // esi
  int v21; // eax
  _DWORD *v22; // edi
  int v23; // eax
  int *v24; // esi
  int v25; // eax
  __int16 v26; // dx
  _DWORD *v27; // edi
  int v28; // eax
  int *v29; // esi
  int v30; // eax
  int v31; // edi
  int v32; // eax
  _DWORD *v33; // ecx
  int *v34; // edi
  unsigned int v35; // eax
  const char *v36; // [esp+0h] [ebp-18h] BYREF
  char *v37; // [esp+4h] [ebp-14h]
  int v38; // [esp+8h] [ebp-10h]

  v11 = ArgList;
  if ( strlen(ArgList) <= 2 )
  {
    sub_65DD1F(a2, a4, 2005, "invalid register, input, or constant name '%s'", ArgList);
    return -2147467259;
  }
  v14 = (_DWORD *)a8;
  v15 = a7;
  *a7 = 0;
  *v14 = 0;
  *a9 = 0;
  if ( *(_WORD *)v11 == *(_WORD *)"v_" )
  {
    v16 = this[45];
    if ( v16 < 10 || v16 > 12 )
    {
      *v15 = 1;
      v18 = this + 7;
      v19 = sub_65EBEC(this + 7, v11);
      if ( v19 )
      {
        v17 = *(const char **)(v19 + 4);
        *a9 = v17;
      }
      else
      {
        v17 = (const char *)sub_65E964(v11 + 2, (char *)&a7 + 3, (char *)&ArgList + 3);
        if ( (int)v17 < 0 )
          goto LABEL_7;
        v20 = this + 39;
        v21 = *v20;
        v38 = 1;
        *a9 = v21;
        v17 = (const char *)sub_66078B(v18, v11, *v20, v38);
        ++*v20;
      }
      if ( a6 )
      {
        v38 = (int)v11;
        v37 = "addressing operations are not allowed on input registers '%s'";
        goto LABEL_61;
      }
    }
    else
    {
      v17 = (const char *)sub_65E964(v11 + 2, (char *)&a6 + 3, (char *)&ArgList + 3);
      if ( (int)v17 < 0 )
      {
LABEL_7:
        v38 = (int)v11;
        v37 = "Invalid input register '%s' specified";
LABEL_61:
        v36 = v17;
        v9 = __readeflags();
        v10 = dword_16F1C35 + dword_16C6EF8;
        __writeeflags(v9);
        _InterlockedExchange((volatile __int32 *)&v36, v10);
        sub_65DD1F(a2, a4, (int)v36, v37);
        return -2147467259;
      }
      if ( HIBYTE(a6) == 5 )
      {
        *v15 = 3;
      }
      else
      {
        if ( HIBYTE(a6) != 10 )
        {
          v38 = (int)v11;
          v37 = "Invalid pixel shader input register '%s' specified";
          goto LABEL_61;
        }
        *v15 = 1;
      }
      *a9 = HIBYTE(ArgList);
    }
    return 0;
  }
  if ( *(_WORD *)v11 == *(_WORD *)"r_" )
  {
    *v15 = 0;
    v22 = this + 21;
    v23 = sub_65EBEC(this + 21, v11);
    if ( v23 )
    {
      v17 = *(const char **)(v23 + 4);
      *a9 = v17;
    }
    else
    {
      v24 = this + 41;
      v25 = *v24;
      v38 = 1;
      *a9 = v25;
      v17 = (const char *)sub_66078B(v22, v11, *v24, v38);
      ++*v24;
    }
    if ( a6 )
    {
      v38 = (int)v11;
      v37 = "addressing operations not allowed on temporary registers '%s'";
      goto LABEL_61;
    }
    return 0;
  }
  v26 = *(_WORD *)v11;
  v17 = "b_";
  if ( *(_WORD *)v11 != *(_WORD *)"c_" && v26 != *(_WORD *)"b_" && v26 != *(_WORD *)"i_" && v26 != *(_WORD *)"s_" )
  {
    if ( !this[44] || (v17 = "o_", v26 != *(_WORD *)"o_") )
    {
      v38 = (int)v11;
      v37 = "'%s' is not a valid register name.  Registers must start with v_, r_, c_, b_, or i_ depending on the registe"
            "r type. (o_ for vs_3_0 only)";
      goto LABEL_61;
    }
    *v15 = 6;
    v27 = this + 14;
    v28 = sub_65EBEC(this + 14, v11);
    if ( v28 )
    {
      v17 = *(const char **)(v28 + 4);
      *a9 = v17;
    }
    else
    {
      v17 = (const char *)sub_65E964(v11 + 2, (char *)&a7 + 3, (char *)&ArgList + 3);
      if ( (int)v17 < 0 )
      {
        v38 = (int)v11;
        v37 = "Invalid output register '%s' specified";
        goto LABEL_61;
      }
      v29 = this + 40;
      v30 = *v29;
      v38 = 1;
      *a9 = v30;
      v17 = (const char *)sub_66078B(v27, v11, *v29, v38);
      ++*v29;
    }
    if ( a6 )
    {
      v38 = (int)v11;
      v37 = "addressing operations are not allowed on output registers '%s'";
      goto LABEL_61;
    }
    return 0;
  }
  if ( *(_WORD *)v11 == *(_WORD *)"b_" )
  {
    *v15 = 14;
    v31 = 0;
  }
  else if ( *(_WORD *)v11 == *(_WORD *)"i_" )
  {
    *v15 = 7;
    v31 = 1;
  }
  else
  {
    if ( *(_WORD *)v11 == *(_WORD *)"s_" )
    {
      *v15 = 10;
      v38 = 2;
    }
    else
    {
      *v15 = 2;
      v38 = 3;
    }
    v31 = v38;
  }
  v32 = sub_65EBEC(this, v11);
  if ( v32 )
  {
    v33 = a9;
    *a9 = *(_DWORD *)(v32 + 4);
    a8 = *(_DWORD *)(v32 + 8);
  }
  else
  {
    result = sub_680557(a4, (char)v11, (int)&a8);
    if ( result < 0 )
      return result;
    if ( !a8 )
    {
      sub_65DD1F(a2, a4, 2005, "constant register '%s' must be defined as a variable '%s'", v11, v11 + 2);
      return -2147467259;
    }
    v38 = a8;
    v34 = &this[v31 + 35];
    *a9 = *v34;
    sub_66078B(this, v11, *v34, v38);
    *v34 += a8;
    ++this[43];
    v33 = a9;
  }
  if ( a6 )
  {
    v35 = *(_DWORD *)(a6 + 24);
    if ( v35 > a8 )
    {
      sub_65DD1F(
        a2,
        a4,
        2005,
        "constant register address out of bounds on constant '%s', size %d, offset %d",
        v11,
        a8,
        v35);
      return -2147467259;
    }
    *v33 += v35;
  }
  return 0;
}
