int __thiscall sub_4A6350(int this)
{
  int *v2; // ecx
  int v3; // eax
  int v5; // [esp-8h] [ebp-Ch]

  if ( *(_BYTE *)(this + 280)
    && *(_DWORD *)(*(_DWORD *)(this + 296) + 312) > 255 - *(_DWORD *)(*(_DWORD *)(this + 296) + 320) )
  {
    v5 = *(_DWORD *)(this + 284);
    *(_BYTE *)(this + 280) = 0;
    sub_4D4060(v5, 0);
    v2 = *(int **)(this + 296);
    v3 = *v2;
    v2[81] = 1058642330;
    *((_BYTE *)v2 + 316) = 0;
    (*(void (__stdcall **)(int))(v3 + 40))(1);
  }
  return 0;
}
