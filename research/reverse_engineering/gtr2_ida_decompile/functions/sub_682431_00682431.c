void __thiscall sub_682431(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void *v3; // [esp-4h] [ebp-8h]

  v3 = (void *)this[52];
  *this = &off_73D054;
  j__free(v3);
  v2 = (void (__thiscall ***)(_DWORD, int))this[56];
  if ( v2 )
    (**v2)(v2, 1);
  sub_681C77(this);
}
