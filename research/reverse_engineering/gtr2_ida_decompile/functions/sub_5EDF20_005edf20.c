int __thiscall sub_5EDF20(int this, int a2, float a3, float a4, float a5, float a6, float a7, int a8)
{
  int v10; // ecx
  int v11; // edx
  void *v12; // ebp
  int v13; // eax
  void *v14; // [esp-14h] [ebp-18h]
  char v15; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(this + 4) == 1 )
  {
    v10 = a2;
    if ( a2 > *(_DWORD *)(this + 24) - 1 )
    {
      v11 = *(_DWORD *)(this + 20);
      *(_DWORD *)(this + 24) = a2 + 1;
      if ( a2 + 1 > v11 )
      {
        v12 = operator new(28 * (a2 + 1));
        qmemcpy(v12, *(const void **)(this + 44), 28 * *(_DWORD *)(this + 20));
        v14 = *(void **)(this + 44);
        *(_DWORD *)(this + 20) = *(_DWORD *)(this + 24);
        j__free(v14);
        v10 = a2;
        *(_DWORD *)(this + 44) = v12;
      }
    }
    v13 = 28 * v10;
    *(float *)(v13 + *(_DWORD *)(this + 44)) = a3;
    *(float *)(v13 + *(_DWORD *)(this + 44) + 4) = a4;
    *(float *)(v13 + *(_DWORD *)(this + 44) + 8) = a5;
    *(_DWORD *)(v13 + *(_DWORD *)(this + 44) + 12) = 1065353216;
    *(float *)(v13 + *(_DWORD *)(this + 44) + 20) = a6;
    *(float *)(v13 + *(_DWORD *)(this + 44) + 24) = a7;
    *(_DWORD *)(v13 + *(_DWORD *)(this + 44) + 16) = a8;
    *(_DWORD *)this |= 0x20u;
    return 0;
  }
  else
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Wrong vertex type -  should be screen vertex", v15);
    return -1;
  }
}
