int __usercall sub_678570@<eax>(unsigned int a1@<eax>, int a2@<ecx>, _BYTE *a3@<edi>, int *a4@<esi>)
{
  int v4; // ebx
  char v5; // dl
  unsigned __int8 v6; // cl
  __int16 v7; // ax
  __int16 v8; // dx
  __int16 v9; // ax
  __int16 v10; // dx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  unsigned __int8 v18; // cl
  int v19; // eax
  unsigned __int8 v20; // dl
  int v21; // ebx
  int result; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax

  v4 = a1 + a2;
  if ( a1 >= 0xE && *a3 == 74 && a3[1] == 70 && a3[2] == 73 && a3[3] == 70 && !a3[4] )
  {
    v5 = a3[7];
    v6 = a3[5];
    *((_BYTE *)a4 + 289) = a3[6];
    v7 = (unsigned __int8)a3[8];
    *((_BYTE *)a4 + 290) = v5;
    v8 = (unsigned __int8)a3[9];
    a4[71] = 1;
    *((_BYTE *)a4 + 288) = v6;
    v9 = v8 + (v7 << 8);
    v10 = (unsigned __int8)a3[11];
    *((_WORD *)a4 + 146) = v9;
    *((_WORD *)a4 + 147) = v10 + ((unsigned __int8)a3[10] << 8);
    if ( v6 != 1 )
    {
      v11 = *a4;
      v12 = (unsigned __int8)a3[6];
      *(_DWORD *)(v11 + 20) = 119;
      *(_DWORD *)(v11 + 24) = v6;
      *(_DWORD *)(v11 + 28) = v12;
      (*(void (__stdcall **)(int *, int))(v11 + 4))(a4, -1);
    }
    v13 = *a4;
    v14 = *((unsigned __int8 *)a4 + 289);
    *(_DWORD *)(v13 + 24) = *((unsigned __int8 *)a4 + 288);
    v15 = *((unsigned __int16 *)a4 + 146);
    *(_DWORD *)(v13 + 28) = v14;
    v16 = *((unsigned __int16 *)a4 + 147);
    *(_DWORD *)(v13 + 32) = v15;
    v17 = *((unsigned __int8 *)a4 + 290);
    *(_DWORD *)(v13 + 36) = v16;
    *(_DWORD *)(v13 + 40) = v17;
    *(_DWORD *)(v13 + 20) = 87;
    (*(void (__stdcall **)(int *, int))(v13 + 4))(a4, 1);
    v18 = a3[13];
    if ( *((_WORD *)a3 + 6) )
    {
      v19 = *a4;
      v20 = a3[12];
      *(_DWORD *)(v19 + 20) = 90;
      *(_DWORD *)(v19 + 24) = v20;
      *(_DWORD *)(v19 + 28) = v18;
      (*(void (__stdcall **)(int *, int))(v19 + 4))(a4, 1);
    }
    v21 = v4 - 14;
    result = 3 * (unsigned __int8)a3[13] * (unsigned __int8)a3[12];
    if ( v21 != result )
    {
      v23 = *a4;
      *(_DWORD *)(v23 + 20) = 88;
      *(_DWORD *)(v23 + 24) = v21;
      return (*(int (__stdcall **)(int *, int))(v23 + 4))(a4, 1);
    }
  }
  else if ( a1 >= 6 && *a3 == 74 && a3[1] == 70 && a3[2] == 88 && a3[3] == 88 && !a3[4] )
  {
    v24 = (unsigned __int8)a3[5];
    if ( v24 == 16 )
    {
      v27 = *a4;
      *(_DWORD *)(v27 + 20) = 108;
      *(_DWORD *)(v27 + 24) = v4;
      return (*(int (__stdcall **)(int *, int))(v27 + 4))(a4, 1);
    }
    else if ( a3[5] == 17 )
    {
      v26 = *a4;
      *(_DWORD *)(v26 + 20) = 109;
      *(_DWORD *)(v26 + 24) = v4;
      return (*(int (__stdcall **)(int *, int))(v26 + 4))(a4, 1);
    }
    else
    {
      v25 = *a4;
      if ( a3[5] == 19 )
      {
        *(_DWORD *)(v25 + 20) = 110;
        *(_DWORD *)(v25 + 24) = v4;
      }
      else
      {
        *(_DWORD *)(v25 + 20) = 89;
        *(_DWORD *)(v25 + 24) = v24;
        *(_DWORD *)(v25 + 28) = v4;
      }
      return (*(int (__stdcall **)(int *, int))(v25 + 4))(a4, 1);
    }
  }
  else
  {
    v28 = *a4;
    *(_DWORD *)(v28 + 20) = 77;
    *(_DWORD *)(v28 + 24) = v4;
    return (*(int (__stdcall **)(int *, int))(v28 + 4))(a4, 1);
  }
  return result;
}
