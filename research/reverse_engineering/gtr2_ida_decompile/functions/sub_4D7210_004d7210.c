// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4D7210(CHAR *this)
{
  void **v2; // esi
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+4h] [ebp-8h] BYREF
  const CHAR **v6; // [esp+8h] [ebp-4h]

  v5 = 0;
  sub_4D13B0((int)&v5, v4);
  v2 = (void **)v6;
  sub_4D4880(this, v6);
  if ( v2 )
  {
    if ( *v2 )
      j_j__free(*v2);
    j__free(v2);
  }
  return 0;
}
