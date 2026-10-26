// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_5F6FC0@<eax>(int a1@<ecx>, int a2@<edi>, int a3, _DWORD *a4, char a5)
{
  char v6; // bl
  int result; // eax
  int v8; // edx
  int v9; // edx
  char *v10; // eax
  char *v11; // edx
  float v12[3]; // [esp+0h] [ebp-34h] BYREF
  _BYTE v13[4]; // [esp+Ch] [ebp-28h] BYREF
  _BYTE v14[4]; // [esp+10h] [ebp-24h] BYREF
  _BYTE v15[8]; // [esp+14h] [ebp-20h] BYREF
  int v16; // [esp+1Ch] [ebp-18h]
  char v17; // [esp+24h] [ebp-10h]

  v6 = 0;
  result = 0;
  if ( a4 )
  {
    v8 = a4[26];
    if ( v8 )
      result = *(_DWORD *)(v8 + 392);
    if ( (BYTE1(*a4) & 0x80u) != 0 )
      v6 = 1;
  }
  if ( *(_DWORD *)(a1 + 348) )
  {
    if ( a3 != dword_FB3EBC || result != dword_FB3EB8 || a5 )
    {
      dword_FB3EB8 = result;
      dword_FB3EBC = a3;
      v16 = 4;
      if ( result )
      {
        v9 = *(_DWORD *)dword_FB40C8;
        if ( a5 )
          (*(void (__cdecl **)(int, int, int, int))(v9 + 376))(dword_FB40C8, 4, result + 320, v16);
        else
          (*(void (__cdecl **)(int, int, int, int))(v9 + 376))(dword_FB40C8, 4, result + 184, v16);
      }
      else
      {
        (*(void (__cdecl **)(int, int, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
          dword_FB40C8,
          4,
          (char *)dword_FB27A8 + 4,
          v16);
      }
      if ( dword_FB3EBC )
      {
        sub_5E4D90((void *)dword_FB3EBC, (int)&dword_FB2F38, (int)&dword_FB2F3C, (int)&dword_FB2F40);
        if ( v6 )
        {
          if ( v17 && dword_FB40C0 )
          {
            sub_5D7870(dword_FB3EB8 + 320, (float *)(dword_FB3EBC + 700), (int)&unk_FB2EB8);
            sub_5E4D90((void *)dword_FB3EBC, (int)v13, (int)v14, (int)v15);
            v10 = sub_496F80((char *)dword_FB40C0);
            sub_5D7810(v12, (float *)&dword_FB2F38, (float *)v10 + 1);
          }
          else
          {
            sub_5D7870(dword_FB3EB8 + 184, (float *)(dword_FB3EBC + 700), (int)&unk_FB2EB8);
          }
          (*(void (__cdecl **)(int, _DWORD, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(
            dword_FB40C8,
            0,
            &unk_FB2EB8,
            4);
        }
        else
        {
          (*(void (__cdecl **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 376))(
            dword_FB40C8,
            0,
            dword_FB3EBC + 700,
            4);
        }
        if ( (*(_DWORD *)(a1 + 340) & 0x100) != 0 )
        {
          qmemcpy(&unk_FB2FB8, (const void *)(dword_FB3EBC + 348), 0x40u);
          sub_5D7120((_DWORD *)(dword_FB3EBC + 560), (int)&unk_FB2FF8);
          (*(void (__cdecl **)(int, int, void *, int, int))(*(_DWORD *)dword_FB40C8 + 376))(
            dword_FB40C8,
            16,
            &unk_FB2FB8,
            8,
            a2);
        }
      }
      else
      {
        dword_FB2F40 = 0;
        dword_FB2F3C = 0;
        dword_FB2F38 = 0;
        (*(void (__cdecl **)(int, _DWORD, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
          dword_FB40C8,
          0,
          (char *)dword_FB27A8 + 4,
          4);
      }
      result = (*(int (__cdecl **)(int, int, int *, int))(*(_DWORD *)dword_FB40C8 + 376))(
                 dword_FB40C8,
                 8,
                 &dword_FB2F38,
                 1);
      dword_FB2EB4 = 0;
    }
  }
  else
  {
    dword_FB3EB8 = result;
    dword_FB3EBC = a3;
    if ( result )
      (*(void (__cdecl **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 256, result + 184);
    else
      (*(void (__cdecl **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(
        dword_FB40C8,
        256,
        (char *)dword_FB27A8 + 4);
    if ( dword_FB3EBC )
    {
      (*(void (__cdecl **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 2, dword_FB3EBC + 348);
      v11 = (char *)(dword_FB3EBC + 632);
    }
    else
    {
      (*(void (__cdecl **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 2, (char *)dword_FB27A8 + 4);
      v11 = (char *)dword_FB27A8 + 4;
    }
    result = (*(int (__cdecl **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 3, v11);
    dword_FB2EB4 = 0;
  }
  return result;
}
