// positive sp value has been detected, the output may be wrong!
int __usercall sub_410A4A@<eax>(int a1@<eax>, _DWORD *a2@<ecx>)
{
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  void *v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  char ***v11; // eax
  char **v12; // esi
  char *v13; // edx
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  int v16; // eax
  int v17; // eax
  char ***v18; // eax
  int result; // eax
  char **i; // esi
  char *v21; // edx
  _DWORD *v22; // eax
  _DWORD *v23; // esi
  char *v24; // eax
  int v25; // eax
  char v26[8]; // [esp-F0h] [ebp-100h] BYREF
  char v27[240]; // [esp-E8h] [ebp-F8h] BYREF

  LOBYTE(a1) = BYTE1(a2) + a1;
  ++a2[16443];
  *(&byte_629120 + a1) += BYTE1(a1);
  v27[0] = a1;
  v3 = (_DWORD *)a2[37];
  memset(&v27[1], 0, 0xFCu);
  v4 = a2 + 37;
  while ( v3 )
  {
    v5 = v3;
    v3 = (_DWORD *)v3[1];
    sub_4145A0(v5);
    sub_5BE8AE(v5);
  }
  *v4 = 0;
  a2[38] = 0;
  a2[39] = 0;
  a2[40] = 0;
  if ( a2[20] == -1 && sub_410970(aNoresearch, v27, 0xFFu) )
  {
    v6 = operator new(8u);
    if ( v6 )
    {
      *v6 = 0;
      v6[1] = -1;
      sub_578600(v27);
    }
    else
    {
      v6 = 0;
    }
    if ( v6 )
    {
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *v7 = v6;
        v7[1] = 0;
        *((_BYTE *)v7 + 8) = 1;
      }
      else
      {
        v7 = 0;
      }
      if ( *v4 )
      {
        *(_DWORD *)(a2[38] + 4) = v7;
      }
      else
      {
        *v4 = v7;
        a2[39] = v7;
      }
      a2[38] = v7;
      ++a2[40];
    }
  }
  if ( sub_410460(a2) && (int)a2[14] > 0 && sub_410970(aSponsorspaceav, v27, 0xFFu) )
  {
    v8 = operator new(8u);
    v9 = v8;
    if ( v8 )
    {
      *v8 = 0;
      v8[1] = -1;
      sub_578600(v27);
    }
    else
    {
      v9 = 0;
    }
    if ( v9 )
    {
      if ( operator new(0xCu) )
        v10 = sub_4DB610(v9, 1);
      else
        v10 = 0;
      if ( *v4 )
      {
        *(_DWORD *)(a2[38] + 4) = v10;
      }
      else
      {
        *v4 = v10;
        a2[39] = v10;
      }
      a2[38] = v10;
      ++a2[40];
    }
  }
  v11 = (char ***)a2[3];
  a2[5] = v11;
  if ( v11 )
  {
    v12 = *v11;
    if ( *v11 )
    {
      do
      {
        if ( !sub_410500(a2, (int)v12) && sub_410970(aSponsorunhappy, v27, 0xFFu) )
        {
          v13 = *v12;
          if ( !*v12 )
            v13 = &byte_629120;
          sub_40C5C0(aSponsor, v13, v27, 0xFFu);
          v14 = operator new(8u);
          v15 = v14;
          if ( v14 )
          {
            *v14 = 0;
            v14[1] = -1;
            sub_578600(v27);
          }
          else
          {
            v15 = 0;
          }
          if ( v15 )
          {
            if ( operator new(0xCu) )
              v16 = sub_4DB610(v15, 1);
            else
              v16 = 0;
            if ( *v4 )
            {
              *(_DWORD *)(a2[38] + 4) = v16;
            }
            else
            {
              *v4 = v16;
              a2[39] = v16;
            }
            a2[38] = v16;
            ++a2[40];
          }
        }
        v17 = a2[5];
        if ( !v17 )
          break;
        v18 = *(char ****)(v17 + 4);
        a2[5] = v18;
        if ( !v18 )
          break;
        v12 = *v18;
      }
      while ( *v18 );
    }
  }
  result = a2[11];
  a2[13] = result;
  if ( result )
  {
    for ( i = *(char ***)result; *(_DWORD *)result; i = *(char ***)result )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, char **, _DWORD))(*a2 + 112))(a2, i, 0) )
      {
        if ( sub_410970(aSponsorpossibl, v26, 0xFFu) )
        {
          v21 = *i;
          if ( !*i )
            v21 = &byte_629120;
          sub_40C5C0(aSponsor, v21, v26, 0xFFu);
          v22 = operator new(8u);
          v23 = v22;
          if ( v22 )
          {
            *v22 = 0;
            v22[1] = -1;
            sub_578600(v26);
            sub_414410(v23, 1);
          }
          else
          {
            sub_414410(0, 1);
          }
        }
      }
      else if ( sub_410970(aSponsorinteres, v26, 0xFFu) )
      {
        v24 = (char *)((int (__thiscall *)(char **))sub_410E00)(i);
        sub_40C5C0(aSponsor, v24, v26, 0xFFu);
        if ( operator new(8u) )
          v25 = sub_410DE0(v26);
        else
          v25 = 0;
        sub_414410(v25, 1);
      }
      result = a2[13];
      if ( !result )
        break;
      result = *(_DWORD *)(result + 4);
      a2[13] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
