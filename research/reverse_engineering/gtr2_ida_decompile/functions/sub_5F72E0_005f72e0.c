int __thiscall sub_5F72E0(_DWORD *this, int a2, _DWORD *a3)
{
  int v3; // eax
  int result; // eax
  int v5; // eax
  char *v6; // edx

  dword_FB3EBC = a2;
  if ( this[87] )
  {
    if ( a2 )
    {
      if ( (*a3 & 0x8000) != 0 && (v3 = a3[26]) != 0 )
      {
        sub_5D7870(*(_DWORD *)(v3 + 392) + 184, (float *)(a2 + 700), (int)&unk_FB2EB8);
        result = (*(int (__stdcall **)(int, _DWORD, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(
                   dword_FB40C8,
                   0,
                   &unk_FB2EB8,
                   4);
        dword_FB2EB4 = 0;
      }
      else
      {
        result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 376))(
                   dword_FB40C8,
                   0,
                   a2 + 700,
                   4);
        dword_FB2EB4 = 0;
      }
    }
    else
    {
      result = (*(int (__stdcall **)(int, _DWORD, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
                 dword_FB40C8,
                 0,
                 (char *)dword_FB27A8 + 4,
                 4);
      dword_FB2EB4 = 0;
    }
  }
  else
  {
    if ( (*a3 & 0x8000) != 0 && (v5 = a3[26]) != 0 )
      (*(void (__stdcall **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(
        dword_FB40C8,
        256,
        *(_DWORD *)(v5 + 392) + 184);
    else
      (*(void (__stdcall **)(int, int, void *))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 256, &unk_FB2EF8);
    if ( dword_FB3EBC )
    {
      (*(void (__stdcall **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 2, dword_FB3EBC + 348);
      v6 = (char *)(dword_FB3EBC + 632);
    }
    else
    {
      (*(void (__stdcall **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(
        dword_FB40C8,
        2,
        (char *)dword_FB27A8 + 4);
      v6 = (char *)dword_FB27A8 + 4;
    }
    result = (*(int (__stdcall **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 3, v6);
    dword_FB2EB4 = 0;
  }
  return result;
}
