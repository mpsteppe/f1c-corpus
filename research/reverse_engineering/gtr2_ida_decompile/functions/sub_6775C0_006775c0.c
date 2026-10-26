int __usercall sub_6775C0@<eax>(int *a1@<esi>)
{
  int result; // eax
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // edi
  int v10; // eax

  switch ( a1[9] )
  {
    case 1:
      a1[10] = 1;
      a1[11] = 1;
      goto LABEL_27;
    case 3:
      if ( !a1[71] )
      {
        if ( a1[74] )
        {
          v4 = *((unsigned __int8 *)a1 + 300);
          if ( *((_BYTE *)a1 + 300) )
          {
            if ( *((_BYTE *)a1 + 300) != 1 )
            {
              v5 = *a1;
              *(_DWORD *)(v5 + 20) = 114;
              *(_DWORD *)(v5 + 24) = v4;
              (*(void (__stdcall **)(int *, int))(v5 + 4))(a1, -1);
            }
            goto LABEL_25;
          }
          goto LABEL_16;
        }
        v6 = (int *)a1[55];
        v7 = *v6;
        v8 = v6[21];
        v9 = v6[42];
        if ( *v6 == 1 )
        {
          if ( v8 == 2 && v9 == 3 )
          {
            a1[10] = 3;
            a1[11] = 2;
            goto LABEL_27;
          }
        }
        else if ( v7 == 82 && v8 == 71 && v9 == 66 )
        {
LABEL_16:
          a1[10] = 2;
          a1[11] = 2;
LABEL_27:
          result = 0;
          goto LABEL_28;
        }
        v10 = *a1;
        *(_DWORD *)(v10 + 24) = v7;
        *(_DWORD *)(v10 + 28) = v8;
        *(_DWORD *)(v10 + 32) = v9;
        *(_DWORD *)(v10 + 20) = 111;
        (*(void (__stdcall **)(int *, int))(v10 + 4))(a1, 1);
      }
LABEL_25:
      a1[10] = 3;
      a1[11] = 2;
      goto LABEL_27;
    case 4:
      if ( a1[74] && (v2 = *((unsigned __int8 *)a1 + 300), *((_BYTE *)a1 + 300)) )
      {
        if ( *((_BYTE *)a1 + 300) != 2 )
        {
          v3 = *a1;
          *(_DWORD *)(v3 + 20) = 114;
          *(_DWORD *)(v3 + 24) = v2;
          (*(void (__stdcall **)(int *, int))(v3 + 4))(a1, -1);
        }
        a1[10] = 5;
        a1[11] = 4;
      }
      else
      {
        a1[10] = 4;
        a1[11] = 4;
      }
      goto LABEL_27;
  }
  result = 0;
  a1[10] = 0;
  a1[11] = 0;
LABEL_28:
  *((double *)a1 + 7) = 1.0;
  a1[12] = 1;
  a1[13] = 1;
  a1[16] = 0;
  a1[17] = 0;
  a1[18] = 0;
  a1[19] = 1;
  a1[20] = 1;
  a1[21] = 0;
  a1[22] = 2;
  a1[23] = 0;
  a1[24] = 256;
  a1[34] = 0;
  a1[25] = 0;
  a1[26] = 0;
  a1[27] = 0;
  return result;
}
