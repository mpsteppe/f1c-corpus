char __stdcall sub_5F63B0(int a1, char a2)
{
  char result; // al
  float *v3; // esi
  float *v4; // eax
  float *v5; // esi
  char *v6; // [esp-4h] [ebp-8h]

  result = a1;
  if ( !a1 || (v3 = *(float **)(a1 + 4)) == 0 )
  {
    dword_FB2EB0 = 0;
    return result;
  }
  result = a2;
  if ( v3 == (float *)dword_FB2EB0 )
  {
    if ( !a2 )
      return result;
  }
  else if ( !a2 )
  {
LABEL_10:
    dword_FB2EB0 = *(_DWORD *)(a1 + 4);
    v4 = sub_5E8F00(v3, (float *)dword_FB40C4, 0, 0);
    goto LABEL_11;
  }
  if ( !dword_FB40C0 )
    goto LABEL_10;
  dword_FB2EB0 = 0;
  v6 = sub_496F80((char *)dword_FB40C0);
  v4 = sub_5E8F00(v3, (float *)dword_FB40C4, 1, (int)v6);
LABEL_11:
  v5 = v4;
  (*(void (__stdcall **)(int, int, float *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 12, v4, 4);
  return (*(int (__stdcall **)(int, _DWORD, float *, int))(*(_DWORD *)dword_FB40C8 + 436))(dword_FB40C8, 0, v5, 4);
}
