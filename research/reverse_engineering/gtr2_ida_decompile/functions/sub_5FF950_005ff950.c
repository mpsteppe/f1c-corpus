int __userpurge sub_5FF950@<eax>(
        int *a1@<ecx>,
        __int32 a2@<ebx>,
        int a3@<edi>,
        int a4,
        int a5,
        _DWORD *a6,
        float a7,
        int a8,
        const char *a9,
        int a10,
        int a11)
{
  int *v12; // eax
  int *v13; // eax
  _DWORD *v14; // ebx
  int i; // eax
  char *v16; // esi

  if ( (*(_BYTE *)a1 & 1) == 0 )
  {
    if ( sub_5FF750(a1, a2, a3, a4, a5, a6, a7, a8, a11) )
      return -1;
    v12 = (int *)operator new(0x1E4u);
    if ( v12 )
      v13 = sub_5E38B0(v12);
    else
      v13 = 0;
    a1[67] = (int)v13;
    sub_5E3A10(v13, a9, 128);
    *(_DWORD *)(a1[67] + 4) = a10;
    if ( strstr((const char *)(a1[67] + 12), ".BIK") )
    {
      *(_DWORD *)(a1[67] + 84) = 7;
    }
    else if ( a10 > 1 )
    {
      *(_DWORD *)(a1[67] + 84) = 6;
      *(_DWORD *)(a1[67] + 88) = 1065353216;
      v14 = operator new(4 * a10);
      for ( i = 0; i < a10; ++i )
        v14[i] = i;
      sub_5E2A70(a1[67], (int)v14, a10);
      j__free(v14);
    }
    if ( sub_5E3AA0((char *)a1[67], 0.0, 0, 1.0, 1) )
    {
      sub_5E4AA0(a1[67], 0);
      v16 = (char *)a1[67];
      if ( v16 )
      {
        sub_5E39C0(v16);
        j__free(v16);
      }
      return -1;
    }
    *a1 |= 5u;
  }
  return 0;
}
