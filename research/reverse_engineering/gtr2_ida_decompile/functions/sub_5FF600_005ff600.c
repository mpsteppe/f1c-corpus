int __userpurge sub_5FF600@<eax>(int a1@<ecx>, __int32 a2@<ebx>, int a3, _DWORD *a4, float a5, int a6)
{
  int *v7; // edi
  float v9; // [esp+0h] [ebp-54h]
  float v10; // [esp+4h] [ebp-50h]
  char Buffer[64]; // [esp+14h] [ebp-40h] BYREF

  v7 = (int *)(a1 + 272);
  if ( !*(_DWORD *)(a1 + 272) )
  {
    sprintf(Buffer, "PROJ%.3dVIEW", *(_DWORD *)(a1 + 40));
    if ( sub_5E59F0(a2, (int)v7, (int)Buffer, 0x8000) )
    {
      sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error creating view for projector %d", *(_DWORD *)(a1 + 40));
      return -1;
    }
    sub_4CD350((_DWORD *)*v7, 0);
    v10 = (float)*(int *)(a1 + 244);
    v9 = (float)*(int *)(a1 + 240);
    sub_5E53E0(*v7, 0.0, 0.0, v9, v10, 0);
    *(_DWORD *)(*v7 + 764) = *(_DWORD *)(a1 + 300);
    *(_DWORD *)(a1 + 224) = a6;
    sub_5FF040((float *)a1, a5);
    sub_5FEEB0((void *)a1, a4, 0.0);
    sub_5FEE10();
    *(_DWORD *)a1 |= 8u;
    sub_5E5050((char *)*v7, 6);
  }
  return 0;
}
