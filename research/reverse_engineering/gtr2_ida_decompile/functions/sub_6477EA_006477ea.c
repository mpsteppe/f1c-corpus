int __thiscall sub_6477EA(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // eax
  unsigned int v5; // eax
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // eax
  void *v10; // eax
  char *i; // ebx
  int *v13; // esi
  _BYTE *v14; // eax
  int *v15; // ecx
  int v16; // ebx
  unsigned __int16 v17; // dx
  size_t v18; // [esp-4h] [ebp-2B4h]
  void (__cdecl __noreturn *v19[2])(int); // [esp+Ch] [ebp-2A4h] BYREF
  int (__stdcall *v20)(int); // [esp+14h] [ebp-29Ch]
  char v21[64]; // [esp+90h] [ebp-220h] BYREF
  ULONG_PTR Parameter; // [esp+D0h] [ebp-1E0h] BYREF
  int v23; // [esp+D4h] [ebp-1DCh]
  _DWORD *v24; // [esp+E8h] [ebp-1C8h]
  int v25; // [esp+118h] [ebp-198h]
  unsigned int v26; // [esp+140h] [ebp-170h]
  unsigned int v27; // [esp+144h] [ebp-16Ch]
  int v28; // [esp+14Ch] [ebp-164h]
  unsigned int v29; // [esp+15Ch] [ebp-154h]
  _DWORD *v30; // [esp+2A8h] [ebp-8h]
  const void **v31; // [esp+2ACh] [ebp-4h]

  v3 = 0;
  v30 = this;
  if ( a2 && a3 )
  {
    Parameter = sub_679270(v19);
    v19[0] = sub_647778;
    v20 = nullsub_10;
    if ( _setjmp3(v21, 0) )
    {
LABEL_4:
      v3 = -2147467259;
LABEL_19:
      sub_6775B0(&Parameter);
      return v3;
    }
    sub_6774C0((ULONG_PTR)&Parameter, 62, 472);
    v4 = (_DWORD *)(*(int (__stdcall **)(ULONG_PTR *, _DWORD, int))v23)(&Parameter, 0, 36);
    v24 = v4;
    v4[8] = a3;
    v4[2] = nullsub_10;
    v4[3] = sub_6477B6;
    v4[4] = sub_6477D3;
    v4[5] = sub_678F40;
    v4[6] = nullsub_10;
    v4[1] = 0;
    *v4 = 0;
    v4[7] = a2;
    sub_6778B0(&Parameter, 1);
    if ( !sub_5AE78A() )
      v25 = 1;
    v20 = sub_647797;
    sub_6773E0(&Parameter);
    if ( v28 == 1 )
    {
      v6 = v30;
      v5 = v26;
      *v30 = 50;
      v6[12] = v5;
    }
    else
    {
      if ( v28 != 3 )
        goto LABEL_4;
      v5 = v26;
      v6 = v30;
      v7 = 4 * v26;
      *v30 = 22;
      v6[12] = v7;
    }
    v8 = v6[16] == 0;
    v6[3] = v5;
    v9 = v27;
    v6[13] = 0;
    v6[4] = v9;
    v6[5] = 1;
    if ( !v8 )
    {
      v18 = v9 * v6[12];
      v6[14] = 1;
      v10 = operator new(v18);
      v6[1] = v10;
      if ( v10
        && (v31 = (const void **)(*(int (__stdcall **)(ULONG_PTR *, int, unsigned int, int))(v23 + 8))(
                                   &Parameter,
                                   1,
                                   v28 * v26,
                                   1)) != 0 )
      {
        if ( *v6 == 50 )
        {
          for ( i = (char *)v6[1]; v29 < v27; i += v26 )
          {
            sub_677350(&Parameter, v31, 1);
            qmemcpy(i, *v31, v26);
          }
          v3 = 0;
        }
        else if ( *v6 == 22 )
        {
          v13 = (int *)v6[1];
          while ( v29 < v27 )
          {
            sub_677350(&Parameter, v31, 1);
            v14 = *v31;
            v15 = &v13[v26];
            if ( v13 < v15 )
            {
              do
              {
                v16 = (unsigned __int8)v14[2];
                HIBYTE(v17) = *v14;
                v14 += 3;
                LOBYTE(v17) = *(v14 - 2);
                *v13++ = v16 | (v17 << 8);
              }
              while ( v13 < v15 );
              v3 = 0;
            }
          }
        }
        sub_6777F0(&Parameter);
      }
      else
      {
        v3 = -2147024882;
      }
    }
    goto LABEL_19;
  }
  return -2147467259;
}
