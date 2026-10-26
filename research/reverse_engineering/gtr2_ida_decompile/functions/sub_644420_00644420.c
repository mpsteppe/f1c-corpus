void __thiscall sub_644420(_DWORD *this)
{
  void *v2; // [esp-8h] [ebp-Ch]
  void *v3; // [esp-4h] [ebp-8h]

  v3 = (void *)this[1];
  *this = &off_735FDC;
  free(v3);
  v2 = (void *)this[2];
  this[1] = 0;
  free(v2);
  this[2] = 0;
}
