int __cdecl sub_558A60(_DWORD *a1)
{
  bool v2; // cc
  int result; // eax
  int v4; // edi
  int *v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // eax
  double *v12; // ecx
  double v13; // st7
  __int16 *v14; // eax
  int v15; // edx
  _WORD *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  double *v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+18h] [ebp-8h]
  int v24; // [esp+1Ch] [ebp-4h]
  int (__cdecl *v25)(int, int, int, int, int); // [esp+28h] [ebp+8h]

  v2 = a1[8] <= 0;
  result = a1[102];
  v4 = a1[49];
  v24 = 0;
  v25 = 0;
  v21 = 0;
  if ( !v2 )
  {
    v5 = (int *)(result + 44);
    v6 = v4 + 36;
    for ( i = result + 44; ; i += 4 )
    {
      if ( *(_DWORD *)v6 == 1 )
      {
        v25 = sub_565C6D;
        goto LABEL_19;
      }
      if ( *(_DWORD *)v6 == 2 )
      {
        v25 = sub_565AAF;
        goto LABEL_19;
      }
      if ( *(_DWORD *)v6 == 4 )
        break;
      if ( *(_DWORD *)v6 != 8 )
      {
        *(_DWORD *)(*a1 + 20) = 6;
        *(_DWORD *)(*a1 + 24) = *(_DWORD *)v6;
LABEL_12:
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        goto LABEL_20;
      }
      v7 = a1[17];
      if ( !v7 )
      {
        v25 = sub_565CAA;
LABEL_19:
        v24 = 0;
        goto LABEL_20;
      }
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 != 1 )
        {
          *(_DWORD *)(*a1 + 20) = 47;
          goto LABEL_12;
        }
        v25 = sub_565D42;
        v24 = 2;
      }
      else
      {
        v25 = sub_565CF6;
        v24 = 1;
      }
LABEL_20:
      *(v5 - 10) = (int)v25;
      if ( *(_BYTE *)(v6 + 12) )
      {
        if ( *v5 != v24 )
        {
          v9 = *(_DWORD *)(v6 + 40);
          v19 = v9;
          if ( v9 )
          {
            *v5 = v24;
            if ( v24 )
            {
              if ( v24 == 1 )
              {
                v14 = (__int16 *)&unk_5F5AA8;
                v15 = v9 - (_DWORD)&unk_5F5AA8;
                v23 = *(_DWORD *)(v6 + 44) - (_DWORD)&unk_5F5AA8;
                do
                {
                  *(__int16 *)((char *)v14 + v23) = (*v14 * *(__int16 *)((char *)v14 + v15) + 2048) >> 12;
                  ++v14;
                }
                while ( (int)v14 < (int)word_5F5B28 );
              }
              else
              {
                v10 = *(_DWORD *)(v6 + 44);
                v11 = 0;
                v22 = (double *)word_5F5B28;
                do
                {
                  v12 = (double *)word_5F5B28;
                  do
                  {
                    v13 = (double)*(unsigned __int16 *)(v19 + 2 * v11) * *v12++;
                    *(float *)(v10 + 4 * v11++) = v13 * *v22;
                  }
                  while ( (int)v12 < (int)dbl_5F5B68 );
                  ++v22;
                }
                while ( (int)v22 < (int)dbl_5F5B68 );
              }
            }
            else
            {
              v16 = *(_WORD **)(v6 + 44);
              v17 = v9 - (_DWORD)v16;
              v18 = 64;
              do
              {
                *v16 = *(_WORD *)((char *)v16 + v17);
                ++v16;
                --v18;
              }
              while ( v18 );
            }
          }
        }
      }
      result = ++v21;
      v5 = (int *)(i + 4);
      v6 += 84;
      if ( v21 >= a1[8] )
        return result;
    }
    v25 = sub_56579A;
    goto LABEL_19;
  }
  return result;
}
