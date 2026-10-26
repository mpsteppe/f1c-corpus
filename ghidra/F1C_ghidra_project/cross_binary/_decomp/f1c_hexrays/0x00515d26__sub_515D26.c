// f1c  0x00515d26  size=146
void __usercall sub_515D26(int a1@<ebx>)
{
  unsigned int v1; // esi
  void *v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int *v5; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( *(int *)(a1 + 288) > 0 )
  {
    v5 = (int *)(a1 + 292);
    do
    {
      v3 = *v5;
      if ( !*(_DWORD *)(*v5 + 76) )
      {
        v1 = *(_DWORD *)(*v5 + 16);
        if ( v1 >= 4 || !*(_DWORD *)(a1 + 4 * v1 + 144) )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 51;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v1;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        v2 = (void *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 130);
        qmemcpy(v2, *(const void **)(a1 + 4 * v1 + 144), 0x82u);
        *(_DWORD *)(v3 + 76) = v2;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *(_DWORD *)(a1 + 288) );
  }
}
