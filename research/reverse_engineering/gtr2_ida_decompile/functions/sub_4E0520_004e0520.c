char __thiscall sub_4E0520(void *this, int a2)
{
  void **v3; // eax
  void **v4; // esi
  void *v5; // edi

  if ( sub_4DEDE0(this, a2) )
    return 1;
  v3 = (void **)operator new(0x20u);
  if ( v3 )
  {
    v3[1] = (void *)-1;
    *v3 = 0;
    v3[3] = (void *)-1;
    v3[2] = 0;
    v3[5] = (void *)-1;
    v3[4] = 0;
    v3[6] = (void *)1065353216;
    v3[7] = (void *)1065353216;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  sub_615860(a2);
  sub_615860(a2);
  if ( (unsigned __int8)sub_4E37E0(v4) )
  {
    sub_5FDFB0(v4, 1);
    return 1;
  }
  else
  {
    if ( v4 )
    {
      v5 = v4[2];
      if ( v5 )
        j_j__free(v5);
      if ( *v4 )
        j_j__free(*v4);
      j__free(v4);
    }
    return 0;
  }
}
